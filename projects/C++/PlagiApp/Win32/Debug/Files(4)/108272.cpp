//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <vector>
#include <algorithm>
#include<ctime>

#include "Unit1.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool kr(int k)
{
	return (k%4==0);
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  srand(time(NULL));
  for (int j=0; j<StringGrid1->RowCount; j++)
		for (int i=0; i<StringGrid1->ColCount; i++)
			StringGrid1->Cells[i][j]=rand()%(StrToInt(LabeledEdit3->Text)+StrToInt(LabeledEdit4->Text)+1)+StrToInt(LabeledEdit3->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  srand(time(NULL));
  for (int j=0; j<StringGrid1->RowCount; j++)
		for (int i=0; i<StringGrid1->ColCount; i++)
			StringGrid1->Cells[i][j]=rand()%(StrToInt(LabeledEdit3->Text)+StrToInt(LabeledEdit4->Text)+1)+StrToInt(LabeledEdit3->Text);;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LabeledEdit1KeyPress(TObject *Sender, System::WideChar &Key)

{
   if (Key==13)
  {
	  int k=StringGrid1->RowCount;
	  StringGrid1->RowCount=StrToInt(LabeledEdit1->Text);
	  if (StrToInt(LabeledEdit1->Text)>k)
	  {
		  srand(time(NULL));
		  for (int j=k; j<StringGrid1->ColCount; j++)
				for (int i=0; i<StringGrid1->RowCount; i++)
					StringGrid1->Cells[i][j]=rand()%(StrToInt(LabeledEdit3->Text)+StrToInt(LabeledEdit4->Text)+1)+StrToInt(LabeledEdit3->Text);;
	  }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LabeledEdit2KeyPress(TObject *Sender, System::WideChar &Key)

{
  if (Key==13)
  {
	  int k=StringGrid1->ColCount;
	  StringGrid1->ColCount=StrToInt(LabeledEdit2->Text);
	  if (StrToInt(LabeledEdit2->Text)>k)
	  {
		  srand(time(NULL));
		  for (int j=0; j<StringGrid1->ColCount; j++)
				for (int i=k; i<StringGrid1->RowCount; i++)
					StringGrid1->Cells[i][j]=rand()%(StrToInt(LabeledEdit3->Text)+StrToInt(LabeledEdit4->Text)+1)+StrToInt(LabeledEdit3->Text);;
	  }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   int s;
   for (int j=0; j<StringGrid1->RowCount; j++)
		for (int i=0; i<StringGrid1->ColCount; i++)
			if (StrToInt(StringGrid1->Cells[i][j])>i+1)
			{
			   s+=StrToInt(StringGrid1->Cells[i][j]);
			}
   Label1->Caption=IntToStr(s);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  Label1->Caption="Нет";
  vector< vector<int> > A;
  for (int j=0; j<StringGrid1->RowCount; j++)
  {
		vector <int> t;
		for (int i=0; i<StringGrid1->ColCount; i++)
			 t.push_back(StrToInt(StringGrid1->Cells[i][j]));
		A.push_back(t);
  }
  int k,Sr=0,Sb=0;
  for (int j=0; j<StringGrid1->RowCount; j++)
  {
	  k=find_if(A[j].begin(), A[j].end(), kr) - A[j].begin();
	  if (k < A[j].size())
	  {
		  Sr=j+1;
		  Sb=k+1;
		  break;
	  }
  }
  if (Sb)
	  Label1->Caption="Да, "+IntToStr(Sr)+", "+IntToStr(Sb);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  vector< vector<int> > A;
  for (int i=0; i<StringGrid1->ColCount; i++)
  {
		vector <int> t;
		for  (int j=0; j<StringGrid1->RowCount; j++)
			 t.push_back(StrToInt(StringGrid1->Cells[i][j]));
		A.push_back(t);
  }
  int M=11, m;
  for (int i=0; i<StringGrid1->ColCount; i++)
  {
	  m=min_element(A[i].begin(), A[i].end()) - A[i].begin();
	  if (A[i][m]<M)
		  M=A[i][m];
  }
  int k;
  Label1->Caption="";
  for (int i=0; i<StringGrid1->ColCount; i++)
  {
	  k=find(A[i].begin(), A[i].end(), M) - A[i].begin();
	  if (k < A[i].size())
			Label1->Caption=Label1->Caption+IntToStr(i+1)+"  ";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  vector< vector<int> > A;
  for (int j=0; j<StringGrid1->RowCount; j++)
  {
		vector <int> t;
		for (int i=0; i<StringGrid1->ColCount; i++)
			 t.push_back(StrToInt(StringGrid1->Cells[i][j]));
		A.push_back(t);
  }
  Label1->Caption="";
  int k,m;
  for (int j=0; j<StringGrid1->RowCount; j++)
  {
	   k=min_element(A[j].begin(), A[j].end()) - A[j].begin();
	   m=fabs(A[j][k]);
	   Label1->Caption=Label1->Caption+IntToStr(m)+"  ";
  }
}
//---------------------------------------------------------------------------

