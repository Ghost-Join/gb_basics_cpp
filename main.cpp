#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//прототипы функции
void funcFileOpen(string str, string data);	//task1
int countCharInFile(string filename);	//task2-1
void buferData(string namefile1, string namefile2, char* array, int sumSize);	//task2-2
int coincidence(string &strSearch, string &strPath);	//task3

int main(int argc, char** argv){
	//Написать программу, которая создаст два текстовых файла, примерно по 50-100 символов в каждом (особого значения не имеет);
	cout << "Task 1. Программа, которая создаст два текстовых файла, примерно по 50-100 символов в каждом\n";
	string path1 = "File1.txt";
	string dataFile1 = "Написать программу, которая создаст два текстовых файла, ";
	string path2 = "File2.txt";
	string dataFile2 = "примерно по 50-100 символов в каждом (особого значения не имеет);";
	funcFileOpen(path1, dataFile1);
	funcFileOpen(path2, dataFile2);
	cout << '\n';
	
	//Написать функцию, «склеивающую» эти файлы, предварительно буферизуя их содержимое в динамически выделенный сегмент памяти нужного размера.
	cout << "Task 2. Функция, «склеивающую» эти файлы, предварительно буферизуя их содержимое в динамически выделенный сегмент памяти нужного размера.\n";
	int nSize1 = countCharInFile(path1);
	int nSize2 = countCharInFile(path2);
	int sumNumArr = nSize1 + nSize2;
	char* ptrArr;
	ptrArr = new char[sumNumArr];
	buferData(path1, path2, ptrArr, sumNumArr);
	
	
	cout << "Результат: ";
	for(int i = 0; i < sumNumArr; i++){
		cout << ptrArr[i];
	}
	cout << "\n";
	
	delete[] ptrArr;
	cout << "\n";
	
	//* Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в указанном пользователем файле (для простоты работаем только с латиницей).
	cout << "Task 3. Программа проверяет присутствует ли указанное пользователем при запуске программы слово в указанном пользователем файле.\n";
	cout << "/>Пример запуска: main.exe cout main.cpp\n";
	string search = "";
	string path3 = "";
	if(argc < 2){
		cout << "Отсутствуют параметры запуска программы";
	}
	else{
		search = argv[1];
		path3 = argv[2];
		int countSearh = coincidence(search, path3);
		if(countSearh!=-1){
			cout << "Точных совпадений слова \"" << search << "\" в файле \"" << path3 << "\" = " << countSearh;			
		}
		else{
			cout << "Программа завершена с ошибкой: -1";
		}
	}
	
	return 0;
}

//Task 3-1
int coincidence(string &strSearch, string &strPath){
	ifstream fileSearch;
	fileSearch.open(strPath);
	if(!fileSearch.is_open()){
		cout << "Error open file!";
	}
	else{
		string tempStr;
		int countSrh = 0;
		while(!fileSearch.eof()){
			fileSearch >> tempStr;
			if(tempStr == strSearch){
				countSrh++;
			}
		}
	return countSrh;
	}
return -1;
}

//Task 2-2
void buferData(string namefile1, string namefile2, char* array, int sumSize){
	ifstream gluing1, gluing2;
	gluing1.open(namefile1);
	gluing2.open(namefile2);
	char cValue;
	if(!gluing1.is_open()&&gluing2.is_open()){
		cout << "Ошибка открытия файла";
	}
	else{
		for(int i=0; i<sumSize; i++){
			if(gluing1.get(cValue)){
				array[i] = cValue;
				// cout << cValue;				
			}
			else if(gluing2.get(cValue)){
				array[i] = cValue;
				// cout << cValue;		
			}
			else{
				cout << "ошибка заполнения массива данными";
			}
		}
	}
	gluing1.close();
	gluing2.close();
}

//Task 2-1
int countCharInFile(string filename){
	int count = 0;
	char cVal;
	ifstream countData;
	
	countData.open(filename);
	if(!countData.is_open()){
		cout << "Ошибка открытия файла: " << filename;
	}
	else{
		while(countData.get(cVal)){
			count++;
		}
	}
	
	countData.close();
	return count;
}

//Task 1
void funcFileOpen(string filename, string data){
	ofstream outData;
	
	outData.open(filename);
	if(!outData.is_open()){
		cout << "Ошибка открытия файла: " << filename;
	}
	else{
		outData << data;
		cout << "Файл \"" << filename << "\" создан. Данные записаны." << "\n";
	}
	outData.close();
}