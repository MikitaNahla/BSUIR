#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{
    double **a, *b; 
    int i, j, n, l, comp = 1, p = 0 ;
    cout << "Input size N = ";
    cin >> n;
    a = new double*[n];
    for (i = 0; i < n; i++)
    {
        a[i] = new double[n];
    }

    b = new double[n];

    cout << "Input massiv A:" << endl << "\n";

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\n";

    l = n;

    for (i = 0; i < n ; i++) {
        for (j = 0; j < l - 1 ; j++) {
            comp *= a[i][j]; 
           // cout << comp << " ";
        }
        l--;
    }   
    
            cout << "Composition of elements = " << comp << "\n";
    
    delete []b;
    delete []a;

    //cout << "Massives was deleted!" << "\n";
    cout << "Press any key ...";
}
