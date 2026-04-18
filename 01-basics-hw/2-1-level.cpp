/*
Рівень 2: Логіка та Обробка даних (Алгоритми)
Фокус: Математичні операції та послідовність дій.

1. "Середній бал": Програма запитує у студента оцінки за три різні предмети (математика, фізика, програмування).
Потрібно обчислити середнє арифметичне цих оцінок і вивести результат. Підказка: зверніть увагу на дійсний тип даних
(double/float).
*/



#include <iostream>

int main() {
    short mathGrade;
    short physicsGrade;
    short programGrade;

    std::cout << "Введіть оцінку по математиці:";
    std::cin >> mathGrade;
    std::cout << "Введіть оцінку по фізиці:";
    std::cin >> physicsGrade;
    std::cout << "Введіть оцінку по програмуванню:";
    std::cin >> programGrade;

    //Зробив short, бо хотів ціле число після ділення:
    short averageGrade = (mathGrade + physicsGrade + programGrade) / 3;
    std::cout << "Ваша середня арифметична оцінка: " << averageGrade;
}