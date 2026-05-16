/*
Завдання 4. Реалізуйте функцію findFirst(int* array, int size, bool (*predicate)(int)), що
повертає індекс першого елемента, для якого predicate повертає true, або -1. Перевірте з
предикатами «є парним» і «більше 10».
*/


#include <iostream>


int findFirst(int* array, int size, bool (*predicate)(int));
bool evenFind(int value);
bool moreTenFind(int value);


int main(){

    const int SIZE = 3;
    int arrayOne[SIZE] = {3, 2, 6};
    int arrayTwo[SIZE] = {9, 5, 11};

    std::cout << findFirst(arrayOne, SIZE, evenFind) << std::endl;
    std::cout << findFirst(arrayTwo, SIZE, moreTenFind) << std::endl;

    return 0;
}


int findFirst(int* array, int size, bool (*predicate)(int)) {

    for (int index = 0; index < size; ++index) {

        if (predicate(array[index]))
            return index;
    }
    return -1;
}

bool evenFind(int value) { return value % 2 == 0; }
bool moreTenFind(int value) { return value > 10; }