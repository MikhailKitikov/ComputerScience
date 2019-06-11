//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *board;
	TImage *fon;
	TDrawGrid *DrawGrid1;
	TButton *Button1;
	TLabel *Label1;
	TLabel *Label2;
	TMainMenu *MainMenu1;
	TMenuItem *Game1;
	TMenuItem *Open1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *Help1;
	TMenuItem *Help2;
	TOpenTextFileDialog *OpenTextFileDialog1;
	TSaveTextFileDialog *SaveTextFileDialog1;
	TBitBtn *BitBtn1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TTimer *Timer1;
	TMenuItem *Save1;
	TMenuItem *Open2;
	TMenuItem *N3;
	TMenuItem *Quit1;
	TPopupMenu *PopupMenu1;
	TMenuItem *k1;
	TMenuItem *Quit2;
	TMenuItem *Save2;
	TMenuItem *Open3;
	TMenuItem *Missamove1;
	TMenuItem *Showpossiblemoves1;
	TImage *Image1;
	TImage *Image2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DrawGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall Quit1Click(TObject *Sender);
	void __fastcall Open2Click(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall k1Click(TObject *Sender);
	void __fastcall Quit2Click(TObject *Sender);
	void __fastcall Save2Click(TObject *Sender);
	void __fastcall Open3Click(TObject *Sender);
	void __fastcall Missamove1Click(TObject *Sender);
	void __fastcall Showpossiblemoves1Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
