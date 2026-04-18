/*
Завдання 4
Напишіть функцію, що виводить на екран передану їй гральну карту.
*/

//Напевно можна було б зробити набагато краще >_<
#include <iostream>
#include <string>

void printCard(std::string rank, std::string suit);

int main() {
    std::string userRank;
    std::string userSuit;

    do {

        std::cout << "Введіть значення картки (A, 2-10, J, Q, K): ";
        std::cin >> userRank;

        if (userRank != "A" && userRank != "2" && userRank != "3" && userRank != "4" && userRank != "5" && userRank != "6" && userRank != "7" && userRank != "8" && userRank != "9" && userRank != "10"  && userRank != "J" && userRank != "Q" && userRank != "K") {
            std::cout << "ПОМИЛКА! Неправильне значення картки!" << std::endl;
            continue;
        }
        std::cout << "Введіть масть картки (1 - ♠ | 2 - ♥ | 3 - ♦ | 4 - ♣): ";
        std::cin >> userSuit;

        if (userSuit == "1") userSuit = "♠";
        else if (userSuit == "2") userSuit = "♥";
        else if (userSuit == "3") userSuit = "♦";
        else if (userSuit == "4") userSuit = "♣";
        else {
            std::cout << "ПОМИЛКА! Неправильна масть картки!" << std::endl;
            continue;
        }

        break;
    } while (true);

    printCard(userRank, userSuit);

    return 0;
}

void printCard(std::string rank, std::string suit) {

    std::cout << "┌───────┐" << std::endl;
    std::cout << "|" << rank;

    if (rank != "10") std::cout << "      |" << std::endl;
    else std::cout << "     |" << std::endl;

    std::cout << "|       |" << std::endl;
    std::cout << "|   " << suit << "   |" << std::endl;
    std::cout << "|       |" << std::endl;
    std::cout << "|     ";

    if (rank != "10") std::cout  << " "<< rank << "|" << std::endl;
    else std::cout << rank << "|" << std::endl;

    std::cout << "└───────┘" << std::endl;

}
