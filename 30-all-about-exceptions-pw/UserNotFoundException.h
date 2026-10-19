#pragma once
#include "LibraryException.h"

class UserNotFoundException : public LibraryException {
private:
    int userID = 0;

public:
    UserNotFoundException(int inputIDUser);

    int getIDUser() const;
};