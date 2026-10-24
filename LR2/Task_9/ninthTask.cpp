#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    double a,fi,b,x,z,y;
int journal;
cout << "Введите от 1 до 3 какую функцию вы хотите получить ( 1)2x , 2)x^3 , 3):x/3) : ";
cin >> journal;
cout << "Введите значение a: ";
cin >> a;
cout << "Введите значение z: ";
cin >> z;
cout << "Введите значение b: ";
cin >> b;

if (z<1) { 

    x = 2 + z;
    cout << "Значение z<1 , значение 2 + x = " << x << endl;
} else {

    x = pow(sin(z), 2);
    cout << "Значение z >= 1 , значение sin(z)^2 = " << x << endl;
}

switch (journal)
{
case 1:
    fi = 2* x;
    cout << "Функция f(x) = 2 * x равна 2" << fi << endl;
    break;

    case 2:
    fi = pow(x,3);
    cout << "Функция f(x) = x^3 равна "  << fi << endl;
    break;

    case 3:
    fi = x/3;
    cout << "Функция f(x) = x/3 равна " << fi << endl;
    break;

default:
    cout << "Для номера " << journal << " не существует такой функции " << endl;
    break;
    return 1;
}

y = (2 * a * fi + b * cos(sqrt(fabs(x)))) /  (pow(x,2) + 5);
cout << "Значение y = " << y << endl;

    return 0;
}