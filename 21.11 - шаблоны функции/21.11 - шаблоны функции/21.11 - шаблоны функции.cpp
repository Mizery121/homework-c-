#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// Задание 1
// Перегруженные функции для int
void initMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void findMinMaxDiagonal(int** matrix, int n) {
    int minElem = matrix[0][0];
    int maxElem = matrix[0][0];

    for (int i = 1; i < n; i++) {
        if (matrix[i][i] < minElem) minElem = matrix[i][i];
        if (matrix[i][i] > maxElem) maxElem = matrix[i][i];
    }

    cout << "Минимальный элемент на главной диагонали: " << minElem << endl;
    cout << "Максимальный элемент на главной диагонали: " << maxElem << endl;
}

void sortRows(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        sort(matrix[i], matrix[i] + n);
    }
}

// Перегруженные функции для double
void initMatrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (rand() % 1000) / 10.0;
        }
    }
}

void printMatrix(double** matrix, int n) {
    cout.precision(2);
    cout << fixed;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void findMinMaxDiagonal(double** matrix, int n) {
    double minElem = matrix[0][0];
    double maxElem = matrix[0][0];

    for (int i = 1; i < n; i++) {
        if (matrix[i][i] < minElem) minElem = matrix[i][i];
        if (matrix[i][i] > maxElem) maxElem = matrix[i][i];
    }

    cout << "Минимальный элемент на главной диагонали: " << minElem << endl;
    cout << "Максимальный элемент на главной диагонали: " << maxElem << endl;
}

void sortRows(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        sort(matrix[i], matrix[i] + n);
    }
}

// Перегруженные функции для char
void initMatrix(char** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 'A' + rand() % 26;
        }
    }
}

void printMatrix(char** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void findMinMaxDiagonal(char** matrix, int n) {
    char minElem = matrix[0][0];
    char maxElem = matrix[0][0];

    for (int i = 1; i < n; i++) {
        if (matrix[i][i] < minElem) minElem = matrix[i][i];
        if (matrix[i][i] > maxElem) maxElem = matrix[i][i];
    }

    cout << "Минимальный элемент на главной диагонали: " << minElem << endl;
    cout << "Максимальный элемент на главной диагонали: " << maxElem << endl;
}

void sortRows(char** matrix, int n) {
    for (int i = 0; i < n; i++) {
        sort(matrix[i], matrix[i] + n);
    }
}

// Функция для демонстрации работы с матрицами
void demoMatrix() {
    srand(time(0));
    int n = 4;

    // Демонстрация для int
    cout << "Матрица int:" << endl;
    int** intMatrix = new int* [n];
    for (int i = 0; i < n; i++) intMatrix[i] = new int[n];

    initMatrix(intMatrix, n);
    cout << "Исходная матрица:" << endl;
    printMatrix(intMatrix, n);
    findMinMaxDiagonal(intMatrix, n);
    sortRows(intMatrix, n);
    cout << "Матрица после сортировки строк:" << endl;
    printMatrix(intMatrix, n);

    // очискта памяти
    for (int i = 0; i < n; i++) delete[] intMatrix[i];
    delete[] intMatrix;

    cout << "\nМатрица double:" << endl;
    // Демонстрация для double
    double** doubleMatrix = new double* [n];
    for (int i = 0; i < n; i++) doubleMatrix[i] = new double[n];

    initMatrix(doubleMatrix, n);
    cout << "Исходная матрица:" << endl;
    printMatrix(doubleMatrix, n);
    findMinMaxDiagonal(doubleMatrix, n);
    sortRows(doubleMatrix, n);
    cout << "Матрица после сортировки строк:" << endl;
    printMatrix(doubleMatrix, n);

    // Очистка памяти
    for (int i = 0; i < n; i++) delete[] doubleMatrix[i];
    delete[] doubleMatrix;

    cout << "\nМатрица char:" << endl;
    // Демонстрация для char
    char** charMatrix = new char* [n];
    for (int i = 0; i < n; i++) charMatrix[i] = new char[n];

    initMatrix(charMatrix, n);
    cout << "Исходная матрица:" << endl;
    printMatrix(charMatrix, n);
    findMinMaxDiagonal(charMatrix, n);
    sortRows(charMatrix, n);
    cout << "Матрица после сортировки строк:" << endl;
    printMatrix(charMatrix, n);

    // Очистка памяти
    for (int i = 0; i < n; i++) delete[] charMatrix[i];
    delete[] charMatrix;
}

// Задание 2
// функция нахождения НОД
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void demoGCD() {
    cout << "\nНахождение НОД:" << endl;

    int a, b;
    cout << "Введите два целых числа: ";
    cin >> a >> b;

    cout << "НОД(" << a << ", " << b << ") = " << gcd(abs(a), abs(b)) << endl;
}

// Задание 3
// Функция для генерации четырехзначного числа
string generateSecretNumber() {
    string secret = "";
    set<char> usedDigits;

    while (secret.length() < 4) {
        char digit = '0' + rand() % 10;
        if (usedDigits.find(digit) == usedDigits.end()) {
            secret += digit;
            usedDigits.insert(digit);
        }
    }

    return secret;
}

// функция игры "Быки и коровы"
void bullsAndCows(string secret, int attempt = 1) {
    string guess;
    cout << "Попытка " << attempt << ". Введите четырехзначное число: ";
    cin >> guess;

    // Проверка правильности ввода
    if (guess.length() != 4 || !all_of(guess.begin(), guess.end(), ::isdigit)) {
        cout << "Ошибка, введите четырехзначное число" << endl;
        bullsAndCows(secret, attempt);
        return;
    }

    // Проверка на уникальность цифр
    set<char> digits(guess.begin(), guess.end());
    if (digits.size() != 4) {
        cout << "Ошибка, все цифры должны быть разными" << endl;
        bullsAndCows(secret, attempt);
        return;
    }

    // Подсчет быков и коров
    int bulls = 0;
    int cows = 0;

    for (int i = 0; i < 4; i++) {
        if (guess[i] == secret[i]) {
            bulls++;
        }
        else if (secret.find(guess[i]) != string::npos) {
            cows++;
        }
    }

    cout << "Быки: " << bulls << ", Коровы: " << cows << endl;

    if (bulls == 4) {
        cout << "\nПоздравляем! вы угадали число " << secret
            << " за " << attempt << " попыток!" << endl;
        return;
    }

    // Рекурсивный вызов для следующей попытки
    bullsAndCows(secret, attempt + 1);
}

void demoBullsAndCows() {
    cout << "\nИгра 'Быки и коровы' " << endl;
    cout << "Компьютер загадал четырехзначное число." << endl;
    cout << "Все цифры в числе разные." << endl;
    cout << "Быки - цифра на своем месте." << endl;
    cout << "Коровы - цифра есть в числе, но не на своем месте." << endl;

    srand(time(0));
    string secret = generateSecretNumber();
    bullsAndCows(secret);
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Задание 1
    demoMatrix();

    // Задание 2
    demoGCD();

    // Задание 3
    demoBullsAndCows();

    return 0;
}