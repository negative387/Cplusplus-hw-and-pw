#include <cstring>
#include <iostream>
#include "Person.h"


Person::Person() { setFullName("Undefined"); }

Person::Person(const char *fullName, const int &age, const std::string &gender, const std::string &phoneNumber) {
    setFullName(fullName);
    setAge(age);
    setGender(gender);
    setPhoneNumber(phoneNumber);
}

Person::~Person() { delete[] fullName; fullName = nullptr; }

Person::Person(const Person& other) {
    setFullName(other.getFullName());
    age = other.age;
    gender = other.gender;
    phoneNumber = other.phoneNumber;
}

Person& Person::operator=(const Person& other) {
    if (this == &other) {
        return *this;
    }

    setFullName(other.getFullName());
    age = other.age;
    gender = other.gender;
    phoneNumber = other.phoneNumber;
    return *this;
}

const char* Person::getFullName() const { if (fullName == nullptr) { return "Undefined"; } return fullName; }
const int& Person::getAge() const { return age; }
const std::string& Person::getGender() const { return gender; }
const std::string& Person::getPhoneNumber() const { return phoneNumber; }

void Person::setFullName(const char *fullName) {
    delete[] this->fullName;
    this->fullName = new char[strlen(fullName) + 1];
    strcpy(this->fullName, fullName);
}
void Person::setAge(const int &age) {
    if (age < 0) {
        std::cout << "Помилка запису віку для \"" << fullName << "\" ! Він автоматично замінено на 0\n\n";
        this->age = 0;
        return;
    }
    this->age = age;
}
void Person::setGender(const std::string &gender) { this->gender = gender; }
void Person::setPhoneNumber(const std::string &phoneNumber) { this->phoneNumber = phoneNumber; }

void Person::print() {
    std::cout << "--------------------\n"
              << "ПІБ: " << fullName << '\n'
              << "Вік: " << age << '\n'
              << "Стать: " << gender << '\n'
              << "Номер телефону: " << phoneNumber << '\n'
              << "--------------------\n";
}
