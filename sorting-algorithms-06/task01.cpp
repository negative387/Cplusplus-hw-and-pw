/*
Завдання 1
Написати програму "довідник". Створити два одновимірні масиви. Один масив зберігає номери мобільних телефонів,
другий — домашні телефонні номери. Реалізувати меню для користувача:
- Відсортувати за номерами мобільних;
- Відсортувати за домашніми номерами телефонів;
- Вивести список користувачів;
- Вихід.
*/

#include <iostream>
#include <string>

int main() {
    const int SIZE = 5;

    std::string users[SIZE] = {"John Pork","Yasha Lava", "Winston Churchill", "Kim Jong-un", "Jeffrey Epstein"};
    int phoneNumber[SIZE] = {440881624, 177746333, 851943855, 767236626, 999261551};
    int homePhoneNumber[SIZE] = {442354111, 437220012, 322975911, 577001520, 567446233};
    int choiceArray[SIZE];
    int choiceNumber;

    do {
        std::cout << std::endl << "1 - Відсортувати за номерами мобільних" << std::endl << "2 - Відсортувати за домашніми номерами телефонів" << std::endl << "3 - Вивести список користувачів" << std::endl << "4 - Вихід" << std::endl << "Введіть цифру:";
        std::cin >> choiceNumber;

        //Відсортовування номерів (1 | 2):
        if (choiceNumber > 0 && choiceNumber < 3) {

            if (choiceNumber == 1) {
                for (int countOne = 0; countOne < SIZE; ++countOne)
                    choiceArray[countOne] = phoneNumber[countOne];
            }
            else {
                for (int countOne = 0; countOne < SIZE; ++countOne)
                    choiceArray[countOne] = homePhoneNumber[countOne];
            }

            for (int step = 1; step < SIZE; ++step) {
                int key = choiceArray[step];
                int index = step - 1;

                while (index >= 0 && choiceArray[index] > key) {
                    choiceArray[index + 1] = choiceArray[index];
                    --index;
                }
                choiceArray[index + 1] = key;
            }

            for (int countTwo = 0; countTwo < SIZE; ++countTwo)
                std::cout << "+380" << choiceArray[countTwo] << std::endl;
        }

        //Вивести користувачів (3):
        else if (choiceNumber == 3) {
            for (int countName = 0; countName < SIZE; ++countName)
                std::cout << users[countName] << std::endl;
        }

        //Помилка:
        else if (choiceNumber < 1 || choiceNumber > 4)
            std::cout << "Ви ввели неправильну цифру!" << std::endl;
    }
    while (choiceNumber != 4);
    std::cout << "До побачення!";

    return 0;
}