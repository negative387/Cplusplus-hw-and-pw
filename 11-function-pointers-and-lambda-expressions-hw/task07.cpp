/*
Завдання 7. Напишіть лямбду square, що зводить число в квадрат. Збережіть її у auto-змінній.
Викличте з аргументами 3, 5, 7 і виведіть результати.
*/


#include <iostream>

int main(){

    auto square = [](int value) { return value * value; };

    std::cout << "3 * 3 = "<< square(3) << std::endl;
    std::cout << "5 * 5 = "<< square(5) << std::endl;
    std::cout << "7 * 7 = "<< square(7) << std::endl;

    return 0;
}