/*
Завдання 3
Число називається досконалим, якщо сума всіх його дільників дорівнює йому
самому. Напишіть функцію пошуку таких чисел у введеному інтервалі.
*/

#include <iostream>

void perfectNumberRange(int start, int end);

int main() {
    int userStartNumber;
    int userEndNumber;

    std::cout << "Введіть число початку діапазону:";
    std::cin >> userStartNumber;
    std::cout << "Введіть число кінця діапазону:";
    std::cin >> userEndNumber;

    std::cout << "Результат: ";
    perfectNumberRange(userStartNumber, userEndNumber);

    return 0;
}

void perfectNumberRange(int start, int end) {

    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
    }
    for (int numberInRange = start + 1; numberInRange < end; ++numberInRange){
        int divisorSum = 0;

        //Сума всіх дільників числа:
        for (int divisor = 1; divisor < numberInRange; ++divisor) {
         if (numberInRange % divisor == 0)
             divisorSum += divisor;
        }

        if (divisorSum == numberInRange)
            std::cout << numberInRange << " ";
    }
}