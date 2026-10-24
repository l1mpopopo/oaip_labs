#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int choice = 0;
    double fx {0};
    double x {0};
    
    do {
        cout << "    Выполнил: Банчук Георгий, гр.653501" << endl;
        cout << "Необходимо приближенно найти корень уравнения f(x) = 0 для функции из своего варианта. Корень нужно найти по следующему алгоритму: перебираем значения от начала до конца интервала с некоторым шагом и ищем значение функции, минимальное по модулю. Аргумент, при котором оно достигается, считаем корнем уравнения. Программа должна запросить у пользователя, на сколько частей разделить область поиска корня, вычислить шаг, с которым нужно проходить значения, пройти в цикле нужные значения, найти корень и вывести его. Постройте блок-схему алгоритма" << endl;
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
            cout << "Введите , на сколько частей разделить область поиска корня: " ;
            
        
        while (!(cin >> n) || n <= 0  )
        {
            cout << "Некорректный ввод, введите , на сколько частей разделить область поиска корня: " ;
            cin.clear();
            cin.ignore(100, '\n');
        }
        const double a = 2;
        const double b = 4; 
        double step{0.0};
        step = (b - a) / n;
        
        double best_x = a;
        double minFx = abs(log(a) + tan(a) * 3.0 + sqrt(a));

        for (int i = 0; i <= n; ++i) {
                double current_x = a + i * step;
                double current_f = abs(log(current_x) + tan(current_x) * 3.0 + sqrt(current_x));

                if (current_f < minFx) {
                    minFx = current_f; 
                    best_x = current_x;
            }
        }
        cout << "Корень уравнения: x = " << best_x << endl;
        double final_f = log(best_x) + tan(best_x) * 3.0 + sqrt(best_x);
        cout << "Значение функции в этой точке: f(x) = " << final_f << endl;
        
    } 
} while (choice != 2);
  
    return 0;

}