#include <iostream>
using namespace std;
int main() {

double x, y;
cout << "Введите значение x: ";
cin >> x;
cout << "Введите значение y: ";   
cin >> y;
double maxXY;
if ( x > y ){
   maxXY = x; 
 
}  else {
  maxXY = y;
}

cout << "Максимум: " << maxXY << "\n";
return 0;
}
