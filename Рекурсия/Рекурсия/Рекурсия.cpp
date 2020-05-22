
#include <iostream>
using namespace std;

long int fact1(int n, int z);

void menu();

int fact2(int n);

int fact3(int n);

int rec(int a[], int n);

int fact5(int n, int r);

int Fait(int n);

int Gate(int n);

int main()
{
    setlocale(LC_ALL, "Russian");
    int namber = 1;
    while (namber != 0)
    {
        menu();
        cout << "Задание № ";
        cin >> namber;

        switch (namber) {
        case 1: {
            int n = 0, z=0;
            cout << "Введите число для вычисления факториала: ";
            cin >> n;
            cout << "Рекурсивный факториал для числа " << n << " = " << fact1(n, z+1) << endl;
            cout << "Количество вызовов рекурсии " << z << endl;
            {
                int res = 1;
                for (int i = 1; i <= n; i++) {
                    res = res * i;
                }
                cout << "Прямой алгоритм факториала для числа " << n << " = " << res << endl;
            }
            break;
        }
        case 2: {
            int n;
            cout << "Введите число для вычисления значения функции: " << endl;
            cin >> n;
            cout << "Функция F(" << n << ") равна " << fact2(n) << endl;
            break;
        }
        case 3: {
            int n;
            cout << "Введите число для проверки, является ли число точной степенью двойки: " << endl;
            cin >> n;
            if (fact3(n))
                printf("YES\n");
            else
                printf("NO\n");
            break;
        }
        case 4: {
            int n = 0;
            cout << "Введите количество элементов в массиве: " << endl;
            cin >> n;
            int *a = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = rand() % 100;
                cout << a[i] << " ";
            }
            cout << endl;
            cout << "Сумма ничетных элементов= " << rec(a, n) << endl;
            break;
        }
        case 5: {
            int n, r=0;
            cout << "Введите число которое нужно развернуть: " << endl;
            cin >> n;
            cout << "Число " << n << " записанное в обратном порядке ";
            int k = n;
            for (int i = 0; k>0; i++)
            {
                k = k / 10;
                r++;
            }
            cout << fact5(n, r) << endl;
            cout << endl;
            break;
        }
        case 6: {
            int n = 0;
            cout << "Введите число, для нахождения значения функций: " << endl;
            for (n = 1; n < 11; n++)
            {
                cout << "Fait(" << n << ")= " << Fait(n) << "   Gate(" << n << ")= " << Gate(n) << endl;
            }
            break;
        }
        case 0: {
            cout << "EXIT..." << endl;
            cout << "..." << endl;
            cout << "..." << endl;
            return 0;
        }
        }
    }
    return 0;
}

long int fact1(int n, int z)
{
    if (n == 0)
    {
        cout << z << endl;
        return 1;
    }
    else
        
        return n * fact1(n - 1, z+1);
    
}

int fact2(int n)
{
    if (n == 1) return 3;
    else
        return (n - 1) * fact2(n - 1);
}

int fact3(int n)
{
    if (n == 2) return 1;
    if (n % 2 == 1) return 0;
    else return fact3(n / 2);
}

int rec(int a[], int n)
{
    if (n < 0)  return 0;
    else
    {
        if (a[n - 1] % 2 == 1) return (rec(a, n - 1) + a[n - 1]);
        else return rec(a, n - 1);
    }
}

int fact5(int n, int r)
{
    if (n < 10) return n;
    else
    {
        int k = (n % 10) * pow(10, r - 1);
        return (k + fact5(n / 10, r - 1));
    }
}

int Fait(int n)
{
    if (n == 1) return -2;
    else
    {
        return 5 * Fait(n - 1) - Gate(n - 1);
    }
}

int Gate(int n)
{
    if (n == 1) return 2;
    else
    {
        return 2 * Fait(n - 1) - Gate(n-1);
    }
}
void menu()
{
    cout << "1 - Задание 1" << endl;
    cout << "2 - Задание 2" << endl;
    cout << "3 - Задание 3" << endl;
    cout << "4 - 8 вариант- 1 задание" << endl;
    cout << "5 - 8 вариант- 2 задание" << endl;
    cout << "6 - 8 вариант- 3 задание" << endl;
    cout << "0 - EXIT" << endl;
}