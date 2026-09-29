#include "Dough.h"

Dough::Dough() {}

Dough::Dough(const std::string& type, int size):
    type(type) {

    if (size < 0) {
        std::cout << "ПОМИЛКА! Розмір не може бути меньше 0!\n";
        this->size = 0;
    } else {
        this->size = size;
    }
}

const std::string& Dough::getType() const { return type; }
int Dough::getSize() const { return size; }

void Dough::setType(const std::string& type) { this->type = type; }
void Dough::setSize(int size) {
    if (size < 0) {
        std::cout << "ПОМИЛКА! Розмір не може бути меньше 0!\n";
    } else {
        this->size = size;
    }
}

void Dough::printInfo() const {
    std::cout << "Тип : " << type << " | Розмір: " << size << " см.";
}
