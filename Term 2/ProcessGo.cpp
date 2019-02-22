//---------------------------------------------------------------------------


#pragma hdrstop

#include "ProcessGo.h"

//---------------------------------------------------------------------------

void ProcessGo::TicksGo(int (&xy)[4][2], int (&XY)[4][2], double scale, int Xlast,
     int Ylast, int Time, double &Xmove, double &Ymove, int &sTime, TLabel *Label5, TLabel *Label8, TLabel *Label9, TLabel *Label10)
{
    SetScale(xy, XY, scale);
    int xTime = 0, yTime = 0;

    if (Xlast != (xy[0][0] + xy[1][0]) / 2)
    {
       if (Time != 0)
       {
          xTime = Time / (Xlast - ((xy[0][0] + xy[1][0]) / 2));
          Xmove = xTime != 0 ? 1 : Xlast - ((xy[0][0] + xy[1][0]) / 2);
       }
       else Xmove = Xlast - ((xy[0][0] + xy[1][0]) / 2);
    }
    else Xmove = 0;

    if (Ylast != (xy[1][1] + xy[2][1]) / 2)
    {
        if (Time != 0)
        {
           yTime = Time / (Ylast - ((xy[1][1] + xy[2][1]) / 2));
           Ymove = yTime != 0 ? 1 : Ylast - ((xy[1][1] + xy[2][1]) / 2);
        }
        else Ymove = Ylast - ((xy[1][1] + xy[2][1]) / 2);
    }
    else Ymove = 0;

    if (Xlast == 0) Xmove = 0;
    if (Ylast == 0) Ymove = 0;

    if (xTime != 0 && yTime != 0) sTime = xTime > yTime ? yTime : xTime;
    else if (xTime != 0 && yTime == 0) sTime = xTime;
    else if (xTime == 0 && yTime != 0) sTime = yTime;
    else sTime = 0;

    if (xTime != 0 && yTime != 0 && xTime > yTime) Xmove = (float)yTime / (float)xTime;
    else if (xTime != 0 && yTime != 0 && xTime < yTime) Ymove = (float)xTime / (float)yTime;
     Label5->Caption = IntToStr(xTime);
     Label8->Caption = FloatToStr(Xmove);

     Label9->Caption = IntToStr(yTime);
     Label10->Caption = FloatToStr(Ymove);
}

#pragma package(smart_init)
