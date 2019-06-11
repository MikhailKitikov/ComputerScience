//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap  *kadr=new Graphics::TBitmap(), *ris=new Graphics::TBitmap(),*fon=new Graphics::TBitmap();
int k = 7;
int w, h, x,x1,y;
 TRect Pr_ris, Pr_kadr, Pr_fon;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
ris-> LoadFromFile("dragon.bmp");
	   w = ris -> Width/k;
	   h = ris -> Height;
	   kadr->Width=w;
	   kadr->Height=h;
	   x=0;
	   x1=-w;
	   y = 20;
	   fon -> Width = w;
	   fon -> Height =h;
	   Pr_fon = Bounds (x1, y, w, h);
	   fon -> Canvas -> CopyRect(Pr_kadr, Image1 -> Canvas, Pr_fon);
	   Pr_kadr = Bounds (0, 0, w, h);
	   Pr_ris=Pr_kadr;
	   kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	   kadr->Transparent=true;
	   Image1 -> Canvas -> Draw(x1, y, kadr);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
Image1 -> Canvas -> CopyRect(Pr_fon, fon -> Canvas, Pr_kadr);
	 x1=x1+10;
	 if (x1 > Image1 -> Width)
		x1= -w;
	 Pr_fon = Bounds (x1, y, w, h);
	 fon -> Canvas -> CopyRect(Pr_kadr, Image1 -> Canvas, Pr_fon);
	 x=x+w;
	 if(x>k*w) x=0;
	 Pr_ris = Bounds (x, 0, w, h);
	 kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	 Image1 -> Canvas -> Draw(x1, y, kadr);
}
//---------------------------------------------------------------------------
