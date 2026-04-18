/*Рівень 1: Базовий (Синтаксис та Виправлення)
Фокус: Робота з типами даних, cout та cin.

"2. Декларатор": Створити програму, де потрібно оголосити 5 різних змінних (ціле число, дробове число, символ,
рядок, логічне значення), присвоїти їм значення та вивести їх у консоль одним довгим рядком.*/



#include <iostream>
#include <string>

int main() {
    short number = 10;
    float numberFloat = 2.5;
    char symbol = 'a';
    std::string word = "privit";
    bool logical = true;
    std::cout << number << '|' << numberFloat << '|' << symbol << '|' << word << '|' << logical;
}