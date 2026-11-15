#include <iostream>

using namespace std;

int main () {
    

    int choice = 0;
        do {
            cout << "\n--- Выполнил: Банчук Георгий, гр.653501 ---" << endl;
            cout << "Вариант 2" << endl; 
            cout << "Дан трёхмерный динамический массив размером n^3 целых неотрицательных чисел. Необходимо определить диагональ с наибольшей суммой чисел. Для обхода диагоналей нельзя использовать вложенные циклы. Постройте блок-схему алгоритма." << endl;
            cout << "----------------------------------------------------------------------------------------" << endl;
            cout << "1. Запустить выполнение программы" << endl;
            cout << "2. Выйти из программы" << endl;
            cout << "Выберите действие (1-2): ";

        while (!(cin >> choice) || choice < 1 || choice > 2) {
            cout << "Некорректный ввод! Введите число 1 или 2: ";
            cin.clear(); 
            cin.ignore(100, '\n');
        }

        
        if (choice == 1){
            int n;
            cout << "Введите значение n: ";
            cin >> n;
            int*** arr = new int**[n];
            for (int i = 0; i < n; i++) {
                arr[i] = new int*[n];
                for (int j = 0; j < n; j++) {
                    arr[i][j] = new int[n];
                }   
            }

            cout << "Введите " << n * n * n << " целых неотрицательных чисел:\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        cin >> arr[i][j][k];
                    }
                }
            }
            long long d1 = 0, d2 = 0, d3 = 0, d4 = 0;
            for (int i = 0; i < n; i++) {
                d1 += arr[i][i][i];
                d2 += arr[i][i][n - 1 - i];
                d3 += arr[i][n - 1 - i][i];
                d4 += arr[n - 1 - i][i][i];
            }
            long long maxSum = d1;
            int maxDiag = 1;

             if (d2 > maxSum) {
                maxSum = d2;
                maxDiag = 2;
            }
            if (d3 > maxSum) {
                maxSum = d3;
                maxDiag = 3;
            }
            if (d4 > maxSum) {
                maxSum = d4;
                maxDiag = 4;
            }

            cout << "\nСуммы диагоналей: d1=" << d1 << ", d2=" << d2 << ", d3=" << d3 << ", d4=" << d4 << endl;
            cout << "Наибольшая сумма у диагонали #" << maxDiag << " и равна: " << maxSum << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    delete[] arr[i][j];
                }
            delete[] arr[i];
            }
            delete[] arr;

        }
        } while (choice != 2);

    return 0;
}
