#include<stdlib.h>
#include <stdio.h>
#include "listeChaineeGenerique.h"
#include "coup.h"
#include "coups.h"
#include "plateau.h"

Coups Coups_creerVide()
{
	return LC_listeVide();
}

void Coups_ajouterCoup(Coups* liste, Coup aAjouter)
{
	LC_ajouter(liste, (void*)&aAjouter, sizeof(Coup));
}

Coup Coups_obtenirCoup(Coups liste, int position)
{
	return *(Coup*)LC_obtenirIemeElement(liste, position);
}

int Coups_estVide(Coups liste)
{
	return LC_estVide(liste);
}

unsigned int Coups_longueur(Coups liste)
{
	return LC_longueur(liste);
}

void Coups_libererCoups(Coups liste)
{
	LC_liberer(liste);
}
