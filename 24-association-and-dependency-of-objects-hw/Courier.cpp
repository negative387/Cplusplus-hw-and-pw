#include "Courier.h"

Courier::Courier() {}

Courier::Courier(const std::string& firstName):
    firstName(firstName) {}

const std::string& Courier::getFirstName() const { return firstName; }
const std::vector<const Order*>& Courier::getOrderList() const { return orderList; }

void Courier::setFirstName(const std::string& firstName) { this->firstName = firstName; }

void Courier::assignOrder(const Order* order) {
    orderList.push_back(order);
}

void Courier::showDeliveries() const {

    std::cout << "=======================\n"
        << "Ім'я кур'єра: " << firstName << '\n'
        << "Список замовлень: \n";

    for (const Order *order : orderList) {
        if (order != nullptr) {
            order->printInfo();
            std::cout << '\n';
        } else {
            std::cout << "Помилка! Порожнє замовлення\n";
        }
    }

    std::cout << "=======================\n";
}
