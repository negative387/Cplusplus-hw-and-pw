/*
Завдання 7. Оголосіть два enum class: Fruit { Apple, Orange, Banana } та Color { Red, Orange, Yellow }.

- Спробуйте порівняти Fruit::Orange == Color::Orange. Що скаже компілятор? Поясніть перевагу enum class
над звичайним enum.
- Напишіть функцію, яка приймає Fruit і виводить назву фрукта.
*/

#include <iostream>

enum class Fruit { Apple, Orange, Banana };
enum class Color { Red, Orange, Yellow };

const char* getFruitMessage(Fruit code);


int main() {

    //Звичайний enum лошара, бо він не бачить різницю між ціми назвами, а enum class бачить:
    //if (Fruit::Orange == Color::Orange)

    Fruit code = Fruit::Banana;

    std::cout << getFruitMessage(code) << std::endl;

    return 0;
}


const char* getFruitMessage(Fruit code) {

    switch (code) {
    case Fruit::Apple: return "Яблуко";
    case Fruit::Orange: return "Апельсин";
    case Fruit::Banana: return "Банан";
    default: return "Невідомий :(";
    }
}