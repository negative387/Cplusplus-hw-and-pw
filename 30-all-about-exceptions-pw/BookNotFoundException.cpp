#include "BookNotFoundException.h"

BookNotFoundException::BookNotFoundException(const std::string& inputName):
    LibraryException("Не знайдено книгу: " + inputName),
    name(inputName) {}

std::string BookNotFoundException::getName() const { return name; }
