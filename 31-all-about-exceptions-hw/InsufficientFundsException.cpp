#include "InsufficientFundsException.h"

InsufficientFundsException::InsufficientFundsException(double balance, double requestedAmount):
    AccountException("Недостатньо коштів на балансі ( " + std::to_string(balance) + " грн. ) для здійснення операції на: " + std::to_string(requestedAmount) + " грн."),
    balance(balance),
    requestedAmount(requestedAmount) {}

double InsufficientFundsException::getBalance() const { return balance; }

double InsufficientFundsException::getRequestedAmount() const { return requestedAmount; }
