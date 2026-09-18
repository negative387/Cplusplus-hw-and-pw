#include "Apartment.h"
#include <iostream>
#include <cstring>

Apartment::Apartment() {}

Apartment::Apartment(int apartmentSize, int apartmentNumber) {
    setApartmentSize(apartmentSize);
    setApartmentNumber(apartmentNumber);
}

Apartment::~Apartment() { delete[] residents; residents = nullptr; }

Apartment::Apartment(const Apartment &other) {
    this->countResidents = other.countResidents;
    this->apartmentSize = other.apartmentSize;
    this->apartmentNumber = other.apartmentNumber;

    if (other.residents != nullptr) {
        this->residents = new Person[other.countResidents];
        for (int index = 0; index < other.countResidents; ++index) {
            this->residents[index] = other.residents[index];
        }
    } else {
        this->residents = nullptr;
    }
}

Apartment& Apartment::operator=(const Apartment& other) {
    if (this == &other) {
        return *this;
    }
    delete[] residents;
    countResidents = other.countResidents;
    apartmentSize = other.apartmentSize;
    apartmentNumber = other.apartmentNumber;

    if (other.residents != nullptr) {
        residents = new Person[countResidents];
        for (int index = 0; index < countResidents; ++index) {
            residents[index] = other.residents[index];
        }
    } else {
        residents = nullptr;
    }
    return *this;
}

void Apartment::addPerson(const Person &person) {
    Person *tempArray = new Person[countResidents + 1];

    for (int index = 0; index < countResidents; ++index) {
        tempArray[index] = residents[index];
    }
    tempArray[countResidents] = person;
    delete[] residents;
    residents = tempArray;
    ++countResidents;
}

void Apartment::deletePerson(const char *fullNameInput) {
    int indexToRemove = -1;

    for (int index = 0; index < countResidents; ++index) {
        if (strcmp(residents[index].getFullName(), fullNameInput) == 0) {
            indexToRemove = index;
            break;
        }
    }
    if (indexToRemove == -1) {
        std::cout << "Жителя \"" << fullNameInput << "\" не знайдено! :(\n\n";
        return;
    }
    if (countResidents == 1) {
        delete[] residents;
        residents = nullptr;
        countResidents = 0;
        std::cout << "Жителя \"" << fullNameInput << "\" успішно видалено!\n\n";
        return;
    }
    Person *tempArray = new Person[countResidents - 1];
    int tempIndex = 0;

    for (int index = 0; index < countResidents; ++index) {
        if (index != indexToRemove) {
            tempArray[tempIndex] = residents[index];
            tempIndex++;
        }
    }
    delete[] residents;
    residents = tempArray;
    --countResidents;
    std::cout << "Жителя \"" << fullNameInput << "\" успішно видалено!\n\n";
}

const Person* Apartment::getResidents() const { return residents; }
int Apartment::getcountResidents() const { return countResidents; }
int Apartment::getApartmentSize() const { return apartmentSize; }
int Apartment::getApartmentNumber() const { return apartmentNumber; }

void Apartment::setApartmentSize(int apartmentSize) {
    if (apartmentSize < 0) {
        std::cout << "Помилка! Площа не може бути меньше 0!\n";
        return;
    }
    this->apartmentSize = apartmentSize;
}

void Apartment::setApartmentNumber(const int apartmentNumber) {
    this->apartmentNumber = apartmentNumber;
}

void Apartment::print() const {
    std::cout << "===== КВАРТИРА " << apartmentNumber << " =====\n"
              << "--- Площа: " << apartmentSize << " м²---\n"
              << "--- Кількість жителів: " << countResidents << " ---\n"
              << "--- Список усіх жителів ---\n";
              for (int index = 0; index < countResidents; ++index) {
                  residents[index].print();
              }
    std::cout << "===========================\n\n";
}