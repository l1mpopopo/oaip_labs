#include <iostream>
using namespace std;

int main () {

    int choice = 0;
        do {
            cout << "    Выполнил: Банчук Георгий, гр.653501" << endl;
            cout << "Разработка программы вычисления суммы квадратов разностей элементов двух последовательностей от 1 до 30 с использованием цикла while и условных переходов." << endl;
            cout << "---------------------------------------" << endl;
            cout << "1. Запустить выполнение программы" << endl;
            cout << "2. Выйти из программы" << endl;
            cout << "Выберите действие (1-2): ";

        while (!(cin >> choice) || choice < 1 || choice > 2) {
            cout << "Некорректный ввод! Введите число 1 или 2: ";
            cin.clear(); 
            cin.ignore(100, '\n');
        }

        if (choice == 1) {
            int i = 1;
            double N = 0.0;
                cout << "Старт вычислений (от 1 до 30): " << endl;
                while (i <= 30){
                double a = 0.0;
                double b = 0.0;
        if (i % 2 != 0 ){
                a = i;
                b = pow(i,2);
        }   else {
                a = i / 2.0;
                b = pow(i,3);
        }
    N += pow((a - b),2);
    i++;
    cout << "Результат вычисления: " << N << endl;
            }   
        } 
    } while (choice != 2);
    return 0;
}