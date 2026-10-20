#include "AccountException.h"

AccountException::AccountException(const std::string &message):
    std::runtime_error(message) {}
