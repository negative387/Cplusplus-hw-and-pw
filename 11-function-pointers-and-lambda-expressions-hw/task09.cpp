/*
Завдання 9. Реалізуйте систему «конвеєра трансформацій» через масив std::function:

std::function<int(int)> pipeline[] = {
    [](int x) { return x * 2; },   // подвоїти
    [](int x) { return x + 10; },  // додати 10
    [](int x) { return x * x; }    // звести в квадрат
};

Напишіть функцію int applyPipeline(int value, std::function<int(int)>* steps, int count), що
послідовно застосовує кожен крок. Протестуйте для числа 3: 3 → 6 → 16 → 256.
*/


#include <iostream>
#include <functional>

int applyPipeline(int value, std::function<int(int)>* steps, int count);


int main(){

    int const SIZE = 3;
    std::function<int(int)> pipeline[SIZE] = {
        [](int x) { return x * 2; },
        [](int x) { return x + 10; },
        [](int x) { return x * x; }
    };

    std::cout << applyPipeline(3, pipeline, SIZE);

    return 0;
}

int applyPipeline(int value, std::function<int(int)>* steps, int count) {

    for (int index = 0; index < count; ++index)
        value = steps[index](value);

    return value;
}