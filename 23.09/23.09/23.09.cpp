#include <iostream>
#include <cmath>
#include <locale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    //задание 1
    int a, b, c;
    cout << "Введите три стороны треугольника: ";
    cin >> a >> b >> c;

    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "Не треугольник";
    }
    else if (a == b && b == c) {
        cout << "Равносторонний";
    }
    else if (a == b || a == c || b == c) {
        cout << "Равнобедренный";
    }
    else {
        cout << "Разносторонний";
    }

    cout << endl;

    //Задание 2
    double x, y, z;
    cout << "Введите коэффициенты a, b, c: ";
    cin >> x >> y >> z;

    double D = y * y - 4 * x * z;

    if (D > 0) {
        double root1 = (-y + sqrt(D)) / (2 * x);
        double root2 = (-y - sqrt(D)) / (2 * x);
        cout << root1 << " " << root2;
    }
    else if (D == 0) {
        double root = -y / (2 * x);
        cout << root;
    }
    else {
        cout << "Нет действительных корней";
    }

    cout << endl;

    //Задание 3
    int month, day;
    cout << "Введите месяц и день: ";
    cin >> month >> day;

    if (month == 12 || month < 3) cout << "Зима";
    else if (month < 6) cout << "Весна";
    else if (month < 9) cout << "Лето";
    else cout << "Осень";

    bool last = false;
    if (month == 2 && day == 28) last = true;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30) last = true;
    else if (day == 31) last = true;

    if (last) cout << ". Последний день месяца.";
    else cout << ". Не последний день месяца.";

    return 0;
}