/*
Завдання 4. Оголосіть змінну int x = 100, звичайний вказівник int* p = &x та подвійний
вказівник int** pp = &p. Виведіть значення x трьома способами: через x, через *p та через **pp.
Переконайтесь, що всі три виводять 100.
*/

#include <iostream>


int main() {

    int x = 100;
    int* p = &x;
    int** pp = &p;

    std::cout << x << std::endl;
    std::cout << *p << std::endl;
    std::cout << **pp << std::endl;

    return 0;
}

