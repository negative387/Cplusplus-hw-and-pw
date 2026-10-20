#pragma once
#include <iostream>

class AccountException : public std::runtime_error {
public:
    AccountException(const std::string &message);
};