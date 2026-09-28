#pragma once
#include <iostream>

class Product {
private:
    std::string name = "Undefined";
    double price = 0.0;

public:
    Product();

    Product(const std::string &name, double price);

    void print() const;

    double getPrice() const;
};