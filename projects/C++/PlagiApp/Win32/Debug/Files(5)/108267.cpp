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
Graphics::TBitmap  *n1=new Graphics::TBitmap(), *n2=new Graphics::TBitmap(), *n3=new Graphics::TBitmap(), *n4=new Graphics::TBitmap(), *n5=new Graphics::TBitmap(), *n6=new Graphics::TBitmap(), *n7=new Graphics::TBitmap(), *n8=new Graphics::TBitmap();
TRect rec;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
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
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   n1 -> LoadFromFile ("1.bmp");
   n2 -> LoadFromFile ("2.bmp");
   n3 -> LoadFromFile ("3.bmp");
   n4 -> LoadFromFile ("4.bmp");
   n5 -> LoadFromFile ("5.bmp");
   n6 -> LoadFromFile ("6.bmp");
   n7 -> LoadFromFile ("7.bmp");
   n8 -> LoadFromFile ("8.bmp");
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
		   DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),n1->Canvas,rec);
			break;
		   }
		   case 2:
		   {
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),n2->Canvas,rec);
			break;
		   }
		   case 3:
		   {
		   DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),n3->Canvas,rec);
			break;
		   }
		   case 4:
			{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),n4->Canvas,rec);
			break;
			}
		   case 5:
			{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),n5->Canvas,rec);
			break;
			}
		   case 6:
			{
		   DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),n6->Canvas,rec);
			break;
			}
		   case 7:
			{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),n7->Canvas,rec);
			break;
			}
		   case 8:
			{
		   DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),n8->Canvas,rec);
			break;
			}
	   }

   if((mas[0][0]==1) && (mas[1][0]==2) && (mas[2][0]==3) &&
		(mas[0][1]==4) && (mas[1][1]==5) && (mas[2][1]==6) &&
		(mas[0][2]==7) && (mas[1][2]==8) && (mas[2][2]==0))
		{
		ShowMessage("Победа!!");
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

