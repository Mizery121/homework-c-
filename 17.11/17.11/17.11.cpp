#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    // 1) Прямоугольник
    int h, w;
    cout << "1. Введите высоту и ширину прямоугольника: ";
    cin >> h >> w;
    cout << "Прямоугольник " << h << "x" << w << ":\n";
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cout << "*";
        cout << endl;
    }

    // 2) Факториал
    int n;
    cout << "\n2. Введите число для факториала: ";
    cin >> n;
    int fact = 1;
    for (int i = 1; i <= n; i++) fact *= i;
    cout << "Факториал " << n << ": " << fact << endl;

    // 3) Простое число
    int num;
    cout << "\n3. Введите число для проверки на простоту: ";
    cin >> num;
    bool prime = true;
    if (num < 2) prime = false;
    else {
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                prime = false;
                break;
            }
        }
    }
    cout << num << (prime ? " простое" : " не простое") << endl;

    // 4) Куб числа
    int x;
    cout << "\n4. Введите число для возведения в куб: ";
    cin >> x;
    cout << "Куб " << x << ": " << x * x * x << endl;

    // 5) Максимум из двух
    int a, b;
    cout << "\n5. Введите два числа для сравнения: ";
    cin >> a >> b;
    cout << "Максимум " << a << " и " << b << ": " << (a > b ? a : b) << endl;

    // 6) Положительное число
    double y;
    cout << "\n6. Введите число для проверки на положительность: ";
    cin >> y;
    cout << y << (y > 0 ? " положительное" : " не положительное") << endl;

    return 0;
}