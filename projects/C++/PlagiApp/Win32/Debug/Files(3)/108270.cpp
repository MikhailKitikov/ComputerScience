//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap  *kadr=new Graphics::TBitmap(), *fon=new Graphics::TBitmap(), *ris=new Graphics::TBitmap();
 TRect Pr_fon, Pr_ris, Pr_kadr;
Graphics::TBitmap  *kadr2=new Graphics::TBitmap(), *fon2=new Graphics::TBitmap(), *ris2=new Graphics::TBitmap(), *ris3=new Graphics::TBitmap();
 TRect Pr_fon2, Pr_ris2, Pr_kadr2;
 int w, h, x, y, k=18,X=0,i=0,x0,y0;
 int w2, h2, x2, y2, k2=15,X2=0;
 double pi=acos(-1.);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	   ris -> LoadFromFile("OBJ.bmp");
	   ris3 -> LoadFromFile("OBJ3.bmp");
	   w = ris -> Width / k;
	   h = ris -> Height;
	   kadr -> Width = w;
	   kadr -> Height = h;
	   Pr_kadr = Bounds (0, 0, w, h);
	   Pr_ris = Pr_kadr;
	   kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	   kadr -> Transparent = true;
	   x = - w;
	   y = 360;
	   fon -> Width = w;
	   fon -> Height =h;
	   Pr_fon = Bounds (x, y, w, h);
	   fon -> Canvas -> CopyRect(Pr_kadr, Image1 -> Canvas, Pr_fon);
	   ris2 -> LoadFromFile("OBJ2.bmp");
	   w2 = ris2 -> Width / k2;
	   h2 = ris2 -> Height;
	   kadr2 -> Width = w2;
	   kadr2 -> Height = h2;
	   Pr_kadr2 = Bounds (0, 0, w2, h2);
	   Pr_ris2 = Pr_kadr2;
	   kadr2 -> Canvas -> CopyRect(Pr_kadr2, ris2 -> Canvas, Pr_ris2);
	   kadr2 -> Transparent = true;
	   x2 = - w2;
	   y2 = 100;
	   fon2 -> Width = w2;
	   fon2 -> Height =h2;
	   Pr_fon2 = Bounds (x2, y2, w2, h2);
	   fon2 -> Canvas -> CopyRect(Pr_kadr2, Image1 -> Canvas, Pr_fon2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	 Image1 -> Canvas -> CopyRect(Pr_fon, fon -> Canvas, Pr_kadr);
	 x++;
	 y=360+50*sin(x*pi/360)+10*sin(x*pi/45);
	 Pr_fon = Bounds (x, y, w, h);
	 fon -> Canvas -> CopyRect(Pr_kadr, Image1 -> Canvas, Pr_fon);
	 X+=w;
	 if (X > k*w)
		 X=0;
	 Pr_ris = Bounds(X, 0, w, h);
	 kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	 Image1 -> Canvas -> Draw(x, y, kadr);
	 if (x==405)
	 {
		Timer1->Enabled=false;
		Timer2->Enabled=true;
		y0=y;
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
	 Image1 -> Canvas -> CopyRect(Pr_fon, fon -> Canvas, Pr_kadr);
	 x++;
	 y=y0+(x-405)*(x-405)/250;
	 Pr_fon = Bounds (x, y, w, h);
	 fon -> Canvas -> CopyRect(Pr_kadr, Image1 -> Canvas, Pr_fon);
	 X+=w;
	 if (X > k*w)
		 X=0;
	 Pr_ris = Bounds(X, 0, w, h);
	 kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	 Image1 -> Canvas -> Draw(x, y, kadr); //624,534
	 if (y>=510)
	 {
		Timer2->Enabled=false;
		Timer3->Enabled=true;
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
	 Image1 -> Canvas -> CopyRect(Pr_fon, fon -> Canvas, Pr_kadr);
	 i++;
	 Pr_fon = Bounds (x, y, w, h);
	 fon -> Canvas -> CopyRect(Pr_kadr, Image1 -> Canvas, Pr_fon);
	 X+=w;
	 if (X > k*w)
		 X=0;
	 Pr_ris = Bounds(X, 0, w, h);
	 kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	 Image1 -> Canvas -> Draw(x, y, kadr);
	 Timer3->Interval+=1;
	 if (i==75)
	 {
		Timer3->Enabled=false;
		Timer4->Enabled=true;
		x0=x;
		y0=y;
		i=0;
	   Timer5->Enabled=true;
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer4Timer(TObject *Sender)
{
	 Image1 -> Canvas -> CopyRect(Pr_fon, fon -> Canvas, Pr_kadr);
	 x++;
	 y=y0-10*sqrt(x-x0);
	 Pr_fon = Bounds (x, y, w, h);
	 fon -> Canvas -> CopyRect(Pr_kadr, Image1 -> Canvas, Pr_fon);
	 X+=w;
	 if (X > k*w)
		 X=0;
	 Pr_ris = Bounds(X, 0, w, h);
	 kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	 Image1 -> Canvas -> Draw(x, y, kadr);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer5Timer(TObject *Sender)
{
	 Image1 -> Canvas -> CopyRect(Pr_fon2, fon2 -> Canvas, Pr_kadr2);
	 x2+=7;
	 y2+=(y+30-y2)/100;
	 Pr_fon2 = Bounds (x2, y2, w2, h2);
	 fon2 -> Canvas -> CopyRect(Pr_kadr2, Image1 -> Canvas, Pr_fon2);
	 X2+=w2;
	 if (X2 > k2*w2)
		 X2=0;
	 Pr_ris2 = Bounds(X2, 0, w2, h2);
	 kadr2 -> Canvas -> CopyRect(Pr_kadr2, ris2 -> Canvas, Pr_ris2);
	 Image1 -> Canvas -> Draw(x2, y2, kadr2);
	 if (x-x2-249<=3)
	 {
		Timer5->Enabled=false;
		Timer4->Enabled=false;
		Image1 -> Canvas -> CopyRect(Pr_fon, fon -> Canvas, Pr_kadr);
		Timer6->Enabled=true;
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer6Timer(TObject *Sender)
{
	 Image1 -> Canvas -> CopyRect(Pr_fon2, fon2 -> Canvas, Pr_kadr2);
	 x2+=10;
	 y2-=y2/50;
	 Pr_fon2 = Bounds (x2, y2, w2, h2);
	 fon2 -> Canvas -> CopyRect(Pr_kadr2, Image1 -> Canvas, Pr_fon2);
	 X2+=w2;
	 if (X2 > k2*w2)
		 X2=0;
	 Pr_ris2 = Bounds(X2, 0, w2, h2);
	 kadr2 -> Canvas -> CopyRect(Pr_kadr2, ris3 -> Canvas, Pr_ris2);
	 Image1 -> Canvas -> Draw(x2, y2, kadr2);
	 if (x2>1.2*Image1->Width)
	 {
		Timer6->Enabled=false;
		ris2 -> LoadFromFile("OBJ4.bmp");
		Timer7->Enabled=true;
		y2=200;
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer7Timer(TObject *Sender)
{
	 Image1 -> Canvas -> CopyRect(Pr_fon2, fon2 -> Canvas, Pr_kadr2);
	 x2-=5;
	 y2=-0.001*x2*x2+1.1*x2;
	 Pr_fon2 = Bounds (x2, y2, w2, h2);
	 fon2 -> Canvas -> CopyRect(Pr_kadr2, Image1 -> Canvas, Pr_fon2);
	 X2+=w2;
	 if (X2 > k2*w2)
		 X2=0;
	 Pr_ris2 = Bounds(X2, 0, w2, h2);
	 kadr2 -> Canvas -> CopyRect(Pr_kadr2, ris2 -> Canvas, Pr_ris2);
	 Image1 -> Canvas -> Draw(x2, y2, kadr2);
	 if (x2 < -w2)
	 {
		 Timer7->Enabled=false;
		 Timer1->Enabled=true;
		 x = -w;
	 }
}
//---------------------------------------------------------------------------
