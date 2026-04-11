/*
Завдання 5
Напишіть функцію, яка визначає, чи є "щасливим" шестизначне число.
*/

#include <iostream>

void luckyNumber(int sixDigitNumber);

int main() {

    int userNumber;

    do {
        std::cout << "Введіть шестизначне число: ";
        std::cin >> userNumber;

        if (userNumber < 100000 || userNumber > 999999) {
            std::cout << "ПОМИЛКА! Ваше число не шестизначне!" << std::endl;
            continue;
        }
        break;

    } while (true);

    luckyNumber(userNumber);

    return 0;
}

void luckyNumber(int sixDigitNumber) {

    int startDigits = sixDigitNumber / 1000;
    int endDigits = sixDigitNumber % 1000;

    int endSumDigit = 0;
    int startSumDigit = 0;

    for (int count = 0; count < 3; ++count) {

        startSumDigit += startDigits % 10;
        startDigits /= 10;
        endSumDigit += endDigits % 10;
        endDigits /= 10;
    }

    if (startSumDigit == endSumDigit) std::cout << "Це щасливе число! :)";
    else std::cout << "Це не щасливе число! :( ";
}
