/*
Завдання 6. Реалізуйте систему «конвеєра обробки даних» (pipeline):

using Transform = int (*)(int);

// Функція apply застосовує масив трансформацій послідовно до числа
int apply(int value, Transform* pipeline, int steps);
Напишіть щонайменше 3 трансформації (double_val, addTen, square). У main створіть конвеєри
з різних комбінацій трансформацій і продемонструйте результати:

[double_val, addTen] для числа 5 → 5*2=10 → 10+10=20
[square, double_val] для числа 3 → 3*3=9 → 9*2=18
*/


#include <iostream>


using Transform = int (*)(int);

int doubleVal(int value);
int addTen(int value);
int square(int value);
int apply(int value, Transform* pipeline, int steps);


int main() {

    const int SIZE = 2;
    Transform pipelineOne[SIZE] = { doubleVal, addTen };
    Transform pipelineTwo[SIZE] = { square, doubleVal };

    std::cout << apply(5, pipelineOne, SIZE) << std::endl;
    std::cout << apply(3, pipelineTwo, SIZE) << std::endl;

    return 0;
}


int doubleVal(int value) { return value * 2; }
int addTen(int value) { return value + 10; }
int square(int value) { return value * value; }

int apply(int value, Transform* pipeline, int steps) {

    for (int index = 0; index < steps; ++index)
        value = pipeline[index](value);

    return value;
}