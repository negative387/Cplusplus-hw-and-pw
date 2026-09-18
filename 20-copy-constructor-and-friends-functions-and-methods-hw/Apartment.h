#pragma once
#include "Person.h"

class Apartment {
private:
    Person *residents = nullptr;
    int countResidents = 0;
    int apartmentSize = 0;
    int apartmentNumber = 0;

public:
    Apartment();
    Apartment(int apartmentSize, int apartmentNumber);

    ~Apartment();

    Apartment(const Apartment &other);

    Apartment& operator=(const Apartment& other);

    void addPerson(const Person &person);

    void deletePerson(const char *fullNameInput);

    const Person* getResidents() const;
    int getcountResidents() const;
    int getApartmentSize() const;
    int getApartmentNumber() const;

    void setApartmentSize(int apartmentSize);
    void setApartmentNumber(const int apartmentNumber);

    void print() const;
};
