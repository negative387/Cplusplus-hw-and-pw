#include <iostream>
#include <fstream>
#include "FrequencyDictionary.h"

/*
Завдання:
Написати програму формування частотного словника появи окремих слів в деякому тексті. Забезпечити:
1. Читання вхідного тексту з файлу
2. Виведення інформації про всі слова
3. Виведення інформації про найбільш часто вживане слово
4. Запис результату в файл
Під час розробки програми використовувати словник типу map.
*/

int main() {

    try {
        std::string textInput;
        std::cout << "Введіть текст для тесту словника ( ТІЛЬКИ ЛАТИНИЦЯ =( ): ";
        std::getline(std::cin, textInput);

        std::ofstream fileWords("words.txt");
        fileWords << textInput;
        fileWords.close();

        FrequencyDictionary test("words.txt");

        test.readFromFile();

        //Виводимо результати в консоль:
        std::cout << "Всі слова: \n";
        test.printAllWords();
        std::cout << "\n\nНайчастіше слово: \n";
        test.printMostFrequent();
        std::cout << '\n';

        //Зберігаємо в новий файл:
        test.saveResultToFile("save.txt");

    } catch (const std::exception &exception) {
        std::cout << "Сталася помилка: " << exception.what() << '\n';
        return 1;
    }

    return 0;
}