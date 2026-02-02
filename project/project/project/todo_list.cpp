#include "todo_list.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void todoList() {
    cout << "\n=== СПИСОК ДЕЛ ===\n";

    vector<Task> tasks;

    while (true) {
        cout << "\nМЕНЮ:\n";
        cout << "1. Добавить дело\n";
        cout << "2. Показать все дела\n";
        cout << "3. Отметить дело как выполненное\n";
        cout << "4. Удалить дело\n";
        cout << "0. В главное меню\n";
        cout << "Выберите пункт: ";

        string choice;
        getline(cin, choice);

        if (choice == "0") {
            cout << "Возвращаемся в главное меню...\n";
            return;
        }

        else if (choice == "1") {
            Task newTask;
            cout << "Введите название дела: ";
            getline(cin, newTask.name);
            cout << "Введите дату (например: 25.12.2023): ";
            getline(cin, newTask.date);
            newTask.done = false;
            tasks.push_back(newTask);
            cout << "? Дело добавлено!\n";
        }

        else if (choice == "2") {
            if (tasks.empty()) {
                cout << "Список дел пуст!\n";
            }
            else {
                cout << "\n=== ВАШИ ДЕЛА ===\n";
                for (size_t i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ". " << tasks[i].name;
                    cout << " (Дата: " << tasks[i].date << ")";
                    if (tasks[i].done) {
                        cout << " - Выполнено";
                    }
                    else {
                        cout << " - Не выполнено";
                    }
                    cout << endl;
                }
            }
        }

        else if (choice == "3") {
            if (tasks.empty()) {
                cout << "Список дел пуст!\n";
                continue;
            }
            cout << "Введите номер дела: ";
            string numStr;
            getline(cin, numStr);
            try {
                int num = stoi(numStr);
                if (num < 1 || num >(int)tasks.size()) {
                    cout << "Неверный номер!\n";
                }
                else {
                    tasks[num - 1].done = true;
                    cout << "Дело отмечено как выполненное!\n";
                }
            }
            catch (...) {
                cout << "Ошибка: введите число!\n";
            }
        }

        else if (choice == "4") {
            if (tasks.empty()) {
                cout << "Список дел пуст!\n";
                continue;
            }
            cout << "Введите номер дела для удаления: ";
            string numStr;
            getline(cin, numStr);
            try {
                int num = stoi(numStr);
                if (num < 1 || num >(int)tasks.size()) {
                    cout << "Неверный номер!\n";
                }
                else {
                    tasks.erase(tasks.begin() + (num - 1));
                    cout << "Дело удалено!\n";
                }
            }
            catch (...) {
                cout << "Ошибка: введите число!\n";
            }
        }

        else {
            cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }
}