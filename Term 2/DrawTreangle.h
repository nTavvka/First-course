//---------------------------------------------------------------------------

#ifndef DrawTreangleH
#define DrawTreangleH
//---------------------------------------------------------------------------
#include "GetParametr.h"
#include "Motion.h"

class DrawTreangle : private GetParametr
{
public:
    void Treangle(TForm *Form, TEdit *EditX1, TEdit *EditY1, TEdit *EditX2, TEdit *EditY2, TEdit *EditX3, TEdit *EditY3,
    TEdit *EditX0, TEdit *EditY0, TLabel *Label5,  TEdit *EditScale, TEdit *SetTime, TEdit *EditR,
    TLabel *Label8, TLabel *Label9, TLabel *Label10);
private:
   // void Draw_on_motion(TForm *Form, int Time, int sTime, double scale, int (&xy)[3][2], int (&XY)[3][2], double Xmove,
   //      double Ymove, int Xlast, int Ylast, int angle, TLabel *Label5, TLabel *Label8, TLabel *Label10);

    //void Draw_on_place(TForm *Form, int Time, double scale, int (&xy)[3][2], int (&XY)[3][2], double angle);
};

#endif
