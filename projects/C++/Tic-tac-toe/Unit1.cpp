//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdlib.h>

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;

char a[3][3], signPL = 'X', signCP = 'O';
string SignFile = "Cross.bmp";
int num = 0, nwins  = 0, ngames = 0, winner = 0, comb = 0, index = 0;

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void standart_settings()
{
  for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	  a[i][j]=' ';
}
string Sign(char button)
{
  string sign_button;
  switch(button)
  {
	  case ' ': {sign_button = "Empty.bmp";break;}
	  case 'O': {sign_button = "Zero.bmp";break;}
	  case 'X': {sign_button = "Cross.bmp";break;}
  }
  return sign_button;
}
void show_table()
{
  Form1->SpeedButton1->Glyph->LoadFromFile(Sign(a[0][0]).c_str());
  Form1->SpeedButton2->Glyph->LoadFromFile(Sign(a[0][1]).c_str());
  Form1->SpeedButton3->Glyph->LoadFromFile(Sign(a[0][2]).c_str());
  Form1->SpeedButton4->Glyph->LoadFromFile(Sign(a[1][0]).c_str());
  Form1->SpeedButton5->Glyph->LoadFromFile(Sign(a[1][1]).c_str());
  Form1->SpeedButton6->Glyph->LoadFromFile(Sign(a[1][2]).c_str());
  Form1->SpeedButton7->Glyph->LoadFromFile(Sign(a[2][0]).c_str());
  Form1->SpeedButton8->Glyph->LoadFromFile(Sign(a[2][1]).c_str());
  Form1->SpeedButton9->Glyph->LoadFromFile(Sign(a[2][2]).c_str());
}
bool check_play()
{
 int p=0;
 for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	 if(a[i][j]==' ')
	 {
	  p=1;
	  break;
     }
 if(p==1)
    return true;
 else
	return false;
}
void best_choice(char r, char g)
{
	Sleep(100);
	for(int i=0;i<3;i++)
    {
	 if(a[i][0]==r && a[i][1]==r && a[i][2]==' ')
        {a[i][2]=g;break;}
     if(a[i][0]==r && a[i][2]==r && a[i][1]==' ')
        {a[i][1]=g;break;}
     if(a[i][1]==r && a[i][2]==r && a[i][0]==' ')
        {a[i][0]=g;break;}
     if(a[0][i]==r && a[1][i]==r && a[2][i]==' ')
        {a[2][i]=g;break;}
     if(a[0][i]==r && a[2][i]==r && a[1][i]==' ')
        {a[1][i]=g;break;}
     if(a[1][i]==r && a[2][i]==r && a[0][i]==' ')
        {a[0][i]=g;break;}
     if(a[0][0]==r && a[1][1]==r && a[2][2]==' ')
        {a[2][2]=g;break;}
     if(a[0][0]==r && a[2][2]==r && a[1][1]==' ')
		{a[1][1]=g;break;}
     if(a[1][1]==r && a[2][2]==r && a[0][0]==' ')
        {a[0][0]=g;break;}
     if(a[0][2]==r && a[1][1]==r && a[2][0]==' ')
        {a[2][0]=g;break;}
     if(a[0][2]==r && a[2][0]==r && a[1][1]==' ')
        {a[1][1]=g;break;}
     if(a[1][1]==r && a[2][0]==r && a[0][2]==' ')
        {a[0][2]=g;break;}
    }
};
void put_object()
{
	Sleep(100);
	int p=0;
	for(int i=0;i<3;i++)
	{
	 for(int j=0;j<3;j++)
		 if(a[0][j] == ' ')
			{a[0][j] = signCP; p=-1; break;}
	 if(p==-1)
	   break;
	}
}
bool point(char q)
{
 int p=0;
 for(int i=0;i<3;i++)
	{
	 if(a[i][0]==q && a[i][1]==q && a[i][2]==' ')
		{p=1;break;}
	 if(a[i][0]==q && a[i][2]==q && a[i][1]==' ')
        {p=1;break;}
     if(a[i][1]==q && a[i][2]==q && a[i][0]==' ')
		{p=1;break;}
     if(a[0][i]==q && a[1][i]==q && a[2][i]==' ')
        {p=1;break;}
     if(a[0][i]==q && a[2][i]==q && a[1][i]==' ')
        {p=1;break;}
     if(a[1][i]==q && a[2][i]==q && a[0][i]==' ')
        {p=1;break;}
	 if(a[0][0]==q && a[1][1]==q && a[2][2]==' ')
        {p=1;break;}
     if(a[0][0]==q && a[2][2]==q && a[1][1]==' ')
        {p=1;break;}
     if(a[1][1]==q && a[2][2]==q && a[0][0]==' ')
        {p=1;break;}
     if(a[0][2]==q && a[1][1]==q && a[2][0]==' ')
        {p=1;break;}
	 if(a[0][2]==q && a[2][0]==q && a[1][1]==' ')
        {p=1;break;}
     if(a[1][1]==q && a[2][0]==q && a[0][2]==' ')
		{p=1;break;}
    }
 if(p==1)
    return true;
 else
    return false;
}
void New_Game()
{
	Form1->SpeedButton10->Enabled = true;
	Form1->SpeedButton10->Visible= true;
	Form1->SpeedButton1->Enabled = false;
	Form1->SpeedButton2->Enabled = false;
	Form1->SpeedButton3->Enabled = false;
	Form1->SpeedButton4->Enabled = false;
	Form1->SpeedButton5->Enabled = false;
	Form1->SpeedButton6->Enabled = false;
	Form1->SpeedButton7->Enabled = false;
	Form1->SpeedButton8->Enabled = false;
	Form1->SpeedButton9->Enabled = false;
}
bool check_win(char d)
{
 int i=0,p=0;
 while(i<3)
 {
   if(a[i][0]==d && a[i][1]==d && a[i][2]==d)
   {
		comb = 1;
		index = i;
		p++;
   }
   if(a[0][i]==d && a[1][i]==d && a[2][i]==d)
   {
		comb = 2;
		index = i;
		p++;
   }
   if(a[0][0]==d && a[1][1]==d && a[2][2]==d)
   {
		comb = 3;
		p++;
   }
   if(a[0][2]==d && a[1][1]==d && a[2][0]==d)
   {
		comb = 4;
		p++;
   }
   if(p !=0)
	 {return true;break;}
   i++;
 }
  if(p==0)
	  return false;
}
void win()
{
int a,b,c;
ifstream fin("Resource.txt");
fin >> a >> b >> c;
a++;
if( winner == 1) b++;
c = (double)b/a*100;
ofstream fout("Resource.txt");
fout << a << endl << b << endl << c << endl;
Form3->Label1->Caption = "Проведено игр: " + IntToStr(a);
Form3->Label2->Caption = "Выиграно: " + IntToStr(b);
Form3->Label3->Caption = "Процент выигрышей: " + IntToStr(c) + '%';
   if(comb == 1)
   {
		switch(index)
		{
			case 0:
			{
				Form1->SpeedButton1->Flat = false;
				Form1->SpeedButton2->Flat = false;
				Form1->SpeedButton3->Flat = false;
				break;
			}
			case 1:
			{
				Form1->SpeedButton4->Flat = false;
				Form1->SpeedButton5->Flat = false;
				Form1->SpeedButton6->Flat = false;
				break;
			}
			case 2:
			{
				Form1->SpeedButton7->Flat = false;
				Form1->SpeedButton8->Flat = false;
				Form1->SpeedButton9->Flat = false;
				break;
			}
		}
   }
   if(comb == 2)
   {
		switch(index)
		{
			case 0:
			{
				Form1->SpeedButton1->Flat = false;
				Form1->SpeedButton4->Flat = false;
				Form1->SpeedButton7->Flat = false;
				break;
			}
			case 1:
			{
				Form1->SpeedButton2->Flat = false;
				Form1->SpeedButton5->Flat = false;
				Form1->SpeedButton8->Flat = false;
				break;
			}
			case 2:
			{
				Form1->SpeedButton3->Flat = false;
				Form1->SpeedButton6->Flat = false;
				Form1->SpeedButton9->Flat = false;
				break;
			}
		}
   }
   if(comb == 3)
   {
		Form1->SpeedButton1->Flat = false;
		Form1->SpeedButton5->Flat = false;
		Form1->SpeedButton9->Flat = false;
   }
   if(comb == 4)
   {
		Form1->SpeedButton3->Flat = false;
		Form1->SpeedButton5->Flat = false;
		Form1->SpeedButton7->Flat = false;
   }
   New_Game();
}
void play()
{
	  if(point(signCP))
	  {
		best_choice(signCP,signCP);
		show_table();
		ngames++;
		winner = 2;
		ShowMessage("Вы проиграли :(");
		if(check_win(signCP))
			win();
	  }
	  else
		if(point(signPL))
		   best_choice(signPL,signCP);
		else
		   put_object();
	  show_table();
}
void __fastcall TForm1::N8Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{
Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N9Click(TObject *Sender)
{
Form4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
Form5->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
standart_settings();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
  if(a[0][0] == ' ')
  {
	SpeedButton1->Glyph->LoadFromFile(SignFile.c_str());
	a[0][0] = signPL;
	if(check_win(signPL))
	{
		ShowMessage("Поздравляю! Вы победили :)");
		winner = 1;
		win();
		ngames++;
		nwins++;
	}
	else
		play();
  }
  if(!check_play() && winner == 0)
  {
	  ShowMessage("Ничья!");
	  ngames++;
	  New_Game();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
  if(a[0][1] == ' ')
  {
	SpeedButton1->Glyph->LoadFromFile(SignFile.c_str());
	a[0][1] = signPL;
	if(check_win(signPL))
	{
		ShowMessage("Поздравляю! Вы победили :)");
		winner = 1;
		win();
		ngames++;
		nwins++;
	}
	else
		play();
  }
  if(!check_play() && winner == 0)
  {
	  ShowMessage("Ничья!");
	  ngames++;
	  New_Game();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
  if(a[0][2] == ' ')
  {
	SpeedButton1->Glyph->LoadFromFile(SignFile.c_str());
	a[0][2] = signPL;
	if(check_win(signPL))
	{
		ShowMessage("Поздравляю! Вы победили :)");
		winner = 1;
		win();
		ngames++;
		nwins++;
	}
	else
		play();
  }
  if(!check_play() && winner == 0)
  {
	  ShowMessage("Ничья!");
	  ngames++;
	  New_Game();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
  if(a[1][0] == ' ')
  {
	SpeedButton1->Glyph->LoadFromFile(SignFile.c_str());
	a[1][0] = signPL;
	if(check_win(signPL))
	{
		ShowMessage("Поздравляю! Вы победили :)");
		winner = 1;
		win();
		ngames++;
		nwins++;
	}
	else
		play();
  }
  if(!check_play() && winner == 0)
  {
	  ShowMessage("Ничья!");
	  ngames++;
	  New_Game();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{
  if(a[1][1] == ' ')
  {
	SpeedButton1->Glyph->LoadFromFile(SignFile.c_str());
	a[1][1] = signPL;
	if(check_win(signPL))
	{
		ShowMessage("Поздравляю! Вы победили :)");
		winner = 1;
		win();
		ngames++;
		nwins++;
	}
	else
		play();
  }
  if(!check_play() && winner == 0)
  {
	  ShowMessage("Ничья!");
	  ngames++;
	  New_Game();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton6Click(TObject *Sender)
{
  if(a[1][2] == ' ')
  {
	SpeedButton1->Glyph->LoadFromFile(SignFile.c_str());
	a[1][2] = signPL;
	if(check_win(signPL))
	{
		ShowMessage("Поздравляю! Вы победили :)");
		winner = 1;
		win();
		ngames++;
		nwins++;
	}
	else
		play();
  }
  if(!check_play() && winner == 0)
  {
	  ShowMessage("Ничья!");
	  ngames++;
	  New_Game();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton7Click(TObject *Sender)
{
  if(a[2][0] == ' ')
  {
	SpeedButton1->Glyph->LoadFromFile(SignFile.c_str());
	a[2][0] = signPL;
	if(check_win(signPL))
	{
		ShowMessage("Поздравляю! Вы победили :)");
		winner = 1;
		win();
		ngames++;
		nwins++;
	}
	else
		play();
  }
  if(!check_play() && winner == 0)
  {
	  ShowMessage("Ничья!");
	  ngames++;
	  New_Game();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton8Click(TObject *Sender)
{
  if(a[2][1] == ' ')
  {
	SpeedButton1->Glyph->LoadFromFile(SignFile.c_str());
	a[2][1] = signPL;
	if(check_win(signPL))
	{
		ShowMessage("Поздравляю! Вы победили :)");
		winner = 1;
		win();
		ngames++;
		nwins++;
	}
	else
		play();
  }
  if(!check_play() && winner == 0)
  {
	  ShowMessage("Ничья!");
	  ngames++;
	  New_Game();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton9Click(TObject *Sender)
{
  if(a[2][2] == ' ')
  {
	SpeedButton1->Glyph->LoadFromFile(SignFile.c_str());
	a[2][2] = signPL;
	if(check_win(signPL))
	{
		ShowMessage("Поздравляю! Вы победили :)");
		winner = 1;
		win();
		ngames++;
		nwins++;
	}
	else
		play();
  }
  if(!check_play() && winner == 0)
  {
      int a,b,c;
	  ifstream fin("Resource.txt");
	  fin >> a >> b >> c;
	  a++;
	  c = b/a*100;
	  ofstream fout("Resource.txt");
	  fout << a << endl << b << endl << c << endl;
	  Form3->Label1->Caption = "Проведено игр: " + IntToStr(a);
	  Form3->Label2->Caption = "Выиграно: " + IntToStr(b);
	  Form3->Label3->Caption = "Процент выигрышей: " + IntToStr(c) + '%';
	  ShowMessage("Ничья!");
	  ngames++;
	  New_Game();
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton10Click(TObject *Sender)
{
	standart_settings();
	show_table();
	Form1->SpeedButton1->Flat = true;
	Form1->SpeedButton2->Flat = true;
	Form1->SpeedButton3->Flat = true;
	Form1->SpeedButton4->Flat = true;
	Form1->SpeedButton5->Flat = true;
	Form1->SpeedButton6->Flat = true;
	Form1->SpeedButton7->Flat = true;
	Form1->SpeedButton8->Flat = true;
	Form1->SpeedButton9->Flat = true;
	Form1->SpeedButton10->Visible = false;
	Form1->SpeedButton10->Enabled = false;
	Form1->SpeedButton1->Enabled = true;
	Form1->SpeedButton2->Enabled = true;
	Form1->SpeedButton3->Enabled = true;
	Form1->SpeedButton4->Enabled = true;
	Form1->SpeedButton5->Enabled = true;
	Form1->SpeedButton6->Enabled = true;
	Form1->SpeedButton7->Enabled = true;
	Form1->SpeedButton8->Enabled = true;
	Form1->SpeedButton9->Enabled = true;
	winner = 0;
}
//---------------------------------------------------------------------------

