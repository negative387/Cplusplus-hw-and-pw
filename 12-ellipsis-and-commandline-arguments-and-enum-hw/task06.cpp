/*
Завдання 6. Оголосіть класичне перерахування enum ErrorCode { Success, NotFound, AccessDenied,
UnknownError }. Напишіть функцію getErrorMessage(ErrorCode code), яка повертає рядок-опис
помилки. Використайте switch.
*/

#include <iostream>

enum ErrorCode { Success, NotFound, AccessDenied, UnknownError };
const char* getErrorMessage(ErrorCode code);


int main() {

    ErrorCode code = AccessDenied;

    std::cout << "Результат: " << getErrorMessage(code) << std::endl;

    return 0;
}


const char* getErrorMessage(ErrorCode code) {

    switch (code) {
        case Success: return "Доступно";
        case NotFound: return "Не знайдено";
        case AccessDenied: return "Доступ заборонено";
        case UnknownError: return "Невідома помилка";
        default: return "Невідомий :(";
    }
}