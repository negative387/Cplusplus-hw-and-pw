/**
Завдання 1
Вивести на екран усі числа від нуля до введеного користувачем числа.
**/

#include <iostream>

int main() {
    int userMaxNumber;
    std::cout << "Введіть максимальне число: ";
    std::cin >> userMaxNumber;

    //Зробив з префіксом (без зайвих копій):
    for (int count = 0; count <= userMaxNumber; ++count) {
        std::cout << count << " ";
    }

}