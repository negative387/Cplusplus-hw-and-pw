#include "InvalidAmountException.h"

InvalidAmountException::InvalidAmountException(double amount):
    AccountException("Передано некоректну суму: " + std::to_string(amount)),
    amount(amount) {}

double InvalidAmountException::getAmount() const { return amount; }
