//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
char zn;
int i,j,mas[3][3];
Graphics::TBitmap  *kr=new Graphics::TBitmap(), *nl=new Graphics::TBitmap();
TRect rec;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	 zn='X';
	 kr->LoadFromFile("k.bmp");
	 nl->LoadFromFile("n.bmp");
	 Image1->Picture->LoadFromFile("янелюблюпустыеобласти.bmp");
	 Image1->Stretch=True;
	 int w=kr->Width;
	 int h=kr->Height;
	 rec=Bounds(0,0,w,h);
	 for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
		  mas[i][j]=0;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::DrawGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)

{
	  if (mas[ACol][ARow]==0)
	  {
	  if (zn=='X')
	  {
		mas[ACol][ARow]=1;
		zn='O';
	  }
	  else
	  {
		mas[ACol][ARow]=2;
		zn='X';
	  }
	  }
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
		case 2:
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),nl->Canvas,rec);
			break;
		}
	 }


if((mas[i][0]==mas[i+1][0])&&(mas[i+1][0]==mas[i+2][0]))
	 {
		 if(mas[i][0]==1)
		 {
			 Label1->Caption="Победили крестики";
		 }
		 if(mas[i][0]==2)
		 {
			 Label1->Caption="Победили нолики";
		 }
	 }
	 if((mas[i][1]==mas[i+1][1])&&(mas[i+1][1]==mas[i+2][1]))
	 {
		 if(mas[i][1]==1)
		 {
			 Label1->Caption="Победили крестики";

		 }
		 if(mas[i][1]==2)
		 {
			 Label1->Caption="Победили нолики";

		 }
	 }
	 if((mas[i][2]==mas[i+1][2])&&(mas[i+1][2]==mas[i+2][2]))
	 {
		 if(mas[i][2]==1)
		 {
			 Label1->Caption="Победили крестики";

		 }
		 if(mas[i][2]==2)
		 {
			 Label1->Caption="Победили нолики";

		 }
	 }
	 if((mas[0][j]==mas[0][j+1])&&(mas[0][j+1]==mas[0][j+2]))
	 {
		 if(mas[0][j]==1)
		 {
			 Label1->Caption="Победили крестики";
		 }
		 if(mas[0][j]==2)
		 {
			 Label1->Caption="Победили нолики";

		 }
	 }
	 if((mas[1][j]==mas[1][j+1])&&(mas[1][j+1]==mas[1][j+2]))
	 {
		 if(mas[1][j]==1)
		 {
			 Label1->Caption="Победили крестики";

		 }
		 if(mas[1][j]==2)
		 {
			 Label1->Caption="Победили нолики";

		 }
	 }
	 if((mas[2][j]==mas[2][j+1])&&(mas[2][j+1]==mas[2][j+2]))
	 {
		 if(mas[2][j]==1)
		 {
			 Label1->Caption="Победили крестики";

		 }
		 if(mas[2][j]==2)
		 {
			Label1->Caption="Победили нолики";

		 }
	 }
	 if((mas[i][j]==mas[i+1][j+1])&&(mas[i+1][j+1]==mas[i+2][j+2]))
	 {
		 if(mas[i][j]==1)
		 {
			 Label1->Caption="Победили крестики";

		 }
		 if(mas[i][j]==2)
		 {
			 Label1->Caption="Победили нолики";

		 }
	 }
	 if((mas[0][2]==mas[1][1])&&(mas[1][1]==mas[2][0]))
	 {
		 if(mas[1][1]==1)
		 {
			 Label1->Caption="Победили крестики";

		 }
		 if(mas[1][1]==2)
		 {
			 Label1->Caption="Победили нолики";
		 }
	 }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{

	Label1->Caption="";
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			mas[i][j]=0;
	DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N2Click(TObject *Sender)
{
	Label1->Caption="";
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			mas[i][j]=0;
	DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N3Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

