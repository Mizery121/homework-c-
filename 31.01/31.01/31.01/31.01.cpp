#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // === Задание 1 ===
    cout << "1. Подсчёт слов по первой букве\n";
    {
        // Создаём файл с русским текстом
        ofstream out("file_rus.txt");
        out << "яблоко банан абрикос ягода\n";
        out << "вишня банан финик инжир\n";
        out.close();

        string search;
        cout << "Введите первую букву (англ.): ";
        char engChar;
        cin >> engChar;
        cin.ignore();

        // Преобразуем английскую букву в русскую
        char rusChar = engChar;
        if (engChar == 'a' || engChar == 'A') rusChar = 'а';
        else if (engChar == 'b' || engChar == 'B') rusChar = 'б';
        // ... можно добавить другие буквы

        ifstream in("file_rus.txt");
        string word;
        int count = 0;

        while (in >> word) {
            if (!word.empty() && word[0] == rusChar) {
                count++;
            }
        }

        cout << "Слов, начинающихся с '" << rusChar << "': " << count << endl;
        in.close();
    }

    // === Задание 2 ===
    cout << "\n2. Замена 0 на 1 и наоборот\n";
    {
        ofstream out("input.txt");
        out << "010101\n";
        out << "Текст с 0 и 1\n";
        out << "1001 0011\n";
        out.close();

        ifstream in("input.txt");
        ofstream out2("output.txt");
        string line;

        while (getline(in, line)) {
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == '0') line[i] = '1';
                else if (line[i] == '1') line[i] = '0';
            }
            out2 << line << endl;
        }

        cout << "Результат в output.txt\n";
        in.close();
        out2.close();
    }

    // === Задание 3 ===
    cout << "\n3. Запись массива строк\n";
    {
        string arr[] = { "строка1", "строка2", "строка3" };
        ofstream out("array.txt");

        for (string s : arr) {
            out << s << endl;
        }
        out.close();

        cout << "Записано в array.txt\n";
    }

    // === Задание 4 ===
    cout << "\n4. Подсчёт символов\n";
    {
        ifstream in("array.txt");
        char c;
        int count = 0;

        while (in.get(c)) {
            count++;
        }

        cout << "Символов: " << count << endl;
        in.close();
    }

    // === Задание 5 ===
    cout << "\n5. Подсчёт строк\n";
    {
        ifstream in("array.txt");
        string line;
        int lines = 0;

        while (getline(in, line)) {
            lines++;
        }

        cout << "Строк: " << lines << endl;
        in.close();
    }

    return 0;
}