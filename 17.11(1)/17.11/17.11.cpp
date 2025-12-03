#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    // 1) Степень числа
    cout << "1. возведение в степень\n";
    double osn;
    int step;
    cout << "Введите основание: ";
    cin >> osn;
    cout << "Введите степень: ";
    cin >> step;

    double res = 1;
    int st = abs(step);
    for (int i = 0; i < st; i++) {
        res = res * osn;
    }
    if (step < 0) {
        res = 1.0 / res;
    }
    cout << osn << "^" << step << " = " << res << "\n\n";

    // 2) Сумма диапазона
    cout << "2. сумма чисел в диапазоне\n";
    int x, y;
    cout << "Введите первое число: ";
    cin >> x;
    cout << "Введите второе число: ";
    cin >> y;

    int start, end;
    if (x < y) {
        start = x;
        end = y;
    }
    else {
        start = y;
        end = x;
    }

    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum = sum + i;
    }
    cout << "Сумма от " << start << " до " << end << " = " << sum << "\n\n";

    // 3) Совершенные числа
    cout << "3. совершенные числа\n";
    int nach, kon;
    cout << "Введите начало интервала: ";
    cin >> nach;
    cout << "Введите конец интервала: ";
    cin >> kon;

    cout << "Совершенные числа в интервале [" << nach << ", " << kon << "]: ";
    for (int num = nach; num <= kon; num++) {
        if (num <= 0) continue;

        int del = 0;
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                del = del + i;
            }
        }
        if (del == num) {
            cout << num << " ";
        }
    }
    cout << "\n\n";

    // 4) Карта
    cout << "4. игральная картаА\n";
    int karta;
    char mast;
    cout << "Введите значение карты (1-13): ";
    cin >> karta;
    cout << "Введите масть (h/d/c/s): ";
    cin >> mast;

    // масть символом
    char mast_sim;
    if (mast == 'h') mast_sim = 'H';
    else if (mast == 'd') mast_sim = 'D';
    else if (mast == 'c') mast_sim = 'C';
    else if (mast == 's') mast_sim = 'S';
    else mast_sim = mast;

    string znach;
    if (karta == 1) znach = "A";
    else if (karta == 11) znach = "J";
    else if (karta == 12) znach = "Q";
    else if (karta == 13) znach = "K";
    else if (karta >= 2 && karta <= 10) znach = to_string(karta);
    else znach = "?";

    cout << " ____\n";
    cout << "|" << znach;
    if (znach.length() == 1) cout << "   ";
    cout << "|\n";
    cout << "| " << mast_sim << "  |\n";
    cout << "| ";
    if (znach.length() == 1) cout << " ";
    cout << znach << " |\n";
    cout << "|____|\n\n";

    // 5) Счастливое число
    cout << "5. счастливое число\n";
    int chislo;
    cout << "Введите шестизначное число: ";
    cin >> chislo;

    if (chislo < 100000 || chislo > 999999) {
        cout << "Это не шестизначное число!\n";
    }
    else {
        int c1 = chislo / 100000;
        int c2 = (chislo / 10000) % 10;
        int c3 = (chislo / 1000) % 10;
        int c4 = (chislo / 100) % 10;
        int c5 = (chislo / 10) % 10;
        int c6 = chislo % 10;

        int sum1 = c1 + c2 + c3;
        int sum2 = c4 + c5 + c6;

        if (sum1 == sum2) {
            cout << chislo << " - СЧАСТЛИВОЕ число!\n";
        }
        else {
            cout << chislo << " - обычное число\n";
        }
    }

    return 0;
}