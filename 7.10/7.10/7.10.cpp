#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    // Задание 1: Игра "Угадай число"
    cout << "\n1. ИГРА УГАДАЙ ЧИСЛО" << endl;

    srand(time(0));
    int secret = rand() % 500 + 1;
    int guess, attempts = 0;

    cout << "Я загадал число от 1 до 500. Угадайте!" << endl;
    cout << "Для выхода введите 0." << endl;

    do {
        cout << "Ваш вариант: ";
        cin >> guess;

        if (guess == 0) {
            cout << "Выход. Загаданное число: " << secret << endl;
            break;
        }

        attempts++;

        if (guess < secret) {
            cout << "БОЛЬШЕ" << endl;
        }
        else if (guess > secret) {
            cout << "МЕНЬШЕ" << endl;
        }
        else {
            cout << "УГАДАЛ! За " << attempts << " попыток." << endl;
        }
    } while (guess != secret);

    // Задание 2: Конвертер валют
    cout << "\n2. КОНВЕРТЕР ВАЛЮТ" << endl;

    // Курсы валют
    double usd_to_rub = 90.5;
    double usd_to_eur = 0.92;
    double eur_to_rub = 98.5;

    int choice;
    double amount;

    do {
        cout << "\n1. USD -> RUB" << endl;
        cout << "2. RUB -> USD" << endl;
        cout << "3. USD -> EUR" << endl;
        cout << "4. EUR -> USD" << endl;
        cout << "5. EUR -> RUB" << endl;
        cout << "6. RUB -> EUR" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;

        if (choice == 0) break;
        if (choice < 1 || choice > 6) {
            cout << "Неверный выбор!" << endl;
            continue;
        }

        cout << "Сумма: ";
        cin >> amount;

        switch (choice) {
        case 1: // USD -> RUB
            cout << amount << " USD = " << amount * usd_to_rub << " RUB" << endl;
            break;
        case 2: // RUB -> USD
            cout << amount << " RUB = " << amount / usd_to_rub << " USD" << endl;
            break;
        case 3: // USD -> EUR
            cout << amount << " USD = " << amount * usd_to_eur << " EUR" << endl;
            break;
        case 4: // EUR -> USD
            cout << amount << " EUR = " << amount / usd_to_eur << " USD" << endl;
            break;
        case 5: // EUR -> RUB
            cout << amount << " EUR = " << amount * eur_to_rub << " RUB" << endl;
            break;
        case 6: // RUB -> EUR
            cout << amount << " RUB = " << amount / eur_to_rub << " EUR" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}