#include <iostream>
#include <cstdlib>
#include "Def.h"

using namespace std;


void initialisation_bornes (t_BORNES bornes)
{
    int i,j,k;
    t_carte carte_vide;
    carte_vide.couleur = "    "; carte_vide.num_carte = 0;

    for (i=0; i<9; i++)
    {
        for (j=0; j<2; j++)
        {
            for (k=0; k<3; k++)
            {
                bornes[i].zones_borne[j].tableau_cartes[k] = carte_vide;
                bornes[i].zones_borne[j].nbre_cartes = 0;
                bornes[i].possession = 0;
            }
        }
    }
}

bool choix_borne (t_BORNES bornes, int num_player, t_tableau_hand hands, int num_carte_choisie, int num_borne_choisie) // cette fois en comptant à partir de 0.
{
    bool nouvel_essai = false;
    t_carte carte_vide;
    carte_vide.couleur = "    "; carte_vide.num_carte = 0;

    t_carte carte_choisie;
    t_zone_borne *emplacement_borne;


    if (hands[num_player][num_carte_choisie].num_carte == 0 || num_carte_choisie > NB_COULEURS - 1
                                                            || num_carte_choisie < 0)
    {
        cout << "il n'y a pas de carte ici." << endl << endl << endl;
        nouvel_essai = true;
        cout << "carte choisie" << num_carte_choisie << endl;
        // on refera une tentative. Une boucle while ne m'inspire pas.
    }
    else if ( num_borne_choisie < 0 || num_borne_choisie > CARTES_PAR_COULEUR - 1)
    {
        cout << "Cette borne n'existe pas" << endl << endl;
        nouvel_essai = true;
    }
    else
    {
        emplacement_borne = &bornes[num_borne_choisie].zones_borne[num_player];

        int emplacement_carte = emplacement_borne->nbre_cartes;
        if (emplacement_carte < 3)
        {
        carte_choisie = hands[num_player][num_carte_choisie];
        hands[num_player][num_carte_choisie] = carte_vide;          // La carte n'est plus dans la main du joueur.

            emplacement_borne->tableau_cartes[emplacement_carte] = carte_choisie; // équivalence entre *blabla.blabla et blabla->blabla
            emplacement_borne->nbre_cartes ++;
        }
        else
        {
            cout << "il n'y a plus d'emplacement disponible sur cette borne" << endl << endl;
            nouvel_essai = true;
        }
    }
    return nouvel_essai;
}

