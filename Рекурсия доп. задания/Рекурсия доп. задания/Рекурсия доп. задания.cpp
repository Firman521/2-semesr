
#include <iostream>
using namespace std;

void menu();

int Simple(int n);

void f1(int n)
{
	if (n < 10) cout << n << endl;
	if (n / 10 == 0) return;
	f1(n / 10);
	cout << n % 10 << endl;
}

void f2(int n, int b[], int i)
{
	if (i < n)
	{
		if (Simple(b[i]) == 0)
		{
			cout << "Делитель: " << b[i] << " простое" << endl;
		}
		return f2(n, b, i + 1);
	}
}

int f3(int n, int i)
{
	if (n != i)
	{
		cout << n << " ";
		return f3(n, i + 1);
	}
	else return 0;
}

int f5(int n, int b[], int ma, int i);

int max(int n, int b[]);

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
			int n;
			cin >> n;
			f1(n);
			break;
		}

		case 2: {
			int n, size = 0;
			cin >> n;
			int* b = new int[n];
			for (int i = 1; i < n/2; i++)
			{
				if (n % i == 0) b[size++] = i;
			}
			b[size++] = n;
			f2(size, b, 0);
			break;
		}

		case 3: {
			int n;
			cin >> n;
			for (int k = 1; k <= n; k++)
				f3(k, 0);
			break;
		}

		case 5:{
			int n, i, b = 1, size=0;
			int* a = new int[100];
			while (b != 0)
			{
				cin >> b;
				if (b!=0) a[size++] = b;
			}
			for (i = 0; i < size; i++) cout << a[i] << " ";
			int ma = max(size, a);
			cout << endl;
			cout << ma << endl;
			cout << "Количество элементов равных максимуму: " << f5(size, a, ma, 0) << endl;
			break;
		}

		case 0: {
			cout << "EXIT" << endl;
			cout << "....." << endl;
			cout << "complete" << endl;
			  }
		}
	}
}

void menu()
{
	cout << "1 - Задание 1" << endl;
	cout << "2 - Задание 2" << endl;
	cout << "3 - Задание 3" << endl;
	cout << "4 - Задание 4" << endl;
	cout << "5 - Pадание 5" << endl;
	cout << "0 - EXIT" << endl;
}

int Simple(int n)
{
	int p = 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			p = 1;
	}
	if (p == 1) return 1;
	else return 0;
}

int f5(int n, int b[],int ma, int i)
{
	if (i < n)
	{
		if (b[i] == ma) return (1 + f5(n, b, ma, i + 1));
		else return f5(n, b, ma, i + 1);
	}
}

int max(int n, int b[])
{
	int ma = b[0];
	for (int i = 1; i < n; i++)
	{
		if (b[i] > ma) ma = b[i];
	}
	return ma;
}