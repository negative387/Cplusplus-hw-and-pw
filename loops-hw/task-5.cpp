/**
Завдання 5
Користувач вводить ціле число А. Програма повинна визначити, що куб суми цифр цього числа дорівнює А*А.
**/

#include <iostream>

int main() {
    int numberA;
    int sumDigitsA = 0;

    std::cout << "Введіть число:";
    std::cin >> numberA;

    int numberLoopA = numberA;
    do {
        sumDigitsA += numberLoopA % 10;
        numberLoopA /= 10;

    } while (numberLoopA != 0);

    if (sumDigitsA * sumDigitsA * sumDigitsA == numberA * numberA)
        std::cout << "Куб суми цифр " << numberA << " дорівнює " << numberA << " * " << numberA <<"!";
    else
        std::cout << "Куб суми цифр " << numberA << " НЕ дорівнює " << numberA << " * " << numberA <<"!";
}