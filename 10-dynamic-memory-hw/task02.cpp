/*
Завдання 2. Реалізуйте int* copyArray(int* source, int size) — динамічна копія масиву.
Покажіть, що зміна копії не впливає на оригінал.
*/

#include <iostream>


int* copyArray(int* source, int size);
void printArray(int* array, int size);

int main() {

    const int SIZE = 5;
    int array[SIZE] = {1, 2, 3, 4, 5};
    int* arrayCopy = copyArray(array, SIZE);

    arrayCopy[0] = 5;

    std::cout << "Оригінал: ";
    printArray(array, SIZE);
    std::cout << "Копія (змінена): ";
    printArray(arrayCopy, SIZE);

    delete[] arrayCopy;
    arrayCopy = nullptr;

    return 0;
}

int* copyArray(int* source, int size) {

    int* array = new int[size];
    for (int count = 0; count < size; ++count)
        array[count] = source[count];

    return array;
}

void printArray(int* array, int size) {
    for (int index = 0; index < size; ++index)
        std::cout << array[index] << " ";
    std::cout << std::endl;
}
