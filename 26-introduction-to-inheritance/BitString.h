#pragma once
#include "String.h"

class BitString : public String {
private:
    bool isValidBitString(const char* line, int length);

public:
    BitString();

    BitString(const char *line);

    BitString(const BitString &other);

    BitString& operator=(const BitString &other);

    ~BitString();

    int toInt(const char *data, int length);

    void toBinaryString(int value, char *data, int length);

    void negate();

    BitString& operator+=(const BitString& other);

    friend BitString operator+(const BitString &left, const BitString &right);
};