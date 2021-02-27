#include <iostream>
using namespace std;
#include "task3_plus.h"

extern const int task3_a, task3_b, task3_c, task3_d;

int main()
{
    //1. Написать программу, вычисляющую выражение a * (b + (c / d)) и выводящую результат с плавающей точкой, где a, b, c, d – целочисленные константы;
    const int a = 1, b = 3, c = 7, d = 2;
    float nResult1;
    nResult1 = (static_cast<float>(a) * static_cast<float>(b) + (static_cast<float>(c) / static_cast<float>(d)));
    cout << "Task 1.\nВычисление выражения a * (b + (c / d)). Переменные указаны в функции main().\nResult = " << nResult1 << endl;
    cout << endl;

    //2. Дано целое число, выведите на экран разницу между этим числом и числом 21. Если же заданное число больше, чем 21, необходимо вывести удвоенную разницу между этим числом и 21. При выполнении задания следует использовать тернарный оператор.
    int nVar_1, nResult2;
    cout << "Task 2.\nСравнение веденного числа с числом 21 и произведение расчетов.\n*использование тернарного оператора(if).\nВведите целое число: ";
    cin >> nVar_1;
    nResult2 = (nVar_1 < 21) ? 21 - nVar_1 : 2 * (nVar_1 - 21);
    cout << "Result = " << nResult2 << endl;
    cout << endl;

    //3. * Написать программу, вычисляющую выражение из первого задания, а переменные для неё инициализировать в другом файле.
    float nResult3;
    nResult3 = (static_cast<float>(task3_a) * static_cast<float>(task3_b) + (static_cast<float>(task3_c) / static_cast<float>(task3_d)));
    cout << "Task 3.\nВычисление выражения a * (b + (c / d)). Переменные указаны в файле task3.cpp.\nResult = " << nResult3 << endl;
    cout << endl;

    //3plus. * Написать программу, вычисляющую выражение из первого задания, а переменные для неё инициализировать в другом файле.
    const int SIZE_VAR = 4;
    int nArr[SIZE_VAR]={};
    cout << "Task 3plus." << endl;
    inputVar(nArr, SIZE_VAR);
    //printArray(nArr, SIZE_VAR);
    float nResult4;
    nResult4 = (static_cast<float>(nArr[0]) * static_cast<float>(nArr[1]) + (static_cast<float>(nArr[2])/static_cast<float>(nArr[3])));
    cout << "Вычисление выражения a * (b + (c / d)). Переменные определяются в task3_plus.h.\nResult = " << nResult4 << endl;
    cout << endl;

    //4.* Описать трёхмерный целочисленный массив, размером 3х3х3, указатель на значения внутри массива и при помощи операции разыменования вывести на экран значение центральной ячейки получившегося куба [1][1][1]
    cout << "Task 4. Описание трёхмерного целочисленного массива, размером 3х3х3 и вывод значения центральной ячейки получившегося куба [1][1][1]" << endl;
    const int SIZE1 = 3, SIZE2 = 3, SIZE3 = 3;
    int nArray[SIZE1][SIZE2][SIZE3]{};
    //Заполнение массива
    int count = 1;
    for(int i=0; i<SIZE1; i++){
        for(int j=0; j<SIZE2; j++){
            for(int z=0; z<SIZE3; z++){
                nArray[i][j][z] = count++;
            }
        }
    }
    //Вывод массива
    for(int i=0; i<SIZE1; i++){
        for(int j=0; j<SIZE2; j++){
            for(int z=0; z<SIZE3; z++){
                cout << nArray[i][j][z] << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "Значение центральной ячейки куба [1][1][1] = " << nArray[1][1][1] << endl;
    //cout << "nArray[" << i << "] = " << nArray[i] << endl;
    return 0;
}
