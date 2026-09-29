#pragma once
#include <iostream>

class Order {
private:
    int orderNumber = -1;
    std::string shippingAddress = "Undefined";

public:

    Order();

    Order(int orderNumber, const std::string &shippingAddress);

    int getOrderNumber() const;
    const std::string& getShippingAddress() const;

    void setOrderNumber(int orderNumber);
    void setShippingAddress(const std::string &shippingAddress);

    void printInfo() const;
};
