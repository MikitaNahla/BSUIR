//---------------------------------------------------------------------------
#include <conio.h>
#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include <math.h>
#define pi 3.1415926
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{       double x,y,z,a,b,c,rez;
        puts("\n\tx,y,z=");
        scanf("%lf%lf%lf", &x,&y,&z);
        a=pow(2,pow(y,x));
        b=pow(3,x*y);
        c=y*(atan(z)-pi/6.)/(fabs(x)+1/((pow(y,2)+1)));
        rez=a+b-c;
        printf("\n x=%7.7lf\n y=%7.7lf\n z=%7.7lf\nResult=%lf\n", x,y,z,rez);
        puts("Press any key ...");
        getch();
        return 0;
}
//---------------------------------------------------------------------------
