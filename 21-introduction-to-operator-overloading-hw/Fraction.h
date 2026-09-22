#pragma once
#include <iostream>

class Fraction {
private:
    int numerator = 0;
    int denominator = 1;

public:

    Fraction();

    Fraction(int numerator,int denominator);

    int getNumerator() const;

    int getDenominator() const;

    void setNumerator(int value);

    void setDenominator(int value);

    friend Fraction operator+(const Fraction &left, const Fraction &right);
    friend Fraction operator-(const Fraction& left, const Fraction& right);
    friend Fraction operator*(const Fraction& left, const Fraction& right);
    friend Fraction operator/(const Fraction& left, const Fraction& right);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
};