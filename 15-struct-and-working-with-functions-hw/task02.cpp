/*
Завдання 2: Доступ до полів та оператори . та ->

Завдання: допишіть тіла функцій позначених // TODO.
*/

#include <iostream>
#include <cmath>

struct Point2D
{
    double x;
    double y;
};

void printPoint(const char* label, const Point2D& p);
void movePoint(Point2D& p, double dx, double dy);
double distanceTo(const Point2D& a, const Point2D& b);
Point2D normalize(const Point2D& p);

int main()
{
    Point2D origin { 0.0, 0.0 };
    Point2D point  { 3.0, 4.0 };

    printPoint("Оригінал", point);

    // Доступ через посилання
    Point2D& pointRef = point;
    pointRef.x = 5.0;
    printPoint("Після зміни через посилання", point);

    // Доступ через вказівник
    Point2D* originPtr = &origin;
    originPtr->x = 1.0;
    originPtr->y = 2.0;
    printPoint("Origin через вказівник", origin);

    // Мутація через функцію
    movePoint(point, -2.0, 1.0);
    printPoint("Після movePoint", point);

    std::cout << "Відстань від origin до point: "
              << distanceTo(origin, point) << "\n";

    // Нормалізація
    Point2D normalizedPoint = normalize(point);
    printPoint("Нормалізована", normalizedPoint);
    std::cout << "Довжина після нормалізації: " << distanceTo(normalizedPoint, { 0.0, 0.0 }) << "\n";

    return 0;
}

void printPoint(const char* label, const Point2D& p)
{
    std::cout << label << ": (" << p.x << ", " << p.y << ")\n";
}

// TODO: змінює координати точки на dx, dy (мутує оригінал)
void movePoint(Point2D& p, double dx, double dy)
{
    p.x += dx;
    p.y += dy;
}

// TODO: повертає евклідову відстань між двома точками
// Формула: sqrt((x2-x1)^2 + (y2-y1)^2)
double distanceTo(const Point2D& a, const Point2D& b)
{
    return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
}

// TODO: повертає нову точку, поділену на magnitude (нормалізація вектора)
// magnitude = sqrt(x^2 + y^2)
// Якщо magnitude == 0 — повернути оригінал
Point2D normalize(const Point2D& p)
{
    double magnitude = std::sqrt(p.x * p.x + p.y * p.y);

    if (magnitude == 0)
        return p;

    return { p.x / magnitude,p.y / magnitude };
}

/*
Очікуваний вивід:

Оригінал: (3, 4)
Після зміни через посилання: (5, 4)
Origin через вказівник: (1, 2)
Після movePoint: (3, 5)
Відстань від origin до point: 3.60555
Нормалізована: (0.6, 1)
Довжина після нормалізації: 1

Питання:
1 - Чому originPtr->x та (*originPtr).x — це одне і те саме? Який із записів кращий і чому?
2 - Що станеться, якщо originPtr буде nullptr, а ми викличемо originPtr->x?
3 - Чому функція printPoint приймає const Point2D&, а movePoint — просто Point2D&?

✅
1 - Бо "->" це скорочення (*originPtr). Краще "->", бо вона зручна.
2 - Буде невизначена поведінка.
3 - Бо printPoint потрібно лише читати а movePoint потрібно змінювати.
❌
*/