// Вариант №2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	int i, max = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] > max) max = a[i];
	}
	return max;
}

int average(int a[], int n)
{
	int i, sum = 0, m=0, j;
	for (i = 0; i < n; i++)
	{
		sum += a[i];
	}
	m= sum / n;
	cout << "SRZ: " << m << endl;
	for (j = m; j < maxi(a, n); j++)
	{
		for (i = 0; i < n; i++)
		{
			if (a[i] == j) return i;
		}
	}
}

int mini(int a[], int n)
{
	int i, min = maxi(a, n);
	for (i = 0; i < n; i++)
	{
		if (a[i] > 0 && a[i] < min) min = a[i];
	}
	return min;
}

int summ(int a[], int n)
{
	int i, sum=0;
	for (i = 0; i < n; i++)
	{
		if (a[i] < 0) return sum;
		else sum += a[i];
	}
	return sum;
}

void input2(int** b, int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			b[i][j] = rand() % 200 - 100;
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
	int i, j, sum=0, min=999999, mi=0;
	for (j = 0; j < m; j++)
	{
		sum = 0;
		for (i = 0; i < n; i++)
		{
			if ((b[i][j] < 0) && (abs(b[i][j]) % 2 == 1)) sum += abs(b[i][j]);
		}
		if (sum < min)
		{
			min = sum;
			sum = 0;
			mi = j;
		}
	}
	return mi;
}

int main()
{
	int i, n, m, j;
	cout << "№1" << endl;
	cout << "N= ";
	cin >> n;
	cout << endl;
	int* a = new int;
	*a = n;
	input(a, n);
	cout << endl;
	output(a, n);
	cout << "index: " << average(a, n) << endl;
	cout << "minimum among the positive: " << mini(a, n) << endl;
	cout << "sum up to the first negative: " << summ(a, n) << endl;
	cout << endl;

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
	cout << "Max column: " << harakter(b, n, m) << endl;
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
