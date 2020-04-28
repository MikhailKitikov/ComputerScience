//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int X1=0, Y1=0, X2=0, Y2=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TForm1::cl()
{
	Image1->Picture = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	cl();
	Image1->Canvas->Pen->Color = clBlack;
	Image1->Canvas->MoveTo(140,200);
	Image1->Canvas->LineTo(140,100);
	Image1->Canvas->LineTo(240,100);
	Image1->Canvas->LineTo(240,200);    //квадрат

	Image1->Canvas->MoveTo(270,200);
	Image1->Canvas->LineTo(270,130);
	Image1->Canvas->LineTo(290,140);
	Image1->Canvas->LineTo(270,150);   //флажок

	Image1->Canvas->Pen->Color = clBlue;
	Image1->Canvas->MoveTo(100,200);
	Image1->Canvas->LineTo(300,160);
	Image1->Canvas->LineTo(260,250);
	Image1->Canvas->LineTo(140,250);
	Image1->Canvas->LineTo(100,200);
	Image1->Canvas->Brush->Color = clWhite;
	Image1->Canvas->FloodFill(230,200,clBlue,fsBorder);
	Image1->Canvas->Pen->Color = clBlack;
	Image1->Canvas->MoveTo(100,200);
	Image1->Canvas->LineTo(300,160);
	Image1->Canvas->LineTo(260,250);
	Image1->Canvas->LineTo(140,250);
	Image1->Canvas->LineTo(100,200);     //корпус

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{

	Graphics::TBitmap* Ris1= new Graphics::TBitmap();
	Ris1->LoadFromFile("puzirki.bmp");
	Image2->Picture->LoadFromFile("puzirki.bmp");
	Image1->Canvas->Brush->Bitmap = Ris1;
	Image1->Canvas->FloodFill(10, 10, clBlack, fsBorder);
	delete Ris1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Graphics::TBitmap* Ris1= new Graphics::TBitmap();
	Ris1->LoadFromFile("Babochka.151bmp.bmp");
	Image2->Picture->LoadFromFile("Babochka.151bmp.bmp");
	Image1->Canvas->Brush->Bitmap = Ris1;
	Label1->Caption = "Выберете фрагмент на Бабочке.";
	delete Ris1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	X1 = X; Y1 = Y;
	Label1->Caption = " x1 = "+IntToStr(X1)+" y1 = "+IntToStr(Y1)+" x2 = "+IntToStr(X2)+" y2 = "+IntToStr(Y2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	X2 = X; Y2 = Y;
	int t;
	if (X2 < X1)
	{
		t = X2;
		X2 = X1;
		X1 = t;
	}
	if (Y2 < Y1)
	{
		t = Y2;
		Y2 = Y1;
		Y1 = t;
	}
    Label1->Caption = " x1 = "+IntToStr(X1)+" y1 = "+IntToStr(Y1)+" x2 = "+IntToStr(X2)+" y2 = "+IntToStr(Y2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	Graphics::TBitmap* Ris1=new Graphics::TBitmap();
	TRect Pr1,Pr2;
	Pr1 = Rect(X1,Y1,X2,Y2);
	Ris1->Width=Pr1.Width();
	Ris1->Height=Pr1.Height();
	Pr2 = Rect(0,0,Ris1->Width,Ris1->Height);
	Ris1->Canvas->CopyRect(Pr2,Image2->Canvas,Pr1);
	Image3->Picture->Assign(Ris1);
	Image1->Canvas->Brush->Bitmap = Ris1;
	Image1->Canvas->FloodFill(X, Y, clBlack, fsBorder);
	delete Ris1;
}
//---------------------------------------------------------------------------

