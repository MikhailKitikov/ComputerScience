//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int n,m,s,o=0,i,j,t,x,b=0,I,a=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
		n=StrToInt(LabeledEdit1->Text);
		m=StrToInt(LabeledEdit2->Text);
		for (i=0; i<m; i++)
			for ( j=0; j<n; j++)
			  StringGrid1->Cells[i][j]=rand()%20;
		Button2 ->Enabled=true;
		Label2->Caption="";
		Button3 ->Enabled=true;
		Button4 ->Enabled=true;
		Button5 ->Enabled=true;
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
	o=0;
	s=0;
	for(i=0;i<m-1;i++)
	{	
	   for(j=1+o;j<n;j++)
	   {
	   s+=StrToInt(StringGrid1->Cells[i][j]);
	   }
	   o++;
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
		 if((t%7==3) || (t%7==2) || (t%7==1))
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
	   x=StrToInt(LabeledEdit3->Text);
		for(i=0;i<m;i++)
	   {
		  b=0;
	   for(j=0;j<n;j++)
		 {
		 t=StrToInt(StringGrid1->Cells[i][j]);
		 b=b+t;
		 }
		 if(b<=x)
		 Label3->Caption=Label3->Caption+"Столбец:"+IntToStr(i)+" ";
	   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	  a=0;
	  I=StrToInt(LabeledEdit4->Text);
	  StringGrid2->ColCount=StringGrid1->ColCount;
	  StringGrid2->RowCount=1;
	  for(j=0;j<n;j++)
	  a=a+StrToInt(StringGrid1->Cells[I][j]);
	  a=a/n;
	  for (i=0; i<m; i++)
	  {
		 if(i==I)
		 StringGrid2->Cells[i][0]=a;
		 else
		 StringGrid2->Cells[i][0]=rand()%20;
	  }
}
//---------------------------------------------------------------------------

