#include "Pet.h"

Pet::Pet() {}

Pet::Pet(const std::string& name, int age): name(name) {
    if (age < 0) {
        std::cout << "ПОМИЛКА! Неправильне значення age! (меньше 0) \n";
        this->age = 0;
    } else {
        this->age = age;
    }
}

void Pet::introduce() const {
    std::cout << "Ім'я: " << name << " | Вік: " << age << "р.";
}
