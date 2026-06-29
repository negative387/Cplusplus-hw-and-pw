/*
Завдання 4: Система коментарів (масив структур + пошук + сортування)

Завдання: створіть Comments.cpp і реалізуйте:

1. Оголосіть структуру Comment { std::string author; std::string text; std::string timestamp; int likes; }.
2. Ініціалізуйте масив із 6 коментарів (різні автори, тексти, час у форматі "2026-01-15 14:30", різна кількість лайків).
3. Реалізуйте функції:
- void printComment(const Comment& comment) — друк одного коментаря.
- void printAll(const Comment* arr, int size) — друк усіх коментарів із номером.
- const Comment* findByAuthor(const Comment* arr, int size, const std::string& author) — лінійний пошук; повертає перший коментар автора або nullptr.
- int indexOfMostLiked(const Comment* arr, int size) — індекс коментаря з максимальною кількістю лайків (або -1, якщо порожній).
- void sortByLikesDesc(Comment* arr, int size) — сортування за лайками за спаданням (через std::swap).
- int countByAuthor(const Comment* arr, int size, const std::string& author) — кількість коментарів автора.
4. У main() продемонструйте:
- друк усіх коментарів;
- пошук за автором, який існує, і за автором, якого немає;
- визначення найпопулярнішого коментаря;
- підрахунок кількості коментарів конкретного автора;
- сортування за лайками та повторний друк.


Питання:
1. Чому Comment — це Record (усі поля публічні, без методів), а не клас?
2. Чому findByAuthor повертає const Comment*, а countByAuthor — int?
3. Чому при сортуванні через std::swap усі поля коментаря (автор, текст, час, лайки) рухаються разом?
4. Як додати поле bool edited (редагований коментар) без зміни логіки сортування?

✅
1 - Бо структурі Comment не потрібно складна логіка
2 - findByAuthor повертає вказівник на цілий об'єкт, а countByAuthor тільки кількість коментарів
3 - Для std::swap структура це одне ціле і тому може міняти всі її поля одночасно.
4 - Просто дописати bool edited; у struct Comment. Функція сортування не буде порівнювати її, але swap буде працювати.
❌
*/


#include <iostream>
#include <string>

struct Comment {
    std::string author;
    std::string text;
    std::string timestamp;
    int likes;
};

void printComment(const Comment& comment);
void printAll(const Comment* arr, int size);
const Comment* findByAuthor(const Comment* arr, int size, const std::string& author);
int indexOfMostLiked(const Comment* arr, int size);
void sortByLikesDesc(Comment* arr, int size);
int countByAuthor(const Comment* arr, int size, const std::string& author);


int main() {

    const int SIZE = 6;
    Comment arrayComments[SIZE] = {

        {"Олена", "текст01...", "2026-01-15 14:30", 12},
        {"Борис", "текст02...", "2026-01-15 15:36", 9},
        {"Віктор", "текст03...", "2026-01-15 15:59", 15},
        {"Аліна", "текст04...", "2026-01-15 17:02", 6},
        {"Тетяна", "текст05...", "2026-01-16 12:37", 10},
        {"Олена", "текст06...", "2026-01-16 13:48", 3},
    };

    std::cout << "\n=== Один коментарій ===\n";
    printComment(arrayComments[0]);


    std::cout << "\n=== Усі коментарі ===\n";
    printAll(arrayComments, SIZE);


    std::cout << "\n=== Пошук за автором \"Тетяна\" ===\n";
    const Comment* findAuthor = findByAuthor(arrayComments, SIZE, "Тетяна");
    if (findAuthor)
        std::cout << '[' << findAuthor->timestamp << "] " << findAuthor->author << ": " << findAuthor->text << " (лайків: " << findAuthor->likes << ")\n";
    else
        std::cout << "Не знайдено\n";


    std::cout << "\n=== Пошук за автором \"Іван\" ===\n";
    const Comment* noFindAuthor = findByAuthor(arrayComments, SIZE, "Іван");
    if (noFindAuthor)
        std::cout << '[' << noFindAuthor->timestamp << "] " << noFindAuthor->author << ": " << noFindAuthor->text << " (лайків: " << noFindAuthor->likes << ")\n";
    else
        std::cout << "Не знайдено\n";


    std::cout << "\n=== Кількість коментарів Олени ===\n";
    std::cout << "Олена має " << countByAuthor(arrayComments, SIZE, "Олена") << " коментарі\n";


    std::cout << "\n=== Найпопулярніший коментар ===\n";
    int mostLikedIndex = indexOfMostLiked(arrayComments, SIZE);
    if (mostLikedIndex != -1)
        std::cout << '[' << arrayComments[mostLikedIndex].timestamp << "] " << arrayComments[mostLikedIndex].author << ": " << arrayComments[mostLikedIndex].text << " (лайків: " << arrayComments[mostLikedIndex].likes << ")\n";
    else
        std::cout << "Масив пустий\n";


    std::cout << "\n=== Після сортування за лайками (спадання) ===\n";
    sortByLikesDesc(arrayComments, SIZE);
    printAll(arrayComments, SIZE);


    return 0;
}


void printComment(const Comment& comment) {

    std::cout << '[' << comment.timestamp << "] " << comment.author << ": " << comment.text << " (лайків: " << comment.likes << ")\n";
}

void printAll(const Comment* arr, int size) {

    for (int index = 0; index < size; ++index)
        std::cout << index + 1 << ". [" << arr[index].timestamp << "] " << arr[index].author << ": " << arr[index].text << " (лайків: " << arr[index].likes << ")\n";
}

const Comment* findByAuthor(const Comment* arr, int size, const std::string& author) {

    for (int index = 0; index < size; ++index) {

        if (arr[index].author == author)
            return &arr[index];
    }
    return nullptr;
}

int indexOfMostLiked(const Comment* arr, int size) {

    if (size <= 0 || arr == nullptr) { return -1; }

    int mostLiked = 0;
    for (int index = 1; index < size; ++index) {

        if (arr[index].likes > arr[mostLiked].likes)
            mostLiked = index;
    }
    return mostLiked;
}

void sortByLikesDesc(Comment* arr, int size) {

    int likesMaxIndex;

    for (int index = 0; index < size - 1; ++index) {

        likesMaxIndex = index;

        for (int indexTwo = index + 1; indexTwo < size; ++indexTwo) {

            if (arr[indexTwo].likes > arr[likesMaxIndex].likes)
                likesMaxIndex = indexTwo;
        }
        std::swap(arr[likesMaxIndex], arr[index]);
    }
}

int countByAuthor(const Comment* arr, int size, const std::string& author) {

    int countCommentsAuthor = 0;

    for (int index = 0; index < size; ++index) {

        if (arr[index].author == author)
            ++countCommentsAuthor;
    }
    return countCommentsAuthor;
}