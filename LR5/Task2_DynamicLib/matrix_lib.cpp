#include "matrix_lib.h"
#include <iostream>
#include <iomanip>

using namespace std;

double** createArr(int n) {
    double** arr = new double*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new double[n];
    }
    return arr;
}

void freeArr(double** arr, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

void fillArrs(double** A, double** B, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = 3.0 * i * j - 3.0;
            B[i][j] = 2.0 * i * j - 2.0;
        }
    }
}

void printArr(double** arr, int n, const char* name) {
    cout << "\nМатрица " << name << " (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(8) << arr[i][j];
        }
        cout << '\n';
    }
}

double sumMainDiagonal(double** arr, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i][i];
    }
    return sum;
}

void solveTask2(int n) {
    double** A = createArr(n);
    double** B = createArr(n);

    fillArrs(A, B, n);

    printArr(A, n, "A");
    printArr(B, n, "B");

    double sumA = sumMainDiagonal(A, n);
    double sumB = sumMainDiagonal(B, n);

    cout << "\nСумма элементов главной диагонали матрицы A: " << sumA << '\n';
    cout << "Сумма элементов главной диагонали матрицы B: " << sumB << '\n';

    freeArr(A, n);
    freeArr(B, n);
}
