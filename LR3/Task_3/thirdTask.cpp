#include <iostream>
#include <cmath>
using namespace std;

int main () {

    
    int choice = 0;
        do {
            cout << "    Выполнил: Банчук Георгий, гр.653501" << endl;
            cout << "Используя цикл for составить программу вычисления значений функции y = sin(x) - cos(x) на отрезке [A, B] в точках X_i = A + i * H, где H = (B - A) / M, M = 20, A = 0, B = pi / 2." << endl;
            cout << "---------------------------------------" << endl;
            cout << "1. Запустить выполнение программы" << endl;
            cout << "2. Выйти из программы" << endl;
            cout << "Выберите действие (1-2): ";

        while (!(cin >> choice) || choice < 1 || choice > 2) {
            cout << "Некорректный ввод! Введите число 1 или 2: ";
            cin.clear(); 
            cin.ignore(100, '\n');
        }

        
        if (choice == 1){
            int M = 20;
            double A = 0.0;
            double x = 0.0;
            double y = 0.0;
            double H = 0.0;
            double B = acos(-1.0)/ 2.0;

            H = (B - A) / M;

            for(int i {0}; i <= M;i++) {       
                x = A + i * H;
                y = sin(x) - cos(x);
                cout << "Значение функции y: " << y << endl;
    }
    }
    } while (choice != 2);
    return 0;
}
