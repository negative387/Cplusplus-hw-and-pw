#include "BitString.h"

bool BitString::isValidBitString(const char* line, int length) {
    for (int index = 0; index < length; index++) {
        if (line[index] != '0' && line[index] != '1') {
            return false;
        }
    }
    return true;
}

BitString::BitString() {}

BitString::BitString(const char* line): String(line) {
    if (line == nullptr || !isValidBitString(line, length)) {
        erase();
    }
}

BitString::BitString(const BitString& other):
    String(other) {}

BitString& BitString::operator=(const BitString& other) {
    String::operator=(other);
    return *this;
}

BitString::~BitString() {}

int BitString::toInt(const char* data, int length) {
    if (data == nullptr || length == 0) {
        return 0;
    }

    int result = 0;

    for (int index = 0; index < length; index++) {
        result = result << 1;
        if (data[index] == '1') { result = result | 1; }
    }

    if (data[0] == '1') {
        result -= (1 << length);
    }
    return result;
}

void BitString::toBinaryString(int value, char* data, int length) {

    for (int index = length - 1; index >= 0; index--) {
        data[index] = (value & 1) + '0';
        value = value >> 1;
    }
    data[length] = '\0';
}

void BitString::negate() {
    int value = toInt(data, length);
    value = -value;
    toBinaryString(value, data, length);
}

BitString& BitString::operator+=(const BitString& other) {
    if (data == nullptr) {
        *this = other;
        return *this;
    }
    if (other.data == nullptr) {
        return *this;
    }

    int mainValue = toInt(data, length);
    int otherValue = toInt(other.data, other.length);

    int result = mainValue + otherValue;
    toBinaryString(result, data, length);

    return *this;
}

BitString operator+(const BitString &left, const BitString &right) {
    BitString result(left);
    result += right;
    return result;
}