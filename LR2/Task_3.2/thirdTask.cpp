#include <iostream>
using namespace std;

int main() {
    double b1;
    int n = 2;
    cout << "Введите b1: ";
    cin >> b1;
    double q = 1.0 / (n+1);
    double sum = b1 / ( 1 - q);
cout << "Сумма прогрессии: " << sum << endl;

    return 0;
}