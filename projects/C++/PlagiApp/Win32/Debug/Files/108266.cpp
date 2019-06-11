//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#include <iostream>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
char zn;
int x=0, y=0;
int m[3][3];
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
		  m[i][j]=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
switch (m[ACol][ARow])
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
	 if((m[0][0]==m[1][0])&&(m[1][0]==m[2][0]))
	 {
		 if (m[0][0]==1)
		 {
			 Label1->Caption = "Победили крестики";
		 }
		 if (m[0][0]==2)
		 {
			 Label1->Caption = "Победили нолики";
		 }
	 }
	 if((m[0][1]==m[1][1])&&(m[1][1]==m[2][1]))
	 {
		 if (m[0][1]==1)
		 {
			 Label1->Caption = "Победили крестики";
		 }
		 if (m[0][1]==2)
		 {
			 Label1->Caption = "Победили нолики";
		 }
	 }
	 if((m[0][2]==m[1][2])&&(m[1][2]==m[2][2]))
	 {
		 if (m[0][2]==1)
		 {
			 Label1->Caption = "Победили крестики";
		 }
		 if (m[0][2]==2)
		 {
			 Label1->Caption = "Победили нолики";
		 }
	 }
	 if((m[0][0]==m[0][1])&&(m[0][1]==m[0][2]))
	 {
		 if (m[0][0]==1)
		 {
			 Label1->Caption = "Победили крестики";
		 }
		 if (m[0][0]==2)
		 {
			 Label1->Caption = "Победили нолики";
		 }
	 }
	 if((m[1][0]==m[1][1])&&(m[1][1]==m[1][2]))
	 {
		 if (m[1][0]==1)
		 {
			 Label1->Caption = "Победили крестики";
		 }
		 if (m[1][0]==2)
		 {
			 Label1->Caption = "Победили нолики";
		 }
	 }
	 if((m[2][0]==m[2][1])&&(m[2][1]==m[2][2]))
	 {
		 if (m[2][0]==1)
		 {
			 Label1->Caption = "Победили крестики";
		 }
		 if (m[2][0]==2)
		 {
			 Label1->Caption = "Победили нолики";
		 }
	 }
	 if((m[0][0]==m[1][1])&&(m[1][1]==m[2][2]))
	 {
		 if (m[0][0]==1)
		 {
			 Label1->Caption = "Победили крестики";
		 }
		 if (m[0][0]==2)
		 {
			 Label1->Caption = "Победили нолики";
		 }
	 }
	 if((m[0][2]==m[1][1])&&(m[1][1]==m[2][0]))
	 {
		 if (m[1][1]==1)
		 {

			 Label1->Caption = "Победили крестики";
		 }
		 if (m[1][1]==2)
		 {
			 Label1->Caption = "Победили нолики";
		 }
	 }

		if (Label1->Caption == "Победили крестики" || Label1->Caption == "Победили нолики") {
		for (int  i=0; i < 3; i++)
			for (int j=0; j<3; j++) {
			if (m[i][j]==0) {
			m[i][j]=3;}
		}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DrawGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)

{
if (m[ACol][ARow]==0) {
	  if (zn=='X')
	  {
		m[ACol][ARow]=1;
		zn='O';
	  }
	  else
	  {
		m[ACol][ARow]=2;
		zn='X';
	  }

	  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
Label1->Caption = "";
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			m[i][j]=0;
	DrawGrid1->Refresh();
	zn='X';
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
/*ifstream kek;
SaveDialog1->Execute();
kek=SaveDialog1->FileName;
ofstream fout(kek.c_str());
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
fout<<m[i][j]<<" ";}*/
}
//---------------------------------------------------------------------------
