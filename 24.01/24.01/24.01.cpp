#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
#include <vector>

using namespace std;

// структуры
struct CharCount {
    int letters;
    int digits;
    int spaces;
    int others;
};

// 1. Реверс строки
string reverseStringWithAlgorithm(const string& s) {
    string reversed = s;
    int n = reversed.length();
    for (int i = 0; i < n / 2; i++) {
        swap(reversed[i], reversed[n - i - 1]);
    }
    return reversed;
}

string reverseStringWithLoop(const string& s) {
    string reversed;
    for (int i = s.length() - 1; i >= 0; i--) {
        reversed += s[i];
    }
    return reversed;
}

// 2. Подсчет символов
CharCount countCharacters(const string& s) {
    CharCount count = { 0, 0, 0, 0 };

    for (char ch : s) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'а' && ch <= 'я') || (ch >= 'А' && ch <= 'Я')) {
            count.letters++;
        }
        else if (ch >= '0' && ch <= '9') {
            count.digits++;
        }
        else if (ch == ' ') {
            count.spaces++;
        }
        else {
            count.others++;
        }
    }
    return count;
}

// 3. Удаление дубликатов
string removeDuplicates(const string& s) {
    string result;
    unordered_set<char> seen;

    for (char ch : s) {
        if (seen.find(ch) == seen.end()) {
            seen.insert(ch);
            result += ch;
        }
    }
    return result;
}

// 4. Проверка префикса и суффикса
bool startsWith(const string& s, const string& prefix) {
    if (prefix.length() > s.length()) return false;

    for (size_t i = 0; i < prefix.length(); i++) {
        if (s[i] != prefix[i]) return false;
    }
    return true;
}

bool endsWith(const string& s, const string& suffix) {
    if (suffix.length() > s.length()) return false;

    size_t startPos = s.length() - suffix.length();
    for (size_t i = 0; i < suffix.length(); i++) {
        if (s[startPos + i] != suffix[i]) return false;
    }
    return true;
}

// 5. Форматирование имени
string formatName(const string& fullName) {
    stringstream ss(fullName);
    string part;
    vector<string> parts;

    while (ss >> part) {
        parts.push_back(part);
    }

    if (parts.empty()) return "";

    string result = parts[0]; // Фамилия

    if (parts.size() > 1) {
        result += " ";
        for (size_t i = 1; i < parts.size(); i++) {
            if (!parts[i].empty()) {
                result += parts[i][0];
                result += ".";
            }
        }
    }

    return result;
}


int main() {
    setlocale(LC_ALL, "RU");


    // Задание 1: Реверс строки
    cout << "\nЗадание 1: Реверс строки\n";
    cout << "Введите строку для реверса: ";
    string input;
    getline(cin, input);

    cout << "Реверс с алгоритмом: " << reverseStringWithAlgorithm(input) << endl;
    cout << "Реверс с циклом: " << reverseStringWithLoop(input) << endl;

    // Задание 2: Подсчет символов
    cout << "\nЗадание 2: Подсчет символов\n";
    cout << "Введите строку для анализа: ";
    getline(cin, input);

    CharCount count = countCharacters(input);
    cout << "Букв: " << count.letters << endl;
    cout << "Цифр: " << count.digits << endl;
    cout << "Пробелов: " << count.spaces << endl;
    cout << "Других символов: " << count.others << endl;

    // Задание 3: Удаление дубликатов
    cout << "\nЗадание 3: Удаление дубликатов\n";
    cout << "Введите строку для удаления дубликатов: ";
    getline(cin, input);

    cout << "Без дубликатов: " << removeDuplicates(input) << endl;

    // Задание 4: Проверка префикса и суффикса
    cout << "\nЗадание 4: Проверка префикса и суффикса\n";
    cout << "Введите основную строку: ";
    getline(cin, input);

    cout << "Введите префикс для проверки: ";
    string prefix;
    getline(cin, prefix);

    cout << "Введите суффикс для проверки: ";
    string suffix;
    getline(cin, suffix);

    cout << "Начинается с '" << prefix << "'? "
        << (startsWith(input, prefix) ? "true" : "false") << endl;
    cout << "Заканчивается на '" << suffix << "'? "
        << (endsWith(input, suffix) ? "true" : "false") << endl;

    // Задание 5: Форматирование имени
    cout << "\nЗадание 5: Форматирование имени\n";
    cout << "Введите полное имя (Фамилия Имя Отчество): ";
    getline(cin, input);

    cout << "Форматированное имя: " << formatName(input) << endl;

    cout << "\nПрограмма завершена\n";

    return 0;
}