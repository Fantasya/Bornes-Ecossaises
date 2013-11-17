#include <iostream>
#include <cstdlib>

#include "Def.h"

using namespace std;

int conditions_victoire (t_BORNES bornes)
{
    int i = 0;
    int bornes_consecutives = 0, bornes_player_1 = 0, bornes_player_2 = 0;
    while (i<8 && bornes_consecutives < 2)
    {
        if (bornes[i].possession == bornes[i+1].possession &&
            bornes[i].possession != 0) bornes_consecutives++;
        else bornes_consecutives = 0;
        i++;
    }
    if (bornes_consecutives == 2) return bornes[i].possession; // 0 permet de continuer. Pas de pb avec les bornes non prises.
    else
    {
        i=0;
        while (i<9)
        {
            if (bornes[i].possession == 1) bornes_player_1++;
            if (bornes[i].possession == 2) bornes_player_2++;
            i++;
        }
        if (bornes_player_2 == 5) return 2;
        else if (bornes_player_1 == 5) return 1;
        else return 0;

    }
}
