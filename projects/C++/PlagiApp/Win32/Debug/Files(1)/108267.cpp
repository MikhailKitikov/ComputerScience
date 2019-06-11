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
	 Image1->Canvas->Pen->Color = clBlack;
	Image1->Canvas->MoveTo(230,245);
	Image1->Canvas->LineTo(215,270);
 Image1->Canvas->MoveTo(270,245);
	Image1->Canvas->LineTo(285,270);
	Image1->Canvas->Brush->Color = clRed;
	Image1->Canvas->MoveTo(180,180);
	Image1->Canvas->LineTo(140,190);
	Image1->Canvas->LineTo(180,200);
	Image1->Canvas->LineTo(180,180);
	Image1->Canvas->FloodFill(170,190,clBlack,fsBorder);
	Image1->Canvas->MoveTo(280,215);
	Image1->Canvas->LineTo(330,225);
	Image1->Canvas->LineTo(280,235);
	Image1->Canvas->LineTo(280,215);
	Image1->Canvas->FloodFill(290,225,clBlack,fsBorder);
	Image1->Canvas->MoveTo(243,230);
	Image1->Canvas->LineTo(273,230);
	Image1->Canvas->LineTo(293,250);
	Image1->Canvas->LineTo(243,230);
	Image1->Canvas->FloodFill(273,232,clBlack,fsBorder);
	 Image1->Canvas->Brush->Color = clRed;
	  Image1->Canvas->Pen->Color = clBlack;
 Image1->Canvas->Brush->Color = clYellow;
Image1->Canvas->Ellipse(200, 200, 300, 250);
Image1->Canvas->FloodFill(250,230,clBlack,fsBorder);
Image1->Canvas->Ellipse(168,168,218,218);
Image1->Canvas->FloodFill(200,180,clBlack,fsBorder);




}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{

	 Image1->Canvas->Pen->Color = clBlack;
	Image1->Canvas->MoveTo(230,245);
	Image1->Canvas->LineTo(215,270);
 Image1->Canvas->MoveTo(270,245);
	Image1->Canvas->LineTo(285,270);
	Image1->Canvas->Brush->Color = clRed;
	Image1->Canvas->MoveTo(180,180);
	Image1->Canvas->LineTo(140,190);
	Image1->Canvas->LineTo(180,200);
	Image1->Canvas->LineTo(180,180);
	Image1->Canvas->FloodFill(170,190,clBlack,fsBorder);
	Image1->Canvas->MoveTo(280,215);
	Image1->Canvas->LineTo(330,225);
	Image1->Canvas->LineTo(280,235);
	Image1->Canvas->LineTo(280,215);
	Image1->Canvas->FloodFill(290,225,clBlack,fsBorder);
	Image1->Canvas->MoveTo(243,230);
	Image1->Canvas->LineTo(273,230);
	Image1->Canvas->LineTo(293,250);
	Image1->Canvas->LineTo(243,230);
	Image1->Canvas->FloodFill(273,232,clBlack,fsBorder);
	 Image1->Canvas->Brush->Color = clRed;
	  Image1->Canvas->Pen->Color = clBlack;
 Image1->Canvas->Brush->Color = clGreen;
Image1->Canvas->Ellipse(200, 200, 300, 250);
Image1->Canvas->FloodFill(250,230,clBlack,fsBorder);
Image1->Canvas->Ellipse(168,168,218,218);
Image1->Canvas->FloodFill(200,180,clBlack,fsBorder);
}
//---------------------------------------------------------------------------
 //---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject *Sender)
{
Image2->Picture->LoadFromFile("ris1.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	X1=X;
	Y1=Y;
	Label1->Caption=" x1="+IntToStr(X1)+" y1="+IntToStr(Y1)+" x2="+IntToStr(X2)+" y2="+IntToStr(Y2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
X2=X;
	Y2=Y;
	Label1->Caption=" x1="+IntToStr(X1)+" y1="+IntToStr(Y1)+" x2="+IntToStr(X2)+" y2="+IntToStr(Y2);
	Graphics::TBitmap* Ris2=new Graphics::TBitmap();
	   TRect Pr1,Pr2;
	   Pr1 = Rect(X1,Y1,X2,Y2);
	   Ris2->Width=Pr1.Width();
	   Ris2->Height=Pr1.Height();
	   Pr2 = Rect(0,0,Ris2->Width,Ris2->Height);
	   Ris2->Canvas->CopyRect(Pr2,Image2->Canvas,Pr1);
	   Image3->Picture->Assign(Ris2);
	   Image1->Canvas->Brush->Bitmap=Ris2;
	Label2->Caption = "выберите часть исходной картинки,которую хотите замостить";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
 Image1->Canvas->FloodFill(X,Y,clBlack,fsBorder);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Graphics::TBitmap* Ris1=new Graphics::TBitmap();
	Ris1->LoadFromFile("ris2.bmp");
	Image1->Canvas->Brush->Bitmap=Ris1;
}
//---------------------------------------------------------------------------

