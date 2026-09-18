#include "ApartmentBuilding.h"
#include <iostream>
#include <cstring>

ApartmentBuilding::ApartmentBuilding() { setApartmentBuildingName("Undefined"); }

ApartmentBuilding::ApartmentBuilding(const char *apartmentBuildingName) { setApartmentBuildingName(apartmentBuildingName); }

ApartmentBuilding::~ApartmentBuilding() {
    delete[] apartments;
    apartments = nullptr;
    delete[] apartmentBuildingName;
    apartmentBuildingName = nullptr;
}

ApartmentBuilding::ApartmentBuilding(const ApartmentBuilding &other) {
    if (other.apartments != nullptr) {
        this->apartments = new Apartment[other.countApartments];
        for (int index = 0; index < other.countApartments; ++index) {
            this->apartments[index] = other.apartments[index];
        }
    } else {
      this->apartments = nullptr;
    }

    if (other.apartmentBuildingName != nullptr) {
        setApartmentBuildingName(other.apartmentBuildingName);
    } else {
        this->apartmentBuildingName = nullptr;
    }

    this->countApartments = other.countApartments;
    this->countResidentsApartments = other.countResidentsApartments;
}

void ApartmentBuilding::addApartment(const Apartment &apartment) {
    Apartment *tempArray = new Apartment[countApartments + 1];
    for (int index = 0; index < countApartments; ++index) {
        tempArray[index] = apartments[index];
    }

    tempArray[countApartments] = apartment;
    countResidentsApartments += tempArray[countApartments].getcountResidents();
    delete[] apartments;
    apartments = tempArray;
    ++countApartments;
}

ApartmentBuilding& ApartmentBuilding::operator=(const ApartmentBuilding& other) {
    if (this == &other) {
        return *this;
    }
    delete[] apartments;
    delete[] apartmentBuildingName;
    countApartments = other.countApartments;
    countResidentsApartments = other.countResidentsApartments;

    if (other.apartmentBuildingName != nullptr) {
        apartmentBuildingName = new char[strlen(other.apartmentBuildingName) + 1];
        strcpy(apartmentBuildingName, other.apartmentBuildingName);
    } else {
        apartmentBuildingName = nullptr;
    }

    if (other.apartments != nullptr) {
        apartments = new Apartment[countApartments];

        for (int index = 0; index < countApartments; ++index) {
            apartments[index] = other.apartments[index];
        }
    } else {
        apartments = nullptr;
    }
    return *this;
}


void ApartmentBuilding::deleteApartment(const int &apartmentNumberInput) {
    int indexToRemove = -1;

    for (int index = 0; index < countApartments; ++index) {
        if (apartments[index].getApartmentNumber() == apartmentNumberInput) {
            indexToRemove = index;
            break;
        }
    }

    if (indexToRemove == -1) {
        std::cout << "Квартири з номером \"" << apartmentNumberInput << "\" не знайдено! :(\n\n";
        return;
    }

    if (countApartments == 1) {
        delete[] apartments;
        apartments = nullptr;
        countApartments = 0;
        countResidentsApartments = 0;
        std::cout << "Квартиру з номером \"" << apartmentNumberInput << "\" успішно видалено!\n\n";
        return;
    }

    Apartment *tempArray = new Apartment[countApartments - 1];
    int tempIndex = 0;

    for (int index = 0; index < countApartments; ++index) {
        if (index != indexToRemove) {
            tempArray[tempIndex] = apartments[index];
            tempIndex++;
        }
    }
    countResidentsApartments -= apartments[indexToRemove].getcountResidents();
    delete[] apartments;
    apartments = tempArray;
    --countApartments;
    std::cout << "Квартиру з номером \"" << apartmentNumberInput << "\" успішно видалено!\n\n";
}

void ApartmentBuilding::setApartmentBuildingName(const char *apartmentBuildingName) {
    delete[] this->apartmentBuildingName;

    if (apartmentBuildingName != nullptr) {
        this->apartmentBuildingName = new char[strlen(apartmentBuildingName) + 1];
        strcpy(this->apartmentBuildingName, apartmentBuildingName);
    } else {
        this->apartmentBuildingName = nullptr;
    }
}

const Apartment* ApartmentBuilding::getApartments() const { return apartments; }
const char* ApartmentBuilding::getApartmentBuildingName() const { if (apartmentBuildingName == nullptr) { return "Undefined"; } return apartmentBuildingName; }
int ApartmentBuilding::getCountApartments() const { return countApartments; }
int ApartmentBuilding::getCountResidentsApartments() const { return countResidentsApartments; }

void ApartmentBuilding::print() const {
    std::cout << "##### БУДИНОК \"" << apartmentBuildingName << "\" #####\n"
              << "--- Кількість квартир: " << countApartments << " ---\n"
              << "--- Кількість жителів: " << countResidentsApartments << " ---\n"
              << "---- Усі квартири: ----\n\n";
    for (int index = 0; index < countApartments; ++index) {
        apartments[index].print();
    }
    std::cout << "##############################\n\n";
}
