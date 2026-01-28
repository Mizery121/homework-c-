#include <iostream>
#include <cstring>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    // Задание 1. Удалить символ с заданным номером
    {
        char str[100];
        cout << "Введите строку: ";
        cin.getline(str, 100);

        int index;
        cout << "Введите номер символа для удаления: ";
        cin >> index;
        cin.ignore();

        // Удаляем символ
        int len = strlen(str);
        for (int i = index; i < len; i++) {
            str[i] = str[i + 1];
        }

        cout << "Результат задания 1: " << str << endl;
    }

    // Задание 2: Удалить все вхождения символа
    {
        char str[100];
        cout << "\nВведите строку: ";
        cin.getline(str, 100);

        char ch;
        cout << "Введите символ для удаления: ";
        cin >> ch;
        cin.ignore();

        // Удаляем все вхождения
        int j = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] != ch) {
                str[j] = str[i];
                j++;
            }
        }
        str[j] = '\0';

        cout << "Результат задания 2: " << str << endl;
    }

    // Задание 3: Вставить символ в указанную позицию
    {
        char str[100];
        cout << "\nВведите строку: ";
        cin.getline(str, 100);

        int pos;
        char ch;
        cout << "Введите позицию и символ: ";
        cin >> pos >> ch;
        cin.ignore();

        int len = strlen(str);

        // Сдвигаем символы вправо
        for (int i = len; i >= pos; i--) {
            str[i + 1] = str[i];
        }

        // Вставляем символ
        str[pos] = ch;

        cout << "Результат задания 3: " << str << endl;
    }

    // Задание 4: Заменить все точки на восклицательные знаки
    {
        char str[100];
        cout << "\nВведите строку: ";
        cin.getline(str, 100);

        // Заменяем точки на восклицательные знаки
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '.') {
                str[i] = '!';
            }
        }

        cout << "Результат задания 4: " << str << endl;
    }

    // Задание 5: Подсчитать сколько раз символ встречается в строке
    {
        char str[100];
        cout << "\nВведите строку: ";
        cin.getline(str, 100);

        char ch;
        cout << "Введите искомый символ: ";
        cin >> ch;
        cin.ignore();

        // Считаем количество вхождений
        int count = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == ch) {
                count++;
            }
        }

        cout << "Результат задания 5: символ '" << ch << "' встречается " << count << " раз(а)" << endl;
    }

    // Задание 6: Подсчитать количество букв, цифр и других символов
    {
        char str[100];
        cout << "\nВведите строку: ";
        cin.getline(str, 100);

        int letters = 0, digits = 0, others = 0;

        for (int i = 0; str[i] != '\0'; i++) {
            if ((str[i] >= 'a' && str[i] <= 'z') ||
                (str[i] >= 'A' && str[i] <= 'Z')) {
                letters++;
            }
            else if (str[i] >= '0' && str[i] <= '9') {
                digits++;
            }
            else {
                others++;
            }
        }

        cout << "Результат задания 6:" << endl;
        cout << "Букв: " << letters << endl;
        cout << "Цифр: " << digits << endl;
        cout << "Других символов: " << others << endl;
    }

    return 0;
}