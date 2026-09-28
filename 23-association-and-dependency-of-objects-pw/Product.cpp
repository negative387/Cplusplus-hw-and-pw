#include "Product.h"

Product::Product() {}

Product::Product(const std::string& name, double price):
    name(name),
    price(price) {}

void Product::print() const {
    std::cout << "Назва: " << name << " | Ціна: " << price  << "$.\n";
}

double Product::getPrice() const {
    return price;
}
