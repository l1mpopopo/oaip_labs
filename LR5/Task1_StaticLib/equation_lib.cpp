#include "equation_lib.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void solveTask1(const double* A, int sizeA, const double* B, int sizeB) {
    cout << "\nРезультаты решения уравнения a_i * x + b_j = 0:\n";
    cout << fixed << setprecision(4);

    for (int i = 0; i < sizeA; ++i) {
        for (int j = 0; j < sizeB; ++j) {
            double x = 0.0;
            if (abs(A[i]) > 1e-12) {
                x = -B[j] / A[i];
                if (abs(x) < 1e-12) {
                    x = 0.0;
                }
            } else {
                x = 0.0;
            }

            cout << "a " << i << " = " << A[i]
                 << ", b " << j << " = " << B[j]
                 << "  ,  x = " << x << '\n';
        }
    }
}