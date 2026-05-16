/*
Завдання 8. Напишіть лямбду isPositive, що повертає true, якщо число більше нуля. Використайте
її у функції forEach (або власному циклі) для виводу лише позитивних чисел з масиву {-3, 1, -1, 4, 0, 7, -2}.
*/


#include <iostream>

void forEach(int* array, int size, bool (*funcCheck)(int));

int main(){

    const int SIZE = 7;
    int array[SIZE] = {-3, 1, -1, 4, 0, 7, -2};

    auto isPositive = [](int value) { return value > 0; };

    forEach(array, SIZE, isPositive);

    return 0;
}

void forEach(int* array, int size, bool (*funcCheck)(int)) {

    for (int index = 0; index < size; ++index) {

        if (funcCheck(array[index]))
            std::cout << array[index] << " ";
    }
}