/*
Завдання 2
Написати програму, що реалізує сортування масиву методом удосконаленого сортування
бульбашковим методом. Удосконалення полягає в тому, щоб аналізувати кількість перестановок
на кожному кроці, якщо ця кількість дорівнює нулю, то продовжувати сортування немає сенсу — масив відсортовано.
*/

#include <iostream>

int main() {
    const int SIZE = 10;
    int array[SIZE] = {1, 2, 4, 3, 5, 6, 7, 8, 10, 9};

    for (int pass = 0; pass < SIZE - 1; ++pass) {

        //Саме удосконалення (написав з is як ми вчили):
        bool isSwapped = false;

        for (int index = 0; index < SIZE - 1 - pass; ++index) {

            if (array[index] > array[index + 1]) {
                int temp = array[index];
                array[index] = array[index + 1];
                array[index + 1] = temp;

                isSwapped = true;
            }
        }
        if (!isSwapped)
            break;
    }

    for (int countResult = 0; countResult < SIZE; ++countResult)
        std::cout << array[countResult] << " ";

    return 0;
}