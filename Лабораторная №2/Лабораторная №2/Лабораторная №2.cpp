// Лабораторная №2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;

void input(int** a, int** b, int& n, int& m, int c[]);

void output_in(int** a, int n, int m);

void tra_in(int** a, int n);

void Sum(int** a, int** b, int** New, int n, int m);

void tra_ou(int** a, int n, int** New);

void trans(int** a, int** New, int n, int m);

void zadanie1(int** a, int n, int m);

void zadanie2(int** a, int n, int m, int &k);

void proizv(int** a, int** b, int** New, int n, int m);

void matri(int** a, int c[], int** New, int n, int m);

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream F1;
	ifstream F2;
	ofstream F3;
	int i, n, m, j, k=0;
	cout << "Начало работы программы" << endl;
	int** a;
	int** b;
	int** New;
	F1.open("mass1.txt", ios::in);
	F1 >> n >> m;
	a = new int* [n];
	b = new int* [n];
	New = new int* [n];
	int* c = new int[n];
	for (i = 0; i < n; i++)
	{
		New[i] = new int[m];
		a[i] = new int[m];
		b[i] = new int[m];
	}
	input(a, b, n, m, c);
	cout << "Матрица A: " << endl;
	output_in(a, n, m);
	cout << "Матрица B: " << endl;
	output_in(b, n, m);
	cout << "Произведение матрицы A на вектор: " << endl;
	matri(a, c, New, n, m);
	output_in(New, n, m);
	cout << "Сумма двух матриц равна:" << endl;
	Sum(a, b, New, n, m);
	output_in(New, n, m);
	if (n == m)
	{
		cout << "Произведение матрицы A на B: " << endl;
		proizv(a, b, New, n, m);
		output_in(New, n, m);
	}
	else cout << "Матрицы не возможно умножить!" << endl;
	if (n == m)
	{
		cout << "1-транспонировать матрицу A и ответ записать в неё; 2-транспонировать матрицу A и результат записать в другоую матрицу:";
		cin >> j;
		if (j == 1)
		{
			tra_in(a, n);
			output_in(a, n, m);
		}
		if (j == 2)
		{
			tra_ou(a, n, New);
			output_in(New, n, m);
		}
	}
	else
	{
		cout << "Не квадратная матрица" << endl;
		delete[] New;
		int** New;
		New = new int* [m];
		for (i = 0; i < m; i++)
		{
			New[i] = new int[n];
		}
		trans(a, New, n, m);
		output_in(New, m, n);
	}
		cout << "9 Вариант: " << endl;
		cout << "1-е задание: " << endl;
		zadanie1(a, n, m);
		cout << "2-е задание: " << endl;
		zadanie2(a, n, m, k);
		if (k == 1)
		{
			cout << "Обмен строк." << endl;
			output_in(a, n, m);
		}
	F1.close();
}


void input(int** a, int** b, int& n, int& m, int c[])
{
	int i, j;
	ifstream F1;
	F1.open("mass1.txt", ios::in);
	F1 >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			F1 >> a[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			F1 >> b[i][j];
		}
	}
	for (i = 0; i < n; i++) F1 >> c[i];
	F1.close();
}

void output_in(int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%5d ", a[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

void tra_in(int** a, int n)
{
	int t;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			t = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = t;
		}
	}
} 

void tra_ou(int** a, int n, int** New)
{
	int t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0;j < n; j++) 
			New[i][j] = a[i][j];
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			t = New[i][j];
			New[i][j] = New[j][i];
			New[j][i] = t;
		}
	}
}

void Sum(int** a, int** b, int** New, int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			New[i][j] = a[i][j] + b[i][j];
		}
	}
}

void trans(int** a, int** New, int n, int m)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			New[i][j] = a[j][i];
		}
	}
}

void zadanie1(int** a, int n, int m)
{
	int t=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0)
			{
				for (int k = 0; k < m; k++)
				{
					if (a[i][k] < 0) t++;
				}
				if (t > 0)
				{
					cout << "строка: " << i << " Количество отрицательных элементов: " << t << endl;
					t = 0;
				}
			}
		}
	}
}

void zadanie2(int** a, int n, int m, int &k)
{
	int max = a[0][0], maxnami = 0, minnami = 0, min = a[0][0], t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (max < a[i][j])
			{
				max = a[i][j];
				maxnami = i;
			}
			if (min > a[i][j])
			{
				min = a[i][j];
				minnami = i;
			}
		}
	}
	if (maxnami == minnami)
	{
		cout << "Первый и последний максимальные элементы находятся в одной строке." << endl;
		k = 0;
	}
	else
	{
		k = 1;
		for (int j = 0; j < m; j++)
		{
			t = a[maxnami][j];
			a[maxnami][j] = a[minnami][j];
			a[minnami][j] = t;
		}
	}
}

void proizv(int** a, int** b, int** New, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			New[i][j] = 0;
			for (int t = 0; t < m; t++)
			{
				New[i][j]+= (a[i][t] * b[t][j]);
			}
		}
	}
}

void matri(int** a, int c[], int** New, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			New[i][j] = 0;
			New[i][j] = a[i][j] * c[i];
		}
	}
}