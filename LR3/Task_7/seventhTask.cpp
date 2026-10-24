#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int choice = 0;

        do {
            cout << "\n--- Выполнил: Банчук Георгий, гр.653501 ---" << endl;
            cout << "Числа Армстронга (названные в честь Майкла Ф. Армстронга (Michael F. Armstrong)), их также называют самовлюбленными числами и совершенными цифровыми инвариантами, – это числа, равные сумме своих цифр, возведенных в степень, равную количеству цифр. Например, наименьшее число Армстронга – 153, которое равно 1^3 + 5^3 + 3^3. Напишите программу, которая выводит все числа Армстронга, меньше введённого пользователем числа." << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "1. Запустить выполнение программы" << endl;
            cout << "2. Выйти из программы" << endl;
            cout << "Выберите действие (1-2): ";

        while (!(cin >> choice) || choice < 1 || choice > 2) {
            cout << "Некорректный ввод! Введите число 1 или 2: ";
            cin.clear(); 
            cin.ignore(100, '\n');
        }

        if (choice == 1){
            int limit = 0;
            cout << "Введите число, до которого искать числа Армстронга: ";
            
            
            while (!(cin >> limit) || limit <= 0) {
                cout << "Некорректный ввод! Введите целое положительное число: ";
                cin.clear();
                cin.ignore(100, '\n');
            }
            
            for (int number = 1; number < limit; number++) {
                
                int temp = number;
                int count_digits = 0;
                while (temp > 0) {
                    count_digits++;
                    temp /= 10; 
                }

                temp = number;
                int sum = 0;
                while (temp > 0) {
                    int digit = temp % 10; 
                    sum += pow(digit, count_digits); 
                    temp /= 10; 
                }

                
                if (sum == number) {
                    
                    cout << number << " ";
                }
            }
            
        }
    } while (choice != 2);
     
    return 0;
}

