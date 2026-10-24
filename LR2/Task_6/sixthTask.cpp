#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double A,b,D,x,S;

    cout << "Введите значение D: ";
    cin >> D;
    cout << "Введите значение x: ";
    cin >> x;

    b = x + D;
    A = D * x / b;
    S = (pow(A,2) + b * cos(x)) / (pow(D,3) + (A +D - b));
    cout << "S = " << S << endl;
    return 0;
}
