#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    // задание 1: Сумма чисел от a до 500
    cout << "задание 1: Сумма чисел от a до 500" << endl;
    int a;
    cout << "Введите число a: ";
    cin >> a;

    int total = 0;
    for (int i = a; i <= 500; i++) {
        total += i;
    }
    cout << "Сумма чисел от " << a << " до 500: " << total << endl << endl;

    // задание 2: Возведение в степень
    cout << "Задание 2: Возведение в степень" << endl;
    int x, y;
    cout << "Введите число x: ";
    cin >> x;
    cout << "Введите степень y: ";
    cin >> y;

    long long result_power = 1;
    for (int i = 0; i < y; i++) {
        result_power *= x;
    }
    cout << x << " в степени " << y << " = " << result_power << endl << endl;

    // задание 4: Произведение чисел от a до 20
    cout << "Задание 4: Произведение чисел от a до 20" << endl;
    int b;
    cout << "Введите число a: ";
    cin >> b;

    if (b >= 1 && b <= 20) {
        long long product = 1;
        for (int i = b; i <= 20; i++) {
            product *= i;
        }
        cout << "Произведение чисел от " << b << " до 20: " << product << endl;
    }
    else {
        cout << "Ошибка: a должно быть в диапазоне от 1 до 20" << endl;
    }
    cout << endl;

    // задание 5: Таблица умножения
    cout << "Задание 5: Таблица умножения" << endl;
    int k;
    cout << "Введите номер варианта k: ";
    cin >> k;

    cout << "Таблица умножения на " << k << ":" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << k << " x " << i << " = " << k * i << endl;
    }

    return 0;
}