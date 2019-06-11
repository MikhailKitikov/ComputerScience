//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdlib.h>
#include <cmath>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap  *kadr=new Graphics::TBitmap(), *ris=new Graphics::TBitmap(), *fon=new Graphics::TBitmap(), *kadr2=new Graphics::TBitmap(), *ris2=new Graphics::TBitmap(), *fon2=new Graphics::TBitmap(), *kadr3=new Graphics::TBitmap(), *ris3=new Graphics::TBitmap(), *fon3=new Graphics::TBitmap();
int k = 8,k2 = 4;
double t=0, x2 = 800, y2 = 50, x3, y3;
int p, life = 3, spider = 7, xcor,ycor,eat=0, a=6, b=8,  w, h, w2, h2, w3, h3, x=450, y=600,  x_ris=0, y_ris=0, x_ris2=0, y_ris2=0, x_ris3=0, y_ris3=0, move = -1,  speed=5, target, web = 0, earned = 100, product;
String MacDonalds[5] = {"картофель фри", "гамбургер", "биг мак", "Coca Cola", "деньги"};
int cost[5] = {20,25,45,30,100};
TRect Pr_ris, Pr_kadr, Pr_fon, Pr_ris2, Pr_kadr2, Pr_fon2, Pr_ris3, Pr_kadr3, Pr_fon3;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	 srand(time(NULL));
	 ris -> LoadFromFile("SpiderMan.bmp");
	 kadr -> Transparent = true;
	 w = ris -> Width / k;
	 h = ris -> Height/2;
	 kadr -> Width = w;
	 kadr -> Height = h;
	 fon -> Width = w;
	 fon -> Height =h;
	 Pr_kadr = Bounds (0, 0, w, h);
	 Pr_ris = Pr_kadr;
	 Pr_fon = Bounds (x, y, w, h);
	 kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	 fon -> Canvas -> CopyRect(Pr_kadr, Image1 -> Canvas, Pr_fon);
	 Image1 -> Canvas -> Draw(x,y,kadr);
	 //
	 ris2 -> LoadFromFile("Spider.bmp");
	 kadr2 -> Transparent = true;
	 w2 = ris2 -> Width / k2;
	 h2 = ris2 -> Height/4;
	 kadr2 -> Width = w2;
	 kadr2 -> Height = h2;
	 fon2 -> Width = w2;
	 fon2 -> Height =h2;
	 Pr_kadr2 = Bounds (0, 0, w2, h2);
	 Pr_ris2 = Pr_kadr2;
	 Pr_fon2 = Bounds (x2, y2, w2, h2);
	 kadr2 -> Canvas -> CopyRect(Pr_kadr2, ris2 -> Canvas, Pr_ris2);
	 fon2 -> Canvas -> CopyRect(Pr_kadr2, Image1 -> Canvas, Pr_fon2);
	 Image1 -> Canvas -> Draw(x2,y2,kadr2);
	 //
	 ris3 -> LoadFromFile("Web.bmp");
	 kadr3 -> Transparent = true;
	 w3 = ris3 -> Width / 5;
	 h3 = ris3 -> Height;
	 kadr3 -> Width = w3;
	 kadr3 -> Height = h3;
	 fon3 -> Width = w3;
	 fon3 -> Height =h3;
	 Pr_kadr3 = Bounds (0, 0, w3, h3);
	 Pr_ris3 = Pr_kadr3;
	 Pr_fon3 = Bounds (x3, y3, w3, h3);
	 //
	 product = rand()%5;
	 Label2->Caption = "Target: " + MacDonalds[product];
	 target = product;
	 switch(product)
	 {
		 case 0:
		 {
			 Image3->Picture->LoadFromFile("MacDonald's1.bmp");
			 break;
		 }
		 case 1:
		 {
			 Image3->Picture->LoadFromFile("MacDonald's2.bmp");
			 break;
		 }
		 case 2:
		 {
			 Image3->Picture->LoadFromFile("MacDonald's3.bmp");
			 break;
		 }
		 case 3:
		 {
			 Image3->Picture->LoadFromFile("MacDonald's4.bmp");
			 break;
		 }
		 case 4:
		 {
			 Image3->Picture->LoadFromFile("MacDonald's5.bmp");
			 break;
		 }
	 }
	 xcor = rand()%800+100;
	 ycor = rand()%650+50;
	 Image3->Left = xcor;
	 Image3->Top = ycor;
	 Label3->Caption = "$" + IntToStr(earned);
	 Image2->Picture->LoadFromFile("Trump.bmp");
	 Label4->Caption = "Life: " + IntToStr(life);
	 Label6->Caption = "Enemy's life: " + IntToStr(spider);
	 x3 = x;
	 y3 = y;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	 Image1 -> Canvas -> CopyRect(Pr_fon, fon -> Canvas, Pr_kadr);
	 x_ris += w;
	 x+=1;
	 if (x_ris > k*w)
		 x_ris = 0;
	 if (x > Image1 -> Width)
		x = -w;
	 switch(move)
	 {
		 case 1:
		 {
			if(y>50)
				y -= speed;
			else
				SpeedButton2->Click();
			break;
		 }
		 case 2:
		 {
			if(y<700)
				y += speed;
			else
				SpeedButton1->Click();
			break;
		 }
		 case 3:
		 {
			if(x<900)
				x += speed;
			else
				SpeedButton4->Click();
			break;
		 }
		 case 4:
		 {
			if(x>0)
				x -= speed;
			else
				SpeedButton3->Click();
			break;
		 }
	 }
	 Pr_ris = Bounds(x_ris, y_ris, w, h);
	 kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	 Pr_fon = Bounds (x, y, w, h);
	 fon -> Canvas -> CopyRect(Pr_kadr, Image1 -> Canvas, Pr_fon);
	 Image1 -> Canvas -> Draw(x,y,kadr);
	 int medx = xcor+Image3->Width/2;
	 int medy = ycor+Image3->Height/2;
	 if(medx >= x-20 && medx <= x+w+20 && medy >= y-20 && medy <= y+h+20)
	 {
		 Image2->Visible = true;
		 earned += cost[product];
		 Label3->Caption = "$" + IntToStr(earned);
		 product = rand()%5;
		 Label2->Caption = "Target: " + MacDonalds[product];
		 target = product;
		 switch(product)
		 {
			case 0:
			 {
				 Image3->Picture->LoadFromFile("MacDonald's1.bmp");
				 break;
			}
			case 1:
			{
				 Image3->Picture->LoadFromFile("MacDonald's2.bmp");
				 break;
			}
			case 2:
			{
				 Image3->Picture->LoadFromFile("MacDonald's3.bmp");
				 break;
			}
			case 3:
			{
				 Image3->Picture->LoadFromFile("MacDonald's4.bmp");
				 break;
			}
			case 4:
			{
				 Image3->Picture->LoadFromFile("MacDonald's5.bmp");
				 break;
			}
		 }
		 xcor = rand()%800+100;
		 ycor = rand()%650+50;
		 Image3->Left = xcor;
		 Image3->Top = ycor;
		 Timer3->Enabled = true;
		 life++;
		 Label2->Caption = "Target: " + MacDonalds[product];
	 }
	 if(x>600 && y<300)
	 {
		Timer2->Enabled = false;
		Timer1->Enabled = false;
		Image1 -> Canvas -> CopyRect(Pr_fon2, fon2 -> Canvas, Pr_kadr2);
		x2 = x;
		y2 = y;
		kadr2 -> Canvas -> CopyRect(Pr_kadr2, ris2 -> Canvas, Pr_ris2);
		fon2 -> Canvas -> CopyRect(Pr_kadr2, Image1 -> Canvas, Pr_fon2);
		Image1 -> Canvas -> Draw(x2,y2,kadr2);
		SpeedButton8->Visible = true;
		SpeedButton8->Enabled = true;
		SpeedButton8->Caption = "You have been killed!!! (tap to continue)";
		SpeedButton1->Visible = false;
		SpeedButton2->Visible = false;
		SpeedButton3->Visible = false;
		SpeedButton4->Visible = false;
		SpeedButton5->Visible = false;
		SpeedButton6->Visible = false;
		SpeedButton7->Visible = false;
		SpeedButton9->Visible = false;
		Label1->Visible = false;
	 }
	 Label3->Caption = "$" + IntToStr(earned);
	 Label4->Caption = "Life: " + IntToStr(life);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	Timer1->Enabled = true;
	move = 1;
	x_ris = 0;
	y_ris = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
	Timer1->Enabled = true;
	move = 2;
	x_ris = 0;
	y_ris = h;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
	Timer1->Enabled = true;
	move = 3;
	x_ris = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
	Timer1->Enabled = true;
	move = 4;
	x_ris = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{
	if(Timer1->Enabled == true)
	{
		 Timer1->Enabled = false;
		 move = -1;
	}
	else
		Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton6Click(TObject *Sender)
{
	speed++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton7Click(TObject *Sender)
{
	if(speed>1)
		speed--;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
	 if(t<6.283)
		t+=0.01;
	 else
		t = 0;
	 Image1 -> Canvas -> CopyRect(Pr_fon2, fon2 -> Canvas, Pr_kadr2);
	 x_ris2 += w2;
	 if (x_ris2 > k2*w2)
	 {
		x_ris2 = 0;
		y_ris2++;
		if(y_ris2 > 3)
			y_ris2 = 0;
	 }
		x2 = 750 + 100*cos(a*t);
		y2 = 150 + 100*sin(b*t);
	 Pr_ris2 = Bounds(x_ris2, y_ris2, w2, h2);
	 kadr2 -> Canvas -> CopyRect(Pr_kadr2, ris2 -> Canvas, Pr_ris2);
	 Pr_fon2 = Bounds (x2, y2, w2, h2);
	 fon2 -> Canvas -> CopyRect(Pr_kadr2, Image1 -> Canvas, Pr_fon2);
	 Image1 -> Canvas -> Draw(x2,y2,kadr2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer3Timer(TObject *Sender)
{

	Timer1->Enabled = true;
	Timer2->Enabled = true;
	Timer3->Enabled = false;
	Image2->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton8Click(TObject *Sender)
{
	SpeedButton8->Visible = false;
	SpeedButton8->Enabled = false;
	Image1 -> Canvas -> CopyRect(Pr_fon, fon -> Canvas, Pr_kadr);
	x=450;
	y=600;
	x_ris = 0;
	y_ris = 0;
	Pr_ris = Bounds(x_ris, y_ris, w, h);
	kadr -> Canvas -> CopyRect(Pr_kadr, ris -> Canvas, Pr_ris);
	Pr_fon = Bounds (x, y, w, h);
	fon -> Canvas -> CopyRect(Pr_kadr, Image1 -> Canvas, Pr_fon);
	Image1 -> Canvas -> Draw(x,y,kadr);
	life--;
	if(life == 0)
	{
		life = 3;
		earned = 0;
		Label3->Caption = "$" + IntToStr(earned);
	}
	Timer2->Enabled = true;
	SpeedButton1->Visible = true;
	SpeedButton2->Visible = true;
	SpeedButton3->Visible = true;
	SpeedButton4->Visible = true;
	SpeedButton5->Visible = true;
	SpeedButton6->Visible = true;
	SpeedButton7->Visible = true;
	SpeedButton9->Visible = true;
	Label1->Visible = true;
	Image1->Picture->LoadFromFile("Scyscraper.bmp");
	Image1 -> Canvas -> Draw(x,y,kadr);
	Label4->Caption = "Life: " + IntToStr(life);
	product = rand()%5;
	Label2->Caption = "Target: " + MacDonalds[product];
	target = product;
	switch(product)
	{
	 case 0:
	 {
		 Image3->Picture->LoadFromFile("MacDonald's1.bmp");
		 break;
	 }
	 case 1:
	 {
		 Image3->Picture->LoadFromFile("MacDonald's2.bmp");
		 break;
	 }
	 case 2:
	 {
		 Image3->Picture->LoadFromFile("MacDonald's3.bmp");
		 break;
	 }
	 case 3:
	 {
		 Image3->Picture->LoadFromFile("MacDonald's4.bmp");
		 break;
	 }
	 case 4:
	 {
		 Image3->Picture->LoadFromFile("MacDonald's5.bmp");
		 break;
	 }
	}
	xcor = rand()%800+100;
	ycor = rand()%650+50;
	Image3->Left = xcor;
	Image3->Top = ycor;
	move = -1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label5Click(TObject *Sender)
{
	Label5->Visible = false;
	Label5->Enabled = false;
	Timer2->Enabled = true;
	Image3->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton9Click(TObject *Sender)
{
	web = 1;
	Timer4->Enabled = true;
	p = 1;
	switch(move)
	{
		case 1:
		{
			x3 = x;
			y3 = y-120;
			break;
		}
		case 2:
		{
			x3 = x;
			y3 = y+120;
			break;
		}
		case 3:
		{
			x3 = x+70;
			y3 = y;
			break;
		}
		case 4:
		{
			x3 = x-70;
			y3 = y;
			break;
		}
		default:
		{
			x3 = x+50;
			y3 = y-50;
			break;
		}
	}
	fon3 -> Canvas -> CopyRect(Pr_kadr3, Image1 -> Canvas, Pr_fon3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer4Timer(TObject *Sender)
{
	 Image1 -> Canvas -> CopyRect(Pr_fon3, fon3 -> Canvas, Pr_kadr3);
	 x_ris3 += w3-10;
	 if (x_ris3 > 5*w3)
		x_ris3 = 0;
	 if(x3>=0 && x3<=1000 && y3>=0 && y3<=800)
	 {
		switch(move)
		{
			 case 1:
			{
				y3-=20;
				break;
			}
			case 2:
			{
				y3+=20;
				break;
			}
			case 3:
			{
				x3+=20;
				break;
			}
			case 4:
			{
				x3-=20;
				break;
			}
			default:
			{
			x3 += 20;
			y3 -= 20;
			break;
			}
		}
	 }
	 else
		Timer4->Enabled = false;
	 Pr_ris3 = Bounds(x_ris3, y_ris3, w3, h3);
	 kadr3 -> Canvas -> CopyRect(Pr_kadr3, ris3 -> Canvas, Pr_ris3);
	 Pr_fon3 = Bounds (x3, y3, w3, h3);
	 fon3 -> Canvas -> CopyRect(Pr_kadr3, Image1 -> Canvas, Pr_fon3);
	 Image1 -> Canvas -> Draw(x3,y3,kadr3);
	 int medx = x3+w3/2;
	 int medy = y3+h3/2;
	 if(medx >= x2-20 && medx <= x2+w2+20 && medy >= y2-20 && medy <= y2+h2+20)
	 {
	   if(p==1)
	   {
			spider--;
			p = 0;
	   }
	   if(spider==0)
	   {
		 spider = 7;
		 earned += 50;
		 Timer2->Enabled = false;
		 Timer1->Enabled = false;
		 Image1 -> Canvas -> CopyRect(Pr_fon2, fon2 -> Canvas, Pr_kadr2);
		 x2 = x;
		 y2 = y;
		 kadr2 -> Canvas -> CopyRect(Pr_kadr2, ris2 -> Canvas, Pr_ris2);
		 fon2 -> Canvas -> CopyRect(Pr_kadr2, Image1 -> Canvas, Pr_fon2);
		 Image1 -> Canvas -> Draw(x2,y2,kadr2);
		 SpeedButton8->Visible = true;
		 SpeedButton8->Enabled = true;
		 SpeedButton8->Caption = "You killed the enemy!!! (tap to continue)";
		 SpeedButton1->Visible = false;
		 SpeedButton2->Visible = false;
		 SpeedButton3->Visible = false;
		 SpeedButton4->Visible = false;
		 SpeedButton5->Visible = false;
		 SpeedButton6->Visible = false;
		 SpeedButton7->Visible = false;
		 SpeedButton9->Visible = false;
		 Label1->Visible = false;
	   }
	   Label3->Caption = "$" + IntToStr(earned);
	   Label6->Caption = "Enemy's life: " + IntToStr(spider);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer5Timer(TObject *Sender)
{
	Image1->Picture->LoadFromFile("Scyscraper.bmp");
	Image1 -> Canvas -> Draw(x,y,kadr);
	Image1 -> Canvas -> Draw(x2,y2,kadr2);
	if(web == 1)
		Image1 -> Canvas -> Draw(x3,y3,kadr3);
	web = 0;
}
//---------------------------------------------------------------------------

