#include "LinearEquation.h"

LinearEquation::LinearEquation() {}

LinearEquation::LinearEquation(double coefficientA, double coefficientB):
    a(coefficientA),
    b(coefficientB) {}

std::vector<double> LinearEquation::findRoots() const {
    std::vector<double> roots;

    if (a == 0) { return roots; }

    roots.push_back(-b / a);
    return roots;
}

void LinearEquation::print() const {
    std::cout << a << "x + (" << b << ") = 0" << '\n';
}
