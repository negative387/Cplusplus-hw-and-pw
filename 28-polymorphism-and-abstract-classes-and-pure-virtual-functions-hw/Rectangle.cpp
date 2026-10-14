#include "Rectangle.h"

Rectangle::Rectangle() {}

Rectangle::Rectangle(int xTopLeftCorner, int yTopLeftCorner, int width, int height) {
    this->xTopLeftCorner = (xTopLeftCorner < 0) ? 0 : xTopLeftCorner;
    this->yTopLeftCorner = (yTopLeftCorner < 0) ? 0 : yTopLeftCorner;
    this->width = (width < 1) ? 1 : width;
    this->height = (height < 1) ? 1 : height;
}

int Rectangle::getXTopLeftCorner() const { return xTopLeftCorner; }

int Rectangle::getYTopLeftCorner() const { return yTopLeftCorner; }

int Rectangle::getWidth() const { return width; }

int Rectangle::getHeight() const { return height; }

void Rectangle::setXTopLeftCorner(int xTopLeftCorner) { this->xTopLeftCorner = (xTopLeftCorner < 0) ? 0 : xTopLeftCorner; }

void Rectangle::setYTopLeftCorner(int yTopLeftCorner) { this->yTopLeftCorner = (yTopLeftCorner < 0) ? 0 : yTopLeftCorner; }

void Rectangle::setWidth(int width) { this->width = (width < 1) ? 1 : width; }

void Rectangle::setHeight(int height) { this->height = (height < 1) ? 1 : height; }

void Rectangle::show() const {
    for (int count = 0; count < yTopLeftCorner; count++) {
        std::cout << '\n';
    }

    for (int row = 0; row < height; row++) {

        for (int space = 0; space < xTopLeftCorner; space++) {
            std::cout << " ";
        }

        for (int column = 0; column < width; ++column) {
            if (row == 0 || row == height - 1 || column == 0 || column == width - 1) {
                std::cout << "# ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << '\n';
    }
}

void Rectangle::save() const {
    std::ofstream saveFile("save.txt", std::ios::app);

    if (!saveFile.is_open()) {
        std::cout << "ПОМИЛКА! Фіг знає чому не відкрился файл для збереження!";
        return;
    }

    saveFile << "Rectangle " << xTopLeftCorner << ' ' << yTopLeftCorner << ' ' << width << ' ' << height << '\n';
    saveFile.close();
    std::cout << "Прямокутник збережен!\n";
}

void Rectangle::load() {
    std::ifstream saveFile("save.txt");

    if (!saveFile.is_open()) {
        std::cout << "ПОМИЛКА! Фіг знає чому не відкрился файл з збереженням!";
        return;
    }

    std::string shapeType;

    while (saveFile >> shapeType) {
        if (shapeType == "Square") {
            int x, y, side;
            saveFile >> x >> y >> side;
        }
        else if (shapeType == "Rectangle") {
            saveFile >> xTopLeftCorner >> yTopLeftCorner >> width >> height;
            std::cout << "Прямокутник завантажено!\n";
            return;
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

    std::cout << "ПОМИЛКА! У файлі взагалі немає жодного прямокутника! =(\n";
}
