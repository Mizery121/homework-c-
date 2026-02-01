#include <iostream>
using namespace std;

// Макросы
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define SQUARE(x) ((x) * (x))
#define POWER(base, exp) (pow_helper(base, exp))
#define IS_EVEN(n) (((n) % 2 == 0) ? 1 : 0)
#define IS_ODD(n) (((n) % 2 != 0) ? 1 : 0)

// Вспомогательная функция для возведения в степень
int pow_helper(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "RU");

    // 1. Нахождение меньшего из двух чисел
    cout << "\n1. Нахождение меньшего из двух чисел" << endl;
    int a, b;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    cout << "MIN(" << a << ", " << b << ") = " << MIN(a, b) << endl;

    // 2. Нахождение большего из двух чисел
    cout << "\n2. Нахождение большего из двух чисел" << endl;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    cout << "MAX(" << a << ", " << b << ") = " << MAX(a, b) << endl;

    // 3. Возведение числа в квадрат
    cout << "\n3. Возведение числа в квадрат" << endl;
    int x;
    cout << "Введите число: ";
    cin >> x;
    cout << "SQUARE(" << x << ") = " << SQUARE(x) << endl;

    // 4. Возведение числа в степень
    cout << "\n4. Возведение числа в степень" << endl;
    int base, exp;
    cout << "Введите основание: ";
    cin >> base;
    cout << "Введите показатель степени: ";
    cin >> exp;
    cout << "POWER(" << base << ", " << exp << ") = " << POWER(base, exp) << endl;

    // 5. Проверка числа на четность
    cout << "\n5. Проверка числа на четность" << endl;
    int n;
    cout << "Введите число: ";
    cin >> n;
    cout << "IS_EVEN(" << n << ") = " << (IS_EVEN(n) ? "четное" : "нечетное") << endl;

    // 6. Проверка числа на нечетность
    cout << "\n6. Проверка числа на нечетность" << endl;
    cout << "Введите число: ";
    cin >> n;
    cout << "IS_ODD(" << n << ") = " << (IS_ODD(n) ? "нечетное" : "четное") << endl;

    cout << "\nПример проблемы с MIN и инкрементом:" << endl;
    int i = 5, j = 10;
    cout << "Исходные значения: i = " << i << ", j = " << j << endl;
    int result = MIN(++i, ++j);
    cout << "После MIN(++i, ++j): i = " << i << ", j = " << j << ", результат = " << result << endl;
    cout << "Инкремент выполнился дважды для одного из значений!" << endl;

    cout << "\nПример проблемы с SQUARE и инкрементом:" << endl;
    i = 3;
    cout << "Исходное значение: i = " << i << endl;
    result = SQUARE(++i);
    cout << "После SQUARE(++i): i = " << i << ", результат = " << result << endl;
    cout << "Ожидалось 4^2 = 16, но получилось другое значение!" << endl;

    return 0;
}