//---------------------------------------------------------------------------

#ifndef ProcessGoH
#define ProcessGoH
//---------------------------------------------------------------------------

#include "Scale.h"

#include <vcl.h>

class ProcessGo : private Scale
{
public:
   void TicksGo(int (&xy)[4][2], int (&XY)[4][2], double scale,
        int Xlast, int Ylast, int Time, double &Xmove, double &Ymove, int &sTime, TLabel *Label1, TLabel *Label2, TLabel *Label3, TLabel *Label4);
};
#endif
