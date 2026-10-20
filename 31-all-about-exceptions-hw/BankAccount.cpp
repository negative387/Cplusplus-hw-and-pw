#include "BankAccount.h"

BankAccount::BankAccount() {}

BankAccount::BankAccount(double balance, double limit):
    balance(balance),
    limit(limit) {}

void BankAccount::deposit(double amount) {
    if (amount <= 0) {
        throw InvalidAmountException(amount);
    }
    balance += amount;
}

void BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw InvalidAmountException(amount);
    }
    if (amount > limit) {
        throw LimitExceededException(limit, amount);
    }
    if (amount > balance) {
        throw InsufficientFundsException(balance, amount);
    }
    balance -= amount;
}

double BankAccount::getBalance() const { return balance; }

double BankAccount::getLimit() const { return limit; }
