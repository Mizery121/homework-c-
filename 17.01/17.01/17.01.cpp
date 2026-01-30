#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

// 1. Система кодов ошибок
enum ErrorCode {
    SUCCESS,
    FILE_NOT_FOUND,
    ACCESS_DENIED,
    OUT_OF_MEMORY
};

ErrorCode checkFile(const string& filename) {
    if (filename.empty()) return FILE_NOT_FOUND;
    if (filename.find("secret") != string::npos) return ACCESS_DENIED;
    if (filename.find("huge") != string::npos) return OUT_OF_MEMORY;
    return SUCCESS;
}

string errorMessage(ErrorCode code) {
    switch (code) {
    case SUCCESS: return "Успех";
    case FILE_NOT_FOUND: return "Файл не найден";
    case ACCESS_DENIED: return "Доступ запрещен";
    case OUT_OF_MEMORY: return "Нехватка памяти";
    default: return "Неизвестная ошибка";
    }
}

// 2. Управление днями недели
enum Day {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

string dayToString(Day day) {
    switch (day) {
    case MONDAY: return "Понедельник";
    case TUESDAY: return "Вторник";
    case WEDNESDAY: return "Среда";
    case THURSDAY: return "Четверг";
    case FRIDAY: return "Пятница";
    case SATURDAY: return "Суббота";
    case SUNDAY: return "Воскресенье";
    default: return "Неизвестно";
    }
}

bool isWeekend(Day day) {
    return day == SATURDAY || day == SUNDAY;
}

// 3. Светофор
enum TrafficLight {
    RED,
    GREEN,
    YELLOW
};

TrafficLight nextLight(TrafficLight current) {
    if (current == RED) return GREEN;
    if (current == GREEN) return YELLOW;
    return RED;
}

string lightToString(TrafficLight light) {
    if (light == RED) return "КРАСНЫЙ";
    if (light == GREEN) return "ЗЕЛЕНЫЙ";
    return "ЖЕЛТЫЙ";
}

// 4. Режим сортировки
enum SortOrder {
    ASCENDING,
    DESCENDING
};

void sortNumbers(int arr[], int size, SortOrder order) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            bool needSwap = false;
            if (order == ASCENDING && arr[j] > arr[j + 1]) needSwap = true;
            if (order == DESCENDING && arr[j] < arr[j + 1]) needSwap = true;

            if (needSwap) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 5. Навигация
enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

struct Point {
    int x, y;
};

Point movePoint(Point p, Direction dir) {
    if (dir == NORTH) p.y++;
    else if (dir == EAST) p.x++;
    else if (dir == SOUTH) p.y--;
    else if (dir == WEST) p.x--;
    return p;
}

string dirToString(Direction dir) {
    if (dir == NORTH) return "Север";
    if (dir == EAST) return "Восток";
    if (dir == SOUTH) return "Юг";
    return "Запад";
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    cout << "1. СИСТЕМА КОДОВ ОШИБОК\n";
    string files[] = { "data.txt", "secret_file.txt", "huge_data.bin", "" };
    for (const auto& file : files) {
        ErrorCode code = checkFile(file);
        cout << file << " -> " << errorMessage(code) << endl;
    }

    cout << "\n2. ДНИ НЕДЕЛИ\n";
    Day today = static_cast<Day>(rand() % 7);
    cout << "Сегодня: " << dayToString(today) << endl;
    cout << "Выходной: " << (isWeekend(today) ? "Да" : "Нет") << endl;

    cout << "\n3. СВЕТОФОР\n";
    TrafficLight light = RED;
    for (int i = 0; i < 5; i++) {
        cout << "Светофор: " << lightToString(light) << endl;
        light = nextLight(light);
    }

    cout << "\n4. СОРТИРОВКА\n";
    int numbers[] = { 5, 2, 8, 1, 9, 3 };
    int size = 6;

    cout << "Исходный массив: ";
    printArray(numbers, size);

    sortNumbers(numbers, size, ASCENDING);
    cout << "По возрастанию: ";
    printArray(numbers, size);

    int numbers2[] = { 5, 2, 8, 1, 9, 3 };
    sortNumbers(numbers2, size, DESCENDING);
    cout << "По убыванию: ";
    printArray(numbers2, size);

    cout << "\n5. НАВИГАЦИЯ\n";
    Point pos = { 0, 0 };
    cout << "Начальная позиция: (" << pos.x << "," << pos.y << ")\n";

    Direction moves[] = { NORTH, EAST, SOUTH, WEST, NORTH };
    for (int i = 0; i < 5; i++) {
        pos = movePoint(pos, moves[i]);
        cout << "Шаг " << (i + 1) << " (" << dirToString(moves[i])
            << ") -> (" << pos.x << "," << pos.y << ")\n";
    }

    return 0;
}