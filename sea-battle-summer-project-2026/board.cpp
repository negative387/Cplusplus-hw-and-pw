#include "board.h"
#include <iostream>
#include <iomanip>

void drawBoardsSideBySide(const GameBoard &playerBoard, const GameBoard &enemyBoard) {
    std::cout << "         ГРАВЕЦЬ                         КОМП'ЮТЕР\n" << std::right <<"  ";
    for (int count = 0; count < BOARD_SIZE; ++count)
        std::cout << std::setw(2) << static_cast<char>('A' + count);
    std::cout << "             ";
    for (int count = 0; count < BOARD_SIZE; ++count)
       std::cout << std::setw(2) << static_cast<char>('A' + count);
    std::cout << '\n';

    for (int yIndex = 0; yIndex < BOARD_SIZE; ++yIndex) {
        std::cout << std::left << std::setw(3) << yIndex + 1 ;
        for (int xIndex = 0; xIndex < BOARD_SIZE; ++xIndex) {
            if (playerBoard.grid[yIndex][xIndex] == '~') {
                std::cout << BLUE_TEXT << playerBoard.grid[yIndex][xIndex] << RESET_TEXT << ' ';
            }
            else if (playerBoard.grid[yIndex][xIndex] == 'S') {
                std::cout << GREEN_TEXT << playerBoard.grid[yIndex][xIndex] << RESET_TEXT << ' ';
            }
            else if (playerBoard.grid[yIndex][xIndex] == 'X') {
                std::cout << RED_TEXT << playerBoard.grid[yIndex][xIndex] << RESET_TEXT << ' ';
            } else {
                std::cout << playerBoard.grid[yIndex][xIndex] << ' ';
            }
        }
        std::cout << "    |     ";
        std::cout << std::left << std::setw(3) << yIndex + 1 ;

        for (int xIndex = 0; xIndex < BOARD_SIZE; ++xIndex) {
            if (enemyBoard.grid[yIndex][xIndex] == '~' || enemyBoard.grid[yIndex][xIndex] == 'S') {
                std::cout << BLUE_TEXT << '~' << RESET_TEXT << ' ';
            }
            else if (enemyBoard.grid[yIndex][xIndex] == 'X') {
                std::cout << RED_TEXT << enemyBoard.grid[yIndex][xIndex] << RESET_TEXT << ' ';
            } else {
                std::cout << enemyBoard.grid[yIndex][xIndex] << ' ';
            }
        }
        std::cout << '\n';
    }
}

void initializeBoard(GameBoard &board) {
    board.aliveShipsCount = 0;

    for (int yIndex = 0; yIndex < BOARD_SIZE; ++yIndex) {
        for (int xIndex = 0; xIndex < BOARD_SIZE; ++xIndex)
            board.grid[yIndex][xIndex] = '~';
    }
}