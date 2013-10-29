#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
const int TOTAL_CARTES = 54;
const int NB_COULEURS = 6; // ROUGE, JAUNE, VERT, BLEU, NOIR, MARRON.
const int CARTES_PAR_COULEUR = 9;
const int NB_BORNES = 9;

struct t_carte
{
    int num_carte;
    string couleur;
};
typedef t_carte t_pioche [TOTAL_CARTES];
typedef t_carte t_hand [6]; // main des joueurs.


typedef t_hand t_tableau_hand[2];

void initialisation_pioche(t_pioche pioche);
int distribution_pioche_debut (t_pioche , t_tableau_hand, int);

t_carte distribution_pioche (t_pioche, int);

// BORNES
typedef t_carte t_tableau_cartes [3];
struct t_zone_borne
{
    t_tableau_cartes tableau_cartes;
    int nbre_cartes;
};
typedef t_zone_borne t_zones_borne [2];
struct t_borne
{
    t_zones_borne zones_borne;
    int possession;
};
typedef t_borne t_BORNES[NB_BORNES];

// PSEUDO AFFICHAGE
void affichage(t_tableau_hand, t_BORNES);

// DECISONS JOUEURS
void initialisation_bornes (t_BORNES);
bool choix_borne (t_BORNES , int, t_tableau_hand, int, int );

void recevoir_carte (t_pioche, t_tableau_hand, int, int);

// REVENDICATION

    bool reperage_revendication (t_BORNES, int, int);

    // Comparaison
    int comparaison (t_borne, int);
    int force_combinaison (t_tableau_cartes);

    // Tri des cartes
    void tri (t_tableau_cartes);
    void permuter (t_tableau_cartes, int);

    // Booleens
    bool meme_couleur (t_tableau_cartes);
    bool consecutives (t_tableau_cartes);
    bool meme_valeur (t_tableau_cartes);
    int departager (t_tableau_cartes, t_tableau_cartes, int);

// FIN DU JEU
int conditions_victoire (t_BORNES);

// IA
    // IA random
        struct t_choix_IA
    {
        int num_carte_choisie;
        int num_borne_choisie;
    };
    t_choix_IA IA_rand (t_BORNES, int, t_tableau_hand);

    // IA BRELAN
    typedef float t_tableau_proba[9];
    void permuter_hand (t_hand);
    void tri_hand (t_hand);
    int proba_brelan(t_BORNES,int, t_tableau_hand, int);
    t_choix_IA IA_brelan (t_BORNES, int, t_tableau_hand);











