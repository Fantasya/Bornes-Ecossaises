/* afficher a l'ecran la position courante de la partie (terrain et cartes des joueurs, les cartes
seront donc visibles par les deux joueurs) */

/* Directives d'inclusion des fichiers */
# include <string>
# include <iostream>
# include "type_def.h"
# include "pioche.h"
using namespace std ;

void affichepartie(t_Main Main1, t_Main Main2, t_Borne Borne1, t_Borne Borne2, t_Borne Borne3, t_Borne Borne4, t_Borne Borne5, t_Borne Borne6, t_Borne Borne7, t_Borne Borne8, t_Borne Borne9)
{
    cout << Main1[0].valeur << Main1[0].couleur << Main1[1].valeur << Main1[1].couleur << Main1[2].valeur << Main1[2].couleur << Main1[3].valeur << Main1[3].couleur << Main1[4].valeur << Main1[4].couleur << Main1[5].valeur << Main1[5].couleur << endl;
    cout << Borne1[0].valeur << Borne1[0].couleur << Borne2[0].valeur << Borne2[0].couleur << Borne3[0].valeur << Borne3[0].couleur << Borne4[0].valeur << Borne4[0].couleur << Borne5[0].valeur << Borne5[0].couleur << Borne6[0].valeur << Borne6[0].couleur << Borne7[0].valeur << Borne7[0].couleur << Borne8[0].valeur << Borne8[0].couleur << Borne9[0].valeur << Borne9[0].couleur << endl;
    cout << Borne1[1].valeur << Borne1[1].couleur << Borne2[1].valeur << Borne2[1].couleur << Borne3[1].valeur << Borne3[1].couleur << Borne4[1].valeur << Borne4[1].couleur << Borne5[1].valeur << Borne5[1].couleur << Borne6[1].valeur << Borne6[1].couleur << Borne7[1].valeur << Borne7[1].couleur << Borne8[1].valeur << Borne8[1].couleur << Borne9[1].valeur << Borne9[1].couleur << endl;
    cout << Borne1[2].valeur << Borne1[2].couleur << Borne2[2].valeur << Borne2[2].couleur << Borne3[2].valeur << Borne3[2].couleur << Borne4[2].valeur << Borne4[2].couleur << Borne5[2].valeur << Borne5[2].couleur << Borne6[2].valeur << Borne6[2].couleur << Borne7[2].valeur << Borne7[2].couleur << Borne8[2].valeur << Borne8[2].couleur << Borne9[2].valeur << Borne9[2].couleur << endl;
    cout <<" BORNE     BORNE      BORNE     BORNE     BORNE     BORNE     BORNE     BORNE     BORNE" <<endl;
    cout << Borne1[3].valeur << Borne1[3].couleur << Borne2[3].valeur << Borne2[3].couleur << Borne3[3].valeur << Borne3[3].couleur << Borne4[3].valeur << Borne4[3].couleur << Borne5[3].valeur << Borne5[3].couleur << Borne6[3].valeur << Borne6[3].couleur << Borne7[3].valeur << Borne7[3].couleur << Borne8[3].valeur << Borne8[3].couleur << Borne9[3].valeur << Borne9[3].couleur << endl;
    cout << Borne1[4].valeur << Borne1[4].couleur << Borne2[4].valeur << Borne2[4].couleur << Borne3[4].valeur << Borne3[4].couleur << Borne4[4].valeur << Borne4[4].couleur << Borne5[4].valeur << Borne5[4].couleur << Borne6[4].valeur << Borne6[4].couleur << Borne7[4].valeur << Borne7[4].couleur << Borne8[4].valeur << Borne8[4].couleur << Borne9[4].valeur << Borne9[4].couleur << endl;
    cout << Borne1[5].valeur << Borne1[5].couleur << Borne2[5].valeur << Borne2[5].couleur << Borne3[5].valeur << Borne3[5].couleur << Borne4[5].valeur << Borne4[5].couleur << Borne5[5].valeur << Borne5[5].couleur << Borne6[5].valeur << Borne6[5].couleur << Borne7[5].valeur << Borne7[5].couleur << Borne8[5].valeur << Borne8[5].couleur << Borne9[5].valeur << Borne9[5].couleur << endl;

    cout << Main2[0].valeur << Main2[0].couleur << Main2[1].valeur << Main2[1].couleur << Main2[2].valeur << Main2[2].couleur << Main2[3].valeur << Main2[3].couleur << Main2[4].valeur << Main2[4].couleur << Main2[5].valeur << Main2[5].couleur << endl;

};
