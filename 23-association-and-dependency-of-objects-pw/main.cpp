#include <iostream>
#include "Product.h"
#include "ShoppingCart.h"

/*
Концепція: Кошик інтернет-магазину посилається на наявні товари. Якщо кошик очистити або видалити — самі товари в базі (в main) залишаються.
Створити клас Product:
- Поля: назва (string), ціна (double).
- Метод для виводу інформації про товар.

Створити клас ShoppingCart:
- Поле: динамічний масив або вектор вказівників на товари (std::vector<const Product*>).
- Метод addProduct(const Product* p): додає посилання на товар.
- Метод calculateTotal(): рахує суму цін доданих товарів.
- Метод printReceipt(): виводить чек зі списком товарів і сумою.

У функції main():
- Створити окремо 2–3 об'єкти Product (наприклад, "Геймпад", "Навушники").
- Створити об'єкт ShoppingCart і додати туди створені товари через їхні адреси (&).
- Викликати друк чека.
*/

int main() {

	Product gamepad("Геймпад", 69.99);
    Product headphone("Навушники", 78.50);
    Product samsungGalaxyQuantumProUltraMaxPlus5GAIEnhancedTitaniumEdition("Samsung Galaxy Quantum Pro Ultra Max Plus 5G AI-Enhanced Titanium Edition", 5.99);

    ShoppingCart cart;

    cart.addProduct(&gamepad);
    cart.addProduct(&headphone);
    cart.addProduct(&samsungGalaxyQuantumProUltraMaxPlus5GAIEnhancedTitaniumEdition);

    cart.printReceipt();

    return 0;
}
