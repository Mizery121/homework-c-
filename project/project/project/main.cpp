#include <iostream>
#include <string>
#include "calculator.h"
#include "todo_list.h"
using namespace std;

// ГЛАВНОЕ МЕНЮ
void mainMenu() {
    while (true) {
        cout << "=== ГЛАВНОЕ МЕНЮ ===\n";
        cout << "1. Калькулятор\n";
        cout << "2. Список дел\n";
        cout << "0. Выход из программы\n";
        cout << "Выберите программу: ";

        string choice;
        getline(cin, choice);

        if (choice == "1") {
            calculator();
        }
        else if (choice == "2") {
            todoList();
        }
        else if (choice == "0") {
            cout << "\nСпасибо за использование программы! До свидания!\n";
            break;
        }
        else {
            cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }
}

// ГЛАВНАЯ ФУНКЦИЯ

int main() {
    setlocale(LC_ALL, "Russian");
    mainMenu();
    return 0;
}