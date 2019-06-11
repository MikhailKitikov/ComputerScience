//---------------------------------------------------------------------------

#include <vcl.h>
#include <cmath>
#include <string>
#pragma hdrstop
  using namespace std;
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x0,y0,x,y,x1,y1,x2,y2,c=0,m=0,s=0;
String c1,m1,s1;
double ang=0,ang1=0,ang2=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   x0=173;y0=300;
   Image2->Canvas->Pen->Color=clWhite;
   Image2->Canvas->Rectangle(0,0,Image1->Width, Image1->Height);
 x=x0;y=y0-120;
   Image2->Canvas->Pen->Color=clBlack;
   Image2->Canvas->Pen->Width=2;
  Image2->Canvas->MoveTo(x0, y0);
   Image2->Canvas->LineTo(x, y);

   Image3->Canvas->Pen->Color=clWhite;
   Image3->Canvas->Rectangle(0,0,Image1->Width, Image1->Height);
   x1=x0;y1=y0-90;
   Image3->Canvas->Pen->Color=clBlack;
   Image3->Canvas->Pen->Width=3;
   Image3->Canvas->MoveTo(x0, y0);
   Image3->Canvas->LineTo(x1, y1);

   Image4->Canvas->Pen->Color=clWhite;
   Image4->Canvas->Rectangle(0,0,Image1->Width, Image1->Height);
   x2=x0;y2=y0-70;
   Image4->Canvas->Pen->Color=clBlack;
   Image4->Canvas->Pen->Width=4;
   Image4->Canvas->MoveTo(x0, y0);
   Image4->Canvas->LineTo(x2, y2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Timer1->Enabled=True;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	   double pi=acos(-1.);
	   Image2->Canvas->Pen->Color=clWhite;
	  Image2->Canvas->Pen->Width=3;
	   Image2->Canvas->MoveTo(x0, y0);
	   Image2->Canvas->LineTo(x, y);

   Image3->Canvas->Pen->Color=clWhite;
   Image3->Canvas->Pen->Width=4;
   Image3->Canvas->MoveTo(x0, y0);
   Image3->Canvas->LineTo(x1, y1);

	Image4->Canvas->Pen->Color=clWhite;
   Image4->Canvas->Pen->Width=5;
   Image4->Canvas->MoveTo(x0, y0);
   Image4->Canvas->LineTo(x2, y2);

	ang=ang+pi/30;
	x=x0+ceil(120*sin(ang));
	y=y0-ceil(120*cos(ang));
   Image2->Canvas->Pen->Color=clBlack;
   Image2->Canvas->Pen->Width=2;
   Image2->Canvas->MoveTo(x0, y0);
   Image2->Canvas->LineTo(x, y);

   ang1=ang1+pi/1800;
   x1=x0+ceil(90*sin(ang1));
   y1=y0-ceil(90*cos(ang1));
  Image3->Canvas->Pen->Color=clBlack;
   Image3->Canvas->Pen->Width=3;
   Image3->Canvas->MoveTo(x0, y0);
   Image3->Canvas->LineTo(x1, y1);

	ang2=ang2+pi/21600;
   x2=x0+ceil(70*sin(ang2));
   y2=y0-ceil(70*cos(ang2));
  Image4->Canvas->Pen->Color=clBlack;
   Image4->Canvas->Pen->Width=4;
   Image4->Canvas->MoveTo(x0, y0);
   Image4->Canvas->LineTo(x2, y2);

   c1=IntToStr(c);
   m1=IntToStr(m);
   s1=IntToStr(s);
   Label1->Caption=c1+":"+m1+":"+s1;
   s++;
   if(s>60)
   {
	   s=0;
	   m++;
   }
   if(m>60)
   {
	   m=0;
	   c++;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image4Click(TObject *Sender)
{
	  Timer1->Enabled=False;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Timer1->Enabled=False;
	  x0=173;y0=300;
   Image2->Canvas->Pen->Color=clWhite;
   Image2->Canvas->Rectangle(0,0,Image1->Width, Image1->Height);
 x=x0;y=y0-120;
   Image2->Canvas->Pen->Color=clBlack;
   Image2->Canvas->Pen->Width=2;
  Image2->Canvas->MoveTo(x0, y0);
   Image2->Canvas->LineTo(x, y);

   Image3->Canvas->Pen->Color=clWhite;
   Image3->Canvas->Rectangle(0,0,Image1->Width, Image1->Height);
   x1=x0;y1=y0-90;
   Image3->Canvas->Pen->Color=clBlack;
   Image3->Canvas->Pen->Width=3;
   Image3->Canvas->MoveTo(x0, y0);
   Image3->Canvas->LineTo(x1, y1);

   Image4->Canvas->Pen->Color=clWhite;
   Image4->Canvas->Rectangle(0,0,Image1->Width, Image1->Height);
   x2=x0;y2=y0-70;
   Image4->Canvas->Pen->Color=clBlack;
   Image4->Canvas->Pen->Width=4;
   Image4->Canvas->MoveTo(x0, y0);
   Image4->Canvas->LineTo(x2, y2);
   Label1->Caption="";
   ang=0;
   ang1=0;
   ang2=0;
   c=0;
   m=0;
   s=0;
}
//---------------------------------------------------------------------------
