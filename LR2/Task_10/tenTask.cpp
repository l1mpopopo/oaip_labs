#include <iostream>
#include <cmath>
using namespace std;

int main() {

        double x1,x2,y1,y2,r,R,d;

        cout << "Введите значение x1: ";
        cin >> x1;
        cout << "Введите значение y1: ";
        cin >> y1;
        cout << "Введите значение x2: ";
        cin >> x2;
        cout << "Введите значение y2: ";
        cin >> y2;
        cout << "Введите радиус r: ";
        cin >> r;
        cout << "Введите значение R: ";
        cin >> R;


    d = sqrt((pow(x2-x1,2) + pow(y2-y1,2)));

    if ( d + r <= R)
    {
        cout << "Да" << endl;
    } else if (d + R <= r)
    {
        cout << "Да, но справедливо обратное для двух фигур" << endl;
    } else if (fabs(R-r) < d && d < (R+r))
    {
        cout << "Фигуры пересекаются" << endl;
    }
    
    else{

        cout << "Ни одно условие не выполнено"  << endl;
    }



    return 0;
}