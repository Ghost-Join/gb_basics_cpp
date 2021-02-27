#include <iostream>

using namespace std;
using PlayingField = int;

int main()
{
    //1. Объявление и инициализация переменных
    int val_1 = 1;
    long int val_2 = 2;
    long long int val_3 = 3;
    unsigned int val_4 = 11;
    unsigned long int val_5 = 22;
    unsigned long long int val_6 = 33;
    uint32_t utVal_1 = 132;
    int8_t tVal_1 = 108;
    short int nVal = 1;
    float fVal_1 = 1.1;
    double dVal_1 = 1.11;
    long double dVal_2 = 1.1111;
    char symbol_1 = 'A';
    unsigned char symbol_2 = 'A';
    string str1 = "Строка";
    bool bVal_1 = true;
    bool bVal_2 = false;
    const float PI = 3.14;

    cout << "val = " << str1 << endl;

    //2. Перечисление возможных символов для игры крестики-нолики
    enum xoVal {val_Empty, val_X, val_O};
    xoVal Empty = val_Empty;
    xoVal X = val_X;
    xoVal O = val_O;
    cout << "Empty = " << Empty << endl;
    cout << "X = " << X << endl;
    cout << "O = " << O << endl;

    //3. Массив
    PlayingField Array[3][3] = {{Empty, Empty, Empty},
                                {Empty, Empty, Empty},
                                {Empty, Empty, Empty}};


    //cout << "Hello World!" << endl;
    return 0;
}
