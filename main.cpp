#include <iostream>
#define checkNum(numValue, numLimitation) (((numValue>=0)&&(numValue<numLimitation))?"true":"false")
#define sizeArray(type, array) (sizeof(array)/sizeof(array[0]))	//по заданию предполагается, что здесь надо размер массива делить на тип данных: sizeof(array)/sizeof(type)
#define get_ELEMENT(array, ident1, ident2) (*(*(n2Array + ident1) + ident2))

#define DEBUG

using namespace std;

int main(int argc, char** argv) {
	
	//1. Описать макрокоманду, проверяющую, входит ли переданное ей число в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно)
	cout << "Task 1. Макрос, проверяющий, входит ли переданное ей число в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно)" << '\n';
	int nInput = 5, nLimit = 7;
	cout << "Value: " << nInput << " | Limit value: " << nLimit << '\n';
	cout << "Result: " << checkNum(nInput, nLimit);
	cout << "\n\n";
	
	//2. Описать макрокоманду, получающую доступ к элементу двумерного массива (организованного динамически) посредством разыменования указателей
	cout << "Task 2. Макрос, получающую доступ к элементу двумерного массива (организованного динамически) посредством разыменования указателей" << '\n';
	int SIZE1 = 5;
	int SIZE2 = 10;
	int** n2Array = new int* [SIZE1];
	for(int i = 0; i < SIZE1; i++) {
		n2Array[i] = new int [SIZE2];
	}
	int count = 0;
	for(int i = 0; i < SIZE1; i++) {
		for(int j = 0; j < SIZE2; j++) {
			n2Array[i][j] = 1+count++;
			cout << n2Array[i][j] << "\t";
		}
		cout << '\n';
	}
	
	int reqVal1 = 2, reqVal2 = 3;
	cout << "Request element array: " << "n2Array[" << reqVal1 << "][" << reqVal2 << "]\n";
	cout << "Array value: " << n2Array[reqVal1][reqVal2] << " <=> " << get_ELEMENT(n2Array, reqVal1, reqVal2);
	
	for(int i = 0; i < SIZE1; i++) {
		delete[] n2Array[i];
	}
	delete[] n2Array;
	
	cout << "\n\n";
	
	//3. * Описать макрокоманду, возвращающую количество элементов локального массива, принимающую на вход ссылку на массив и его тип
	cout << "Task 3. Макрос, возвращающую количество элементов локального массива, принимающую на вход ссылку на массив и его тип" << '\n';
	int n3Array[]{1, 2, 3, 4, 5, 6, 7, 8};
	cout << "Result: Size Array = " << sizeArray(int, n3Array);
	cout << "\n";
	
#ifdef DEBUG
	cout << "\nВремя выполнения: " << __TIME__;
#endif
	return 0;
}