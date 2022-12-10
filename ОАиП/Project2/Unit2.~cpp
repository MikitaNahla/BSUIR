//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{ Edit1->Text="";
  Edit2->Text="";
  Edit3->Text="";
  Memo1->Clear();
  Memo1->Lines->Add("Лабораторная работа №2");
  RadioGroup1->ItemIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 double a,c,x,y,f,r,g,h,j,z,max;
 a=StrToFloat(Edit1->Text);
 c=StrToFloat(Edit2->Text);
 z=StrToFloat(Edit3->Text);
 if (z<=1) x=pow(z,2)+1;
 if (z<=1) Memo1->Lines->Add("x=pow(z,2)+1");
 if (z>1) x=1/(sqrt(z-1));
 if (z>1) Memo1->Lines->Add("x=1/(sqrt(z-1))");
                 switch(RadioGroup1->ItemIndex){

                        case 0: f=2*x;
                        Memo1->Lines->Add("2x=" +FloatToStrF(f,ffFixed,7,7)); break;

                        case 1: f=pow(x,2) ;
                        Memo1->Lines->Add("x^2=" +FloatToStrF(f,ffFixed,7,7)); break;

                        case 2: f=x/3.;
                        Memo1->Lines->Add("x/3=" +FloatToStrF(f,ffFixed,7,7)); break;
                  }
        g=a*pow(sin(pow(f,2)-1),3);
        h=c*log(fabs(x));
        j=exp(x);
        y=g+h+j;
        Memo1->Lines->Add("Значение функции= " +FloatToStrF(y,ffFixed,7,7));
}
//---------------------------------------------------------------------------







