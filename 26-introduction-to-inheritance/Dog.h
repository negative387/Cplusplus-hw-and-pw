#pragma once
#include <iostream>
#include "Pet.h"

class Dog : public Pet {
private:
    std::string breed = "Indefined";

public:
    Dog();

    Dog(const std::string &name, int age, const std::string &breed);

    void introduce() const;
};