//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 TPoint a[13];
 a[0].X=300;
 a[0].Y=300;
 a[1].X=280;
 a[1].Y=220;
 a[2].X=300;
 a[2].Y=170;
 a[3].X=260;
 a[3].Y=210;
 a[4].X=210;
 a[4].Y=120;
 a[5].X=200;
 a[5].Y=250;
 a[6].X=180;
 a[6].Y=180;
 a[7].X=190;
 a[7].Y=270;
 a[8].X=180;
 a[8].Y=300;
 Image1->Canvas->Polygon(a,8);
 Image1->Canvas->Brush->Color = clBlue;
 Image1->Canvas->Ellipse(200,90,220,150);
 Image1->Canvas->Ellipse(270,140,340,200);
Image1->Canvas->Ellipse(200,200,160,160);
//FloodFill(260,210,clWhite,fsSurface);
//FloodFill(x,y,Color,FillStyle);



}
//---------------------------------------------------------------------------

