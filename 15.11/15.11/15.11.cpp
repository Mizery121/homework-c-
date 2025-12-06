#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    // === 1. Перевод в систему счисления ===
    cout << "1. Перевод числа в систему счисления\n";
    int n1, b;
    cout << "Число: "; cin >> n1;
    cout << "Система счисления: "; cin >> b;

    if (b < 2 || b > 36) cout << "Ошибка!\n";
    else {
        string result = "";
        int num = n1;
        if (num == 0) result = "0";
        while (num > 0) {
            int r = num % b;
            char c = (r < 10) ? '0' + r : 'A' + r - 10;
            result = c + result;
            num /= b;
        }
        cout << "Результат: " << result << "\n\n";
    }

    // === 2. Игра в кубики ===
    cout << "2. Игра в кубики\n";
    srand(time(NULL));
    int human = 0, computer = 0;
    cout << "Кто первый? (1-человек, 2-компьютер): ";
    int first; cin >> first;

    for (int i = 1; i <= 5; i++) {
        int h1 = rand() % 6 + 1, h2 = rand() % 6 + 1;
        int c1 = rand() % 6 + 1, c2 = rand() % 6 + 1;

        if (first == 1) {
            cout << "Человек: " << h1 + h2 << " ";
            cout << "Компьютер: " << c1 + c2 << endl;
            human += h1 + h2;
            computer += c1 + c2;
        }
        else {
            cout << "Компьютер: " << c1 + c2 << " ";
            cout << "Человек: " << h1 + h2 << endl;
            computer += c1 + c2;
            human += h1 + h2;
        }
    }

    cout << "Итог: " << human << ":" << computer << endl;
    cout << "Среднее: " << (float)human / 5 << " и " << (float)computer / 5 << "\n\n";

    // === 3. Прямоугольник ===
    cout << "3. Прямоугольник\n";
    int h, w;
    cout << "Высота и ширина: "; cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cout << "*";
        cout << endl;
    }
    cout << endl;

    // === 4. Факториал ===
    cout << "4. Факториал\n";
    int n4;
    cout << "Число: "; cin >> n4;
    long long f = 1;
    for (int i = 1; i <= n4; i++) f *= i;
    cout << "Факториал: " << f << "\n\n";

    // === 5. Простое число ===
    cout << "5. Проверка на простое число\n";
    int n5;
    cout << "Число: "; cin >> n5;
    bool prime = true;
    if (n5 < 2) prime = false;
    for (int i = 2; i * i <= n5; i++)
        if (n5 % i == 0) { prime = false; break; }
    cout << (prime ? "Простое" : "Не простое") << "\n\n";

    // === 6. Минимум/максимум ===
    cout << "6. Минимум и максимум в массиве\n";
    int arr6[5];
    cout << "Введите 5 чисел: ";
    for (int i = 0; i < 5; i++) cin >> arr6[i];

    int min = arr6[0], max = arr6[0];
    int minIdx = 0, maxIdx = 0;
    for (int i = 1; i < 5; i++) {
        if (arr6[i] < min) { min = arr6[i]; minIdx = i; }
        if (arr6[i] > max) { max = arr6[i]; maxIdx = i; }
    }
    cout << "Мин: " << min << " (поз. " << minIdx << ")\n";
    cout << "Макс: " << max << " (поз. " << maxIdx << ")\n\n";

    // === 7. Реверс массива ===
    cout << "7. Реверс массива\n";
    int arr7[5];
    cout << "Введите 5 чисел: ";
    for (int i = 0; i < 5; i++) cin >> arr7[i];

    cout << "Было: ";
    for (int i = 0; i < 5; i++) cout << arr7[i] << " ";
    cout << endl;

    for (int i = 0; i < 2; i++) {
        int temp = arr7[i];
        arr7[i] = arr7[4 - i];
        arr7[4 - i] = temp;
    }

    cout << "Стало: ";
    for (int i = 0; i < 5; i++) cout << arr7[i] << " ";
    cout << endl;

    return 0;
}