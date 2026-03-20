/**
Завдання 2
Підрахувати кількість цілих чисел у діапазоні від 100 до 999, у яких усі цифри різні.
**/

#include <iostream>

int main() {
    for (int count = 100; count <= 999; ++count) {
        if ((count % 10 != count / 100) && (count % 10 != count / 10 % 10) && (count / 100 != count / 10 % 10))
            std::cout << count << " ";
    }
}