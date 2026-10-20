#pragma once
#include "AccountException.h"

class InvalidAmountException : public AccountException {
private:
    double amount = 0.0;

public:
    InvalidAmountException(double amount);

    double getAmount() const;
};