#pragma once
#include <iostream>
#include "Pet.h"

class Parrot : public Pet {
private:
    bool canSpeak = false;

public:
    Parrot();

    Parrot(const std::string &name, int age, bool canSpeak);

    void introduce() const;
};
