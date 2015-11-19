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
bool Cheburashka (double x, double y, double a, double b, double c);

int main()
    {
    _txWindowStyle &= ~ WS_CAPTION;

    txCreateWindow (XWindow, YWindow);
    Osnov ();
    }

void Osnov ()
    {
    double Zoom = 30;
    COLORREF color = TX_WHITE;
    double perX = 0, perY = 0;
    Setka (Zoom, XWindow, YWindow, 0, 0);
    int t = 0;

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txBegin ();
        txClear ();

        //Mass_Nerav (Kn_Ner, Kn_NerN, color, Zoom, image, perX, perY);
        Neravenstvo (Zoom, TX_GREEN, Cheburashka, t%2, t%2, t%12, 1, 0, perX, perY);

        t ++;
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

bool Cheburashka (double x, double y, double a, double b, double c)
    {
    if (x * x + y * y >= 120 && x * x + y * y <= 140 ||
        0.15 * x * x <= y + 10 + a && 0.075 * x * x >= y + 5 - a ||
        (x - 4) * (x - 4) + (y - 5) * (y - 5) <= b || (x + 4) * (x + 4) + (y - 5) * (y - 5) <= b||
        (x + c) * (x + c) + y * y <= 90 && x * x + y * y >= 140||
        (x - c) * (x - c) + y * y <= 90 && x * x + y * y >= 140)
        {
        return true;
        }

    else return false;
    }

