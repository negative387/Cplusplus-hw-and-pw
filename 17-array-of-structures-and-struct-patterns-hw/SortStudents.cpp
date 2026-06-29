/*
Завдання 2: Сортування масиву структур за різними полями

Завдання: створіть SortStudents.cpp і реалізуйте:

1. Оголосіть ту ж структуру Student з полями name, age, gpa.
2. Ініціалізуйте масив із 6 студентів (різні імена, віки, GPA).
3. Реалізуйте три функції сортування (будь-який алгоритм, наприклад selection sort):
- void sortByName(Student* arr, int size) — за алфавітом, за зростанням (std::string має оператор <).
- void sortByAge(Student* arr, int size) — за зростанням віку.
- void sortByGpaDesc(Student* arr, int size) — за GPA за спаданням.
4. Усі три функції використовують std::swap (з <algorithm>) для обміну.
5. Реалізуйте void printAll(const Student* arr, int size) для виведення списку.
6. У main() послідовно викличте кожне сортування та виведіть результат.


1. Чому обмін через std::swap(arr[i], arr[minIdx]) коректний для масиву структур? що саме він копіює?
2. Чому для сортування за іменем використовується <, а для GPA — >?
3. Якби замість одного масиву students[] було три паралельних — що довелося б писати в тілі сортування?
4. Чому варто передавати Student* arr (не const), хоча ми лише переставляємо елементи?

✅
1 - Бо для std::swap структура це одне ціле і може міняти всі її поля одночасно. Копіює у тимчасову змінну, а потім міняє значення місцями.
2 - Бо імена за зростанням, а GPA за спаданням.
3 - Потрібно буде синхронно міняти місцями елементи у всіх 3 масивах.
4 - Щоб змогли змінювати орігінал.
❌
*/


#include <iostream>
#include <algorithm>

struct Student {
    std::string name;
    int age;
    double gpa;
};

void sortByName(Student* arr, int size);
void sortByAge(Student* arr, int size);
void sortByGpaDesc(Student* arr, int size);
void printAll(const Student* arr, int size);


int main() {

    const int SIZE = 6;
    Student arrayStudents[SIZE] = {
        {"Олена Коваль", 20, 3.90},
        {"Борис Шевченко", 22, 3.40},
        {"Тетяна Бондар", 21, 3.75},
        {"Дмитро Мельник", 19, 2.80},
        {"Аліна Петренко", 20, 3.60},
        {"Віктор Гриценко", 23, 3.85}
    };

    std::cout << "\n=== До сортування ===\n";
    printAll(arrayStudents, SIZE);

    std::cout << "\n=== Сортування за іменем ===\n";
    sortByName(arrayStudents, SIZE);
    printAll(arrayStudents, SIZE);

    std::cout << "\n=== Сортування за віком ===\n";
    sortByAge(arrayStudents, SIZE);
    printAll(arrayStudents, SIZE);

    std::cout << "\n=== Сортування за GPA (спадання) ===\n";
    sortByGpaDesc(arrayStudents, SIZE);
    printAll(arrayStudents, SIZE);

    return 0;
}


void sortByName(Student* arr, int size) {

    int nameMinIndex;

    for (int index = 0; index < size - 1; ++index) {
        nameMinIndex = index;

        for (int indexTwo = index + 1; indexTwo < size; ++indexTwo) {

            if (arr[indexTwo].name < arr[nameMinIndex].name)
                nameMinIndex = indexTwo;
        }
        std::swap(arr[nameMinIndex], arr[index]);
    }
}

void sortByAge(Student* arr, int size) {

    int ageMinIndex;

    for (int index = 0; index < size - 1; ++index) {
        ageMinIndex = index;

        for (int indexTwo = index + 1; indexTwo < size; ++indexTwo) {

            if (arr[indexTwo].age < arr[ageMinIndex].age)
                ageMinIndex = indexTwo;
        }
        std::swap(arr[ageMinIndex], arr[index]);
    }
}

void sortByGpaDesc(Student* arr, int size) {

    int gpaMaxIndex;

    for (int index = 0; index < size - 1; ++index) {

        gpaMaxIndex = index;

        for (int indexTwo = index + 1; indexTwo < size; ++indexTwo) {

            if (arr[indexTwo].gpa > arr[gpaMaxIndex].gpa)
                gpaMaxIndex = indexTwo;
        }
        std::swap(arr[gpaMaxIndex], arr[index]);
    }
}

void printAll(const Student* arr, int size) {

    for (int index = 0; index < size; ++index)
        std::cout << index + 1 << ". " << arr[index].name << " - вік: " << arr[index].age << ", GPA: " << arr[index].gpa << '\n';
}