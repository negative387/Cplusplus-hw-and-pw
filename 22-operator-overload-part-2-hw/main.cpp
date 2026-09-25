#include <iostream>
#include "Overcoat.h"
#include "Flat.h"


int main() {
    std::cout << "\n========== ВЕРХНІЙ ОДЯГ ==========\n";

    Overcoat coat1("Nike Jacket", "Куртка", "Чорний", 150);
    Overcoat coat2("Adidas Jacket", "Куртка", "Синій", 200);
    Overcoat coat3("Yezzy", "Футболка", "Білий", 20);

    std::cout << "Одяг 1:\n" << coat1 << "\n";
    std::cout << "Одяг 2:\n" << coat2 << "\n";
    std::cout << "Одяг 3:\n" << coat3 << "\n";

    std::cout << "\nПорівняння типів:\n";
    if (coat1 == coat2) {
        std::cout << "Одяг 1 і одяг 2 мають однаковий тип\n";
    } else {
        std::cout << "Одяг 1 і одяг 2 мають різний тип\n";
    }
    if (coat1 == coat3) {
        std::cout << "Одяг 1 і одяг 3 мають однаковий тип\n";
    } else {
        std::cout << "Одяг 1 і одяг 3 мають різний тип\n";
    }

    std::cout << "\nПорівняння ціни:\n";
    if (coat2 > coat1) {
        std::cout << "Одяг 2 дорожчий за одяг 1\n";
    } else {
        std::cout << "Одяг 2 не дорожчий за одяг 1\n";
    }

    std::cout << "\nПорівняння куртки і футболки:\n";
    coat3 > coat1;

    Overcoat coat4;
    coat4 = coat1;
    std::cout << "\nОдяг 4 після coat4 = coat1:\n";
    std::cout << coat4 << "\n";


    std::cout << "========== КВАРТИРИ ==========\n";

    Flat flat1("Іван Петренко", 50, 100000, 12);
    Flat flat2("Олександр Коваленко", 2, 1200000, 67);
    Flat flat3("Петро Іванов", 50, 90000, 7);

    std::cout << "Квартира 1:\n" << flat1 << "\n";
    std::cout << "Квартира 2:\n" << flat2 << "\n";
    std::cout << "Квартира 3:\n" << flat3 << "\n";

    std::cout << "\nПорівняння площі:\n";
    if (flat1 == flat2) {
        std::cout << "Квартира 1 і квартира 2 мають однакову площу\n";
    } else {
        std::cout << "Квартира 1 і квартира 2 мають різну площу\n";
    }

    if (flat1 == flat3) {
        std::cout << "Квартира 1 і квартира 3 мають однакову площу\n";
    } else {
        std::cout << "Квартира 1 і квартира 3 мають різну площу\n";
    }

    std::cout << "\nПорівняння ціни:\n";
    if (flat2 > flat1) {
        std::cout << "Квартира 2 дорожча за квартиру 1\n";
    } else {
        std::cout << "Квартира 2 не дорожча за квартиру 1\n";
    }

    Flat flat4;
    flat4 = flat1;
    std::cout << "\nКвартира 4 після flat4 = flat1:\n";
    std::cout << flat4 << "\n";

    return 0;
}
