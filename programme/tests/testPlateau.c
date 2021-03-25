#include<stdlib.h>
#include<CUnit/Basic.h>
#include "plateau.h"
#include "testPlateau.h"
#include "couleur.h"
#include "cellule.h"
#include "joueur.h"
#include "position.h"

void test_plateau_creation_dimention_largeur(void)
{
  Plateau plateau = Plateau_creePlateau(8,8);
  int res = Plateau_obtenirLargeur(plateau) == 8;
  Plateau_detruitPlateau(&plateau);
  CU_ASSERT_TRUE(res);
}

void test_plateau_creation_dimention_hauteur(void)
{
  Plateau plateau = Plateau_creePlateau(8,8);
  int res = Plateau_obtenirHauteur(plateau) == 8;
  Plateau_detruitPlateau(&plateau);
  CU_ASSERT_TRUE(res);
}

void test_plateau_obtenirCellule(void)
{

    Plateau plateau = Plateau_creePlateau(8,8);
    Position positionHG = Position_creerPosition(1,1);
    Cellule celluleHG = *Plateau_obtenirCellule(plateau, positionHG);
    int res = Position_egales(positionHG,Cellule_obtenirPosition(celluleHG));
    Plateau_detruitPlateau(&plateau);
    CU_ASSERT_TRUE(res);
}

void test_plateau_creation_pion_Debut(void)
{
  Plateau plateau = Plateau_creePlateau(8,8);
  Plateau_initialisePionDebut(&plateau);

  Position blanc1 = Position_creerPosition(4,4);
  Position blanc2 = Position_creerPosition(5,5);
  Position noir1 = Position_creerPosition(4,5);
  Position noir2 = Position_creerPosition(5,4);
  Cellule cellBlanc1 = *Plateau_obtenirCellule(plateau,blanc1);
  Cellule cellBlanc2 = *Plateau_obtenirCellule(plateau,blanc2);
  Cellule cellNoir1 = *Plateau_obtenirCellule(plateau,noir1);
  Cellule cellNoir2 = *Plateau_obtenirCellule(plateau,noir2);

  int res = Couleur_estBlanc(Cellule_obtenirCouleur(cellBlanc1));
  res *= Couleur_estBlanc(Cellule_obtenirCouleur(cellBlanc2));
  res *= Couleur_estNoir(Cellule_obtenirCouleur(cellNoir1));
  res *= Couleur_estNoir(Cellule_obtenirCouleur(cellNoir2));

  Plateau_detruitPlateau(&plateau);
  CU_ASSERT_TRUE(res);
}

void test_plateau_estRempli(void)
{
	Plateau plateau = Plateau_creePlateau(8,8);
	for (int i = 1; i<=8; i++)
	{
		for (int j = 1; j<=8; j++)
		{
			Cellule* cell = Plateau_obtenirCellule(plateau, Position_creerPosition(i,j));
			Cellule_placerCouleur(cell, Couleur_noir());
		}
	}
	
	int estRempli = 1;
	int i = 1;
	int j = 1;
	while (!estRempli && (i<=8 && j<=8))
	{
		Cellule cell = *Plateau_obtenirCellule(plateau, Position_creerPosition(i,j));
		estRempli *= !Couleur_estSansCouleur(Cellule_obtenirCouleur(cell));
		if (i < 8)
		{
			i++;
		}
		else
		{
			i=1;
			j++;
		}
	}
	CU_ASSERT_TRUE(estRempli);
	Plateau_detruitPlateau(&plateau);
}

void test_plateau_jouerCoup(void)
{
	Plateau plateau = Plateau_creePlateau(8,8);
	Plateau_initialisePionDebut(&plateau);
	Coup coupTest = Coup_creerCoup(Position_creerPosition(4, 3), Couleur_noir()); //Pion noir en d3
	Plateau_jouerCoup(&plateau, coupTest);
	int res = Couleur_estNoir(Plateau_obtenirCouleur(plateau, Position_creerPosition(4, 3)));
	res *= Couleur_estNoir(Plateau_obtenirCouleur(plateau, Position_creerPosition(4, 4)));
	res *= Couleur_estNoir(Plateau_obtenirCouleur(plateau, Position_creerPosition(4, 5)));
	res *= Couleur_estNoir(Plateau_obtenirCouleur(plateau, Position_creerPosition(5, 4)));
	res *= Couleur_estBlanc(Plateau_obtenirCouleur(plateau, Position_creerPosition(5, 5)));
	CU_ASSERT_TRUE(res);
	Plateau_detruitPlateau(&plateau);
}

void test_plateau_nbPions_vide(void)
{
	Joueur joueurTest = Joueur_creerJoueur(Strategie_humain(), Couleur_blanc());
	Joueur adversaireTest = Joueur_creerJoueur(Strategie_humain(), Couleur_noir());
	Plateau plateau = Plateau_creePlateau(8,8);
	CU_ASSERT_TRUE(Plateau_nombrePion(plateau, Joueur_obtenirCouleur(joueurTest)) == 0 && Plateau_nombrePion(plateau, Joueur_obtenirCouleur(adversaireTest)) == 0);
	Plateau_detruitPlateau(&plateau);
}

void test_plateau_nbPions_debut(void)
{
	Joueur joueurTest = Joueur_creerJoueur(Strategie_humain(), Couleur_blanc());
	Joueur adversaireTest = Joueur_creerJoueur(Strategie_humain(), Couleur_noir());
	Plateau plateau = Plateau_creePlateau(8,8);
	Plateau_initialisePionDebut(&plateau);
	CU_ASSERT_TRUE(Plateau_nombrePion(plateau, Joueur_obtenirCouleur(joueurTest)) == 2 && Plateau_nombrePion(plateau, Joueur_obtenirCouleur(adversaireTest) == 2));
	Plateau_detruitPlateau(&plateau);
}

void test_plateau_nbPions_coup(void)
{
	Joueur joueurTest = Joueur_creerJoueur(Strategie_humain(), Couleur_blanc());
	Joueur adversaireTest = Joueur_creerJoueur(Strategie_humain(), Couleur_noir());
	Plateau plateau = Plateau_creePlateau(8,8);
	Plateau_initialisePionDebut(&plateau);
	Coup coupTest = Coup_creerCoup(Position_creerPosition(4, 3), Couleur_noir()); //Pion noir en d3
	Plateau_jouerCoup(&plateau, coupTest);
	CU_ASSERT_TRUE(Plateau_nombrePion(plateau, Joueur_obtenirCouleur(joueurTest)) == 1 && Plateau_nombrePion(plateau, Joueur_obtenirCouleur(adversaireTest)) == 4);
	Plateau_detruitPlateau(&plateau);
}

void test_plateau_coupPossible_debut(void)
{
	Plateau plateau = Plateau_creePlateau(8,8);
	Plateau_initialisePionDebut(&plateau);
	int res = 1;
	for (int i=1; i<Plateau_obtenirLargeur(plateau); i++)
	{
		for (int j=1; j<Plateau_obtenirHauteur(plateau); j++)
		{
			Coup coupATester = Coup_creerCoup(Position_creerPosition(i,j), Couleur_noir());
			if ((i==4 && j==3) || (i==3 && j==4) || (i==5 && j==6) || (i==6 && j==5))
			{
				res *= Plateau_estUnCoupPossible(plateau, coupATester);
			}
			else
			{
				res *= !(Plateau_estUnCoupPossible(plateau, coupATester));
			}
		}
	}
	CU_ASSERT_TRUE(res);
	Plateau_detruitPlateau(&plateau);
}

void test_plateau_listeCoupsPossibles_debut(void)
{
	Plateau plateau = Plateau_creePlateau(8,8);
	Plateau_initialisePionDebut(&plateau);
	Coups coupsPossibles = Plateau_listeCoupsPossibles(plateau, Couleur_noir());
	CU_ASSERT_TRUE(Coups_longueur(coupsPossibles) == 4);
	Coups_libererCoups(coupsPossibles);
	Plateau_detruitPlateau(&plateau);
}


void test_plateau_obtenirCouleur(void)
{
  Plateau plateau = Plateau_creePlateau(8,8);
  Position pos = Position_creerPosition(1,1);
  Cellule *cellule = Plateau_obtenirCellule(plateau,pos);
  Cellule_placerCouleur(cellule,Blanc);
  CU_ASSERT_TRUE(
		 Plateau_obtenirCouleur(plateau,pos)==Blanc
		 );

}
