#include <iostream>
#include <iomanip>
using namespace std;

int** createArr(int n, int k) {
    int** arr = new int*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[k];
    }
    return arr;
}

void deleteArr(int** arr, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

void inputArr(int** arr, int n, int k) {
    cout << "Введите элементы массива A (" << n << "x" << k << "):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << "A[" << i << "][" << j << "] = ";
            while (!(cin >> arr[i][j])) {
                cout << "Ошибка ввода! Введите целое число: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }
    }
}

void printArr(int** arr, int n, int k) {
    cout << "\nИсходный массив A:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << setw(6) << arr[i][j];
        }
        cout << '\n';
    }
}

// Создание одномерного динамического массива из чётных элементов главной диагонали
int* extractEvenDiagonal(int** arr, int n, int k, int& outSize) {
    int diagLen = n;
    if (k < n) {
        diagLen = k;
    
    }
    outSize = 0;

    for (int i = 0; i < diagLen; ++i) {
        if (arr[i][i] % 2 == 0) {
            ++outSize;
        }
    }

    if (outSize == 0) {
        return nullptr;
    }

    int* result = new int[outSize];
    int idx = 0;
    for (int i = 0; i < diagLen; ++i) {
        if (arr[i][i] % 2 == 0) {
            result[idx++] = arr[i][i];
        }
    }

    return result;
}

long long calculateProduct(const int* arr, int size) {
    long long product = 1;
    for (int i = 0; i < size; ++i) {
        product *= arr[i];
    }
    return product;
}

int main() {
    int choice = 0;
    do {
        cout << "\n--- Выполнил: Банчук Георгий, гр.653501 ---" << endl;
        cout << "Задание 3." << endl;
        cout << "Дан двумерный динамический массив целых чисел А размерностью n x k. Размерность массива ввести с клавиатуры." << endl;
        cout << "Значения элементов массива ввести с клавиатуры. Создать динамический массив из элементов, расположенных на главной" << endl;
        cout << "диагонали матрицы и имеющих четное значение. Вычислить произведение элементов динамического массива." << endl;
        cout << "Созданный массив и результат произведения вывести на экран. Использовать функции." << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
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

            int** A = createArr(n, k);
            inputArr(A, n, k);
            printArr(A, n, k);

            int evenCount = 0;
            int* evenDiag = extractEvenDiagonal(A, n, k, evenCount);

            if (evenCount == 0) {
                cout << "\nНа главной диагонали нет чётных элементов. Новый массив пуст, произведение не вычисляется." << endl;
            } else {
                cout << "\nСозданный массив из чётных элементов главной диагонали (" << evenCount << " шт.):\n";
                for (int i = 0; i < evenCount; ++i) {
                    cout << evenDiag[i] << " ";
                }
                cout << '\n';

                long long product = calculateProduct(evenDiag, evenCount);
                cout << "Произведение элементов созданного массива: " << product << endl;

                delete[] evenDiag;
            }

            deleteArr(A, n);
            cin.ignore(1000, '\n');
        }
    } while (choice != 2);

    return 0;
}