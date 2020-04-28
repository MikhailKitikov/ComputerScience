//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap  *kadr=new Graphics::TBitmap(), *fon=new Graphics::TBitmap(), *ris=new Graphics::TBitmap(), *kadr1=new Graphics::TBitmap(), *fon1=new Graphics::TBitmap(), *ris1=new Graphics::TBitmap();;
 TRect Pr_fon, Pr_kadr,Pr_ris,Pr_fon1, Pr_kadr1,Pr_ris1;
 int w, h, x=0, y=0,k=2,p=4,x_mv,y_mv,w1, h1, x1=0, y1=0,k1=2,p1=4,x_mv1,y_mv1;
 double a=0,a1=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
ris->LoadFromFile("00.bmp");
	 ris->Transparent=true;
	 kadr->Transparent=true;
	 w=ris->Width/k;
	 h=ris->Height/p;
	 kadr->Width=w;
	 kadr->Height=h;

	 Pr_kadr=Bounds(0,0,w,h);
	 Pr_ris=Pr_kadr;

	 x_mv=-w;
	 y_mv=Image1->Height/15;

	 fon->Width=w;
	 fon->Height=h;

	 Pr_fon=Bounds(x_mv+w,y_mv,w,h);
	 fon->Canvas->CopyRect(Pr_kadr,Image1->Canvas,Pr_fon);

	 kadr->Canvas->CopyRect(Pr_kadr,ris->Canvas,Pr_ris);
	 Image1->Canvas->Draw(x_mv,y_mv,kadr);



	  ris1->LoadFromFile("ar.bmp");
	 ris1->Transparent=true;
	 kadr1->Transparent=true;
	 w1=ris1->Width/k1;
	 h1=ris1->Height/p1;
	 kadr1->Width=w1;
	 kadr1->Height=h1;

	 Pr_kadr1=Bounds(0,0,w1,h1);
	 Pr_ris1=Pr_kadr1;

	 x_mv1=-w1;
	 y_mv1=Image1->Height/2;

	 fon1->Width=w1 ;
	 fon1->Height=h1;

	 Pr_fon1=Bounds(x_mv1+w1,y_mv1,w1,h1);
	 fon1->Canvas->CopyRect(Pr_kadr1,Image1->Canvas,Pr_fon1);

	 kadr1->Canvas->CopyRect(Pr_kadr1,ris1->Canvas,Pr_ris1);
	 Image1->Canvas->Draw(x_mv1,y_mv1,kadr1);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 x+=w;
	 if(x>k*w)
	 {
	 x=0;
	 y+=h;
	 }
	 if(y>(p-1)*h)
	 {
	 y=0;
	 y_mv=Image1->Height/15;
	 }
	 Pr_ris=Bounds(x,y,w,h);
	 kadr->Canvas->CopyRect(Pr_kadr,ris->Canvas,Pr_ris);

	 Image1->Canvas->CopyRect(Pr_fon,fon->Canvas,Pr_kadr);
	 x_mv+=10;
	 y_mv=y_mv+5*sin(a);
	 if(x_mv>Image1->Width)
	 x_mv=-w;
	 Pr_fon=Bounds(x_mv,y_mv,w,h);
	 fon->Canvas->CopyRect(Pr_kadr,Image1->Canvas,Pr_fon);

	 Image1->Canvas->Draw(x_mv,y_mv,kadr);
	 a=a+0.3;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
 x1+=w1;
	 if(x1>k1*w1)
	 {
	 x1=0;
	 y1+=h1;
	 }
	 if(y1>p1*h1)
	 {
	 y1=0;
	 y_mv1=Image1->Height/2;
	 }
	 Pr_ris1=Bounds(x1,y1,w1,h1);
	 kadr1->Canvas->CopyRect(Pr_kadr1,ris1->Canvas,Pr_ris1);

	 Image1->Canvas->CopyRect(Pr_fon1,fon1->Canvas,Pr_kadr1);
	 x_mv1+=10;
	 y_mv1=y_mv1+2*sin(a1);
	 if(x_mv1>Image1->Width)
	 x_mv1=-w1;
	 Pr_fon1=Bounds(x_mv1,y_mv1,w1,h1);
	 fon1->Canvas->CopyRect(Pr_kadr1,Image1->Canvas,Pr_fon1);

	 Image1->Canvas->Draw(x_mv1,y_mv1,kadr1);
	 a1=a1+0.3;
}
//---------------------------------------------------------------------------

