#include <iostream>
#include <cmath>
using namespace std;


int main() {
double x1, y1, x2, y2, x3, y3;
cout << "Введите x1 y1 x2 y2 x3 y3: ";
cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

double PI = acos(-1.0);

    /* стороны */ 
double a = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));  
double b = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));  
double c = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));  
double p = (a + b + c) / 2;
    
    /* углы */ 
double angA = acos((b*b + c*c - a*a) / (2*b*c));
double angB = acos((a*a + c*c - b*b) / (2*a*c));
double angC = acos((a*a + b*b - c*c) / (2*a*b));
 /* площади */
double S1 = fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2;
double S2 = sqrt(p * (p - a) * (p - b) * (p - c));
double S3 = 0.5 * b * c * sin(angA);
double S = S1;

    /* высоты */ 
double ha = 2 * S / a, hb = 2 * S / b, hc = 2 * S / c;


    /* медианы */ 
double ma = 0.5 * sqrt(2*b*b + 2*c*c - a*a);
double mb = 0.5 * sqrt(2*a*a + 2*c*c - b*b);
double mc = 0.5 * sqrt(2*a*a + 2*b*b - c*c);

    /* биссектриссы */ 
double la = sqrt(b * c * ((b + c) * (b + c) - a * a)) / (b + c);
double lb = sqrt(a * c * ((a + c) * (a + c) - b * b)) / (a + c);
double lc = sqrt(a * b * ((a + b) * (a + b) - c * c)) / (a + b);

    /* радиусы */ 
double r = S / p;
double R = a * b * c / (4 * S);
   
   

    cout << "Стороны: a(BC) = " << a << ", b(AC) = " << b << ", c(AB) = " << c << endl;
    cout << "Высоты: ha = " << ha << ", hb = " << hb << ", hc = " << hc << endl;
    cout << "Медианы: ma = " << ma << ", mb = " << mb << ", mc = " << mc << endl;
    cout << "Биссектрисы: la = " << la << ", lb = " << lb << ", lc = " << lc << endl;
    cout << "Углы (рад): A = " << angA << ", B = " << angB << ", C = " << angC << endl;
    cout << "Углы (град): A = " << angA * 180 / PI << ", B = " << angB * 180 / PI << ", C = " << angC * 180 / PI << endl;
    cout << "Радиус вписанной r = " << r << ", описанной R = " << R << endl;
    cout << "Вписанная: площадь = " << PI * r * r << ", длина = " << 2 * PI * r << endl;
    cout << "Описанная: площадь = " << PI * R * R << ", длина = " << 2 * PI * R << endl;
    cout << "Периметр = " << a + b + c << endl;
    cout << "Площадь (координаты) = " << S1 << endl;
    cout << "Площадь (Герон) = " << S2 << endl;
    cout << "Площадь (через угол) = " << S3 << endl;
    return 0;
}