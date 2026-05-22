/*
Завдання 1. Реалізуйте функцію sum(int count, ...) з використанням макросів <cstdarg>. Перший аргумент вказує кількість
цілих чисел, що передаються далі. Поверніть їхню суму. Протестуйте для викликів sum(3, 10, 20, 30) та sum(5, 1, 2, 3, 4, 5).
*/

#include <iostream>
#include <cstdarg>

int sum(int count, ...);


int main() {

    std::cout << sum(3, 10, 20, 30) << std::endl;
    std::cout << sum(5, 1, 2, 3, 4, 5) << std::endl;

    return 0;
}


int sum(int count, ...) {

    int result = 0;

    va_list list;
    va_start(list, count);

    for (int element = 0; element < count; ++element)
        result += va_arg(list, int);

    va_end(list);

    return result;
}