#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    //задача 1

    cout << "Задача 1: \n";
    int number;
    cout << "Введите число: ";
    cin >> number;

    int temp = abs(number);
    int digitCount = 0;
    int digitSum = 0;
    int zeroCount = 0;

    if (temp == 0) {
        digitCount = 1;
        zeroCount = 1;
        digitSum = 0;
    }
    else {
        while (temp > 0) {
            int digit = temp % 10;
            digitCount++;
            digitSum += digit;
            if (digit == 0) {
                zeroCount++;
            }
            temp /= 10;
        }
    }

    double average = static_cast<double>(digitSum) / digitCount;

    cout << "\nРезультаты анализа числа " << number << ":\n";
    cout << "Количество цифр: " << digitCount << endl;
    cout << "Сумма цифр: " << digitSum << endl;
    cout << "Среднее арифметическое: " << average << endl;
    cout << "Количество нулей: " << zeroCount << endl;


    //задача 2
    cout << "\nЗадача 2: \n";
    int cellSize;
    cout << "Введите размер клеточки: ";
    cin >> cellSize;

    cout << "\nШахматная доска:\n";
    for (int row = 0; row < 8; row++) {
        for (int subRow = 0; subRow < cellSize; subRow++) {
            for (int col = 0; col < 8; col++) {
                if ((row + col) % 2 == 0) {
                    for (int i = 0; i < cellSize; i++) {
                        cout << "*";
                    }
                }
                else {
                    for (int i = 0; i < cellSize; i++) {
                        cout << "-";
                    }
                }
            }
            cout << endl;
        }
    }



    //задача 3
    cout << "\nЗадача 3: \n";
    cout << "Поле морского боя:\n\n";

    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            char letter = 'A' + col;
            cout << letter << row << " ";
        }
        cout << endl;
    }


    return 0;
}