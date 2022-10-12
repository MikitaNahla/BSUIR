#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <istream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");
    int k, i, n = 0, m = 0, length = 0, sl = 0, o = 0, z = 0, p=0, x=0;
    char stroka[1111];
    char a;

    cout << "Введите строку : \n"  ;
    cin.getline(stroka, 1111);

    length = strlen(stroka);

    cout << "Длина строки : " << length << endl;

    cout << "Введите k : ";
    cin >> k;
    k--;
 
    if (k >= length)
    {
        return 0;
    }

    for (i = 1; i < length; i++)
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
    
    for (i = 1; i < length ; i++)
    {
        while (m != n)
        {
            for (z = i; z < length ; z++)
            {
                stroka[z] = stroka[z + 1];
            }
            m++;
            length--;
        }
        cout << stroka[i];
    }
    cout << endl;
    
    //cout << "\n" << length << endl;

    for (i = 1 ; i <= length; i++)
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
            cout << "Ваше слово под номером : " << sl << endl;
            break;
        }
        if (stroka[i] == '\0')
        {
            sl++;
            cout << "Ваше слово под номером : " << sl;
        }
    }
}