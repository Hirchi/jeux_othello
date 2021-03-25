#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "position.h"

Position Position_creerPosition(int x, int y)
{
	Position position;
	position.abscisse = x;
	position.ordonnee = y;
	return position;
}

int Position_abscisse(Position position)
{
	return position.abscisse;
}

int Position_ordonnee(Position position)
{
	return position.ordonnee;
}


int Position_egales(Position position1, Position position2)
{
	if(position1.abscisse != position2.abscisse) return 0;
	if(position1.ordonnee != position2.ordonnee) return 0;
	return 1;
}

char* Position_positionEnChaine(Position position)
{
	//On convertie l'abscisse et l'ordonnee en char ASCII
	//NE PAS OUBLIER DE FREE LE RESULTAT
	char caracAbscisse = 'a' + position.abscisse - 1; //Car l'ordonnee commence à 1
	char caracOrdonnee = '0' + position.ordonnee;
	//char sautDeLigne = '\n';
	char finDeChaine = '\0';

	char* resultat = malloc(3*sizeof(char));
	resultat[0] = caracAbscisse;
	resultat[1] = caracOrdonnee;
	resultat[2] = finDeChaine;

	return resultat;
}

Position Position_chaineEnPosition(char* str)
{
	int abscisse = ((int)str[0] - (int)'a') + 1;
	int ordonnee = atoi(&str[1]);
	return Position_creerPosition(abscisse, ordonnee);
}

Position Position_positionAdjacente(Position position, Direction direction)
{
    int abscisse = position.abscisse;
    int ordonnee = position.ordonnee;

    switch (direction) {
        case NORD:
          ordonnee -= 1;
          break;
        case NORD_EST:
          abscisse += 1;
          ordonnee -= 1;
          break;
        case EST:
          abscisse += 1;
          break;
        case SUD_EST:
          abscisse += 1;
          ordonnee += 1;
          break;
        case SUD:
          ordonnee += 1;
          break;
        case SUD_OUEST:
          abscisse -= 1;
          ordonnee += 1;
          break;
        case OUEST:
          abscisse -= 1;
          break;
        case NORD_OUEST:
          abscisse -= 1;
          ordonnee -= 1;
          break;
    }
    return Position_creerPosition(abscisse,ordonnee);
}
