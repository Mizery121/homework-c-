#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    // 3 Задание
    int M, N;
    cout << "Размеры массивов A и B: ";
    cin >> M >> N;

    vector<int> A(M), B(N);

    cout << "Элементы массива A: ";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Элементы массива B: ";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    // Объединяем массивы без повторений
    vector<int> C;

    for (int i = 0; i < M; i++) {
        bool found = false;
        for (int num : C) {
            if (num == A[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            C.push_back(A[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        bool found = false;
        for (int num : C) {
            if (num == B[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            C.push_back(B[i]);
        }
    }

    cout << "Объединенный массив: ";
    for (int num : C) {
        cout << num << " ";
    }
    cout << endl;

    //  4 Задание
    int choice;
    cout << "1 - удалить четные, 2 - удалить нечетные: ";
    cin >> choice;

    vector<int> D;

    if (choice == 1) {
        // Оставляем нечетные
        for (int num : C) {
            if (num % 2 != 0) {
                D.push_back(num);
            }
        }
    }
    else if (choice == 2) {
        // Оставляем четные
        for (int num : C) {
            if (num % 2 == 0) {
                D.push_back(num);
            }
        }
    }

    cout << "Результат: ";
    if (D.empty()) {
        cout << "массив пуст";
    }
    else {
        for (int num : D) {
            cout << num << " ";
        }
    }

    return 0;
}