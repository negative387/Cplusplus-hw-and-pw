/*
Завдання 5: Мутатори та передача за посиланням/вказівником

Завдання: допишіть тіла функцій позначених // TODO.
*/

#include <iostream>
#include <string>
#include <cstdint>

struct BankAccount
{
    std::string ownerName;
    uint32_t    accountNumber;
    double      balance;
};

void printAccount(const BankAccount& account);
bool createAccount(const std::string& name, uint32_t number, BankAccount& out);
bool deposit(BankAccount& account, double amount);
bool withdraw(BankAccount& account, double amount);
BankAccount* findAccount(BankAccount* accounts, int size, uint32_t number);

int main()
{
    const int SIZE = 3;
    BankAccount accounts[SIZE];

    // Створення через фабрику
    createAccount("Олена Коваль",   1001, accounts[0]);
    createAccount("Максим Дяченко", 1002, accounts[1]);
    createAccount("Тетяна Бондар",  1003, accounts[2]);

    // Демонстрація невдалого створення
    BankAccount invalidAccount;
    if (!createAccount("", 1004, invalidAccount))
        std::cout << "Не вдалося створити рахунок з порожнім ім'ям\n\n";

    std::cout << "=== Початкові баланси ===\n";
    for (int i = 0; i < SIZE; ++i)
        printAccount(accounts[i]);

    std::cout << "\n=== Операції ===\n";
    std::cout << "Поповнення #1001 на 5000:\n";
    deposit(accounts[0], 5000.0);
    printAccount(accounts[0]);

    std::cout << "\nЗняття з #1002 на 10000:\n";
    withdraw(accounts[1], 10000.0);

    std::cout << "\nЗняття з #1002 на 3000:\n";
    withdraw(accounts[1], 3000.0);
    printAccount(accounts[1]);

    std::cout << "\n=== Пошук через вказівник ===\n";
    BankAccount* foundAccount = findAccount(accounts, SIZE, 1003);
    if (foundAccount != nullptr) {
        std::cout << "Знайдено: "; printAccount(*foundAccount);
    }
    else
        std::cout << "Рахунок не знайдено\n";

    BankAccount* notFoundAccount = findAccount(accounts, SIZE, 9999);
    if (notFoundAccount != nullptr) {
        std::cout << "Знайдено: "; printAccount(*notFoundAccount);
    }
    else
        std::cout << "Рахунок #9999 не знайдено\n";

    return 0;
}

void printAccount(const BankAccount& account)
{
    std::cout << "Рахунок #" << account.accountNumber
              << " | " << account.ownerName
              << " | Баланс: " << account.balance << " грн\n";
}

// TODO: фабрична функція — створює рахунок з балансом 0.0
// Повертає true якщо ім'я непорожнє, інакше — false
bool createAccount(const std::string& name, uint32_t number, BankAccount& out)
{
    if (name.empty())
        return false;


    out.ownerName = name;
    out.accountNumber = number;
    out.balance = 0.0;
    std::cout << "Акаунт успішно зроблено!!!\n";

    return true;
}

// TODO: поповнює рахунок на amount
// Повертає false якщо amount <= 0
bool deposit(BankAccount& account, double amount)
{
    if (amount <= 0) {
        std::cout << "Помилка! Рахунок не може бути менше або дорівнює 0!\n";
        return false;
    }

    account.balance += amount;
    std::cout << "Успішно поповнено!!!\n";
    return true;
}

// TODO: знімає кошти з рахунку
// Повертає false якщо amount <= 0 або amount > balance
bool withdraw(BankAccount& account, double amount)
{
    if (amount <= 0 || amount > account.balance) {
        std::cout << "Помилка! У вас нехватає коштів! :(\n";
        return false;
    }

    account.balance -= amount;
    std::cout << "Успішно знято кошти!!!\n";
    return true;
}

// TODO: шукає рахунок за номером
// Повертає вказівник на знайдений рахунок або nullptr
BankAccount* findAccount(BankAccount* accounts, int size, uint32_t number)
{
    for (int i = 0; i < size; ++i) {

        if (accounts[i].accountNumber == number)
            return &accounts[i];
    }

    return nullptr;
}

/*
Питання:
1. Чому deposit і withdraw повертають bool, а не просто змінюють баланс?
2. У чому різниця між findAccount, що повертає BankAccount*, і функцією, що повертає BankAccount&? Коли nullptr кращий за виключення?
3. Що станеться, якщо викликати deposit(accounts[0], -500)?

✅
1 - Щоб повідомити программі успішно або ні.
2 - У BankAccount& повинно гарантувати що акаунт є, а BankAccount* якщо немає буде повертати nullptr. Коли акаунта може бути не знайдено.
3 - Помилка: "Помилка! Рахунок не може бути менше або дорівнює 0!" :) .
❌
*/