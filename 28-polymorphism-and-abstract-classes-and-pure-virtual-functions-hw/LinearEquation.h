#pragma once
#include "Equation.h"
#include <iostream>

class LinearEquation : public Equation {
private:
    double a = 0.0;
    double b = 0.0;

public:
    LinearEquation();

    LinearEquation(double coefficientA, double coefficientB);

    std::vector<double> findRoots() const override;

    void print() const override;
};