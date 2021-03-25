#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "listeChaineeGenerique.h"


Noeud* LC_listeVide()
{
	return NULL;
}

int LC_estVide(Noeud* liste)
{
	return (liste == NULL);
}

void LC_fixerListeSuivante(Noeud** liste1, Noeud* liste2)
{
	(*liste1)->suivant = liste2;
}

void LC_ajouter(Noeud** liste, void* nouvelElement, size_t tailleDonnees)
{
	Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
	nouveauNoeud->element = malloc(tailleDonnees);
	LC_fixerListeSuivante(&nouveauNoeud, *liste);

	for (int i=0; i<tailleDonnees; i++)
	{
		*((char*)(nouveauNoeud->element)+i)=*((char*)(nouvelElement) + i); //Char prend un bit, cela revient donc
																	   //a copier bit par bit l'element à
																	   //ajouter
	}
	(*liste) = nouveauNoeud;
}

Noeud* LC_obtenirListeSuivante(Noeud* liste)
{
	assert(!LC_estVide(liste));
	return liste->suivant;
}

void* LC_obtenirElement(Noeud* liste)
{
	if (LC_estVide(liste))
	{
		return NULL;
	}
	else
	{
		return liste->element;
	}
}

void* LC_obtenirIemeElement(Noeud* liste, int position)
{
    assert(position<=LC_longueur(liste) && position > 0);
	int i = 1;
	while (i<position && !LC_estVide(liste))
	{
		liste = LC_obtenirListeSuivante(liste);
		i++;
	}
	return LC_obtenirElement(liste);
}

unsigned int LC_longueur(Noeud* liste)
{
	if (LC_estVide(liste))
	{
		return 0;
	}
	else
	{
		return 1+LC_longueur(LC_obtenirListeSuivante(liste));
	}
}

void LC_liberer(Noeud* liste)
{
	while(!LC_estVide(liste))
	{
		Noeud* suivant = LC_obtenirListeSuivante(liste);
		free(liste->element);
		free(liste);
		liste = suivant;
	}
}
