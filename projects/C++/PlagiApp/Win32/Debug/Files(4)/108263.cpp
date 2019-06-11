//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
int m,n,x;
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
	 StringGrid2->ColCount=m;
	 StringGrid1->RowCount=n;
	  StringGrid2->RowCount=1;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::LabeledEdit1KeyPress(TObject *Sender, System::WideChar &Key)

{
	if (Key==13)
	{
		 n=StrToInt(LabeledEdit1->Text);
		 StringGrid1->RowCount=n;
		 BitBtn1->Enabled=true;
		 x=StrToInt(LabeledEdit1->Text);
		  StringGrid2->RowCount=1;
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
		   StringGrid2->ColCount=m;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
	int s=0;
	x=StrToInt(LabeledEdit3->Text);
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
		 if((i-j==x)||((i-j)==-x))
		 { s+=StrToInt(StringGrid1->Cells[i][j]);  }
	Label1->Caption=IntToStr(s);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{     Label5->Caption="нет";
	  for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
		 if(StrToInt(StringGrid1->Cells[i][j])%7!=0)
		 { break;  }  Label5->Caption="да";
}
//---------------------------------------------------------------------------
 int y=0,a,b;
void __fastcall TForm1::Button2Click(TObject *Sender)
{     for (int i=0; i<n; i++)
	   {	for (int j=0; j<m; j++)
		 {
			 for(int k=0;k<m;k++)
			 {    a=StrToInt(StringGrid1->Cells[j][i]);
				  b=StrToInt(StringGrid1->Cells[k][i]);
				if(a==b&&k!=j)
				  {
				   Label7->Caption=Label7->Caption+IntToStr(i)+",";
				   goto labe1;
				   }
			 }

		 }
		   labe1:
		   continue;
		 }
}
//---------------------------------------------------------------------------






void __fastcall TForm1::Button3Click(TObject *Sender)
{ int maxi=0;int a;
for (int i=0; i<n; i++)
	   {  	for (int j=0; j<m; j++)
		 {
		  a=StrToInt(StringGrid1->Cells[j][i]);
			if(a>maxi)
		maxi=a;;

		 }
		  StringGrid2->Cells[i][0]=IntToStr(maxi);
		  maxi=0;
		 }
}
//---------------------------------------------------------------------------

