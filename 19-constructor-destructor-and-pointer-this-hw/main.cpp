#include "Contact.h"
#include "PhoneBook.h"
#include <iostream>


int main() {
    PhoneBook myBook;

    Contact c1("Шевченко Тарас Григорович", "044-111-22-33", "044-555-55-55", "67-123-45-67", "Письменник");
    Contact c2("Леся Українка", "033-222-11-00", "Undefined", "8050-987-65-43", "Поетеса");
    Contact c3("Джефрі Епштейн", "666-666-99-99", "666-666-77-77", "12-345-67-89", ":)");

    myBook.addContact(c1);
    myBook.addContact(c2);
    myBook.addContact(c3);

    std::cout << "Виводимо усіх абонентів:\n";
    myBook.printAll();

    std::cout << "Зберегаємо книгу у файл:\n";
    myBook.saveToFile("phonebook.txt");


    std::cout << "Шукаємо: \"Леся Українка\"\n";
    myBook.searchContact("Леся Українка");

    std::cout << "Шукаємо когось кого немає в книзі:\n";
    myBook.searchContact("Петренко Петро");

    std::cout << "Видалення абонента: \n";
    myBook.deleteContact("Леся Українка");
    myBook.printAll();

    std::cout << "\nЗавантаження з файлу в нову книгу...\n";
    PhoneBook importedBook;
    importedBook.loadFromFile("phonebook.txt");
    std::cout << "Вміст нової книги після імпорту:\n";
    importedBook.printAll();
}