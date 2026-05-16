/*
Завдання 5. Реалізуйте таблицю диспетчеризації для простого калькулятора:

- Функції add, subtract, multiply, divide (з перевіркою ділення на нуль).
- Масив вказівників int (*operations[4])(int, int).
- Функція getOperation(char op), що повертає відповідний вказівник із масиву.
- У main зчитайте два числа та символ операції, знайдіть та викличте відповідну функцію.
*/


#include <iostream>


int add(int numberOne, int numberTwo);
int subtract(int numberOne, int numberTwo);
int multiply(int numberOne, int numberTwo);
int divide(int numberOne, int numberTwo);
int (*operations[4])(int, int) = { add, subtract, multiply, divide };
int (*getOperation(char operation))(int, int);

int main() {

    int (*functionPtr)(int, int) = nullptr;
    int numberOne;
    int numberTwo;
    char operation;

    std::cout << "Введіть \" число1 операція(+ - * /) число2 \" :";

    std::cin >> numberOne;
    std::cin >> operation;
    std::cin >> numberTwo;

    functionPtr = getOperation(operation);

    if (functionPtr != nullptr)
        std::cout << numberOne << " "  << operation << " " << numberTwo << " = "<< functionPtr(numberOne, numberTwo);

    return 0;
}

int add(int numberOne, int numberTwo) { return numberOne + numberTwo; }
int subtract(int numberOne, int numberTwo) { return numberOne - numberTwo; }
int multiply(int numberOne, int numberTwo) { return numberOne * numberTwo; }
int divide(int numberOne, int numberTwo) {
    if (numberTwo == 0) {
        std::cout << "ПОМИЛКА! Ділення на нуль! :";
        return 0;
    }
    return numberOne / numberTwo;
}

int (*getOperation(char operation))(int, int) {

    if (operation == '+')
        return operations[0];
    else if (operation == '-')
        return operations[1];
    else if (operation == '*')
        return operations[2];
    else if (operation == '/')
        return operations[3];
    else {
        std::cout << "ПОМИЛКА! Невірна введена операція!";
        return nullptr;
    }
}

