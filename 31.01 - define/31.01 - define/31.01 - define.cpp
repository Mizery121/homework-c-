#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string lastName;
    string firstName;
    string group;
    int age;
    double averageGrade;
};

vector<Student> students;
string filename = "students.txt";

// Загрузка данных из файла
void loadData() {
    ifstream file(filename);
    if (!file) {
        cout << "Файл не найден. Будет создан новый." << endl;
        return;
    }

    Student s;
    while (file >> s.id >> s.lastName >> s.firstName >> s.group >> s.age >> s.averageGrade) {
        students.push_back(s);
    }
    file.close();
    cout << "Загружено " << students.size() << " студентов." << endl;
}

// Сохранение данных в файл
void saveData() {
    ofstream file(filename);
    for (auto& s : students) {
        file << s.id << " " << s.lastName << " " << s.firstName << " "
            << s.group << " " << s.age << " " << s.averageGrade << endl;
    }
    file.close();
    cout << "Данные сохранены в файл." << endl;
}

// Показать всех студентов
void showAll() {
    if (students.empty()) {
        cout << "Нет студентов." << endl;
        return;
    }
    cout << "\nСписок студентов:" << endl;
    for (auto& s : students) {
        cout << s.id << ". " << s.lastName << " " << s.firstName
            << " - Группа: " << s.group << ", Возраст: " << s.age
            << ", Средний балл: " << s.averageGrade << endl;
    }
}

// Добавить студента
void addStudent() {
    Student s;
    s.id = students.empty() ? 1 : students.back().id + 1;

    cout << "\nДобавление нового студента:" << endl;
    cout << "Фамилия: "; cin >> s.lastName;
    cout << "Имя: "; cin >> s.firstName;
    cout << "Группа: "; cin >> s.group;
    cout << "Возраст: "; cin >> s.age;
    cout << "Средний балл: "; cin >> s.averageGrade;

    students.push_back(s);
    cout << "Студент добавлен (ID: " << s.id << ")" << endl;
}

// Поиск по фамилии
void searchByLastName() {
    if (students.empty()) {
        cout << "Нет студентов." << endl;
        return;
    }

    string search;
    cout << "Поиск по фамилии: ";
    cin >> search;

    bool found = false;
    for (auto& s : students) {
        if (s.lastName == search) {
            cout << "Найден: " << s.lastName << " " << s.firstName
                << " - Группа: " << s.group << ", Возраст: " << s.age << endl;
            found = true;
        }
    }
    if (!found) cout << "Не найдено." << endl;
}

// Поиск по возрасту
void searchByAge() {
    if (students.empty()) {
        cout << "Нет студентов." << endl;
        return;
    }

    int age;
    cout << "Поиск по возрасту: ";
    cin >> age;

    bool found = false;
    for (auto& s : students) {
        if (s.age == age) {
            cout << "Найден: " << s.lastName << " " << s.firstName
                << " - Группа: " << s.group << ", Возраст: " << s.age << endl;
            found = true;
        }
    }
    if (!found) cout << "Не найдено." << endl;
}

// Поиск по первой букве фамилии
void searchByFirstLetter() {
    if (students.empty()) {
        cout << "Нет студентов." << endl;
        return;
    }

    char letter;
    cout << "Первая буква фамилии: ";
    cin >> letter;

    bool found = false;
    for (auto& s : students) {
        if (!s.lastName.empty() && s.lastName[0] == letter) {
            cout << "Найден: " << s.lastName << " " << s.firstName
                << " - Группа: " << s.group << ", Возраст: " << s.age << endl;
            found = true;
        }
    }
    if (!found) cout << "Не найдено." << endl;
}

// Редактировать студента
void editStudent() {
    if (students.empty()) {
        cout << "Нет студентов." << endl;
        return;
    }

    int id;
    cout << "ID студента для редактирования: ";
    cin >> id;

    bool found = false;
    for (auto& s : students) {
        if (s.id == id) {
            found = true;
            cout << "Редактирование: " << s.lastName << " " << s.firstName << endl;

            cout << "Новая фамилия [" << s.lastName << "]: ";
            cin >> s.lastName;
            cout << "Новое имя [" << s.firstName << "]: ";
            cin >> s.firstName;
            cout << "Новая группа [" << s.group << "]: ";
            cin >> s.group;
            cout << "Новый возраст [" << s.age << "]: ";
            cin >> s.age;
            cout << "Новый средний балл [" << s.averageGrade << "]: ";
            cin >> s.averageGrade;

            cout << "Данные обновлены." << endl;
            break;
        }
    }
    if (!found) cout << "Студент с таким ID не найден." << endl;
}

// Удалить студента
void deleteStudent() {
    if (students.empty()) {
        cout << "Нет студентов." << endl;
        return;
    }

    int id;
    cout << "ID студента для удаления: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            cout << "Удаляем: " << it->lastName << " " << it->firstName << endl;
            students.erase(it);
            cout << "Студент удален." << endl;
            return;
        }
    }
    cout << "Студент с таким ID не найден." << endl;
}

int main() {
    setlocale(LC_ALL, "RU");

    // Загрузка данных
    loadData();

    // Если нет данных, добавляем тестовых
    if (students.empty()) {
        cout << "Добавляем тестовых студентов..." << endl;
        students = {
            {1, "Иванов", "Иван", "РПО 22/1", 20, 4.5},
            {2, "Петров", "Петр", "РПО 22/1", 21, 4.2},
            {3, "Сидорова", "Анна", "РПО 22/1", 19, 4.8}
        };
    }

    // Последовательное выполнение операций
    showAll();

    cout << "\n Добавление студента " << endl;
    addStudent();

    cout << "\n Поиск по фамилии " << endl;
    searchByLastName();

    cout << "\n Поиск по возрасту " << endl;
    searchByAge();

    cout << "\n Поиск по первой букве фамилии " << endl;
    searchByFirstLetter();

    cout << "\n Редактирование студента " << endl;
    editStudent();

    cout << "\n Удаление студента " << endl;
    deleteStudent();

    cout << "\n Показать обновленный список " << endl;
    showAll();

    // Сохранение в файл
    cout << "\n Сохранение данных " << endl;
    saveData();

    return 0;
}