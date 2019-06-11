//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=138,y=60;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
Image1->Picture->LoadFromFile("box.bmp");
Image2->Picture->LoadFromFile("ball.bmp");
Timer1->Enabled=False;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
Timer1->Enabled=True;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{

Image2->Top=y;
Image2->Left=x;
if((x>=138)&&(x<401)&&(y>=60)&&(y<323))
{y=y+1;
x=x+1;}
if((x<=401)&&(x>=138)&&(y>=323)&&(y<=383))
{y=y+1;
x=x-1;}
//if((x<=331)&&(x>=78)&&(y>=120)&&(y<=383))
//{y=y-1;
//x=x-1;}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
Timer1->Enabled=False;
}
//---------------------------------------------------------------------------

