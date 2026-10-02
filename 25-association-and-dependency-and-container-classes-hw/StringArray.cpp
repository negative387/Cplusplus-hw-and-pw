//
// Created by Sergey on 02.10.2026.
//

#include "StringArray.h"

StringArray::StringArray() {}

StringArray::StringArray(int arrayLength) {
    if (arrayLength < 0) {
        throw std::invalid_argument("Розмір не може бути меньше 0!");
    }
    length = arrayLength;
    data = new std::string[length]{};
}

StringArray::StringArray(const std::initializer_list<std::string>& list) {
    length = list.size();
    data = new std::string[length]{};

    int index = 0;
    for (const std::string &element : list) {
        data[index] = element;
        index++;
    }
}

StringArray::~StringArray() {
    delete[] data;
    data = nullptr;
}

int StringArray::getLength() const { return length; }

bool StringArray::isEmpty() const { return length == 0; }

std::string& StringArray::operator[](int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Індекс за межами діапазону StringArray!");
    }
    return data[index];
}

const std::string& StringArray::operator[](int index) const {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Індекс за межами діапазону const StringArray!");
    }
    return data[index];
}

void StringArray::erase() {
    delete[] data;
    data = nullptr;
    length = 0;
}

void StringArray::reallocate(int newLength) {
    erase();

    if (newLength > 0) {
        length = newLength;
        data = new std::string[length]{};
    }
}

StringArray::StringArray(const StringArray& other) {
    length = other.length;

    if (other.data != nullptr) {
        data = new std::string[length]{};
        for (int index = 0; index < length; index++) {
            data[index] = other.data[index];
        }
    } else {
        data = nullptr;
    }
}

StringArray& StringArray::operator=(const StringArray& other) {
    if (this == &other) return *this;

    length = other.length;
    delete[] data;

    if (other.data != nullptr) {
        data = new std::string[length]{};
        for (int index = 0; index < length; index++) {
            data[index] = other.data[index];
        }
    } else {
        data = nullptr;
    }
    return *this;
}

StringArray& StringArray::operator=(const std::initializer_list<std::string>& list) {
    length = list.size();
    delete[] data;
    data = nullptr;
    data = new std::string[length]{};

    int index = 0;
    for (const std::string &element : list) {
        data[index] = element;
        index++;
    }

    return *this;
}

void StringArray::resize(int newLength) {
    if (length == newLength) { return; }
    if (newLength <= 0) { erase(); return; }

    std::string *tempData = new std::string[newLength]{};
    int elementsToCopy = std::min(length, newLength);

    for (int index = 0; index < elementsToCopy; index++) {
        tempData[index] = data[index];
    }

    delete[] data;
    length = newLength;
    data = tempData;
}

void StringArray::insertBefore(const std::string& value, int index) {
    if (index < 0 || index > length) {
        throw std::out_of_range("Індекс за межами діапазону!");
    }

    std::string *tempData = new std::string[length + 1]{};

    for (int forIndex = 0; forIndex < index; forIndex++) {
        tempData[forIndex] = data[forIndex];
    }

    tempData[index] = value;

    for (int forIndex = index; forIndex < length; forIndex++) {
        tempData[forIndex + 1] = data[forIndex];
    }
    delete[] data;
    length++;
    data = tempData;
}

void StringArray::insertAtBeginning(const std::string& value) {
    insertBefore(value, 0);
}

void StringArray::insertAtEnd(const std::string& value) {
    insertBefore(value, length);
}

void StringArray::remove(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Індекс за межами діапазону!");
    }

    if (length == 1) { erase(); return; }

    std::string *tempData = new std::string[length - 1]{};
    int tempIndex = 0;

    for (int forIndex = 0; forIndex < length; forIndex++) {
        if (forIndex != index) {
            tempData[tempIndex] = data[forIndex];
            tempIndex++;
        }
    }

    delete[] data;
    length--;
    data = tempData;
}

std::ostream& operator<<(std::ostream& os, const StringArray& array) {
    os << "[";
    for (int index = 0; index < array.length; ++index) {
        os << "\"" << array.data[index] << "\"";
        if (index < array.length - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

void printConstElement(const StringArray& constArr, int index) {
    std::cout << constArr[index];
}
