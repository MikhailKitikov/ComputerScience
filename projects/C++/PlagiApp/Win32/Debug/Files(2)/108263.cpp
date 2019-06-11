//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;  double r1,r2,x,y; double i=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	   Timer1->Enabled=true;
	   r1=StrToInt(LabeledEdit1->Text);
	   r2=StrToInt(LabeledEdit2->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	  i=i+0.1 ;
			x=250+r1*cos(i);
			y=r2*sin(i)+350;
			Image2->Top=y;
			Image2->Left=x;

}
//---------------------------------------------------------------------------
