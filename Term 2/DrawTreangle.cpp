//---------------------------------------------------------------------------


#pragma hdrstop

#include "DrawTreangle.h"

//---------------------------------------------------------------------------

void DrawTreangle::Treangle(TForm *Form, TEdit *EditX1, TEdit *EditY1, TEdit *EditX2, TEdit *EditY2, TEdit *EditX3, TEdit *EditY3,
    TEdit *EditX0, TEdit *EditY0, TLabel *Label5,  TEdit *EditScale, TEdit *SetTime, TEdit *EditR,
    TLabel *Label8, TLabel *Label9, TLabel *Label10)
{
    int xy[3][2], XY[3][2], Xlast, Ylast, Time, sTime = 0;
    double scale = 1, Xmove = 0, Ymove = 0, angle = 0;

    Get(xy, EditX1, EditY1, EditX2, EditY2, EditX3, EditY3, EditX0, EditY0, Xlast, Ylast, EditScale, scale, SetTime, Time, EditR, angle);

    Label9->Caption = FloatToStr(angle);

    int X0 = (xy[0][0] + xy[1][0]) / 2, Y0 = (xy[1][1] + xy[2][1]) / 2;
    double XmoveCpy = Xmove, YmoveCpy = Ymove;

    XY[0][0] = xy[0][0]; XY[0][1] = xy[0][1];
    XY[1][0] = xy[1][0]; XY[1][1] = xy[1][1];
    XY[2][0] = xy[2][0]; XY[2][1] = xy[2][1];

    /*
    if (Time > 0 && sTime != 0 || Xmove != 0 || Ymove != 0)
    {
       Draw_on_motion(Form, Time, sTime, scale, xy, XY, Xmove, Ymove, Xlast, Ylast, angle, Label5, Label8, Label10);
    }
    else
   {
       Draw_on_place(Form, Time, scale, xy, XY, angle);
   }
    */

    Label5->Caption = IntToStr(XY[0][0]);

    X0 = (xy[0][0] + xy[1][0] + xy[2][0]) / 3;
    Y0 = (xy[0][1] + xy[1][1] + xy[2][1]) / 3;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
void DrawTreangle::Draw_on_motion(TForm *Form, int Time, int sTime, double scale, int (&xy)[3][2], int (&XY)[3][2], double Xmove,
    double Ymove, int Xlast, int Ylast, int angle, TLabel *Label5, TLabel *Label8, TLabel *Label10)
{
     double ChScale = scale - 1, XmoveCpy = Xmove, YmoveCpy = Ymove, ChAngle;
      int X0 = (xy[0][0] + xy[1][0] + xy[2][0]) / 3,  Y0 = (xy[0][1] + xy[1][1] + xy[2][1]) / 3, NTick = 0;
      //int XChange = 0, YChange = 0;
     /*
     if (Time != 0)
     {
        NTick = Time / sTime;
        ChScale = (scale - 1) / (double)NTick;
        ChAngle = (double)angle / (double)sTime;
     }
     else ChAngle = angle;

      int Xfirst = X0, Yfirst = Y0;
      double ChScaleCpy = ChScale, ChAngleCpy = ChAngle;
      int XChange = X0, YChange = Y0;


      Label8->Caption = IntToStr(XY[0][0]);
     // do
     // {
         //Application->ProcessMessages();
         //Sleep(sTime);

         //Label10->Caption = FloatToStr(ChAngle);
         //if (ChScale != 0) SetScale(xy, XY, scale, ChScale);

         //if (Time == 0) Turn(XY, xy, ChAngle, Xfirst, Yfirst); ////////////////////////////////

         //Turn_on_motion(XY, xy, ChAngle, XChange, YChange);
          /*
         if (Xmove >= 1 || Xmove <= -1)
         {
            XY[0][0] += Xmove;
            XY[1][0] += Xmove;
            XY[2][0] += Xmove;
            Xmove = Xmove > 0 ? Xmove-- : Xmove++;
         }

         if (Ymove >= 1 || Ymove <= -1)
         {
            XY[0][1] += Ymove;
            XY[1][1] += Ymove;
            XY[2][1] += Ymove;
            Ymove = Ymove > 0 ? Ymove-- : Ymove++;
         }




         Form->Repaint();
         Form->Canvas->Pen->Width = 3;
         Form->Canvas->MoveTo(XY[0][0], XY[0][1]);
         Form->Canvas->LineTo(XY[1][0], XY[1][1]);
         Form->Canvas->LineTo(XY[2][0], XY[2][1]);
         Form->Canvas->LineTo(XY[0][0], XY[0][1]);

         Xmove += XmoveCpy;
         Ymove += YmoveCpy;
         ChScale += ChScaleCpy;

         ChAngle += ChAngleCpy;
         XChange += Xmove;
         YChange += Ymove;

         //X0 = (XY[0][0] + XY[1][0]) / 2;
         //Y0 = (XY[1][1] + XY[2][1]) / 2;

         X0 = (XY[0][0] + XY[1][0] + XY[2][0]) / 3;
         Y0 = (XY[0][1] + XY[1][1] + XY[2][1]) / 3;

         //if (ChAngle >= 0 && ChAngle >= angle) break;
         //Label8->Caption = IntToStr(Xfirst);
         //Label5->Caption = IntToStr(Yfirst);
         /*
         if (Xmove > 0 || Ymove > 0)
         {
            if (X0 + Y0 >= Xlast + Ylast) break;
         }
         else if (Xmove < 0 || Ymove < 0)
         {
            if (X0 + Y0 <= Xlast + Ylast) break;
         }
         else break;
           */
     // }while (true);
//}
/*
void DrawTreangle::Draw_on_place(TForm *Form, int Time, double scale, int (&xy)[3][2], int (&XY)[3][2], double angle)
{
double ChScale = scale - 1, ChAngle;
      int X0 = abs((xy[0][0] + xy[1][0]) / 2), Y0 = abs((xy[1][1] + xy[2][1]) / 2), NTick = 0, Counter = 0;
      int XLast = xy[0][0] < X0 ? xy[0][0] - abs((X0 - xy[0][0]) * abs(scale - 1)) : xy[0][0] + abs((X0 - xy[0][0]) * abs(scale - 1));

   ////////////////////////////////////////////////////////

      if (Time != 0)
      {
          NTick = Time /abs(XLast - X0);
          ChScale = (scale - 1) / NTick;
          ChAngle = angle / NTick;
      }
      else ChAngle = angle;

   ////////////////////////////////////////////////////////

      double ChScaleCpy = ChScale, ChAngleCpy = ChAngle;
      do
      {
         Application->ProcessMessages();
         Sleep(NTick);

         if (ChScale != 0) SetScale(xy, XY, scale, ChScale);

         Turn(XY, xy, ChAngle, X0, Y0);

         Form->Repaint();
         Form->Canvas->Pen->Width = 3;
         Form->Canvas->MoveTo(XY[0][0], XY[0][1]);
         Form->Canvas->LineTo(XY[1][0], XY[1][1]);
         Form->Canvas->LineTo(XY[2][0], XY[2][1]);
         Form->Canvas->LineTo(XY[3][0], XY[3][1]);
         Form->Canvas->LineTo(XY[0][0], XY[0][1]);

         ChScale += ChScaleCpy;
         Counter++;

         if (ChScale != 0 && ChAngle != 0)
         {
            ChAngle += ChAngleCpy;
            if (ChAngle > 0 && ChAngle >= angle+1) break;
            else if (ChAngle < 0 && ChAngle <= angle+1) break;
         }
         else if (Counter == NTick || Time == 0) break;

         if (angle == 0)
         {
            if (ChScale > 0 && ChScale >= scale - 1) break;
            else if (ChScale < 0 && ChScale <= scale - 1) break;
            else if (ChScale == 0) break;
         }

      }while (true);
}
                */
#pragma package(smart_init)
