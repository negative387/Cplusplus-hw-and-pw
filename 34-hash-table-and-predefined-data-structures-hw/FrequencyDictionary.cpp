#include "FrequencyDictionary.h"

std::string FrequencyDictionary::normalizeWord(const std::string& word) {

    std::string normalized;
    for (const char symbol : word) {
        if (std::isalpha(symbol)) {
            normalized += std::tolower(symbol);
        }
    }
    return normalized;
}

FrequencyDictionary::FrequencyDictionary(const std::string& readFileInput) {

    std::ifstream file(readFileInput);

    if (file.is_open()) {
        readFile = readFileInput;
    } else {
        throw std::runtime_error("Не вдалося відкрити файл: " + readFileInput);
    }
}

std::string FrequencyDictionary::getReadFile() const { return readFile; }

void FrequencyDictionary::setReadFile(const std::string& readFileInput) {
    std::ifstream file(readFileInput);

    if (file.is_open()) {
        wordsCount.clear();
        readFile = readFileInput;
    } else {
        throw std::runtime_error("Не вдалося відкрити файл: " + readFileInput);
    }
}

void FrequencyDictionary::readFromFile() {
    std::ifstream file(readFile);

    if (!file.is_open()) {
        throw std::runtime_error("Не вдалося відкрити файл: " + readFile);
    }

    std::string word;

    while (file >> word) {
        std::string normalizedWord = normalizeWord(word);

        if (!normalizedWord.empty()) {
            wordsCount[normalizedWord]++;
        }
    }
}

void FrequencyDictionary::printAllWords() const {
    for (const auto &wordInfo : wordsCount) {
        std::cout << wordInfo.first << ": " << wordInfo.second << "; ";
    }
}

void FrequencyDictionary::printMostFrequent() const {

    if (wordsCount.empty()) {
        throw std::runtime_error("Не вдалося знайти найбільш частіше слово, бо map пуста");
    }

    int maxFrequency = 0;
    for (const auto &wordInfo : wordsCount) {
        if (maxFrequency < wordInfo.second) {
            maxFrequency = wordInfo.second;
        }
    }

    for (const auto &wordInfo : wordsCount) {
        if (wordInfo.second == maxFrequency) {
            std::cout << wordInfo.first << ": " << maxFrequency << "; ";
        }
    }
}

void FrequencyDictionary::saveResultToFile(const std::string& saveFileInput) {
    if (wordsCount.empty()) {
        throw std::runtime_error("Не вдалося зберегти результат, бо map пуста");
    }

    std::ofstream file(saveFileInput);

    if (!file.is_open()) {
        throw std::runtime_error("Не вдалося відкрити файл: " + saveFileInput);
    }

    for (const auto &wordInfo : wordsCount) {
        file << wordInfo.first << ' ' << wordInfo.second << '\n';
    }

    std::cout << "Результат словника успішно збережено!";
}
