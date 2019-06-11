//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
char zn;
int mas[3][3],i1=0,j1=0,d=0,str=0,stolb=0;
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

{   if(mas[ACol][ARow]==0){
	  if (zn=='X')
	  {
		mas[ACol][ARow]=1;
		zn='O';
	  }
	  else
	  {
		mas[ACol][ARow]=2;
		zn='X';
	  }  }
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
	 for (d=0; d<3; d++) {
	 if ((mas[i1][d]==mas[i1+1][d])&&(mas[i1+2][d]==mas[i1+1][d])&&(mas[i1][d]==1)) {
	  Label1->Caption="Крестоносцы победили";
	  for (stolb=0; stolb < 3; stolb++) {
	  for (str = 0; str < 3; str++) {
	  if(mas[stolb][str]==0)mas[stolb][str]=3 ;
	  }}}}
	 for (d=0; d<3; d++) {
	 if ((mas[i1][d]==mas[i1+1][d])&&(mas[i1+2][d]==mas[i1+1][d])&&(mas[i1][d]==2)) {
	  Label1->Caption="Кругоносцы победили";
	  for (stolb=0; stolb < 3; stolb++) {
	  for (str = 0; str < 3; str++) {
	  if(mas[stolb][str]==0)mas[stolb][str]=3 ;
	  }}}}
	 for (d=0; d<3; d++) {
	 if ((mas[d][i1]==mas[d][i1+1])&&(mas[d][i1+1]==mas[d][i1+2])&&(mas[d][i1]==1)) {
	  Label1->Caption="Крестоносцы победили";
	  for (stolb=0; stolb < 3; stolb++) {
	  for (str = 0; str < 3; str++) {
	  if(mas[stolb][str]==0)mas[stolb][str]=3 ;
	  }}}}
	 for (d=0; d<3; d++) {
	 if ((mas[d][i1]==mas[d][i1+1])&&(mas[d][i1+1]==mas[d][i1+2])&&(mas[d][i1]==2)) {
	  Label1->Caption="Кругоносцы победили";
	  for (stolb=0; stolb < 3; stolb++) {
	  for (str = 0; str < 3; str++) {
	  if(mas[stolb][str]==0)mas[stolb][str]=3 ;
	  }}}}
	 for (d=0; d<3; d++) {
	 if ((mas[d][i1]==mas[d+1][i1+1])&&(mas[d+1][i1+1]==mas[d+2][i1+2])&&(mas[d][i1]==1)) {
	  Label1->Caption="Крестоносцы победили";
	  for (stolb=0; stolb < 3; stolb++) {
	  for (str = 0; str < 3; str++) {
	  if(mas[stolb][str]==0)mas[stolb][str]=3 ;
	  }}}}
	 for (d=0; d<3; d++) {
	 if ((mas[d][i1]==mas[d+1][i1+1])&&(mas[d+1][i1+1]==mas[d+2][i1+2])&&(mas[d][i1]==2)) {
	  Label1->Caption="Кругоносцы победили";
	  for (stolb=0; stolb < 3; stolb++) {
	  for (str = 0; str < 3; str++) {
	  if(mas[stolb][str]==0)mas[stolb][str]=3 ;
	  }}}}
	 for (d=0; d<3; d++) {
	 if ((mas[d][i1+2]==mas[d+1][i1+1])&&(mas[d+1][i1+1]==mas[d+2][i1])&&(mas[d][i1+2]==1)) {
	  Label1->Caption="Крестоносцы победили";
	  for (stolb=0; stolb < 3; stolb++) {
	  for (str = 0; str < 3; str++) {
	  if(mas[stolb][str]==0)mas[stolb][str]=3 ;
	  }}}}
	 for (d=0; d<3; d++) {
	 if ((mas[d][i1+2]==mas[d+1][i1+1])&&(mas[d+1][i1+1]==mas[d+2][i1])&&(mas[d][i1+2]==2)) {
	  Label1->Caption="Кругоносцы победили";
	  for (stolb=0; stolb < 3; stolb++) {
	  for (str = 0; str < 3; str++) {
	  if(mas[stolb][str]==0)mas[stolb][str]=3 ;
	  }}}}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			mas[i][j]=0;
	DrawGrid1->Refresh();
	Label1->Caption="";
    zn='X';
}
//---------------------------------------------------------------------------
