#include <iostream>
#include "BankAccount.h"

/*
Розробіть систему класів-винятків для класу банківського рахунку (BankAccount). Програма повинна валідувати операції та
сигналізувати про помилки через власну ієрархію винятків.

Вимоги:

Створіть базовий клас AccountException, похідний від std::runtime_error.
Створіть спеціалізовані класи-винятки:
- InvalidAmountException — передано некоректну суму (нульову або від'ємну).
- InsufficientFundsException — недостатньо коштів на балансі для здійснення операції.
- LimitExceededException — сума зняття перевищує встановлений разовий ліміт.

Кожен клас-виняток має зберігати контекст:
- InvalidAmountException: некоректна сума (double amount).
- InsufficientFundsException: поточний баланс (double balance) та запитана сума (double requestedAmount).
- LimitExceededException: разовий ліміт (double limit) та запитана сума (double requestedAmount).

Реалізуйте клас BankAccount:
- Поля: поточний баланс і ліміт на одну операцію зняття.
- deposit(double amount) — поповнення балансу.
- withdraw(double amount) — списання коштів з перевіркою коректності суми, ліміту та залишку.

У функції main() продемонструйте генерацію винятків та багаторівневу обробку через try ... catch (від конкретних винятків
до базового AccountException).
Очікуваний результат:
- Ієрархія з базового та 3 спеціалізованих класів винятків.
- Інформативні повідомлення у методі what().
- Геттери для отримання контекстних полів.
- Демонстрація правильної послідовності перехоплення (catch).
*/

int main() {

    BankAccount account(1000.0, 500.0);

    std::cout << "Успішне поповнення та зняття:\n";
    try {
        account.deposit(200.0);
        std::cout << "Успішно внесено 200 грн!\n";
        account.withdraw(300.0);
        std::cout << "Успішно знято 300 грн!\n";
    } catch (const AccountException &exception) {
        std::cout << "Помилка: " << exception.what() << '\n';
    }

    std::cout << "\nПеревищення ліміту при знятті:\n";
    try {
        account.withdraw(600.0);
    } catch (const LimitExceededException &exception) {
        std::cout << "Помилка LimitExceededException: " << exception.what() << '\n';
    } catch (const AccountException &exception) {
        std::cout << "Помилка: " << exception.what() << '\n';
    }

    std::cout << "\nНекоректна сума:\n";
    try {
        account.deposit(-50.0);
    } catch (const InvalidAmountException &exception) {
        std::cout << "Помилка InvalidAmountException: " << exception.what() << '\n';
    } catch (const AccountException &exception) {
        std::cout << "Помилка: " << exception.what() << '\n';
    }

    std::cout << "\nНедостатньо коштів:\n";
    try {
        BankAccount poorAccount(100.0, 500.0);
        poorAccount.withdraw(500.0);
    } catch (const InsufficientFundsException &exception) {
        std::cout << "Помилка InsufficientFundsException: " << exception.what() << '\n';
    } catch (const AccountException &exception) {
        std::cout << "Помилка: " << exception.what() << '\n';
    }

    return 0;
}