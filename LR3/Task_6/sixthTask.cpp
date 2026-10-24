#include <iostream>
#include <cmath>

using namespace std;
int main() {
    double x = 0.0;
    int choice = 0;
    
    do {
            cout << "    Выполнил: Банчук Георгий, гр.653501" << endl;
            cout << "Из величин, определяемых выражениями a = sinx, b = cosx, c = ln|x| при заданном х, определить и вывести на экран дисплея минимальное значение. Использование стандартных математических методов запрещено." << endl;
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
        cout << "Введите значение x: " ;
        cin >> x;
        if(x == 0){
            cout << "Не существует ln|x| по ОДЗ" ;
            
        }

        else{
            double a = sin(x);
            double b = cos(x);
            double c = log(fabs(x));
            double minValue = 0.0;
            minValue = a;
            if (b < minValue) {
                minValue = b;
    }
            if(c < minValue){
                minValue = c;
                    
    }

    cout << "Значение sin(x) = " << a << endl;
    cout << "Значение cos(x) = " << b << endl;
    cout << "Значение ln|x| = " << c << endl;
    cout << "Минимальное значение: " << minValue << endl;
        }
                 }       
    } while (choice != 2);
    return 0;
}