//---------------------------------------------------------------------------
#include <math.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
double f,y,z,x,h,a,b,s,c=1;
double n,k;
cout << "Input a,b,h,n\n";
cin >> a >> b >> h >> n;
for (x=a; x<=b; x+=h){
    y=(1-pow(x,2)/2)*cos(x)-(x/2)*sin(x);
    s=0;
    for (k=0; k<=n; k++){
        c=1;
        for (double j=2; j<=(k*2);j++){
            c*=j;
        }
        z=(pow(-1,k)*((2*pow(k,2)+1)*pow(x,2*k)))/c;
        s+=z;
    }
    f=fabs(y-s);
    cout << s << " " << y << " " << f << endl;
}
cout<< "Press any key ...";
getch();
return 0;
}
//---------------------------------------------------------------------------
 