/*
Завдання 2
Зарплата менеджера становить 200$ + відсоток від продажів (продажі до 500$ — 3%, від 500 до 1000 — 5%, понад 1000 — 8%).
Користувач вводить із клавіатури рівень продажів для трьох менеджерів. Визначити їхню зарплату, визначити найкращого менеджера,
нарахувати йому премію 200$, вивести підсумки на екран.
*/

#include <iostream>
#include <string>

int main() {
    short salary = 200;
    std::string nameFirstManagerConsole = "Перший мененджер";
    std::string nameSecondManagerConsole = "Другий мененджер";
    std::string nameThirdManagerConsole = "Третій мененджер";
    float resultFirstManager;
    float resultSecondManager;
    float resultThirdManager;
    float salesFirstManager;
    float salesSecondManager;
    float salesThirdManager;

    std::cout << "Введіть рівень продажів першого мененджера: ";
    std::cin >> salesFirstManager;
    std::cout << "Введіть рівень продажів другого мененджера: ";
    std::cin >> salesSecondManager;
    std::cout << "Введіть рівень продажів третього мененджера: ";
    std::cin >> salesThirdManager;

    //Перший мененджер:
    if (salesFirstManager < 500)
        resultFirstManager = salary + (salesFirstManager / 100 * 3);
    else if (salesFirstManager <= 1000)
        resultFirstManager = salary + (salesFirstManager / 100 * 5);
    else
        resultFirstManager = salary + (salesFirstManager / 100 * 8);

    //Другий мененджер:
    if (salesSecondManager < 500)
        resultSecondManager = salary + (salesSecondManager / 100 * 3);
    else if (salesSecondManager <= 1000)
        resultSecondManager = salary + (salesSecondManager / 100 * 5);
    else
        resultSecondManager = salary + (salesSecondManager / 100 * 8);

    //Третій мененджер:
    if (salesThirdManager < 500)
        resultThirdManager = salary + (salesThirdManager / 100 * 3);
    else if (salesThirdManager <= 1000)
        resultThirdManager = salary + (salesThirdManager / 100 * 5);
    else
        resultThirdManager = salary + (salesThirdManager / 100 * 8);

    //Находимо найбільше число (для нічиї):
    float maxResult = resultFirstManager;
    if (maxResult < resultSecondManager)
        maxResult = resultSecondManager;
    if (maxResult < resultThirdManager)
        maxResult = resultThirdManager;


    //Якщо перший мененджер найкращий:
    if (resultFirstManager == maxResult) {
        nameFirstManagerConsole += " (найркащий)";
        resultFirstManager += 200;
    }
    //Якщо другий мененджер найкращий:
    if (resultSecondManager == maxResult) {
        nameSecondManagerConsole += " (найркащий)";
        resultSecondManager += 200;
    }
    //Якщо третій мененджер найкращий:
    if (resultThirdManager == maxResult) {
        nameThirdManagerConsole += " (найркащий)";
        resultThirdManager += 200;
    }

    //Виводимо результати ._. :
    std::cout << nameFirstManagerConsole << ": " << resultFirstManager << "$" << std::endl << nameSecondManagerConsole << ": " << resultSecondManager << "$" << std::endl << nameThirdManagerConsole << ": " << resultThirdManager << "$" << std::endl;
}