#pragma once
#include "LibraryException.h"
#include "BookNotFoundException.h"
#include "BookUnavailableException.h"
#include "UserNotFoundException.h"
#include "OverdueException.h"

class Library {
public:
    void borrowBook(int userID, const std::string &name);

    void returnBook(int userID, const std::string &name);

    void findBook(const std::string &inputName);
};