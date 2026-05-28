/*
Завдання 4: Програма на C++ — псевдоніми типів у дії

Створіть програму, яка демонструє всі чотири причини використовувати псевдоніми типів.
Вимоги до програми:

1. Оголосіть псевдоніми через using для:
- фізичних одиниць (Meters, Kilograms, Seconds)
- типів зі <cstdint> (StudentId, Score, Timestamp)
- вказівника на функцію (Predicate)
- складного типу (оберіть самостійно)

2. Реалізуйте функцію double kineticEnergy(Kilograms mass, Meters speed) — формула ½mv²
3. Реалізуйте функцію int countIf(int* arr, int size, Predicate pred) — рахує елементи, для яких предикат true
4. Реалізуйте три предикати: isEven, isPositive, isGreaterThan100

У main():
- Виведіть кінетичну енергію для mass = 70.0 кг, speed = 15.0 м/с
- Для масиву {-5, 120, 3, 88, -1, 200, 7, 44, 150, -2} виведіть кількість елементів для кожного предиката
- Виведіть sizeof для кожного псевдоніма зі <cstdint>

*/


//✅
#include <iostream>
#include <cstdint>
#include <vector>

using Meters = double;
using Kilograms = double;
using Seconds = double;
using StudentId = uint64_t;
using Score = uint32_t;
using Timestamp = uint16_t;
using Predicate = bool (*)(int);
//Взяв складний тип з kostyl:
using StudentScoreList  = std::vector<std::pair<std::string, int>>;

double kineticEnergy(Kilograms mass, Meters speed);
int countIf(int* arr, int size, Predicate pred);
bool isEven(int value);
bool isPositive(int value);
bool isGreaterThan100(int value);
void printArray(int* array, int size);


int main() {

    const int SIZE = 10;
    int array[SIZE] = {-5, 120, 3, 88, -1, 200, 7, 44, 150, -2};
    Kilograms mass = 70.0;
    Meters speed = 15.0;

    std::cout << "=== Фізичні одиниці ===" << std::endl;
    std::cout << "Кінетична енергія (" << mass << "кг, " << speed << "м/с): " << kineticEnergy(mass, speed) << " Дж" << std::endl << std::endl;

    std::cout << "=== Предикати ===" << std::endl;
    std::cout << "Масив: ";
    printArray(array, SIZE);
    std::cout << "isEven: " << countIf(array, SIZE, isEven) << " елементів" << std::endl;
    std::cout << "isPositive: " << countIf(array, SIZE, isPositive) << " елементів" << std::endl;
    std::cout << "isGreaterThan100: " << countIf(array, SIZE, isGreaterThan100) << " елементів" << std::endl << std::endl;

    std::cout << "=== Розміри типів з <cstdint> ===" << std::endl;
    std::cout << "StudentId (int64_t): " << sizeof(StudentId) << " байт" << std::endl;
    std::cout << "Score (int32_t): " << sizeof(Score) << " байт" << std::endl;
    std::cout << "Timestamp (int16_t): " << sizeof(Timestamp) << " байт" << std::endl;

    return 0;
}


double kineticEnergy(Kilograms mass, Meters speed) { return speed * speed * mass / 2; }

int countIf(int* arr, int size, Predicate pred) {

    int isTrueCount = 0;

    for (int index = 0; index < size; ++index) {

        if (pred(arr[index]))
            isTrueCount += 1;
    }
    return isTrueCount;
}

bool isEven(int value) { return value % 2 == 0; }
bool isPositive(int value) { return value > 0; }
bool isGreaterThan100(int value) { return value > 100; }

void printArray(int* array, int size) {

    for (int index = 0; index < size; ++index)
        std::cout << array[index] << " ";
    std::cout << std::endl;
}
//❌


/*
Питання:
1. Чому sizeof(StudentId) гарантований, а sizeof(int) — ні?
2. Що потрібно змінити в програмі, якщо замість int для Score потрібен double? Скільки рядків?

✅
1 - cstdint фіксований, а просто int нефіксований.
2 - Замінити uint..._t на double. Один рядок: "using Score = double';
❌
*/