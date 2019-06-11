//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <algorithm>
#include <cmath>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int pr[9];
int mas[3][3];
int k=0,C0st,C0r,i,j;
Graphics::TBitmap  *ch1=new Graphics::TBitmap(), *ch2=new Graphics::TBitmap(), *ch3=new Graphics::TBitmap(), *ch4=new Graphics::TBitmap(), *ch5=new Graphics::TBitmap(), *ch6=new Graphics::TBitmap(), *ch7=new Graphics::TBitmap(), *ch8=new Graphics::TBitmap();
TRect rec;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
ch1 -> LoadFromFile ("1.bmp");
   ch2 -> LoadFromFile ("2.bmp");
   ch3 -> LoadFromFile ("3.bmp");
   ch4 -> LoadFromFile ("4.bmp");
   ch5 -> LoadFromFile ("5.bmp");
   ch6 -> LoadFromFile ("6.bmp");
   ch7 -> LoadFromFile ("7.bmp");
   ch8 -> LoadFromFile ("8.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ÇàïîëíèòüClick(TObject *Sender)
{

	 int w, h;
	srand(time(NULL));
	w = DrawGrid1 -> DefaultColWidth;
	h = DrawGrid1 -> DefaultRowHeight;
	rec = Bounds(0,0,w,h);
	for (i = 0; i <9; i++)
	{
	   pr[i]=i;
	}
	random_shuffle (pr,pr +8);
	for (int i = 0; i < 3; i++)
	{
	   for (int j = 0; j < 3; j++)
	   {
		   mas[i][j]=pr[k];
		   k++;
	   }
	}
	for (int i = 0; i < 3; i++)
	{
	   for (int j = 0; j < 3; j++)
	   {
		  if (mas[i][j]==0)
			C0st=i;
			C0r=j;
	   }
	}
   DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DrawGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
        switch(mas[ACol][ARow])
		{
		   case 0:
		   {
		   DrawGrid1->Canvas->FillRect(DrawGrid1->CellRect(ACol,ARow));
		   break;
		   }
		   case 1:
		   {
		   DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),ch1->Canvas,rec);
			break;
		   }
		   case 2:
		   {
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),ch2->Canvas,rec);
			break;
		   }
		   case 3:
		   {
		   DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),ch3->Canvas,rec);
			break;
		   }
		   case 4:
			{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),ch4->Canvas,rec);
			break;
			}
		   case 5:
			{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),ch5->Canvas,rec);
			break;
			}
		   case 6:
			{
		   DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),ch6->Canvas,rec);
			break;
			}
		   case 7:
			{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),ch7->Canvas,rec);
			break;
			}
		   case 8:
			{
		   DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),ch8->Canvas,rec);
			break;
			}
	   }

   if((mas[0][0]==1) && (mas[1][0]==2) && (mas[2][0]==3) &&
		(mas[0][1]==4) && (mas[1][1]==5) && (mas[2][1]==6) &&
		(mas[0][2]==7) && (mas[1][2]==8) && (mas[2][2]==0))
		{
		ShowMessage("WIN!!");
		DrawGrid1->Canvas->FillRect(DrawGrid1->CellRect(2,2));
		for (int i = 0; i < 3; i++)
		  {
			for (int j= 0; j < 3; j++)
			{
				mas[i][j]=0;
			}
			}
		  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DrawGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)

{
   int opts[4][2];
	opts[0][0] = ACol;
	opts[0][1] = ARow-1;
	opts[1][0] = ACol+1;
	opts[1][1] = ARow;
	opts[2][0] = ACol;
	opts[2][1] = ARow+1;
	opts[3][0] = ACol-1;
	opts[3][1] = ARow;


	for (int i = 0; i < 4; i++) {

		if((opts[i][0]>=0)&&(opts[i][1]>=0)&&(opts[i][0]<3)&&(opts[i][1]<3))
			{
			  int col = opts[i][0];
			  int row = opts[i][1];

			  if (mas[col][row]==0)
			  {
				mas[col][row] = mas[ACol][ARow];
				mas[ACol][ARow] = 0;
				break;
			  }
			}
	}
	DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------
