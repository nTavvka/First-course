//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "DrawRectangle.h"
#include "DrawTreangle.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   DrawRect R;
   R.Rectangle(Form1, EditX1, EditY1, EditX2, EditY2, EditX0, EditY0, EditScale, SetTime, EditR, Label10);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
   DrawTreangle T;
   T.Treangle(Form1, EditX1, EditY1, EditX2, EditY2, EditX3, EditY3, EditX0, EditY0, Label234, EditScale,
   SetTime, EditR, Label8, Label9, Label10);
}
//---------------------------------------------------------------------------

