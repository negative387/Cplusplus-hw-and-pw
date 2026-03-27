/**
Завдання 4
Користувач вводить довільне ціле число А. Необхідно вивести всі цілі числа В, для яких А ділитися без залишку
на В*В і не ділитися без залишку на В*В*В.
**/


#include <iostream>

int main() {
    int numberA;

    std::cout << "Введіть число:";
    std::cin >> numberA;

    for (int numberB = 1; numberB * numberB <= numberA; ++numberB) {


        if (numberA % (numberB * numberB) == 0 && numberA % (numberB * numberB * numberB) != 0)
            std::cout << numberB << " ";

    }

}