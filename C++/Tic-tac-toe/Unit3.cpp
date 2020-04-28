//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <fstream>
#include <string.h>

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
using namespace std;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
Form3->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCreate(TObject *Sender)
{
ifstream fin("Resource.txt");
int a, b, c;
fin >> a >> b >> c;
Form3->Label1->Caption = "Проведено игр: " + IntToStr(a);
Form3->Label2->Caption = "Выиграно: " + IntToStr(b);
Form3->Label3->Caption = "Процент выигрышей: " + IntToStr(c) + '%';
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
ofstream fout("Resource.txt");
int s = 0;
fout << s << endl << s << endl << s << endl;
ifstream fin("Resource.txt");
int a, b, c;
fin >> a >> b >> c;
Form3->Label1->Caption = "Проведено игр: " + IntToStr(a);
Form3->Label2->Caption = "Выиграно: " + IntToStr(b);
Form3->Label3->Caption = "Процент выигрышей: " + IntToStr(c) + '%';
}
//---------------------------------------------------------------------------

