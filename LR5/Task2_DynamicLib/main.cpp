#include "array_lib.h"
#include <iostream>

using namespace std;

int main() {
    int choice = 0;
    do {
        cout << "\n--- Выполнил: Банчук Георгий, гр.653501 ---" << endl;
        cout << "Задание 2 (Динамическая библиотека)" << endl;
        cout << "Рекурсивная проверка условия -10 < X_i^3 < 20 для всех элементов массива." << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "1. Запустить выполнение программы" << endl;
        cout << "2. Выйти из программы" << endl;
        cout << "Выберите действие (1-2): ";

        while (!(cin >> choice) || choice < 1 || choice > 2) {
            cout << "Некорректный ввод! Введите число 1 или 2: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (choice == 1) {
            int n = 0;
            cout << "\nВведите размерность массива N: ";
            while (!(cin >> n) || n <= 0) {
                cout << "Ошибка! Введите целое положительное число: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            double* X = new double[n];

            cout << "Введите " << n << " элементов массива X:\n";
            for (int i = 0; i < n; ++i) {
                cout << "X[" << i << "] = ";
                while (!(cin >> X[i])) {
                    cout << "Ошибка ввода! Введите число: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            }
            cin.ignore(1000, '\n');

            bool result = solveTask2(X, n);

            cout << "\nРезультат проверки: ";
            if (result) {
                cout << "ИСТИНА — условие -10 < X_i^3 < 20 выполняется для ВСЕХ элементов массива." << endl;
            } else {
                cout << "ЛОЖЬ — условие -10 < X_i^3 < 20 выполняется НЕ для всех элементов массива." << endl;
            }

            delete[] X;
        }
    } while (choice != 2);

    return 0;
}