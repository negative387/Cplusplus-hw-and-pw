#pragma once
#include <vector>
#include "Product.h"

class ShoppingCart {
private:
    std::vector<const Product*> products;

public:
    void addProduct(const Product* product);

    double calculateTotal() const;

    void printReceipt() const;
};