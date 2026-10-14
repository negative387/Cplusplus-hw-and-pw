#include <iostream>
#include <vector>
#include <fstream>
#include "LinearEquation.h"
#include "QuadraticEquation.h"
#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"

/*
Завдання №1:
Створити абстрактний базовий клас з віртуальною функцією — корені рівняння. Створити похідні класи:
клас лінійних рівнянь і клас квадратних рівнянь. Визначити функцію обчислення коренів рівнянь.

Завдання №2
Створіть абстрактний клас Shape для малювання плоских фігур. Визначте віртуальні методи:
- Show () — виведення на екран інформації про фігуру,
- Save () — збереження фігури в файл,
- Load () — зчитування фігури з файлу.
Визначте похідні класи:
- Square — квадрат, який характеризується координатами лівого верхнього кута і довжиною сторони
- Rectangle — прямокутник із заданими координатами верхнього лівого кута і розмірами
- Circle — коло із заданими координатами центра і радіусом
- Ellipse — еліпс з заданими координатами верхнього кута описаного навколо нього прямокутника зі
сторонами, паралельними осям координат, і розмірами цього прямокутника.
Створіть масив фігур, збережіть фігури в файл, завантажте в інший масив і виведіть на екран інформацію
про кожну з фігур
*/

int main() {
    std::ofstream clearFile("save.txt");
    clearFile.close();

    std::cout << "ЗАВДАННЯ 1:\n\n";

    //Створюємо лінійне рівняння 2x - 4 = 0:
    std::cout << "Створюємо лінійне рівняння 2x - 4 = 0:\n";
    LinearEquation linear(2, -4);
    linear.print();

    std::vector<double> linearRoots = linear.findRoots();
    std::cout << "Корені: ";
    for (double root : linearRoots) {
        std::cout << root << " ";
    }
    std::cout << "\n-------------------------\n";

    //Створюємо квадратне рівняння x^2 - 5x + 6 = 0:
    std::cout << "Створюємо квадратне рівняння x^2 - 5x + 6 = 0:\n";
    QuadraticEquation quadratic(1, -5, 6);
    quadratic.print();

    std::vector<double> quadraticRoots = quadratic.findRoots();
    std::cout << "Корені: ";
    for (double root : quadraticRoots) {
        std::cout << root << " ";
    }
    std::cout << "\n-------------------------\n";


    std::cout << "\nЗАВДАННЯ 2:\n";

    std::vector<Shape*> figuresOriginal;
    figuresOriginal.push_back(new Square(4, 2, 5));
    figuresOriginal.push_back(new Rectangle(2, 1, 8, 4));
    figuresOriginal.push_back(new Circle(14, 7, 5));
    figuresOriginal.push_back(new Ellipse(3, 2, 12, 6));


    //Зберігаємо орігінал у файл:
    std::cout << "\nЗберігаємо орігінал у файл:\n";
    for (int index = 0; index < figuresOriginal.size(); index++) {
        figuresOriginal[index]->save();
    }

    for (int index = 0; index < figuresOriginal.size(); index++) {
        delete figuresOriginal[index];
    }
    figuresOriginal.clear();

    std::vector<Shape*> figuresCopy;

    //Відкриваємо файл щоб дізнатися послідовність фігур:
    std::ifstream checkFile("save.txt");
    if (!checkFile.is_open()) {
        std::cout << "ПОМИЛКА! Не вдалося відкрити файл save.txt для розпізнавання фігур!\n";
        return 1;
    }

    std::string typeInFile;

    //Завантажуємо орігінал з файлу у копию:
    std::cout << "\nЗавантажуємо орігінал з файлу у копию:\n";
    while (checkFile >> typeInFile) {
        Shape* temporaryShape = nullptr;

        if (typeInFile == "Square") {
            temporaryShape = new Square();
            int x, y, side;
            checkFile >> x >> y >> side;
        }
        else if (typeInFile == "Rectangle") {
            temporaryShape = new Rectangle();
            int x, y, width, height;
            checkFile >> x >> y >> width >> height;
        }
        else if (typeInFile == "Circle") {
            temporaryShape = new Circle();
            int x, y, radius;
            checkFile >> x >> y >> radius;
        }
        else if (typeInFile == "Ellipse") {
            temporaryShape = new Ellipse();
            int x, y, width, height;
            checkFile >> x >> y >> width >> height;
        }
        if (temporaryShape != nullptr) {
            temporaryShape->load();
            figuresCopy.push_back(temporaryShape);
        }
    }
    checkFile.close();

    //Виводимо фігури з копії:
    std::cout << "\nВиводимо фігури з копії:\n";
    for (int index = 0; index < figuresCopy.size(); index++) {
        std::cout << "\n-------------------------\n";
        figuresCopy[index]->show();
    }

    for (int index = 0; index < figuresCopy.size(); index++) {
        delete figuresCopy[index];
    }

    return 0;
}