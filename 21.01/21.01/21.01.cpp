#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <typeinfo>
#include <algorithm>

using namespace std;


// Функции калькулятора
int sum(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int division(int a, int b) {
    if (b == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        return 0;
    }
    return a / b;
}

// Компараторы для сортировки
bool ascending(int a, int b) { return a > b; }
bool descending(int a, int b) { return a < b; }

// Функции для интегрирования
double square(double x) { return x * x; }

// Функции для меню
void openFile() { cout << "Файл открыт!" << endl; }
void saveFile() { cout << "Файл сохранен!" << endl; }
void editFile() { cout << "Редактирование файла..." << endl; }
void printFile() { cout << "Печать файла..." << endl; }
void exitMenu() { cout << "Выход из меню!" << endl; }

// Шаблон сложения
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) { return a + b; }

// Функция для сложного указателя
double exampleFunc(int x) { return x * 2.5; }
double (*getFuncPtr1())(int) { return exampleFunc; }
auto getFuncPtr2() -> double (*)(int) { return exampleFunc; }
using FuncPtr = double (*)(int);
FuncPtr getFuncPtr3() { return exampleFunc; }


void bubbleSort(int arr[], int size, bool (*comp)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (comp(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

double integrate(double a, double b, int n, double (*func)(double)) {
    double h = (b - a) / n, sum = 0.0;
    for (int i = 0; i < n; i++) sum += func(a + (i + 0.5) * h);
    return sum * h;
}


void task1_1() {
    cout << "\n1. КАЛЬКУЛЯТОР \n" << string(40, '=') << endl;

    int num1, num2;
    char op;
    int (*operation)(int, int);

    cout << "Введите первое число: "; cin >> num1;
    cout << "Введите второе число: "; cin >> num2;
    cout << "Введите операцию (+, -, *, /): "; cin >> op;

    switch (op) {
    case '+': operation = sum; break;
    case '-': operation = sub; break;
    case '*': operation = mul; break;
    case '/': operation = division; break;
    default: cout << "Неизвестная операция!" << endl; return;
    }

    cout << num1 << " " << op << " " << num2 << " = " << operation(num1, num2) << endl;
}

void task1_2() {
    cout << "\n2. СРАВНЕНИЕ СТРОК\n" << string(25, '=') << endl;

    char str1[100], str2[100];
    int (*compare)(const char*, const char*) = strcmp;

    cout << "Введите первую строку: ";
    cin.ignore(); cin.getline(str1, 100);
    cout << "Введите вторую строку: ";
    cin.getline(str2, 100);

    int result = compare(str1, str2);
    cout << "Результат: ";
    if (result < 0) cout << "первая строка меньше второй" << endl;
    else if (result > 0) cout << "первая строка больше второй" << endl;
    else cout << "строки равны" << endl;
}

void task2_1() {
    cout << "\n3. СОРТИРОВКА С КОМПАРАТОРОМ\n" << string(35, '=') << endl;

    int size;
    cout << "Введите размер массива: "; cin >> size;
    int* arr = new int[size];
    int* arr2 = new int[size];

    cout << "Введите " << size << " чисел через пробел: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }

    bubbleSort(arr, size, ascending);
    cout << "По возрастанию: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    bubbleSort(arr2, size, descending);
    cout << "По убыванию: ";
    for (int i = 0; i < size; i++) cout << arr2[i] << " ";
    cout << endl;

    delete[] arr;
    delete[] arr2;
}

void task2_2() {
    cout << "\n4. ЧИСЛЕННОЕ ИНТЕГРИРОВАНИЕ\n" << string(35, '=') << endl;

    double a, b;
    int n;
    cout << "Введите начало интервала: "; cin >> a;
    cout << "Введите конец интервала: "; cin >> b;
    cout << "Введите количество разбиений: "; cin >> n;

    cout << "\nИнтеграл sin(x) от " << a << " до " << b << ":" << endl;
    cout << "Метод прямоугольников: " << integrate(a, b, n, sin) << endl;

    cout << "\nИнтеграл x^2 от " << a << " до " << b << ":" << endl;
    cout << "Метод прямоугольников: " << integrate(a, b, n, square) << endl;
}

void task3_1() {
    cout << "\n5. МЕНЮ ДЕЙСТВИЙ\n" << string(20, '=') << endl;

    void (*menuActions[])() = { openFile, saveFile, editFile, printFile, exitMenu };
    const char* menuItems[] = {
        "1. Открыть файл", "2. Сохранить файл", "3. Редактировать файл",
        "4. Печать файла", "5. Выход"
    };

    int choice;
    do {
        cout << "\nМеню:" << endl;
        for (int i = 0; i < 5; i++) cout << menuItems[i] << endl;
        cout << "Выберите действие (1-5): "; cin >> choice;

        if (choice >= 1 && choice <= 5) menuActions[choice - 1]();
        else cout << "Неверный выбор!" << endl;
    } while (choice != 5);
}

void task4_1() {
    cout << "\n6. УПРОЩЕНИЕ ИТЕРАТОРОВ\n" << string(30, '=') << endl;

    vector<int> vec = { 1, 2, 3, 4, 5 };

    cout << "С auto: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) cout << *it << " ";
    cout << "\nRange-based for: ";
    for (auto x : vec) cout << x << " ";
    cout << endl;
}

void task4_2() {
    cout << "\n7. TИП РЕЗУЛЬТАТА ВЫРАЖЕНИЯ\n" << string(35, '=') << endl;

    int a; double b;
    cout << "Введите целое число: "; cin >> a;
    cout << "Введите вещественное число: "; cin >> b;

    decltype(a * b) c1 = a * b;
    auto c2 = a * b;

    cout << "decltype(a*b): " << c1 << " (тип: " << typeid(c1).name() << ")" << endl;
    cout << "auto: " << c2 << " (тип: " << typeid(c2).name() << ")" << endl;
}

void task5_1() {
    cout << "\n8. СЛОЖЕНИЕ РАЗНЫХ ТИПОВ\n" << string(30, '=') << endl;

    int x; double y;
    cout << "Введите целое число: "; cin >> x;
    cout << "Введите вещественное число: "; cin >> y;

    cout << "add(" << x << ", " << y << ") = " << add(x, y) << endl;
    cout << "add(" << y << ", " << x << ") = " << add(y, x) << endl;
}

void task5_2() {
    cout << "\n9. УКАЗАТЕЛЬ НА ФУНКЦИЮ\n" << string(30, '=') << endl;

    int value;
    cout << "Введите число для функции: "; cin >> value;

    auto ptr1 = getFuncPtr1();
    auto ptr2 = getFuncPtr2();
    auto ptr3 = getFuncPtr3();

    cout << "Результат: " << ptr1(value) << endl;
    cout << "Все три указателя работают одинаково!" << endl;
}


int main() {
    setlocale(LC_ALL, "RU");

    task1_1();
    task1_2();
    task2_1();
    task2_2();
    task3_1();
    task4_1();
    task4_2();
    task5_1();
    task5_2();

    return 0;
}