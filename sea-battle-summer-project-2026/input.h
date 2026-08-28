#pragma once
#include "structures.h"

int getValidatedMenuChoice(int minCoordinate, int maxCoordinate);
BoardCoordinate getValidatedCoordinates(const std::string& playerCoordinate);
int getValidatedDirection();