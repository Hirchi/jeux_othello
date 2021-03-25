#include "plateau.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "utile.h"
#include "ihm.h"


Plateau Plateau_creePlateau(unsigned int largeur ,unsigned int hauteur)
{
  Plateau plateau;
  plateau.largeur = largeur;
  plateau.hauteur = hauteur;
  Cellule *tableauCellule = malloc(largeur*hauteur*sizeof(Cellule));

  Cellule celluleTmp;
  Position positionTmp;
  for (int row = 0; row < hauteur; row++) {
    for (int col = 0; col < largeur; col++) {
      positionTmp = Position_creerPosition(col+1,row+1);
      celluleTmp = Cellule_creerCellule(positionTmp);
      tableauCellule[col+row*largeur] = celluleTmp;
    }
  }
  plateau.tableauCellule = tableauCellule;
  return plateau;

}

void Plateau_initialisePionDebut(Plateau *plateau)
{
  Cellule *tableauCellule = Plateau_obtenirCellules(plateau);
  Couleur blanc = Couleur_blanc();
  Couleur noir = Couleur_noir();
  Cellule_placerCouleur(tableauCellule+27,blanc);
  Cellule_placerCouleur(tableauCellule+28,noir);
  Cellule_placerCouleur(tableauCellule+36,blanc);
  Cellule_placerCouleur(tableauCellule+35,noir);
}

Cellule* Plateau_obtenirCellules(Plateau *plateau)
{
  return plateau->tableauCellule;
}

unsigned int Plateau_obtenirLargeur(Plateau plateau)
{
  return plateau.largeur;
}
unsigned int Plateau_obtenirHauteur(Plateau plateau)
{
  return plateau.hauteur;
}

Cellule* Plateau_obtenirCellule(Plateau plateau,Position position)
{
  unsigned int indice = Position_abscisse(position)-1 + (Position_ordonnee(position)-1) * Plateau_obtenirLargeur(plateau);
  Cellule* tableauCellules = Plateau_obtenirCellules(&plateau);
  return tableauCellules+indice;
}

void Plateau_detruitPlateau(Plateau *plateau)
{
  Cellule *tab = Plateau_obtenirCellules(plateau);
  free(tab);
  tab = NULL;
}

int Plateau_estRempli(Plateau plateau)
{
  int resultat = 1;
  unsigned int largeur = Plateau_obtenirLargeur(plateau);
  unsigned int hauteur = Plateau_obtenirHauteur(plateau);
  Position positionTmp;
  Cellule celluleTmp;
  for (size_t row = 0; row < hauteur; row++) {
    for (size_t col = 0; col < largeur; col++) {
      positionTmp = Position_creerPosition(col+1,row+1);
      celluleTmp = *(Plateau_obtenirCellule(plateau,positionTmp));
      if(!Cellule_estVide(celluleTmp))resultat = 0;
    }
  }
  return resultat;
}

unsigned int Plateau_nombrePion(Plateau plateau, Couleur couleurDuJoueur)
{
  unsigned int largeur = Plateau_obtenirLargeur(plateau);
  unsigned int hauteur = Plateau_obtenirHauteur(plateau);
  unsigned int nbPionDuJoueur = 0;
  Position positionTmp;
  Cellule celluleTmp;
  for (size_t row = 0; row < hauteur; row++) {
    for (size_t col = 0; col < largeur; col++) {
      positionTmp = Position_creerPosition(col+1,row+1);
      celluleTmp = *(Plateau_obtenirCellule(plateau,positionTmp));
      if(Cellule_obtenirCouleur(celluleTmp) == couleurDuJoueur)nbPionDuJoueur++;
    }
  }
  return nbPionDuJoueur;
}

char* Plateau_plateauEnString(Plateau plateau)
{
  //Format du plateau de base: 8:8:...........................BN......NB...........................
  unsigned int hauteur = Plateau_obtenirHauteur(plateau);
  unsigned int nbDigitHauteur = nbDigit(hauteur);
  unsigned int largeur = Plateau_obtenirLargeur(plateau);
  unsigned int nbDigitLargeur = nbDigit(largeur);
  char* chaine = malloc((hauteur*largeur+3+nbDigitHauteur+nbDigitLargeur)*sizeof(char));

  sprintf(chaine,"%d",hauteur);
  chaine[nbDigitHauteur] = ':';
  sprintf(chaine+nbDigitHauteur+1,"%d",largeur);
  unsigned int indice = nbDigitHauteur+nbDigitLargeur+1;
  chaine[indice] = ':';
  indice = nbDigitHauteur+nbDigitLargeur+2;

  Cellule *tableauCellule = Plateau_obtenirCellules(&plateau);
  Couleur couleur;
  for (int i = 0; i < hauteur*largeur; i++) {
    couleur = Cellule_obtenirCouleur(tableauCellule[i]);
    chaine[indice+i] = Couleur_couleurVersChar(couleur);
  }
  chaine[hauteur*largeur+2+nbDigitHauteur+nbDigitLargeur] = '\0';
  return chaine;
}

Plateau Plateau_stringEnPlateau(char* string)
{

  unsigned int hauteur = prochainNombreDansChaine(string);
  unsigned int nbDigitHauteur = nbDigit(hauteur);
  unsigned int largeur = prochainNombreDansChaine(string+nbDigitHauteur+1);
  unsigned int nbDigitLargeur = nbDigit(largeur);
  unsigned int indice = nbDigitHauteur+nbDigitLargeur+2;
  Plateau plateau = Plateau_creePlateau(largeur,hauteur);
  Cellule *tableauCellule = Plateau_obtenirCellules(&plateau);
  Couleur couleur;
  for (int row = 0; row < hauteur; row++) {
    for (int col = 0; col < largeur; col++) {
      if(string[indice+col+row*largeur] != '.')
      {
        couleur = Couleur_charVersCouleur(string[indice+col+row*largeur]);
        Cellule_placerCouleur(tableauCellule+col+row*largeur,couleur);
      }
    }
  }
  return plateau;
}

int Plateau_jouerCoupR(Plateau *plateau, Position position, Direction direction, Couleur couleurDuJoueur)
{

    if(!Plateau_estDansLePlateau(*plateau,position))
    {
        return 0;
    }
    Cellule *cellule = Plateau_obtenirCellule(*plateau,position);
    Couleur couleurDeLaCellule = Cellule_obtenirCouleur(*cellule);
    int res = 0;
    if(couleurDeLaCellule == Couleur_sansCouleur()) // Normalement elle est toujours dans le plateau, mais on est jamais trop prudant
    {
        return 0;
    }
    else
    {
        if(couleurDeLaCellule == couleurDuJoueur)
        {
            return 1;
        }
        else
        {
            Position PositionAdjacente = Position_positionAdjacente(position,direction);
            res = Plateau_jouerCoupR(plateau,PositionAdjacente,direction,couleurDuJoueur);
        }
    }
    if(res == 1)
    {
        Cellule_placerCouleur(cellule,couleurDuJoueur);
        return 1;
    }
    return 0;
}

int Plateau_jouerCoup(Plateau *plateau, Coup coup)
{
  if(!Plateau_estUnCoupPossible(*plateau,coup))return 0;

  Position position = Coup_obtenirPosition(coup);
  Couleur couleur = Coup_obtenirCouleur(coup);
  Cellule *cellule = Plateau_obtenirCellule(*plateau,position);
  Cellule_placerCouleur(cellule,Coup_obtenirCouleur(coup));

  Direction v_listeDirection[8] = {NORD, NORD_EST, EST, SUD_EST, SUD, SUD_OUEST, OUEST, NORD_OUEST};
  Position tmp;
  for (int i = 0; i < 8; i++) {
    tmp = Position_positionAdjacente(position,v_listeDirection[i]);
    if(Plateau_estDansLePlateau(*plateau,tmp))
    {
        Plateau_jouerCoupR(plateau,tmp,v_listeDirection[i],couleur);
    }
  }

  return 1;
}
/*void Plateau_jouerCoupR(Plateau *plateau, Position position, Direction direction, Couleur couleurDuJoueur)
{
  Cellule *cellule = Plateau_obtenirCellule(*plateau,position);

  int caseChangerDeCouleur = 0; // Boolean
  Position PositionAdjacente = Position_positionAdjacente(position,direction);
  if(Plateau_estDansLePlateau(*plateau,PositionAdjacente)) // Normalement elle est toujours dans le plateau, mais on est jamais trop prudant
  {
    Couleur couleurAdjacente = Plateau_obtenirCouleur(*plateau,PositionAdjacente);
    if(couleurAdjacente != couleurDuJoueur)
    {
        caseChangerDeCouleur = Plateau_jouerCoupR(plateau,PositionAdjacente,direction,couleurDuJoueur);
    }
  }
  if(caseChangerDeCouleur ==  1)
  {
    Cellule_placerCouleur(cellule,couleurDuJoueur);
  }
  return caseChangerDeCouleur
}*/


Couleur Plateau_obtenirCouleur(Plateau plateau, Position position)
{
	return Cellule_obtenirCouleur(*(Plateau_obtenirCellule(plateau,position)));
}

int Plateau_estUnCoupPossibleR(Plateau plateau, Position position, Direction direction, Couleur couleurDuJoueur)
{
    Position PositionAdjacente = Position_positionAdjacente(position,direction);
    if(Plateau_estDansLePlateau(plateau,PositionAdjacente))
    {
        Couleur couleurAdjacente = Plateau_obtenirCouleur(plateau,PositionAdjacente);
        if(couleurAdjacente == couleurDuJoueur)
        {
            return 1;
        }
        else if(Cellule_estVide(*(Plateau_obtenirCellule(plateau,PositionAdjacente))))
        {
            return 0;
        }
        else
        {
            return Plateau_estUnCoupPossibleR(plateau,PositionAdjacente,direction,couleurDuJoueur);
        }
    }
    else
    {
        return 0;
    }

}

int Plateau_estUnCoupPossible(Plateau plateau, Coup coup)
{
  Position position = Coup_obtenirPosition(coup);
  Couleur couleur = Coup_obtenirCouleur(coup);
  Couleur complement = Couleur_complement(couleur);

  if(Plateau_obtenirCouleur(plateau, position) != Couleur_sansCouleur())
  {
    return 0;
  }

  int resultat = 0;
  Direction v_listeDirection[8] = {NORD, NORD_EST, EST, SUD_EST, SUD, SUD_OUEST, OUEST, NORD_OUEST};
  Position tmp;
  int i = 0;

  while (i < 8 && resultat != 1) {
    tmp = Position_positionAdjacente(position,v_listeDirection[i]);
    if(Plateau_estDansLePlateau(plateau,tmp))
    {
      if(Plateau_obtenirCouleur(plateau,tmp) == complement)
      {
        resultat = Plateau_estUnCoupPossibleR(plateau,tmp,v_listeDirection[i],couleur);
      }
    }
    i++;
  }
return resultat;
}

int Plateau_estDansLePlateau(Plateau plateau, Position position)
{
  int abscisse = Position_abscisse(position);
  int ordonnee = Position_ordonnee(position);
  int hauteur = Plateau_obtenirHauteur(plateau);
  int largeur = Plateau_obtenirLargeur(plateau);
  return  1 <= abscisse && abscisse <= largeur && 1 <= ordonnee && ordonnee <= hauteur;
}
/*
Coups Plateau_listeCoupsPossibles(Plateau plateau, Couleur couleurRef)
{
	Coups resultat = Coups_creerVide();
	for (unsigned int i = 0; i<Plateau_obtenirLargeur(plateau); i++)
	{
		for (unsigned int j = 0; j<Plateau_obtenirHauteur(plateau); j++)
		{
			Coup coupATester = Coup_creerCoup(Position_creerPosition(i,j), couleurRef);
			if (Plateau_estUnCoupPossible(plateau, coupATester))
			{
        printf("1");
				Coups_ajouterCoup(&resultat, coupATester);
			}
      else
      {
        printf("0");
      }
		}
    printf("\n");
	}
	return resultat;
}
*/

Coups Plateau_listeCoupsPossibles(Plateau plateau, Couleur couleurDuJoueur)
{
	Coups liste = Coups_creerVide();
	int hauteur = Plateau_obtenirHauteur(plateau);
	int largeur = Plateau_obtenirLargeur(plateau);
	Position tmp;
	Coup coupTmp;

	for (int row = 1; row <= hauteur; row++) {
		for (int col = 1; col <= largeur; col++) {
			tmp = Position_creerPosition(col,row);
			coupTmp = Coup_creerCoup(tmp,couleurDuJoueur);
			if(Plateau_estUnCoupPossible(plateau,coupTmp))
			{
				Coups_ajouterCoup(&liste,coupTmp);
			}
		}
	}
	return liste;
}
//*/
