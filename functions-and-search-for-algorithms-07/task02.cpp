/*
Завдання 2
Написати функцію, яка отримує як параметри 2 цілих числа і повертає суму
чисел з діапазону між ними.
*/

#include <iostream>

int rangeSum(int start, int end);

int main() {
    int userStartNumber;
    int userEndNumber;

    std::cout << "Введіть число початку діапазону:";
    std::cin >> userStartNumber;
    std::cout << "Введіть число кінця діапазону:";
    std::cin >> userEndNumber;

    std::cout << "Результат: " << rangeSum(userStartNumber, userEndNumber);

    return 0;
}

int rangeSum(int start, int end) {
    int result = 0;

    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
    }

    for (int numberInRange = start + 1; numberInRange < end; ++numberInRange)
        result += numberInRange;
    return result;
}