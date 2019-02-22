//---------------------------------------------------------------------------

#ifndef MotionH
#define MotionH
//---------------------------------------------------------------------------
#include "Scale.h"
#include "ScaleS.h"
#include "Rotation.h"

//#include <math.h>
#include <vcl.h>

class Motion : public Scale, public Rotation    //public ScaleS,
{
public:
   void SetTick(int (&xy)[4][2], int (&XY)[4][2], double scale,
        int Xlast, int Ylast, int Time, double &Xmove, double &Ymove, int &sTime);

  // void SetTick(int (&xy)[3][2], int (&XY)[3][2], double scale,
    //    int Xlast, int Ylast, int Time, double &Xmove, double &Ymove, int &sTime,  TLabel *Label10);
};
#endif
