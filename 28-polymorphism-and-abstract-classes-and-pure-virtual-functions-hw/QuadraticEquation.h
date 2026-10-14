#pragma once
#include "Equation.h"
#include <iostream>
#include <cmath>

class QuadraticEquation : public Equation {
private:
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

public:
    QuadraticEquation();

    QuadraticEquation(double coefficientA, double coefficientB, double coefficientC);

    std::vector<double> findRoots() const override;

    void print() const override;
};