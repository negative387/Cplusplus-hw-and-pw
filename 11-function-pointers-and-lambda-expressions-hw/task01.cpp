/*
Завдання 1. Оголосіть вказівник calcPtr на функцію, що приймає два int і повертає int. Напишіть функції
add, subtract і multiply з такою сигнатурою. Послідовно присвоюйте кожну функцію calcPtr і викликайте
через нього з аргументами 10 і 4. Виведіть результати.
*/


#include <iostream>


int add(int valueOne, int valueTwo);
int subtract(int valueOne, int valueTwo);
int multiply(int valueOne, int valueTwo);

int main() {

    int (*calcPtr)(int, int);

    calcPtr = add;
    std::cout << calcPtr(10, 4) << std::endl;

    calcPtr = subtract;
    std::cout << calcPtr(10, 4) << std::endl;

    calcPtr = multiply;
    std::cout << calcPtr(10, 4) << std::endl;

    return 0;
}


int add(int valueOne, int valueTwo) { return valueOne + valueTwo; }
int subtract(int valueOne, int valueTwo) { return valueOne - valueTwo; }
int multiply(int valueOne, int valueTwo) { return valueOne * valueTwo; }