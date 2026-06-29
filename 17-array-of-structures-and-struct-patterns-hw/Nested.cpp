/*
Завдання 3: Вкладені структури

Завдання: створіть Nested.cpp:

1. Оголосіть структуру Address з полями: std::string city, std::string street, int buildingNumber.
2. Оголосіть структуру Person з полями: std::string name, int age, Address homeAddress.
3. Ініціалізуйте масив із 3 осіб агрегатним ініціалізатором (Київ, Львів, Одеса — на ваш вибір).
4. Реалізуйте void printPerson(const Person& person) — друк ієрархії з ланцюжком person.homeAddress.city.
5. У main() змініть адресу однієї людини через ланцюжок крапок і виведіть результат.

Питання:
1. Як через ланцюжок крапок змінити поле вкладеної структури (наприклад, місто)?
2. Чому printPerson приймає const Person&, а не Person за значенням?

✅
1 - Код: arrayPersons[2].homeAddress.city = "Львів";
2 - ЩОБ НЕ БУЛО КОПІЮВАННЯ ТА НЕ ЗМІНЮВАЛИ ОРИГІНАЛ :)
❌
*/

#include <iostream>
#include <string>

struct Address {
    std::string city;
    std::string street;
    int buildingNumber;
};

struct Person {
    std::string name;
    int age;
    Address homeAddress;
};

void printPerson(const Person& person);


int main() {

    const int SIZE = 3;
    Person arrayPersons[SIZE] = {
        {"Олена Коваль", 20, { "Київ", "Хрещатик", 22 }},
        {"Артем Котенко", 12, { "Мала Токмачка", "Миру", 67 }},
        {"Олександр Краченко", 31, { "Одеса", "Героїв Крут", 20 }}
    };

    std::cout << "\n=== До переїзду ===\n";
    printPerson(arrayPersons[0]);

    arrayPersons[0].homeAddress.city = "Дніпро";
    arrayPersons[0].homeAddress.street = "Набережна Перемоги";
    arrayPersons[0].homeAddress.buildingNumber = 45;

    std::cout << "\n=== Після переїзду Олени ===\n";
    printPerson(arrayPersons[0]);

    return 0;
}

void printPerson(const Person& person) {

    std::cout << person.name << ", " << person.age << "р.\n";
    std::cout << "  Адреса: " << person.homeAddress.city << ", вул. " << person.homeAddress.street << ", " << person.homeAddress.buildingNumber << '\n';
}