/*
Завдання 3: Масив структур

Завдання: допишіть тіла функцій позначених // TODO.
*/

#include <iostream>
#include <string>
#include <iomanip>


struct Employee
{
    std::string name;
    std::string department;
    double      salary;
};

void printTable(const Employee* arr, int size);
double averageSalary(const Employee* arr, int size);
const Employee& findHighestPaid(const Employee* arr, int size);
int countByDepartment(const Employee* arr, int size, const std::string& department);

int main()
{
    const int SIZE = 5;
    Employee team[SIZE] =
    {
        { "Олена Коваль",    "Розробка",  35000.0 },
        { "Максим Дяченко",  "Маркетинг", 28000.0 },
        { "Тетяна Бондар",   "Розробка",  42000.0 },
        { "Іван Петренко",   "HR",        25000.0 },
        { "Анна Шевченко",   "Маркетинг", 31000.0 },
    };

    printTable(team, SIZE);

    std::cout << "\nСередня зарплата: " << averageSalary(team, SIZE) << " грн\n";

    const Employee& topEarner = findHighestPaid(team, SIZE);
    std::cout << "Найвища зарплата: " << topEarner.name << " — " << topEarner.salary << " грн\n";

    std::cout << "Розробка: " << countByDepartment(team, SIZE, "Розробка") << " осіб\n";
    std::cout << "Маркетинг: " << countByDepartment(team, SIZE, "Маркетинг") << " осіб\n";

    return 0;
}


// TODO: виводить таблицю співробітників з заголовком та розділювачем
// Використовуйте std::setw для вирівнювання стовпців
void printTable(const Employee* arr, int size)
{
    // - Я цей код здебільшого загуглив:
    std::cout << std::left << std::setw(25) << "ПІБ";
    std::cout << std::setw(30) << "Відділ";
    std::cout << "Зарплата\n";

    std::cout << "--------------------------------------------------------\n";

    for (int i = 0; i < size; ++i) {

        int name_padding = static_cast<int>(25 + (arr[i].name.length() - arr[i].name.length() / 2));
        std::cout << std::left << std::setw(name_padding) << arr[i].name;

        int dept_padding = static_cast<int>(25 + (arr[i].department.length() - arr[i].department.length() / 2));
        std::cout << std::setw(dept_padding) << arr[i].department;

        std::cout << arr[i].salary << "\n";
    }
}

// TODO: повертає середню зарплату по масиву
double averageSalary(const Employee* arr, int size)
{
    double amount = 0;

    for (int i = 0; i < size; ++i)
        amount += arr[i].salary;

    return amount / size;
}

// TODO: повертає посилання на співробітника з найвищою зарплатою
const Employee& findHighestPaid(const Employee* arr, int size)
{
    const Employee *highestPaidPtr = &arr[0];

    for (int i = 1; i < size; ++i) {

        if (highestPaidPtr->salary < arr[i].salary)
            highestPaidPtr = &arr[i];
    }

    return *highestPaidPtr;
}

// TODO: повертає кількість співробітників у вказаному відділі
int countByDepartment(const Employee* arr, int size, const std::string& department)
{
    int countDepartment = 0;

    for (int i = 0; i < size; ++i) {

        if (arr[i].department == department)
            ++countDepartment;
    }

    return countDepartment;
}

/*
Питання:
1. Чому функція findHighestPaid повертає const Employee&, а не Employee за значенням?
2. Що станеться, якщо у функції printTable параметр буде Employee* arr замість const Employee* arr?
3. Як зміниться код, якщо кількість співробітників змінюватиметься під час виконання програми?

✅
1 - Щоб не було зайвого копіювання.
2 - Функция printTable зможе змінювати Employee.
3 - Потрібно буде зробити динамічну пам'ять :) .
❌
*/