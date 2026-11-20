#include "equation_lib.h"
#include <iostream>
#include <iomanip>

using namespace std;

void solveTask1(const double* A, int sizeA, const double* B, int sizeB) {
    cout << "\nРезультаты решения уравнения a_i * x + b_j = 0:\n";
    cout << fixed << setprecision(4);

    for (int i = 0; i < sizeA; ++i) {
        for (int j = 0; j < sizeB; ++j) {
            double x = 0.0;
            if (A[i] != 0.0) {
                x = -B[j] / A[i];
                if (x == 0.0) {
                    x = 0.0; 
                }
            }

            cout << "a " << i << " = " << A[i]
                 << ", b " << j << " = " << B[j]
                 << "  ,  x = " << x << '\n';
        }
    }
}