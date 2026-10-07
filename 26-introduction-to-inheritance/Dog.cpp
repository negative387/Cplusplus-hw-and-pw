#include "Dog.h"

Dog::Dog() {}

Dog::Dog(const std::string& name, int age, const std::string& breed):
    Pet(name, age), breed(breed) {}

void Dog::introduce() const {
    std::cout << "Собака -> ";
    Pet::introduce();
    std::cout << " | Порода: " << breed << '\n';
}
