#include "utils.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

void saveCurrentGame(const GameBoard &playerBoard, const GameBoard &enemyBoard, const PlayerProfile &profile, bool &isPlayerTurn) {
    std::ofstream outputFile("savegame.txt");

    if (!outputFile) { return; }

    for (int yIndexPlayer = 0; yIndexPlayer < BOARD_SIZE; ++yIndexPlayer) {
        for (int xIndexPlayer = 0; xIndexPlayer < BOARD_SIZE; ++xIndexPlayer) {
            outputFile << playerBoard.grid[yIndexPlayer][xIndexPlayer] << ' ';
        }
        outputFile << '\n';
    }
    for (int yIndexEnemy = 0; yIndexEnemy < BOARD_SIZE; ++yIndexEnemy) {
        for (int xIndexEnemy = 0; xIndexEnemy < BOARD_SIZE; ++xIndexEnemy) {
            outputFile << enemyBoard.grid[yIndexEnemy][xIndexEnemy] << ' ';
        }
        outputFile << '\n';
    }
    outputFile << playerBoard.aliveShipsCount << ' ' << enemyBoard.aliveShipsCount << ' ' << isPlayerTurn << ' ' << profile.totalShotsCount << ' ' << profile.playerName;
    outputFile.close();
    std::cout << "Гра збережена!\n";
}

bool loadSavedGame(GameBoard &playerBoard, GameBoard &enemyBoard, PlayerProfile &profile, bool &isPlayerTurn) {
    std::ifstream inputFile("savegame.txt");

    if (!inputFile.is_open()) { return false; }

    for (int yIndexPlayer = 0; yIndexPlayer < BOARD_SIZE; ++yIndexPlayer) {
        for (int xIndexPlayer = 0; xIndexPlayer < BOARD_SIZE; ++xIndexPlayer) {
            inputFile >> playerBoard.grid[yIndexPlayer][xIndexPlayer];
        }
    }
    for (int yIndexEnemy = 0; yIndexEnemy < BOARD_SIZE; ++yIndexEnemy) {
        for (int xIndexEnemy = 0; xIndexEnemy < BOARD_SIZE; ++xIndexEnemy) {
            inputFile >> enemyBoard.grid[yIndexEnemy][xIndexEnemy];
        }
    }
    inputFile >> playerBoard.aliveShipsCount >> enemyBoard.aliveShipsCount >> isPlayerTurn >> profile.totalShotsCount >> profile.playerName;
    std::cout << "Гру успішно завантажено!";
    return true;
}

void updateLeaderboard(const PlayerProfile &profile) {
    std::ofstream outputFile("leaderboard.txt", std::ios::app);

    if (!outputFile) { return; }

    outputFile << profile.playerName << ' ' << profile.gamesWonCount << ' ' << profile.successfulShotsCount << ' ' << profile.totalShotsCount << '\n';
}

void printLeaderboard() {
    PlayerProfile records[100];
    int count = 0;
    std::ifstream inputFile("leaderboard.txt");

    while (inputFile >> records[count].playerName >> records[count].gamesWonCount >> records[count].successfulShotsCount >> records[count].totalShotsCount) {
        count++;
    }
    std::sort(records, records + count, [](const PlayerProfile &a, const PlayerProfile &b) { return a.gamesWonCount > b.gamesWonCount; });

    std::cout << "--------------------------------\n" << "| | ІМ'Я | ПЕРЕМОГИ | ВЛУЧАННЯ |\n";
    for (int countPlace = 0; countPlace < count && countPlace < 5; ++countPlace) {
        std::cout << '|' << countPlace + 1 << "|  " << std::left << std::setw(10) << records[countPlace].playerName << std::left << std::setw(5) << records[countPlace].gamesWonCount
        << std::right << std::setw(5) << records[countPlace].successfulShotsCount << '/' <<  records[countPlace].totalShotsCount << '\n';
    }
    std::cout << "--------------------------------\n";
}
