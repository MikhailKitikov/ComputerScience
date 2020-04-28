//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
Graphics::TBitmap   *k1=new Graphics::TBitmap(),
*k2=new Graphics::TBitmap(), *k3=new Graphics::TBitmap(), *k4=new Graphics::TBitmap(),
*k5=new Graphics::TBitmap(), *k6=new Graphics::TBitmap(), *k7=new Graphics::TBitmap(),
*k8=new Graphics::TBitmap(), *k9=new Graphics::TBitmap(), *k10=new Graphics::TBitmap(),
*k11=new Graphics::TBitmap(), *k12=new Graphics::TBitmap(), *k13=new Graphics::TBitmap(),
*k14=new Graphics::TBitmap(), *k15=new Graphics::TBitmap();
TRect rec;
int ch = 4;
int mas[4][4];
int coxr[16], cox = 0;
vector<int> ran(16);
//---------------------------------------------------------------------------
void __fastcall TForm1::proverca()
{
	bool pr = true;
	int kk = 1;
	for (int i = 0; i < ch; i++)
		for (int j = 0; j < ch; j++)
		{
			if (mas[j][i] != kk && mas[j][i] != 0)
			{
				pr = false;
				break;
			}
			kk++;
		}
	if (pr == true)
	   ShowMessage("Вы Победили!");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::nova9_igra()
{
	if (ch == 3)
	{
		DrawGrid1->ColCount = 3;
		DrawGrid1->RowCount = 3;
	}
	else
	{
		DrawGrid1->ColCount = 4;
		DrawGrid1->RowCount = 4;
	}
	rec=Bounds(0,0,50,50);
	for (int i = 0; i < ch*ch; i ++)
		ran[i] = i;
	srand ( time(NULL) );
	random_shuffle(ran.begin(),ran.begin() + ch*ch);
	int kk = 0;
	for (int i = 0; i < ch; i ++)
		for (int j = 0; j < ch; j++)
		{
			mas[i][j] = ran[kk];
			coxr[kk] = ran[kk];
			kk++;

		}
	cox = 1;
	DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	k1->LoadFromFile("1.bmp");
	k2->LoadFromFile("2.bmp");
	k3->LoadFromFile("3.bmp");
	k4->LoadFromFile("4.bmp");
	k5->LoadFromFile("5.bmp");
	k6->LoadFromFile("6.bmp");
	k7->LoadFromFile("7.bmp");
	k8->LoadFromFile("8.bmp");
	k9->LoadFromFile("9.bmp");
	k10->LoadFromFile("10.bmp");
	k11->LoadFromFile("11.bmp");
	k12->LoadFromFile("12.bmp");
	k13->LoadFromFile("13.bmp");
	k14->LoadFromFile("14.bmp");
	k15->LoadFromFile("15.bmp");

	nova9_igra();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
	switch (mas[ACol][ARow])
	{
		case 1:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k1->Canvas,rec);
			break;
		}
		case 2:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k2->Canvas,rec);
			break;
		}
		case 3:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k3->Canvas,rec);
			break;
		}
		case 4:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k4->Canvas,rec);
			break;
		}
		case 5:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k5->Canvas,rec);
			break;
		}
		case 6:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k6->Canvas,rec);
			break;
		}
		case 7:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k7->Canvas,rec);
			break;
		}
		case 8:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k8->Canvas,rec);
			break;
		}
		case 9:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k9->Canvas,rec);
			break;
		}
		case 10:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k10->Canvas,rec);
			break;
		}
		case 11:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k11->Canvas,rec);
			break;
		}
		case 12:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k12->Canvas,rec);
			break;
		}
		case 13:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k13->Canvas,rec);
			break;
		}
		case 14:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k14->Canvas,rec);
			break;
		}
		case 15:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k15->Canvas,rec);
			break;
		}
		default:
		{
			break;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	nova9_igra();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)
{
	if (ACol - 1 >= 0)
		if (mas[ACol-1][ARow] == 0)
			swap(mas[ACol][ARow],mas[ACol-1][ARow]);
	if (ARow - 1 >= 0)
		if (mas[ACol][ARow-1] == 0)
			swap(mas[ACol][ARow],mas[ACol][ARow-1]);
	if (ACol + 1 <= 3)
		if (mas[ACol+1][ARow] == 0)
			swap(mas[ACol][ARow],mas[ACol+1][ARow]);
	if (ARow + 1 <= 3)
		if (mas[ACol][ARow+1] == 0)
			swap(mas[ACol][ARow],mas[ACol][ARow+1]);
	DrawGrid1->Refresh();
	if (mas[ch-1][ch-1] == 0)
		proverca();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N331Click(TObject *Sender)
{
	ch = 3;
	nova9_igra();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N441Click(TObject *Sender)
{
	ch = 4;
	nova9_igra();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
	int kk = 0;
	for (int i = 0; i < ch; i ++)
		for (int j = 0; j < ch; j++)
		{
			mas[i][j] = coxr[kk];
			kk++;
		}
	DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------

