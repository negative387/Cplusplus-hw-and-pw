#pragma once
#include "structures.h"

// 1. Функция-судья: проверяет, можно ли поставить корабль по этим координатам
bool isPlacementValid(const GameBoard &board, int xIndex, int yIndex, int shipSize, int direction);

// 2. Функция физического размещения: рисует корабль на поле (заменяет '~' на 'S')
void placeShipOnGrid(GameBoard &board, int xIndex, int yIndex, int shipSize, int direction);

// 3. Главная функция расстановки для Игрока (пошаговый ручной ввод с клавиатуры)
void placeShipsManually(GameBoard &board);

// 4. Главная функция расстановки для Бота (полностью автоматическая случайная генерация)
void placeShipsRandomly(GameBoard &board);

bool isShipSunk(const GameBoard &board, int shotX, int shotY);

void markSunkShipAura(GameBoard &board, int shotX, int shotY);