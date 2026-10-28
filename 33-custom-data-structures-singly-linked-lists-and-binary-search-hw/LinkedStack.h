#pragma once
#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node* next = nullptr;

    Node(T value, Node* nextNode) :
        data(value),
        next(nextNode) {}
};


template <typename T>
class LinkedStack {
private:
    Node<T> *head = nullptr;
    int capacity = 4;
    int currentSize = 0;

public:
    LinkedStack();
    ~LinkedStack();

    void push(T value);
    void pop();
    T top() const;

    int getCapacity() const;
    int getCurrentSize() const;
    bool isEmpty() const;

    Node<T>* clone() const;
    Node<T>* operator+(const LinkedStack<T> &other);
    Node<T>* operator*(const LinkedStack<T> &other);

    void print() const;
};

#include "LinkedStack.hpp"
