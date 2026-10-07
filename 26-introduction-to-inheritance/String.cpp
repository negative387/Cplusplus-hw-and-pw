#include "String.h"

String::String(): length(0), data(nullptr) {}

String::String(const char* line) {
    if (line == nullptr) {
        length = 0;
        data = new char[1];
        data[0] = '\0';
    } else {
        length = std::strlen(line);
        data = new char[length + 1];
        std::strcpy(data, line);
    }
}

String::String(const String& other) {
    length = other.length;

    if (other.data != nullptr) {
        data = new char[length + 1]{};
        std::strcpy(data, other.data);
    } else {
        data = nullptr;
    }
}

String& String::operator=(const String& other) {
    if (this == &other) { return *this; }

    length = other.length;
    delete[] data;

    if (other.data != nullptr) {
        data = new char[length + 1]{};
        std::strcpy(data, other.data);
    } else {
        data = nullptr;
    }
    return *this;
}

int String::getLength() const { return length; }

const char* String::getData() const {
    if (data == nullptr) { return "Undefined"; }
    return data;
}

void String::erase() {
    delete[] data;
    data = nullptr;
    length = 0;
}

String::~String() {
    delete[] data;
    data = nullptr;
    length = 0;
}

String& String::operator+=(const String& other) {

    if (other.length == 0 || other.data == nullptr) {
        return *this;
    }

    int newLength = length + other.length;
    char* tempData = new char[newLength + 1];

    if (data != nullptr) {
        std::strcpy(tempData, data);
    } else {
        tempData[0] = '\0';
    }
    // Нещодавно дізнався про цю функцію ( сподіваюсь це не чітерство ):
    std::strcat(tempData, other.data);

    delete[] data;
    data = tempData;
    length = newLength;
    return *this;
}

String operator+(const String &left, const String &right) {
    String newString{left};
    newString += right;
    return newString;
}

bool operator==(const String &left, const String &right) {
    if (left.length != right.length) { return false; }

    for (int index = 0; index < left.length; index++) {
        if (left.data[index] != right.data[index]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const String &left, const String &right) {
    return !(left == right);
}