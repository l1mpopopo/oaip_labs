#include <iostream>
#include <cmath>

using namespace std;
int main() {
   double p,q,r,phi,u,v,x1,x2,x3;
   cout << "Введите значение p,q через пробел: ";
   cin >> p >> q;

   double Q = pow(p / 3.0, 3) + pow(q / 2.0, 2);
if (Q > 0) {
        u = cbrt(-q / 2.0 + sqrt(Q));
        v = cbrt(-q / 2.0 - sqrt(Q));
        x1 = u + v;
        
        cout << "x1 = " << x1 << endl;
    } 
    else if (Q == 0) {
        
         u = cbrt(-q / 2.0);
        x1 = 2 * u;
        x2 = -u;
        cout << "x1 = " << x1 << endl;
        cout << "x2,3 = " << x2 << endl;
    } 
    else {
     
         r = 2.0 * sqrt(-p / 3.0);
         phi = acos(-q / (2.0 * sqrt(pow(-p / 3.0, 3))));
        
         x1 = r * cos(phi / 3.0);
         x2 = r * cos((phi + 2.0 * M_PI) / 3.0);
         x3 = r * cos((phi + 4.0 * M_PI) / 3.0);
        
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        cout << "x3 = " << x3 << endl;
    }

    return 0;
}