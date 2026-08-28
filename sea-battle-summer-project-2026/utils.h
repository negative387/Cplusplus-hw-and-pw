#pragma once
#include "board.h"

void saveCurrentGame(const GameBoard &playerBoard, const GameBoard &enemyBoard, const PlayerProfile &profile, bool &isPlayerTurn);
bool loadSavedGame(GameBoard &playerBoard, GameBoard &enemyBoard, PlayerProfile &profile, bool &isPlayerTurn);
void updateLeaderboard(const PlayerProfile &profile);
void printLeaderboard();