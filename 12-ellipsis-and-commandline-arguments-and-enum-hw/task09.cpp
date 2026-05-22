/*
Завдання 9. Об'єднайте теми: напишіть програму, яка приймає через командний рядок назву дня тижня (наприклад, "Monday"),
конвертує його в enum class Day, а потім через варіативну функцію printSchedule(Day day, ...) виводить список справ на
цей день. Кількість справ може бути різною.
*/

#include <iostream>
#include <cstdarg>
#include <string>

enum class Day {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

void printSchedule(Day day, ...);


int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "ПОМИЛКА! Допишить день тижня." << std::endl;
        std::cout << "Приклад: " << argv[0] << " Friday" << std::endl;
        return 1;
    }

    std::string inputDay = argv[1];
    Day dayUser;

    if (inputDay == "Monday") {
        dayUser = Day::Monday;
        printSchedule(dayUser, "Прокинутися", "Поїсти", "Поспати", nullptr);
    } else if (inputDay == "Tuesday") {
        dayUser = Day::Tuesday;
        printSchedule(dayUser, "Прокинутися", "Доробити домашку", "Поспати", nullptr);
    } else if (inputDay == "Wednesday") {
        dayUser = Day::Wednesday;
        printSchedule(dayUser, "Прокинутися", "Поїсти", "Пари 15:30", "Поспати", nullptr);
    } else if (inputDay == "Thursday") {
        dayUser = Day::Thursday;
        printSchedule(dayUser, "Прокинутися", "Поїсти", "Поспати", nullptr);
    } else if (inputDay == "Friday") {
        dayUser = Day::Friday;
        printSchedule(dayUser, "Прокинутися", "Поїсти", "Доробити домашку", "Поспати", nullptr);
    } else if (inputDay == "Saturday") {
        dayUser = Day::Saturday;
        printSchedule(dayUser, "Прокинутися", "Пари 9:00", "Поїсти", "Поспати", nullptr);
    } else if (inputDay == "Sunday") {
        dayUser = Day::Sunday;
        printSchedule(dayUser, "Прокинутися", nullptr);
    } else {
        std::cout << "ПОМИЛКА! Невизначений день тижня: " << inputDay << std::endl;
        std::cout << "Можливі дні тижня: \"Monday\", \"Tuesday\", \"Wednesday\"..." << std::endl;
        return 1;
    }

    return 0;
}


void printSchedule(Day day, ...) {

    std::cout << "---- Розклад на";
    switch(day) {
    case Day::Monday: std::cout << " Monday"; break;
    case Day::Tuesday: std::cout << " Tuesday"; break;
    case Day::Wednesday: std::cout << " Wednesday"; break;
    case Day::Thursday: std::cout << " Thursday"; break;
    case Day::Friday: std::cout << " Friday"; break;
    case Day::Saturday: std::cout << " Saturday"; break;
    case Day::Sunday: std::cout << " Sunday"; break;
    }
    std::cout << " ----" << std::endl;

    va_list tasks;
    va_start(tasks, day);

    while (true) {
        const char* nextTask = va_arg(tasks, const char*);

        if (nextTask == nullptr)
            break;

        std::cout << "- " << nextTask << std::endl;
    }

    va_end(tasks);

    std::cout << "----------------------------" << std::endl;
}