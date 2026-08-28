#include "game.h"
#include "utils.h"
#include "board.h"
#include "input.h"
#include "ship.h"
#include <iostream>

static bool isHuntingMode = true;
static BoardCoordinate firstHit = {-1, -1};
static BoardCoordinate lastHit = {-1, -1};
static int currentDirection = 1;

void startNewGame() {
    resetBotMemory();
	GameBoard playerBoard = {};
    GameBoard enemyBoard = {};
    PlayerProfile profile = {};
    bool isPlayerTurn = true;
    std::cout << "Введіть ваше ім'я: ";
    std::cin >> profile.playerName;
    std::cin.ignore(1000, '\n');

    initializeBoard(playerBoard);
    initializeBoard(enemyBoard);
    placeShipsManually(playerBoard);
    placeShipsRandomly(enemyBoard);
    playGameLoop(playerBoard, enemyBoard, profile, isPlayerTurn);
    updateLeaderboard(profile);
}
void playGameLoop(GameBoard &playerBoard, GameBoard &enemyBoard, PlayerProfile &profile, bool isPlayerTurn) {
    std::string playerInputCoordinate;
    BoardCoordinate playerCoordinate{};
    BoardCoordinate enemyCoordinate{};

    while (playerBoard.aliveShipsCount > 0 && enemyBoard.aliveShipsCount > 0) {
        system("cls");

        if (isPlayerTurn) {
            drawBoardsSideBySide(playerBoard, enemyBoard);
            std::cout << "Ваш хід! Введіть координати для пострілу: ";
            std::cin >> playerInputCoordinate;
            std::cin.ignore(1000, '\n');
            playerCoordinate = getValidatedCoordinates(playerInputCoordinate);

            if (playerCoordinate.y == -1 || playerCoordinate.x == -1) {
                std::cout << RED_TEXT << "Неправильний формат координат! Введіть Enter для продовження..." << RESET_TEXT;
                std::cin.get();
                continue;
            }
            else if (playerCoordinate.x == -2 && playerCoordinate.y == -2) {
                saveCurrentGame(playerBoard, enemyBoard, profile, isPlayerTurn);
                system("pause");
                return;
            }
            else if (enemyBoard.grid[playerCoordinate.y][playerCoordinate.x] == '*' ||
                enemyBoard.grid[playerCoordinate.y][playerCoordinate.x] == 'X') {
                std::cout << RED_TEXT << "Ви вже стріляли в цю клітку! Введіть Enter для продовження..." << RESET_TEXT;
                std::cout << std::flush;
                std::cin.get();
                continue;
            }
            profile.totalShotsCount++;

            if (enemyBoard.grid[playerCoordinate.y][playerCoordinate.x] == 'S') {
                profile.successfulShotsCount++;
                enemyBoard.grid[playerCoordinate.y][playerCoordinate.x] = 'X';
                enemyBoard.aliveShipsCount--;
                if (isShipSunk(enemyBoard, playerCoordinate.x, playerCoordinate.y)) {
                    markSunkShipAura(enemyBoard, playerCoordinate.x, playerCoordinate.y);
                    system("cls");
                    drawBoardsSideBySide(playerBoard, enemyBoard);
                    std::cout << "Потопив! Введіть Enter для продовження...";
                }
                else {
                    system("cls");
                    drawBoardsSideBySide(playerBoard, enemyBoard);
                    std::cout << "Влучання! Введіть Enter для продовження...";
                }
                std::cout << std::flush;
                std::cin.get();
            }
            else {
                enemyBoard.grid[playerCoordinate.y][playerCoordinate.x] = '*';
                isPlayerTurn = false;
                system("cls");
                drawBoardsSideBySide(playerBoard, enemyBoard);
                std::cout << "Промах! Введіть Enter для продовження...";
                std::cout << std::flush;
                std::cin.get();
            }
        } else {
            drawBoardsSideBySide(playerBoard, enemyBoard);
            enemyCoordinate = getBotShot(playerBoard);

            if (playerBoard.grid[enemyCoordinate.y][enemyCoordinate.x] == 'S') {
                std::cout << "Хід ворога!\n";
                playerBoard.grid[enemyCoordinate.y][enemyCoordinate.x] = 'X';
                playerBoard.aliveShipsCount--;
                if (isShipSunk(playerBoard, enemyCoordinate.x, enemyCoordinate.y)) {
                    markSunkShipAura(playerBoard, enemyCoordinate.x, enemyCoordinate.y);
                    system("cls");
                    drawBoardsSideBySide(playerBoard, enemyBoard);
                    std::cout << "Ворог потопив Ваш корабль! Введіть Enter для продовження...";
                    resetBotMemory();
                } else {
                    system("cls");
                    drawBoardsSideBySide(playerBoard, enemyBoard);
                    std::cout << "Ворог влучив! Введіть Enter для продовження...";
                    if (isHuntingMode) {
                        isHuntingMode = false;
                        firstHit = enemyCoordinate;
                    }
                    lastHit = enemyCoordinate;
                }
                std::cout << std::flush;
                std::cin.get();
            }
            else if (playerBoard.grid[enemyCoordinate.y][enemyCoordinate.x] == '*' ||
                playerBoard.grid[enemyCoordinate.y][enemyCoordinate.x] == 'X') {
                continue;
            } else {
                std::cout << "Хід ворога!\n";
                playerBoard.grid[enemyCoordinate.y][enemyCoordinate.x] = '*';
                if (!isHuntingMode) {
                    currentDirection++;
                    if (currentDirection > 4) {
                        currentDirection = 1;
                    }
                    lastHit = firstHit;
                }
                isPlayerTurn = true;
                system("cls");
                drawBoardsSideBySide(playerBoard, enemyBoard);
                std::cout << "Ворог промазав! Введіть Enter для продовження...";
                std::cout << std::flush;
                std::cin.get();
            }
        }
    }
    if (enemyBoard.aliveShipsCount == 0) {
        profile.gamesWonCount++;
        std::cout << GREEN_TEXT << "ПЕРЕМОГА! Ви повністю знищили флот ворога!\n" << RESET_TEXT;
        system("pause");
        }
    if (playerBoard.aliveShipsCount == 0) {
        std::cout << RED_TEXT << "Ви програли. Ваш флот повністю знищено!\n" << RESET_TEXT;
        system("pause");
    }
}

void resetBotMemory() {
    isHuntingMode = true;
    currentDirection = 1;
    firstHit = {-1, -1};
    lastHit = {-1, -1};
}

BoardCoordinate getBotShot(const GameBoard &playerBoard) {
    BoardCoordinate target{};

    while (true) {
        if (isHuntingMode) {
            target.x = rand() % BOARD_SIZE;
            target.y = rand() % BOARD_SIZE;
            return target;
        } else {
            switch (currentDirection) {
            case 1:
                target.x = lastHit.x;
                target.y = lastHit.y - 1;
                break;
            case 2:
                target.x = lastHit.x + 1;
                target.y = lastHit.y;
                break;
            case 3:
                target.x = lastHit.x;
                target.y = lastHit.y + 1;
                break;
            case 4:
                target.x = lastHit.x - 1;
                target.y = lastHit.y;
                break;
            }
            if (target.x < 0 || target.x >= 10 || target.y < 0 || target.y >= 10 || playerBoard.grid[target.y][target.x] == '*') {
                if (firstHit.x != lastHit.x || firstHit.y != lastHit.y) {
                    if (currentDirection == 2) { currentDirection = 4; }
                    else if (currentDirection == 4) { currentDirection = 2; }
                    else if (currentDirection == 1) { currentDirection = 3; }
                    else if (currentDirection == 3) { currentDirection = 1; }
                } else { ++currentDirection; }
                if (currentDirection > 4) { currentDirection = 1; }
                lastHit = firstHit;
                continue;
            }
            if (playerBoard.grid[target.y][target.x] == 'X') {
                lastHit = target;
                continue;
            }
        }
        return target;
    }
}