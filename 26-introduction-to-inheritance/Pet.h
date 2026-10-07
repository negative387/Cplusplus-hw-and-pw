#pragma once
#include <iostream>

class Pet {
protected:
    std::string name = "Undefined";
    int age = 0;

public:
    Pet();

    Pet(const std::string &name, int age);

    void introduce() const;
};