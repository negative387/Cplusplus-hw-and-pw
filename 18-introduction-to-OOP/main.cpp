/*
Завдання:
Реалізуйте клас «Дріб». Необхідно зберігати чисельник і знаменник як змінні-члени. Реалізуйте
функції-члени длявведення даних в змінні-члени, для виконання арифметичних операцій (додавання,
віднімання, множення, ділення, і т.д.).
*/


#include <iostream>


class Fraction {

private:
    int numerator;
    int denominator;

public:
    void setNumerator(int value) {
        numerator = value;
    }

    void setDenominator(int value) {
        if (value < 1) {
            std::cout << "ПОМИЛКА! Знаменник не може бути меньше 1";
            denominator = 1;
        } else {
            denominator = value;
        }
    }

    Fraction add(Fraction valueSecond) {
        Fraction result;
        result.denominator = denominator * valueSecond.denominator;
        result.numerator = result.denominator / denominator * numerator + result.denominator / valueSecond.denominator * valueSecond.numerator;
        return result;
    }

    Fraction subtract(Fraction valueSecond) {
        Fraction result;
        result.denominator = denominator * valueSecond.denominator;
        result.numerator = result.denominator / denominator * numerator - result.denominator / valueSecond.denominator * valueSecond.numerator;
        return result;
    }

    Fraction multiply(Fraction valueSecond) {
        Fraction result;
        result.denominator = denominator * valueSecond.denominator;
        result.numerator = numerator * valueSecond.numerator;
        return result;
    }

    Fraction divide(Fraction valueSecond) {
        Fraction result;
        if (valueSecond.numerator == 0) {
            std::cout << "ПОМИЛКА! Неможливо ділити на чисельник який дорівнює 0";
            result.denominator = 1;
            result.numerator = 0;
            return result;
        }
        result.denominator = denominator * valueSecond.numerator;
        result.numerator = numerator * valueSecond.denominator;
        return result;
    }

    void print() {
        std::cout << numerator << "/" << denominator;
    }
};

int main() {

    Fraction valueOne;
    valueOne.setNumerator(4);
    valueOne.setDenominator(18);

    Fraction valueTwo;
    valueTwo.setNumerator(2);
    valueTwo.setDenominator(6);

    Fraction divideResult = valueOne.divide(valueTwo);
    divideResult.print();

    std::cout << '\n';

    Fraction addResult = valueOne.add(valueTwo);
    addResult.print();

    return 0;
}