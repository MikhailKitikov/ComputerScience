//---------------------------------------------------------------------------

#include <vcl.h>
#include <algorithm>
#pragma hdrstop
using namespace std;
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
int clr=1,a=0,X1=0,Y1=0,X2=0,Y2=0;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  Image2->Picture = NULL;
  Image3->Picture = NULL;
  a=0;
  Image1->Canvas->Pen->Width=12;
  Image1->Canvas->MoveTo(125,275);
  Image1->Canvas->LineTo(125,150);
  Image1->Canvas->MoveTo(80,125);
  Image1->Canvas->LineTo(170,175);
  Image1->Canvas->Pen->Width=3;
  Image1->Canvas->Brush->Color=RGB(163,33,5);
  Image1->Canvas->Rectangle(200,200,500,350);
  Image1->Canvas->Brush->Color=RGB(81,87,83);
  Image1->Canvas->Ellipse(50,275,200,425);
  Image1->Canvas->Ellipse(463,350,538,425);
  Image1->Canvas->Brush->Color=clYellow;
  Image1->Canvas->Pie(480,225,520,280,500,280,500,225);
  Image1->Canvas->Brush->Color=RGB(103,68,65);
  Image1->Canvas->Rectangle(260,200,240,115);
  Image1->Canvas->Brush->Color=clWhite;
  Image1->Canvas->Font->Size=30;
  Image1->Canvas->Font->Color=clBlue;
  Image1->Canvas->Font->Name="Times new roman";
  Image1->Canvas->TextOut(150,25,"А купице трахтар?");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  if (ColorDialog1 ->Execute())
  {
	clr=ColorDialog1->Color;
	a=0;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
  if (a==0)
  {
	Image1->Canvas->Brush->Style=bsSolid;
	Image1->Canvas->Brush->Color=clr;
	Image1->Canvas->FloodFill(X,Y,clBlack,fsBorder);
  }
  else
  {
	Graphics::TBitmap* Ris=new Graphics::TBitmap();
	Ris->Assign(Image2->Picture);
	Image1->Canvas->Brush->Bitmap=NULL;
	Image1->Canvas->Brush->Bitmap=Ris;
	Image1->Canvas->FloodFill(X,Y,clBlack,fsBorder);
	delete Ris;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  Image2->Picture = NULL;
  Image3->Picture = NULL;
  a=0;
  Graphics::TBitmap* Ris=new Graphics::TBitmap();
  Ris->LoadFromFile("gn.bmp");
  Image1->Canvas->Brush->Bitmap=NULL;
  Image1->Canvas->Brush->Bitmap=Ris;
  Image1->Canvas->FloodFill(150,300,clBlack,fsBorder);
  Image1->Canvas->FloodFill(500,400,clBlack,fsBorder);
  delete Ris;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  Image2->Picture = NULL;
  Image3->Picture = NULL;
  a=0;
  Graphics::TBitmap* Ris1=new Graphics::TBitmap();
  Graphics::TBitmap* Ris2=new Graphics::TBitmap();
  TRect Pr1,Pr2;
  Ris1->LoadFromFile("bl.bmp");
  int x=276,y=148,w=88,h=23;
  Pr1 = Bounds(x,y,w,h);
  Pr2 = Rect(0,0,w,h);
  Ris2->Width=w;
  Ris2->Height=h;
  Ris2->Canvas->CopyRect(Pr2,Ris1->Canvas,Pr1);
  Image2->Picture->Assign(Ris2);
  Image1->Canvas->Brush->Bitmap=NULL;
  Image1->Canvas->Brush->Bitmap=Ris2;
  Image1->Canvas->FloodFill(300,300,clBlack,fsBorder);
  delete Ris1;
  delete Ris2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  Image2->Picture = NULL;
  Image3->Picture = NULL;
  a=0;
  Image3->Visible=True;
  Image3->Enabled=True;
  Image3->Picture->LoadFromFile("bl.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
  X1=X; Y1=Y;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
  X2=X; Y2=Y;
  Image2->Picture = NULL;
  Graphics::TBitmap* Ris=new Graphics::TBitmap();
  TRect Pr1,Pr2;
  if (X1>X2)
	swap(X1,X2);
  if (Y1>Y2)
	swap(Y1,Y2);
  Pr1 = Rect(X1,Y1,X2,Y2);
  Ris->Width=Pr1.Width();
  Ris->Height=Pr1.Height();
  Pr2 = Rect(0,0,Ris->Width,Ris->Height);
  Ris->Canvas->CopyRect(Pr2,Image3->Canvas,Pr1);
  Image2->Picture->Assign(Ris);
  delete Ris;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
  a=1;
  Image3->Picture = NULL;
  Image3->Visible=False;
  Image3->Enabled=False;
}
//---------------------------------------------------------------------------

