#include "Complex.h"


Complex::Complex() {}

Complex::Complex(double realPart, double imaginaryPart) {
    setRealPart(realPart);
    setImaginaryPart(imaginaryPart);
}

double Complex::getRealPart() const { return realPart; }
double Complex::getImaginaryPart() const { return imaginaryPart; }

void Complex::setRealPart(const double realPart) {
    this->realPart = realPart;
}

void Complex::setImaginaryPart(const double imaginaryPart) {
    this->imaginaryPart = imaginaryPart;
}


Complex operator+(const Complex& left, const Complex& right) {
    return Complex(left.realPart + right.realPart, left.imaginaryPart + right.imaginaryPart);
}

Complex operator-(const Complex& left, const Complex& right) {
    return Complex(left.realPart - right.realPart, left.imaginaryPart - right.imaginaryPart);
}

Complex operator*(const Complex& left, const Complex& right) {
    return Complex( left.realPart * right.realPart - left.imaginaryPart * right.imaginaryPart,
                left.realPart * right.imaginaryPart + left.imaginaryPart * right.realPart );
}

Complex operator/(const Complex &left, const Complex &right) {
    double denominator = right.realPart * right.realPart + right.imaginaryPart * right.imaginaryPart;

    if (denominator == 0.0) {
        std::cout << "ПОМИЛКА! Ділення на нуль у комплексних числах\n";
        return Complex(0.0, 0.0);
    }
    double resultRealPart = (left.realPart * right.realPart + left.imaginaryPart * right.imaginaryPart) / denominator;
    double resultImaginaryPart = (left.imaginaryPart * right.realPart - left.realPart * right.imaginaryPart) / denominator;
    return Complex(resultRealPart, resultImaginaryPart);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    out << complex.realPart;

    if (complex.imaginaryPart >= 0) {
        out << " + " << complex.imaginaryPart << 'i';
    } else {
        out << " - " << -complex.imaginaryPart << 'i';
    }
    return out;
}