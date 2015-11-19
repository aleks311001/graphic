
#include "TXLib.h"

typedef double (func_t) (double x);

typedef bool (ner_t) (double x, double y, double a, double b, double c);

struct Knop
    {
    double x, y;
    double Zoom;
    HDC vkl, vikl;
    COLORREF color;
    func_t* func1;
    func_t* func2;
    const char* tekst;
    double kolvo_pi_min, kolvo_pi_max;
    double z_p;
    double* per;
    };

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
    HDC Knopka_Vkl_dly_ob_gr;
    HDC Knopka_Vikl_dly_ob_gr;
    HDC Knopka_Vkl2_dly_par_gr;
    HDC Knopka_Vikl2_dly_par_gr;
    HDC Knopka_Vkl_dly_pol_kord_gr;
    HDC Knopka_Vikl_dly_pol_kord_gr;
    HDC Knopka_Vkl_dly_ner;
    HDC Knopka_Vikl_dly_ner;
    HDC Knopka_Vkl3_dly_drug;
    HDC Knopka_Vikl3_dly_drug;
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
    HDC RGB_255_255_255White;
    HDC RGB_0_162_232Blue;
    HDC RGB_0_255_0Green;
    HDC RGB_0_0_255Blue;
    HDC RGB_163_73_163Magenta;
    HDC RGB_181_230_29Green;
    HDC RGB_234_222_0Yellow;
    HDC RGB_255_0_0Red;
    HDC RGB_255_43_112Pink;
    HDC RGB_255_119_28Orange;
    HDC Knopka_Vikluchit;
    };

double XWindow = GetSystemMetrics (SM_CXSCREEN), YWindow = GetSystemMetrics (SM_CYSCREEN);

void Grafik (COLORREF color, func_t* f, double Zoom, double perX = 0, double perY = 0, double c = 1, double d =0);
void Grafik_Parametr (COLORREF color, func_t* f1, func_t* f2, double kol_bo_pi2, double kol_bo_pi, double Zoom, double PerX, double PerY, double c = 1, double d = 0);
void Grafik_V_Pol_Korsd (COLORREF color, func_t* f, double h, double t, double Zoom, double PerX = 0, double PerY = 0, double c = 1, double d = 0);
void Neravenstvo (double Zoom, COLORREF color, ner_t* nerav, double a, double b, double c, double shagX, double shagY, double perX, double perY);
//void Mandelbrot (double Zoom, double perX, double perY);
void Mandelbrot (Knop * Kn, double perX, double perY);
double Parabola                     (double x);
double Liney                        (double x);
double f_9_delit_x                  (double x);
double f_1delit_x_umnogit_x_minus_9 (double x);
double sqrt_xplus2_plus_s_xminus2   (double x);
double prer_pryam                   (double x);
double diagr                        (double x);
double t_umnog_cos                  (double t);
double t_umnog_sin                  (double t);
double zvez_cos                     (double t);
double zvez_sin                     (double t);
double Babochka_sin                 (double t);
double Babochka_cos                 (double t);
double CatX                         (double t);
double CatY                         (double t);
double tochki                       (double x);
double NeoidX                       (double t);
double NeoidY                       (double t);
double cochleoidX                   (double t);
double cochleoidY                   (double t);
double tri_listX                    (double t);
double tri_listY                    (double t);
double tan_atan                     (double t);
double Sin_sinc                     (double t);
double sinc                         (double x);
double sinc2                        (double x);
double Kardiogr                     (double x);
double Zvezd2X                      (double t);
double Zvezd2Y                      (double t);
double SQRT                         (double x);
double Holmi                        (double x);
double Pol                          (double alfa);
double Pol_spiral                   (double a);
double serdce                       (double x);
double mod                          (double x);
double Chtoto                       (double x);
double EpicikloidaX                 (double x);
double EpicikloidaY                 (double x);
double sad                          (double x);
void text (const char * text, double x, double y);
void Setka (double zoom, double a, double b, double PerX, double PerY);
void Knopka             (Knop * Kn, double perX = 0, double perY = 0, double um = 1, double pl = 0);
void klear              (Knop * Kn, const char* tekst, double Zoom, double PerX = 0, double PerY = 0);
void Knopka_Par         (Knop * Kn, double PerX = 0, double PerY = 0, double um = 1, double pl = 0);
void Knopka_Dvig_naMest (Knop * Kn, double Zoom, double* c, double c_ravno, double* d, double d_ravno, double PerX = 0, double PerY = 0);
void Knopka_Color       (Knop * Kn, double Zoom, COLORREF* color, double PerX = 0, double PerY = 0);
void Knopka_Zoom        (Knop * Kn, double* Zoom, double PerX = 0, double PerY = 0);
void Knopka_Dvig        (Knop * Kn, double Zoom, double PerX = 0, double PerY = 0);
void Knopka_Pol_Kord    (Knop * Kn, double PerX = 0, double PerY = 0, double um = 1, double pl = 0);
void Knopka_Nerav       (Knop_Ner* Kn, double perX = 0, double perY = 0);
//void Knopka_Sohranit    (Knop * Kn, const char* tekst, double Zoom, double PerX, double PerY);
void Osnov ();
void AllImage (AllIzobr * Image);
void AllDeleteImage (AllIzobr * Image);
void Mass_Color_Kord (int N_Color, Knop Color[]);
void Mass_Color_Ris (Knop Color[], int N_Color, COLORREF* color, double Zoom, double perX, double perY);
void Mass_Ob_Kn (Knop Kn_ob[], int Kn_obN, COLORREF color, double Zoom, AllIzobr image, double perX = 0, double perY = 0);
void Mass_Par_Kn (Knop Kn_param[], int Kn_paramN, COLORREF color, double Zoom, AllIzobr image, double perX = 0, double perY = 0);
void Mass_Pol_Kord_Kn (Knop Kn_Pol[], int Kn_PolN, COLORREF color, double Zoom, AllIzobr image, double perX = 0, double perY = 0);
void Mass_Zoom (Knop Kn_Zoom[], int N_Zoom, double *Zoom, double perX, double perY);
void Mass_Dvig (Knop Dvig[], int N_Dvig, double Zoom, double perX, double perY);
void Mass_Nerav (Knop_Ner Kn_Ner[], int Kn_NerN, COLORREF color, double Zoom, AllIzobr image, double perX, double perY);
bool Krug         (double x, double y, double a, double b, double c);
bool Parabola_Ner (double x, double y, double a, double b, double c);
bool volni        (double x, double y, double a, double b, double c);
bool korablik     (double x, double y, double a, double b, double c);
bool smailik      (double x, double y, double a, double b, double c);
bool Mashina      (double x, double y, double a, double b, double c);
bool Kletki       (double x, double y, double a, double b, double c);
bool Kletki2      (double x, double y, double a, double b, double c);
bool Tipo_voln    (double x, double y, double a, double b, double c);
bool Kletki3      (double x, double y, double a, double b, double c);
bool Cheburashka  (double x, double y, double a, double b, double c);
double theta (double x);
double sgn (double x);

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

    int Kn_obN    = 16;
    int Kn_paramN = 10;
    int Kn_PolN   = 3;
    int N_Color   = 10;
    int N_Zoom    = 4;
    int N_Dvig    = 5;
    int Kn_NerN   = 11;

    AllIzobr image = {};
    AllImage (&image);


    Knop Kn_ob[16]   = {{60, 30,            0, NULL, NULL, color, sin,                          NULL, "Синус"     , 0,  2   * txPI},
                        {60, 85,            0, NULL, NULL, color, Parabola,                     NULL, "Парабола"  , 0,  2   * txPI},
                        {60, 140,           0, NULL, NULL, color, tochki,                       NULL, "Точки"     , 0,  10  * txPI},
                        {60, 195,           0, NULL, NULL, color, tan,                          NULL, "Тангенс"   , 0,  2   * txPI},
                        {60, 250,           0, NULL, NULL, color, f_9_delit_x,                  NULL, "Гипербола"                 },
                        {60, YWindow - 250, 0, NULL, NULL, color, f_1delit_x_umnogit_x_minus_9, NULL, "'Рожица'"                  },
                        {60, YWindow - 195, 0, NULL, NULL, color, sqrt_xplus2_plus_s_xminus2,   NULL, "'Тропеция'", 0,  10  * txPI},
                        {60, YWindow - 140, 0, NULL, NULL, color, prer_pryam,                   NULL, "Прер прям" , 0,  100 * txPI},
                        {60, YWindow - 85,  0, NULL, NULL, color, diagr,                        NULL, "Арнамент"  , 0,  2   * txPI},
                        {60, 305,           0, NULL, NULL, color, sinc2,                        NULL, "Волна"     , 0,  100 * txPI},
                        {60, YWindow - 305, 0, NULL, NULL, color, Kardiogr,                     NULL, "Кардиогр." , 0,  15  * txPI},
                        {60, 360,           0, NULL, NULL, color, SQRT,                         NULL, "Корень"    , 0,  100 * txPI},
                        {60, YWindow - 360, 0, NULL, NULL, color, Holmi,                        NULL, "Холмы"     , 0,  2   * txPI},
                        {60, YWindow - 415, 0, NULL, NULL, color, serdce,                       NULL, "Сердце"    , -2, 100 * txPI},
                        {60, 415,           0, NULL, NULL, color, Chtoto,                       NULL, "Что-то"    , 0,  2   * txPI},
                        {60, 470,           0, NULL, NULL, color, sad,                          NULL, "Алгебра"   , 0,  2   * txPI}};

    Knop Kn_param[10]= {{XWindow - 60, 30,  0, NULL, NULL, color, t_umnog_cos,  t_umnog_sin,  "Спираль",     0,   300},
                        {XWindow - 60, 85,  0, NULL, NULL, color, zvez_cos,     zvez_sin,     "Звезда",      0,   20},
                        {XWindow - 60, 140, 0, NULL, NULL, color, Babochka_cos, Babochka_sin, "Бабочка",     0,   10},
                        {XWindow - 60, 195, 0, NULL, NULL, color, CatY,         CatX,         "Кошка",       0,   10},
                        {XWindow - 60, 250, 0, NULL, NULL, color, NeoidY,       NeoidX,       "Neoid",       150, 150},
                        {XWindow - 60, 305, 0, NULL, NULL, color, cochleoidY,   cochleoidX,   "cochleoid",   0,   8},
                        {XWindow - 60, 360, 0, NULL, NULL, color, tri_listY,    tri_listX,    "три.листник", 0,   50},
                        {XWindow - 60, 415, 0, NULL, NULL, color, tan_atan,     Sin_sinc,     "син. тан.",   0,   100},
                        {XWindow - 60, 470, 0, NULL, NULL, color, Zvezd2Y,      Zvezd2X,      "Звезда2",     0,   10},
                        {XWindow - 60, 525, 0, NULL, NULL, color, EpicikloidaY, EpicikloidaX, "Эпициклоида", 0,   20}};

    Knop Kn_Pol [3]  = {{165,           30, 0, NULL, NULL, color, Pol,        NULL, "Спирограмма",      0,  8 * txPI},
                        {XWindow - 165, 30, 0, NULL, NULL, color, Pol_spiral, NULL, "Спираль3",        -50, 50},
                        {270,           30, 0, NULL, NULL, color, Liney,      NULL, "Линейная",        -50, 50}};

    Knop clean       = {60,  YWindow - 30, 0, image.Knopka_Vkl3_dly_drug, image.Knopka_Vikl3_dly_drug};

    //Knop Sohran      = {XWindow - 455,  YWindow - 30, 0, image.Knopka_Vkl3_dly_drug, image.Knopka_Vikl3_dly_drug};

    Knop Vikluch     = {XWindow - 13, YWindow - 13, 0, image.Knopka_Vikluchit};

    Knop Dvig [5]    = {{XWindow - 150, YWindow - 240, 0, image.Knopka_Vkl_vverh,    image.Knopka_Vikl_vverh,  NULL, NULL,  NULL,  NULL, 0, 0, -1, &perY},
                        {XWindow - 60,  YWindow - 150, 0, image.Knopka_Vkl_vpravo,   image.Knopka_Vikl_vpravo, NULL, NULL,  NULL,  NULL, 0, 0,  1, &perX},
                        {XWindow - 150, YWindow - 60,  0, image.Knopka_Vkl_vniz,     image.Knopka_Vikl_vniz,   NULL, NULL,  NULL,  NULL, 0, 0,  1, &perY},
                        {XWindow - 240, YWindow - 150, 0, image.Knopka_Vkl_vlevo,    image.Knopka_Vikl_vlevo,  NULL, NULL,  NULL,  NULL, 0, 0, -1, &perX},
                        {XWindow - 150, YWindow - 150, 0, image.Knopka_Vkl_na_mesto, image.Knopka_Vikl_na_mesto}};

    Knop Kn_Zoom [4] = {{XWindow / 2 - 80,  YWindow - 80, 0, image.Knopka_Plus_Vkl,      image.Knopka_Plus_Vikl,      NULL, NULL,  NULL,  NULL, 0, 0,  0.05},
                        {XWindow / 2 + 80,  YWindow - 80, 0, image.Knopka_Minus_Vkl,     image.Knopka_Minus_Vikl,     NULL, NULL,  NULL,  NULL, 0, 0, -0.05},
                        {XWindow / 2 - 160, YWindow - 80, 0, image.Knopka_Plus_Vkl_Big,  image.Knopka_Plus_Vikl_Big,  NULL, NULL,  NULL,  NULL, 0, 0,  0.5},
                        {XWindow / 2 + 160, YWindow - 80, 0, image.Knopka_Minus_Vkl_Big, image.Knopka_Minus_Vikl_Big, NULL, NULL,  NULL,  NULL, 0, 0, -0.5}};

    Knop Color [10]  = {{0, 20, 0, image.RGB_255_255_255White,   NULL, RGB(255, 255, 255)},
                        {0, 20, 0, image.RGB_0_162_232Blue,      NULL, RGB(0,   162, 232 )},
                        {0, 20, 0, image.RGB_0_255_0Green,       NULL, RGB(0,   255, 0 )},
                        {0, 20, 0, image.RGB_0_0_255Blue,        NULL, RGB(0,   0,   255)},
                        {0, 20, 0, image.RGB_163_73_163Magenta,  NULL, RGB(163, 73,  163)},
                        {0, 20, 0, image.RGB_181_230_29Green,    NULL, RGB(181, 230, 29)},
                        {0, 20, 0, image.RGB_234_222_0Yellow,    NULL, RGB(234, 222, 0 )},
                        {0, 20, 0, image.RGB_255_0_0Red,         NULL, RGB(255, 0,   0 )},
                        {0, 20, 0, image.RGB_255_43_112Pink,     NULL, RGB(255, 43,  112)},
                        {0, 20, 0, image.RGB_255_119_28Orange,   NULL, RGB(255, 119, 28)}};

    Knop_Ner Kn_Ner [11] = {{165,          YWindow - 85, 0, NULL, NULL, Krug,         20,   0, 0,  "Круг",     0, 0, color},
                           {270,           YWindow - 85, 0, NULL, NULL, Parabola_Ner, 0.25, 0, 0,  "Парабола", 0, 1, color},
                           {375,           YWindow - 85, 0, NULL, NULL, volni,        0.5,  0, 0,  "Волны",    1, 0, color},
                           {XWindow - 350, YWindow - 85, 0, NULL, NULL, korablik,     0,    0, 0,  "Кораблик", 1, 1, color},
                           {XWindow - 350, YWindow - 30, 0, NULL, NULL, smailik,      1,    0, 0,  "Смайлик",  0, 0, color},
                           {375,           YWindow - 30, 0, NULL, NULL, Mashina,      1,    0, 0,  "Машина",   0, 1, color},
                           {165,           YWindow - 30, 0, NULL, NULL, Kletki,       0.5,  0, 0,  "Клетки",   1, 1, color},
                           {270,           YWindow - 30, 0, NULL, NULL, Kletki2,      0.5,  0, 0,  "Клетки2",  1, 0, color},
                           {480,           YWindow - 30, 0, NULL, NULL, Kletki3,      1,    0, 0,  "Клетки3",  0, 0, color},
                           {480,           YWindow - 85, 0, NULL, NULL, Tipo_voln,    1,    0, 0,  "Типо Волн",0, 1, color},
                           {XWindow - 455, YWindow - 85, 0, NULL, NULL, Cheburashka,  0,    4, 13, "Чебурашка",1, 0, color}};

    Knop Mandelbr  = {XWindow - 455, YWindow - 30, 0, image.Knopka_Vkl3_dly_drug, image.Knopka_Vikl3_dly_drug, NULL, NULL, NULL, "Мандельброт"};

    Mass_Color_Kord (N_Color, Color);

    while (!GetAsyncKeyState (VK_DELETE))
        {
        txBegin ();

        //txClear ();

        // Mandelbrot (Zoom, perX, perY);

        klear  (&clean, "Очистить", Zoom, perX, perY);

        Mass_Dvig (Dvig, N_Dvig, Zoom, perX, perY);

        Mass_Color_Ris (Color, N_Color, &color, Zoom, perX, perY);

        Mass_Zoom (Kn_Zoom, N_Zoom, &Zoom, perX, perY);

        Knopka_Dvig_naMest (&Dvig [4], Zoom, &perX, 0, &perY, 0, perX, perY);

        Mandelbrot (&Mandelbr, perX, perY);

        //Knopka_Sohranit (&Sohran, "Сохранить", Zoom, perX, perY);

        Mass_Ob_Kn (Kn_ob, Kn_obN, color, Zoom, image, perX, perY);

        Mass_Par_Kn (Kn_param, Kn_paramN, color, Zoom, image, perX, perY);

        Mass_Pol_Kord_Kn (Kn_Pol, Kn_PolN, color, Zoom, image, perX, perY);

        Mass_Nerav (Kn_Ner, Kn_NerN, color, Zoom, image, perX, perY);

        ///*******************************
        txBitBlt (txDC(), Vikluch.x - 13, Vikluch.y - 13, 25, 25, Vikluch.vkl, 0, 0);
        if (txMouseX() < Vikluch.x + 12.5 && txMouseX() > Vikluch.x - 12.5 && txMouseY() < Vikluch.y + 12.5 && txMouseY() > Vikluch.y - 12.5 && txMouseButtons() == 1)
            {
            _txExit = true;
            break;
            }
        ///*******************************

        txEnd ();
        }

    AllDeleteImage (&image);
    }

double CatX (double t)
    {
    return  - (721 * sin(t)) / 4 + 196 / 3 * sin(2 * t) - 86 / 3 * sin(3 * t) - 131 / 2 * sin(4 * t) + 477 / 14 * sin(5 * t) + 27 * sin(6 * t) - 29 / 2 * sin(7 * t) + 68 /
            5 * sin(8 * t) + 1 / 10 * sin(9 * t) + 23 / 4 * sin(10 * t) - 19 / 2 * sin(12 * t) - 85 / 21 * sin(13 * t) + 2 / 3 * sin(14 * t) + 27 / 5 * sin(15 * t) + 7 / 4 *
            sin(16 * t) + 17 / 9 * sin(17 * t) - 4 * sin(18 * t) - 1 / 2 * sin(19 * t) + 1 / 6 * sin(20 * t) + 6 / 7 * sin(21 * t) - 1 / 8 * sin(22 * t) + 1 / 3 * sin(23 * t) +
            3 / 2 * sin(24 * t) + 13 / 5 * sin(25 * t) + sin(26 * t) - 2 * sin(27 * t) + 3 / 5 * sin(28 * t) - 1 / 5 * sin(29 * t) + 1 / 5 * sin(30 * t) + (2337 * cos(t)) / 8 -
            43 / 5 * cos(2 * t) + 322 / 5 * cos(3 * t) - 117 / 5 * cos(4 * t) - 26 / 5 * cos(5 * t) - 23 / 3 * cos(6 * t) + 143 / 4 * cos(7 * t) - 11 / 4 * cos(8 * t) - 31 / 3 *
            cos(9 * t) - 13 / 4 * cos(10 * t) - 9 / 2 * cos(11 * t) + 41 / 20 * cos(12 * t) + 8 * cos(13 * t) + 2 / 3 * cos(14 * t) + 6 * cos(15 * t) + 17 / 4 * cos(16 * t) - 3 /
            2 * cos(17 * t) - 29 / 10 * cos(18 * t) + 11 / 6 * cos(19 * t) + 12 / 5 * cos(20 * t) + 3 / 2 * cos(21 * t) + 11 / 12 * cos(22 * t) - 4 / 5 * cos(23 * t) + cos(24 * t) +
            17 / 8 * cos(25 * t) - 7 / 2 * cos(26 * t) - 5 / 6 * cos(27 * t) - 11 / 10 * cos(28 * t) + 1 / 2 * cos(29 * t) - 1 / 5 * cos(30 * t);
    }

double CatY (double t)
    {
    return  - (637 * sin(t)) / 2 - 188 / 5 * sin(2 * t) - 11 / 7 * sin(3 * t) - 12 / 5 * sin(4 * t) + 11 / 3 * sin(5 * t) - 37 / 4 * sin(6 * t) + 8 / 3 * sin(7 * t) +
            65 / 6 * sin(8 * t) - 32 / 5 * sin(9 * t) - 41 / 4 * sin(10 * t) - 38 / 3 * sin(11 * t) - 47 / 8 * sin(12 * t) + 5 / 4 * sin(13 * t) - 41 / 7 * sin(14 * t) - 7 / 3 *
            sin(15 * t) - 13 / 7 * sin(16 * t) + 17 / 4 * sin(17 * t) - 9 / 4 * sin(18 * t) + 8 / 9 * sin(19 * t) + 3 / 5 * sin(20 * t) - 2 / 5 * sin(21 * t) + 4 / 3 * sin(22 * t) +
            1 / 3 * sin(23 * t) + 3 / 5 * sin(24 * t) - 3 / 5 * sin(25 * t) + 6 / 5 * sin(26 * t) - 1 / 5 * sin(27 * t) + 10 / 9 * sin(28 * t) + 1 / 3 * sin(29 * t) - 3 / 4 *
            sin(30 * t) - (125 * cos(t)) / 2 - 521 / 9 * cos(2 * t) - 359 / 3 * cos(3 * t) + 47 / 3 * cos(4 * t) - 33 / 2 * cos(5 * t) - 5 / 4 * cos(6 * t) + 31 / 8 * cos(7 * t) +
            9 / 10 * cos(8 * t) - 119 / 4 * cos(9 * t) - 17 / 2 * cos(10 * t) + 22 / 3 * cos(11 * t) + 15 / 4 * cos(12 * t) - 5 / 2 * cos(13 * t) + 19 / 6 * cos(14 * t) + 7 / 4 *
            cos(15 * t) + 31 / 4 * cos(16 * t) - cos(17 * t) + 11 / 10 * cos(18 * t) - 2 / 3 * cos(19 * t) + 13 / 3 * cos(20 * t) - 5 / 4 * cos(21 * t) + 2 / 3 * cos(22 * t) + 1 / 4 *
            cos(23 * t) + 5 / 6 * cos(24 * t) + 3 / 4 * cos(26 * t) - 1 / 2 * cos(27 * t) - 1 / 10 * cos(28 * t) - 1 / 3 * cos(29 * t) - 1 / 19 * cos(30 * t);
    }

double Parabola (double x)
    {
    return x * x;
    }

double Liney (double x)
    {
    return x;
    }

double f_9_delit_x (double x)
    {
    return 9 / x;
    }

double f_1delit_x_umnogit_x_minus_9 (double x)
    {
    return 1 / (x * x - 9);
    }

double sqrt_xplus2_plus_s_xminus2 (double x)
    {
    return sqrt((x + 2) * (x + 2)) + sqrt((x - 2) * (x - 2));
    }

double prer_pryam (double x)
    {
    return abs(x - 1) * (x * x - 4) / (x - 1);
    }

double diagr (double x)
    {
    return (1 + sin (9 * x)) * (1 + sin(x)) * (1 + 0.03 * sin(45 * x)) * (1 + 0.04 * sin(9 * 33 * x));
    }

double t_umnog_sin(double t)
    {
    return t * sin(t);
    }

double t_umnog_cos(double t)
    {
    return t * cos(t);
    }

double zvez_cos(double t)
    {
    return (cos(t) + cos(1.1 * t) / (1.1));
    }

double zvez_sin(double t)
    {
    return (sin(t) - sin(1.1 * t) / (1.1));
    }

double Babochka_sin (double t)
    {
    return sin(t) * (exp(cos(t)) - 2 * cos(4 * t) + pow(sin(t / 12), 5));
    }

double Babochka_cos (double t)
    {
    return cos(t) * (exp(cos(t)) - 2 * cos(4 * t) + pow(sin(t / 12), 5));
    }

double tochki (double x)
    {
    return (1 + sin(x)) * (1 + 0.9 * cos(8 * x))*(1 + 0.1 * cos(24 * x)) * (1 + 0.8 * tan (16 * x));
    }

double NeoidX (double t)
    {
    return cos(t) * (2 * t + 1);
    }

double NeoidY (double t)
    {
    return sin(t) * (2 * t + 1);
    }

double cochleoidX (double t)
    {
    return sinc(t)*cos(t);
    }

double cochleoidY (double t)
    {
    return sinc(t)*sin(t);
    }

double tri_listX (double t)
    {
    return sinc2(t) * cos(t);
    }

double tri_listY (double t)
    {
    return sinc2(t) * sin(t);
    }

double tan_atan (double t)
    {
    return atan (t) * tan (t);
    }

double Sin_sinc (double t)
    {
    return sinc2 (t) * sin (t);
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

double theta (double x)
    {
    if (x > 0)      return 1;
    else if (x < 0) return 0;
    else            return 0.5;
    }

double sgn (double x)
    {
         if (x < 0) return -1;
    else if (x > 0) return 1;
               else return 0;
    }

double sad (double x)
    {
    return mod (mod (mod (mod (mod (x) - 1) - 2) - 3) - 4);
    }

double Zvezd2X (double t)
    {
    return 24.8 * (cos (t) + cos (6.2 * t) / 6.2);
    }

double Zvezd2Y (double t)
    {
    return 24.8 * (sin (t) - sin (6.2 * t) / 6.2);
    }

double Kardiogr (double x)
    {
    return sin (x) + cos (sqrt (3) * x);
    }

double SQRT (double x)
    {
    return sqrt (abs(x));
    }

double Holmi (double x)
    {
    return sin (cos (x)) + cos (tan (x)) + tan (sin (x));
    }

double Pol (double alfa)
    {
    return sin(7 * alfa / 4)/**2 * ((sin (alfa) * sqrt (abs (cos (alfa)))) / (sin (90 * alfa) + 1.5) - (sin (alfa) + 1) / 0.55)*/;
    }

double serdce (double x)
    {
    return  -txPI * pow (mod(4 - x * x), 1 / 100) / 4 + sqrt (mod (x)) + sqrt (mod (cos (x))) * cos (200 * x);
    }

double Pol_spiral (double a)
    {
    return a*a;
    }

double mod (double x)
    {
    if (x < 0) return -x;
    else       return x;
    }

double Chtoto (double x)
    {
    return log (mod (2 - 2*sin (x) + (sin (x) * sqrt (mod (cos (x)))) / (sin (x) + 1.4)));
    }

double EpicikloidaX (double x)
    {
    return 6.2 * (cos (x) - cos (3.1 * x) / 3.1);
    }

double EpicikloidaY (double x)
    {
    return 6.2 * (sin (x) - sin (3.1 * x) / 3.1);
    }

void AllImage (AllIzobr * Image)
    {
    Image->Knopka_Vkl_dly_ob_gr        = txLoadImage ("Image//Knopka_Vkl_dly_ob_gr.bmp");
    Image->Knopka_Vikl_dly_ob_gr       = txLoadImage ("Image//Knopka_Vikl_dly_ob_gr.bmp");
    Image->Knopka_Vkl_dly_pol_kord_gr  = txLoadImage ("Image//Knopka_Vkl_dly_pol_kord_gr.bmp");
    Image->Knopka_Vikl_dly_pol_kord_gr = txLoadImage ("Image//Knopka_Vikl_dly_pol_kord_gr.bmp");
    Image->Knopka_Vkl2_dly_par_gr      = txLoadImage ("Image//Knopka_Vkl2_dly_par_gr.bmp");
    Image->Knopka_Vikl2_dly_par_gr     = txLoadImage ("Image//Knopka_Vikl2_dly_par_gr.bmp");
    Image->Knopka_Vkl_dly_ner          = txLoadImage ("Image//Knopka_Vkl_dly_ner.bmp");
    Image->Knopka_Vikl_dly_ner         = txLoadImage ("Image//Knopka_Vikl_dly_ner.bmp");
    Image->Knopka_Vkl3_dly_drug        = txLoadImage ("Image//Knopka_Vkl3_dly_drug.bmp");
    Image->Knopka_Vikl3_dly_drug       = txLoadImage ("Image//Knopka_Vikl3_dly_drug.bmp");
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
    Image->RGB_255_255_255White        = txLoadImage ("Image//RGB_255_255_255White.bmp");
    Image->RGB_0_162_232Blue           = txLoadImage ("Image//RGB_0_162_232Blue.bmp");
    Image->RGB_0_255_0Green            = txLoadImage ("Image//RGB_0_255_0Green2.bmp");
    Image->RGB_0_0_255Blue             = txLoadImage ("Image//RGB_0_0_255Blue2.bmp");
    Image->RGB_163_73_163Magenta       = txLoadImage ("Image//RGB_163_73_163Magenta.bmp");
    Image->RGB_181_230_29Green         = txLoadImage ("Image//RGB_181_230_29Green.bmp");
    Image->RGB_234_222_0Yellow         = txLoadImage ("Image//RGB_234_222_0Yellow.bmp");
    Image->RGB_255_0_0Red              = txLoadImage ("Image//RGB_255_0_0Red.bmp");
    Image->RGB_255_43_112Pink          = txLoadImage ("Image//RGB_255_43_112Pink.bmp");
    Image->RGB_255_119_28Orange        = txLoadImage ("Image//RGB_255_119_28Orange.bmp");
    Image->Knopka_Vikluchit            = txLoadImage ("Image//Knopka_Vikluchit.bmp");
    }

void AllDeleteImage (AllIzobr * Image)
    {
    txDeleteDC (Image->Knopka_Vkl_dly_ob_gr);
    txDeleteDC (Image->Knopka_Vikl_dly_ob_gr);
    txDeleteDC (Image->Knopka_Vkl2_dly_par_gr);
    txDeleteDC (Image->Knopka_Vikl2_dly_par_gr);
    txDeleteDC (Image->Knopka_Vkl_dly_pol_kord_gr);
    txDeleteDC (Image->Knopka_Vikl_dly_pol_kord_gr);
    txDeleteDC (Image->Knopka_Vkl_dly_ner);
    txDeleteDC (Image->Knopka_Vikl_dly_ner);
    txDeleteDC (Image->Knopka_Vkl3_dly_drug);
    txDeleteDC (Image->Knopka_Vikl3_dly_drug);
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
    txDeleteDC (Image->RGB_255_255_255White);
    txDeleteDC (Image->RGB_0_162_232Blue);
    txDeleteDC (Image->RGB_0_255_0Green);
    txDeleteDC (Image->RGB_0_0_255Blue);
    txDeleteDC (Image->RGB_163_73_163Magenta);
    txDeleteDC (Image->RGB_181_230_29Green);
    txDeleteDC (Image->RGB_234_222_0Yellow);
    txDeleteDC (Image->RGB_255_0_0Red);
    txDeleteDC (Image->RGB_255_43_112Pink);
    txDeleteDC (Image->RGB_255_119_28Orange);
    txDeleteDC (Image->Knopka_Vikluchit);
    }

void Grafik (COLORREF color, func_t* f, double Zoom, double perX, double perY, double c /*= 1*/, double d /*=0*/)
    {
    txSetColor (color, 2);
    double x = -XWindow / (2 * Zoom);
    while (x <= +XWindow / (2 * Zoom))
        {
        double y = c * f (x) + d;

        txCircle (x * Zoom + XWindow / 2 + perX, -y * Zoom + YWindow / 2 + perY, 1);
        //txLine (xy_Old.x * Zoom + a / 2, -xy_Old.y * Zoom + b / 2, xy.x * Zoom + a / 2, -xy.y * Zoom + b / 2);

        if (x > 0.01 || x < -0.02)
            {
            x += 0.001;
            }

        else
            {
            x = 0.02;
            }

        if (x <= -2.98 && x >= - 3.02)
            {
            x = - 2.97;
            }

        if (x >= 2.98 && x <= 3.02)
            {
            x = 3.03;
            }

        if (x > 3.02 || x < -3.02)
            {
            x += 0.001;
            }

        if (x < 2.98 && x > -2.98)
            {
            x += 0.001;
            }

        if (x >= 0.99 && x < 1.01)
            {
            x = 1.02;
            }
        //txSleep (0);
        }
    }

void Grafik_Parametr (COLORREF color, func_t* f1, func_t* f2, double kol_bo_pi2, double kol_bo_pi, double Zoom, double PerX, double PerY, double c /*= 1*/, double d /*=0*/)
    {
    txSetFillColor (color);
    txSetColor (color);
    double t = -kol_bo_pi2 * txPI;

    while (t <= kol_bo_pi * txPI)
        {
        double y = c * f1(t) + d;
        double x = c * f2(t) + d;

        txCircle (x * Zoom + XWindow / 2 + PerX, -y * Zoom + YWindow / 2 + PerY, 1);

        t += 0.002;

        //txSleep (0);
        }
    }

void Grafik_V_Pol_Korsd (COLORREF color, func_t* f, double h, double t, double Zoom, double PerX, double PerY, double c, double d)
    {
    txSetFillColor (color);
    txSetColor (color);
    double alfa = h;
    while (alfa < t)
        {
        double r = c * f (alfa) + d;
        double x = r * cos (alfa);
        double y = r * sin (alfa);

        txCircle (x * Zoom + XWindow / 2 + PerX, -y * Zoom + YWindow / 2 + PerY, 1);

        if (t < 90 * txPI)
            {
            alfa += 0.001;
            }
        else
            {
            alfa += 0.002;
            }
        }
    }

void Neravenstvo (double Zoom, COLORREF color, ner_t* nerav, double a, double b, double c, double shagX, double shagY, double perX, double perY)
    {
    for (double y = -YWindow / (2 * Zoom); y <= YWindow / (2 * Zoom); y += 2 / Zoom)
        {
        for (double x = -XWindow / (2 * Zoom); x <= XWindow / (2 * Zoom); x += 2 / Zoom)
            {
            if (nerav (x, y, a, b, c) == true)
                {
                txSetPixel (x * Zoom + XWindow/2 + perX + shagX, -y * Zoom + YWindow / 2 + perY + shagY, color);
                }
            }
        }
    }

void text (const char * text, double x, double y)
    {
    txSelectFont ("Comic Sans MS", 15, 7, 0, false, false, false, 0);
    txTextOut (x, y, text);
    }

void Setka (double zoom, double a, double b, double PerX, double PerY)
    {
    txBegin ();

    txSetFillColor (TX_BLACK);
    txClear ();

    /*double x = XWindow / 2, y = YWindow / 2;

    txSetColor (TX_WHITE);

    while (x < XWindow / zoom)
        {
        txLine (x * zoom / 2, 0, x * zoom / 2, YWindow);
        x++;
        }

    x = a / 2;
    while (x > 0)
        {
        txLine (x * zoom / 2, 0, x * zoom / 2, YWindow);
        x--;
        }

    while (y < YWindow / zoom)
        {
        txLine (0, y * zoom / 2, XWindow, y * zoom / 2);
        y++;
        }

    while (y > 0)
        {
        txLine (0, y * zoom / 2, XWindow, y * zoom / 2);
        y--;
        }
       */
    txSetColor (TX_WHITE, 3);
    txLine (0, b / 2, XWindow, b / 2);
    txLine (a / 2, 0, a / 2, YWindow);
    txLine (XWindow, b / 2, XWindow - 30, b / 2 - 15);
    txLine (XWindow, b / 2, XWindow - 30, b / 2 + 15);
    txLine (a / 2, 0, a / 2 + 15, 30);
    txLine (a / 2, 0, a / 2 - 15, 30);

    txEnd ();
    }

void Mandelbrot (Knop * Kn, double perX, double perY)
    {
    HDC dc = NULL;

    if (txMouseX() < Kn->x + 50 && txMouseX() > Kn->x - 50 && txMouseY() < Kn->y + 25 && txMouseY() > Kn->y - 25)
        {
        if (txMouseButtons() == 1)
            {
            system ("Mandelbrot.exe");
            }
        if (txMouseButtons() == 3)
            {
            Kn->x = txMouseX();
            Kn->y = txMouseY();
            Setka (Kn->Zoom, XWindow, YWindow, perX, perY);
            }
        dc = Kn->vkl;
        }
    else
        {
        dc = Kn->vikl;
        }
    txBitBlt (txDC(), Kn->x - 50, Kn->y - 25, 100, 50, dc, 0, 0);
    txSetColor (TX_BLACK);
    text (Kn->tekst, Kn->x - 43, Kn->y - 17);
    }

void Knopka (Knop * Kn, double perX, double perY, double um, double pl)
    {
    HDC dc = NULL;

    if (txMouseX() < Kn->x + 50 && txMouseX() > Kn->x - 50 && txMouseY() < Kn->y + 25 && txMouseY() > Kn->y - 25)
        {
        if (txMouseButtons() == 1)
            {
            Grafik (Kn->color, Kn->func1, Kn->Zoom, perX, perY, um, pl);
            }
        if (txMouseButtons() == 2)
            {
            Grafik_V_Pol_Korsd (Kn->color, Kn->func1, Kn->kolvo_pi_min, Kn->kolvo_pi_max, Kn->Zoom, perX, perY, um, pl);
            }
        if (txMouseButtons() == 3)
            {
            Kn->x = txMouseX();
            Kn->y = txMouseY();
            Setka (Kn->Zoom, XWindow, YWindow, perX, perY);
            }
        dc = Kn->vkl;
        }
    else
        {
        dc = Kn->vikl;
        }
    txBitBlt (txDC(), Kn->x - 50, Kn->y - 25, 100, 50, dc, 0, 0);
    txSetColor (TX_BLACK);
    text (Kn->tekst, Kn->x - 43, Kn->y - 17);
    }

void klear (Knop * Kn, const char* tekst, double Zoom, double PerX, double PerY)
    {
    HDC dc = NULL;

    if (txMouseX() < Kn->x + 50 && txMouseX() > Kn->x - 50 && txMouseY() < Kn->y + 25 && txMouseY() > Kn->y - 25)
        {
        if (txMouseButtons() == 1)
            {
            Setka (Zoom, XWindow, YWindow, PerX, PerY);
            }
        if (txMouseButtons() == 3)
            {
            Kn->x = txMouseX();
            Kn->y = txMouseY();
            Setka (Zoom, XWindow, YWindow, PerX, PerY);
            }
        dc = Kn->vkl;
        }
    else
        {
        dc = Kn->vikl;
        }
    txBitBlt (txDC(), Kn->x - 50, Kn->y - 25, 100, 50, dc, 0, 0/*, 1*/);
    txSetColor (TX_BLACK);
    text (tekst, Kn->x - 43, Kn->y - 17);
    }

void Knopka_Par (Knop * Kn, double PerX, double PerY, double um, double pl)
    {
    HDC dc = NULL;

    if (txMouseX() < Kn->x + 50 && txMouseX() > Kn->x - 50 && txMouseY() < Kn->y + 25 && txMouseY() > Kn->y - 25)
        {
        if (txMouseButtons() == 1)
            {
            Grafik_Parametr (Kn->color, Kn->func1, Kn->func2, Kn->kolvo_pi_min, Kn->kolvo_pi_max, Kn->Zoom, PerX, PerY, um, pl);
            }
        if (txMouseButtons() == 3)
            {
            Kn->x = txMouseX();
            Kn->y = txMouseY();
            Setka (Kn->Zoom, XWindow, YWindow, PerX, PerY);
            }
        dc = Kn->vkl;
        }
    else
        {
        dc = Kn->vikl;
        }
    txBitBlt (txDC(), Kn->x - 50, Kn->y - 25, 100, 50, dc, 0, 0/*, 1*/);
    txSetColor (TX_BLACK);
    text (Kn->tekst, Kn->x - 43, Kn->y - 17);
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
            Setka (Kn->Zoom, XWindow, YWindow, PerX, PerY);
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
            Setka (Zoom, XWindow, YWindow, PerX, PerY);
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
            Setka (*Zoom, XWindow, YWindow, PerX, PerY);
            }
        dc = Kn->vkl;
        }
    else
        {
        dc = Kn->vikl;
        }
    txBitBlt (txDC(), Kn->x - 37.5, Kn->y - 37.5, 75, 75, dc, 0, 0/*, 1*/);
    }

void Knopka_Color (Knop* Kn, double Zoom, COLORREF* color, double PerX, double perY)
    {
    if (txMouseX() < Kn->x + 15 && txMouseX() > Kn->x - 15 && txMouseY() < Kn->y + 15 && txMouseY() > Kn->y - 15)
        {
        if (txMouseButtons() == 1)
            {
            *color = Kn->color;
            }
        if (txMouseButtons() == 3)
            {
            Kn->x = txMouseX();
            Kn->y = txMouseY();
            Setka (Zoom, XWindow, YWindow, PerX, perY);
            }
        }
    txBitBlt (txDC(), Kn->x - 15, Kn->y - 15, 30, 30, Kn->vkl, 0, 0);
    }

void Knopka_Pol_Kord (Knop * Kn, double PerX, double PerY, double um, double pl)
    {
    HDC dc = NULL;

    if (txMouseX() < Kn->x + 50 && txMouseX() > Kn->x - 50 && txMouseY() < Kn->y + 25 && txMouseY() > Kn->y - 25)
        {
        if (txMouseButtons() == 1)
            {
            Grafik_V_Pol_Korsd (Kn->color, Kn->func1, Kn->kolvo_pi_min, Kn->kolvo_pi_max, Kn->Zoom, PerX, PerY, um, pl);
            }
        if (txMouseButtons() == 3)
            {
            Kn->x = txMouseX();
            Kn->y = txMouseY();
            Setka (Kn->Zoom, XWindow, YWindow, PerX, PerY);
            }
        dc = Kn->vkl;
        }
    else
        {
        dc = Kn->vikl;
        }
    txBitBlt (txDC(), Kn->x - 50, Kn->y - 25, 100, 50, dc, 0, 0/*, 1*/);
    txSetColor (TX_BLACK);
    text (Kn->tekst, Kn->x - 43, Kn->y - 17);
    }

void Knopka_Nerav (Knop_Ner* Kn, double perX, double perY)
    {
    HDC dc = NULL;

    if (txMouseX() < Kn->x + 50 && txMouseX() > Kn->x - 50 && txMouseY() < Kn->y + 25 && txMouseY() > Kn->y - 25)
        {
        if (txMouseButtons() == 1)
            {
            Neravenstvo (Kn->Zoom, Kn->color, Kn->ner, Kn->a, Kn->b, Kn->c, Kn->shagX, Kn->shagY, perX, perY);
            }
        if (txMouseButtons() == 3)
            {
            Kn->x = txMouseX();
            Kn->y = txMouseY();
            Setka (Kn->Zoom, XWindow, YWindow, perX, perY);
            }
        dc = Kn->vkl;
        }
    else
        {
        dc = Kn->vikl;
        }
    txBitBlt (txDC(), Kn->x - 50, Kn->y - 25, 100, 50, dc, 0, 0/*, 1*/);
    txSetColor (TX_BLACK);
    text (Kn->tekst, Kn->x - 43, Kn->y - 17);
    }

/*void Knopka_Sohranit (Knop * Kn, const char* tekst, double Zoom, double PerX, double PerY)
    {
    HDC dc = NULL;

    if (txMouseX() < Kn->x + 50 && txMouseX() > Kn->x - 50 && txMouseY() < Kn->y + 25 && txMouseY() > Kn->y - 25)
        {
        if (txMouseButtons() == 1)
            {
            HDC save = txCreateCompatibleDC (XWindow, YWindow);
            txBitBlt (save, 0, 0, XWindow, YWindow, txDC(), 0, 0, NOTSRCCOPY);
            txDeleteDC (save);
            }
        if (txMouseButtons() == 3)
            {
            Kn->x = txMouseX();
            Kn->y = txMouseY();
            Setka (Zoom, XWindow, YWindow, PerX, PerY);
            }
        dc = Kn->vkl;
        }
    else
        {
        dc = Kn->vikl;
        }
    txBitBlt (txDC(), Kn->x - 50, Kn->y - 25, 100, 50, dc, 0, 0);
    txSetColor (TX_BLACK);
    text (tekst, Kn->x - 43, Kn->y - 17);
    }*/

void Mass_Color_Kord (int N_Color, Knop Color[])
    {
    double h = -135;
    int i = 0;
    while (i < N_Color && h <= 135)
        {
        Color[i].x = XWindow / 2 - h;
        h += 30;
        i++;
        }
    }

void Mass_Color_Ris (Knop Color[], int N_Color, COLORREF* color, double Zoom, double perX, double perY)
    {
    int i = 0;
    while (i < N_Color)
        {
        Knopka_Color (&Color[i], Zoom, color, perX, perY);
        i++;
        }
    }

void Mass_Ob_Kn (Knop Kn_ob[], int Kn_obN, COLORREF color, double Zoom, AllIzobr image, double perX, double perY)
    {
    int i = 0;
    while (i < Kn_obN)
        {
        Kn_ob[i].vkl  = image.Knopka_Vkl_dly_ob_gr;
        Kn_ob[i].vikl = image.Knopka_Vikl_dly_ob_gr;
        Kn_ob[i].Zoom = Zoom;
        Kn_ob[i].color = color;
        Knopka (&Kn_ob[i], perX, perY);
        i++;
        }
    }

void Mass_Par_Kn (Knop Kn_param[], int Kn_paramN, COLORREF color, double Zoom, AllIzobr image, double perX, double perY)
    {
    int i = 0;
    while (i < Kn_paramN)
        {
        Kn_param[i].vkl = image.Knopka_Vkl2_dly_par_gr;
        Kn_param[i].vikl = image.Knopka_Vikl2_dly_par_gr;
        Kn_param[i].Zoom = Zoom;
        Kn_param[i].color = color;
        Knopka_Par (&Kn_param[i], perX, perY);
        i++;
        }
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

void Mass_Pol_Kord_Kn (Knop Kn_Pol[], int Kn_PolN, COLORREF color, double Zoom, AllIzobr image, double perX, double perY)
    {
    for (int i = 0; i < Kn_PolN; i++)
        {
        Kn_Pol[i].vkl   = image.Knopka_Vkl_dly_pol_kord_gr;
        Kn_Pol[i].vikl  = image.Knopka_Vikl_dly_pol_kord_gr;
        Kn_Pol[i].Zoom  = Zoom;
        Kn_Pol[i].color = color;
        Knopka_Pol_Kord (&Kn_Pol[i], perX, perY);
        }
    }

void Mass_Nerav (Knop_Ner Kn_Ner[], int Kn_NerN, COLORREF color, double Zoom, AllIzobr image, double perX, double perY)
    {
    for (int i = 0; i < Kn_NerN; i++)
        {
        Kn_Ner[i].vkl  = image.Knopka_Vkl_dly_ner;
        Kn_Ner[i].vikl = image.Knopka_Vikl_dly_ner;
        Kn_Ner[i].Zoom = Zoom;
        Kn_Ner[i].color = color;
        Knopka_Nerav (&Kn_Ner[i], perX, perY);
        }
    }

bool Parabola_Ner (double x, double y, double a, double b, double c)
    {
    if (y >=  a * x * x) return true;
    else                 return false;
    }

bool Krug (double x, double y, double a, double b, double c)
    {
    if (x * x + y * y <= a) return true;
    else                    return false;
    }

bool volni (double x, double y, double a, double b, double c)
    {
    if (sin (x) < a * tan (y)) return true;
    else                   return false;
    }

bool korablik (double x, double y, double a, double b, double c)
    {
    if (-mod(cos (x + a)) >= y + 5 ||
        -mod(5 * (x + 25)) + 3 >= y + a ||
        y + 5 + a >= -5 * (x + 10) && y + 5 + a < 10 && y + 5 + a >= 15 * (x - 20) ||
        y + 4 + a <= 15 * (x - 7) && y + 4 + a < 15 && y + 4 + a >= 15 * (x - 14) ||
        y - 9 + a <= -mod(5 * (x)) || (x) * (x) + (y - 9 + a) * (y - 9 + a) <= 1 ||
        (x - 15) * (x - 15) + (y - 14 + a) * (y - 14 + a) <= 2.5 || (x - 18) * (x - 18) + (y - 17 + a) * (y - 17 + a) <= 3)
         {
         return true;
         }
    else return false;
    }

bool smailik (double x, double y, double a, double b, double c)
    {
    if (0.15 * a * x * x <= y + 10 && 0.075 * a * x * x >= y + 5 ||
        (x - 5) * (x - 5) + (y - 6) * (y - 6) <= 2 * a || (x + 5) * (x + 5) + (y - 6) * (y - 6) <= 2 * a ||
        -mod(2 * a * x) + 4 >= y && y > 1 ||
        x * x + y * y >= 120 && x * x + y * y <= 140)
         {
         return true;
         }
    else return false;
    }

bool Mashina (double x, double y, double a, double b, double c)
    {
    if (y < -3 || (x + 6) * (x + 6) + (y + 1.5) * (y + 1.5) <= 3 || (x - 6) * (x - 6) + (y + 1.5) * (y + 1.5) <= 3 ||
        y > - 0.5 && y <= 5 * (x + 9) && y <= -10 * (x - 9) && y < 2.5 ||
        y >= 2.5 && y <= 2.5 * (x + 6) && y <= -5 * (x - 7) && y < 5)
        {
        return true;
        }
    else
        {
        return false;
        }
    }

bool Kletki (double x, double y, double a, double b, double c)
    {
    if (tan(y) / atan (x) * tan(x) / atan(y) >= a * x * y)
         {
         return true;
         }
    else return false;
    }

bool Kletki2 (double x, double y, double a, double b, double c)
    {
    if (sin(y) / cos (x) * sin(x) / cos(y) <= a * x * y)
         {
         return true;
         }
    else return false;
    }

bool Kletki3 (double x, double y, double a, double b, double c)
    {
    if (sinc2(y) / sinc(x) * sinc2(x) / sinc(y) <= a * x * y)
        {
        return true;
        }
    else return false;
    }

bool Tipo_voln (double x, double y, double a, double b,  double c)
    {
    if (cos(y) / sinc2(x) * tan(x) / atan(y) <= a * sin(x) * sinc(y))
        {
        return true;
        }
    else return false;
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

/*void Mandelbrot (double Zoom, double perX, double perY)
    {
    double x_Old = 0, y_Old = 0;
    double x_New = 0, y_New = 0;
    COLORREF color = TX_BLACK;

    for (double x0 = -2; x0 < 1.5; x0 += 1 / Zoom)
        {
        for (double y0 = -1; y0 < 1; y0 += 1 / Zoom)
            {
            x_Old = x0;
            y_Old = y0;

            for (double n = 0; n < 250; n++)
                {
                x_New = x_Old * x_Old - y_Old * y_Old + x0;
                y_New = 2 * x_Old * y_Old + y0;

                color = RGB(n / 5, n / 2.5, n);

                if (sqrt (x_New * x_New + y_New * y_New) >= 50)
                    {
                    break;
                    }

                x_Old = x_New;
                y_Old = y_New;
                }
            txSetPixel (x0 * Zoom + perX + XWindow / 2, -y0 * Zoom + perY + YWindow / 2, color);
            }
        }
    }
*/
