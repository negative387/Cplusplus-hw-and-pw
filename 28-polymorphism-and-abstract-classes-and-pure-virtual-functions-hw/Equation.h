#pragma once
#include <vector>

class Equation {
public:
    virtual ~Equation();

    virtual std::vector<double> findRoots() const = 0;
    virtual void print() const = 0;
};