/*
Рівень 2: Логіка та Обробка даних (Алгоритми)
Фокус: Математичні операції та послідовність дій.

2. "Обмін валют 2.0": Користувач вводить суму в гривнях та актуальний курс долара. Програма має вирахувати,
скільки доларів отримає користувач, але з урахуванням комісії банку (наприклад, фіксовано 10 грн за операцію).
*/



#include <iostream>

int main() {
    short commissionBank = 10;

    float grivnyi;
    float dollarRate;

    std::cout << "Введіть сумму гривень: ";
    std::cin >> grivnyi;
    std::cout << "Введіть курс долара: ";
    std::cin >> dollarRate;

    float resultDollars = grivnyi / dollarRate;
    float resultPay = grivnyi + commissionBank;

    std::cout << "Ви отримуєте: " << resultDollars << '$' << std::endl;
    //Спочатку написав '₴', але побачивши якісь странні цифри у терміналі змінив на "₴":
    std::cout << "Сплата з комісією: " << resultPay << "₴";
}