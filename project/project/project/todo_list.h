#ifndef TODO_LIST_H // директива и ее конец
#define TODO_LIST_H

#include <string>
#include <vector>
using namespace std;

struct Task {
    string name;
    string date;
    bool done;
};

void todoList();

#endif