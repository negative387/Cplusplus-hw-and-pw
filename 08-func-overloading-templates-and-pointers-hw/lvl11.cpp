/*
Рівень 1: Базовий (Синтаксис та Розуміння)
Фокус: Механіка перевантаження та базові операції з адресами.

1. «Математик-універсал» (Перевантаження): Створіть три функції з абсолютно однаковим іменем CalculateArea.

- Перша має приймати одне ціле число (сторона квадрата) і повертати його площу.
- Друга — два цілих числа (сторони прямокутника) і повертати площу.
- Третя — одне дійсне число (радіус кола) і повертати площу кола (використайте 3.14). Викличте всі
три функції у main та виведіть результат.
*/


#include <iostream>

double calculateArea(int side);
double calculateArea(int sideOne, int sideTwo);
double calculateArea(double radius);

int main() {
    std::cout << "Площа сторони квадрата: " << calculateArea(5) << std::endl;
    std::cout << "Площа сторони прямокутника: " << calculateArea(5, 6) << std::endl;
    std::cout << "Площа радіуса кола: " << calculateArea(6.0) << std::endl;

    return 0;
}


double calculateArea(int side) {
    return side * side;
}

double calculateArea(int sideOne, int sideTwo) {
    return sideOne * sideTwo;
}

double calculateArea(double radius) {
    return 3.14 * radius * radius;
}