#include <iostream>
#include "Fraction.h"
#include "Complex.h"

int main() {


    std::cout << "=== Тестування класу Fraction (завдання 1) ===\n\n";

    Fraction fraction1(3, 4);
    Fraction fraction2(2, 5);
    Fraction fractionZeroNumerator(0, 3);

    std::cout << "Перевірка помилки об'єкта з знаменником 0:\n";
    Fraction fractionInvalidDenominator(5, 0);

    std::cout << "\nПерший дріб (fraction1): " << fraction1 << '\n';
    std::cout << "Другий дріб (fraction2): " << fraction2 << "\n\n";

    std::cout << "Додавання (fraction1 + fraction2): " << (fraction1 + fraction2) << '\n';
    std::cout << "Віднімання (fraction1 - fraction2): " << (fraction1 - fraction2) << '\n';
    std::cout << "Множення (fraction1 * fraction2): " << (fraction1 * fraction2) << '\n';
    std::cout << "Ділення (fraction1 / fraction2): " << (fraction1 / fraction2) << "\n\n";

    std::cout << "Перевірка помилки ділення на дріб з чисельником 0:\n";
    Fraction fractionDivZero = fraction1 / fractionZeroNumerator;
    std::cout << "Результат при помилці ділення: " << fractionDivZero << '\n';

    std::cout << "\n==================================================\n\n";


    std::cout << "=== Тестування класу Complex (завдання 2) ===\n\n";

    Complex complex1(4.0, -2.5);
    Complex complex2(1.5, 3.0);
    Complex complexZero(0.0, 0.0);

    std::cout << "Перше число (complex1): " << complex1 << '\n';
    std::cout << "Друге число (complex2): " << complex2 << "\n\n";

    std::cout << "Додавання (complex1 + complex2): " << (complex1 + complex2) << '\n';
    std::cout << "Віднімання (complex1 - complex2): " << (complex1 - complex2) << '\n';
    std::cout << "Множення (complex1 * complex2): " << (complex1 * complex2) << '\n';
    std::cout << "Ділення (complex1 / complex2): " << (complex1 / complex2) << "\n\n";

    std::cout << "Перевірка помилки ділення на нуль для Complex:\n";
    Complex complexDivZero = complex1 / complexZero;
    std::cout << "Результат при помилці: " << complexDivZero << '\n';

    return 0;
}