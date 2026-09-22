#include "Fraction.h"
#include <iostream>

Fraction::Fraction() { }

Fraction::Fraction(const int numerator, const int denominator) {
    setNumerator(numerator);
    setDenominator(denominator);
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

// Я якщо шо не забув передавати через &value. Я дізнався, що інти не потрібно передавати з & бо вони і так маленькі :) .
void Fraction::setNumerator(const int value) {
    numerator = value;
}

void Fraction::setDenominator(const int value) {
    if (value < 1) {
        std::cout << "ПОМИЛКА! Знаменник не може бути меньше 1\n";
        denominator = 1;
    } else {
        denominator = value;
    }
}

Fraction operator+(const Fraction &left, const Fraction &right) {

    Fraction result;
    result.denominator = left.denominator * right.denominator;
    result.numerator = result.denominator / left.denominator * left.numerator + result.denominator / right.denominator * right.numerator;
    return result;
}

Fraction operator-(const Fraction &left, const Fraction &right) {

    Fraction result;
    result.denominator = left.denominator * right.denominator;
    result.numerator = result.denominator / left.denominator * left.numerator - result.denominator / right.denominator * right.numerator;
    return result;
}

Fraction operator*(const Fraction &left, const Fraction &right) {

    Fraction result;
    result.denominator = left.denominator * right.denominator;
    result.numerator = left.numerator * right.numerator;
    return result;
}

Fraction operator/(const Fraction &left, const Fraction &right) {

    Fraction result;
    if (right.numerator <= 0) {
        std::cout << "ПОМИЛКА! Неможливо ділити на чисельник який менше або є 0\n";
        result.denominator = 1;
        result.numerator = 0;
        return result;
    }
    result.denominator = left.denominator * right.numerator;
    result.numerator = left.numerator * right.denominator;
    return result;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    out << fraction.numerator << '/' << fraction.denominator;
    return out;
}