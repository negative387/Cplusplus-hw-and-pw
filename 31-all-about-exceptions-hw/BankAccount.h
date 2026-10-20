#pragma once
#include "InvalidAmountException.h"
#include "InsufficientFundsException.h"
#include "LimitExceededException.h"

class BankAccount {
private:
    double balance = 0.0;
    double limit = 0.0;

public:
    BankAccount();

    BankAccount(double balance, double limit);

    void deposit(double amount);

    void withdraw(double amount);

    double getBalance() const;
    double getLimit() const;
};