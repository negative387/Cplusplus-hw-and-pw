/*
Рівень 2: Логіка (Шаблони та Передача за адресою)
Фокус: Написання узагальненого коду та зміна даних через функції.

2. «Справжній обмін» (Вказівники як параметри): Якщо передати змінні у функцію
звичайним способом і спробувати їх поміняти місцями, в оригіналі нічого не
зміниться (бо передаються копії). Напишіть функцію SwapValues, яка приймає два
вказівники на цілі числа. Всередині функції поміняйте місцями значення, на
які вони вказують. Перевірте роботу в main: створіть дві змінні, виведіть їх,
викличте функцію (передавши їхні адреси через &) і виведіть знову.
*/


#include <iostream>

void swapValues(int *numberOne, int *numberTwo);

int main() {
    int numberOne = 10;
    int numberTwo = 20;

    std::cout << "Перший до: " << numberOne << "; Другий до: " << numberTwo << std::endl;

    swapValues(&numberOne, &numberTwo);

    std::cout << "Перший після: " << numberOne << "; Другий після: " << numberTwo << std::endl;

    return 0;
}

void swapValues(int *numberOne, int *numberTwo) {
    int temp = *numberOne;
    *numberOne = *numberTwo;
    *numberTwo = temp;
}