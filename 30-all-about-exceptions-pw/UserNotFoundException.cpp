#include "UserNotFoundException.h"

UserNotFoundException::UserNotFoundException(int inputIDUser):
    LibraryException("Не знайдено юзера з ID: " + std::to_string(inputIDUser)),
    userID(inputIDUser) {}

int UserNotFoundException::getIDUser() const { return userID; }
