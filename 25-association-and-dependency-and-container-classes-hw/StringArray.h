#pragma once
#include <iostream>

class StringArray {
private:
    int length = 0;
    std::string *data = nullptr;

public:
    // Завдання 1: Оголошення класу та базові конструктори / деструктор:
    StringArray();

    explicit StringArray(int arrayLength);

    StringArray(const std::initializer_list<std::string> &list);

    ~StringArray();

    int getLength() const;

    bool isEmpty() const;

    // Завдання 2: Доступ до елементів та безпечне очищення
    std::string& operator[](int index);

    const std::string& operator[](int index) const;

    void erase();

    void reallocate(int newLength);

    friend std::ostream& operator<<(std::ostream& os, const StringArray& array);

    // Завдання 3: Правило трьох (Rule of Three) — Глибоке копіювання
    StringArray(const StringArray& other);

    StringArray& operator=(const StringArray& other);

    StringArray& operator=(const std::initializer_list<std::string>& list);

    //Завдання 4: Зміна розміру та вставка / видалення елементів:
    void resize(int newLength);

    void insertBefore(const std::string& value, int index);

    void insertAtBeginning(const std::string& value);

    void insertAtEnd(const std::string& value);

    void remove(int index);
};

std::ostream& operator<<(std::ostream& os, const StringArray& array);

void printConstElement(const StringArray& constArr, int index);
