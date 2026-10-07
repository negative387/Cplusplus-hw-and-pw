#pragma once
#include <cstring>

class String {
protected:
    int length = 0;
    char *data = nullptr;

public:
    String();

    String(const char *line);

    String(const String &other);

    String& operator=(const String &other);

    int getLength() const;
    const char* getData() const;

    void erase();

    ~String();

    friend String operator+(const String &left, const String &right);

    String& operator+=(const String& other);

    friend bool operator==(const String &left, const String &right);
    friend bool operator!=(const String &left, const String &right);

};