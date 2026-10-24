#include <iostream>
using namespace std;
int main() {
 double x,y,z;
cout << "Введите x: " ; cin >> x;
cout << "Введите y: " ; cin >> y;
cout << "Введите z: " ; cin >> z;

if (x > 0 &&y > 0 && z > 0 && (x+y > z) && (x+z > y)  && (y+z > x)) {

       cout << "Существует\n"; 

}
else {

    cout << "Не существует\n";
}

return 0;


}