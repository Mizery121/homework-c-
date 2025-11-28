#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    //ЗАДАНИЕ 1
    cout << "=== ЗАДАНИЕ 1 ===" << endl;
    double arr[] = { -5.7, 6.0, 2, 0, -4.7, 6, 8.1, -4 };
    int size = 8;

    double last_positive = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] > 0) {
            last_positive = arr[i];
            break;
        }
    }

    double first_negative = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            first_negative = arr[i];
            break;
        }
    }

    cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Последнее положительное: " << last_positive << endl;
    cout << "Первое отрицательное: " << first_negative << endl << endl;

    //ЗАДАНИЕ 2
    cout << "=== ЗАДАНИЕ 2 ===" << endl;
    int residents[10];

    cout << "Введите количество жильцов для 10 квартир:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Квартира " << (i + 1) << ": ";
        cin >> residents[i];
    }

    //Поиск по номеру квартиры
    int apartment;
    cout << "Введите номер квартиры (1-10): ";
    cin >> apartment;
    cout << "Жильцов в квартире " << apartment << ": " << residents[apartment - 1] << endl;

    //Сумма по подъездам(2 подъезда по 5 квартир)
    cout << "Жильцов в подъезде 1: ";
    int sum1 = 0;
    for (int i = 0; i < 5; i++) {
        sum1 += residents[i];
    }
    cout << sum1 << endl;

    cout << "Жильцов в подъезде 2: ";
    int sum2 = 0;
    for (int i = 5; i < 10; i++) {
        sum2 += residents[i];
    }
    cout << sum2 << endl;

    //Многодетные семьи
    cout << "Многодетные семьи: ";
    for (int i = 0; i < 10; i++) {
        if (residents[i] > 5) {
            cout << "кв." << (i + 1) << " ";
        }
    }
    cout << endl << endl;

    //ЗАДАНИЕ 3
    cout << "=== ЗАДАНИЕ 3 ===" << endl;
    double temp[10];

    cout << "Введите температуру за 10 дней:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "День " << (i + 1) << ": ";
        cin >> temp[i];
    }

    //Средняя температура
    double sum_temp = 0;
    for (int i = 0; i < 10; i++) {
        sum_temp += temp[i];
    }
    cout << "Средняя температура: " << (sum_temp / 10) << endl;

    //Дни ниже указанной температуры
    double limit;
    cout << "Введите пороговую температуру: ";
    cin >> limit;

    int cold_days = 0;
    for (int i = 0; i < 10; i++) {
        if (temp[i] < limit) {
            cold_days++;
        }
    }
    cout << "Дней ниже " << limit << ": " << cold_days << endl << endl;

    //ЗАДАНИЕ 4
    cout << "=== ЗАДАНИЕ 4 ===" << endl;
    double cars[10];

    cout << "Введите стоимость 10 автомобилей:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Автомобиль " << (i + 1) << ": ";
        cin >> cars[i];
    }

    //максимальная стоимость
    double max_price = cars[0];
    for (int i = 1; i < 10; i++) {
        if (cars[i] > max_price) {
            max_price = cars[i];
        }
    }

    cout << "Максимальная стоимость: " << max_price << endl;

    //первый автомобиль с максимальной ценой
    for (int i = 0; i < 10; i++) {
        if (cars[i] == max_price) {
            cout << "Первый самый дорогой: автомобиль " << (i + 1) << endl;
            break;
        }
    }

    //последний автомобиль с максимальной ценой
    for (int i = 9; i >= 0; i--) {
        if (cars[i] == max_price) {
            cout << "Последний самый дорогой: автомобиль " << (i + 1) << endl;
            break;
        }
    }
    cout << endl;

    //ЗАДАНИЕ 5
    cout << "=== ЗАДАНИЕ 5 ===" << endl;
    int numbers[10];

    cout << "Введите 10 чисел:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Число " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    cout << "Повторяющиеся числа: ";
    bool found_duplicates = false;
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (numbers[i] == numbers[j]) {
                cout << numbers[i] << " ";
                found_duplicates = true;
                break;
            }
        }
    }
    if (!found_duplicates) {
        cout << "нет";
    }
    cout << endl << endl;

    //ЗАДАНИЕ 6
    cout << "=== ЗАДАНИЕ 6 ===" << endl;
    int A[10], B[10], X[20];

    cout << "Массив A: ";
    for (int i = 0; i < 10; i++) {
        A[i] = i + 1;  //заполнение от 1 до 10
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Массив B: ";
    for (int i = 0; i < 10; i++) {
        B[i] = i + 11; //заполнение от 11 до 20
        cout << B[i] << " ";
    }
    cout << endl;

    //Чередование
    cout << "Чередование: ";
    for (int i = 0; i < 10; i++) {
        X[2 * i] = A[i];
        X[2 * i + 1] = B[i];
    }
    for (int i = 0; i < 20; i++) {
        cout << X[i] << " ";
    }
    cout << endl;

    //Следование
    cout << "Следование: ";
    for (int i = 0; i < 10; i++) {
        X[i] = A[i];
        X[i + 10] = B[i];
    }
    for (int i = 0; i < 20; i++) {
        cout << X[i] << " ";
    }
    cout << endl;

    return 0;
}