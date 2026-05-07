/*
Завдання 1. Реалізуйте int* createFilledArray(int size, int value) — виділяє масив, заповнює
кожен елемент value, повертає. Викличте, виведіть, звільніть у main.
*/

#include <iostream>


int* createFilledArray(int size, int value);
void printArray(int* array, int size);

int main() {

    const int SIZE = 6;
    int *arrayResult = createFilledArray(SIZE, 67);

    printArray(arrayResult, SIZE);

    delete[] arrayResult;
    arrayResult = nullptr;

    return 0;
}

int* createFilledArray(int size, int value) {

    int* array = new int[size];

    for (int count = 0; count < size; ++count)
        array[count] = value;

    return array;
}

void printArray(int* array, int size) {

    for (int index = 0; index < size; ++index)
        std::cout << array[index] << " ";
    std::cout << std::endl;
}