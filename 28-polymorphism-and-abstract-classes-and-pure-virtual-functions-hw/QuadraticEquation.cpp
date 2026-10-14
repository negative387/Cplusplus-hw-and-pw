#include "QuadraticEquation.h"

QuadraticEquation::QuadraticEquation() {}

QuadraticEquation::QuadraticEquation(double coefficientA, double coefficientB, double coefficientC):
    a(coefficientA),
    b(coefficientB),
    c(coefficientC) {}

std::vector<double> QuadraticEquation::findRoots() const {
    std::vector<double> roots;

    if (a == 0) {
        if (b != 0) { roots.push_back(-c / b); }

        return roots;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        roots.push_back((-b + std::sqrt(discriminant)) /(2 * a));
        roots.push_back((-b - std::sqrt(discriminant)) / (2 * a));
    }
    else if (discriminant == 0) {
        roots.push_back(-b / (2 * a));
    }

    return roots;
}

void QuadraticEquation::print() const {
    std::cout << a << "x^2 + (" << b << ")x + (" << c << ") = 0" << '\n';
}
