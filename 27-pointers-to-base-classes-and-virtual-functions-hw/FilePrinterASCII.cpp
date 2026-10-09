#include "FilePrinterASCII.h"

void FilePrinterASCII::Display(const char* path) const {
    std::ifstream inputFile(path);

    if (!inputFile.is_open()) {
        std::cout << "ПОМИЛКА! Файл з шляхом: \"" << path << "\" не знайдено!\n";
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        for (char symbol : line) {
            int asciiCode = static_cast<unsigned char>(symbol);
            std::cout << asciiCode << ' ';
        }
        std::cout << '\n';
    }

    inputFile.close();
}
