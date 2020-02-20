#include <iostream>
#include <fstream>
using namespace std;

void perestoi(int a[], int s, int c, int k);

void input(int a[], int n, int& m, int b, int v);

void line(int a[], int n);

int main()
{
	float Nomer = 1;
	int nomer = 0;
    setlocale(LC_ALL, "Russian");
    while (Nomer != 0)
    {
		cout << "1-Первая задача; 2-Вторая задача; 0-выход." << endl;
		cin >> Nomer;
		cout << Nomer << endl;
		nomer = Nomer;
		cout << nomer << endl;
		if (Nomer > 2 || Nomer<0 || Nomer!=nomer) cout << "Вы выбрали не существующую задачу. Повторите выбор." << endl;

        if (Nomer == 1)
        {
			int i, n = 0, m = 0, j = 0;
			ifstream F1;
			ofstream F2;
			F2.open("Nomer_1.txt", ios::out);
			F1.open("mass.txt", ios::in);
			while (!F1.eof())
			{
				F1 >> m; 
				if (m > 0) n++;// Счетчик количества чисел в масиве
			}
			F1.close();
			cout << "N= " << n << endl;//Вывод количества чисел в массиве.
			int* a = new int[n];//Создание массива.
			F1.open("mass.txt", ios::in);
			while (!F1.eof())//Цикл подсчета количества чиел удовлетворяющих условию.
			{
				F1 >> m;
				if (m > 0)
				{
					a[j] = m;//Наполнение массива положительными числами. Согласно условию.
					j += 1;
				}
			}
			line(a, n);//Сортировка массива по возрастанию.
			for (i = 0; i < n; i++)
			{
				F2 << a[i] << endl;//Вывод отсортированного массива в файл.
			}
			cout << "The program is complete" << endl;
			F1.close();
			F2.close();
        }

        if (Nomer == 2)
        {
			ofstream F1;
			int i, n = -1, m = 0, k = 0, v = 0, b = 0;
			while (n < 0)//Проверка достоверности количества элементов.
			{
				cout << "Amount of elements: ";
				cin >> n;
				if (n < 0) cout << "Некоректный ввод, число должно быть целым и положительным." << endl;
			}
			while (v > b || v == b)//Проверка достоверности введенных данных.
			{
				cout << "A= ";
				cin >> v;
				cout << "B= ";
				cin >> b;
				if (v > b || v == b) cout << "Повторите ввод A и B. Условия: A<B и A != B." << endl;
			}
			int* a = new int[n];
			input(a, n, m, b, v); // заполнение массива
			//cout << m << endl; // количество элементов удовлетворяющих условию
			cout << "K= ";// Дополнительный элемент
			cin >> k;
			int s = m + n;// общее количество элементов в новом массиве
			//cout << s << endl;
			a = (int*)realloc(a, s * sizeof(int)); // расширение массива
			if (k < 0 || k == 0)  // нахождение положительных элементов и установка дополнительных элементов.
			{
				for (i = 0; i < s; i++)
				{
					if (a[i] > 0) perestoi(a, s, i, k); //
				}
			}
			else
			{
				for (i = 0; i < s; i++)
				{
					if (a[i] > 0) //
					{
						perestoi(a, s, i, k);
						i++;
					}
				}
			}
			F1.open("itog1.txt", ios::out); //вывод итогового массива в файл.
			for (i = 0; i < s; i++)
			{
				F1 << a[i] << endl;
			}
			F1.close();
			cout << "The program is complete" << endl;
        }
    }
}

/**
Функция сдвига массива в право с определенного элемента, с шагом один.
*/
void perestoi(int a[], int s, int c, int k)
{
	int i;
	for (i = s - 1; i > c; i--)
	{
		a[i + 1] = a[i];
	}
	a[c + 1] = k;
}

/**
1)Функция заполнения массива случайными числами.
2)Функция подсчета количества положительных элементов и возвращение значения переменной m.
*/
void input(int a[], int n, int& m, int b, int v)
{
	int i;
	if (v > 0 && b > 0)
	{
		for (i = 0; i < n; i++)
		{
			a[i] = rand() % v+(b-v);
			cout << a[i] << endl;
			if (a[i] > 0) m += 1;
		}
	}
	if (v < 0 && b>0)
	{
		for (i = 0; i < n; i++)
		{

			a[i] = rand() % (b + abs(v))-abs(v);
			cout << a[i] << endl;
			if (a[i] > 0) m += 1;
		}
	}
	if (v < 0 && b < 0)
	{
		for (i = 0; i < n; i++)
		{

			a[i] = rand() % (abs(v) - abs(b)) - abs(v);
			cout << a[i] << endl;
			if (a[i] > 0) m += 1;
		}
	}
	if (v == 0 && b > 0)
	{
		for (i = 0; i < n; i++)
		{

			a[i] = rand() % b;
			cout << a[i] << endl;
			if (a[i] > 0) m += 1;
		}
	}
	if (v < 0 && b == 0)
	{
		for (i = 0; i < n; i++)
		{

			a[i] = rand() % abs(v) - abs(v);
			cout << a[i] << endl;
			if (a[i] > 0) m += 1;
		}
	}
}

/**
Сортировка прямого выбора.
*/
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
