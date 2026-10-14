#include "Circle.h"

Circle::Circle() {}

Circle::Circle(int xCenter, int yCenter, int radius) {
    this->xCenter = (xCenter < 0) ? 0 : xCenter;
    this->yCenter = (yCenter < 0) ? 0 : yCenter;
    this->radius = (radius < 1) ? 1 : radius;
}

int Circle::getXCenter() const { return xCenter; }

int Circle::getYCenter() const { return yCenter; }

int Circle::getRadius() const { return radius; }

void Circle::setXCenter(int xCenter) { this->xCenter = (xCenter < 0) ? 0 : xCenter; }

void Circle::setYCenter(int yCenter) { this->yCenter = (yCenter < 0) ? 0 : yCenter; }

void Circle::setRadius(int radius) { this->radius = (radius < 1) ? 1 : radius; }

void Circle::show() const {
    //Проходимо по вертикалі з невеликим запасом:
    for (int yCount = 0; yCount < yCenter + radius + 2; yCount++) {

        if (yCount < yCenter - radius) {
            std::cout << '\n';
            continue;
        }

        //Малюєм рядок зліва направо від 0 до правого краю кола з запасом:
        for (int xCount = 0; xCount < xCenter + (radius * 2) + 4; xCount++) {

            //Рахуєм відстань від центра:
            double distanceX = (xCount - xCenter) / 2.0;
            double distanceY = yCount - yCenter;
            double currentRadiusSquared = (distanceX * distanceX) + (distanceY * distanceY);
            //Оптимальні межі для товщини країв (#):
            double innerBoundary = (radius - 0.8) * (radius - 0.8);
            double outerBoundary = (radius + 0.8) * (radius + 0.8);

            if (currentRadiusSquared >= innerBoundary && currentRadiusSquared <= outerBoundary) {
                std::cout << "#";
            } else {
                std::cout << " ";
            }
        }
        std::cout << '\n';
    }
}

void Circle::save() const {
    std::ofstream saveFile("save.txt", std::ios::app);

    if (!saveFile.is_open()) {
        std::cout << "ПОМИЛКА! Фіг знає чому не відкрился файл для збереження!";
        return;
    }

    saveFile << "Circle " << xCenter << ' ' << yCenter << ' ' << radius << '\n';
    saveFile.close();
    std::cout << "Коло збережено!\n";
}

void Circle::load() {
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
            int x, y, width, height;
            saveFile >> x >> y >> width >> height;
        }
        else if (shapeType == "Circle") {
            saveFile >> xCenter >> yCenter >> radius;
            std::cout << "Коло завантажено!\n";
            return;
        }
        else if (shapeType == "Ellipse") {
            int x, y, width, height;
            saveFile >> x >> y >> width >> height;
        }
    }

    std::cout << "ПОМИЛКА! У файлі взагалі немає жодного кола! =(\n";
}
