#include <iostream>
#include <iomanip>

using namespace std;

// Функция для создания двумерного массива
int** createMatrix(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

// Функция для удаления двумерного массива
void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Функция для вывода матрицы
void printMatrix(int** matrix, int rows, int cols) {
    cout << "Матрица (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// Функция для заполнения матрицы значениями
void fillMatrix(int** matrix, int rows, int cols) {
    cout << "Заполните матрицу " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

// Задание 1: Добавление строки в конец
int** addRowToEnd(int** matrix, int& rows, int cols) {
    int** newMatrix = new int* [rows + 1];

    // Копируем старые строки
    for (int i = 0; i < rows; i++) {
        newMatrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            newMatrix[i][j] = matrix[i][j];
        }
    }

    // Добавляем новую строку
    newMatrix[rows] = new int[cols];
    cout << "Введите значения для новой строки в конце (" << cols << " чисел): ";
    for (int j = 0; j < cols; j++) {
        cin >> newMatrix[rows][j];
    }

    // Удаляем старую матрицу
    deleteMatrix(matrix, rows);

    rows++;
    return newMatrix;
}

// Задание 2: Добавление строки в начало
int** addRowToBeginning(int** matrix, int& rows, int cols) {
    int** newMatrix = new int* [rows + 1];

    // Добавляем новую строку в начало
    newMatrix[0] = new int[cols];
    cout << "Введите значения для новой строки в начале (" << cols << " чисел): ";
    for (int j = 0; j < cols; j++) {
        cin >> newMatrix[0][j];
    }

    // Копируем старые строки со смещением
    for (int i = 0; i < rows; i++) {
        newMatrix[i + 1] = new int[cols];
        for (int j = 0; j < cols; j++) {
            newMatrix[i + 1][j] = matrix[i][j];
        }
    }

    // Удаляем старую матрицу
    deleteMatrix(matrix, rows);

    rows++;
    return newMatrix;
}

// Задание 3: Добавление строки в указанную позицию
int** addRowAtPosition(int** matrix, int& rows, int cols, int position) {
    if (position < 1 || position > rows + 1) {
        cout << "Ошибка: позиция должна быть от 1 до " << rows + 1 << endl;
        return matrix;
    }

    int** newMatrix = new int* [rows + 1];

    // Копируем строки до позиции
    for (int i = 0; i < position - 1; i++) {
        newMatrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            newMatrix[i][j] = matrix[i][j];
        }
    }

    // Добавляем новую строку
    newMatrix[position - 1] = new int[cols];
    cout << "Введите значения для новой строки в позиции " << position << " (" << cols << " чисел): ";
    for (int j = 0; j < cols; j++) {
        cin >> newMatrix[position - 1][j];
    }

    // Копируем оставшиеся строки
    for (int i = position - 1; i < rows; i++) {
        newMatrix[i + 1] = new int[cols];
        for (int j = 0; j < cols; j++) {
            newMatrix[i + 1][j] = matrix[i][j];
        }
    }

    // Удаляем старую матрицу
    deleteMatrix(matrix, rows);

    rows++;
    return newMatrix;
}

// Задание 4: Удаление строки по указанному номеру
int** deleteRowAtPosition(int** matrix, int& rows, int cols, int position) {
    if (rows <= 1) {
        cout << "Ошибка: нельзя удалить строку, в матрице всего одна строка!" << endl;
        return matrix;
    }

    if (position < 1 || position > rows) {
        cout << "Ошибка: позиция должна быть от 1 до " << rows << endl;
        return matrix;
    }

    int** newMatrix = new int* [rows - 1];

    int newIndex = 0;
    for (int i = 0; i < rows; i++) {
        if (i != position - 1) { // Пропускаем удаляемую строку
            newMatrix[newIndex] = new int[cols];
            for (int j = 0; j < cols; j++) {
                newMatrix[newIndex][j] = matrix[i][j];
            }
            newIndex++;
        }
    }

    // Удаляем старую матрицу
    deleteMatrix(matrix, rows);

    rows--;
    return newMatrix;
}

int main() {
    setlocale(LC_ALL, "RU");

    // Создание исходной матрицы
    int rows, cols;
    cout << "Введите размеры исходной матрицы:\n";
    cout << "Количество строк: ";
    cin >> rows;
    cout << "Количество столбцов: ";
    cin >> cols;

    int** matrix = createMatrix(rows, cols);
    fillMatrix(matrix, rows, cols);

    cout << "\nИсходная матрица: " << endl;
    printMatrix(matrix, rows, cols);

    // Задание 1: Добавление строки в конец
    cout << "\nЗадание 1: Добавление строки в конец" << endl;
    matrix = addRowToEnd(matrix, rows, cols);
    cout << "Результат после добавления строки в конец:" << endl;
    printMatrix(matrix, rows, cols);

    // Задание 2: Добавление строки в начало
    cout << "\nЗадание 2: Добавление строки в начало" << endl;
    matrix = addRowToBeginning(matrix, rows, cols);
    cout << "Результат после добавления строки в начало:" << endl;
    printMatrix(matrix, rows, cols);

    // Задание 3: Добавление строки в указанную позицию
    cout << "\nЗадание 3: Добавление строки в указанную позицию" << endl;
    int position;
    cout << "Введите позицию для добавления строки (1-" << rows + 1 << "): ";
    cin >> position;
    matrix = addRowAtPosition(matrix, rows, cols, position);
    cout << "Результат после добавления строки в позицию " << position << ":" << endl;
    printMatrix(matrix, rows, cols);

    // Задание 4: Удаление строки по указанному номеру
    cout << "\nЗадание 4: Удаление строки по указанному номеру" << endl;
    cout << "Введите номер строки для удаления (1-" << rows << "): ";
    cin >> position;
    matrix = deleteRowAtPosition(matrix, rows, cols, position);
    cout << "Результат после удаления строки " << position << ":" << endl;
    printMatrix(matrix, rows, cols);

    // Очистка памяти
    deleteMatrix(matrix, rows);

    return 0;
}