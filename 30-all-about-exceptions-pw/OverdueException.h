#pragma once
#include "LibraryException.h"

class OverdueException : public LibraryException {
private:
    std::string name = "Undefined";
    std::string dateIssue = "Undefined";
    std::string returnDeadline = "Undefined";
    double fineAmount = 0.0;

    std::string makeMessage(const std::string &name, const std::string &dateIssue, const std::string &returnDeadline, double fineAmount);

public:
    OverdueException(const std::string &name, const std::string &dateIssue, const std::string &returnDeadline, double fineAmount);

    std::string getName() const;
    std::string getDateIssue() const;
    std::string getReturnDeadline() const;
    double getFineAmount() const;
};