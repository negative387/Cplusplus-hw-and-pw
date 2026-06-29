/*
Завдання 1: Масив структур замість паралельних масивів

Завдання: створіть ClassRoom.cpp і реалізуйте:

1. Оголосіть структуру Student з полями: std::string name, int age, double gpa.
2. Ініціалізуйте масив із 5 студентів (на ваш вибір).
3. Реалізуйте функцію друку одного студента void printStudent(const Student& student) з вирівняними стовпцями через
<iomanip> (ширина імені 20, віку 4, GPA 8, два знаки після коми).
4. Реалізуйте функцію друку всієї групи void printClass(const Student* arr, int size), що спочатку виводить заголовок і
розділову лінію.
5. Реалізуйте const Student* findByName(const Student* arr, int size, const std::string& name) — лінійний пошук;
повертає вказівник на знайденого студента або nullptr.
6. Реалізуйте int indexOfBest(const Student* arr, int size) — повертає індекс студента з максимальним GPA; для
порожнього масиву повертає -1.
7. У main() викличте всі функції та продемонструйте пошук студента, якого немає.

Питання:
1. Чому три паралельних масиви (names[], ages[], gpas[]) — гірший дизайн ніж один масив students[]?
2. Чому findByName повертає const Student*, а не індекс чи копію Student?
3. Навіщо indexOfBest повертає -1, а не 0 у випадку порожнього масиву?
4. Чому перед використанням результату findByName обов'язкова перевірка на nullptr?

✅
1 - Бо це не оптимізовано та важче для написання коду.
2 - Бо копія Student може бути занадто великою, а не індекс щоб було можливо повертати nullptr.
3 - 0 може бути першим елементом масиву, а -1 це чітка помилка.
4 - Щоб програма не завершилась помилкою.
❌
*/

#include <iostream>
#include <iomanip>
#include <string>

struct Student {
    std::string name;
    int age;
    double gpa;
};

void printStudent(const Student& student);
void printClass(const Student* arr, int size);
const Student* findByName(const Student* arr, int size, const std::string& name);
int indexOfBest(const Student* arr, int size);


int main() {

    const int SIZE = 5;
    Student arrayStudents[SIZE] = {
        {"Олена Коваль", 20, 3.90},
        {"Борис Шевченко", 22, 3.40},
        {"Тетяна Бондар", 21, 3.75},
        {"Дмитро Мельник", 19, 3.80},
        {"Аліна Петренко", 20, 3.60}
    };

    std::cout << "\n=== Друк одного студента ===\n";
    printStudent(arrayStudents[0]);

    std::cout << "\n=== Список групи ===\n";
    printClass(arrayStudents, SIZE);

    std::cout << "\n=== Пошук студента ===\n";
    const Student* findName = findByName(arrayStudents, SIZE, "Тетяна Бондар");
    if (findName)
        std::cout << "Знайдено: " << findName->name << ", GPA: " << findName->gpa << '\n';
    else
        std::cout << "Не знайдено\n";

    std::cout << "\n=== Пошук студента, якого немає ===\n";
    const Student* noFindName = findByName(arrayStudents, SIZE, "Тарас Шевченко");
    if (noFindName)
        std::cout << "Знайдено: " << noFindName->name << ", GPA: " << noFindName->gpa << '\n';
    else
        std::cout << "Не знайдено\n";

    std::cout << "\n=== Найкращий студент ===\n";
    int indexGpaBest = indexOfBest(arrayStudents, SIZE);
    if (indexGpaBest != -1) {

        std::cout << arrayStudents[indexGpaBest].name << " (GPA: " << arrayStudents[indexGpaBest].gpa << ")\n";
    }
    else
        std::cout << "Порожній масив\n";

    return 0;
}


void printStudent(const Student& student) {

    std::cout << std::setw(20) << student.name << std::setw(4) << student.age << std::setw(8) << std::fixed << std::setprecision(2) << student.gpa << '\n';
}

void printClass(const Student* arr, int size) {

    std::cout << std::left << std::setw(20) << "Ім'я" << std::setw(15) << "Вік" << "GPA\n";
    std::cout << std::string(32, '-') << '\n';

    for (int index = 0; index < size; ++index)
        std::cout << std::left << std::setw(30) << arr[index].name << std::setw(10) << arr[index].age << arr[index].gpa << '\n';
}

const Student* findByName(const Student* arr, int size, const std::string& name) {

    for (int index = 0; index < size; ++index) {

        if (arr[index].name == name)
            return &arr[index];
    }
    return nullptr;
}

int indexOfBest(const Student* arr, int size) {

    if (size <= 0 || arr == nullptr) { return -1; }

        int bestGpaIndex = 0;
        for (int index = 1; index < size; ++index) {

            if (arr[index].gpa > arr[bestGpaIndex].gpa)
                bestGpaIndex = index;
        }
        return bestGpaIndex;
}