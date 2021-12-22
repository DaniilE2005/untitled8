#include "MATRIX.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    long long m, n;
    cout << "Введите размеры матрицы:" << "\n";
    cin >> m >> n;
    long long D[m][n];
    cout << "Введите матрицу:" << "\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> D[i][j];
        }
    }
    cout << "Возможные операции:" << "\n";
    cout << "1: Сложение матриц одной размерности" << "\n";
    cout << "2: Умножение матрицы на число" << "\n";
    cout << "3: Умножение двух матриц" << "\n";
    cout << "4: Транспортирование матрицы" << "\n";
    cout << "5: Быстрое возведение матрицы в натуральную степень" << "\n";
    cout << "Введите нужный тип операции:" << "\n";
    long long type;
    cin >> type;
    if (type == 1) {
        cout << MATRIX operator+(const MATRIX& D);
    }
    if (type == 2) {
        long long k;
        cout << "Введите число:\n";
        cin >> k;
        cout << MATRIX operator*(k);
    }
    if (type == 3) {
        cout << MATRIX operator*(const MATRIX& D);
    }
    if (type == 4) {
        cout << MATRIX operator&(const MATRIX& D);
    }
    if (type == 5) {
        long long i;
        cout << "Введите степень:\n";
        cin >> i;
        cout << MATRIX operator^(i);
    }
}