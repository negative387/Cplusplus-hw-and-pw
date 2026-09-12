#pragma once
#include "Contact.h"
#include <iostream>


class PhoneBook {
private:
    Contact* contacts;
    int contactsCount;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact(const Contact &contactInput);
    void deleteContact(const char *fullNameInput);
    void searchContact(const char* fullNameInput);
    void printAll() const;
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};
