#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int M, N;

    // Ввод размеров массивов
    cout << "M = ";
    cin >> M;
    cout << "N = ";
    cin >> N;

    // Ввод массивов
    vector<int> A(M), B(N);

    cout << "A: ";
    for (int i = 0; i < M; i++) cin >> A[i];

    cout << "B: ";
    for (int i = 0; i < N; i++) cin >> B[i];

    // Задача 1. Элементы A, не входящие в B
    set<int> setB(B.begin(), B.end());
    set<int> result1;

    for (int x : A) {
        if (setB.count(x) == 0) {
            result1.insert(x);
        }
    }

    // Задача 2. Симметричная разность
    set<int> setA(A.begin(), A.end());
    set<int> result2;

    for (int x : A) {
        if (setB.count(x) == 0) result2.insert(x);
    }
    for (int x : B) {
        if (setA.count(x) == 0) result2.insert(x);
    }

    // Вывод результатов
    cout << "\n1) A без B: ";
    for (int x : result1) cout << x << " ";

    cout << "\n2) Симметричная разность: ";
    for (int x : result2) cout << x << " ";

    return 0;
}