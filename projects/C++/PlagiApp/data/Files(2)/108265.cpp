//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
double t=0;
int a=1,b=5;

//Были проблемы с картинками, картинки загружены через Image->Picture вручную, не кодом

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
Image2->Left=180+10*ceil((a+b)*cos(t)-a*cos(1.*(a+b)/a)*t);
Image2->Top=150+10*ceil((a+b)*sin(t)-a*sin(1.*(a+b)/a)*t);
t=t+3.14/20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Timer1->Enabled=True;
a=StrToInt(Edit1->Text);
b=StrToInt(Edit2->Text);
}

