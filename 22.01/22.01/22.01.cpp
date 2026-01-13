#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    //1.1
    cout << "1.1 Сложение двух чисел" << endl;
    int a, b;
    cout << "Введите два числа: ";
    cin >> a >> b;
    cout << a << " + " << b << " = " << a + b << endl << endl;

    //1.2
    cout << "1.2 Цельсий в Фаренгейт" << endl;
    float C;
    cout << "Введите градусы Цельсия: ";
    cin >> C;
    float F = C * 9.0 / 5.0 + 32;
    cout << C << "°C = " << F << "°F" << endl << endl;

    //2.1
    cout << "2.1 Четное или нечетное" << endl;
    int num;
    cout << "Введите число: ";
    cin >> num;
    if (num % 2 == 0)
        cout << num << " - четное" << endl;
    else
        cout << num << " - нечетное" << endl;
    cout << endl;

    //2.2
    cout << "2.2 Высокосный год" << endl;
    int year;
    cout << "Введите год: ";
    cin >> year;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        cout << year << " - высокосный" << endl;
    else
        cout << year << " - не высокосный" << endl;
    cout << endl;

    //3.1
    cout << "3.1 Сумма от 1 до N" << endl;
    int N;
    cout << "Введите N: ";
    cin >> N;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += i;
    }
    cout << "Сумма от 1 до " << N << " = " << sum << endl << endl;

    // 3.2 Таблица умножения
    cout << "3.2 Таблица умножения" << endl;
    int m;
    cout << "Введите число: ";
    cin >> m;
    for (int i = 1; i <= 10; i++) {
        cout << m << " x " << i << " = " << m * i << endl;
    }
    cout << endl;

    // 4.1
    cout << "4.1 Минимальный элемент массива" << endl;
    int arr1[10];
    cout << "Введите 10 чисел: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr1[i];
    }
    int min = arr1[0];
    for (int i = 1; i < 10; i++) {
        if (arr1[i] < min) min = arr1[i];
    }
    cout << "Минимальный элемент: " << min << endl << endl;

    // 4.2 
    cout << "4.2 Сумма строк матрицы" << endl;
    int matrix[3][3];
    cout << "Введите 9 чисел для матрицы 3x3: ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        int row_sum = 0;
        for (int j = 0; j < 3; j++) {
            row_sum += matrix[i][j];
        }
        cout << "Сумма строки " << i + 1 << ": " << row_sum << endl;
    }
    cout << endl;

    // 5.1
    cout << "5.1 Функция max" << endl;
    int x, y;
    cout << "Введите два числа: ";
    cin >> x >> y;

    int maximum;
    if (x > y) maximum = x;
    else maximum = y;
    cout << "Максимум: " << maximum << endl << endl;

    // 5.2
    cout << "5.2 Простое число" << endl;
    int prime_num;
    cout << "Введите число: ";
    cin >> prime_num;
    bool is_prime = true;
    if (prime_num <= 1) is_prime = false;
    else {
        for (int i = 2; i <= sqrt(prime_num); i++) {
            if (prime_num % i == 0) {
                is_prime = false;
                break;
            }
        }
    }
    if (is_prime) cout << prime_num << " - простое" << endl;
    else cout << prime_num << " - не простое" << endl;
    cout << endl;

    // 6.1
    cout << "6.1 Обмен через указатели" << endl;
    int p = 10, q = 20;
    cout << "До: p = " << p << ", q = " << q << endl;
    int* ptr1 = &p;
    int* ptr2 = &q;
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    cout << "После: p = " << p << ", q = " << q << endl << endl;

    // 6.2
    cout << "6.2 Сумма массива через указатели" << endl;
    int arr2[5] = { 1, 2, 3, 4, 5 };
    int* ptr = arr2;
    int array_sum = 0;
    for (int i = 0; i < 5; i++) {
        array_sum += *(ptr + i);
    }
    cout << "Сумма массива: " << array_sum << endl << endl;

    // 7.1
    cout << "7.1 Длина строки" << endl;
    char str[100];
    cout << "Введите строку: ";
    cin.ignore();// очистка буфера
    cin.getline(str, 100);
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    cout << "Длина строки: " << length << endl << endl;

    // 7.2
    cout << "7.2 Подсчет гласных" << endl;
    char str2[100];
    cout << "Введите строку: ";
    cin.getline(str2, 100);
    int vowels = 0;
    for (int i = 0; str2[i] != '\0'; i++) {
        char ch = tolower(str2[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'а' || ch == 'е' || ch == 'и' || ch == 'о' || ch == 'у') {
            vowels++;
        }
    }
    cout << "Количество гласных: " << vowels << endl << endl;

    // 8.1
    cout << "8.1 Среднее арифметическое" << endl;
    int arr3[5];
    cout << "Введите 5 чисел: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr3[i];
    }
    float avg_sum = 0;
    for (int i = 0; i < 5; i++) {
        avg_sum += arr3[i];
    }
    cout << "Среднее: " << avg_sum / 5 << endl << endl;

    return 0;
}