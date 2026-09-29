#pragma once
#include <iostream>

class Dough {
private:
    std::string type = "Undefined";
    int size = -1;

public:
    Dough();

    Dough(const std::string &type, int size);

    const std::string& getType() const;
    int getSize() const;

    void setType(const std::string &type);
    void setSize(int size);

    void printInfo() const;
};