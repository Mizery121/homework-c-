#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct VideoStore {
    string title;
    string director;
    string genre;
    double rating;
    double price;
};

vector<VideoStore> movies;

void showAll() {
    if (movies.empty()) {
        cout << "Каталог пуст!\n";
        return;
    }
    cout << "\nСписок фильмов:\n";
    for (int i = 0; i < movies.size(); i++) {
        cout << i + 1 << ". " << movies[i].title << " | "
            << movies[i].director << " | "
            << movies[i].genre << " | "
            << movies[i].rating << " | "
            << movies[i].price << " руб.\n";
    }
}

void addMovie() {
    VideoStore m;
    cout << "\nДобавление фильма:\n";
    cout << "Название: ";
    cin.ignore();
    getline(cin, m.title);
    cout << "Режиссер: ";
    getline(cin, m.director);
    cout << "Жанр: ";
    getline(cin, m.genre);
    cout << "Рейтинг (0-10): ";
    cin >> m.rating;
    cout << "Цена: ";
    cin >> m.price;
    movies.push_back(m);
    cout << "Фильм добавлен!\n";
}

void searchTitle() {
    string s;
    cout << "Поиск по названию: ";
    cin.ignore();
    getline(cin, s);

    bool found = false;
    for (auto& m : movies) {
        if (m.title.find(s) != string::npos) {
            cout << "Найден: " << m.title << " | " << m.director << " | " << m.genre << "\n";
            found = true;
        }
    }
    if (!found) cout << "Не найдено\n";
}

void searchGenre() {
    string s;
    cout << "Поиск по жанру: ";
    cin.ignore();
    getline(cin, s);

    bool found = false;
    for (auto& m : movies) {
        if (m.genre.find(s) != string::npos) {
            cout << "Найден: " << m.title << " | " << m.director << " | " << m.genre << "\n";
            found = true;
        }
    }
    if (!found) cout << "Не найдено\n";
}

void searchDirector() {
    string s;
    cout << "Поиск по режиссеру: ";
    cin.ignore();
    getline(cin, s);

    bool found = false;
    for (auto& m : movies) {
        if (m.director.find(s) != string::npos) {
            cout << "Найден: " << m.title << " | " << m.director << " | " << m.genre << "\n";
            found = true;
        }
    }
    if (!found) cout << "Не найдено\n";
}

void mostPopular() {
    string genre;
    cout << "Введите жанр: ";
    cin.ignore();
    getline(cin, genre);

    double maxRating = -1;
    VideoStore* popular = nullptr;

    for (auto& m : movies) {
        if (m.genre == genre && m.rating > maxRating) {
            maxRating = m.rating;
            popular = &m;
        }
    }

    if (popular) {
        cout << "Самый популярный в жанре " << genre << ": "
            << popular->title << " (рейтинг: " << popular->rating << ")\n";
    }
    else {
        cout << "Фильмов в этом жанре нет\n";
    }
}

void testData() {
    movies = {
        {"Мстители", "Джо Руссо", "Фантастика", 9.5, 1200},
        {"Побег из Шоушенка", "Фрэнк Дарабонт", "Драма", 9.3, 800},
        {"Крестный отец", "Коппола", "Криминал", 9.2, 1000},
        {"Темный рыцарь", "Нолан", "Боевик", 9.0, 1100},
        {"Форрест Гамп", "Земекис", "Драма", 8.8, 700}
    };
    cout << "Добавлено 5 тестовых фильмов!\n";
}

int main() {
    setlocale(LC_ALL, "RU");
    int choice;

    do {
        cout << "\n   ВИДЕОМАГАЗИН   \n";
        cout << "1. Показать все\n";
        cout << "2. Добавить фильм\n";
        cout << "3. Поиск по названию\n";
        cout << "4. Поиск по жанру\n";
        cout << "5. Поиск по режиссеру\n";
        cout << "6. Самый популярный в жанре\n";
        cout << "7. Тестовые данные\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: showAll(); break;
        case 2: addMovie(); break;
        case 3: searchTitle(); break;
        case 4: searchGenre(); break;
        case 5: searchDirector(); break;
        case 6: mostPopular(); break;
        case 7: testData(); break;
        case 0: cout << "Выход\n"; break;
        default: cout << "Неверный выбор\n";
        }
    } while (choice != 0);

    return 0;
}