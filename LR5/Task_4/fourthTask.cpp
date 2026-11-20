#include <iostream>
#include <iomanip>

using namespace std;

double** createArr(int n, int k) {
    double** arr = new double*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new double[k];
    }
    return arr;
}

void deleteArr(double** arr, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

void inputArr(double** arr, int n, int k) {
    cout << "Введите элементы массива (" << n << "x" << k << "):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << "A[" << i << "][" << j << "] = ";
            while (!(cin >> arr[i][j])) {
                cout << "Ошибка ввода! Введите вещественное число: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }
    }
}

void printArr(double** arr, int n, int k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << setw(8) << arr[i][j];
        }
        cout << '\n';
    }
}

int findZeros(double** arr, int n, int k) {
    int zeroCount = 0;
    cout << "\nПоиск элементов с нулевым значением:\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (arr[i][j] == 0.0) {
                cout << "Найден нулевой элемент на позиции [" << i << "][" << j << "]\n";
                ++zeroCount;
            }
        }
    }

    if (zeroCount == 0) {
        cout << "Элементы с нулевым значением в массиве не встречаются.\n";
    } else {
        cout << "Общее количество нулевых элементов: " << zeroCount << '\n';
    }

    return zeroCount;
}

void reverseArr(double** arr, int n, int k) {
    int total = n * k;
    int left = 0;
    int right = total - 1;

    while (left < right) {
        int r1 = left / k;
        int c1 = left % k;
        int r2 = right / k;
        int c2 = right % k;

        double temp = arr[r1][c1];
        arr[r1][c1] = arr[r2][c2];
        arr[r2][c2] = temp;

        ++left;
        --right;
    }
}

int main() {
    int choice = 0;
    do {
        cout << "\n--- Выполнил: Банчук Георгий, гр.653501 ---" << endl;
        cout << "Задание 4." << endl;
        cout << "Создать двумерный динамический массив вещественных чисел. Определить, встречаются ли среди них элементы" << endl;
        cout << "с нулевым значением. Если встречаются такие элементы, то определить их индексы и общее количество." << endl;
        cout << "Переставить элементы этого массива в обратном порядке и вывести на экран. Использовать функции." << endl;
        cout << "------------------------------------------------------------------------------------------------------------" << endl;
        cout << "1. Запустить выполнение программы" << endl;
        cout << "2. Выйти из программы" << endl;
        cout << "Выберите действие (1-2): ";

        while (!(cin >> choice) || choice < 1 || choice > 2) {
            cout << "Некорректный ввод! Введите число 1 или 2: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        if (choice == 1) {
            int n = 0, k = 0;
            cout << "\nВведите количество строк n: ";
            while (!(cin >> n) || n <= 0) {
                cout << "Ошибка! Введите целое положительное число: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            cout << "Введите количество столбцов k: ";
            while (!(cin >> k) || k <= 0) {
                cout << "Ошибка! Введите целое положительное число: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            double** A = createArr(n, k);
            inputArr(A, n, k);

            cout << "\nИсходный массив:\n";
            printArr(A, n, k);

            findZeros(A, n, k);

            reverseArr(A, n, k);
            cout << "\nМассив после перестановки элементов в обратном порядке:\n";
            printArr(A, n, k);

            deleteArr(A, n);
            cin.ignore(1000, '\n');
        }
    } while (choice != 2);

    return 0;
}