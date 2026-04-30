/*
Завдання 1: Резервування каналів (Посилання &) Напишіть функцію swapPorts, яка приймає два порти
(основний та резервний) і міняє їхні значення місцями. Використовуйте посилання, щоб функція
змінила оригінальні змінні.
*/

#include <iostream>

void swapPorts(int &main, int &backup);

int main() {
    int mainPort = 80;
    int backupPort = 8080;

    std::cout << "mainPort до: " << mainPort << " " << "backupPort до: " << backupPort << std::endl;

    swapPorts(mainPort, backupPort);

    std::cout << "mainPort після: " << mainPort << " " << "backupPort після: " << backupPort << std::endl;
    return 0;
}

void swapPorts(int &main, int &backup) {
    int temp = main;
    main = backup;
    backup = temp;
}