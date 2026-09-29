#include "Order.h"

Order::Order() {}

Order::Order(int orderNumber, const std::string& shippingAddress):
    orderNumber(orderNumber),
    shippingAddress(shippingAddress) {}

int Order::getOrderNumber() const { return orderNumber; }
const std::string& Order::getShippingAddress() const { return shippingAddress; }

void Order::setOrderNumber(int orderNumber) { this->orderNumber = orderNumber; }
void Order::setShippingAddress(const std::string& shippingAddress) { this->shippingAddress = shippingAddress; }

void Order::printInfo() const {
    std::cout << "Номер замовлення: " << orderNumber << " | Адреса: " << shippingAddress << " .";
}
