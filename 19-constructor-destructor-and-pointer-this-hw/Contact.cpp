#include "Contact.h"
#include <iostream>
#include <cstring>


Contact::Contact() {fullName = nullptr;}

Contact::Contact(const char *fullNameInput, const std::string &homePhoneInput,
          const std::string &workPhoneInput, const std::string &cellPhoneInput, const std::string &addInfoInput) :
    homePhone(homePhoneInput), workPhone(workPhoneInput), cellPhone(cellPhoneInput), addInfo(addInfoInput) {

    fullName = new char[strlen(fullNameInput) + 1];
    strcpy(fullName, fullNameInput);
}

Contact::~Contact() { delete[] fullName; fullName = nullptr; }

const char* Contact::getFullName() const { if (fullName == nullptr) { return "Undefined"; } return fullName; }
const std::string &Contact::getHomePhone() const { return homePhone; }
const std::string &Contact::getWorkPhone() const { return workPhone; }
const std::string &Contact::getCellPhone() const { return cellPhone; }
const std::string &Contact::getAddInfo() const { return addInfo; }

void Contact::setFullName(const char *fullNameInput) {
    delete[] fullName;
    fullName = new char[strlen(fullNameInput) + 1];
    strcpy(fullName, fullNameInput);
}
void Contact::setHomePhone(const std::string &homePhoneInput) { homePhone = homePhoneInput; }
void Contact::setWorkPhone(const std::string &workPhoneInput) { workPhone = workPhoneInput; }
void Contact::setCellPhone(const std::string &cellPhoneInput) { cellPhone = cellPhoneInput; }
void Contact::setAddInfo(const std::string &addInfoInput) { addInfo = addInfoInput; }

void Contact::print() const {
    std::cout << "------------------------------\n"
              << "ПІБ: " << fullName << '\n'
              << "Домашній телефон: " << homePhone << '\n'
              << "Робочий телефон: " << workPhone << '\n'
              << "Мобільний телефон: " << cellPhone << '\n'
              << "Додаткова інформація: " << addInfo << '\n'
              << "------------------------------\n\n";
}