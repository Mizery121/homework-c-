#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    //задача 1
    cout << "Задача 1: \n";
    int A, B;
    cout << "Введите начало диапазона A: ";
    cin >> A;
    cout << "Введите конец диапазона B: ";
    cin >> B;

    cout << "\nРезультаты:\n";
    for (int num = A; num <= B; num++) {
        cout << "Делители для числа " << num << " — ";
        int count = 0;
        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {
                cout << i << " ";
                count++;
            }
        }
        cout << "(всего: " << count << " делителей)\n";
    }

    //задача 2
    cout << "\nзадача 2: \n";
    cout << "Простые числа: \n";
    int primeCount = 0;
    for (int num = 2; num <= 1000; num++) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << num << " ";
            primeCount++;
            if (primeCount % 10 == 0) cout << endl;
        }
    }
    cout << "\nВсего простых чисел: " << primeCount << endl;

    //Задача 3
    cout << "\nЗадача 3: \n";
    int width, height;
    cout << "Введите ширину фигуры (положительное нечетное число): ";
    cin >> width;
    cout << "Введите высоту фигуры (положительное нечетное число): ";
    cin >> height;

    if (width % 2 == 0 || height % 2 == 0 || width <= 0 || height <= 0) {
        cout << "Ошибка! Числа должны быть положительными и нечетными.\n";
    }
    else {
        cout << "\nФигура:\n";
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << "| * ";
            }
            cout << "|\n";
        }
    }

    // Задача 4: Комбинации кода чемодана
    cout << "\n=== Задача 4: Комбинации кода чемодана ===\n";
    cout << "Все возможные комбинации трехзначного кода без повторяющихся цифр:\n";
    int comboCount = 0;

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (i != j && i != k && j != k) {
                    cout << i << j << k << " ";
                    comboCount++;
                    if (comboCount % 10 == 0) cout << endl;
                }
            }
        }
    }

    int totalTime = comboCount * 3;
    cout << "\nВсего комбинаций: " << comboCount << endl;
    cout << "Время для открытия в худшем случае: " << totalTime << " секунд ("
        << totalTime / 60 << " минут " << totalTime % 60 << " секунд)\n";

    return 0;
}