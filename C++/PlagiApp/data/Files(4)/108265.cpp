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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
n=StrToInt(LabeledEdit1->Text);
m=StrToInt(LabeledEdit2->Text);
 for (int i=0; i<m; i++)
  for (int j=0; j<n; j++)
StringGrid1->Cells[i][j]=rand()%50;
Button2->Enabled=true;
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
		 Button1->Enabled=true;
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::LabeledEdit2KeyPress(TObject *Sender, System::WideChar &Key)

{
 if (Key==13)
	{
		  m=StrToInt(LabeledEdit2->Text);
		  StringGrid1->ColCount=m;
		  Button1->Enabled=True;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
int s=0;
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
   if (j==i)
{
s+=StrToInt(StringGrid1->Cells[j][i]);
}
Label1->Caption=IntToStr(s);

}
//---------------------------------------------------------------------------
