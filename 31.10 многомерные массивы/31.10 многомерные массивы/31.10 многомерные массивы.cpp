#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    // Задание 1
    cout << "Задание 1:\n";
    int n;
    cout << "Введите число: ";
    cin >> n;

    int arr1[3][3];
    int current = n;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr1[i][j] = current;
            current = current * 2;
        }
    }

    cout << "Результат:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    // Задание 2
    cout << "\nЗадание 2:\n";
    cout << "Введите число: ";
    cin >> n;

    int arr2[3][3];
    current = n;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr2[i][j] = current;
            current = current + 1;
        }
    }

    cout << "Результат:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    // Задание 3
    cout << "\nЗадание 3:\n";
    int arr3[2][6] = { {1,2,0,4,5,3}, {4,5,3,9,0,1} };

    cout << "Исходный массив:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }

    int shift;
    cout << "Количество сдвигов: ";
    cin >> shift;

    char dir;
    cout << "Направление (l-влево, r-вправо, u-вверх, d-вниз): ";
    cin >> dir;

    int result[2][6];

    if (dir == 'l') { // влево
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 6; j++) {
                result[i][j] = arr3[i][(j + shift) % 6];
            }
        }
    }
    else if (dir == 'r') { // вправо
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 6; j++) {
                result[i][j] = arr3[i][(j - shift + 6) % 6];
            }
        }
    }
    else if (dir == 'u') { // вверх
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 6; j++) {
                result[i][j] = arr3[(i + shift) % 2][j];
            }
        }
    }
    else if (dir == 'd') { // вниз
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 6; j++) {
                result[i][j] = arr3[(i - shift + 2) % 2][j];
            }
        }
    }

    cout << "После сдвига:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}