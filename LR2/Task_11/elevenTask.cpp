#include <iostream>
#include <cmath>
using namespace std;


int main () {

    int h1,h2,min1,min2,hout,minout ;
    char dvoetoch = ':';
cout << "Введите часы и минуты, когда начата работа (через :):  ";
cin >> h1 >> dvoetoch >> min1;
cout << "Введите часы и минуты, когда законечна работа (через :):  ";
cin >> h2  >> dvoetoch >> min2;

hout = h2-h1;
minout = min2 - min1;
if (minout < 0) {
    minout = minout + 60;
    hout = hout - 1;


}
if (hout < 0) {
    hout = hout + 24;
}
cout << "На работу затрачено: " << hout  << "ч. " << minout << "мин. " << endl ;


    return 0;
}


