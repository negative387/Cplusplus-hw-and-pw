/*
Завдання 8. Створіть enum class FilePermission з прапорцями: Read = 1, Write = 2, Execute = 4. Напишіть функцію
checkPermission(int mask, FilePermission p), яка перевіряє, чи є відповідний дозвіл у масці (використовуючи бітові операції &).
*/

#include <iostream>

enum class FilePermission { Read = 1, Write = 2, Execute = 4 };

void checkPermission(int mask, FilePermission p);


int main() {

    FilePermission p = FilePermission::Execute;

    std::cout << "mask = 2 : ";
    checkPermission(2, p);
    std::cout << std::endl;

    std::cout << "mask = 4 : ";
    checkPermission(4, p);
    std::cout << std::endl;

    return 0;
}


void checkPermission(int mask, FilePermission p) {

    if (mask & static_cast<int>(p))
        std::cout << "Дозволено";
    else
        std::cout << "Не дозволено";
}
