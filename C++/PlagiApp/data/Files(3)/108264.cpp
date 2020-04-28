//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <cmath>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap  *kadr=new Graphics::TBitmap(), *ris=new Graphics::TBitmap();
Graphics::TBitmap  *kadr1=new Graphics::TBitmap(), *ris1=new Graphics::TBitmap();
int k = 8, k1 = 4;
int w, h, x, w1, h1, x1;
double a = 3, b, d = 6;
int c = 0;
int im2top = 160;
int im2left = 10;
int im3top = 30;
int im3left = 30;
TRect Pr_ris, Pr_kadr, Pr_ris1, Pr_kadr1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	 ris -> LoadFromFile("cat.bmp");
	 w = ris -> Width / k;
	 h = ris -> Height;
	 kadr -> Width = w;
	 kadr -> Height = h;
	 Pr_kadr = Bounds (0, 0, w, h);
	 Pr_ris = Pr_kadr;
	 kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	 Image2 -> Canvas -> Draw(0,0,kadr);

	 ris1 -> LoadFromFile("ptitca.bmp");
	 w1 = ris1 -> Width / k1;
	 h1 = ris1 -> Height;
	 kadr1 -> Width = w1;
	 kadr1 -> Height = h1;
	 Pr_kadr1 = Bounds (0, 0, w1, h1);
	 Pr_ris1 = Pr_kadr1;
	 kadr1 -> Canvas -> CopyRect(Pr_kadr1, ris1 -> Canvas, Pr_ris1);
	 Image3 -> Canvas -> Draw(0,0,kadr1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	x+=w;
	if (x > k*w)
		x=0;
	Pr_ris = Bounds(x, 0, w, h);
	kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	Image2 -> Canvas -> Draw(0,0,kadr);

	x1+=w1;
	if (x1 > k1*w1)
		x1=0;
	Pr_ris1 = Bounds(x1, 0, w1, h1);
	kadr1 -> Canvas -> CopyRect(Pr_kadr1, ris1 -> Canvas, Pr_ris1);
	Image3 -> Canvas -> Draw(0,0,kadr1);

	c++;
	if (c >= 10) {
	   im2left += a*c;
	   im3left += d*c;
	   c = 0;
	}
	b = int(20*sin(a*c/4));
	Image2->Top = im2top - b;
	Image2->Left = im2left + a*c;
	if (Image2->Left >= Image1->Width) {
		im2left = 0;
		Image2->Left = 0;
	}

	Image3->Top = im3top + b;
	Image3->Left = im3left + d*c ;
	if (Image3->Left >= Image1->Width) {
		im3left = 0;
		Image3->Left = 0;
	}


}
//---------------------------------------------------------------------------
