//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x0 = 110, y0 = 30;
int x = x0, y = y0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	if (y < Image1->Height)
	{
		x ++;
		y = (x-110)*(x-110) + y0;
	}
	else
	{
		x = x0;
		y = y0;
	}
	Image2->Left = x;
	Image2->Top = y;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
