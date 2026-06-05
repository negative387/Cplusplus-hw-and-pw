/*
Завдання 4: Власні рядкові функції — без <cstring>
Реалізуйте базові рядкові операції вручну, не використовуючи функції з <cstring>. Це навчить вас розуміти, як ці
функції насправді влаштовані.

Вимоги до програми:
1. Реалізуйте функцію int my_strlen(const char* s) — повертає довжину рядка (кількість символів до '\0').
2. Реалізуйте функцію void my_strcpy(char* dst, const char* src, int dst_size) — безпечне копіювання: копіює не
більше dst_size - 1 символів і завжди додає '\0'.
3. Реалізуйте функцію int my_strcmp(const char* a, const char* b) — лексикографічне порівняння: повертає < 0, 0 або > 0.
4. Реалізуйте функцію void my_toupper(char* s) — перетворює всі малі латинські літери на великі (не використовуючи <cctype>).

У main():
- Протестуйте кожну функцію на кількох прикладах.
- Порівняйте результати з відповідними функціями зі <cstring> та <cctype> (виведіть обидва результати поруч).
- Покажіть, що my_strcpy не переповнює буфер: спробуйте скопіювати рядок "Hello, World!" у буфер розміром 6.
*/

#include <iostream>
#include <cstring>
#include <cctype>

int my_strlen(const char* s);

void my_strcpy(char* dst, const char* src, int dst_size);

int my_strcmp(const char* a, const char* b);

void my_toupper(char* s);

int main()
{
    // Тест my_strlen
    std::cout << "=== my_strlen ===" << std::endl ;

    std::cout << "my_strlen(\"Hello\")  = " << my_strlen("Hello")  << std::endl;
    std::cout << "strlen(\"Hello\")     = " << std::strlen("Hello") << std::endl;

    // Тест my_strcpy
    std::cout << std::endl << "=== my_strcpy ===" << std::endl;

    char buf[6];
    char testStrcpy[6];

    my_strcpy(buf, "Hello, World!", sizeof(buf));
    std::cout << "Скопійовано у buf[6]: \"" << buf << "\"" << std::endl;

      // -Як я поняв якщо написати "Hello, World!" з розміром 6 то буде undefined behavior:
    std::strcpy(testStrcpy, "Hello");
    std::cout << "Перевірка з cstring: " << '"' << testStrcpy << '"' << std::endl;

    // Тест my_strcmp
    std::cout << std::endl << "=== my_strcmp ===" << std::endl;
    std::cout << "my_strcmp(\"abc\", \"abc\") = " << my_strcmp("abc", "abc") << std::endl;
    std::cout << "my_strcmp(\"abc\", \"abd\") = " << my_strcmp("abc", "abd") << std::endl;
    std::cout << "my_strcmp(\"abd\", \"abc\") = " << my_strcmp("abd", "abc") << std::endl;

    std::cout << "strcmp(\"abc\", \"abc\") = " << strcmp("abc", "abc") << std::endl;
    std::cout << "strcmp(\"abc\", \"abd\") = " << strcmp("abc", "abd") << std::endl;
    std::cout << "strcmp(\"abd\", \"abc\") = " << strcmp("abd", "abc") << std::endl;

    // Тест my_toupper
    std::cout << std::endl << "=== my_toupper ===" << std::endl;
    char word[] = "hello, world!";
    my_toupper(word);
    std::cout << "Після my_toupper: " << word << std::endl;

      // -Цей код я взяв з гугла по звісним причинам :)
    char testToupper[] = "hello, world!";

    for (int index = 0; testToupper[index] != '\0'; ++index) {
        testToupper[index] = static_cast<char>(std::toupper(static_cast<unsigned char>(testToupper[index])));
    }
    std::cout << "Після toupper: " << testToupper << std::endl;

    return 0;
}


int my_strlen(const char* s) {
    // -На ютубі побачив що можна з поінтерами набагато простіше зробити:
     const char *pointer = s;

    while (*pointer != '\0') {
        ++pointer;
    }
    return pointer - s;
}

void my_strcpy(char* dst, const char* src, int dst_size) {

    int index = 0;

    while (index < dst_size - 1 && src[index] != '\0') {
        dst[index] = src[index];
        ++index;
    }
    dst[index] = '\0';
}

int my_strcmp(const char* a, const char* b) {

    while (*a != '\0' && *a == *b) {
        ++a;
        ++b;
    }
    return *a - *b;
}

void my_toupper(char* s) {

    while (*s != '\0') {
        if (*s >= 'a' && *s <= 'z') {
            *s -= ('a' - 'A');
        }
        ++s;
    }
}