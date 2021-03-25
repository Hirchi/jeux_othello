#include <assert.h>
#include "couleur.h"

Couleur Couleur_blanc()
{
	Couleur c = Blanc;
	return c;
}

Couleur Couleur_noir()
{
	Couleur c = Noir;
	return c;
}

Couleur Couleur_sansCouleur()
{
	Couleur c = SansCouleur;
	return c;
}

int Couleur_estBlanc(Couleur c)
{
	return (c==Blanc);
}

int Couleur_estNoir(Couleur c)
{
	return (c==Noir);
}

int Couleur_estSansCouleur(Couleur c)
{
	return (c==SansCouleur);
}

char Couleur_couleurVersChar(Couleur couleur)
{
	if(Couleur_estBlanc(couleur))return 'B';
	if(Couleur_estNoir(couleur))return 'N';
	return '.';
}

Couleur Couleur_charVersCouleur(char caractere)
{
	switch (caractere) {
		case 'B':
			return Couleur_blanc();
		case 'N':
			return Couleur_noir();
		default:
			return Couleur_sansCouleur();
	}
}

Couleur Couleur_complement(Couleur c)
{
    assert(!Couleur_estSansCouleur(c));
	Couleur resultat;
	if (Couleur_estBlanc(c))
	{
		resultat = Couleur_noir();
	}
	else
	{
		resultat = Couleur_blanc();
	}
	return resultat;
}
