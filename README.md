Bornes-Ecossaises
=================

TA - Shotten Toten
bon je comprend pas trpo comment ça marche... je vais mettre l'IA pour voir ce que ça donne :

#include <cstdlib>
#include <cmath>
#include "Def.h"

// IA RANDOM
t_choix_IA IA_rand(t_BORNES bornes, int num_player, t_tableau_hand hands)
{
    t_choix_IA choix_IA;
    int num_carte_choisie, num_borne_choisie;
    int avant_arriere = rand()%2;

    num_carte_choisie = rand()%6 + 1;
    while (hands[num_player][num_carte_choisie - 1].num_carte == 0)
    {
        if (avant_arriere == 0) num_carte_choisie = num_carte_choisie%6 + 1;
        else num_carte_choisie = (num_carte_choisie + 4)%6 + 1;  // le + 4 au lieu de -2 pour les mêmes raisons que pour le choix de la borne.
    }
    num_borne_choisie = rand()%9 + 1;
    while (bornes[num_borne_choisie - 1].zones_borne[num_player].nbre_cartes == 3)
    {
        if (avant_arriere == 0) num_borne_choisie = num_borne_choisie%9 + 1; 
        // on parcourt les bornes vers la droite.
        else num_borne_choisie = (num_borne_choisie + 7)%9 + 1; // Et là vers la gauche. (-2%9 != 7, donc on ajoute 9 pour reser positif)
    }
    choix_borne(bornes, num_player, hands, num_carte_choisie - 1, num_borne_choisie - 1);
    choix_IA.num_borne_choisie = num_borne_choisie;
    choix_IA.num_carte_choisie = num_carte_choisie;
    return choix_IA;
}
/*
    cartes_pas utiles n'a pas besoind d'être réinitialisé à chaque fois...
*/
// IA BRELAN
    // Donne la carte ayant la plus grande probabilité de donner un brelan. (donne la valeur de la carte.)
    // doit prendre en compte les cartes déjà jouées de SON coté....
    int proba_brelan (t_BORNES bornes, t_tableau_hand hands, int num_player)
    {
        t_tableau_proba tableau_proba;
        int compte_cartes_utiles[9];
        int compte_cartes_pas_utiles[9];
        int ncir[9]; // Nombre Cartes Interessantes Restantes
        int i,j,k, valeur_best_proba = 1;
        float maximum;

        t_hand hand_trie = hands[num_player];

        for (i=0; i<9; i++)
        {
            tableau_proba[i] = 0;
            compte_cartes_utiles[i] = 0;
            compte_cartes_pas_utiles[i] = 0;
        }

        tri_hand (hand_trie);

        for (i=0; i<6; i++) compte_cartes_utiles[(hand_trie[i].num_carte) - 1] ++;
        //for (i=0; i<9; i++) cout << compte_cartes_utiles[i] << endl;
        for (j=0; j<2; j++)
        {
            for (i=0; i<9; i++)
            {
                for (k=0; k<bornes[i].zones_borne[j].nbre_cartes; k++)
                {
                if (j == num_player)
                {
                    if (bornes[i].zones_borne[num_player].nbre_cartes == 3 ||
                        compte_cartes_utiles[bornes[i].zones_borne[num_player].tableau_cartes[k].num_carte - 1] == 0)
                        // les cartes ne sont pas "utilisables" si la borne du joueur est pleine ou si il n'y a pas de cartes de même valeur dans la main du joueur.
                    {
                        compte_cartes_pas_utiles[bornes[i].zones_borne[j].tableau_cartes[k].num_carte - 1] ++;
                    }
                    else
                    {
                        compte_cartes_utiles[bornes[i].zones_borne[num_player].tableau_cartes[k].num_carte - 1] ++; // ces cartes sont à prendre en comtpe dans les probas.
                        //cout << "+ 1 en utile pour la valeur : " << i << " " << j << " " << k << endl;
                    }
                }
                else  compte_cartes_pas_utiles[bornes[i].zones_borne[j].tableau_cartes[k].num_carte - 1] ++;
                }
            }
        }
        //cout << endl;
        //for (i=0; i<9; i++) cout << compte_cartes_utiles[i] << endl;

        //for (i=0; i<9; i++) cout << "carte utile " << i << " = " << compte_cartes_utiles[i] << endl;
        //for (i=0; i<9; i++) cout << compte_cartes_utiles[i] << endl;
        for (i=0; i<9; i++)
        {
            ncir[i] = 9 - compte_cartes_utiles[i] - compte_cartes_pas_utiles[i];
            switch (compte_cartes_utiles[i])
            {
            case 0 :
                tableau_proba[i] = 0;
                break;
            case 1 :
                tableau_proba[i] = 1 - pow((float)1/2,ncir[i])*(1 + ncir[i]);
                break;
            case 2 :
                tableau_proba[i] = 1 - pow((float)1/2,ncir[i]);
                break;
            default :
                tableau_proba[i] = 1;
                break;
            }
        }
        //for (i=0; i<9; i++) cout << "proba carte " << i << " = " << tableau_proba[i] << endl;

        //on cherche la valeur de la carte ayant la proba la plus grande de donner un brelan.
        maximum = tableau_proba[0];
        for (i=1; i<9; i++)
        {
            if (max(maximum, tableau_proba[i]) != maximum)
            {
                maximum = max(maximum, tableau_proba[i]);
                valeur_best_proba = i+1;
            }
        }
        //cout << "meilleure carte = " << valeur_best_proba << endl;
        return valeur_best_proba;
    }

    void tri_hand (t_hand hand) // MOYEN D'ADAPTER L'AUTRE FONCTION DE TRI ??!
    {
        int i=0, j=0, nb_passages = 0;
        for (i=0; i<6; i++)
        {
            for (j=0; j<(5-nb_passages); j++)
            {
                if (hand[j].num_carte > hand[j+1].num_carte) permuter (hand, j);
            }
            nb_passages ++;
        }
    }

    void permuter_hand (t_hand hand, int i)
    {
        t_carte temp;
        temp = hand[i];
        hand[i] = hand[i+1];
        hand[i+1] = temp;
    }

    // choix de la borne et de la carte en fonction des probas
    t_choix_IA IA_brelan(t_BORNES bornes, int num_player, t_tableau_hand hands)
    {
        t_choix_IA choix_IA;
        int num_carte_choisie, num_borne_choisie;
        int valeur_carte_choisie = proba_brelan(bornes, hands, num_player);

        num_carte_choisie = 1;
        // on cherche la première carte de la main dont la valeur correspond à celle donnant le plus facilment un brelan.
        while (hands[num_player][num_carte_choisie - 1].num_carte != valeur_carte_choisie) num_carte_choisie++;
        choix_IA.num_carte_choisie = num_carte_choisie;

        num_borne_choisie = 1;
        // on cherche la  OK (si = 0) ou (1ere carte de meme valeur et !=3)
        // négation : PAS OK :(si != 0) et (1ere carte != ou ==3)

        // les bornes sont remplies dans l'ordre : si il y en a une non remplie avec la valeur
        // de la carte actuelle, on prend !
        while (bornes[num_borne_choisie - 1].zones_borne[num_player].nbre_cartes != 0 &&
            (bornes[num_borne_choisie - 1].zones_borne[num_player].tableau_cartes[0].num_carte != valeur_carte_choisie ||
            bornes[num_borne_choisie - 1].zones_borne[num_player].nbre_cartes == 3 ))
        {
             num_borne_choisie ++;
        }
        if (num_borne_choisie > 9)
        {
            num_borne_choisie = 1;
            while (bornes[num_borne_choisie - 1].zones_borne[num_player].nbre_cartes == 3) num_borne_choisie ++;
        }
        choix_IA.num_borne_choisie = num_borne_choisie;
        //cout << "borne : " << num_borne_choisie;
        choix_borne(bornes, num_player, hands, num_carte_choisie - 1, num_borne_choisie - 1);

        return choix_IA;
    }



