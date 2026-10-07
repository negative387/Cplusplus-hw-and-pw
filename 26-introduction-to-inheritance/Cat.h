#pragma once
#include <iostream>
#include "Pet.h"

class Cat : public Pet {
private:
    std::string color = "Undefined";

public:
    Cat();

    Cat(const std::string &name, int age, const std::string &color);

    void introduce() const;
};