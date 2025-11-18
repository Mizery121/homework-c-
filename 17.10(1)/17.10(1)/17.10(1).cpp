#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    srand(time(0));

    cout << "ТЕСТ ПО ТАБЛИЦЕ УМНОЖЕНИЯ\n\n";

    // 1-3 уровни
    for (int level = 1; level <= 3; level++) {
        int questions, maxNum;

        if (level == 1) {
            questions = 3;
            maxNum = 5;
            cout << "УРОВЕНЬ 1 (легкий)\n";
        }
        else if (level == 2) {
            questions = 5;
            maxNum = 8;
            cout << "УРОВЕНЬ 2 (средний)\n";
        }
        else {
            questions = 7;
            maxNum = 10;
            cout << "УРОВЕНЬ 3 (сложный)\n";
        }

        int correct = 0;

        // вопросы каждого уровня
        for (int i = 1; i <= questions; i++) {
            int a = rand() % maxNum + 1;
            int b = rand() % maxNum + 1;
            int answer;

            cout << i << ") " << a << " * " << b << " = ";
            cin >> answer;

            if (answer == a * b) {
                cout << "Верно!\n";
                correct++;
            }
            else {
                cout << "Нет, правильно: " << a * b << "\n";
            }
        }

        cout << "Уровень " << level << ": " << correct << " из " << questions << " верно\n\n";
    }

    // ромб
    cout << "Введите размер ромба: ";
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << string(n - i, ' ') << string(2 * i - 1, '*') << "\n";
    }
    for (int i = n - 1; i >= 1; i--) {
        cout << string(n - i, ' ') << string(2 * i - 1, '*') << "\n";
    }

    return 0;
}