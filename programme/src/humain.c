#include <stdio.h>
#include <string.h>
#include "plateau.h"
#include "position.h"
#include "couleur.h"
#include "coup.h"
#include "joueur.h"
#include "humain.h"


#define TAILLE_MAX_ENTREE 4

int positionValide(const Plateau plateau, char* entree)
{
	int largeur = Plateau_obtenirLargeur(plateau);
	int hauteur = Plateau_obtenirHauteur(plateau);
	if(!(entree[0] >= 'a' && entree[0] < 'a'+largeur))
	{
		return 0;
	}
	if(!(entree[1] >= '1' && entree[1] < '1'+hauteur))
	{
		return 0;
	}
	return 1;
}

Coup obtenirCoupHumain(Plateau p, Joueur joueurReference)
{
	//PRECONDITION = Au moins 1 coup valide possible, à vérifier au niveau de la partie
	int estValide = 0;
	int tailleReponse = 0;
	Coup coupEntre;
	char entree[TAILLE_MAX_ENTREE];
	while (!estValide || tailleReponse > 3 || tailleReponse <= 0)
	{

		tailleReponse=scanf("%s", entree);
		estValide = positionValide(p,entree);
		coupEntre = Coup_creerCoup(Position_chaineEnPosition(entree), Joueur_obtenirCouleur(joueurReference));
		if(estValide == 1 && tailleReponse <= 3 && tailleReponse > 0)estValide = Plateau_estUnCoupPossible(p, coupEntre);
	}
	return coupEntre;
}
