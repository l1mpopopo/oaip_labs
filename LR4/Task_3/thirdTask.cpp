#include <iostream>

using namespace std;

int main () {
    

    int choice = 0;
        do {
            cout << "\n--- Выполнил: Банчук Георгий, гр.653501 ---" << endl;
            cout << "Вариант 2" << endl; 
            cout << "Квадратную вещественную матрицу А размером N возвести в K-ю степень, т.е. вычислить A1 = A, A2 = A*A, A3 = A2 * A и т.д.Память для массива выделить динамически." << endl;
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
            int N,K;

            cout << "Введите значение N: ";
            cin >> N;
            cout << "Введите значение K: ";
            cin >> K;

            double** A = new double* [N];
            double** result = new double* [N];
            double** nakopitel = new double* [N];

            for (int i = 0; i < N; i++) {
                    A[i] = new double[N];
                    result[i] = new double[N];
                    nakopitel[i] = new double[N];
            }

            cout << "Введите элементы матрицы A:" << endl;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                cin >> A[i][j];
                result[i][j] = A[i][j];
                }
            }   

            for (int power_of_number = 2; power_of_number <= K; power_of_number++){
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        nakopitel[i][j] = 0;
                        for (int m = 0; m < N; m++) {
                            nakopitel[i][j] += result[i][m] * A[m][j];
                        }
                    }
                }
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        result[i][j] = nakopitel[i][j];
                    }
                }
            }   
            cout << "Результат:" << endl;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
            for (int i = 0; i < N; i++) {
                delete[] A[i];
                delete[] result[i];
                delete[] nakopitel[i];
            }
            delete[] A;
            delete[] result;
            delete[] nakopitel;
        }
        } while (choice != 2);

    return 0;
}
