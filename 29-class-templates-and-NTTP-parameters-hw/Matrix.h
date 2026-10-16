#pragma once
#include <iostream>
#include <ctime>

template <typename T>
class Matrix {
private:
    int rows = 0;
    int cols = 0;
    T *dataMatrix = nullptr;

public:
    Matrix();

    Matrix(int rows, int cols);

    Matrix(const Matrix& other);

    Matrix& operator=(const Matrix& other);

    ~Matrix();

    void set(int rows, int cols, const T &value);

    T get(int rows, int cols) const;

    void fillFromKeyboard();

    void fillRandom();

    void print() const;

    Matrix<T> operator+(const Matrix<T> &other) const;

    Matrix<T> operator-(const Matrix<T> &other) const;

    Matrix<T> operator*(const Matrix<T> &other) const;

    Matrix<T> operator/(const Matrix<T> &other) const;

    T maxElement() const;

    T minElement() const;
};

#include "Matrix.hpp"

template <>
void Matrix<std::string>::fillRandom() {
    std::srand(std::time(0));
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int alphabetSize = 26;

    for (int indexRows = 0; indexRows < rows; indexRows++) {
        for (int indexCols = 0; indexCols < cols; indexCols++) {
            std::string randomWord = "";
            for (int count = 0; count < 5; count++) {
                randomWord += alphabet[std::rand() % alphabetSize];
            }
            set(indexRows, indexCols, randomWord);
        }
    }
}
