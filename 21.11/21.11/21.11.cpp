#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
using namespace std;


// 1 Задание
double power(double base, int exp) {
    if (exp == 0) return 1;// Любое число в степени 0 = 1
    if (exp > 0) return base * power(base, exp - 1);// Положительная степень
    return 1.0 / power(base, -exp);// Отрицательная степень
}

//2 Задание
void printStars(int n) {
    if (n <= 0) return;
    cout << "*";
    printStars(n - 1);
}

// 3 Задание
int sumRange(int a, int b) {
    if (a > b) return 0;
    if (a == b) return a;
    return a + sumRange(a + 1, b);// Текущее число + сумма остальных
}

// 4 Задание
int findMinSumStart(int arr[], int index, int& minSum, int& minIndex) {
    if (index > 90) return minIndex;

    // Вычисление суммы текущих 10 чисел
    int currentSum = 0;
    for (int i = index; i < index + 10; i++) {
        currentSum += arr[i];
    }

    // Если сумма меньше минимальной
    if (currentSum < minSum) {
        minSum = currentSum;
        minIndex = index;
    }

    // Рекурсивный вызов для следующей позиции
    return findMinSumStart(arr, index + 1, minSum, minIndex);
}


int main() {
    setlocale(LC_ALL, "RU");
    cout << "=== ВЫПОЛНЕНИЕ РЕКУРСИВНЫХ ФУНКЦИЙ ===\n\n";

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Задание 1
    cout << "1. Возведение в степень:\n";

    // Пользовательский ввод для демонстрации
    double num;
    int exp;
    cout << "\nВведите число для возведения в степень: ";
    cin >> num;
    cout << "Введите степень: ";
    cin >> exp;
    cout << num << "^" << exp << " = " << power(num, exp) << "\n\n";

    // Задание 2
    cout << "2. Вывод звезд:\n";

    int starCount;
    cout << "Введите количество звезд: ";
    cin >> starCount;
    cout << "Результат: ";
    printStars(starCount);
    cout << "\n\n";

    // Задание 3
    cout << "3. Сумма чисел в диапазоне:\n";

    int start, end;
    cout << "Введите начало диапазона: ";
    cin >> start;
    cout << "Введите конец диапазона: ";
    cin >> end;

    cout << "Сумма чисел от " << start << " до " << end
        << " = " << sumRange(start, end) << "\n\n";

    // Задание 4
    cout << "4. Поиск последовательностей с минимальной суммой:\n";

    const int SIZE = 100;
    int numbers[SIZE];

    // Заполнение массива случайными числами
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = rand() % 100;
    }

    cout << "Полный массив: ";
    for (int i = 0; i < 100; i++) {
        cout << numbers[i] << " ";
    }

    // Поиск последовательности из 10 чисел с минимальной суммой
    int minSum = INT_MAX;
    int minStart = -1;

    findMinSumStart(numbers, 0, minSum, minStart);

    cout << "\nНачало последовательности: элемент номер  " << minStart << "\n";
    cout << "Минимальная сумма 10 чисел: " << minSum << "\n";
    cout << "Последовательность: ";

    // Вывод найденной последовательности
    for (int i = minStart; i < minStart + 10; i++) {
        cout << numbers[i];
        if (i < minStart + 9) cout << " + ";
    }
    cout << " = " << minSum << endl;


    return 0;
}