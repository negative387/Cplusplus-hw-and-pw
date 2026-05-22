/*
Завдання 2. Реалізуйте варіативну функцію min(int count, ...), яка знаходить мінімальне число серед переданих аргументів.
Перевірте її роботу, передавши 4-5 різних чисел.
*/

#include <iostream>
#include <cstdarg>

int min(int count, ...);


int main() {

    std::cout << min(5, 9, 4, 14, 3, 8);

    return 0;
}


int min(int count, ...) {

    va_list list;
    va_start(list, count);

    int minValue = va_arg(list, int);

    for (int element = 1; element < count; ++element) {
        int current = va_arg(list, int);

        if (current < minValue)
            minValue = current;
    }

    va_end(list);

    return minValue;
}