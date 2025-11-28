#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    // задание 1
    cout << "ЗАДАНИЕ 1" << endl;
    int arr[3][4] = { {3,5,6,7}, {12,1,1,1}, {0,7,12,1} };

    int sum = 0;
    int min = arr[0][0];
    int max = arr[0][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            sum += arr[i][j];
            if (arr[i][j] < min) min = arr[i][j];
            if (arr[i][j] > max) max = arr[i][j];
        }
    }

    cout << "Сумма: " << sum << endl;
    cout << "Среднее: " << sum / 12.0 << endl;
    cout << "Минимальный: " << min << endl;
    cout << "Максимальный: " << max << endl << endl;

    // задание 2
    cout << "ЗАДАНИЕ 2" << endl;
    int rowSum[3] = { 0 };
    int colSum[4] = { 0 };
    int total = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
            rowSum[i] += arr[i][j];
            colSum[j] += arr[i][j];
        }
        cout << "| " << rowSum[i] << endl;
        total += rowSum[i];
    }

    cout << "-----------------" << endl;
    for (int j = 0; j < 4; j++) {
        cout << colSum[j] << " ";
    }
    cout << "| " << total << endl << endl;

    // задание 3
    cout << "ЗАДАНИЕ 3" << endl;
    int big[5][10];
    int small[5][5];

    // заполнение 1 массива случайными числами
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            big[i][j] = rand() % 51;
        }
    }

    // заполнение 2 массива
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            small[i][j] = big[i][j * 2] + big[i][j * 2 + 1];
        }
    }

    cout << "\nПервый массив:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            cout << big[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nВторой массив:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << small[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}