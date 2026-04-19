/*
Рівень 3: Архітектура та Злам (Краш-тести та Безпека)
Фокус: Розуміння того, як ламається компілятор та захист від падінь.

2. «Захисник пам'яті» (Робота з nullptr): Напишіть функцію SafeUpdate,
яка приймає вказівник на int та нове цілочисельне значення. Функція повинна
спочатку перевірити, чи не є вказівник порожнім (nullptr).

- Якщо він порожній — вивести червоне повідомлення про помилку "Увага:
спроба запису в нікуди!".
- Якщо дійсний — оновити значення за вказівником. У main протестуйте обидва
сценарії: викличте функцію, передавши їй реальну адресу змінної, і викличте
її знову, передавши їй явно nullptr.
*/

#include <iostream>

void safeUpdate(int *numberOld, int numberNew);

int main() {
    int numberOld = 5;
    int *ghost = nullptr;

    safeUpdate(&numberOld, 20);
    safeUpdate(ghost, 20);

    return 0;
}

void safeUpdate(int *numberOld, int numberNew) {
    if (!numberOld) {
        std::cout << "\033[31mУвага:спроба запису в нікуди!\033[0m" << std::endl;
        return;
    }
    *numberOld = numberNew;
    std::cout << "\033[32mУспішно!\033[0m" << std::endl;
}