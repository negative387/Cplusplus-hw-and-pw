#include <iostream>
#include "Library.h"

/*
Розробіть систему класів-винятків для програми управління бібліотечним каталогом. Система повинна обробляти різноманітні
сценарії помилок: неіснуючі книги, зайняті примірники, прострочені повернення, неіснуючі читачі тощо.

Вимоги:
Створіть базовий клас LibraryException, похідний від std::runtime_error.

Створіть спеціалізовані класи-винятки:
- BookNotFoundException — книгу не знайдено за ISBN або назвою.
- BookUnavailableException — усі примірники книги зайняті.
- UserNotFoundException — читача не знайдено в системі.
- OverdueException — книга прострочена, повернення неможливе без сплати штрафу.

Кожен клас має зберігати релевантний контекст:
- BookNotFoundException: ISBN або назва книги.
- BookUnavailableException: ISBN, кількість усіх примірників, дата найближчого очікуваного повернення.
- UserNotFoundException: ID користувача.
- OverdueException: ISBN, дата видачі, дата граничного повернення, розмір штрафу.

Реалізуйте спрощений клас Library з методами:
- borrowBook(userID, isbn) — видача книги користувачу.
- returnBook(userID, isbn) — повернення книги.
- findBook(isbn) — пошук книги в каталозі.
Продемонструйте багаторівневу обробку винятків з різними обробниками для кожного типу помилки та універсальним обробником
LibraryException.

Очікуваний результат:
- Ієрархія з 5 класів винятків.
- Детальні діагностичні повідомлення у методі what().
- Геттери для всіх контекстних полів.
- Демонстрація правильної черговості блоків catch.
*/

int main() {

    //Успішна видача книги:
    std::cout << "Успішна видача:\n";
    try {
        Library test1;
        test1.borrowBook(124567, "Mein Kampf");
    }
    catch (const LibraryException &exception) {
        std::cout << "Помилка: " << exception.what() << '\n';
    }

    //Користувача не знайдено:
    std::cout << "\nКористувача не знайдено:\n";
    try {
        Library test2;
        test2.borrowBook(0, "UserNotFoundException test");
    }
    catch (const LibraryException &exception) {
        std::cout << "Помилка: " << exception.what() << '\n';
    }

    //Книгу не знайдено:
    std::cout << "\nКнигу не знайдено:\n";
    try {
        Library test3;
        test3.borrowBook(1234567, "BookNotFoundException test");
    }
    catch (const LibraryException &exception) {
        std::cout << "Помилка: " << exception.what() << '\n';
    }

    //Усі примірники зайняті:
    std::cout << "\nУсі примірники зайняті:\n";
    try {
        Library test4;
        test4.borrowBook(1234567, "BookUnavailableException test");
    }
    catch (const LibraryException &exception) {
        std::cout << "Помилка: " << exception.what() << '\n';
    }

    //Прострочена книга:
    std::cout << "\nПрострочена книга:\n";
    try {
        Library test5;
        test5.returnBook(1234567, "OverdueException test");
    }
    catch (const LibraryException &exception) {
        std::cout << "Помилка: " << exception.what() << '\n';
    }

    return 0;
}