//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
char zn;
int mas[3][3];
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
	  Label1->Caption=" ";
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
	  else
	  {
		Label1->Caption="Тут уже есть знак!";
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


	 int x=0;
	 int y=0;
	 if ((mas[0][y]==mas[1][y]) && (mas[1][y]==mas[2][y]))
	 {
		if (mas[0][y]==1)
		{
		   Label1->Caption="Победили крестики";
		}
		if (mas[0][y]==2)
		{
		   Label1->Caption="Победили нолики";
		}
	 }


	 if ((mas[0][y+1]==mas[1][y+1]) && (mas[1][y+1]==mas[2][y+1]))
	 {
		if (mas[0][y+1]==1)
		{
		   Label1->Caption="Победили крестики";
		}
		if (mas[0][y+1]==2)
		{
		   Label1->Caption="Победили нолики";
		}
	 }


	  if ((mas[0][y+2]==mas[1][y+2]) && (mas[1][y+2]==mas[2][y+2]))
	 {
		if (mas[0][y+2]==1)
		{
		   Label1->Caption="Победили крестики";
		}
		if (mas[0][y+2]==2)
		{
		   Label1->Caption="Победили нолики";
		}
	 }



	 if ((mas[x][0]==mas[x][1]) && (mas[x][1]==mas[x][2]))
	 {
		if (mas[x][0]==1)
		{
		   Label1->Caption="Победили крестики";
		}
		if (mas[x][0]==2)
		{
		   Label1->Caption="Победили нолики";
		}
	 }



	 if ((mas[x+1][0]==mas[x+1][1]) && (mas[x+1][1]==mas[x+1][2]))
	 {
		if (mas[x+1][0]==1)
		{
		   Label1->Caption="Победили крестики";
		}
		if (mas[x+1][0]==2)
		{
		   Label1->Caption="Победили нолики";
		}
	 }



	  if ((mas[x+2][0]==mas[x+2][1]) && (mas[x+2][1]==mas[x+2][2]))
	 {
		if (mas[x+2][0]==1)
		{
		   Label1->Caption="Победили крестики";
		}
		if (mas[x+2][0]==2)
		{
		   Label1->Caption="Победили нолики";
		}
	 }


	  if ((mas[x][y]==mas[x+1][y+1]) && (mas[x+1][y+1]==mas[x+2][y+2]))
	 {
		if (mas[x][y]==1)
		{
		   Label1->Caption="Победили крестики";
		}
		if (mas[x][y]==2)
		{
		   Label1->Caption="Победили нолики";
		}
	 }


	 if ((mas[x+2][y]==mas[x+1][y+1]) && (mas[x+1][y+1]==mas[x][y+2]))
	 {
		if (mas[x+2][y]==1)
		{
		   Label1->Caption="Победили крестики";
		}
		if (mas[x+2][y]==2)
		{
		   Label1->Caption="Победили нолики";
		}
	 }


	 if (Label1->Caption=="Победили нолики" || Label1->Caption=="Победили крестики")
	 {
		for (int i=0; i<3; i++)
		   for (int j=0; j<3; j++)
		   {
			  if (mas[i][j]==0)
				 mas[i][j]=3;
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
	zn='X';
	DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Restart1Click(TObject *Sender)
{
	Label1->Caption="";
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			mas[i][j]=0;
	zn='X';
	DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Close1Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

