#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // Задача 1
    cout << "Задание 1: " << endl;
    int a, b, c;
    cout << "Введите три числа: ";
    cin >> a >> b >> c;

    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    cout << "Наибольшее число: " << max << endl << endl;

    // Задача 2
    cout << "Задание 2: " << endl;
    int N;
    cout << "Введите размер таблицы: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }
    cout << endl;

    // Задание 3
    cout << "Задание 3: " << endl;
    int x;
    cout << "Введите число: ";
    cin >> x;

    if (x % 3 == 0 && x % 5 == 0) {
        cout << "FizzBuzz" << endl;
    }
    else if (x % 3 == 0) {
        cout << "Fizz" << endl;
    }
    else if (x % 5 == 0) {
        cout << "Buzz" << endl;
    }
    else {
        cout << x << endl;
    }
    cout << endl;

    // Задание 4
    cout << "Задание 4: " << endl;
    int factN;
    long long factorial = 1;
    cout << "Введите число: ";
    cin >> factN;

    if (factN < 0) {
        cout << "Факториал отрицательного числа не определен!" << endl;
    }
    else {
        for (int i = 1; i <= factN; i++) {
            factorial *= i;
        }
        cout << "Факториал: " << factorial << endl;
    }
    cout << endl;

    // Задача 5
    cout << "Задание 5: " << endl;
    int size;
    cout << "Размер массива: ";
    cin >> size;

    if (size <= 0) {
        cout << "Неверный размер массива!" << endl;
    }
    else if (size > 100) {
        cout << "Слишком большой размер массива! Максимум 100." << endl;
    }
    else {
        int arr[100];
        srand(time(0));

        cout << "Случайные числа: ";
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100 + 1;
            cout << arr[i] << " ";
        }
        cout << endl;

        int min = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        cout << "Минимальный элемент: " << min << endl;
    }
    cout << endl;

    // Задача 6
    cout << "Задание 6: " << endl;
    int numberN;
    cout << "Введите число: ";
    cin >> numberN;

    for (int i = 1; i <= numberN; i++) {
        if (i % 15 == 0) {
            cout << "ThreeFive ";
        }
        else if (i % 3 == 0) {
            cout << "Three ";
        }
        else if (i % 5 == 0) {
            cout << "Five ";
        }
        else {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}