#include <iostream>
#include "LinkedStack.h"

/*
Завдання №1
Реалізуйте стек у вигляді однозв’язного списку. Потрібно реалізувати типові операції з роботи зі стеком. При переповненні
стеку потрібно збільшувати його розмір.

Завдання №2
В існуючий клас однозв’язного списку додати: операцію клонування списку (функція повинна повертати адресу голови
клонованого списку), перевантажити оператор «+» (оператор повинен повертати адресу голови нового списку, що містить
елементи обох списків для яких викликався оператор), перевантажити оператор «*» (оператор повинен повертати адресу голови
нового списку, який містить тільки загальні елементи обох списків для яких викликався оператор).
*/

template <typename T>
void printList(Node<T> *head) {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << ' ';
        current = current->next;
    }
    std::cout << '\n';
}

template <typename T>
void freeList(Node<T> *head) {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    LinkedStack<int> stackOne;
    stackOne.push(40);
    stackOne.push(30);
    stackOne.push(20);
    stackOne.push(10);

    LinkedStack<int> stackTwo;
    stackTwo.push(60);
    stackTwo.push(10);
    stackTwo.push(50);
    stackTwo.push(30);

    std::cout << "Стек 1: ";
    stackOne.print();
    std::cout << '\n';

    std::cout << "Стек 2: ";
    stackTwo.print();
    std::cout << "\n\n";

    //Перевірка clone():
    Node<int>* copiedHead = stackOne.clone();
    std::cout << "Копія стека 1: ";
    printList(copiedHead);

    //Перевірка operator+ :
    Node<int>* sumHead = stackOne + stackTwo;
    std::cout << "Стек 1 + cтек 2: ";
    printList(sumHead);

    //Перевірка operator* :
    Node<int>* intersectHead = stackOne * stackTwo;
    std::cout << "Стек 1 * cтек 2: ";
    printList(intersectHead);

    //Очищення пам'яті... якщо б у модулях copy, +, * повертати саме стек, а не голову то було б простіше =(
    freeList(copiedHead);
    freeList(sumHead);
    freeList(intersectHead);

    return 0;
}