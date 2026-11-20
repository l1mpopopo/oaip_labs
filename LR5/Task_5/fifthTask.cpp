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
    cout << "Введите элементы массива (" << n << "x" << k << "):\n";
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
    cout << "\nИсходный массив:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << setw(6) << arr[i][j];
        }
        cout << '\n';
    }
}

int* extractOddFromEvenCols(int** arr, int n, int k, int& outSize) {
    outSize = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; j += 2) {
            if (arr[i][j] % 2 != 0) {
                ++outSize;
            }
        }
    }

    if (outSize == 0) {
        return nullptr;
    }

    int* result = new int[outSize];
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; j += 2) {
            if (arr[i][j] % 2 != 0) {
                result[idx++] = arr[i][j];
            }
        }
    }

    return result;
}

double calculateAverage(const int* arr, int size) {
    long long sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

int main() {
    int choice = 0;
    do {
        cout << "\n--- Выполнил: Банчук Георгий, гр.653501 ---" << endl;
        cout << "Задание 5." << endl;
        cout << "Дан двумерный динамический массив целых чисел. Значения элементов данного массива ввести с клавиатуры." << endl;
        cout << "Создать динамический массив из элементов, расположенных в четных столбцах данного массива и имеющих" << endl;
        cout << "нечетное значение. Вычислить среднее арифметическое элементов динамического массива. Вывести результат" << endl;
        cout << "на экран. Использовать функции." << endl;
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

            int** A = createArr(n, k);
            inputArr(A, n, k);
            printArr(A, n, k);

            int oddCount = 0;
            int* oddArr = extractOddFromEvenCols(A, n, k, oddCount);

            if (oddCount == 0) {
                cout << "\nВ чётных столбцах нет нечётных элементов. Новый массив пуст, среднее арифметическое не вычисляется." << endl;
            } else {
                cout << "\nСозданный массив из нечётных элементов чётных столбцов (" << oddCount << " шт.):\n";
                for (int i = 0; i < oddCount; ++i) {
                    cout << oddArr[i] << " ";
                }
                cout << '\n';

                double avg = calculateAverage(oddArr, oddCount);
                cout << "Среднее арифметическое элементов созданного массива: " << avg << endl;

                delete[] oddArr;
            }

            deleteArr(A, n);
            cin.ignore(1000, '\n');
        }
    } while (choice != 2);

    return 0;
}