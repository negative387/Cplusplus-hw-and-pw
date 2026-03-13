/*
Рівень 3: Архітектура та Створення (Міні-проєкт)
Фокус: Реальний сценарій використання.

Міні-проєкт: "Генератор чека для кафе": Створіть програму, яка імітує замовлення в кав'ярні:
Програма вітається і запитує ім'я клієнта.

Користувач вводить ціну кави, кількість чашок та бажаний відсоток чайових (наприклад, 10%).

Програма має вивести фінальний "чек" у гарній рамці (використовуючи ASCII-символи *, -, |), де вказано:
- Ім'я клієнта.
- Загальну вартість замовлення.
- Суму чайових окремо.
- Фінальну суму до сплати.

Додатково: Використовуйте Escape-послідовності \t та \n для форматування чека.*/



#include <iostream>
#include <string>

int main() {
    std::string clientName;
    float coffeePrice;
    int cupsNumber;
    float tip;

    std::cout << "Вітаємо у кафе CupEE! Введіть ваше ім'я: ";
    std::cin >> clientName;
    std::cout << "Введіть ціну кави: ";
    std::cin >> coffeePrice;
    std::cout << "Введіть кількість чашок: ";
    std::cin >> cupsNumber;
    std::cout << "Введіть бажаний відсоток чайових: ";
    std::cin >> tip;

    float amount = coffeePrice * cupsNumber;
    float tipAmount = amount / 100 * tip;
    float finalAmount = amount + tipAmount;

    std::cout << "|---------------------" << std::endl;
    std::cout << "|        Ім'я:        " << std::endl;
    std::cout << "| -" << clientName << std::endl;
    std::cout << "|---------------------" << std::endl;
    std::cout << "|     Замовлення:     " << std::endl;
    std::cout << "| -" << "Кава " << cupsNumber << "шт." << std::endl;
    std::cout << "|---------------------" << std::endl;
    std::cout << "|      Вартість:      " << std::endl;
    std::cout << "| -" << amount << "₴" << std::endl;
    std::cout << "|---------------------" << std::endl;
    std::cout << "|    Сума чайових:    " << std::endl;
    std::cout << "| -" << tipAmount << "₴" << std::endl;
    std::cout << "|---------------------" << std::endl;
    std::cout << "|    ФІНАЛЬНА СУМА:   " << std::endl;
    std::cout << "| -" << finalAmount << "₴" << std::endl;
    std::cout << "|---------------------" << std::endl;
}