#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // ЗАДАНИЕ 1
    cout << "Задание 1.\n";

    const int n = 5;
    int mobTel[n], tel[n];

    // Ввод данных
    cout << "Введите данные для " << n << " пользователей:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nПользователь " << (i + 1) << ":\n";
        cout << "Мобильный телефон: ";
        cin >> mobTel[i];
        cout << "Домашний телефон: ";
        cin >> tel[i];
    }

    // Вывод данных
    cout << "\n\nИсходные данные:\n";
    cout << "№\tМобильный\tДомашний\n";
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << "\t" << mobTel[i] << "\t\t" << tel[i] << endl;
    }

    // Сортировка по мобильным номерам
    cout << "\n\nСортировка по мобильным номерам...\n";

    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (mobTel[j] > mobTel[j + 1]) {
                int temp = mobTel[j];
                mobTel[j] = mobTel[j + 1];
                mobTel[j + 1] = temp;

                temp = tel[j];
                tel[j] = tel[j + 1];
                tel[j + 1] = temp;

                swapped = true;
            }
        }

        if (!swapped) {
            cout << "Сортировка остановлена на шаге " << (i + 1) << endl;
            break;
        }
    }

    // Вывод после сортировки
    cout << "\nПосле сортировки по мобильным номерам:\n";
    cout << "№\tМобильный\tДомашний\n";
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << "\t" << mobTel[i] << "\t\t" << tel[i] << endl;
    }

    // ЗАДАНИЕ 2
    cout << "\n\nЗадание 2.\n\n";

    const int m = 10;
    int arr[m];

    cout << "Введите " << m << " чисел для сортировки:\n";
    for (int i = 0; i < m; i++) {
        cout << "Число " << (i + 1) << ": ";
        cin >> arr[i];
    }

    cout << "\nИсходный массив: ";
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Пузырьковая сортировка
    cout << "\nСортировка...\n";
    for (int i = 0; i < m - 1; i++) {
        swapped = false;

        for (int j = 0; j < m - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {
            cout << "Сортировка остановлена на шаге " << (i + 1) << endl;
            break;
        }
    }

    cout << "\nОтсортированный массив: ";
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ЗАДАНИЕ 3
    cout << "\n\nЗадание 3.\n\n";

    const int p = 8;
    int pancakes[p];

    cout << "Введите радиусы " << p << " оладий (снизу вверх):\n";
    for (int i = 0; i < p; i++) {
        cout << "Оладье " << (i + 1) << " (радиус): ";
        cin >> pancakes[i];
    }

    cout << "\nИсходная стопка (снизу вверх): ";
    for (int i = p - 1; i >= 0; i--) {
        cout << pancakes[i] << " ";
    }
    cout << endl;

    // Функция для переворота
    auto flip = [](int arr[], int k) {
        int start = 0;
        while (start < k) {
            int temp = arr[start];
            arr[start] = arr[k];
            arr[k] = temp;
            start++;
            k--;
        }
        };

    // Блинная сортировка (по убыванию снизу вверх)
    for (int size = p; size > 1; size--) {
        // Максимальный элемент
        int maxIndex = 0;
        for (int i = 1; i < size; i++) {
            if (pancakes[i] > pancakes[maxIndex]) {
                maxIndex = i;
            }
        }

        // Если максимальный элемент не снизу, то переворачиваем
        if (maxIndex != size - 1) {
            // Сначала переворачиваем до максимального
            if (maxIndex != 0) {
                cout << "Переворачиваем до оладья " << (maxIndex + 1) << endl;
                flip(pancakes, maxIndex);
            }

            // Переворачиваем всю стопку
            cout << "Переворачиваем все " << size << " оладий\n";
            flip(pancakes, size - 1);
        }
    }

    cout << "\nОтсортированная стопка (снизу вверх по убыванию): ";
    for (int i = p - 1; i >= 0; i--) {
        cout << pancakes[i] << " ";
    }
    cout << endl;

    // Заданиеи 4
    cout << "\n\nЗадание 4.\n\n";

    cout << "Тестировка 10 массивов по 1000 элементов\n\n";

    srand(time(0));
    const int ARRAY_SIZE = 1000;
    const int NUM_TESTS = 10;

    int bubbleTotal = 0;
    int selectionTotal = 0;

    for (int test = 1; test <= NUM_TESTS; test++) {
        int* arr1 = new int[ARRAY_SIZE];
        int* arr2 = new int[ARRAY_SIZE];

        // Заполнение случайными числами
        for (int i = 0; i < ARRAY_SIZE; i++) {
            int num = rand() % 10000;
            arr1[i] = num;
            arr2[i] = num;
        }

        // Пузырьковая сортировка
        int bubbleSwaps = 0;
        for (int i = 0; i < ARRAY_SIZE - 1; i++) {
            swapped = false;

            for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
                if (arr1[j] > arr1[j + 1]) {
                    int temp = arr1[j];
                    arr1[j] = arr1[j + 1];
                    arr1[j + 1] = temp;
                    bubbleSwaps++;
                    swapped = true;
                }
            }

            if (!swapped) break;
        }
        bubbleTotal += bubbleSwaps;

        // Сортировка выбором
        int selectionSwaps = 0;
        for (int i = 0; i < ARRAY_SIZE - 1; i++) {
            int minIndex = i;

            for (int j = i + 1; j < ARRAY_SIZE; j++) {
                if (arr2[j] < arr2[minIndex]) {
                    minIndex = j;
                }
            }

            if (minIndex != i) {
                int temp = arr2[i];
                arr2[i] = arr2[minIndex];
                arr2[minIndex] = temp;
                selectionSwaps++;
            }
        }
        selectionTotal += selectionSwaps;

        delete[] arr1;
        delete[] arr2;

        cout << "Тест " << test << ": ";
        cout << "Пузырьковая = " << bubbleSwaps << ", ";
        cout << "Выбором = " << selectionSwaps << endl;
    }

    cout << "\nРЕЗУЛЬТАТЫ:\n";
    cout << "Среднее число перестановок:\n";
    cout << "- Пузырьковая сортировка: " << (double)bubbleTotal / NUM_TESTS << endl;
    cout << "- Сортировка выбором: " << (double)selectionTotal / NUM_TESTS << endl;

    if (bubbleTotal < selectionTotal) {
        cout << "Пузырьковая сортировка эффективнее (меньше перестановок)\n";
    }
    else if (bubbleTotal > selectionTotal) {
        cout << "Сортировка выбором эффективнее (меньше перестановок)\n";
    }
    else {
        cout << "Обе сортировки одинаково эффективны\n";
    }

    return 0;
}