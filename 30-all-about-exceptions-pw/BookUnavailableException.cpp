#include "BookUnavailableException.h"

std::string BookUnavailableException::makeMessage(const std::string& name, int copies,
    const std::string& returnDate) const {
    return "Книга \"" + name + "\" недоступна! >:( "
        + "Усі " + std::to_string(copies) + " примірникі зайняті! "
        + "Найближче повернення: " + returnDate;
}

BookUnavailableException::BookUnavailableException(const std::string& name, int countCopies,
    const std::string& nextDateReturn):
    LibraryException(makeMessage(name, countCopies, nextDateReturn)),
    name(name),
    countCopies(countCopies),
    nextDateReturn(nextDateReturn) {}

std::string BookUnavailableException::getName() const { return name; }

int BookUnavailableException::getCountCopies() const { return countCopies; }

std::string BookUnavailableException::getNextDateReturn() const { return nextDateReturn; }
