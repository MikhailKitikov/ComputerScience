//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap  *kadr=new Graphics::TBitmap(), *ris=new Graphics::TBitmap(), *kadr1=new Graphics::TBitmap(), *ris1=new Graphics::TBitmap();
int k = 8;
int w, h, x,w1, h1, x1,y=0,y1=100;
 TRect Pr_ris, Pr_kadr ,Pr_ris1, Pr_kadr1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{

	  ris -> LoadFromFile("1.bmp");
	  ris->Transparent=True;
	  ris1->Transparent=True;
	 w = ris -> Width / k;
	 h = ris -> Height;
	 kadr -> Width = w;
	 kadr -> Height = h;
	 Pr_kadr = Bounds (0, 0, w, h);
	 Pr_ris = Pr_kadr;
	 kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	 Image2 -> Canvas -> Draw(x,y,kadr);
	ris1 -> LoadFromFile("2.bmp");
	 w1 = ris -> Width / 8;
	 h1 = ris -> Height;
	 kadr1 -> Width = w1;
	 kadr1 -> Height = h1;
	 Pr_kadr1 = Bounds (0, 0, w1, h1);
	 Pr_ris1 = Pr_kadr1;
	 kadr1 -> Canvas -> CopyRect(Pr_kadr1, ris1 -> Canvas, Pr_ris1);
	 Image2 -> Canvas -> Draw(100,100,kadr1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	 x+=w;
	 if (x > k*w)
		 x=0;
	 Pr_ris = Bounds(x, 0, w, h);
	 kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	 Image2 -> Canvas -> Draw(x,y,kadr);

  x1+=w1;
	 if (x1 > k*w1)
		 x1=0;
	 Pr_ris1 = Bounds(x1, 0, w1, h1);
	 kadr1 -> Canvas -> CopyRect(Pr_kadr1, ris1 -> Canvas, Pr_ris1);
	 Image2 -> Canvas -> Draw(x1,y1,kadr1);
	 y=sin(x);
	 y1=sin(x1)+100;
}
//---------------------------------------------------------------------------


