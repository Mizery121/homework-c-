#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU"); // первое задание не делается почему то
    cout << "ВОЗВЕДЕНИЕ ЧИСЛА В СТЕПЕНЬ" << endl;

    double number;
    int power;

    // Ввод числа
    cout << "Введите число: ";
    cin >> number;

    // Выбор степени - просто цифра от 0 до 7
    cout << "Введите степень (0-7): ";
    cin >> power;

    // Проверка корректности ввода степени
    if (power < 0 || power > 7) {
        cout << "Ошибка! Степень должна быть от 0 до 7." << endl;
        return 1;
    }

    // Вычисление результата
    double result = 1;

    for (int i = 0; i < power; i++) {
        result *= number;
    }

    // Вывод результата
    cout << number << " ^ " << power << " = " << result << endl;

    return 0;
}