#include "OverdueException.h"

std::string OverdueException::makeMessage(const std::string& name, const std::string& dateIssue,
    const std::string& returnDeadline, double fineAmount) {
    return "Книга з назвою: \"" + name + "\" прострочена! "
        + "Дата видачі: " + dateIssue + ". "
        + "Кінечний термін: " + returnDeadline + ". "
        + "Штраф: " + std::to_string(fineAmount) + " біткоїнів.";
}

OverdueException::OverdueException(const std::string& name, const std::string& dateIssue,
    const std::string& returnDeadline, double fineAmount):
    LibraryException(makeMessage(name, dateIssue, returnDeadline, fineAmount)),
    name(name),
    dateIssue(dateIssue),
    returnDeadline(returnDeadline),
    fineAmount(fineAmount) {}

std::string OverdueException::getName() const { return name; }

std::string OverdueException::getDateIssue() const { return dateIssue; }

std::string OverdueException::getReturnDeadline() const { return returnDeadline; }

double OverdueException::getFineAmount() const { return fineAmount; }
