#include "Library.h"

void Library::borrowBook(int userID, const std::string& name) {
    if (userID == 0) {
        throw UserNotFoundException(userID);
    }
    if (name == "BookNotFoundException test") {
        throw BookNotFoundException(name);
    }
    if (name == "BookUnavailableException test") {
        throw BookUnavailableException(name, 999, "2026-10-19");
    }

    std::cout << "Книга: \"" << name << "\" успішно видана юзеру з ID: " << userID << '\n';
}

void Library::returnBook(int userID, const std::string& name) {
    if (name == "OverdueException test") {
        throw OverdueException(name, "2026-10-09", "2026-10-18", 12.0);
    }

    std::cout << "Книга: \"" << name << "\" успішно повернута юзером з ID: " << userID << '\n';
}

void Library::findBook(const std::string& inputName) {
    if (inputName == "BookNotFoundException test" || inputName.empty()) {
        throw BookNotFoundException(inputName);
    }

    std::cout << "Книгу: \"" << inputName << "\" знайдено в каталозі бібліотеки!\n";
}
