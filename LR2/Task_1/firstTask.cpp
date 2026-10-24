#include <iostream>
using namespace std;
int main() {

    /*  (8  + 69x^2) + (23x^3 + 32x)  and  (69x2 + 8) - (23x3 + 32x)     */
double x;
cout << "Введите x:";
cin >> x;

double x2 = x*x ;
double t = 23 * x2 ;
double d = x * (t + 32);
double f = 8 + 3*t;
double A = f + d;
double B = f - d; 

cout << "Результат сложения: " << A << endl;
cout << "Результат вычитания: " << B << endl;
return 0;
}