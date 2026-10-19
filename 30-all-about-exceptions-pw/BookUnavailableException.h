#pragma once
#include "LibraryException.h"

class BookUnavailableException : public LibraryException {
private:
    std::string name = "Undefined";
    int countCopies = 0;
    std::string nextDateReturn = "Undefined";

    std::string makeMessage(const std::string &name, int copies, const std::string &returnDate) const;

public:
    BookUnavailableException(const std::string &name, int countCopies, const std::string &nextDateReturn);

    std::string getName() const;
    int getCountCopies() const;
    std::string getNextDateReturn() const;
};