#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Ru");
    char ch;
    int ch_code;

    cout << "Введите символ: " << endl; cin >> ch;
    ch_code = int(ch);


    if ((ch_code >= 65 && ch_code <= 90) || (ch_code >= 97 && ch_code <= 122)) {
        cout << "Вы ввели букву" << endl;
    }
    else if (ch_code >= 48 && ch_code <= 57) {
        cout << "Вы ввели цифру" << endl;
    }
    else if (ch_code == 46 || ch_code == 44 || ch_code == 33 || ch_code == 63) {
        cout << "Вы ввели знак препинания" << endl;
    }
    else {
        cout << "Вы ввели что-то другое" << endl;
    }

    //задание 2

    int choice, dialogue_duration;


    cout << "Введите какой оператор вы хотите выбрать: " << endl << endl;
    cout << "MTS: 10 руб за минуту - 1" << endl;
    cout << "Билайн: 15 руб за минуту - 2" << endl;
    cout << "Yota: 17 руб за минуту - 3" << endl;
    cout << "Мегафон: 22 руб за минуту - 4" << endl;
    cout << "Теле2.: 19 руб за минуту - 5" << endl;

    cin >> choice;

    cout << "Введите количество времени для разговора: " << endl; cin >> dialogue_duration;

    switch (choice) {
    case 1:
        dialogue_duration = 10 * dialogue_duration;
        cout << "Ваша стоимость: " << dialogue_duration << endl;
        break;
    case 2:
        dialogue_duration = 15 * dialogue_duration;
        cout << "Ваша стоимость: " << dialogue_duration << endl;
        break;
    case 3:
        dialogue_duration = 17 * dialogue_duration;
        cout << "Ваша стоимость: " << dialogue_duration << endl;
        break;
    case 4:
        dialogue_duration = 22 * dialogue_duration;
        cout << "Ваша стоимость: " << dialogue_duration << endl;
        break;
    case 5:
        dialogue_duration = 19 * dialogue_duration;
        cout << "Ваша стоимость: " << dialogue_duration << endl;
        break;
    default:
        cout << "Вы ввели не ту команду, пожалуйста повторите еще раз" << endl;
    }

}

