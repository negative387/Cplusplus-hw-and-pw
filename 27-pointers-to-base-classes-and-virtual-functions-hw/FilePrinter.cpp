#include "FilePrinter.h"

void FilePrinter::display(const char* path) const {
    std::ifstream inputFile(path);

    if (!inputFile.is_open()) {
        std::cout << "ПОМИЛКА! Файл з шляхом: \"" << path << "\" не знайдено!\n";
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << '\n';
    }

    inputFile.close();
}

FilePrinter::~FilePrinter() = default;
