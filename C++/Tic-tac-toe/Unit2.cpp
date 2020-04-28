//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit1.cpp"
//---------------------------------------------------------------------------
//#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton1Click(TObject *Sender)
{
ShowMessage("Функция находится на стадии доработки. Приносим свои извинения.");
signPL = 'X';
signCP = 'O';
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton2Click(TObject *Sender)
{
ShowMessage("Функция находится на стадии доработки. Приносим свои извинения.");
signPL = 'O';
signCP = 'X';
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
Form2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
if(Key == 13)
{
	Form2->Label1->Caption = Edit1->Text;
	Form5->Label6->Caption = Edit1->Text;
}
}
//---------------------------------------------------------------------------

