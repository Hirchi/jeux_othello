#include<stdlib.h>
#include<CUnit/Basic.h>
#include "coups.h"
#include "coup.h"
#include "couleur.h"
#include "position.h"
#include "testCoups.h"
#define TAB_SIZE 3

void test_coups_obtenir_coup(void)
{
	Coup tabElem[TAB_SIZE] = {Coup_creerCoup(Position_creerPosition(1, 2), Couleur_blanc()),
					   Coup_creerCoup(Position_creerPosition(3, 4), Couleur_noir()),
					   Coup_creerCoup(Position_creerPosition(5, 6), Couleur_blanc())};
	
	Coups coups = Coups_creerVide();
	for (int i=0; i<TAB_SIZE; i++)
	{
		Coups_ajouterCoup(&coups, tabElem[i]);	
	}
	
	int res = 1;
	for (int i=0; i<TAB_SIZE; i++)
	{
		Coup cListe = Coups_obtenirCoup(coups, i+1);
		Coup cTab = tabElem[(TAB_SIZE-1) - i];
		res *= Position_egales(Coup_obtenirPosition(cListe), Coup_obtenirPosition(cTab)) 
			   && (
					(Couleur_estBlanc(Coup_obtenirCouleur(cListe)) && Couleur_estBlanc(Coup_obtenirCouleur(cTab)))
					|| (Couleur_estNoir(Coup_obtenirCouleur(cListe)) && Couleur_estNoir(Coup_obtenirCouleur(cTab)))
				  );
	}
	CU_ASSERT_TRUE(res);
	Coups_libererCoups(coups);
}


void test_coups_coupsVide(void)
{
	Coups coupsVide = Coups_creerVide();
	CU_ASSERT_TRUE(LC_estVide(coupsVide));
}


void test_coups_ajouterCoup(void)
{/*
	Coups* cListe;
	Coup coupAjouter = Coup_creerCoup(Position_creerPosition(1, 2),Couleur_blanc());
	&cListe = Coups_creerVide();
	Coups_ajouterCoup(cListe,coupAjouter);
	CU_ASSERT_TRUE(
			Coup_obtenirCouleur(Coups_obtenirCoup(&cListe,0)) == Couleur_blanc() &&
			Position_position_egales(Coup_obtenirPosition(Coups_obtenirCoup(&cListe,0)),Position_creerPosition(1, 2))
			);*/
}
