/**
Завдання 6
Користувач вводить ціле число. Необхідно вивести всі цілі числа, на які задане число ділиться без залишку.
**/

#include <iostream>

int main() {
    int userNumber;

    std::cout << "Введіть число:";
    std::cin >> userNumber;

    for (int count = 1; count < userNumber; ++count) {;

        if (userNumber % count == 0)
            std::cout << count << " ";
    }

}