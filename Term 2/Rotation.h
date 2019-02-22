//---------------------------------------------------------------------------

#ifndef RotationH
#define RotationH
//---------------------------------------------------------------------------
#include <math.h>

class Rotation
{
public:
    void Turn(int (&XY)[4][2], int (&xy)[4][2], double angle, int X0, int Y0);
    void Turn_on_motion(int (&XY)[4][2], int (&xy)[4][2], double ChAngle, int X0, int Y0);
};

#endif
