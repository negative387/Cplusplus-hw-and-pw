#include "board.h"
#include "utils.h"
#include "game.h"
#include "ship.h"
#include "input.h"
#include "structures.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    GameBoard playerBoard = {};
    GameBoard enemyBoard = {};
    PlayerProfile profile = {};
    bool isPlayerTurn = true;
    int menuChoice = 0;

    while (true) {
        system("cls");
        std::cout << "\033[36m---МОРСЬКИЙ БІЙ---\n" << RESET_TEXT;
        std::cout << BLUE_TEXT << "1 - Нова Гра\n" << RESET_TEXT
                  << BLUE_TEXT << "2 - Продовжити\n" << RESET_TEXT
                  << BLUE_TEXT << "3 - Таблиця Лідерів\n" << RESET_TEXT
                  << BLUE_TEXT << "4 - Вихід\n" << RESET_TEXT
		          << BLUE_TEXT << "НОТАТКА:\n" << RESET_TEXT
		          << BLUE_TEXT << "1. Вказуємо координати, починаючи з англійської літери (приклад: \"b5\")\n" << RESET_TEXT
		          << BLUE_TEXT << "2. Щоб зберегтись, введіть - \"0\" у рядку з координатами\n\n" << RESET_TEXT
		          << "Введіть цифру варіант: ";
        std::cin >> menuChoice;

        switch (menuChoice) {
        case 1:
            startNewGame();
            break;
        case 2:
            if (loadSavedGame(playerBoard, enemyBoard, profile, isPlayerTurn)) {
                playGameLoop(playerBoard, enemyBoard, profile, isPlayerTurn);
                updateLeaderboard(profile);
            } else {
                std::cout << RED_TEXT << "Немає збереження! :(" << RESET_TEXT;
                system("pause");
            }
            break;
        case 3:
            printLeaderboard();
            system("pause");
            break;
        case 4:
            std::cout << GREEN_TEXT << "Допобачення..." << RESET_TEXT;
            return 0;
        }
    }
    return 0;
}
