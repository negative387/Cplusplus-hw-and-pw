#include "Cat.h"

Cat::Cat() {}

Cat::Cat(const std::string& name, int age, const std::string& color):
    Pet(name, age), color(color) {}

void Cat::introduce() const {
    std::cout << "Кіт -> ";
    Pet::introduce();
    std::cout << " | Колір: " << color << '\n';
}
