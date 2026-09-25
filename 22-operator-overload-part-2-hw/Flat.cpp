#include "Flat.h"


Flat::Flat() {}

Flat::Flat(const std::string &ownerName, int area, int price, int number) :
    ownerName(ownerName),
    area(area),
    price(price),
    number(number) {}

const std::string& Flat::getOwnerName() const { return ownerName; }
int Flat::getArea() const { return area; }
int Flat::getPrice() const { return price; }
int Flat::getNumber() const { return number; }

void Flat::setOwnerName(const std::string &ownerName) { this->ownerName = ownerName; }
void Flat::setArea(int area) { this->area = area; }
void Flat::setPrice(int price) { this->price = price; }
void Flat::setNumber(int number) { this->number = number; }

Flat& Flat::operator=(const Flat &other) {

    if (this == &other) {
        return *this;
    }
    ownerName = other.ownerName;
    area = other.area;
    price = other.price;
    number = other.number;
    return *this;
}

bool operator==(const Flat &left, const Flat &right) {
    return left.area == right.area;
}

bool operator>(const Flat &left, const Flat &right) {
    return left.price > right.price;
}

std::ostream& operator<<(std::ostream& out, const Flat &flat) {
    out << "Власник: " << flat.ownerName << " | Номер квартири: " << flat.number << " | Площа: " << flat.area << "м² | Ціна: " << flat.price << "$ .";
    return out;
}