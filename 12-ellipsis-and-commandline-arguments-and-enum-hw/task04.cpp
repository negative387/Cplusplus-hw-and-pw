/*
Завдання 4. Напишіть програму, яка приймає аргументи командного рядка (argc, argv).
Програма повинна виводити:

- Ім'я самої програми (перший елемент argv).
- Кількість переданих аргументів.
- Кожен аргумент у форматі Argument [i]: value.
*/


#include <iostream>

int main(int argc, char* argv[]) {

    std::cout << "Ім'я програми: " << argv[0] << std::endl;
    std::cout << "Кількість аргументів: " << argc << std::endl;
    std::cout << "Аргументи:" << std::endl;

    for (int index = 1; index < argc; ++index) {

        std::cout << "Argument [" << index << "] = " << argv[index] << std::endl;
    }

    return 0;
}