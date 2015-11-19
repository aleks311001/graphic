#include "TXLib.h"

typedef bool (ner_t) (double x, double y, double a, double b, double c);

struct Knop_Ner
    {
    double x, y;
    double Zoom;
    HDC vkl, vikl;
    ner_t* ner;
    double a, b, c;
    const char* tekst;
    double shagX, shagY;
    COLORREF color;
    };

struct AllIzobr
    {
    HDC Knopka_Vkl_dly_ner;
    HDC Knopka_Vikl_dly_ner;
    };

double XWindow = GetSystemMetrics (SM_CXSCREEN), YWindow = GetSystemMetrics (SM_CYSCREEN);
void Osnov ();
void Neravenstvo (double Zoom, COLORREF color, ner_t* nerav, double a, double b, double c, double shagX, double shagY, double perX, double perY);
double mod (double x);
void Setka (double zoom, double a, double b, double PerX, double PerY);
bool Stakan (double x, double y, double a, double b, double c);

int main()
    {
    _txWindowStyle &= ~ WS_CAPTION;

    txCreateWindow (XWindow, YWindow);
    Osnov ();
    }

void Osnov ()
    {
    double Zoom = 55;
    COLORREF color = TX_WHITE;
    double perX = 0, perY = 0;
    Setka (Zoom, XWindow, YWindow, 0, 0);
    double a = 0, b = 0, c = 0;

    int Kn_NerN   = 1;

    Knop_Ner Kn_Ner [1] = {{XWindow - 455, YWindow - 85, 0, NULL, NULL, Stakan,  a, b, c, "Стакан", 1, 0, color}};

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txBegin ();
        txClear ();

        //Mass_Nerav (Kn_Ner, Kn_NerN, color, Zoom, image, perX, perY);
        Neravenstvo (Zoom, TX_GREEN, Stakan, a, b, c, 1, 0, perX, perY);

        a += 25;
        b += 0.9;

        if (b > 12) b = 0;

        txEnd ();
        }
    }

void Neravenstvo (double Zoom, COLORREF color, ner_t* nerav, double a, double b, double c, double shagX, double shagY, double perX, double perY)
    {
    for (double y = -YWindow / (2 * Zoom); y <= YWindow / (2 * Zoom); y += 2 / Zoom)
        {
        for (double x = -XWindow / (2 * Zoom); x <= XWindow / (2 * Zoom); x += 1 / Zoom)
            {
            if (nerav (x, y, a, b, c) == true)
                {
                txSetPixel (x * Zoom + XWindow/2 + perX + shagX, -y * Zoom + YWindow / 2 + perY + shagY, color);
                }
            }
        }
    }

void Setka (double zoom, double a, double b, double PerX, double PerY)
    {
    txBegin ();

    txSetFillColor (TX_BLACK);
    txClear ();

    txSetColor (TX_WHITE, 3);
    txLine (0, b / 2, XWindow, b / 2);
    txLine (a / 2, 0, a / 2, YWindow);
    txLine (XWindow, b / 2, XWindow - 30, b / 2 - 15);
    txLine (XWindow, b / 2, XWindow - 30, b / 2 + 15);
    txLine (a / 2, 0, a / 2 + 15, 30);
    txLine (a / 2, 0, a / 2 - 15, 30);

    txEnd ();
    }

double mod (double x)
    {
    if (x < 0) return -x;
    else       return x;
    }

bool Stakan (double x, double y, double a, double b, double c)
    {
    if (x * x + (y - 0.5) * (y - 0.5) >= 50 && x * x + (y - 0.5) * (y - 0.5) <= 55 && y <= 0.75 ||
        -mod(cos ((x + a) * 2) / 2) >= y + 0.5 && x * x + (y - 0.5) * (y - 0.5) <= 55 ||
        -mod(2.5 * x) >= y + 2.5 && y >= -10 ||
        x * x + (y - 10 + b) * (y - 10 + b) <= 1)
        {
        return true;
        }

    else return false;
    }
