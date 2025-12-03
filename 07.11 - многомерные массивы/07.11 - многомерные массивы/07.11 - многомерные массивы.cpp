#include <iostream>
#include <vector>
#include <random>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "RU");
    random_device rd;
    mt19937 gen(rd());

    // 1) Массив 10 чисел [1,100]
    cout << "1. Массив из 10 чисел:\n";
    vector<int> arr(10);
    for (int& x : arr) x = uniform_int_distribution<>(1, 100)(gen);
    for (int x : arr) cout << x << " ";
    cout << endl;

    // 2) Максимальный элемент
    cout << "\n2. Максимальный элемент:\n";
    vector<int> arr2(15);
    for (int& x : arr2) x = uniform_int_distribution<>(1, 50)(gen);
    int max_idx = 0;
    for (int i = 1; i < 15; i++) {
        if (arr2[i] > arr2[max_idx]) max_idx = i;
    }
    for (int x : arr2) cout << x << " ";
    cout << "\nМаксимум: " << arr2[max_idx] << " на позиции " << max_idx << endl;

    // 3) Только положительные
    cout << "\n3. Только положительные числа:\n";
    vector<int> arr3(20);
    for (int& x : arr3) x = uniform_int_distribution<>(-50, 50)(gen);
    for (int x : arr3) cout << x << " ";
    cout << "\nПоложительные: ";
    for (int x : arr3) if (x > 0) cout << x << " ";
    cout << endl;

    // 4) Простые числа
    cout << "\n4. Подсчет простых чисел:\n";
    vector<int> arr4(15);
    for (int& x : arr4) x = uniform_int_distribution<>(1, 100)(gen);
    int primes = 0;
    for (int x : arr4) {
        cout << x << " ";
        if (isPrime(x)) primes++;
    }
    cout << "\nПростых чисел: " << primes << endl;

    // 5) Минимальное расстояние
    cout << "\n5. Минимальное расстояние:\n";
    vector<int> a(8), b(8);
    for (int& x : a) x = uniform_int_distribution<>(1, 100)(gen);
    for (int& x : b) x = uniform_int_distribution<>(1, 100)(gen);
    int min_dist = 1000;
    for (int x : a) {
        for (int y : b) {
            int d = abs(x - y);
            if (d < min_dist) min_dist = d;
        }
    }
    for (int x : a) cout << x << " ";
    cout << endl;
    for (int x : b) cout << x << " ";
    cout << "\nМинимальное расстояние: " << min_dist << endl;

    // 6) Матрица 5x5
    cout << "\n6. Матрица 5x5:\n";
    int m5[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            m5[i][j] = uniform_int_distribution<>(1, 100)(gen);
            cout << m5[i][j] << "\t";
        }
        cout << endl;
    }

    // 7) Суммы строк матрицы 4x4
    cout << "\n7. Суммы строк матрицы 4x4:\n";
    int m4[4][4];
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            m4[i][j] = uniform_int_distribution<>(1, 100)(gen);
            cout << m4[i][j] << "\t";
            sum += m4[i][j];
        }
        cout << "  Сумма: " << sum << endl;
    }

    return 0;
}