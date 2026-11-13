#include <iostream>
#include <cmath>
using namespace std;

int main () {

    
    int choice = 0;
        do {
            cout << "\n--- Выполнил: Банчук Георгий, гр.653501 ---" << endl;
            cout << "Вариант 2" << endl; 
            cout << "Инициализировать при объявлении статический двумерный массив целых чисел размером MxN. Определить количество отрицательных элементов, расположенных выше главной диагонали матрицы." << endl;
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
            const int M = 4;
            const int N = 4;

            int arr[M][N]{
                {2,-4,5,3},
                {6,54,-3,2},
                {32,43,5,-33},
                {4,-87,23,43}
            };
            cout << "Главная диагональ: ";
            for (int i{0}; i < M; i++) {
                cout << arr[i][i] << ' ';    
            }
            cout << "\n";
        
            int minusUpDiagonal{0};
            for (int i{0}; i < M; i++) {
                for (int j = i + 1; j < N; j++)
                {
                    if (arr[i][j] < 0){
                        minusUpDiagonal++;
                    }
                    
                }
                }
            cout << "Количество отрицательных элементов выше главной диагонали:" << minusUpDiagonal << endl;             
            

        }   
    } while (choice != 2);

    return 0;
}
