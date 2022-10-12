#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, ".1251");
	string stroka, a;
	int size, i, sl = 0, k = 0, n = 0, m = 0, z = 0, o = 0;

	cout << "Введите строку : " << endl;

	getline(cin, stroka);

	size = stroka.size();
	cout << endl;
	cout << "Размер строки : " << size << endl;

    cout << "Введите k : ";
    cin >> k;
    k--;

    if (k >= size)
    {
        return 0;
    }

    for (i = 1; i < size; i++)
    {
        if (stroka[i] == ' ')
        {
            n++;
        }
        if (stroka[i] != ' ')
        {
            break;
        }
    }

    k += n;

    //cout << length << endl;

    for (i = 1; i < size; i++)
    {
        while (m != n)
        {
            for (z = i; z < size; z++)
            {
                stroka[z] = stroka[z + 1];
            }
            m++;
            size--;
        }
        //cout << stroka[i];
    }
    cout << endl;

    //cout << "\n" << length << endl;

    for (i = 1; i <= size; i++)
    {
        if (stroka[i] == ',' || stroka[i] == ':' || stroka[i] == '.' || stroka[i] == '--')
        {
            if (k == i)
            {
                cout << "Это знак препинания";
                return 0;
            }
        }
        if (stroka[i] == ' ')
        {
            if (stroka[i + 1] != ' ')
            {
                sl++;
                o = i + 1;
            }
        }
        if (k < o)
        {
            cout << sl << endl;
            break;
        }
        if (stroka[i] == '\0')
        {
            sl++;
            cout << "Ваше слово под номером : " << sl;
        }
    }
}