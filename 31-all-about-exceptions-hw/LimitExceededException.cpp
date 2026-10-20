#include "LimitExceededException.h"

LimitExceededException::LimitExceededException(double limit, double requestedAmount):
    AccountException("Сума зняття ( " + std::to_string(requestedAmount) + " грн. ) перевищує встановлений разовий ліміт: " + std::to_string(limit) + " грн."),
    limit(limit),
    requestedAmount(requestedAmount) {}

double LimitExceededException::getLimit() const { return limit; }

double LimitExceededException::getRequestedAmount() const { return requestedAmount; }
