#include <iostream>
#include <stack>

/*
Завдання:
Є рядок символів, ознакою кінця, якого є «;» . У рядку можуть бути фігурні, круглі, квадратні дужки. Дужки можуть
бути відкриваючими і закриваючими. Необхідно перевірити коректність розташування дужок. При цьому необхідно, щоб
виконувалися наступні правила:

1. Кожна відкриваюча дужка повинна мати справа таку ж закриваючу. Зворотне правило також має працювати.
2. Відкриваюча і закриваюча пари дужок різних типів повинні бути правильно розташовані відносно один до одного.

- Приклад правильного рядка: ({x-y-z} * [x + 2y] - (z + 4x)).
- Приклад неправильного рядка: ([x-y-z} * [x + 2y) - {z + 4x)].

Якщо всі правила дотримані виведіть інформаційне повідомлення про коректність рядка, інакше — покажіть рядок до
місця виникнення першої помилки.
*/

std::string isCorrectParentheses(const std::string &text) {

    std::stack<char> parentheses;
    std::string checkText = "";

    for (const char &symbol : text) {

        if (symbol == ';') {
            break;
        }

        if (symbol == '(' || symbol == '{' || symbol == '[') {
            parentheses.push(symbol);
        }

        else if (symbol == ')' || symbol == '}' || symbol == ']') {

            if (parentheses.empty()) {
                return  "Помилка! (зайва закриваюча скобка): \"" + checkText + "\" -> " + symbol + " <-";
            }

            char topParenthesis = parentheses.top();
            parentheses.pop();

            if ((topParenthesis != '(' && symbol == ')') ||
                (topParenthesis != '{' && symbol == '}') ||
                (topParenthesis != '[' && symbol == ']')) {
                return "Помилка! (неправильний тип скобки): \"" + checkText + "\" -> " + symbol + " <-";
            }
        }
        checkText += symbol;
    }

    if (!parentheses.empty()) {
        return "Помилка! (не всі скобки закриті): \"" + checkText + '\"';
    }

    return "Дужки коректні!";
}

int main() {

    std::cout << "Приклад правильного рядка:\n"
              << "\"({x-y-z} * [x + 2y] - (z + 4x))\": "
              << isCorrectParentheses("({x-y-z} * [x + 2y] - (z + 4x))");

    std::cout << "\nПриклад неправильного рядка:\n"
              << "\"([x-y-z} * [x + 2y) - {z + 4x)]\": "
              << isCorrectParentheses("([x-y-z} * [x + 2y) - {z + 4x)]");

    return 0;
}