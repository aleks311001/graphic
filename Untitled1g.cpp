
#include "TXLib.h"

int main()
    {
    txCreateWindow (1000, 600);

    int *fibbon = new int [50];
    memset (fibbon, 0, 50* sizeof (*fibbon));
    int i = 0;

    fibbon [0] = 1;
    fibbon [1] = 1;

    while (i < 48)
        {
        fibbon [i + 2] = fibbon [i] + fibbon [i + 1];
        printf ("%d,  ", fibbon [i]);
        i++;
        }

    return 0;
    }
