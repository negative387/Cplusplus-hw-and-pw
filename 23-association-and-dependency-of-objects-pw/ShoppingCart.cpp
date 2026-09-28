#include "ShoppingCart.h"

void ShoppingCart::addProduct(const Product* product) {
    if (product != nullptr) {
        products.push_back(product);
    }
}

double ShoppingCart::calculateTotal() const {
    double total = 0.0;
    for (const Product* product : products) {
        total += product->getPrice();
    }
    return total;
}

void ShoppingCart::printReceipt() const {
    std::cout << "===== ЧЕК =====\n";
    if (products.empty()) {
        std::cout << "Кошик пустий :(\n";
    } else {
        for (const Product* product : products) {
            product->print();
        }
    }
    std::cout << "---------------\n";
    std::cout << "Сума: " << calculateTotal() << " $\n";
    std::cout << "===============\n";
}
