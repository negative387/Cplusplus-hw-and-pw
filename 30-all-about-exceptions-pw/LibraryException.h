#pragma once
#include <iostream>

class LibraryException : public std::runtime_error {
public:
    LibraryException(const std::string &message);
};