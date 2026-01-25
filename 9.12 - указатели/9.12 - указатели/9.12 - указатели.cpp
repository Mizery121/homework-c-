#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int M, N;

    // Ввод размера массива
    cout << "Введите размер массива A(M): ";
    cin >> M;
    cout << "Введите размер массива B(N): ";
    cin >> N;

    // Создание массива
    int* A = new int[M];
    int* B = new int[N];

    // Заполнение массива А
    cout << "Введите элементы массива A: ";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    // Заполнение массива В
    cout << "Введите элементы массива B: ";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    // ЗАДАНИЕ 1.
    int* result1 = new int[M];
    int count1 = 0;

    // Ищем элементы из  массива A, которых нет в массиве B
    for (int i = 0; i < M; i++) {
        bool found = false;

        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }

        // Если не нашли в B, проверяем на повтор
        if (!found) {
            bool duplicate = false;
            for (int k = 0; k < count1; k++) {
                if (result1[k] == A[i]) {
                    duplicate = true;
                    break;
                }
            }

            if (!duplicate) {
                result1[count1] = A[i];
                count1++;
            }
        }
    }

    // Вывод Задания 1
    cout << endl << "ЗАДАНИЕ 1." << endl;
    cout << "Элементы A, которых нет в B: ";
    if (count1 == 0) {
        cout << "таких элементов нет";
    }
    else {
        for (int i = 0; i < count1; i++) {
            cout << result1[i] << " ";
        }
    }
    cout << endl;

    // ЗАДАНИЕ 2
    int* result2 = new int[M + N]; // максимум M+N элементов
    int count2 = 0;

    // Элементы из A, которых нет в B
    for (int i = 0; i < M; i++) {
        bool found = false;

        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }

        // Если не нашли, проверяем на повтор
        if (!found) {
            bool duplicate = false;
            for (int k = 0; k < count2; k++) {
                if (result2[k] == A[i]) {
                    duplicate = true;
                    break;
                }
            }

            if (!duplicate) {
                result2[count2] = A[i];
                count2++;
            }
        }
    }

    // Элементы из B, которых нет в A
    for (int i = 0; i < N; i++) {
        bool found = false;

        for (int j = 0; j < M; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }

        // Если не нашли, проверяем на повтор
        if (!found) {
            bool duplicate = false;
            for (int k = 0; k < count2; k++) {
                if (result2[k] == B[i]) {
                    duplicate = true;
                    break;
                }
            }

            if (!duplicate) {
                result2[count2] = B[i];
                count2++;
            }
        }
    }

    // Вывод Задания 2
    cout << endl << "ЗАДАНИЕ 2." << endl;
    cout << "Элементы, не общие для A и B: ";
    if (count2 == 0) {
        cout << "таких элементов нет";
    }
    else {
        for (int i = 0; i < count2; i++) {
            cout << result2[i] << " ";
        }
    }
    cout << endl;

    // Очистка памяти
    delete[] A;
    delete[] B;
    delete[] result1;
    delete[] result2;

    return 0;
}