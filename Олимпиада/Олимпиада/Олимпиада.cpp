#include <iostream>
#include <fstream>
using namespace std;

void line(int a[], int n)
{
    int i, j, min, mink = 0, t;
    for (i = 0; i < n - 1; i++)
    {
        min = a[i];
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                mink = j;
            }
        }
        if (a[i] > min)
        {
            t = a[i];
            a[i] = a[mink];
            a[mink] = t;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 0, t = 0;
    ifstream F1;
    ofstream F2;
    F1.open("input.txt", ios::in);
    F2.open("output.txt", ios::out);
    F1 >> n;
    t = n;
    int* a;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        F1 >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                a[j] = -1;
                t = t - 1;
            }
        }
    }
    line(a, n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != -1) F2 << a[i] << " ";
    }
    return 0;
}