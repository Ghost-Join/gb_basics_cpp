#include <iostream> //qt - выдавал ошибку на этапе сборки
namespace myFunc {
//Task 1. Функция 1
void printArray(int array[], int size){
    for(int i=0; i<size; i++){
        std::cout << array[i] << " ";
    }
    std::cout << '\n';
}

//Task 1. Функция 2
void noBits(int array[], int size){
    int num = 1;
    for(int i=0; i<size; i++){
        array[i] = num^array[i];
    }
}

// Task 2. Функция 1
void inputArray2task(int array[], int size){
    for(int i=0; i<size; i++){
        array[i] += 3*i+1;
    }
}

// Task 3. Функция 1
int checkBalance(int array[], int size){
    for(int i=0; i<size; i++){
        // std::cout << " Res1: i=" << i;				//отладочная информация

        if(i==0||i==size-1){
            // std::cout << " GoTo1 \n";				//отладочная информация
            continue;
        }
        else{
            int sumLeft = 0;
            for(int n=0; n<i; n++){
                sumLeft += array[n];
            }
            // std::cout << " | sLeft=" << sumLeft << " == [i]=" << n3Arr1[i];		//отладочная информация
            int sumReight = 0;
            if(sumLeft==array[i]){
                for(int j=i+1; j<size; j++){
                    sumReight += array[j];
                }
                // std::cout << " ==" << " sReight=" << sumReight;					//отладочная информация
                if(sumLeft==sumReight){
                    // std::cout << " | TRUE_!";									//отладочная информация
                    return 1;
                }
                else{
                    // std::cout << " | FALSE sLeft!=sReight";						//отладочная информация
                    return 0;
                }
            }
            else{
                // std::cout << " || FALSE sLeft!=n3Arr1[i] \n";					//отладочная информация
                continue;
            }
        }
        // std::cout << '\n';
    }
    return 0;
}

// Task 4. Функция 1
void shiftArrayRight(int array[], int size, int num){
    for(int i=0; i<num; i++){
        int temp = array[size-1];
        for(int j=size-1; j>0; --j){
            array[j] = array[j-1];
        }
        array[0] = temp;
    }
}

// Task 4. Функция 2
void shiftArrayLeft(int array[], int size, int num){
    for(int i=0; i<num; i++){
        int temp = array[0];
        for(int j=0; j<size-1; ++j){
            array[j] = array[j+1];
        }
        array[size-1] = temp;
    }
}
}
