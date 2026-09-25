#include "Overcoat.h"


Overcoat::Overcoat() {}

Overcoat::Overcoat(const std::string &name, const std::string &type, const std::string &color, int price) :
    name(name),
    type(type),
    color(color),
    price(price) {}

const std::string& Overcoat::getName() const { return name; }
const std::string& Overcoat::getType() const { return type; }
const std::string& Overcoat::getColor() const { return color; }
int Overcoat::getPrice() const { return price; }

void Overcoat::setName(const std::string &name) { this->name = name; }
void Overcoat::setType(const std::string &type) { this->type = type; }
void Overcoat::setColor(const std::string &color) { this->color = color; }
void Overcoat::setPrice(int price) { this->price = price; }

Overcoat& Overcoat::operator=(const Overcoat &other) {

    if (this == &other) {
        return *this;
    }
    name = other.name;
    type = other.type;
    color = other.color;
    price = other.price;
    return *this;
}

bool operator==(const Overcoat &left, const Overcoat &right) {
    return left.type == right.type;
}
bool operator>(const Overcoat &left, const Overcoat &right) {

    if (left.type == right.type) {
        return left.price > right.price;
    } else {
        std::cout << "ПОМИЛКА! Тип верхнього одягу не однаковий!\n";
        return false;
    }
}

std::ostream& operator<<(std::ostream& out, const Overcoat &overcoat) {
    out << "Назва: " << overcoat.name << " | Тип: " << overcoat.type << " | Колір: " << overcoat.color << " | Ціна: " << overcoat.price << "$ .";
    return out;
}