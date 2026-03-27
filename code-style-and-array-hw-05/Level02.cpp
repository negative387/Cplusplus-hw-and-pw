/*
Завдання 2
Напишіть програму, яка виконує поелементну суму двох масивів і
результат заносить у третій масив.
*/

#include <iostream>

int main() {

    const int SIZE = 5;
    int firstArray[SIZE] = {12, 33, 41, 20, 6};
    int secondArray[SIZE] = {9, 15, 2, 47, 6};
    int sumArray[SIZE];

    for (int count = 0; count < SIZE; ++count) {
        sumArray[count] = firstArray[count] + secondArray[count];
        std::cout << firstArray[count] << " + " << secondArray[count] << " = " << sumArray[count] << std::endl;
    }

    return 0;
}