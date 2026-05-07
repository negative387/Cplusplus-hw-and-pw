/*
Завдання 3. Реалізуйте int* resizeArray(int* oldArray, int oldSize, int newSize):

Алоцює новий масив newSize елементів.
Копіює min(oldSize, newSize) елементів.
Звільняє oldArray.
Повертає новий масив.

Протестуйте: масив {1, 2, 3} → розширити до 5 (нові = 0) → вивести.
*/

#include <iostream>

int* resizeArray(int* oldArray, int oldSize, int newSize);
void printArray(int* array, int size);


int main() {

    const int SIZE = 3;
    int* array = new int[SIZE]{1, 2, 3};
    int* arrayNew = resizeArray(array, SIZE, 5);
    const int NEWSIZE = 5;
    array = nullptr;

    printArray(arrayNew, NEWSIZE);

    delete[] arrayNew;
    arrayNew = nullptr;

    return 0;
}

int* resizeArray(int* oldArray, int oldSize, int newSize) {

    int* array = new int[newSize];

    for (int index = 0; index < newSize; ++index) {
        if (index < oldSize)
            array[index] = oldArray[index];
        else
            array[index] = 0;
    }

    delete[] oldArray;

    return array;
}

void printArray(int* array, int size) {

    for (int index = 0; index < size; ++index)
        std::cout << array[index] << " ";
    std::cout << std::endl;
}
