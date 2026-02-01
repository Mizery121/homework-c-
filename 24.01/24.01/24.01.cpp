#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ЗАДАНИЕ 1: КОМПЛЕКСНЫЕ ЧИСЛА

struct Complex {
    double real;
    double imag;
};

Complex add(Complex a, Complex b) {
    return { a.real + b.real, a.imag + b.imag };
}

Complex subtract(Complex a, Complex b) {
    return { a.real - b.real, a.imag - b.imag };
}

Complex multiply(Complex a, Complex b) {
    return {
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    };
}

Complex divide(Complex a, Complex b) {
    double d = b.real * b.real + b.imag * b.imag;
    if (d == 0) {
        cout << "Ошибка деления на ноль!" << endl;
        return { 0, 0 };
    }
    return {
        (a.real * b.real + a.imag * b.imag) / d,
        (a.imag * b.real - a.real * b.imag) / d
    };
}

void showComplex(Complex c) {
    if (c.imag >= 0)
        cout << c.real << " + " << c.imag << "i";
    else
        cout << c.real << " - " << -c.imag << "i";
}

// ЗАДАНИЕ 2: АВТОМОБИЛЬ

struct Car {
    string brand;
    double length;
    double clearance;
    double engineVolume;
    double enginePower;
    double wheelDiameter;
    string color;
    string transmission;
};

vector<Car> cars;

void addCar() {
    Car c;
    cout << "\nМарка: "; cin >> c.brand;
    cout << "Длина (м): "; cin >> c.length;
    cout << "Клиренс (мм): "; cin >> c.clearance;
    cout << "Объем двигателя (л): "; cin >> c.engineVolume;
    cout << "Мощность (л.с.): "; cin >> c.enginePower;
    cout << "Диаметр колес (дюймы): "; cin >> c.wheelDiameter;
    cout << "Цвет: "; cin >> c.color;
    cout << "Коробка (механика/автомат): "; cin >> c.transmission;
    cars.push_back(c);
}

void showCars() {
    if (cars.empty()) {
        cout << "Нет автомобилей" << endl;
        return;
    }
    for (int i = 0; i < cars.size(); i++) {
        cout << "\nАвтомобиль " << i + 1 << ":" << endl;
        cout << "Марка: " << cars[i].brand << endl;
        cout << "Длина: " << cars[i].length << " м" << endl;
        cout << "Клиренс: " << cars[i].clearance << " мм" << endl;
        cout << "Объем: " << cars[i].engineVolume << " л" << endl;
        cout << "Мощность: " << cars[i].enginePower << " л.с." << endl;
        cout << "Колеса: " << cars[i].wheelDiameter << " дюймов" << endl;
        cout << "Цвет: " << cars[i].color << endl;
        cout << "Коробка: " << cars[i].transmission << endl;
    }
}

void searchCar() {
    if (cars.empty()) {
        cout << "Нет автомобилей для поиска" << endl;
        return;
    }

    cout << "\nПоиск по:" << endl;
    cout << "1. Марке" << endl;
    cout << "2. Цвету" << endl;
    cout << "3. Минимальной мощности" << endl;
    cout << "Выбор: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        string brand;
        cout << "Введите марку: "; cin >> brand;
        for (auto& c : cars) {
            if (c.brand == brand) {
                cout << "Найден: " << c.brand << ", цвет: " << c.color
                    << ", мощность: " << c.enginePower << " л.с." << endl;
            }
        }
    }
    else if (choice == 2) {
        string color;
        cout << "Введите цвет: "; cin >> color;
        for (auto& c : cars) {
            if (c.color == color) {
                cout << "Найден: " << c.brand << ", цвет: " << c.color
                    << ", мощность: " << c.enginePower << " л.с." << endl;
            }
        }
    }
    else if (choice == 3) {
        double power;
        cout << "Минимальная мощность: "; cin >> power;
        for (auto& c : cars) {
            if (c.enginePower >= power) {
                cout << "Найден: " << c.brand << ", мощность: " << c.enginePower
                    << " л.с., цвет: " << c.color << endl;
            }
        }
    }
}


int main() {
    setlocale(LC_ALL, "RU");

    // Задание 1: Комплексные числа
    cout << "\nЗадание 1: КОМПЛЕКСНЫЕ ЧИСЛА" << endl;

    Complex a, b;
    cout << "Введите первое комплексное число (действительная и мнимая часть): ";
    cin >> a.real >> a.imag;
    cout << "Введите второе комплексное число (действительная и мнимая часть): ";
    cin >> b.real >> b.imag;

    cout << "\nA = "; showComplex(a);
    cout << "\nB = "; showComplex(b);

    cout << "\n\nA + B = "; showComplex(add(a, b));
    cout << "\nA - B = "; showComplex(subtract(a, b));
    cout << "\nA * B = "; showComplex(multiply(a, b));
    cout << "\nA / B = "; showComplex(divide(a, b));
    cout << endl;

    // Задание 2: Автомобили
    cout << "\nЗадание 2: АВТОМОБИЛИ" << endl;

    // Добавление тестовых данных
    cars = {
        {"Toyota", 4.6, 160, 2.0, 150, 17, "белый", "автомат"},
        {"BMW", 4.8, 140, 3.0, 249, 18, "черный", "автомат"},
        {"Lada", 4.2, 180, 1.6, 106, 15, "красный", "механика"}
    };

    cout << "\nТестовые автомобили загружены." << endl;

    // Показать все автомобили
    cout << "\nВсе автомобили:" << endl;
    showCars();

    // Поиск автомобиля
    cout << "\nПоиск автомобилей" << endl;
    searchCar();

    // Добавление нового автомобиля
    cout << "\nДобавление нового автомобиля" << endl;
    addCar();

    // Показать обновленный список
    cout << "\nОбновленный список автомобилей" << endl;
    showCars();

    return 0;
}