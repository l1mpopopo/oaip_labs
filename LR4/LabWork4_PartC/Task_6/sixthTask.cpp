
#include <iostream>
#include <iomanip>
#include <new>

using namespace std;

int main() {
    int choice = 0;
    long long n;
    long long** a = nullptr;

    do {
        cout << "\n--- Выполнил: Банчук Георгий, гр.653501 ---" << endl;
        cout << "Вариант 2" << endl;
        cout << "Построить магический квадрат. Порядок квадрата задаётся пользователем. Максимальный размер магического квадрата не превышает 2^32 - 1." << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "1. Запустить выполнение программы" << endl;
        cout << "2. Выйти из программы" << endl;
        cout << "Выберите действие (1-2): ";

        while (!(cin >> choice) || choice < 1 || choice > 2) {
            cout << "Некорректный ввод! Введите число 1 или 2: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (choice == 1) {

            do {
                cout << "\nВведите порядок магического квадрата N: ";

                if (!(cin >> n)) {
                    cout << "Ошибка: введите целое число." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    n = 0;
                }
                else if (n < 1 || n > 4294967295LL) {
                    cout << "Ошибка: N должно быть от 1 до 4294967295." << endl;
                }
                else if (n == 2) {
                    cout << "Магического квадрата порядка 2 не существует." << endl;
                }

            } while (n < 1 || n > 4294967295LL || n == 2);

            if (n > 2000) {
                cout << "Слишком большой размер для выделения памяти." << endl;
            }
            else {

                bool memory = true;
                long long rows = 0;

                a = new (nothrow) long long*[n];

                if (a == nullptr) {
                    memory = false;
                }
                else {
                    while (rows < n && memory) {
                        a[rows] = new (nothrow) long long[n]();

                        if (a[rows] == nullptr) {
                            memory = false;
                        }
                        else {
                            rows++;
                        }
                    }
                }

                if (!memory) {
                    cout << "Ошибка: не хватает памяти для квадрата." << endl;

                    for (long long i = 0; i < rows; i++) {
                        delete[] a[i];
                    }

                    delete[] a;
                    a = nullptr;
                }
                else {

                    long long total = n * n;

                    if (n % 2 == 1) {

                        long long i = 0;
                        long long j = n / 2;

                        for (long long num = 1; num <= total; num++) {
                            a[i][j] = num;

                            long long next_i = (i - 1 + n) % n;
                            long long next_j = (j + 1) % n;

                            if (a[next_i][next_j] != 0) {
                                i = (i + 1) % n;
                            }
                            else {
                                i = next_i;
                                j = next_j;
                            }
                        }
                    }

                    else if (n % 4 == 0) {

                        for (long long r = 0; r < n; r++) {
                            for (long long c = 0; c < n; c++) {
                                a[r][c] = r * n + c + 1;
                            }
                        }

                        for (long long r = 0; r < n; r++) {
                            for (long long c = 0; c < n; c++) {
                                if (r % 4 == c % 4 ||
                                    (r % 4) + (c % 4) == 3) {
                                    a[r][c] = total + 1 - a[r][c];
                                }
                            }
                        }
                    }

                    else {

                        long long m = n / 2;
                        long long k = (m - 1) / 2;
                        long long mm = m * m;

                        long long i = 0;
                        long long j = m / 2;

                        for (long long num = 1; num <= mm; num++) {
                            a[i][j] = num;

                            long long next_i = (i - 1 + m) % m;
                            long long next_j = (j + 1) % m;

                            if (a[next_i][next_j] != 0) {
                                i = (i + 1) % m;
                            }
                            else {
                                i = next_i;
                                j = next_j;
                            }
                        }

                        for (long long r = 0; r < m; r++) {
                            for (long long c = 0; c < m; c++) {
                                long long v = a[r][c];

                                a[r][c + m] = v + 2 * mm;
                                a[r + m][c] = v + 3 * mm;
                                a[r + m][c + m] = v + mm;
                            }
                        }

                        for (long long r = 0; r < m; r++) {
                            for (long long c = 0; c < n; c++) {

                                bool swapIt = false;

                                if (c < k) {
                                    swapIt = true;
                                }

                                if (r == m / 2 && c >= 1 && c <= k) {
                                    swapIt = true;
                                }

                                if (r == m / 2 && c == 0) {
                                    swapIt = false;
                                }

                                if (c > n - k) {
                                    swapIt = true;
                                }

                                if (swapIt) {
                                    long long temp = a[r][c];
                                    a[r][c] = a[r + m][c];
                                    a[r + m][c] = temp;
                                }
                            }
                        }
                    }

                    if (n <= 15) {
                        cout << "\nМагический квадрат порядка " << n << ":" << endl;

                        for (long long r = 0; r < n; r++) {
                            for (long long c = 0; c < n; c++) {
                                cout << setw(6) << a[r][c] << " ";
                            }
                            cout << endl;
                        }

                        long long magic_sum = 0;

                        for (long long c = 0; c < n; c++) {
                            magic_sum += a[0][c];
                        }

                        cout << "\nМагическая константа = " << magic_sum << endl;
                    }
                    else {
                        cout << "\nКвадрат успешно построен, но слишком велик для вывода на экран!" << endl;
                    }

                    for (long long i = 0; i < n; i++) {
                        delete[] a[i];
                    }

                    delete[] a;
                    a = nullptr;
                }
            }
        }

    } while (choice != 2);

    return 0;
}
