#include <iostream>
#include <string>
#include <cctype> // для isalpha, isdigit и т.д.
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    cout << "=== Задание 1: Замена пробелов на табуляции ===\n";
    cout << "Введите строку: ";
    string str1;
    getline(cin, str1);

    // Заменяем пробелы на табуляции
    for (size_t i = 0; i < str1.length(); i++) {
        if (str1[i] == ' ') {
            str1[i] = '\t';
        }
    }
    cout << "Результат: " << str1 << "\n\n";

    cout << "=== Задание 2: Подсчёт символов ===\n";
    cout << "Введите строку: ";
    string str2;
    getline(cin, str2);

    int letters = 0, digits = 0, others = 0;

    for (char c : str2) {
        if (isalpha(c)) letters++;
        else if (isdigit(c)) digits++;
        else others++;
    }

    cout << "Букв: " << letters << endl;
    cout << "Цифр: " << digits << endl;
    cout << "Остальных символов: " << others << "\n\n";

    cout << "=== Задание 3: Подсчёт слов ===\n";
    cout << "Введите предложение: ";
    string str3;
    getline(cin, str3);

    int words = 0;
    bool inWord = false;

    for (char c : str3) {
        if (c == ' ' || c == '\t' || c == '\n') {
            inWord = false;
        }
        else if (!inWord) {
            words++;
            inWord = true;
        }
    }

    cout << "Количество слов: " << words << "\n\n";

    cout << "=== Задание 4: Проверка на палиндром ===\n";
    cout << "Введите строку: ";
    string str4;
    getline(cin, str4);

    // Убираем пробелы и приводим к нижнему регистру
    string cleanStr = "";
    for (char c : str4) {
        if (c != ' ') {
            cleanStr += tolower(c);
        }
    }

    // Проверяем на палиндром
    bool isPalindrome = true;
    int len = cleanStr.length();

    for (int i = 0; i < len / 2; i++) {
        if (cleanStr[i] != cleanStr[len - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "Строка является палиндромом!\n";
    }
    else {
        cout << "Строка не является палиндромом.\n";
    }

    return 0;
}