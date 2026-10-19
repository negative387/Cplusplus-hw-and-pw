#pragma once
#include "LibraryException.h"

class BookNotFoundException : public LibraryException {
private:
    std::string name = "Undefined";

public:
    BookNotFoundException(const std::string &inputName);

    std::string getName() const;
};

