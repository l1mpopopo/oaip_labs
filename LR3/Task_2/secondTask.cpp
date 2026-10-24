#include <iostream>
using namespace std;



int main () {

    
    int choice = 0;
        do {
            cout << "    Выполнил: Банчук Георгий, гр.653501" << endl;
            cout << "Разработка программы вычисления суммы числового ряда с общим членом d_n = 1/(2^n) + 1/(3^n) с заданной точностью 10^-3 с использованием цикла do-while." << endl;
            cout << "---------------------------------------" << endl;
            cout << "1. Запустить выполнение программы" << endl;
            cout << "2. Выйти из программы" << endl;
            cout << "Выберите действие (1-2): ";

        while (!(cin >> choice) || choice < 1 || choice > 2) {
            cout << "Некорректный ввод! Введите число 1 или 2: ";
            cin.clear(); 
        }

        if (choice == 1) {
            double sum = 0.0;
            int n = 1;
            double dn = 0.0;
                cout << "\n Старт вычислений " << endl;
                do {
                
                     dn = pow((1.0 / 2.0),n) + pow((1.0 / 3.0),n);
                    n++;
                    sum += dn;
                    cout << "Результат вычисления: " << sum << endl;
            }while (dn >= 0.001);
        } 
    } while (choice != 2);
    return 0;
}