/*
Рівень 2: Логіка та Обробка даних (Алгоритми)
Фокус: Математичні операції та послідовність дій.

3. "Магія остачі": Користувач вводить двозначне число. Програма повинна вивести окремо першу цифру і окремо
другу. Підказка: використовуйте / 10 та % 10.
*/



#include <iostream>

int main() {
    short twoDigitNumber;

    std::cout << "Будь-ласка напишить ДВОХ-ЗНАЧНЕ число (я ще не вмію try-except C++): ";
    std::cin >> twoDigitNumber;

    short firstDigit = twoDigitNumber / 10;
    short secondDigit = twoDigitNumber % 10;

    std::cout << "Перша цифра: " << firstDigit << " | Друга цифра: " << secondDigit;
}