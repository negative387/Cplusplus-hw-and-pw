#include "FilePrinterBinary.h"

void FilePrinterBinary::Display(const char* path) const {
    std::ifstream inputFile(path);

    if (!inputFile.is_open()) {
        std::cout << "ПОМИЛКА! Файл з шляхом: \"" << path << "\" не знайдено!\n";
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        for (char symbol : line) {
            // Побачив цей bitset у вас на сайті ( на сторінці "Системи числення та двійкова арифметика" ):
            std::cout << std::bitset<8>(symbol) << ' ';
        }
    }
    std::cout << '\n';

    inputFile.close();
}
