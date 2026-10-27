#pragma once
#include <stdexcept>


template <typename T>
class Stack {
private:
    T* data = nullptr;
    int maxCapacity = 1;
    int topIndex = -1;

public:
    Stack(int capacity);
    ~Stack();

    // Зробив як на сайти:
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    void push(const T& value);
    void pop();
    T top() const;

    bool isEmpty() const;
    bool isFull() const;

    int size() const;
    int capacity() const;
};

#include "Stack.hpp"
