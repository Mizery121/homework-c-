#include <iostream>
#include <iomanip>
using namespace std;

// ЗАДАНИЕ 1: ПИЦЦЕРИЯ

void pizzaOrder() {
    cout << "=== МИНИ-ПИЦЦЕРИЯ ===" << endl;

    // Меню
    cout << "\nМеню пиццы:" << endl;
    cout << "1. Маргарита - $10" << endl;
    cout << "2. Пепперони - $12" << endl;
    cout << "3. Гавайская - $11" << endl;
    cout << "4. Четыре сыра - $13" << endl;

    cout << "\nМеню напитков:" << endl;
    cout << "5. Кола - $2" << endl;
    cout << "6. Сок - $3" << endl;
    cout << "7. Вода - $1" << endl;

    // Переменные для хранения заказа
    int pizza1 = 0, pizza2 = 0, pizza3 = 0, pizza4 = 0;
    int drink1 = 0, drink2 = 0, drink3 = 0;

    // Ввод заказа
    int code, quantity;
    cout << "\nВводите код продукта и количество (0 - закончить):" << endl;

    while (true) {
        cout << "Код: "; cin >> code;
        if (code == 0) break;

        cout << "Количество: "; cin >> quantity;

        switch (code) {
        case 1: pizza1 += quantity; break;
        case 2: pizza2 += quantity; break;
        case 3: pizza3 += quantity; break;
        case 4: pizza4 += quantity; break;
        case 5: drink1 += quantity; break;
        case 6: drink2 += quantity; break;
        case 7: drink3 += quantity; break;
        default: cout << "Неверный код!" << endl;
        }
    }

    // Рассчеты
    int totalPizzas = pizza1 + pizza2 + pizza3 + pizza4;
    int freePizzas = totalPizzas / 5;

    // Цены
    double p1_price = 10.0, p2_price = 12.0, p3_price = 11.0, p4_price = 13.0;
    double d1_price = 2.0, d2_price = 3.0, d3_price = 1.0;

    // Стоимость пицц (без учета бесплатных)
    double pizza_cost = pizza1 * p1_price + pizza2 * p2_price + pizza3 * p3_price + pizza4 * p4_price;

    // Стоимость напитков
    double drink_cost = drink1 * d1_price + drink2 * d2_price + drink3 * d3_price;

    // Скидка на напитки (если цена >2 и кол-во >3)
    double drink_discount = 0;
    if (drink2 > 3) {
        drink_discount = drink2 * d2_price * 0.15;
    }

    // Общая сумма до скидок
    double total = pizza_cost + drink_cost - drink_discount;

    // Скидка 20% если сумма >50
    double big_discount = 0;
    if (total > 50) {
        big_discount = total * 0.20;
    }

    double final_total = total - big_discount;

    // Вывод чека
    cout << "\n=== ВАШ ЧЕК ===" << endl;

    if (pizza1 > 0) cout << "Маргарита x" << pizza1 << " - $" << pizza1 * p1_price << endl;
    if (pizza2 > 0) cout << "Пепперони x" << pizza2 << " - $" << pizza2 * p2_price << endl;
    if (pizza3 > 0) cout << "Гавайская x" << pizza3 << " - $" << pizza3 * p3_price << endl;
    if (pizza4 > 0) cout << "Четыре сыра x" << pizza4 << " - $" << pizza4 * p4_price << endl;

    if (drink1 > 0) cout << "Кола x" << drink1 << " - $" << drink1 * d1_price << endl;
    if (drink2 > 0) {
        cout << "Сок x" << drink2 << " - $" << drink2 * d2_price;
        if (drink_discount > 0) cout << " (скидка $" << drink_discount << ")";
        cout << endl;
    }
    if (drink3 > 0) cout << "Вода x" << drink3 << " - $" << drink3 * d3_price << endl;

    if (freePizzas > 0) {
        cout << "\nБесплатных пицц: " << freePizzas << " (каждая 5-я в подарок)" << endl;
    }

    cout << "\nСумма: $" << pizza_cost + drink_cost << endl;
    if (drink_discount > 0) cout << "Скидка на напитки: $" << drink_discount << endl;
    if (big_discount > 0) cout << "Скидка 20%: $" << big_discount << endl;
    cout << "ИТОГО: $" << final_total << endl;
}

//  ЗАДАНИЕ 2: МЕНЕДЖЕРЫ

void managerSalary() {
    cout << "\n=== РАСЧЕТ ЗАРПЛАТ МЕНЕДЖЕРОВ ===" << endl;

    double sales1, sales2, sales3;

    cout << "\nВведите продажи 1-го менеджера: $";
    cin >> sales1;
    cout << "Введите продажи 2-го менеджера: $";
    cin >> sales2;
    cout << "Введите продажи 3-го менеджера: $";
    cin >> sales3;

    // Расчет зарплат
    double salary1 = 200;
    double salary2 = 200;
    double salary3 = 200;

    // 1-й менеджер
    if (sales1 < 500) salary1 += sales1 * 0.03;
    else if (sales1 <= 1000) salary1 += sales1 * 0.05;
    else salary1 += sales1 * 0.08;

    // 2-й менеджер
    if (sales2 < 500) salary2 += sales2 * 0.03;
    else if (sales2 <= 1000) salary2 += sales2 * 0.05;
    else salary2 += sales2 * 0.08;

    // 3-й менеджер
    if (sales3 < 500) salary3 += sales3 * 0.03;
    else if (sales3 <= 1000) salary3 += sales3 * 0.05;
    else salary3 += sales3 * 0.08;

    // Определяем лучшего менеджера
    double best_sales = sales1;
    int best_manager = 1;

    if (sales2 > best_sales) {
        best_sales = sales2;
        best_manager = 2;
    }
    if (sales3 > best_sales) {
        best_sales = sales3;
        best_manager = 3;
    }

    // Начисляем премию лучшему
    if (best_manager == 1) salary1 += 200;
    else if (best_manager == 2) salary2 += 200;
    else salary3 += 200;

    // Вывод результатов
    cout << "\n=== РЕЗУЛЬТАТЫ ===" << endl;

    cout << "\nМенеджер 1:" << endl;
    cout << "  Продажи: $" << sales1 << endl;
    cout << "  Зарплата: $" << salary1;
    if (best_manager == 1) cout << " (включая премию $200)";
    cout << endl;

    cout << "\nМенеджер 2:" << endl;
    cout << "  Продажи: $" << sales2 << endl;
    cout << "  Зарплата: $" << salary2;
    if (best_manager == 2) cout << " (включая премию $200)";
    cout << endl;

    cout << "\nМенеджер 3:" << endl;
    cout << "  Продажи: $" << sales3 << endl;
    cout << "  Зарплата: $" << salary3;
    if (best_manager == 3) cout << " (включая премию $200)";
    cout << endl;

    cout << "\nЛучший менеджер: №" << best_manager << endl;
    cout << "Его продажи: $" << best_sales << endl;
}


int main() {
    setlocale(LC_ALL, "RU");

    // Задание 1: Пиццерия
    pizzaOrder();

    // Задание 2: Менеджеры
    managerSalary();

    cout << "\n=== ВСЕ ЗАДАНИЯ ВЫПОЛНЕНЫ ===" << endl;
    return 0;
}