#include "calculator.h"
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <stdexcept>
using namespace std;

// Проверка приоритета операторов
int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Выполнение операции
double applyOperation(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0) throw runtime_error("Деление на ноль!");
        return a / b;
    }
    return 0;
}

// Вычисление выражения
double evaluateExpression(string expression) {
    stack<double> numbers;
    stack<char> operators;

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') continue;

        else if (isdigit(expression[i]) || expression[i] == '.') {
            string numStr = "";
            while (i < expression.length() &&
                (isdigit(expression[i]) || expression[i] == '.')) {
                numStr += expression[i];
                i++;
            }
            i--;
            numbers.push(stod(numStr));
        }

        else if (expression[i] == '(') {
            operators.push('(');
        }

        else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double b = numbers.top(); numbers.pop();
                double a = numbers.top(); numbers.pop();
                char op = operators.top(); operators.pop();
                numbers.push(applyOperation(a, b, op));
            }
            operators.pop();
        }

        else if (expression[i] == '+' || expression[i] == '-' ||
            expression[i] == '*' || expression[i] == '/') {

            if (expression[i] == '-' && (i == 0 || expression[i - 1] == '(' ||
                expression[i - 1] == '+' || expression[i - 1] == '-' ||
                expression[i - 1] == '*' || expression[i - 1] == '/')) {
                numbers.push(0);
            }

            while (!operators.empty() && getPriority(operators.top()) >= getPriority(expression[i])) {
                double b = numbers.top(); numbers.pop();
                double a = numbers.top(); numbers.pop();
                char op = operators.top(); operators.pop();
                numbers.push(applyOperation(a, b, op));
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        double b = numbers.top(); numbers.pop();
        double a = numbers.top(); numbers.pop();
        char op = operators.top(); operators.pop();
        numbers.push(applyOperation(a, b, op));
    }

    return numbers.top();
}

void calculator() {
    cout << "\n=== КАЛЬКУЛЯТОР ===\n";
    cout << "Поддерживает: + - * / ( )\n";
    cout << "Примеры: 5+3*2, (5+3)*2, 2*(3+4)/2\n";

    while (true) {
        cout << "Введите выражение или команду: ";
        string input;
        getline(cin, input);

        if (input == "меню" || input == "menu" || input == "m") {
            cout << "Возвращаемся в главное меню...\n";
            return;
        }

        if (input.empty()) continue;

        try {
            string cleanExpr = "";
            for (char c : input) {
                if (c != ' ') cleanExpr += c;
            }

            double result = evaluateExpression(cleanExpr);
            cout << "Результат: " << result << "\n\n";
        }
        catch (const exception& e) {
            cout << "Ошибка: " << e.what() << "\n\n";
        }
        catch (...) {
            cout << "Неизвестная ошибка!\n\n";
        }
    }
}