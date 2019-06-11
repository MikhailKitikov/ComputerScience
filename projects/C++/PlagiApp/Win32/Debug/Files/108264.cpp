//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <fstream>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm1 *Form1;
char zn;
int mas[10][10],n;
Graphics::TBitmap  *kr=new Graphics::TBitmap(), *nl=new Graphics::TBitmap();


TRect rec;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{     DrawGrid1->Enabled=false;


       //доделать боковую проверку

}
int po=0;
//---------------------------------------------------------------------------
void __fastcall TForm1::DrawGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)

{
	  if (zn=='X'&&mas[ACol][ARow]==0)
	  {
		mas[ACol][ARow]=1;
		zn='O';
	  }
	  if (zn=='O'&&mas[ACol][ARow]==0)
	  {
		mas[ACol][ARow]=10;
		zn='X';
	  }
	  int s=0;
	  for(int j=0;j<n;j++)
	 {for(int i=0;i<n;i++)
	  { s+=mas[j][i];}
	  if(s==n)
	  {po=1;
	  }if(s==n*10)
	  { po=2;
	  }
	  s=0;

}
	  for(int j=0;j<n;j++)
	 {for(int i=0;i<n;i++)
	  { s+=mas[i][j];}
	  if(s==n)
	  { po=1;
	  }if(s==n*10)
	  { po=2;
	  }
	  s=0;

   }
   for(int i=0;i<n;i++)
   {
	  s+=mas[i][i];
   }
   if(s==n)
	  { po=1;
	  }if(s==n*10)
	  { po=2;
	  }
	  s=0;
	  for(int i=0;i<n;i++)
   {
	  s+=mas[n-1-i][i];
   }
   if(s==n)
	  { po=1;
	  }if(s==n*10)
	  { po=2;
	  }
	  s=0;
 /*  if(mas[0][0]+mas[1][1]+mas[2][2]==n||mas[2][0]+mas[1][1]+mas[0][2]==n)
   {
	 po=1;

   }
   if(mas[0][0]+mas[1][1]+mas[2][2]==n*10||mas[2][0]+mas[1][1]+mas[0][2]==n*10)
   {
	   po=2;

   } */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DrawGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State)
{
	 switch (mas[ACol][ARow])
	 {
		case 1:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),kr->Canvas,rec);
			break;
		}
		case 10:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),nl->Canvas,rec);
			break;
		}
	 }
	 if(po==1)
	 {
		 ShowMessage("krestik win");
		 DrawGrid1->Enabled=false; po=0;
	 }
	  if(po==2)
	 {
		 ShowMessage("nol win");DrawGrid1->Enabled=false; po=0;
	 }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{     DrawGrid1->Enabled=true;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			mas[i][j]=0;
	DrawGrid1->Refresh();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{     DrawGrid1->Enabled=true;
     zn='X';

	 kr->LoadFromFile("k.bmp");
	 nl->LoadFromFile("n.bmp");
	 int w=kr->Width;
	 int h=kr->Height;
	 rec=Bounds(0,0,w,h);
	 n=StrToInt(Edit1->Text);
	 DrawGrid1->Height=n*250/3;
	 DrawGrid1->Width=n*250/3;
	 DrawGrid1->ColCount=n;
	 DrawGrid1->RowCount=n;
	 for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
		  mas[i][j]=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{
	ofstream out("out.txt");
	  for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			out<< mas[i][j]<<" ";
			out.close() ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{         ifstream in("out.txt");
        for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			in>> mas[i][j];
				in.close() ;
        	DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------

