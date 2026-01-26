#include <iostream>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int SIZE = 5;
    int source[SIZE];  // Массив 
    int destination1[SIZE];  // Для задания 1
    int destination2[SIZE];  // Для задания 2
    int destination3[SIZE];  // Для задания 3
    int temp[SIZE];

    // Ввод массива
    cout << "Введите " << SIZE << " элементов массива:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Элемент " << i + 1 << ": ";
        cin >> source[i];
    }
    cout << endl;

    // Сохраняем исходный массив
    for (int i = 0; i < SIZE; i++) {
        temp[i] = source[i];
    }

    // Задание 1. Копирование массива
    cout << "Задание 1: Копирование массива" << endl;
    int* ptrSrc1 = source;
    int* ptrDst1 = destination1;

    for (int i = 0; i < SIZE; ++i) {
        *(ptrDst1 + i) = *(ptrSrc1 + i);
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << source[i] << " ";
    }
    cout << endl;

    cout << "Скопированный массив: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << destination1[i] << " ";
    }
    cout << endl << endl;

    // Задание 2. Изменение порядка элементов на противоположный
    cout << "Задание 2: Изменение порядка элементов на противоположный" << endl;

    // Восстанавливаем исходный массив
    for (int i = 0; i < SIZE; i++) {
        source[i] = temp[i];
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << source[i] << " ";
    }
    cout << endl;

    int* start = source;
    int* end = source + SIZE - 1;

    // Копируем исходный массив
    for (int i = 0; i < SIZE; i++) {
        destination2[i] = source[i];
    }

    start = destination2;
    end = destination2 + SIZE - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        ++start;
        --end;
    }

    cout << "Массив в обратном порядке: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << destination2[i] << " ";
    }
    cout << endl << endl;

    // Задание 3. Копирование массива в обратном порядке
    cout << "=== Задание 3: Копирование массива в обратном порядке ===" << endl;

    // Восстанавливаем исходный массив
    for (int i = 0; i < SIZE; i++) {
        source[i] = temp[i];
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << source[i] << " ";
    }
    cout << endl;

    int* ptrSrc3 = source;
    int* ptrDst3 = destination3 + SIZE - 1;

    for (int i = 0; i < SIZE; ++i) {
        *ptrDst3 = *ptrSrc3;
        ++ptrSrc3;
        --ptrDst3;
    }

    cout << "Массив, скопированный в обратном порядке: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << destination3[i] << " ";
    }
    cout << endl;

    return 0;
}