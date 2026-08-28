#include "ship.h"
#include "input.h"
#include "board.h"
#include <iostream>

void placeShipsManually(GameBoard &board) {
    int sizeShips[BOARD_SIZE] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    std::string coordinateInput;
    BoardCoordinate coordinateUser{};
    int directionUser = 0;

    for (int sizeShipIndex = 0; sizeShipIndex < BOARD_SIZE; ++sizeShipIndex) {
        while (true) {
            system("cls");
            drawBoardsSideBySide(board, board);

            std::cout << "Розташування! Розміщуємо координати корабля уздовж " << sizeShips[sizeShipIndex] << " палуби: ";
            std::cin >> coordinateInput;
            coordinateUser = getValidatedCoordinates(coordinateInput);

            if (sizeShips[sizeShipIndex] > 1) { directionUser = getValidatedDirection(); }
            else { directionUser = 1; }

            if (!isPlacementValid(board, coordinateUser.x, coordinateUser.y, sizeShips[sizeShipIndex], directionUser)) {
                std::cout << RED_TEXT << "Помилка! Корабель порушує правила або виходить за межі поля. Введіть Enter для продовження..." << RESET_TEXT;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cin.get();
                continue;
            }
            placeShipOnGrid(board, coordinateUser.x, coordinateUser.y, sizeShips[sizeShipIndex], directionUser);
            std::cin.ignore(1000, '\n');
            break;
        }
    }
}

void placeShipsRandomly(GameBoard &board) {
    int sizeShips[BOARD_SIZE] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    int xRandomIndex = 0;
    int yRandomIndex = 0;
    int directionRandom = 0;

    for (int sizeShipIndex = 0; sizeShipIndex < BOARD_SIZE; ++sizeShipIndex) {
        while (true) {
            xRandomIndex = rand() % BOARD_SIZE;
            yRandomIndex = rand() % BOARD_SIZE;
            directionRandom = rand() % 4 + 1;

            if (!isPlacementValid(board, xRandomIndex, yRandomIndex, sizeShips[sizeShipIndex], directionRandom)) {
                continue;
            }
            placeShipOnGrid(board, xRandomIndex, yRandomIndex, sizeShips[sizeShipIndex], directionRandom);
            break;
        }
    }
}

void placeShipOnGrid(GameBoard &board, int xIndex, int yIndex, int shipSize, int direction) {
    int currentX = 0;
    int currentY = 0;

    for (int shipIndex = 0; shipIndex < shipSize; ++shipIndex) {
        switch(direction) {
        case 1:
            currentX = xIndex;
            currentY = yIndex - shipIndex;
            break;
        case 2:
            currentX = xIndex + shipIndex;
            currentY = yIndex;
            break;
        case 3:
            currentX = xIndex;
            currentY = yIndex + shipIndex;
            break;
        case 4:
            currentX = xIndex - shipIndex;
            currentY = yIndex;
            break;
        }
        board.grid[currentY][currentX] = 'S';
        ++board.aliveShipsCount;
    }
}

bool isPlacementValid(const GameBoard &board, int xIndex, int yIndex, int shipSize, int direction) {
    int currentX = 0;
    int currentY = 0;

    for (int shipIndex = 0; shipIndex < shipSize; ++shipIndex) {
        switch(direction) {
            case 1:
                currentX = xIndex;
                currentY = yIndex - shipIndex;
                break;
            case 2:
                currentX = xIndex + shipIndex;
                currentY = yIndex;
                break;
            case 3:
                currentX = xIndex;
                currentY = yIndex + shipIndex;
                break;
            case 4:
                currentX = xIndex - shipIndex;
                currentY = yIndex;
                break;
        }
        if (currentX < 0 || currentX >= BOARD_SIZE || currentY < 0 || currentY >= BOARD_SIZE) { return false; }
        if (board.grid[currentY][currentX] != '~') { return false; }

        for (int yCheck = -1; yCheck <= 1; ++yCheck) {
            for (int xCheck = -1; xCheck <= 1; ++xCheck) {
                if ((currentY + yCheck) < 0 || (currentY + yCheck) >= BOARD_SIZE ||
                    (currentX + xCheck) < 0 || (currentX + xCheck) >= BOARD_SIZE) {
                continue;
                }
                if (board.grid[currentY + yCheck][currentX + xCheck] != '~') { return false; }
            }
        }
    }
    return true;
}

bool isShipSunk(const GameBoard &board, int shotX, int shotY) {
    bool isSunk = true;
    int checkX = shotX + 1;

    while (checkX < BOARD_SIZE) {
        if (board.grid[shotY][checkX] == 'S') {
            isSunk = false;
            break;
        }
        else if (board.grid[shotY][checkX] == 'X') { ++checkX; }
        else { break; }
    }
    checkX = shotX - 1;

    while (checkX >= 0) {
        if (board.grid[shotY][checkX] == 'S') {
            isSunk = false;
            break;
        }
        else if (board.grid[shotY][checkX] == 'X') { --checkX; }
        else { break; }
    }
    int checkY = shotY + 1;

    while (checkY < BOARD_SIZE) {
        if (board.grid[checkY][shotX] == 'S') {
            isSunk = false;
            break;
        }
        else if (board.grid[checkY][shotX] == 'X') { ++checkY; }
        else { break; }
    }
    checkY = shotY - 1;

    while (checkY >= 0) {
        if (board.grid[checkY][shotX] == 'S') {
            isSunk = false;
            break;
        }
        else if (board.grid[checkY][shotX] == 'X') { --checkY; }
        else { break; }
    }
    return isSunk;
}

void markSunkShipAura(GameBoard &board, int shotX, int shotY) {
    auto markSingleDeckAura = [&board](int currentX, int currentY) {

        for (int shiftY = -1; shiftY <= 1; ++shiftY) {
            for (int shiftX = -1; shiftX <= 1; ++shiftX) {
                int checkX = currentX + shiftX;
                int checkY = currentY + shiftY;

                if (checkX < 0 || checkX >= BOARD_SIZE || checkY < 0 || checkY >= BOARD_SIZE) { continue; }
                if (board.grid[checkY][checkX] == '~') { board.grid[checkY][checkX] = '*'; }
            }
        }
    };
    markSingleDeckAura(shotX, shotY);
    int checkX = shotX + 1;

    while (checkX < BOARD_SIZE && board.grid[shotY][checkX] == 'X') {
        markSingleDeckAura(checkX, shotY);
        ++checkX;
    }
    checkX = shotX - 1;

    while (checkX >= 0 && board.grid[shotY][checkX] == 'X') {
       markSingleDeckAura(checkX, shotY);
       --checkX;
    }
    int checkY = shotY + 1;

    while (checkY < BOARD_SIZE && board.grid[checkY][shotX] == 'X') {
        markSingleDeckAura(shotX, checkY);
        ++checkY;
    }
    checkY = shotY - 1;

    while (checkY >= 0 && board.grid[checkY][shotX] == 'X') {
        markSingleDeckAura(shotX, checkY);
        --checkY;
    }
}