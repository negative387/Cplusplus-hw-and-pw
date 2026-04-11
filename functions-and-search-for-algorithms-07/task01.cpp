/*
Завдання 1
Написати функцію, яка приймає два параметри: основу степеня та показник степеня і обчислює
ступінь числа на основі отриманих даних.
*/

#include <iostream>

double raiseToThePower(double base, int exponent);


int main() {
    double userBase;
    int userExponent;

    std::cout << "Введіть основу степеня:";
    std::cin >> userBase;
    std::cout << "Введіть показник степеня:";
    std::cin >> userExponent;

    std::cout << "Результат: " << raiseToThePower(userBase, userExponent);

    return 0;
}


double raiseToThePower(double base, int exponent) {
    double result = 1;

    for (int count = 0; count < exponent; ++count)
        result *= base;
    return result;
}