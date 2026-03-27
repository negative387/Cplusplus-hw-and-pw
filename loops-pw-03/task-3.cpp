/**
Завдання 3
Користувач вводить дві межі діапазону. Порахувати суму всіх чисел діапазону
**/

#include <iostream>

int main() {

    int userStartNumber;
    int userFinishNumber;
    int sumNumber = 0;

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

    //Сума всього діапазона:
    for (int count = userStartNumber; count <= userFinishNumber; ++count) {
        sumNumber += count;
    }
    std::cout << "Сума всіх чисел діапазона: " << sumNumber;
}