#pragma once
#include <iostream>
#include <map>
#include <fstream>

class FrequencyDictionary {
private:
    std::map<std::string, int> wordsCount;
    std::string readFile = "Undefined";

    std::string normalizeWord(const std::string &word);

public:
    FrequencyDictionary(const std::string &readFileInput);

    std::string getReadFile() const;

    void setReadFile(const std::string &readFileInput);

    void readFromFile();

    void printAllWords() const;

    void printMostFrequent() const;

    void saveResultToFile(const std::string &saveFileInput);
};