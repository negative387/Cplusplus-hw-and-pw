/*
Завдання 6. Динамічно виділіть масив вказівників int* розміром 3. Оголосіть три окремі змінні
int і запишіть їхні адреси в елементи масиву. Виведіть значення, розіменувавши кожен вказівник
і звільніть пам'ять.
*/

#include <iostream>

int main() {

    const int SIZE = 3;
    int indexZero = 3;
    int indexOne = 9;
    int indexTwo = 2;

    int** arrayPtrs = new int*[SIZE]{&indexZero, &indexOne, &indexTwo};

    for (int index = 0; index < SIZE; ++index) {
        std::cout << *arrayPtrs[index] << " ";
    }

    delete[] arrayPtrs;
    arrayPtrs = nullptr;

    return 0;
}