//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <cmath>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
int Dg, Sp;
double pi=acos(-1.),L,T,l,t;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  Dg=SpinEdit3->Value;
  Sp=SpinEdit4->Value;
  Image2->Left=SpinEdit1->Value+165;
  Image2->Top=SpinEdit2->Value+196;
  L=SpinEdit4->Value*cos(SpinEdit3->Value*pi/180);
  T=SpinEdit4->Value*sin(SpinEdit3->Value*pi/180);
  l=Image2->Left;
  t=Image2->Top;
  Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpinEdit1Change(TObject *Sender)
{
  if (!Timer1->Enabled)
  {
		Image2->Left=SpinEdit1->Value+165;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpinEdit2Change(TObject *Sender)
{
  if (!Timer1->Enabled)
  {
		Image2->Top=SpinEdit2->Value+196;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  if ((l<165)||(l>666))
  {
	  L*=-1;
  }
  if ((t<196)||(t>448))
  {
	  T*=-1;
  }
  l+=L;
  t-=T;
  Image2->Left=l;
  Image2->Top=t;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  Timer1->Enabled=false;
  SpinEdit1->Value=Image2->Left-165;
  SpinEdit2->Value=Image2->Top-196;
}
//---------------------------------------------------------------------------

