//---------------------------------------------------------------------------


#pragma hdrstop

#include "GetParametr.h"

//---------------------------------------------------------------------------

void GetParametr::Get(int (&xy)[4][2], TEdit *EditX1, TEdit *EditY1, TEdit *EditX2, TEdit *EditY2,
 TEdit *EditX0, TEdit *EditY0, int &X0, int&Y0, TEdit *EditScale, double &scale, TEdit *SetTime, int &Time, TEdit *EditR, double &angle)
{
   xy[0][0] = EditX1->Text.ToInt();
   xy[1][0] = EditX2->Text.ToInt();
   xy[2][0] = EditX2->Text.ToInt();
   xy[3][0] = EditX1->Text.ToInt();

   xy[0][1] = EditY1->Text.ToInt();
   xy[1][1] = EditY1->Text.ToInt();
   xy[2][1] = EditY2->Text.ToInt();
   xy[3][1] = EditY2->Text.ToInt();

   X0 = EditX0->Text.ToInt();
   Y0 = EditY0->Text.ToInt();

   scale = EditScale->Text.ToDouble();
   Time = SetTime->Text.ToInt();
   angle = EditR->Text.ToInt();
}

void GetParametr::Get(int (&xy)[3][2], TEdit *EditX1, TEdit *EditY1, TEdit *EditX2, TEdit *EditY2, TEdit *EditX3, TEdit *EditY3,
   TEdit *EditX0, TEdit *EditY0, int&X0, int&Y0, TEdit *EditScale, double &scale, TEdit *SetTime, int &Time, TEdit *EditR, double &angle)
{
   xy[0][0] = EditX1->Text.ToInt();
   xy[1][0] = EditX2->Text.ToInt();
   xy[2][0] = EditX3->Text.ToInt();

   xy[0][1] = EditY1->Text.ToInt();
   xy[1][1] = EditY2->Text.ToInt();
   xy[2][1] = EditY3->Text.ToInt();

   X0 = EditX0->Text.ToInt();
   Y0 = EditY0->Text.ToInt();

   scale = EditScale->Text.ToDouble();
   Time = SetTime->Text.ToInt();
   angle = EditR->Text.ToInt();
}
#pragma package(smart_init)
