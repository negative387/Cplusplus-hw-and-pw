#pragma once
#include "Dough.h"


class Pizza {
private:
    std::string name = "Undefined";
    Dough dough;

public:
    Pizza();

    Pizza(const std::string &name, const std::string &typeDough, int sizeDough);

    const std::string& getName() const;
    const Dough& getDough() const;

    void setName(const std::string &name);

    void printReceipt() const;
};
