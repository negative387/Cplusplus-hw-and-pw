#include "Square.h"

Square::Square() {}

Square::Square(int xTopLeftCorner, int yTopLeftCorner, int sideLength) {
    //Побачив такий спосіб перевірки на якомусь сайті ( виглядає набагато краще =) ):
    this->xTopLeftCorner = (xTopLeftCorner < 0) ? 0 : xTopLeftCorner;
    this->yTopLeftCorner = (yTopLeftCorner < 0) ? 0 : yTopLeftCorner;
    this->sideLength = (sideLength < 1) ? 1 : sideLength;
}

int Square::getXTopLeftCorner() const { return xTopLeftCorner; }

int Square::getYTopLeftCorner() const { return yTopLeftCorner; }

int Square::getSideLength() const { return sideLength; }

void Square::setXTopLeftCorner(int xTopLeftCorner) { this->xTopLeftCorner = (xTopLeftCorner < 0) ? 0 : xTopLeftCorner; }

void Square::setYTopLeftCorner(int yTopLeftCorner) { this->yTopLeftCorner = (yTopLeftCorner < 0) ? 0 : yTopLeftCorner; }

void Square::setSideLength(int sideLength) { this->sideLength = (sideLength < 1) ? 1 : sideLength; }

void Square::show() const {
    for (int count = 0; count < yTopLeftCorner; count++) {
        std::cout << '\n';
    }

    for (int row = 0; row < sideLength; row++) {

        for (int space = 0; space < xTopLeftCorner; space++) {
            std::cout << " ";
        }

        for (int column = 0; column < sideLength; ++column) {
            if (row == 0 || row == sideLength - 1 || column == 0 || column == sideLength - 1) {
                std::cout << "# ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << '\n';
    }
}

void Square::save() const {
    std::ofstream saveFile("save.txt", std::ios::app);

    if (!saveFile.is_open()) {
        std::cout << "ПОМИЛКА! Фіг знає чому не відкрился файл для збереження!";
        return;
    }

    saveFile << "Square " << xTopLeftCorner << ' ' << yTopLeftCorner << ' ' << sideLength << '\n';
    saveFile.close();
    std::cout << "Квадрат збережен!\n";
}

void Square::load() {
    std::ifstream saveFile("save.txt");

    if (!saveFile.is_open()) {
        std::cout << "ПОМИЛКА! Фіг знає чому не відкрился файл з збереженням!";
        return;
    }

    std::string shapeType;

    while (saveFile >> shapeType) {
        if (shapeType == "Square") {
            saveFile >> xTopLeftCorner >> yTopLeftCorner >> sideLength;
            std::cout << "Квадрат завантажено!\n";
            return;
        }
        else if (shapeType == "Rectangle") {
            int x, y, width, height;
            saveFile >> x >> y >> width >> height;
        }
        else if (shapeType == "Circle") {
            int x, y, radius;
            saveFile >> x >> y >> radius;
        }
        else if (shapeType == "Ellipse") {
            int x, y, width, height;
            saveFile >> x >> y >> width >> height;
        }
    }

    std::cout << "ПОМИЛКА! У файлі взагалі немає жодного квадрата! =(\n";
}
