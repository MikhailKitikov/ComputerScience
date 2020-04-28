//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int n, m, k, l;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	n=StrToInt(LabeledEdit2->Text);
	m=StrToInt(LabeledEdit1->Text);
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			StringGrid1->Cells[i][j]=rand()%20 - 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int s=0;
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			s+=StrToInt(StringGrid1->Cells[i][j]);
	Label2->Caption= "Summ = " + IntToStr(s);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	n=StrToInt(LabeledEdit2->Text);
	StringGrid1->RowCount=n;
	m=StrToInt(LabeledEdit1->Text);
	StringGrid1->ColCount=m;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	n=StrToInt(LabeledEdit2->Text);
	m=StrToInt(LabeledEdit1->Text);
	StringGrid1->ColCount=m;
	StringGrid1->RowCount=n;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int i, j;
	int k = StrToInt(LabeledEdit3->Text);
	int l = StrToInt(LabeledEdit4->Text);
	int o = 0, a = StrToInt(StringGrid1->Cells[k-1][l-1]);
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
			if (StrToInt(StringGrid1->Cells[i][j]) != a)
			{
				o++;
				break;
			}
		if (o == 1)
			break;
	}
	if (i == m && j == n)
		Label3->Caption = "Таких нет";
	else
		Label3->Caption = "Такие есть, например А[" + IntToStr(i+1) + "][" + IntToStr(j+1) + "]";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int s[100];
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			s[i] += StrToInt(StringGrid1->Cells[i][j]);

	int Max = s[0];
	for (int i = 1; i < m; i++)
		if (s[i] > Max)
			Max = s[i];
	for (int i = 0; i < m; i++)
		if (s[i] == Max)
			Label4->Caption = IntToStr(i+1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	StringGrid2->ColCount = m;
	int o = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			if (StringGrid1->Cells[i][j] > 0)
				o++;
		StringGrid2->Cells[i][0] = IntToStr(o);
		o = 0;
	}

}
//---------------------------------------------------------------------------

