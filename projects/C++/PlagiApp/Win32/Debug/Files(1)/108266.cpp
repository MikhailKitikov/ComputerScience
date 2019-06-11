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
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Image1->Canvas->MoveTo(180,200);
Image1->Canvas->LineTo(180,100);
Image1->Canvas->LineTo(135,100);
Image1->Canvas->LineTo(30,200);
Image1->Canvas->LineTo(180,200);
Image1->Canvas->Ellipse(160,112,140,137);
Image1->Canvas->MoveTo(180,125);
Image1->Canvas->LineTo(200,150);
Image1->Canvas->LineTo(180,150);
Image1->Canvas->MoveTo(180,175);
Image1->Canvas->LineTo(200,150);
Image1->Canvas->Ellipse(150,120,157,130);
Image1->Canvas->MoveTo(30,180);
Image1->Canvas->LineTo(30,190);
Image1->Canvas->LineTo(45,185);
Image1->Canvas->LineTo(30,180);
Image1->Canvas->MoveTo(30,110);
Image1->Canvas->LineTo(30,130);
Image1->Canvas->LineTo(90,180);
Image1->Canvas->LineTo(110,180);
Image1->Canvas->LineTo(120,160);
Image1->Canvas->LineTo(115,140);
Image1->Canvas->LineTo(30,110);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
	Graphics::TBitmap *Ris1=new Graphics::TBitmap();
	Ris1->LoadFromFile("disk.bmp");
	Image3->Canvas->Draw(10,10,Ris1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
Graphics::TBitmap *Ris1=new Graphics::TBitmap();
Ris1->LoadFromFile("disk.bmp");
Image1->Canvas->Brush->Bitmap=Ris1;
Image1->Canvas->FloodFill(127,140,clWhite,fsSurface);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
	TRect Pr1,Pr2;
	Graphics::TBitmap*Ris2=new Graphics::TBitmap();
	Ris2->LoadFromFile("2.bmp");
	Image2->Canvas->Draw(0,0,Ris2);
Label1->Caption="Чтобы замостить фон рисунка выбранным фрагментом, выдели и нажми на кнопку";
Label2->Visible=True;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
Graphics::TBitmap *Ris1=new Graphics::TBitmap(), *Ris2=new Graphics::TBitmap();
Ris1->LoadFromFile("disk.bmp");
TRect Pr1,Pr2;
Pr1=Rect(40,30,70,60);
Pr2=Rect(0,0,30,30);
Ris2->Width=30;
Ris2->Height=30;
Ris2->Canvas->CopyRect(Pr2,Ris1->Canvas, Pr1);
Image1->Canvas->Brush->Bitmap=Ris2;
Image1->Canvas->FloodFill(90,150,clWhite,fsSurface);
Image1->Canvas->FloodFill(60,140,clWhite,fsSurface);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
Graphics::TBitmap* Ris1=new Graphics::TBitmap();
TRect Pr1,Pr2;
Pr1 = Rect(X1,Y1,X2,Y2);
Ris1->Width=Pr1.Width();
Ris1->Height=Pr1.Height();
Pr2=Rect(0,0,Ris1->Width,Ris1->Height);
Ris1->Canvas->CopyRect(Pr2,Image2->Canvas,Pr1);
Image3->Picture->Assign(Ris1);
Image1->Canvas->Brush->Bitmap=Ris1;
Image1->Canvas->FloodFill(0,0,clWhite,fsSurface);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	X1=X; Y1=Y;
	Label2->Caption=" x1="+IntToStr(X1)+" y1="+IntToStr(Y1)+" x2="+IntToStr(X2)+" y2="+IntToStr(Y2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	X2=X; Y2=Y;
	Label2->Caption=" x1="+IntToStr(X1)+" y1="+IntToStr(Y1)+" x2="+IntToStr(X2)+" y2="+IntToStr(Y2);
}
//---------------------------------------------------------------------------




