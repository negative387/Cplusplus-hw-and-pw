#pragma once
#include "AccountException.h"

class LimitExceededException  : public AccountException {
private:
    double limit = 0.0;
    double requestedAmount = 0.0;

public:
    LimitExceededException(double limit, double requestedAmount);

    double getLimit() const;
    double getRequestedAmount() const;
};