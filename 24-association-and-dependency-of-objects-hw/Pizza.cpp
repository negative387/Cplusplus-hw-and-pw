#include "Pizza.h"

Pizza::Pizza() {}

Pizza::Pizza(const std::string& name, const std::string& typeDough, int sizeDough):
    name(name),
    dough(typeDough, sizeDough) {}

const std::string& Pizza::getName() const { return name; }
const Dough& Pizza::getDough() const { return dough; }

void Pizza::setName(const std::string& name) { this->name = name; }

void Pizza::printReceipt() const {
    std::cout << "Назва піци: " << name << '\n'
        << "Тісто: \n";
    dough.printInfo();
    std::cout << '\n';
}
