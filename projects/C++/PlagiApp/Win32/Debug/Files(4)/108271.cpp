//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
int m,n;
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
		n=StrToInt(LabeledEdit1->Text);
		m=StrToInt(LabeledEdit2->Text);
		for (int i=0; i<m; i++)
			for (int j=0; j<n; j++)
			  StringGrid1->Cells[i][j]=rand()%20;
		BitBtn2 ->Enabled=true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	 n=StrToInt(LabeledEdit1->Text);
	 m=StrToInt(LabeledEdit2->Text);
	 StringGrid1->ColCount=m;
	 StringGrid1->RowCount=n;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LabeledEdit1KeyPress(TObject *Sender, System::WideChar &Key)

{
	if (Key==13)
	{
		 n=StrToInt(LabeledEdit1->Text);
		 StringGrid1->RowCount=n;
		 BitBtn1->Enabled=true;
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::LabeledEdit2KeyPress(TObject *Sender, System::WideChar &Key)

{
	  if (Key==13)
	{
		  m=StrToInt(LabeledEdit2->Text);
		  StringGrid1->ColCount=m;
		  BitBtn1->Enabled=True;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
	int i=0;
	int j=0;
	int s=0;
	for (int i=0; i<m; i++)
	for (int j=0; j<n; j++)
	if (i+j<=m-2) {
		s+=StrToInt(StringGrid1->Cells[i][j]);
	}
	
	LabeledEdit3->Text=IntToStr(s);
}
//---------------------------------------------------------------------------