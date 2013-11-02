/* 
                           BORNES-ECOSSAISES
fichier: affichage.cpp
auteur: Jordan Peltier
modifié par: Ophir LOJKINE
date de création: novembre 2013
*/

/*
J'ai modifié son code pour afficher le jeu de tel sorte que le joueur qui joue ne voie plus les cartes de l'adversaire.
C'était très simple ne vous inquiétez pas ^^ (en 5 min puisque le code de Vianney le permettait)
Alors j'ai juste changé les zone_Bornes en zones_borne. j'avais changé les définiitions et jordan a du utiliser celles d'avant^^
j'ai aussi mis les conditions uniquement à l'affichage des cartes des joueurs pour que ce soit plus compact.
*/

#include <string>
#include <iostream>
#include "Def.h"

using namespace std;


void afficher_carte (t_carte *carte) {
	if (carte == 0) {
		cout << "? ????      " ;
	} else {
		cout << carte->num_carte << " " << carte->couleur << "      " ;
	}
}

void affichage (t_tableau_hand hands, t_BORNES bornes, int num_player)
	{
	int i,j;

	cout << string(19, ' ');

	if (num_player == 0) {
		for (i=0; i<6; i++)
			cout << hands[0][i].num_carte << " " << hands[0][i].couleur << "      " ;
	}
	else {for (i=0; i<6; i++) cout << "?" << " " << "????" << "      " ;}
	for (i=0; i<3; i++) cout << endl;

	for (i=0; i<9; i++) if (bornes[i].possession == 1) cout << "   -BORNE-  " ;
		                else cout << "            ";
	for (i=0; i<3; i++) cout << endl;

	for (i=2; i>=0; i--)
	{
		for (j=0; j<9; j++) cout << "   " << bornes[j].zones_borne[0].tableau_cartes[i].num_carte << " " << bornes[j].zones_borne[0].tableau_cartes[i].couleur << "   ";
		cout << endl << endl;
	}

	for (i=0; i<2; i++) cout << endl;
	for (i=0; i<9; i++) if (bornes[i].possession == 0) cout << "   -BORNE-  " ;
		                else cout << "            ";
	for (i=0; i<4; i++) cout << endl;

	for (i=0; i<3; i++)
	{
		for (j=0; j<9; j++) cout << "   " << bornes[j].zones_borne[1].tableau_cartes[i].num_carte << " " << bornes[j].zones_borne[1].tableau_cartes[i].couleur << "   ";
		cout << endl << endl;
	}

	for (i=0; i<2; i++) cout << endl;
	for (i=0; i<9; i++) if (bornes[i].possession == 2) cout << "   -BORNE-  " ;
		                else cout << "            ";
	for (i=0; i<3; i++) cout << endl;

	cout << "                   ";

	if (num_player==0) {for (i=0; i<6; i++) cout << "?" << " " << "????" << "      ";}
	else {for (i=0; i<6; i++) cout << hands[1][i].num_carte << " " << hands[1][i].couleur << "      " ;}
	for (i=0; i<10; i++) cout << endl;
}

