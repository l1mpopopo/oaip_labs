#include "array_lib.h"

bool checkHalf(const double* X, int left, int right) {
    if (left == right) {
        double cube = X[left] * X[left] * X[left];
        return (cube > -10.0) && (cube < 20.0);
    }

    int mid = left + (right - left) / 2;
    return checkHalf(X, left, mid) && checkHalf(X, mid + 1, right);
}

bool solveTask2(const double* X, int n) {
    if (n <= 0 || X == nullptr) {
        return false;
    }
    return checkHalf(X, 0, n - 1);
}