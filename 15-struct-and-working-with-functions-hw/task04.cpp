/*
Завдання 4: Передача структур у функції — за значенням та за const&

Завдання: допишіть тіла функцій позначених // TODO.
*/

#include <iostream>
#include <string>

struct Student
{
    std::string name;
    int         age;
    double      gpa;
};

void celebrateBirthday(Student student);
void printStudent(const Student& student);
double scholarshipAmount(const Student& student);
bool hasHigherGpa(const Student& a, const Student& b);

int main()
{
    Student studentOlena { "Олена Коваль", 20, 3.9 };
    Student studentMaksym { "Максим Дяченко", 22, 3.4 };

    std::cout << "=== Демонстрація передачі за значенням ===\n";
    std::cout << "До: "; printStudent(studentOlena);
    std::cout << "\n";
    celebrateBirthday(studentOlena);
    std::cout << "\nПісля у main(): "; printStudent(studentOlena);
    std::cout << "\n(вік не змінився — змінювалась копія)\n\n";

    std::cout << "=== Стипендія ===\n";
    std::cout << studentOlena.name << " отримає " << scholarshipAmount(studentOlena) << " грн\n";
    std::cout << studentMaksym.name << " отримає " << scholarshipAmount(studentMaksym) << " грн\n";

    std::cout << "\n=== Порівняння ===\n";
    if (hasHigherGpa(studentOlena, studentMaksym))
        std::cout << studentOlena.name << " має більший GPA\n";
    else
        std::cout << studentMaksym.name << " має більший GPA\n";

    return 0;
}

// За значенням — створює копію, змінює копію
// TODO: додає 1 до віку копії, виводить повідомлення
void celebrateBirthday(Student student)
{
    student.age += 1;
    std::cout << "Всередині функції: " << student.name <<  " тепер " << student.age << " років";
}

// За константним посиланням — без копіювання, лише читання
// TODO: виводить ім'я, вік та GPA студента
void printStudent(const Student& student)
{
    std::cout << student.name << ", " << student.age << " р., GPA: " << student.gpa;
}

// За константним посиланням — обчислення без модифікації
// TODO: повертає суму стипендії
// Якщо gpa >= 3.5 — стипендія = gpa * 1000.0
// Інакше — стипендія = gpa * 500.0
double scholarshipAmount(const Student& student)
{
    if (student.gpa >= 3.5)
        return student.gpa * 1000.0;

    return student.gpa * 500.0;
}

// TODO: порівнює двох студентів за GPA
// Повертає true якщо перший має більший GPA
bool hasHigherGpa(const Student& a, const Student& b)
{
    if (a.gpa > b.gpa)
        return true;

    return false;
}

/*
Очікуваний вивід:

=== Демонстрація передачі за значенням ===
До: Олена Коваль, 20 р., GPA: 3.9
Всередині функції: Олена Коваль тепер 21 років
Після у main(): Олена Коваль, 20 р., GPA: 3.9
(вік не змінився — змінювалась копія)

=== Стипендія ===
Олена Коваль отримає 3900 грн
Максим Дяченко отримає 1700 грн

=== Порівняння ===
Олена Коваль має більший GPA


Питання:
1. Скільки копій Student створюється при виклику celebrateBirthday(studentOlena)? Чи можна це перевірити?
2. Чому printStudent приймає const Student&, а не просто Student? Яка економія для структури з std::string?
3. У якому випадку передача за значенням буде ефективнішою за const&?

✅
1 - 1 копія. Якщо оригінал в main не змінився, а в функціі змінився, то значить в функціі копія :) .
2 - Щоб не було зайвої копії та функція не змогла змінювати оригінал. Напевно економія пам'яті.
3 - Коли структура невелика та звичайна (без масива та string).
❌
*/