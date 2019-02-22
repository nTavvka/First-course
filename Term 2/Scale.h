//---------------------------------------------------------------------------

#ifndef ScaleH
#define ScaleH
//---------------------------------------------------------------------------
#include <math.h>
 #include <vcl.h>
class Scale
{
public:
   void SetScale(int (&xy)[4][2],  int (&XY)[4][2], double scale);
   void SetScaleW(int (&xy)[4][2], int (&XY)[4][2], double scale, double ChScale, TLabel *Label10);
};

#endif
