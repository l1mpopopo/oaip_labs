#include <iostream>
 using namespace std;
int main () {
int x, y;
double a,b,c,k;
cout << "Введите значение x: " ;    
cin >> x; 
cout << "Введите значение y: " ;    
cin >> y;
cout << "Введите значение a: " ;
cin >> a;
cout << "Введите значение b: " ;
cin >> b;
cout << "Введите значение c: " ;
cin >> c;
cout << "Введите значение k: " ;
cin >> k;

if (x > y ) {
	y = 0;
}
 else if ( x < y ) {
	x = 0; 
}
else {
   x= 0;
 y = 0;
}

if ( a > c && a > b) {
   a -= k;
} else if ( b > c && b > a) {
  b -= k;
} else {
   c -= k;
}
cout << "X: " << x << "\n Y: " << y << "\n" ;
cout << "A: " << a << "\n B: " << b << "\n C: " << c << endl ;
  
return 0;
}
