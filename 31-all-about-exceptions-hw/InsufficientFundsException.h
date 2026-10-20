#pragma once
#include "AccountException.h"

class InsufficientFundsException  : public AccountException {
private:
    double balance = 0.0;
    double requestedAmount = 0.0;

public:
    InsufficientFundsException(double balance, double requestedAmount);

    double getBalance() const;
    double getRequestedAmount() const;
};