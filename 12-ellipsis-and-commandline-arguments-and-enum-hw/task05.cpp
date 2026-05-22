/*
Завдання 5. Створіть програму-калькулятор через командний рядок. Вона має приймати три аргументи: число1, операція (+, -, x, /)
та число2. Наприклад: ./calc 10 + 5. Виведіть результат. Не забудьте про перевірку кількості аргументів (argc == 4).
*/


#include <iostream>
#include <sstream>

int strToInt(const char* str, bool& success);


int main(int argc, char* argv[]) {

    if (argc != 4) {
        std::cout << "Пишіть: " << argv[0] << " число  оператор(+, -, x, /)  число" << std::endl;
        std::cout << "Приклад: " << argv[0] << " 2 x 3" << std::endl;
        exit(1);
    }

    bool element01, element03;
    int numberLeft  = strToInt(argv[1], element01);
    int numberRight = strToInt(argv[3], element03);

    if (!element01 || !element03) {
        std::cout << "ПОМИЛКА! Потрібно цілі числа." << std::endl;
        exit(1);
    }

    char operat = argv[2][0];

    if (operat == '+')
        std::cout << numberLeft << " + " << numberRight << " = " << (numberLeft + numberRight) << std::endl;
    else if (operat == '-')
        std::cout << numberLeft << " - " << numberRight << " = " << (numberLeft - numberRight) << std::endl;
    else if (operat == 'x')
        std::cout << numberLeft << " x " << numberRight << " = " << (numberLeft * numberRight) << std::endl;
    else if (operat == '/') {

        if (numberRight == 0) {
            std::cout << "ПОМИЛКА! Ділення на нуль." << std::endl;
            exit(1);
        }
        std::cout << numberLeft << " / " << numberRight << " = " << (numberLeft / numberRight) << std::endl;

    }
    else {
        std::cout << "ПОМИЛКА! Невідомий оператор \'" << operat << "\'" << std::endl;
        std::cout << "Можливі оператори: + - x /" << std::endl;
        exit(1);
    }

    return 0;
}

//Вповністю скопіював цю функцію з kostyl:
int strToInt(const char* str, bool& success) {

    std::stringstream ss(str);
    int result;
    success = static_cast<bool>(ss >> result);
    return result;
}
