#include "Ellipse.h"

Ellipse::Ellipse() {}

Ellipse::Ellipse(int xTopLeftCorner, int yTopLeftCorner, int width, int height) {
    this->xTopLeftCorner = (xTopLeftCorner < 0) ? 0 : xTopLeftCorner;
    this->yTopLeftCorner = (yTopLeftCorner < 0) ? 0 : yTopLeftCorner;
    this->width = (width < 2) ? 2 : width;
    this->height = (height < 2) ? 2 : height;
}

int Ellipse::getXTopLeftCorner() const { return xTopLeftCorner; }

int Ellipse::getYTopLeftCorner() const { return yTopLeftCorner; }

int Ellipse::getWidth() const { return width; }

int Ellipse::getHeight() const { return height; }

void Ellipse::setXTopLeftCorner(int xTopLeftCorner) { this->xTopLeftCorner = (xTopLeftCorner < 0) ? 0 : xTopLeftCorner; }

void Ellipse::setYTopLeftCorner(int yTopLeftCorner) { this->yTopLeftCorner = (yTopLeftCorner < 0) ? 0 : yTopLeftCorner; }

void Ellipse::setWidth(int width) { this->width = (width < 2) ? 2 : width; }

void Ellipse::setHeight(int height) { this->height = (height < 2) ? 2 : height; }

void Ellipse::show() const {

    double xCenter = xTopLeftCorner + (width / 2.0);
    double yCenter = yTopLeftCorner + (height / 2.0);
    double radiusX = width / 2.0;
    double radiusY = height / 2.0;

    //Перебираємо рядки від 0 до нижньої межі фігури з запасом:
    for (int yCount = 0; yCount < yTopLeftCorner + height + 2; yCount++) {

        if (yCount < yTopLeftCorner) {
            std::cout << '\n';
            continue;
        }

        //Йдемо зліва направо від 0 до кінця фігури з урахуванням розтягнення консольнолі:
        for (int xCount = 0; xCount < (xTopLeftCorner + width) * 2 + 4; xCount++) {

            double distanceX = ((xCount / 2.0) - xCenter) / radiusX;
            double distanceY = (yCount - yCenter) / radiusY;;
            double ellipseValue = (distanceX * distanceX) + (distanceY * distanceY);
            // Робимо товщину стінок фігури (#):
            double innerBoundary = 0.75;
            double outerBoundary = 1.25;

            if (ellipseValue >= innerBoundary && ellipseValue <= outerBoundary) {
                std::cout << "#";
            } else {
                std::cout << " ";
            }
        }
        std::cout << '\n';
    }
}

void Ellipse::save() const {
    std::ofstream saveFile("save.txt", std::ios::app);

    if (!saveFile.is_open()) {
        std::cout << "ПОМИЛКА! Фіг знає чому не відкрился файл для збереження!";
        return;
    }

    saveFile << "Ellipse " << xTopLeftCorner << ' ' << yTopLeftCorner << ' ' << width << ' ' << height << '\n';
    saveFile.close();
    std::cout << "Еліпс збережено!\n";
}

void Ellipse::load() {
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
            int x, y, radius;
            saveFile >> x >> y >> radius;
        }
        else if (shapeType == "Ellipse") {
            saveFile >> xTopLeftCorner >> yTopLeftCorner >> width >> height;
            std::cout << "Еліпс завантажено!\n";
            return;
        }
    }
    std::cout << "ПОМИЛКА! У файлі взагалі немає жодного еліпса! =(\n";
}
