#include "input.h"
#include <iostream>

int getValidatedMenuChoice(int minCoordinate, int maxCoordinate) {return 0;}
BoardCoordinate getValidatedCoordinates(const std::string& playerCoordinate) {
    BoardCoordinate temporaryCoordinate{};

	if(playerCoordinate[0] >= 'A' && playerCoordinate[0] <= 'J' ||
	   playerCoordinate[0] >= 'a' && playerCoordinate[0] <= 'j' ) {

	    temporaryCoordinate.x = std::toupper(playerCoordinate[0]) - 'A';
	    if (playerCoordinate.length() == 2) {
	        temporaryCoordinate.y = playerCoordinate[1] - '0' - 1;
	    }
	    else if (playerCoordinate.length() == 3) {
	        if (playerCoordinate[1] == '1' && playerCoordinate[2] == '0') {
	            temporaryCoordinate.y = 9;
	        }
	        else {
	            temporaryCoordinate.x = -1;
	            temporaryCoordinate.y = -1;
	        }
	    }
	    else {
	        temporaryCoordinate.x = -1;
	        temporaryCoordinate.y = -1;
	    }
	}
	else if (playerCoordinate[0] == '0') {
	    temporaryCoordinate.x = -2;
	    temporaryCoordinate.y = -2;
	}
    else {
        temporaryCoordinate.x = -1;
        temporaryCoordinate.y = -1;
    }
    return temporaryCoordinate;
}

int getValidatedDirection() {
    int choice = 0;

    while (true) {
        std::cout << "Напрямок! Оберіть напрямок (1 - вгору, 2 - вправо, 3 - вниз, 4 - вліво): ";
        std::cin >> choice;
        if (choice < 1 || choice > 4 || std::cin.fail() == true) {
            std::cout << RED_TEXT << "Помилка! Напрямок має бути цифрою від 1 до 4. Натисніть Enter, щоб повторити введення..." << RESET_TEXT;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin.get();
            continue;
        }
        break;
    }
    return choice;
}
