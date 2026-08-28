#pragma once
#include <string>

#define RESET_TEXT   "\033[0m"
#define RED_TEXT     "\033[31m"
#define GREEN_TEXT   "\033[32m"
#define BLUE_TEXT    "\033[34m"

const int BOARD_SIZE = 10;
const int DIR_UP = 1;
const int DIR_RIGHT = 2;
const int DIR_DOWN = 3;
const int DIR_LEFT = 4;

struct PlayerProfile {
    std::string playerName;
    int totalShotsCount;
    int successfulShotsCount;
    int gamesWonCount;
};

struct BoardCoordinate {
    int x;
    int y;
};

struct GameBoard {
    char grid[BOARD_SIZE][BOARD_SIZE];
    int aliveShipsCount;
};