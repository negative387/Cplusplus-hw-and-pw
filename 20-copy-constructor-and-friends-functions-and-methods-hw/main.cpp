#include <iostream>
#include "Person.h"
#include "Apartment.h"
#include "ApartmentBuilding.h"

/*
Створіть програму, що імітує багатоквартирний будинок. Необхідно створити класи «Людина», «Квартира»,
«Дім». Клас «Квартира» містить динамічний масив об’єктів класу «Людина». Клас «Дім» містить масив об’єктів
класу «Квартира». Кожен з класів містить змінні-члени і функції-члени, які необхідні для предметної області
класу. Звертаємо вашу увагу, що пам’ять під рядкові значення виділяється динамічно. Наприклад, для ПІБ в
класі «Людина». Не забувайте забезпечити класи різними конструкторами (конструктор копіювання обов’язковий),
деструкторами. В main протестувати роботу отриманого набору класів.
*/

int main() {
    // 1. Створюємо людей:
    Person person1("Іван Петренко", 67, "Гендерфлюід", "+380501111111");
    Person person2("Олександр Коваленко", 32, "Стіл", "+380502222222");
    Person person3("Марія Шевченко", 28, "Пангендер", "+380503333333");

    std::cout << "===== СТВОРЕНІ ЛЮДИ =====\n\n";
    person1.print();
    person2.print();
    person3.print();


    // 2. Створюємо квартири:
    Apartment apartment1(55, 101);
    Apartment apartment2(70, 102);


    // 3. Додаємо людей у квартири:
    apartment1.addPerson(person1);
    apartment1.addPerson(person2);
    apartment2.addPerson(person3);

    std::cout << "\n===== КВАРТИРИ ПІСЛЯ ДОДАВАННЯ ЖИТЕЛІВ =====\n\n";
    apartment1.print();
    apartment2.print();


    // 4. Створюємо будинок:
    ApartmentBuilding building("Сонячний будинок");


    // 5. Додаємо квартири у будинок:
    building.addApartment(apartment1);
    building.addApartment(apartment2);

    std::cout << "\n===== БУДИНОК ПІСЛЯ ДОДАВАННЯ КВАРТИР =====\n\n";
    building.print();


    // 6. Перевіряємо видалення людини:
    std::cout << "===== ВИДАЛЕННЯ ЖИТЕЛЯ =====\n\n";

    apartment1.deletePerson("Олександр Коваленко");
    apartment1.print();


    // 7. Перевіряємо видалення квартири:
    std::cout << "===== ВИДАЛЕННЯ КВАРТИРИ =====\n\n";

    building.deleteApartment(102);
    building.print();


    // 8. Перевіряємо копіювання:
    std::cout << "===== ПЕРЕВІРКА КОПІЮВАННЯ =====\n\n";

    ApartmentBuilding copiedBuilding(building);

    std::cout << "Оригінальний будинок:\n";
    building.print();
    std::cout << "Скопійований будинок:\n";
    copiedBuilding.print();


    // 9. Перевіряємо сеттер віку;
    std::cout << "===== ПЕРЕВІРКА НЕПРАВИЛЬНОГО ВІКУ =====\n\n";
    Person testPerson("Тестова Людина", -5, "They/Them", "+380504444444");
    testPerson.print();

    return 0;
}
