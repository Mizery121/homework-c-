#include <iostream>
#include <iomanip>
using namespace std;


// 1. Пузырьковая сортировка
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 2. Сортировка вставками
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 4. Быстрая сортировка
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            // Обмен элементов
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Обмен элемента
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//Функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функция для копирования массива
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Задание 3
const int NUM_GRADES = 10;

void inputGrades(int grades[]) {
    cout << "Введите 10 оценок студента (1-12):" << endl;
    for (int i = 0; i < NUM_GRADES; i++) {
        bool valid = false;
        while (!valid) {
            cout << "Оценка " << i + 1 << ": ";
            cin >> grades[i];
            if (grades[i] >= 1 && grades[i] <= 12) {
                valid = true;
            }
            else {
                cout << "Ошибка, оценка должна быть от 1 до 12" << endl;
            }
        }
    }
}

void printGrades(int grades[]) {
    cout << "Оценки студента: ";
    for (int i = 0; i < NUM_GRADES; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;
}

void retakeExam(int grades[]) {
    int index, newGrade;
    cout << "Введите номер оценки для пересдачи (1-" << NUM_GRADES << "): ";
    cin >> index;

    if (index < 1 || index > NUM_GRADES) {
        cout << "Неверный номер оценки!" << endl;
        return;
    }

    bool valid = false;
    while (!valid) {
        cout << "Введите новую оценку (1-12): ";
        cin >> newGrade;

        if (newGrade >= 1 && newGrade <= 12) {
            valid = true;
            grades[index - 1] = newGrade;
            cout << "Оценка успешно обновлена!" << endl;
        }
        else {
            cout << "Оценка должна быть в диапазоне 1-12!" << endl;
        }
    }
}

void checkScholarship(int grades[]) {
    double sum = 0;
    for (int i = 0; i < NUM_GRADES; i++) {
        sum += grades[i];
    }
    double average = sum / NUM_GRADES;

    cout << fixed << setprecision(2);
    cout << "Средний балл: " << average << endl;

    if (average >= 10.7) {
        cout << "Поздравляем! Стипендия выходит!" << endl;
    }
    else {
        cout << "К сожалению, стипендия не выходит." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    // 1.Пузырьковая сортировка
    cout << "1.Пузырьковая сортировка" << endl;
    int arr1[] = { 64, 34, 25, 12, 22, 11, 90, 5, 42, 18 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Исходный массив: ";
    printArray(arr1, n1);

    // Создание копии для сортировки
    int arr1_copy[10];
    copyArray(arr1, arr1_copy, n1);
    bubbleSort(arr1_copy, n1);

    cout << "После пузырьковой сортировки: ";
    printArray(arr1_copy, n1);
    cout << endl;

    // 2.Сортировка вставками
    cout << "2.Сортировка вставками" << endl;
    int arr2[] = { 64, 34, 25, 12, 22, 11, 90, 5, 42, 18 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Исходный массив: ";
    printArray(arr2, n2);

    // Создание копии для сортировки
    int arr2_copy[10];
    copyArray(arr2, arr2_copy, n2);
    insertionSort(arr2_copy, n2);

    cout << "После сортировки вставками: ";
    printArray(arr2_copy, n2);
    cout << endl;

    // 3.Успеваемость
    cout << "3.Успеваемость студента" << endl;

    int grades[NUM_GRADES];

    inputGrades(grades);
    cout << endl;

    printGrades(grades);
    cout << endl;

    // Пересдача экзамена
    cout << "Пример пересдачи экзамена:" << endl;
    retakeExam(grades);
    cout << endl;

    // Вывод обновленных оценок
    cout << "Обновленные оценки: ";
    printGrades(grades);
    cout << endl;

    // Проверка стипендии
    cout << "Проверка стипендии:" << endl;
    checkScholarship(grades);
    cout << endl;

    // 4.Быстрая сортировка
    cout << "4.Быстрая сортировка" << endl;
    int arr4[] = { 64, 34, 25, 12, 22, 11, 90, 5, 42, 18, 33, 77, 19, 8 };
    int n4 = sizeof(arr4) / sizeof(arr4[0]);

    cout << "Исходный массив: ";
    printArray(arr4, n4);

    // Создание копии для сортировки
    int arr4_copy[14];
    copyArray(arr4, arr4_copy, n4);
    quickSort(arr4_copy, 0, n4 - 1);

    cout << "После быстрой сортировки: ";
    printArray(arr4_copy, n4);
    cout << endl;

    // Демонстрация всех сортировок на одном массиве
    cout << "=== Сравнение всех методов сортировки:" << endl;

    int demoArray[] = { 45, 23, 67, 12, 89, 34, 56, 78, 90, 21 };
    int demoSize = sizeof(demoArray) / sizeof(demoArray[0]);

    cout << "Исходный массив для сравнения: ";
    printArray(demoArray, demoSize);

    // Копии массива для разных сортировок
    int bubbleCopy[10];
    int insertionCopy[10];
    int quickCopy[10];

    copyArray(demoArray, bubbleCopy, demoSize);
    copyArray(demoArray, insertionCopy, demoSize);
    copyArray(demoArray, quickCopy, demoSize);

    // Пузырьковая сортировка
    bubbleSort(bubbleCopy, demoSize);
    cout << "Пузырьковая сортировка:       ";
    printArray(bubbleCopy, demoSize);

    // Сортировка вставками
    insertionSort(insertionCopy, demoSize);
    cout << "Сортировка вставками:         ";
    printArray(insertionCopy, demoSize);

    // Быстрая сортировка
    quickSort(quickCopy, 0, demoSize - 1);
    cout << "Быстрая сортировка:           ";
    printArray(quickCopy, demoSize);


    return 0;
}