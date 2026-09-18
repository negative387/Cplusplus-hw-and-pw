#pragma once
#include "Apartment.h"

class ApartmentBuilding {

private:
    Apartment *apartments = nullptr;
    char *apartmentBuildingName = nullptr;
    int countApartments = 0;
    int countResidentsApartments = 0;

public:
    ApartmentBuilding();

    ApartmentBuilding(const char *apartmentBuildingName);

    ~ApartmentBuilding();

    ApartmentBuilding(const ApartmentBuilding &other);

    ApartmentBuilding& operator=(const ApartmentBuilding& other);

    void addApartment(const Apartment &apartment);

    void deleteApartment(const int &apartmentNumberInput);

    void setApartmentBuildingName(const char *apartmentBuildingName);

    const Apartment* getApartments() const;
    const char* getApartmentBuildingName() const;
    int getCountApartments() const;
    int getCountResidentsApartments() const;

    void print() const;
};
