/**
Завдання 3
Користувач вводить будь-яке ціле число. Необхідно з цього цілого числа видалити всі цифри 3 і 6 та вивести назад на екран.
**/

#include <iostream>

int main() {
    int userNumber;
    int resultReverseNumber = 0;
    int resultNumber = 0;

    std::cout << "Введіть число:";
    std::cin >> userNumber;

    //Сортируємо цифри та додаємо перевернуто у змінну:
    do {
        if (userNumber % 10 != 3 && userNumber % 10 != 6) {
            resultReverseNumber = resultReverseNumber * 10 + userNumber % 10;
            userNumber /= 10;
        }
        else
            userNumber /= 10;
    }
    while (userNumber != 0);

    //Перевертаємо цифри у фінальну змінну:
    do {
        resultNumber = resultNumber * 10 + resultReverseNumber % 10;
        resultReverseNumber /= 10;
    } while (resultReverseNumber != 0);

    std::cout << resultNumber;
}