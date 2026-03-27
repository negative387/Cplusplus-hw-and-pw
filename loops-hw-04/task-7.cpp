/**
Завдання 7
Користувач вводить два цілих числа. Необхідно вивести всі цілі числа, на які обидва введених числа діляться без залишку.
**/

#include <iostream>

int main() {
    int userFirstNumber;
    int userSecondNumber;

    std::cout << "Введіть перше число:";
    std::cin >> userFirstNumber;
    std::cout << "Введіть друге число:";
    std::cin >> userSecondNumber;


    for (int count = 1; count <= userFirstNumber && count <= userSecondNumber; ++count) {

        if (userFirstNumber % count == 0 && userSecondNumber % count == 0)
            std::cout << count << " ";
    }

}