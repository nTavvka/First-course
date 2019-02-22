//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *EditX1;
	TEdit *EditY1;
	TEdit *EditX2;
	TEdit *EditY2;
	TLabel *Label234;
	TEdit *EditX0;
	TEdit *EditY0;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *EditScale;
	TEdit *SetTime;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TEdit *EditR;
	TLabel *Label5;
	TLabel *Label11;
	TEdit *EditX3;
	TEdit *EditY3;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
