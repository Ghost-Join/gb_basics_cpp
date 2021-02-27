//#ifndef TASK3_PLUS_H
//#define TASK3_PLUS_H

//#endif // TASK3_PLUS_H

void inputVar(int array[], int count_var){
    cout << "Введите последовательно переменные: A, B, C, D\n" << endl;
    for(int i = 0; i < count_var; i++) {
        cin >> array[i];
    }
}

void printArray(int array[], int count_var) {
    for(int i = 0; i < count_var; i++) {
        cout << array[i] << endl;
    }
}
