#include <iostream>
#include "Matrix.h"

/*
Завдання:
Створіть шаблонний клас матриця. Необхідно реалізувати динамічне виділення пам’яті, очищення пам’яті,
заповнення матриці з клавіатури, заповнення випадковими значеннями, вивід матриці, арифметичні операції
за допомогою перевантажених операторів (+, –, *, /), пошук максимального та мінімального елементів.
*/

int main() {


    std::cout << "ТЕСТ МАТРИЦЬ int:\n\n";

    Matrix<int> matrixOne(2, 3);
    Matrix<int> matrixTwo(2, 3);

    matrixOne.fillRandom();
    matrixTwo.fillRandom();

    std::cout << "matrixOne:\n";
    matrixOne.print();
    std::cout << "\nmatrixTwo:\n";
    matrixTwo.print();

    std::cout << "\nРезультат додавання (matrixOne + matrixTwo):\n";
    Matrix<int> matrixAdd = matrixOne + matrixTwo;
    matrixAdd.print();

    std::cout << "\nРезультат віднімання (matrixOne - matrixTwo):\n";
    Matrix<int> matrixSub = matrixOne - matrixTwo;
    matrixSub.print();

    std::cout << "\nРезультат множення (matrixOne * matrixTwo):\n";
    Matrix<int> matrixMul = matrixOne * matrixTwo;
    matrixMul.print();


    std::cout << "\nМаксимальний елемент в matrixOne: " << matrixOne.maxElement() << "\n";
    std::cout << "Мінімальний елемент в matrixOne: " << matrixOne.minElement() << "\n\n";


    std::cout << "ТЕСТ МАТРИЦЬ string:\n\n";

    Matrix<std::string> matrixStringOne(2, 2);
    Matrix<std::string> matrixStringTwo(2, 2);

    matrixStringOne.fillRandom();
    matrixStringTwo.fillRandom();

    std::cout << "matrixStringOne:\n"; matrixStringOne.print();
    std::cout << "\nmatrixStringTwo:\n"; matrixStringTwo.print();

    //Поки що тільки додавання для стрінг ¯\_(ツ)_/¯ :
    std::cout << "\nРезультат додавання matrixStringOne + matrixStringTwo:\n";
    Matrix<std::string> matrixStringAdd = matrixStringOne + matrixStringTwo;
    matrixStringAdd.print();

    return 0;
}