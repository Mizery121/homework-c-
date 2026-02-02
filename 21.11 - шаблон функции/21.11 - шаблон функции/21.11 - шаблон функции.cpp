#include <iostream>
#include <cmath>

using namespace std;

// Задание 1: Среднее арифметическое
double average(double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum / n;
}

// Задание 2: Решение линейного уравнения
void solveLinear(double a, double b) {
    if (a == 0) {
        if (b == 0) cout << "Бесконечно много решений" << endl;
        else cout << "Нет решений" << endl;
    }
    else {
        cout << "x = " << -b / a << endl;
    }
}

// Задание 2: Решение квадратного уравнения
void solveQuadratic(double a, double b, double c) {
    if (a == 0) {
        solveLinear(b, c);
        return;
    }

    double d = b * b - 4 * a * c;
    if (d > 0) {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (d == 0) {
        double x = -b / (2 * a);
        cout << "x = " << x << endl;
    }
    else {
        cout << "Нет действительных корней" << endl;
    }
}

// Задание 3: Округление
double roundTo(double num, int decimals) {
    double p = pow(10, decimals);
    return round(num * p) / p;
}

// Задание 4: Максимум в одномерном массиве
int findMax1D(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

// Задание 5: Максимум двух и трех чисел
int max(int a, int b) {
    return (a > b) ? a : b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int main() {
    setlocale(LC_ALL, "RU");
    int choice;

    while (true) {
        cout << "\n1. Среднее арифметическое" << endl;
        cout << "2. Решение уравнений" << endl;
        cout << "3. Округление числа" << endl;
        cout << "4. Максимум в массиве" << endl;
        cout << "5. Максимум чисел" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1: {
            int n;
            cout << "Сколько чисел? ";
            cin >> n;
            double arr[100];
            cout << "Введите числа: ";
            for (int i = 0; i < n; i++) cin >> arr[i];
            cout << "Среднее: " << average(arr, n) << endl;
            break;
        }

        case 2: {
            cout << "1. Линейное (ax + b = 0)" << endl;
            cout << "2. Квадратное (ax^2 + bx + c = 0)" << endl;
            int type;
            cin >> type;

            if (type == 1) {
                double a, b;
                cout << "Введите a и b: ";
                cin >> a >> b;
                solveLinear(a, b);
            }
            else {
                double a, b, c;
                cout << "Введите a, b, c: ";
                cin >> a >> b >> c;
                solveQuadratic(a, b, c);
            }
            break;
        }

        case 3: {
            double num;
            int decimals;
            cout << "Введите число: ";
            cin >> num;
            cout << "Сколько знаков после запятой? ";
            cin >> decimals;
            cout << "Результат: " << roundTo(num, decimals) << endl;
            break;
        }

        case 4: {
            int n;
            cout << "Сколько чисел в массиве? ";
            cin >> n;
            int arr[100];
            cout << "Введите числа: ";
            for (int i = 0; i < n; i++) cin >> arr[i];
            cout << "Максимум: " << findMax1D(arr, n) << endl;
            break;
        }

        case 5: {
            cout << "Сколько чисел сравнить (2 или 3)? ";
            int count;
            cin >> count;

            if (count == 2) {
                int a, b;
                cout << "Введите два числа: ";
                cin >> a >> b;
                cout << "Максимум: " << max(a, b) << endl;
            }
            else if (count == 3) {
                int a, b, c;
                cout << "Введите три числа: ";
                cin >> a >> b >> c;
                cout << "Максимум: " << max(a, b, c) << endl;
            }
            break;
        }
        }
    }

    return 0;
}