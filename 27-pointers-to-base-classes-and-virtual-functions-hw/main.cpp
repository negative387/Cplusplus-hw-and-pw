#include "FilePrinter.h"
#include "FilePrinterASCII.h"
#include "FilePrinterBinary.h"

/*
Завдання:
Створіть ієрархію класів для роботи з файлами. Базовий клас вміє відкривати файл і виводити його вміст
в  консоль, перший клас нащадок відкриває файл і виводить вміст у вигляді ASCII-кодів символів, розташованих
в файлі, другий клас нащадок відкриває файл і виводить його вміст у двійковому вигляді і т.д. Щоб
продемонструвати вміст файлу в базовому класі визначена віртуальна функція: void Display (const char * path),
де path — шлях до файлу. Нащадки створюють свою реалізацію віртуальної функції.
*/

int main() {
    const char* filePath = "test.txt";

    std::ofstream testFile(filePath);
    if (testFile.is_open()) {
        testFile << "Lorem Ipsum";
        testFile.close();
    }

    std::cout << "Оберіть режим виведення:\n"
              << "1 - Звичайний текст\n"
              << "2 - ASCII коди\n"
              << "3 - Двійковий вигляд\n"
              << "Ваш вибір: ";
    int choice;
    std::cin >> choice;

    // Зробив як на сайті ( може такий спосіб тут і не потрібен ¯\_(ツ)_/¯ ):
    FilePrinter* printer = nullptr;

    switch (choice) {
    case 1:
        printer = new FilePrinter();
        break;
    case 2:
        printer = new FilePrinterASCII();
        break;
    case 3:
        printer = new FilePrinterBinary();
        break;
    default:
        std::cout << "ПОМИЛКА! Неправильний вибір!\n";
        return 0;
    }

    std::cout << "ВМІСТ ФАЙЛУ:   \n";
    printer->Display(filePath);

    delete printer;
    return 0;
}