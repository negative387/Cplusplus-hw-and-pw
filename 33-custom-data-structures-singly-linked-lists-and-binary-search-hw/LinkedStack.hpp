#include <iostream>

template <typename T>
LinkedStack<T>::LinkedStack() {
}

template <typename T>
LinkedStack<T>::~LinkedStack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void LinkedStack<T>::push(T value) {
    if (capacity == currentSize) {
        capacity *= 2;
    }

    Node<T>* newNode = new Node<T>(value, head);
    head = newNode;
    currentSize++;
}

template <typename T>
void LinkedStack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Однозв'язанний стек порожній! Неможливо видалити елемент!");
    }
    Node<T>* tempNode = head;
    head = head->next;
    delete tempNode;
    currentSize--;
}

template <typename T>
T LinkedStack<T>::top() const {
    if (isEmpty()) {
        throw std::underflow_error("Однозв'язанний стек порожній! Неможливо побачити верхній елемент!");
    }
    return head->data;
}

template <typename T>
int LinkedStack<T>::getCapacity() const { return capacity; }

template <typename T>
int LinkedStack<T>::getCurrentSize() const { return currentSize; }

template <typename T>
bool LinkedStack<T>::isEmpty() const {
    return currentSize == 0;
}

template <typename T>
Node<T>* LinkedStack<T>::clone() const {
    if (head == nullptr) {
        return nullptr;
    }

    Node<T>* newHead = new Node<T>(head->data, nullptr);
    Node<T>* currentNode = head->next;
    Node<T>* currentClone = newHead;

    while (currentNode != nullptr) {
        currentClone->next = new Node<T>(currentNode->data, nullptr);
        currentClone = currentClone->next;
        currentNode = currentNode->next;
    }

    return newHead;
}

template <typename T>
Node<T>* LinkedStack<T>::operator+(const LinkedStack<T> &other) {
    LinkedStack<T> tempStack;

    Node<T>* currentThis = this->head;
    while (currentThis != nullptr) {
        tempStack.push(currentThis->data);
        currentThis = currentThis->next;
    }

    Node<T>* currentOther = other.head;
    while (currentOther != nullptr) {
        tempStack.push(currentOther->data);
        currentOther = currentOther->next;
    }

    LinkedStack<T> result;
    Node<T>* currentTemp = tempStack.head;
    while (currentTemp != nullptr) {
        result.push(currentTemp->data);
        currentTemp = currentTemp->next;
    }

    return result.clone();
}

template <typename T>
Node<T>* LinkedStack<T>::operator*(const LinkedStack<T> &other) {
    if (this->head == nullptr || other.head == nullptr) {
        return nullptr;
    }

    LinkedStack<T> temp;
    Node<T>* currentThis = this->head;

    while (currentThis != nullptr) {
        Node<T>* currentOther = other.head;
        bool foundInOther = false;

        while (currentOther != nullptr) {
            if (currentThis->data == currentOther->data) {
                foundInOther = true;
                break;
            }
            currentOther = currentOther->next;
        }

        if (foundInOther) {
            Node<T>* currentResult = temp.head;
            bool alreadyExists = false;

            while (currentResult != nullptr) {
                if (currentResult->data == currentThis->data) {
                    alreadyExists = true;
                    break;
                }
                currentResult = currentResult->next;
            }

            if (!alreadyExists) {
                temp.push(currentThis->data);
            }
        }
        currentThis = currentThis->next;
    }

    LinkedStack<T> result;
    Node<T>* currentTemp = temp.head;
    while (currentTemp != nullptr) {
        result.push(currentTemp->data);
        currentTemp = currentTemp->next;
    }

    return result.clone();
}

template <typename T>
void LinkedStack<T>::print() const {
    Node<T>* current = this->head;

    while (current != nullptr) {
        std::cout << current->data << ' ';
        current = current->next;
    }
}