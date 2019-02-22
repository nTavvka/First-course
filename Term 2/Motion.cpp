//---------------------------------------------------------------------------


#pragma hdrstop

#include "Motion.h"

//---------------------------------------------------------------------------

void Motion::SetTick(int (&xy)[4][2], int (&XY)[4][2], double scale, int Xlast,
     int Ylast, int Time, double &Xmove, double &Ymove, int &sTime)
{
    SetScale(xy, XY, 1);
    //SetScaleS(xy, XY, scale);
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

    if (sTime < 0)
     {
     	sTime *= -1;
     	Xmove *= -1;
     	Ymove *= -1;
     }
}

///////////////////////////////////////////////////////////////////////////////////////////

/*
void Motion::SetTick(int (&xy)[3][2], int (&XY)[3][2], double scale, int Xlast,
     int Ylast, int Time, double &Xmove, double &Ymove, int &sTime, TLabel *Label10)
{
    //SetScale(xy, XY, 1);
    //SetScaleS(xy, XY, scale);                   (xy[0][1] + xy[1][1] + xy[2][1]) / 3
    int xTime = 0, yTime = 0;

    if (Xlast != (xy[0][0] + xy[1][0]) / 2)
    {
       if (Time != 0)
       {
          xTime = Time / (Xlast - ((xy[0][0] + xy[1][0] + xy[2][0]) / 3);
          Xmove = xTime != 0 ? 1 : Xlast - ((xy[0][0] + xy[1][0] + xy[2][0]) / 3);
       }
       else Xmove = Xlast - ((xy[0][0] + xy[1][0] + xy[2][0]) / 3);
    }
    else Xmove = 0;

    if (Ylast != (xy[0][1] + xy[1][1] + xy[2][1]) / 3)
    {
        if (Time != 0)
        {
           yTime = Time / (Ylast - ((xy[0][1] + xy[1][1] + xy[2][1]) / 3);
           Ymove = yTime != 0 ? 1 : Ylast - ((xy[0][1] + xy[1][1] + xy[2][1]) / 3);
        }
        else Ymove = Ylast - ((xy[0][1] + xy[1][1] + xy[2][1]) / 3);
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

    if (sTime < 0)
     {
     	sTime *= -1;
     	Xmove *= -1;
     	Ymove *= -1;
     }

     //Label5->Caption = IntToStr(xTime);
     //Label8->Caption = IntToStr(sTime);

    // Label9->Caption = IntToStr(yTime);
     //Label10->Caption = FloatToStr(Xmove);

     //scale = scale / 5;
}
           */
#pragma package(smart_init)
