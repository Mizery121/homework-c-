#ifndef CALCULATOR_H // директива и ее конец
#define CALCULATOR_H

#include <string>
using namespace std;

// ќбъ€влени€ функций калькул€тора
int getPriority(char op);
double applyOperation(double a, double b, char op);
double evaluateExpression(string expression);
void calculator();

#endif