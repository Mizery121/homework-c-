#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    // 1. Символьная переменная
    cout << "1. Символьная переменная" << endl;
    char symbol = 'A';
    cout << "Символ: " << symbol << endl << endl;

    // 4. Проверка четности числа
    cout << "4. Проверка четности" << endl;
    int number;
    cout << "Введите число: ";
    cin >> number;
    cout << "Число " << number << " - " << (number % 2 == 0 ? "чётное" : "нечётное") << endl << endl;

    // 7. Кубы чисел от 1 до 10
    cout << "7. Кубы чисел от 1 до 10" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << i << "^3 = " << i * i * i << endl;
    }
    cout << endl;

    // 10. Сортировка выбором с вводом данных
    cout << "10. Сортировка выбором" << endl;
    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    int* arr = new int[n];  // Динамическое выделение памяти
    cout << "Введите " << n << " элементов массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Сортировка выбором
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Обмен элементов
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    delete[] arr;  // Освобождение памяти

    // 13. Двумерный массив 3x3
    cout << "13. Двумерный массив 3x3" << endl;
    int matrix[3][3];
    int count = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = count++;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}