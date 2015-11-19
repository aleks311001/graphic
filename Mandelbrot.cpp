
#include "DirectTX.h"
struct Knop
    {
    double x, y;
    double Zoom;
    HDC vkl, vikl;
    double z_p;
    double* per;
    };

struct AllIzobr
    {
    HDC Knopka_Vkl_vverh;
    HDC Knopka_Vikl_vverh;
    HDC Knopka_Vkl_vpravo;
    HDC Knopka_Vikl_vpravo;
    HDC Knopka_Vkl_vniz;
    HDC Knopka_Vikl_vniz;
    HDC Knopka_Vkl_vlevo;
    HDC Knopka_Vikl_vlevo;
    HDC Knopka_Vkl_na_mesto;
    HDC Knopka_Vikl_na_mesto;
    HDC Knopka_Plus_Vkl;
    HDC Knopka_Plus_Vikl;
    HDC Knopka_Minus_Vkl;
    HDC Knopka_Minus_Vikl;
    HDC Knopka_Plus_Vkl_Big;
    HDC Knopka_Plus_Vikl_Big;
    HDC Knopka_Minus_Vkl_Big;
    HDC Knopka_Minus_Vikl_Big;
    };

double XWindow = GetSystemMetrics (SM_CXSCREEN), YWindow = GetSystemMetrics (SM_CYSCREEN);
void Mandelbrot (double Zoom, double perX, double perY);
void Knopka_Dvig (Knop * Kn, double Zoom, double PerX, double PerY);
void Knopka_Dvig_naMest (Knop * Kn, double Zoom, double* c, double c_ravno, double* d, double d_ravno, double PerX, double PerY);
void Knopka_Zoom (Knop * Kn, double* Zoom, double PerX, double PerY);
void Mass_Zoom (Knop Kn_Zoom[], int N_Zoom, double *Zoom, double perX, double perY);
void Mass_Dvig (Knop Dvig[], int N_Dvig, double Zoom, double perX, double perY);
//void Mish (double* Zoom, double* x0, double* y0, double* xmax, double* ymax);
void AllDeleteImage (AllIzobr * Image);
void Mish (double * Zoom, double* x0, double* y0);
double sinc  (double x);
double sinc2 (double x);
void AllImage (AllIzobr * Image);
//void Clear ();

int main()
    {
    DirectTXCreateWindow (XWindow - 20, YWindow - 20, "Для закрытия Мандельброта нажмите Escape.");
    double Zoom = 500;
    double perX = 0, perY = 0;
    int N_Zoom    = 4;
    int N_Dvig    = 5;
    double x0 = 0;
    double y0 = 0;

    AllIzobr image = {};
    AllImage (&image);

    Knop Dvig [5]    = {{XWindow - 20 - 150, YWindow - 20 - 240, 0, image.Knopka_Vkl_vverh,    image.Knopka_Vikl_vverh,  -50, &perY},
                        {XWindow - 20 - 60,  YWindow - 20 - 150, 0, image.Knopka_Vkl_vpravo,   image.Knopka_Vikl_vpravo,  50, &perX},
                        {XWindow - 20 - 150, YWindow - 20 - 60,  0, image.Knopka_Vkl_vniz,     image.Knopka_Vikl_vniz,    50, &perY},
                        {XWindow - 20 - 240, YWindow - 20 - 150, 0, image.Knopka_Vkl_vlevo,    image.Knopka_Vikl_vlevo,  -50, &perX},
                        {XWindow - 20 - 150, YWindow - 20 - 150, 0, image.Knopka_Vkl_na_mesto, image.Knopka_Vikl_na_mesto}};

    Knop Kn_Zoom [4] = {{(XWindow - 20 )/ 2 - 80,  YWindow - 20 - 80, 0, image.Knopka_Plus_Vkl,      image.Knopka_Plus_Vikl,       50},
                        {(XWindow - 20 )/ 2 + 80,  YWindow - 20 - 80, 0, image.Knopka_Minus_Vkl,     image.Knopka_Minus_Vikl,     -50},
                        {(XWindow - 20 )/ 2 - 160, YWindow - 20 - 80, 0, image.Knopka_Plus_Vkl_Big,  image.Knopka_Plus_Vikl_Big,   100},
                        {(XWindow - 20 )/ 2 + 160, YWindow - 20 - 80, 0, image.Knopka_Minus_Vkl_Big, image.Knopka_Minus_Vikl_Big, -100}};

    txSetFillColor (TX_BLACK);

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        DirectTXBegin ();

        //Clear ();

        //_beginthread (Mandelbrot, 0, (double *) (Zoom, perX, perY));

        //Mish (&Zoom, &x0, &y0, &xmax, &ymax);

        Mandelbrot (Zoom, perX, perY);

        Mass_Zoom (Kn_Zoom, N_Zoom, &Zoom, perX, perY);

        Knopka_Dvig_naMest (&Dvig [4], Zoom, &perX, 0, &perY, 0, perX, perY);

        Mass_Dvig (Dvig, N_Dvig, Zoom, perX, perY);

        DirectTXEnd ();
        }

    AllDeleteImage (&image);
    }

void AllImage (AllIzobr * Image)
    {
    Image->Knopka_Vkl_vverh            = txLoadImage ("Image//Knopka_Vkl_vverh.bmp");
    Image->Knopka_Vikl_vverh           = txLoadImage ("Image//Knopka_Vikl_vverh.bmp");
    Image->Knopka_Vkl_vpravo           = txLoadImage ("Image//Knopka_Vkl_vpravo.bmp");
    Image->Knopka_Vikl_vpravo          = txLoadImage ("Image//Knopka_Vikl_vpravo.bmp");
    Image->Knopka_Vkl_vniz             = txLoadImage ("Image//Knopka_Vkl_vniz.bmp");
    Image->Knopka_Vikl_vniz            = txLoadImage ("Image//Knopka_Vikl_vniz.bmp");
    Image->Knopka_Vkl_vlevo            = txLoadImage ("Image//Knopka_Vkl_vlevo.bmp");
    Image->Knopka_Vikl_vlevo           = txLoadImage ("Image//Knopka_Vikl_vlevo.bmp");
    Image->Knopka_Vkl_na_mesto         = txLoadImage ("Image//Knopka_Vkl_na_mesto.bmp");
    Image->Knopka_Vikl_na_mesto        = txLoadImage ("Image//Knopka_Vikl_na_mesto.bmp");
    Image->Knopka_Plus_Vkl             = txLoadImage ("Image//Knopka_Plus_Vkl.bmp");
    Image->Knopka_Plus_Vikl            = txLoadImage ("Image//Knopka_Plus_Vikl.bmp");
    Image->Knopka_Minus_Vkl            = txLoadImage ("Image//Knopka_Minus_Vkl.bmp");
    Image->Knopka_Minus_Vikl           = txLoadImage ("Image//Knopka_Minus_Vikl.bmp");
    Image->Knopka_Plus_Vkl_Big         = txLoadImage ("Image//Knopka_Plus_Vkl_Big.bmp");
    Image->Knopka_Plus_Vikl_Big        = txLoadImage ("Image//Knopka_Plus_Vikl_Big.bmp");
    Image->Knopka_Minus_Vkl_Big        = txLoadImage ("Image//Knopka_Minus_Vkl_Big.bmp");
    Image->Knopka_Minus_Vikl_Big       = txLoadImage ("Image//Knopka_Minus_Vikl_Big.bmp");
    }

void AllDeleteImage (AllIzobr * Image)
    {
    txDeleteDC (Image->Knopka_Vkl_vverh);
    txDeleteDC (Image->Knopka_Vikl_vverh);
    txDeleteDC (Image->Knopka_Vkl_vpravo);
    txDeleteDC (Image->Knopka_Vikl_vpravo);
    txDeleteDC (Image->Knopka_Vkl_vniz);
    txDeleteDC (Image->Knopka_Vikl_vniz);
    txDeleteDC (Image->Knopka_Vkl_vlevo);
    txDeleteDC (Image->Knopka_Vikl_vlevo);
    txDeleteDC (Image->Knopka_Vkl_na_mesto);
    txDeleteDC (Image->Knopka_Vikl_na_mesto);
    txDeleteDC (Image->Knopka_Plus_Vkl);
    txDeleteDC (Image->Knopka_Plus_Vikl);
    txDeleteDC (Image->Knopka_Minus_Vkl);
    txDeleteDC (Image->Knopka_Minus_Vikl);
    txDeleteDC (Image->Knopka_Plus_Vkl_Big);
    txDeleteDC (Image->Knopka_Plus_Vikl_Big);
    txDeleteDC (Image->Knopka_Minus_Vkl_Big);
    txDeleteDC (Image->Knopka_Minus_Vikl_Big);
    }

void Mandelbrot (double Zoom, double perX, double perY)
    {
    double x_Old = 0, y_Old = 0;
    double x_New = 0, y_New = 0;
    DirectTXColor color = TX_BLACK;

    for (double x = -2; x < 1.5; x += 1 / Zoom)
        {
        for (double y = -1.25; y < 1.25; y += 1 / Zoom)
            {
            x_Old = x;
            y_Old = y;

            for (double n = 0; n < 25; n++)
                {
                x_New = x_Old * x_Old - y_Old * y_Old + x;
                y_New = 2 * x_Old * y_Old + y;

                color = RGB();
                if (sqrt (x_New * x_New + y_New * y_New) >= 50)
                    {
                    break;
                    }

                if (n >= 24)
                    {
                    color = RGB(0, 0, 0);
                    }

                x_Old = x_New;
                y_Old = y_New;
                }
            DirectTXPutPixel (x * Zoom + perX + (XWindow - 20) / 2, -y * Zoom + perY + (YWindow - 20 )/ 2, color);
            }
        }
    DirectTXFlush ();
    }

double sinc (double x)
    {
    if (x == 0) return 1;
    else        return sin(x) / x;
    }

double sinc2 (double x)
    {
    if (x == 0) return 1;
    else        return sin(txPI * x) / txPI * x;
    }

void Mish (double * Zoom, double* x0, double* y0)
    {
    if (txMouseButtons() & 1)
        {

        *Zoom += *Zoom;
        if (*Zoom <= 0.1)
            {
            *Zoom = 0.1;
            }

        *x0 = txMouseX();
        *y0 = txMouseY();
        }
    }

void Knopka_Dvig (Knop * Kn, double Zoom, double PerX, double PerY)
    {
    HDC dc = NULL;

    if (txMouseX() < Kn->x + 37.5 && txMouseX() > Kn->x - 37.5 && txMouseY() < Kn->y + 37.5 && txMouseY() > Kn->y - 37.5)
        {
        if (txMouseButtons() == 1)
            {
            *Kn->per += Kn->z_p;
            }
        if (txMouseButtons() == 3)
            {
            Kn->x = txMouseX();
            Kn->y = txMouseY();
            txClear ();
            }
        dc = Kn->vkl;
        }
    else
        {
        dc = Kn->vikl;
        }
    txBitBlt (txDC(), Kn->x - 37.5, Kn->y - 37.5, 75, 75, dc, 0, 0/*, 1*/);
    }

void Knopka_Dvig_naMest (Knop * Kn, double Zoom, double* c, double c_ravno, double* d, double d_ravno, double PerX, double PerY)
    {
    HDC dc = NULL;

    if (txMouseX() < Kn->x + 37.5 && txMouseX() > Kn->x - 37.5 && txMouseY() < Kn->y + 37.5 && txMouseY() > Kn->y - 37.5)
        {
        if (txMouseButtons() == 1)
            {
            *c = c_ravno;
            *d = d_ravno;
            }
        if (txMouseButtons() == 3)
            {
            Kn->x = txMouseX();
            Kn->y = txMouseY();
            txClear ();
            }

        dc = Kn->vkl;

        }
    else
        {
        dc = Kn->vikl;
        }

    txBitBlt (txDC(), Kn->x - 37.5, Kn->y - 37.5, 75, 75, dc, 0, 0/*, 1*/);
    }

void Knopka_Zoom (Knop * Kn, double* Zoom, double PerX, double PerY)
    {
    HDC dc = NULL;

    if (txMouseX() < Kn->x + 37.5 && txMouseX() > Kn->x - 37.5 && txMouseY() < Kn->y + 37.5 && txMouseY() > Kn->y - 37.5)
        {
        if (txMouseButtons() == 1)
            {
            *Zoom += Kn->z_p;
            if (*Zoom <= 0.1)
                {
                *Zoom = 0.1;
                }
            }
        if (txMouseButtons() == 3)
            {
            Kn->x = txMouseX();
            Kn->y = txMouseY();
            txClear ();
            }
        dc = Kn->vkl;
        }
    else
        {
        dc = Kn->vikl;
        }
    txBitBlt (txDC(), Kn->x - 37.5, Kn->y - 37.5, 75, 75, dc, 0, 0/*, 1*/);
    }

void Mass_Zoom (Knop Kn_Zoom[], int N_Zoom, double *Zoom, double perX, double perY)
    {
    int i = 0;
    while (i < N_Zoom)
        {
        Knopka_Zoom (&Kn_Zoom [i], *&Zoom, perX, perY);
        i++;
        }
    }

void Mass_Dvig (Knop Dvig[], int N_Dvig, double Zoom, double perX, double perY)
    {
    int i = 0;
    while (i < N_Dvig - 1)
        {
        Knopka_Dvig (&Dvig [i], Zoom, perX, perY);
        i++;
        }
    }



