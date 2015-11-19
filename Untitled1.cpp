
#include "TXLib.h"
double XWindow = GetSystemMetrics (SM_CXSCREEN), YWindow = GetSystemMetrics (SM_CYSCREEN);
void Mandelbrod (double PerX, double PerY, double Zoom);

int main()
    {
    _txWindowStyle &= ~ WS_CAPTION;
    txCreateWindow (XWindow, YWindow);

    Mandelbrod (0, 0, 100);

    return 0;
    }

void Mandelbrod (double PerX, double PerY, double Zoom)
    {
    double x0 = -2, x_old = -2;
    double y0 = -2, y_old = -2;
    double n;

    while (x0 < 2)
        {
        while (y0 < 2)
            {
            while (n < 3)
                {
                double x_new = x_old * x_old - y_old * y_old + x0;
                double y_new = 2 * x_old * y_old + y0;

                if (sqrt (x_new * x_new + y_new * y_new) > 1)
                    {
                    txSetPixel (x_new * Zoom + XWindow / 2 + PerX, -y_new * Zoom + YWindow / 2 + PerY, RGB(255, 0, 255));
                    break;
                    }
                x_old = x_new;
                y_old = y_new;
                n++;
                }
            y0 += 0.01;
            }
        x0 += 0.01;
        }
    }
