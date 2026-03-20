/**
Завдання 4
Користувач із клавіатури вводить числа. Порахувати їхню суму і вивести на екран, щойно користувач введе нуль.
**/

#include <iostream>

int main() {
    int userNumber;
    int sumNumber = 0;

    std::cout << "! Введіть 0 для закінчення рахування !" << std::endl;

    do {
        std::cout << "Введіть число:";
        std::cin >> userNumber;
        sumNumber += userNumber;
    } while (userNumber != 0);

    std::cout << "Сума дорівнює: "<< sumNumber;
}