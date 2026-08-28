#pragma once
#include "structures.h"

void startNewGame();
void playGameLoop(GameBoard &playerBoard, GameBoard &enemyBoard, PlayerProfile &profile, bool isPlayerTurn);
void resetBotMemory();
BoardCoordinate getBotShot(const GameBoard &playerBoard);
