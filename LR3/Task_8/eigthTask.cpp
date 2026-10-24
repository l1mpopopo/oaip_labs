#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int choice = 0;

        do {
            cout << "\n--- Выполнил: Банчук Георгий, гр.653501 ---" << endl;
            cout << "Разработка программы вычисления знакочередующейся суммы элементов числовой последовательности с целочисленными степенными коэффициентами двойки без использования вещественной арифметики." << endl;
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
            int n {0};
            cout << "Введите n: ";
            
        while (!(cin >> n) || n <= 0  )
        {
            cout << "Некорректный ввод, введите n больше нуля ";
            cin.clear();
            cin.ignore(100, '\n');
        }
        long long sum {0};
        long long coeff {1};
        cout << "Введите значения констант (a1,a2, ...): ";
        
        for (int i = 0;i < n;i++) {
            long long input_number = 0; 
            cout << "Введи число номер " << i << ": ";
            
            while (!(cin >> input_number)) {
                    cout << "Некорректный ввод! Введите целое число: ";
                    cin.clear();
                    cin.ignore(100, '\n');
                }
            sum += coeff * input_number;
            coeff *= -2;
        }
            cout << "Результат вычисления: " << sum << endl;
        
    } 
}while (choice != 2);
     
    return 0;

}
