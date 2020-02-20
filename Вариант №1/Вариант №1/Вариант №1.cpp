// Вариант №1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void input(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
}

void output(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "a[" << i << "]: " << a[i] << endl;
	}
}

int maxi(int a[], int n)
{
	int i, max=0, mi=0;
	for (i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			mi = i;
		}
	}
	return mi;
}

int mini(int a[], int n)
{
	int i, min = 999999;
	for (i = 0; i < n; i++)
	{
		if (a[i] < min) min = a[i];
	}
	cout << min << endl;
	return min;
}

int first(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] < 0) return i;
	}
}

void swap(int a[], int n)
{
	int t = a[maxi(a, n)];
	a[maxi(a, n)] = a[first(a, n)];
	a[first(a, n)] = t;
}

void srz(int a[], int n)
{
	int i, sum = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] != maxi(a, n) || a[i] != mini(a, n)) sum += a[i];
	}
	cout << "SRZ: " << sum / (n - 2) << endl;
}

void average_mines(int a[], int n)
{
	int i, sum=0;
	for (i = 0; i < n; i++)
	{
		sum += a[i];
	}
	sum = sum / n;
	for (i = 0; i < n; i++)
	{
		a[i] = a[i] - sum;
	}
}

void input2(int** b, int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			b[i][j] = rand();
		}
	}
}

void output2(int** b, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%5d ", b[i][j]);
		}
		cout << endl;
	}
}

int harakter(int** b, int n, int m)
{
	int i, j, sum = 0, max=0, mi=0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (b[i][j] > 0 && b[i][j] % 2 == 0) sum += b[i][j];
		}
		if (sum > max)
		{
			max = sum;
			mi = i;
		}
		sum = 0;
	}
	return mi;
}

int main()
{
	int i, n, m, j;
	cout << "N= ";
	cin >> n;
	cout << endl;
	int* a = new int;
	*a = n;
	input(a, n);
	cout << "№1: " << endl;
	average_mines(a, n);
	cout << endl;
	output(a, n);
	swap(a, n);
	cout << endl;
	output(a, n);
	srz(a, n);


	cout << "№2" << endl;
	cout << "N= ";
	cin >> n;
	cout << "M= ";
	cin >> m;
	int** b;
	b = new int* [n];
	for (i = 0; i < n; i++)
	{
		b[i] = new int[m];
	}
	input2(b, n, m);
	output2(b, n, m);
	cout << "Max line: " << harakter(b, n, m) << endl;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
