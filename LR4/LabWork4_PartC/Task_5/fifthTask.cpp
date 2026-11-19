#include <iostream>
using namespace std;

int main() {
    int choice = 0;
    do {
        cout << "\n--- Выполнил: Банчук Георгий, гр.653501 ---" << endl;
        cout << "Вариант 2" << endl;
        cout << "На вход подаётся поле для игры в 'сапёр' размером n*m символов, где символ '.' означает пустое место, а символ '*' - бомбу. Требуется дополнить это поле числами, как в оригинальной игре." << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "1. Запустить выполнение программы" << endl;
        cout << "2. Выйти из программы" << endl;
        cout << "Выберите действие (1-2): ";

        while (!(cin >> choice) || choice < 1 || choice > 2) {
            cout << "Некорректный ввод! Введите число 1 или 2: ";
            cin.clear();
            cin.ignore(100, '\n');
        }

        if (choice == 1) {
            int n, m;
            cout << "Количество строк (n): ";
            cin >> n;
            cout << "Количество столбцов (m): ";
            cin >> m;

            char** field = new char*[n];
            for (int i = 0; i < n; i++) {
                field[i] = new char[m];
            }

            cout << "Введите игровое поле ('.' - пустая клетка, '*' - мина):\n";
            for (int i = 0; i < n; i++) {
                cout << "Строка " << i + 1 << ": ";
                for (int j = 0; j < m; j++) {
                cin >> field[i][j];
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (field[i][j] == '*') {
                        continue;
                    }

                    int count = 0;
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            int ni = i + di;
                            int nj = j + dj;

                            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                                if (field[ni][nj] == '*') {
                                    count++;
                                }
                            }
                        }
                    }

                    if (count > 0) {
                        field[i][j] = '0' + count;
                    }
                    else {
                    field[i][j] = '0';
                    }
                }
            }
        
        cout << "\nРезультат:\n\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
            cout << field[i][j] << "   ";
        }
            cout << "\n\n";
        }
        for (int i = 0; i < n; i++){
            delete[] field[i];
        }
        delete[] field;
        }    
} while (choice != 2);

    return 0;
}
