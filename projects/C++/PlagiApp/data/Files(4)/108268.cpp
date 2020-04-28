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
int m,n,i,j,t,x1=0,J,x2=0,a;
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
		n=StrToInt(LabeledEdit1->Text);
		m=StrToInt(LabeledEdit2->Text);
		for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
		StringGrid1->Cells[i][j]=rand()%20;
		Button2 ->Enabled=true;
		Button3 ->Enabled=true;
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
   if(m==n)
   {
int s=0;
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
		{
		if(j==i)
		{
		  s+=StrToInt(StringGrid1->Cells[i][j]);
		}
		if(i==n-1-j)
		 s+=StrToInt(StringGrid1->Cells[i][j]);
		}
		if(n%2==1)
		{
			s=s-StrToInt(StringGrid1->Cells[n/2][m/2]);
		}
	Label1->Caption=IntToStr(s);
	}
	else
	{
        ShowMessage("Неправильный массив");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	 for(i=0;i<m;i++)
	{
	   for(j=0;j<n;j++)
	   {
		 t=StrToInt(StringGrid1->Cells[i][j]);
		 if((t%7==0) && (t%4!=0))
		 {
		 Label2->Caption=Label2->Caption+"Столбец:"+IntToStr(i)+"Строка:"+IntToStr(j)+" ";
		 j=n;
		 i=m;
		 Button3->Enabled=false;
		 }
	   }
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	   Label3->Caption="";
	   for(j=0;i<m-1;j++)
	   {
	   for(i=0;i<n-1;i++)
	   {
		  t=StrToInt(StringGrid1->Cells[i][j]);
		 x1=x1+t;
	   }
		 for(J=j+1;J<m;J++)
		  {
			  for(i=0;i<n-1;i++)
				 {
				   t=StrToInt(StringGrid1->Cells[i][J]);
				   x2=x2+t;
				}
		  }
		if(x1==x2)
		{
		 //J=J-1;
		 Label3->Caption=Label3->Caption+"Строка:"+IntToStr(j)+" "+" и строка:"+IntToStr(J);
		}
	   }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	   a=0;
	  J=StrToInt(LabeledEdit3->Text);
	  StringGrid2->ColCount=StringGrid1->RowCount;
	  StringGrid2->RowCount=1;
	  for(i=0;i<m;i++)
	  a=a+StrToInt(StringGrid1->Cells[i][J]);
	  a=a/m;
	  for (i=0; i<m; i++)
	  {
		 if(i==J)
		 StringGrid2->Cells[i][0]=a;
		 else
		 StringGrid2->Cells[i][0]=rand()%20;
	  }
}
//---------------------------------------------------------------------------

