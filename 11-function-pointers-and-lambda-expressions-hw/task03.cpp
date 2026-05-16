/*
Завдання 3. Оголосіть using-псевдонім Transformer для функції int(int). Напишіть функцію
applyToArray(int* array, int size, Transformer fn), що застосовує fn до кожного елемента
масиву. Перевірте з функцією, що подвоює число.
*/


#include <iostream>

using Transformer = int(int);

void applyToArray(int* array, int size, Transformer fn);
int doubleValue(int value);
void printArray(int* array, int size);


int main() {

    const int SIZE = 5;
    int array[SIZE] = {1, 2, 3, 4, 5};

    applyToArray(array, SIZE, doubleValue);

    printArray(array, SIZE);

    return 0;
}


void applyToArray(int* array, int size, Transformer fn) {

    for (int index = 0; index < size; ++index)
        array[index] = fn(array[index]);
}

int doubleValue(int value) { return value * 2; }

void printArray(int* array, int size) {

    for (int index = 0; index < size; ++index)
        std::cout << array[index] << " ";
    std::cout << std::endl;
}