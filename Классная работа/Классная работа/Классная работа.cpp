#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> 
#include <string.h>
#include <cstring>
#include <stdio.h> 
#include <algorithm>

using namespace std;

int palindrom(char* a);

void menu();

void kount(char* a);

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
            cout << "Считает количество символов в строке." << endl;
            cin.clear();
            cin.ignore();
            int i, n = 0;
            char* s = new char[100];
            cout << "Vvedite stroky- ";
            cin.getline(s, 255);
            for (i = 0; s[i] != '\0'; i++) n++;
            cout << "Количество символов в строке: " << n << endl;
            cout << endl;
            break;
        }
        case 3: {
            cout << "Определяет является ли строка палиндромом." << endl;
            cin.clear();
            cin.ignore();
            int i;
            char* s = new char[100];
            cout << "При использовании Русского языка, программа будет выдовать не верные результаты," << endl;
            cout << "поэтому рекомендуется использовать латинский алфовит." << endl;
            cout << "Введите строку - ";
            cin.getline(s, 255);
            if (palindrom(s)) cout << "Строка является Палиндромом!" << endl;
            else cout << "Строка не является Палиндромом!" << endl;
            break;
        }
        case 4: {
            cout << "Считает количество слов в строке, а также количество предложений." << endl;
            cin.clear();
            cin.ignore();
            int i;
            char* s = new char[100];
            cout << "Vvedite stroky- ";
            cin.getline(s, 255);
            kount(s);
            break;
        }
        case 2: {
            cout << "Составляет предложения из заранее подготовленных слов." << endl;
            cout << "Порядок слов: article, существительное, глагол, предлог, article и существительное. " << endl;
            cin.clear();
            cin.ignore();
            int arts, nos, ves, pres;

            char* art[100];
            {
                ifstream  fin("art.txt");
                if (!fin) {
                    cout << "ошибка открытия файла" << endl;
                    break;
                }
                char* s = new char[100];
                int size = 0;
                int n;
                while (!fin.eof())
                {
                    fin.getline(s, 100, '\n');
                    char  seps[] = " ,;"; // Строка разделителей
                    char* token; // указатель на новой слово
                    token = strtok(s, seps);// находим первое слово
                    n = 0; //n - количество слов
                    while (token != NULL) {
                        art[size] = token; size++;
                        token = strtok(NULL, seps); n++;// выделяем следующее слово
                    }
                }
                //for (int i = 0; i < n; i++) cout << art[i] << " блин ";
                arts = n;
                cout << endl;
            }

            char* no[100];// = { "boy", "girl", "cat", "city", "car" };
            {
                ifstream  fin("no.txt");
                if (!fin) {
                    cout << "ошибка открытия файла" << endl;
                    exit;
                }
                char* s = new char[100];
                int size = 0;
                int n;
                while (!fin.eof())
                {
                    fin.getline(s, 100, '\n');
                    char  seps[] = " ,;"; // Строка разделителей
                    char* token; // указатель на новой слово
                    token = strtok(s, seps);// находим первое слово
                    n = 0; //n - количество слов
                    while (token != NULL) {
                        no[size] = token; size++;
                        token = strtok(NULL, seps); n++;// выделяем следующее слово
                    }
                }
                //for (int i = 0; i < n; i++) cout << no[i] << " ";
                nos = n;
            }

            char* ve[100];// = { "drove", "worked", "ran", "walked", "write" };
            {
                ifstream  fin("ve.txt");
                if (!fin) {
                    cout << "ошибка открытия файла" << endl;
                    exit;
                }
                char* s = new char[100];
                int size = 0;
                int n;
                while (!fin.eof())
                {
                    fin.getline(s, 100, '\n');
                    char  seps[] = " ,;"; // Строка разделителей
                    char* token; // указатель на новой слово
                    token = strtok(s, seps);// находим первое слово
                    n = 0; //n - количество слов
                    while (token != NULL) {
                        ve[size] = token; size++;
                        token = strtok(NULL, seps); n++;// выделяем следующее слово
                    }
                }
                //for (int i = 0; i < n; i++) cout << ve[i] << " ";
                ves = n;
            }

            char* pre[100];// = { "to", "from", "over", "under", "in" };
            //int pres = sizeof(pre) / sizeof(pre[0]);
            {
                ifstream  fin("pre.txt");
                if (!fin) {
                    cout << "ошибка открытия файла" << endl;
                    exit;
                }
                char* s = new char[100];
                int size = 0;
                int n;
                while (!fin.eof())
                {
                    fin.getline(s, 100, '\n');
                    char  seps[] = " ,;"; // Строка разделителей
                    char* token; // указатель на новой слово
                    token = strtok(s, seps);// находим первое слово
                    n = 0; //n - количество слов
                    while (token != NULL) {
                        pre[size] = token; size++;
                        token = strtok(NULL, seps); n++;// выделяем следующее слово
                    }
                }
                //for (int i = 0; i < n; i++) cout << pre[i] << " ";     
                pres = n;
            }

            int N;
            cout << "Количество предложений = ";
            cin >> N;

            for (int i = 0; i < N; i++)
            {
                const int max_N = 256;
                char offer[max_N];
                sprintf(offer, "%s %s %s %s %s %s.", art[rand() % arts], no[rand() % nos], ve[rand() % ves], pre[rand() % pres], art[rand() % arts], no[rand() % nos]);
                offer[0] = toupper(offer[0]);
                cout << offer << endl;
            }
            cout << endl;
            break;
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
    cout << "0 - EXIT" << endl;
}

int palindrom(char* a)
{
    char* b = new char[100];
    int n = strlen(a);
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (isalpha(a[i])) {
            b[k++] = tolower(a[i]);
        }
    }
    b[k] = '\0';


    bool t = 1;
    int j;
    for (int i = 0, j = strlen(b) - 1; i < j; i++, j--)
    {
        if ((b[i]) != b[j])
        {
            t = 0;

        }
    }
    return t;
}


void kount(char* a)
{
    int i;
    char* b = new char[100];
    strcpy(b, a);

    char  seps[] = " ,.;!?";
    char seps1[] = ".!?";
    char* token;
    token = strtok(b, seps);
    int n = 1;
    while (token != NULL) {
        token = strtok(NULL, seps); n++;
    }
    n--;
    cout << "Количество слов: " << n << endl;
    n = 0;
    for (i = 0; i < strlen(a); i++)
    {
        if (a[i] == '.' || a[i] == '!' || a[i] == '?') n++;
    }
    cout << "Количество предложений: " << n << endl;
}
