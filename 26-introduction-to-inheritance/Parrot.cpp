#include "Parrot.h"

Parrot::Parrot() {}

Parrot::Parrot(const std::string& name, int age, bool canSpeak):
    Pet(name, age), canSpeak(canSpeak) {}

void Parrot::introduce() const {
    std::cout << "Папуга -> ";
    Pet::introduce();
    std::cout << " | Може говорити: " << (canSpeak ? "так" : "ні") << '\n';
}
