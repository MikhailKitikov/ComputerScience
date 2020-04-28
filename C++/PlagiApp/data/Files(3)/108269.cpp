//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap  *kadr=new Graphics::TBitmap(), *fon=new Graphics::TBitmap(), *ris=new Graphics::TBitmap(),
*kadr2=new Graphics::TBitmap(), *fon2=new Graphics::TBitmap(), *ris2=new Graphics::TBitmap();
int k = 3;
int k1 = 4;
int w, h, x, x1, y, w2, h2, x02, x2, y2;
TRect Pr_ris, Pr_fon, Pr_kadr, Pr_ris2, Pr_fon2, Pr_kadr2;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	   ris -> LoadFromFile("удар2.bmp");
	   w = ris -> Width / k;
	   h = ris -> Height;
	   kadr -> Width = w;
	   kadr -> Height = h;
	   x=0;
	   x1 = - w;
	   y = 170;
	   fon -> Width = w;
	   fon -> Height =h;
	   Pr_fon = Bounds (x1, y, w, h);
	   fon -> Canvas -> CopyRect(Pr_kadr, Image1 -> Canvas, Pr_fon);
	   Pr_kadr = Bounds (0, 0, w, h);
	   Pr_ris = Pr_kadr;
	   kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	   kadr -> Transparent = true;
	   Image1 -> Canvas -> Draw(x1,y,kadr);
	   ris2 -> LoadFromFile("м€ч.bmp");
	   w2 = ris2 -> Width / k1;
	   h2 = ris2 -> Height;
	   kadr2 -> Width = w2;
	   kadr2 -> Height = h2;
	   x02=20;
	   x2 = - w;
	   y2 = 340;
	   fon2 -> Width = w2;
	   fon2 -> Height =h2;
	   Pr_fon2 = Bounds (x2, y2, w2, h2);
	   fon2 -> Canvas -> CopyRect(Pr_kadr2, Image1 -> Canvas, Pr_fon2);
	   Pr_kadr2 = Bounds (0, 0, w2, h2);
	   Pr_ris2 = Pr_kadr2;
	   kadr2 -> Canvas -> CopyRect(Pr_kadr2, ris2 -> Canvas, Pr_ris2);
	   kadr2 -> Transparent = true;
	   Image1 -> Canvas -> Draw(x2,y2,kadr2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
Image1 -> Canvas -> CopyRect(Pr_fon, fon -> Canvas, Pr_kadr);
	 x1=x1+10;
	 if (x1 > Image1 -> Width)
		x1 = -w;
	 Pr_fon = Bounds (x1, y, w, h);
	 fon -> Canvas -> CopyRect(Pr_kadr, Image1 -> Canvas, Pr_fon);
	 x+=w;
	 if (x > k*w)
		 x=0;
	 Pr_ris = Bounds(x, 0, w, h);
	 kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	 Image1 -> Canvas -> Draw(x1, y, kadr);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
Image1 -> Canvas -> CopyRect(Pr_fon2, fon2 -> Canvas, Pr_kadr2);
	 y2 = fabs(100*sin(x2)+200);
	 x2=x2+10;
	 if (x2 > Image1 -> Width)
		x2 = -w2;
	 Pr_fon2 = Bounds (x2, y2, w2, h2);
	 fon2 -> Canvas -> CopyRect(Pr_kadr2, Image1 -> Canvas, Pr_fon2);
	 x02+=w2;
	 if (x02 > k1*w2)
		 x02=0;
	 Pr_ris2 = Bounds(x02, 0, w2, h2);
	 kadr2 -> Canvas -> CopyRect(Pr_kadr2, ris2 -> Canvas, Pr_ris2);
	 Image1 -> Canvas -> Draw(x2, y2, kadr2);
}
//---------------------------------------------------------------------------

