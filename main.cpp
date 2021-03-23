#include <iostream>
#include <random>

enum class CellState {	//Взято из кода
    Empty, X, O
};
enum class Sign {	//Взято из кода
    X, O
};

struct GameField {	//++Изменено
	int sizeArray;
	CellState** mapField;
};

struct GameData {	//Взято из кода
	GameField field;
	Sign player_sign;
};

struct TurnOutcome {	//++Изменено
    bool isOver : 1;
    Sign victor : 2;	//++Изменено
    bool isDraw : 1;
};

#define CHK_ISVALID(szArr, row, column) (((row) >= 0) && ((row) < (szArr)) && ((column) >= 0) && ((column) < (szArr)))	//++Изменено
#define CHK_GET_ARR(array, row, column) (*((*(field.mapField + row)) + column))	//++Изменено

// bool isValidCell(const GameField& field, size_t row, size_t column) {	//Изменено
    // return row >= 0 && row < field.sizeArray && column >= 0 && column < field.sizeArray;
// }

CellState getCell(const GameField& field, size_t row, size_t column) {	//++Изменено
    if (!CHK_ISVALID(field.sizeArray, row, column)) return CellState::Empty;
    return CHK_GET_ARR(field.mapField, row, column);
}

bool isCellEmpty(const GameField& field, size_t row, size_t column) {	//++Изменено
    return getCell(field, row, column) == CellState::Empty;
}

void putSign(GameField& field, Sign sign, size_t row, size_t column) {	//++Изменено
    if (CHK_ISVALID(field.sizeArray, row, column)) {
        CHK_GET_ARR(field.mapField, row, column) = (sign == Sign::X) ? CellState::X : CellState::O;
    }
}

void initField(GameField& field) {	//++Изменено: Инициализация игрового поля (двумерного массива)
	field.mapField = new CellState* [field.sizeArray];
	for(int i = 0; i < field.sizeArray; i++) {
		field.mapField[i] = new CellState [field.sizeArray];
	}
	for(int i = 0; i < field.sizeArray; i++) {
		for(int j = 0; j < field.sizeArray; j++) {
			field.mapField[i][j] = CellState::Empty;
		}
	}
}

void printGameField(const GameField& field) {	//Вывод состояния игрового поля
	
	std::cout << " ";
	for(int strTop = 0; strTop < field.sizeArray; strTop++) {
		std::cout << "_" << strTop + 1;
	}
	std::cout << "_\n";
	for(int i = 0; i < field.sizeArray; i++) {
		std::cout << i + 1 << "|";
		for(int j = 0; j < field.sizeArray; j++) {
			switch(field.mapField[i][j]) {
				case CellState::Empty:
					std::cout << "_";				
				break;
				case CellState::X:
					std::cout << "X";				
				break;
				case CellState::O:
					std::cout << "O";				
				break;
			}
			std::cout << "|";
		}
		std::cout << "\n";
	}
}


bool askQuestion(char positive, char negative) {	//Взято из кода
    char sign {};
    std::cin >> sign;
    sign = tolower(sign);

    while (sign != positive && sign != negative) {
        std::cout << "Wrong input: received '" << sign << "', should be one of \'" << positive << "\' or \'" << negative << "\'\n";
        std::cin >> sign;
        sign = tolower(sign);
    }
    return sign == positive;
}


Sign queryPlayerSign() {	//Взято из кода
    std::cout << "Please input wheter you're X or O: ";
    bool isX = askQuestion('x', 'o');
    return isX ? Sign::X : Sign::O;
}


int inputSizeArray(Sign sing_player) {	//++Изменено: Ввод колличества эллементов массива
	std::cout << "Input size array 3=(3x3), 4=(4x4), ... * MIN=3, MAX=9: ";
	int szArr;
	std::cin >> szArr;
	
	while((szArr < 3) || (szArr > 9)) {
		std::cout << "Error input! * MIN=3, MAX=9: ";
		std::cin >> szArr;
	}
	
	if(sing_player == Sign::X){
		std::cout << "\nSign player = X | ";
	} else {
		std::cout << "\nSign player = O | ";
	}
	std::cout << "Set value: " << szArr << " = (" << szArr << "x" << szArr << "). | ";
	std::cout << "Good game!\n";
	return szArr;
}

bool isDraw(const GameField& field) {	//++Изменено
	bool resDraw = false;
	int empty_arr = 0;
    for (size_t i = 0; i < field.sizeArray; i++) {
		for (size_t j = 0; j < field.sizeArray; j++) {
			if (field.mapField[i][j] == CellState::Empty) {
				empty_arr++;
			}
		}
    }
	if(empty_arr > 0){
		resDraw = false;		
	} else {
		resDraw = true;		
	}
    return resDraw;
}

bool checkLine(const GameField& field, size_t start_row, size_t start_column, int delta_row, int delta_column) {	//Взято из кода
    size_t current_row = start_row;
    size_t current_column = start_column;
    auto first = getCell(field, start_row, start_column);
    if (first == CellState::Empty) {
        return false;
    }
    while (CHK_ISVALID(field.sizeArray, current_row, current_column)) {	//++Изменено
        if (getCell(field, current_row, current_column) != first) {
            return false;
        }
        current_row += delta_row;
        current_column += delta_column;
    }
    return true;
}

#define CHECK_LINE(start_row, start_column, delta_row, delta_column) \
        if (checkLine(field, start_row, start_column, delta_row, delta_column)) { \
            outcome.isOver = true; \
            outcome.victor = getCell(field, start_row, start_column) == CellState::X ? Sign::X : Sign::O; \
            return outcome; \
        }

TurnOutcome checkTurnOutcome(const GameField& field) {	//Взято из кода
    TurnOutcome outcome {};
    for (size_t row = 0; row < field.sizeArray; row++) {
        CHECK_LINE(row, 0, 0, 1)
    }
    for (size_t column = 0; column < field.sizeArray; column++) {
        CHECK_LINE(0, column, 1, 0)
    }
    CHECK_LINE(0, 0, 1, 1)
    CHECK_LINE(0, 2, 1, -1)

    if (isDraw(field)) {
        outcome.isDraw = true;
    }
    return outcome;
}

void processPlayerTurn(GameField& field, Sign player_sign) {	//Взято из кода
    std::cout << "Enter row and column: ";

    int rowIn, columnIn, row, column;
    std::cin >> rowIn >> columnIn;
	row = rowIn - 1;
	column = columnIn - 1;

    while (!CHK_ISVALID(field.sizeArray, row, column) || !isCellEmpty(field, row, column)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input, please enter row and column of an empty cell: ";
        std::cin >> row >> column;
    }

    putSign(field, player_sign, row, column);
}

#undef CHECK_LINE
#undef CHK_ISVALID
#undef CHK_GET_ARR

void processAiTurn(GameField& field, Sign ai_sign) {	//++Изменено
	
	size_t empty_array[field.sizeArray*field.sizeArray];
	size_t last_empty_idx_i = 0;
	for(int i=0; i<field.sizeArray; i++){
		for(int j=0; j<field.sizeArray; j++){
			if (field.mapField[i][j] == CellState::Empty) {
				empty_array[last_empty_idx_i] = i*10+j;
				last_empty_idx_i++;
			}
		}
	}

    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<size_t> dist(0, last_empty_idx_i - 1);
	
    for (size_t i = 0; i < last_empty_idx_i; i++) {
        size_t target = empty_array[i];
        field.mapField[target/10][target%10] = ai_sign == Sign::X ? CellState::X : CellState::O;
        auto outcome = checkTurnOutcome(field);
        if (outcome.isOver) {
            return;
        }
        field.mapField[target/10][target%10] = CellState::Empty;

        auto opposite_sign = ai_sign == Sign::X ? Sign::O : Sign::X;
        field.mapField[target/10][target%10] = opposite_sign == Sign::X ? CellState::X : CellState::O;
        outcome = checkTurnOutcome(field);
        if (outcome.isOver) {
            field.mapField[target/10][target%10] = ai_sign == Sign::X ? CellState::X : CellState::O;
			outcome.isOver = true;
            return;
        }
        field.mapField[target/10][target%10] = CellState::Empty;
    }
	
	size_t target = empty_array[dist(mt)];
    putSign(field, ai_sign, target / 10, target % 10);

}

TurnOutcome runGameLoop(GameData& GameDataPlayer) {	//Взято из кода
	TurnOutcome outcome{};
	
	initField(GameDataPlayer.field);
	printGameField(GameDataPlayer.field);
	
    while(true) {
        if(GameDataPlayer.player_sign == Sign::X) {
			std::cout << "\nPlayer Turn: ";
            processPlayerTurn(GameDataPlayer.field, Sign::X);
        } else {
			std::cout << "\nAi Turn: \n";
            processAiTurn(GameDataPlayer.field, Sign::X);
        }
        
        printGameField(GameDataPlayer.field);
        outcome = checkTurnOutcome(GameDataPlayer.field);
        if (outcome.isOver||outcome.isDraw) {
            return outcome;
        }

        if(GameDataPlayer.player_sign == Sign::O) {
			std::cout << "\nPlayer Turn: ";
            processPlayerTurn(GameDataPlayer.field, Sign::O);
        } else {
			std::cout << "\nAi Turn: \n";
            processAiTurn(GameDataPlayer.field, Sign::O);
        }
        
        printGameField(GameDataPlayer.field);
        outcome = checkTurnOutcome(GameDataPlayer.field);
        if (outcome.isOver||outcome.isDraw) {
            return outcome;
        }
    }
}

void printGameOutcome(const TurnOutcome& outcome, GameData& gdPlaeyr) {	//++Изменено
	
    if (outcome.isDraw) {
        std::cout << "It's a draw.\n";
    } else if (outcome.victor == gdPlaeyr.player_sign) {
        std::cout << "Congrats! You're winner.\n";
    } else {
        std::cout << "No luck this time.\n";
    }
}

bool queryPlayAgain() {	//Взято из кода: запрашивает повтор игры
    std::cout << "Want to play again? [y or n]: ";
    return askQuestion('y', 'n');
}

int main() {    //++Изменено
	Sign player_sign = queryPlayerSign();
	GameField field;
	field.sizeArray = inputSizeArray(player_sign);
	
	GameData GameDataPlayer;
	GameDataPlayer.field = field;
	GameDataPlayer.player_sign = player_sign;
		
	bool shouldExit = false;
    while(!shouldExit) {
        auto outcome = runGameLoop(GameDataPlayer);
        printGameOutcome(outcome, GameDataPlayer);
        shouldExit = !queryPlayAgain();
    }

    return 0;
    }
