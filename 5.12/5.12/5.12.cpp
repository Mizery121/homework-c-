#include <stdio.h>
#include <iostream>

#define SIZE 5  // Размер массива 

int main() {
    setlocale(LC_ALL, "RU");
    // Исходный массив
    int arr1[SIZE] = { 1, 2, 3, 4, 5 };

    printf("Исходный массив: ");
    for (int i = 0; i < SIZE; i++) printf("%d ", arr1[i]);
    printf("\n\n");

    //задание 1. Копирование массива
    int arr2[SIZE];
    int* p1 = arr1;
    int* p2 = arr2;

    // Копирование с использованием арифметики указателей
    for (int i = 0; i < SIZE; i++) {
        *(p2 + i) = *(p1 + i);
    }

    printf("Задание 1 - Копия массива: ");
    for (int i = 0; i < SIZE; i++) printf("%d ", arr2[i]);
    printf("\n");

    // задание 2. Реверс массива
    int arr3[SIZE];
    // Создание копии для реверса массива
    for (int i = 0; i < SIZE; i++) arr3[i] = arr1[i];

    int* start = arr3;
    int* end = arr3 + SIZE - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    printf("Задание 2 - Реверс массива: ");
    for (int i = 0; i < SIZE; i++) printf("%d ", arr3[i]);
    printf("\n");

    // задание 3. Копирование массива в обратном порядке
    int arr4[SIZE];
    int* src = arr1;
    int* dst = arr4 + SIZE - 1;

    // Копирование элементов в обратном порядке
    for (int i = 0; i < SIZE; i++) {
        *dst = *src;
        src++;
        dst--;
    }

    printf("Задание 3 - Копия в обратном порядке: ");
    for (int i = 0; i < SIZE; i++) printf("%d ", arr4[i]);
    printf("\n\n");

    // Вывод массивов
    printf("Итоговые массивы:\n");
    printf("Исходный:          ");
    for (int i = 0; i < SIZE; i++) printf("%d ", arr1[i]);
    printf("\n");

    printf("Копия:             ");
    for (int i = 0; i < SIZE; i++) printf("%d ", arr2[i]);
    printf("\n");

    printf("Реверс:            ");
    for (int i = 0; i < SIZE; i++) printf("%d ", arr3[i]);
    printf("\n");

    printf("Копия с реверсом:  ");
    for (int i = 0; i < SIZE; i++) printf("%d ", arr4[i]);
    printf("\n");

    return 0;
}