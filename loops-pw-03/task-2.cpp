/**
Завдання 2
Користувач вводить дві межі діапазону. Вивести на екран усі числа з цього діапазону. Передбачити, щоб
користувач міг вводити межі діапазону в довільному порядку.
- Вивести всі парні числа з діапазону.
- Вивести всі непарні числа з діапазону.
- Вивести всі числа, кратні семи.
**/

#include <iostream>

int main() {
    int userStartNumber;
    int userFinishNumber;

    std::cout << "Введіть початкове число:";
    std::cin >> userStartNumber;
    std::cout << "Введіть фінальне число:";
    std::cin >> userFinishNumber;

    //Перевірка на правильний порядок:
    if (userStartNumber > userFinishNumber) {
        int temporaryStartNumber = userStartNumber;
        userStartNumber = userFinishNumber;
        userFinishNumber = temporaryStartNumber;
    }

    //Виводимо усі числа діапазону:
    std::cout << "Усі числа діапазону: " << std::endl;
    for (int count = userStartNumber; count <= userFinishNumber; ++count)
            std::cout << count << " ";
    std::cout << std::endl;

    //Виводимо парні числа діапазону:
    std::cout << "Парні числа діапазону: " << std::endl;
    for (int numberEven = userStartNumber; numberEven <= userFinishNumber; ++numberEven) {
        if (numberEven % 2 == 0)
            std::cout << numberEven << " ";
    }
    std::cout << std::endl;

    //Виводимо непарні числа діапазону:
    std::cout << "Непарні числа діапазону: " << std::endl;
    for (int numberOdd = userStartNumber; numberOdd <= userFinishNumber; ++numberOdd) {
        if (numberOdd % 2 != 0)
            std::cout << numberOdd << " ";
    }
    std::cout << std::endl;

    //Виводимо кратні 7 числа діапазону:
    std::cout << "Кратні 7 числа діапазону: " << std::endl;
    for (int numberMultipleSeven = userStartNumber; numberMultipleSeven <= userFinishNumber; ++numberMultipleSeven) {
        if (numberMultipleSeven % 7 == 0)
            std::cout << numberMultipleSeven << " ";
    }
}
