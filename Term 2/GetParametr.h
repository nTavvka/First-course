//---------------------------------------------------------------------------

#ifndef GetParametrH
#define GetParametrH
//---------------------------------------------------------------------------
#include <vcl.h>

class GetParametr
{
public:
   void Get(int (&xy)[4][2], TEdit *EditX1, TEdit *EditY1, TEdit *EditX2, TEdit *EditY2,
   TEdit *EditX0, TEdit *EditY0, int&X0, int&Y0, TEdit *EditScale, double &scale, TEdit *SetTime, int &Time, TEdit *EditR, double &angle);

   void Get(int (&xy)[3][2], TEdit *EditX1, TEdit *EditY1, TEdit *EditX2, TEdit *EditY2, TEdit *EditX3, TEdit *EditY3,
   TEdit *EditX0, TEdit *EditY0, int&X0, int&Y0, TEdit *EditScale, double &scale, TEdit *SetTime, int &Time, TEdit *EditR, double &angle);
};

#endif
