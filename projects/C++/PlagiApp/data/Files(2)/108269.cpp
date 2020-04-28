//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
using namespace std;
double y;
int x=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
y = fabs(100*sin(x))+50;
Image2->Left=x;
Image2->Top=Image1->Height - y;
x+=15;
if (x>Image1->Width)
	x=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image2Click(TObject *Sender)
{
Timer1->Enabled=false;
}
//---------------------------------------------------------------------------

