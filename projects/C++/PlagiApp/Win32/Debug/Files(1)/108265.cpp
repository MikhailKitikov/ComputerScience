//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
int x1,y1,x2,y2,nselect;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
x1=0;
y1 =0;
x2=0;
y2=0;
nselect=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{

 Image1->Canvas->Rectangle(120,20,200,100);
 Image1->Canvas->Rectangle(140,100,180,140);
 Image1->Canvas->Rectangle(100,140,220,240);
 Image1->Canvas->Rectangle(60,140,100,200);
 Image1->Canvas->Rectangle(220,140,260,200);
 Image1->Canvas->Rectangle(120,240,150,300);
 Image1->Canvas->Rectangle(170,240,200,300);
 Image1->Canvas->Ellipse(135,40,155,55);
  Image1->Canvas->Ellipse(170,40,190,55);
  Image1->Canvas->MoveTo(150,80);
  Image1->Canvas->LineTo(170,80);

Graphics::TBitmap* Ris1=new Graphics::TBitmap();
Ris1->LoadFromFile("1111.bmp");
Image1->Canvas->Brush->Bitmap=Ris1;
Image1->Canvas->FloodFill(200,200,Image1->Canvas->Pixels[8][8],fsSurface);
Image1->Canvas->Brush->Bitmap=NULL ;
delete Ris1;

Graphics::TBitmap* Ris2=new Graphics::TBitmap();
Ris2->LoadFromFile("image.bmp");
Image2->Canvas->Draw(0,0,Ris2);
delete Ris2;


}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	 { if (ColorDialog1->Execute())
{
Image1->Canvas->Brush->Style=bsSolid;
Image1->Canvas->Brush->Color=ColorDialog1->Color;
Image1->Canvas->FloodFill(121,21,clBlack,fsBorder);
Image1->Canvas->FloodFill(141,101,clBlack,fsBorder);
Image1->Canvas->FloodFill(101,141,clBlack,fsBorder);
Image1->Canvas->FloodFill(61,141,clBlack,fsBorder);
Image1->Canvas->FloodFill(221,141,clBlack,fsBorder);
Image1->Canvas->FloodFill(121,241,clBlack,fsBorder);
Image1->Canvas->FloodFill(171,241,clBlack,fsBorder);
}
}
}

//---------------------------------------------------------------------------
void __fastcall TForm3::Image2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
x1=X;
y1=Y;
nselect=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Image2MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
if (nselect==1)
 {
 x2=X;y2=Y;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Image2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
nselect=0;
Graphics::TBitmap* Ris3=new Graphics::TBitmap();
TRect Pr1;
Pr1 = Rect(0, 0, 20, 30);
TRect Pr2;
if ((x2<x1))
 {
  int a=x1;
  x1=x2;
  x2=a;
 }
if (y2<y1)
 {
  int b=y1;
  y1=y2;
  y2=b;
}
Pr2 = Rect(x1, y1, x2, y2);
Ris3->Width=x2-x1; // ”станавливаем ширину
Ris3->Height=y2-y1; //и высоту нашего изображени€
Ris3->Canvas->CopyRect(Pr1,Image2->Canvas,Pr2);
Image1->Canvas->Brush->Bitmap=Ris3;
Image1->Canvas->FloodFill(200,200,Image1->Canvas->Pixels[8][8],fsSurface);
Image1->Canvas->FloodFill(240,50,Image1->Canvas->Pixels[8][8],fsSurface);
Image1->Canvas->FloodFill(300,180,Image1->Canvas->Pixels[8][8],fsSurface);
delete Ris3;

}
//---------------------------------------------------------------------------
