
#include "TXLib.h"

const double XWindow = GetSystemMetrics (SM_CXSCREEN), YWindow = GetSystemMetrics (SM_CYSCREEN);

void Kot ();

int main()
    {
    _txWindowStyle &= ~ WS_CAPTION;

    txCreateWindow (XWindow, YWindow);

    Kot ();

    return 0;
    }

void Kot ()
    {

    HDC Kot  = txLoadImage ("Image//Кот.bmp");

    double x = random (XWindow / 2 + 300, XWindow / 2 - 300), y = random (YWindow / 2 - 300, YWindow / 2 + 300);
    double a = random (-300, 300), b = random (-300, 300);

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txBegin ();
        txSetFillColor (TX_WHITE);
        txClear ();
        if (GetAsyncKeyState('A')) x-=2;
        if (GetAsyncKeyState('D')) x+=2;
        if (GetAsyncKeyState('W')) y-=2;
        if (GetAsyncKeyState('S')) y+=2;
        txTransparentBlt (txDC (), x, y, 92, 41, Kot, 0, 0, TX_WHITE);
        if (abs (x - x + a) > 35 + 10)txBitBlt (txDC (), x + a, y + b, 38, 20, Kot, 113, 10);
        if (x < 0) x = XWindow;
        if (x > XWindow) x = 0;
        if (y < 0) y = YWindow;
        if (y > YWindow) y = 0;

        txEnd ();
        }
    txDeleteDC (Kot);
    }

