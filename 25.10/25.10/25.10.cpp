#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // Задача 1
    cout << "Таблица умножения от 1 до 10" << endl;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << i << " * " << j << " = " << i * j << endl;
        }
        cout << endl;
    }

    // Задача 2
    cout << "Поиск простых чисел" << endl;
    int N;
    cout << "Введите n: ";
    cin >> N;

    cout << "Простые числа до " << N << ": ";
    for (int num = 2; num <= N; num++) {
        bool isPrime = true;
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << num << " ";
        }
    }
    cout << endl << endl;

    // Задача 3
    cout << "Матрица m x n" << endl;
    int M, cols;
    cout << "Введите m (строки): ";
    cin >> M;
    cout << "Введите n (столбцы): ";
    cin >> cols;

    int counter = 1;
    cout << "Матрица " << M << "x" << cols << ":" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < cols; j++) {
            cout << counter++ << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Задача 4
    cout << "Перестановки чисел от 1 до 3" << endl;
    int arr[] = { 1, 2, 3 };
    int count = 0;

    // Все перестановки
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i != j && i != k && j != k) {
                    // отслеживание перестановок
                    cout << ++count << ": " << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                }
            }
        }
    }
    cout << "Всего перестановок: " << count << endl;

    return 0;
}