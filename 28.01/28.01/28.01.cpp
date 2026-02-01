#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Задание 1: ПРЯМОУГОЛЬНИК

struct Rectangle {
    double x, y;       // координаты верхнего левого угла
    double width;      // ширина
    double height;     // высота
};

// Функция перемещения прямоугольника
void moveRect(Rectangle& r, double dx, double dy) {
    r.x += dx;
    r.y += dy;
    cout << "Перемещено на (" << dx << ", " << dy << ")\n";
}

// Функция изменения размера
void resizeRect(Rectangle& r, double newWidth, double newHeight) {
    r.width = newWidth;
    r.height = newHeight;
    cout << "Размер изменен: " << newWidth << "x" << newHeight << "\n";
}

// Функция печати прямоугольника
void printRect(const Rectangle& r) {
    cout << "Прямоугольник:\n";
    cout << "  X: " << r.x << ", Y: " << r.y << "\n";
    cout << "  Ширина: " << r.width << ", Высота: " << r.height << "\n";
    cout << "  Правый нижний: (" << r.x + r.width << ", " << r.y + r.height << ")\n";
}

void task1() {
    cout << "\nЗАДАНИЕ 1: ПРЯМОУГОЛЬНИК\n";

    Rectangle r;
    cout << "Введите координаты верхнего левого угла (x y): ";
    cin >> r.x >> r.y;
    cout << "Введите ширину и высоту: ";
    cin >> r.width >> r.height;

    printRect(r);

    double dx, dy;
    cout << "\nВведите смещение для перемещения (dx dy): ";
    cin >> dx >> dy;
    moveRect(r, dx, dy);
    printRect(r);

    double newW, newH;
    cout << "\nВведите новую ширину и высоту: ";
    cin >> newW >> newH;
    resizeRect(r, newW, newH);
    printRect(r);
}

// Задание 2: ТОЧКА

struct Point {
    double x, y;
};

// Функция вычисления расстояния между точками
double distancePoints(const Point& p1, const Point& p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

void task2() {
    cout << "\nЗАДАНИЕ 2: РАССТОЯНИЕ МЕЖДУ ТОЧКАМИ\n";

    Point p1, p2;
    cout << "Введите координаты первой точки (x y): ";
    cin >> p1.x >> p1.y;
    cout << "Введите координаты второй точки (x y): ";
    cin >> p2.x >> p2.y;

    double dist = distancePoints(p1, p2);
    cout << "Расстояние между точками: " << dist << "\n";
}

// ЗАДАНИЕ 3: ДРОБЬ

// Функция для нахождения наибольшего общего делителя
int findGCD(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct Fraction {
    int num;   // числитель
    int den;   // знаменатель

    // Сокращение дроби
    void simplify() {
        int gcd = findGCD(num, den);
        num /= gcd;
        den /= gcd;
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }
};

// Функции для операций с дробями
Fraction addFrac(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.num = a.num * b.den + b.num * a.den;
    result.den = a.den * b.den;
    result.simplify();
    return result;
}

Fraction subFrac(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.num = a.num * b.den - b.num * a.den;
    result.den = a.den * b.den;
    result.simplify();
    return result;
}

Fraction mulFrac(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.num = a.num * b.num;
    result.den = a.den * b.den;
    result.simplify();
    return result;
}

Fraction divFrac(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.num = a.num * b.den;
    result.den = a.den * b.num;
    result.simplify();
    return result;
}

// Функция для вывода дроби в правильном виде
void printFraction(const Fraction& f) {
    if (f.den == 1) {
        cout << f.num;
    }
    else if (abs(f.num) > f.den) {
        int whole = f.num / f.den;
        int remainder = abs(f.num) % f.den;
        if (whole != 0) {
            cout << whole << " ";
        }
        if (remainder != 0) {
            cout << remainder << "/" << f.den;
        }
    }
    else {
        cout << f.num << "/" << f.den;
    }
}

void task3() {
    cout << "\nЗАДАНИЕ 3: ОПЕРАЦИИ С ДРОБЯМИ\n";

    Fraction f1, f2;

    cout << "Введите первую дробь (числитель и знаменатель): ";
    cin >> f1.num >> f1.den;
    if (f1.den == 0) {
        cout << "Ошибка: знаменатель не может быть 0!\n";
        return;
    }

    cout << "Введите вторую дробь (числитель и знаменатель): ";
    cin >> f2.num >> f2.den;
    if (f2.den == 0) {
        cout << "Ошибка: знаменатель не может быть 0!\n";
        return;
    }

    f1.simplify();
    f2.simplify();

    cout << "\nПервая дробь (сокращенная): ";
    printFraction(f1);
    cout << "\nВторая дробь (сокращенная): ";
    printFraction(f2);

    cout << "\n\nРезультаты операций:\n";

    cout << "Сумма: ";
    printFraction(f1);
    cout << " + ";
    printFraction(f2);
    cout << " = ";
    Fraction sum = addFrac(f1, f2);
    printFraction(sum);
    cout << "\n";

    cout << "Разность: ";
    printFraction(f1);
    cout << " - ";
    printFraction(f2);
    cout << " = ";
    Fraction diff = subFrac(f1, f2);
    printFraction(diff);
    cout << "\n";

    cout << "Произведение: ";
    printFraction(f1);
    cout << " * ";
    printFraction(f2);
    cout << " = ";
    Fraction prod = mulFrac(f1, f2);
    printFraction(prod);
    cout << "\n";

    if (f2.num != 0) {
        cout << "Деление: ";
        printFraction(f1);
        cout << " / ";
        printFraction(f2);
        cout << " = ";
        Fraction quot = divFrac(f1, f2);
        printFraction(quot);
        cout << "\n";
    }
    else {
        cout << "Деление на 0 невозможно!\n";
    }
}


int main() {
    setlocale(LC_ALL, "RU");

    // Задание 1
    task1();

    // Задание 2  
    task2();

    // Задание 3
    task3();


    return 0;
}