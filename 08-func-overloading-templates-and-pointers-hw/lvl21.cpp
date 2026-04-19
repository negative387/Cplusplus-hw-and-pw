/*
Рівень 2: Логіка (Шаблони та Передача за адресою)
Фокус: Написання узагальненого коду та зміна даних через функції.

1. «Універсальний пошуковик» (Шаблони функцій): Напишіть шаблонну функцію
FindMax, яка приймає масив та його розмір, а повертає найбільший елемент масиву.
У функції main створіть три масиви: цілих чисел (int), дійсних чисел (double) та
символів (char). Проженіть кожен масив через вашу шаблонну функцію та виведіть
максимальний елемент для кожного типу.
*/

#include <iostream>

template<typename T, int N>
T findMax(T array[N]) {
    T max = array[0];

    for (int count = 0; count < N; ++count) {
        if (array[count] > max)
            max = array[count];
    }
    return max;
}

int main() {
    const int SIZE = 5;
    int intArray[SIZE] = {3, 7, 12, 1, 8};
    double doubleArray[SIZE] = {1.04, 5.5, 9.07, 8.032, 9.1};
    char charArray[SIZE] = {'D', 'A', 'G', 'Z', 'R'};

    std::cout << "Максимальний int: " << findMax<int, SIZE>(intArray) << std::endl;
    std::cout << "Максимальний double: " << findMax<double, SIZE>(doubleArray) << std::endl;
    std::cout << "Максимальний char: " << findMax<char, SIZE>(charArray) << std::endl;

    return 0;
}
