#pragma once
#include <iostream>

class Complex {
private:
    double realPart = 0.0;
    double imaginaryPart = 0.0;

public:
    Complex();

    Complex(double realPart, double imaginaryPart);

    double getRealPart() const;
    double getImaginaryPart() const;

    void setRealPart(const double realPart);

    void setImaginaryPart(const double imaginaryPart);

    friend Complex operator+(const Complex& left, const Complex& right);
    friend Complex operator-(const Complex& left, const Complex& right);
    friend Complex operator*(const Complex& left, const Complex& right);
    friend Complex operator/(const Complex &left, const Complex &right);

    friend std::ostream& operator<<(std::ostream& out, const Complex& complex);
};