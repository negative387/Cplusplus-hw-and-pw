#pragma once
#include "Order.h"
#include <iostream>
#include <vector>

class Courier {
private:
    std::string firstName = "Undefined";
    std::vector<const Order*> orderList;

public:
    Courier();

    Courier(const std::string &firstName);

    const std::string& getFirstName() const;
    const std::vector<const Order*>& getOrderList() const;

    void setFirstName(const std::string &firstName);

    void assignOrder(const Order* order);

    void showDeliveries() const;
};