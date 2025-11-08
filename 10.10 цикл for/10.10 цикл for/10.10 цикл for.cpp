#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    //Задание 1
    cout << "задание 1:\n";
    int num1;
    cout << "Введите число: ";
    cin >> num1;

    cout << "Число наоборот: ";
    while (num1 > 0) {
        cout << num1 % 10;
        num1 /= 10;
    }
    cout << endl << endl;

    //Ззадание 2
    cout << "задание 2:\n";
    int num2;
    cout << "Введите число: ";
    cin >> num2;

    int sum = 0;
    while (num2 > 0) {
        sum += num2 % 10;
        num2 /= 10;
    }
    cout << "Сумма цифр: " << sum << endl << endl;

    //Задание 3
    cout << "Задание 3:\n";
    int days;
    cout << "Введите количество дней: ";
    cin >> days;

    int path = 0;
    int daily = 15;
    for (int i = 0; i < days; i++) {
        path += daily;
        daily += 2;
    }
    cout << "Общий путь: " << path << " см" << endl << endl;

    //Задание 4
    cout << "Задание 4:\n";
    int heads = 0;
    cout << "Введите 9 раз (1-орел, 0-решка):\n";

    for (int i = 0; i < 9; i++) {
        int coin;
        cin >> coin;
        if (coin == 1) heads++;
    }

    if (heads % 2 == 0) {
        cout << "Решение: положительное\n";
    }
    else {
        cout << "Решение: отрицательное\n";
    }
    cout << endl;

    //Задание 5
    cout << "Задание 5:\n";
    int days_count, start;
    cout << "Дней в месяце: ";
    cin >> days_count;
    cout << "Первый день недели (1-пн - 7-вс): ";
    cin >> start;

    cout << "Пн Вт Ср Чт Пт Сб Вс\n";

    for (int i = 1; i < start; i++) {
        cout << "   ";
    }

    for (int day = 1; day <= days_count; day++) {
        cout << day << " ";
        if (day < 10) cout << " ";

        if ((start - 1 + day) % 7 == 0) {
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}