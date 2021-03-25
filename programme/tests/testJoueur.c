#include<stdlib.h>
#include<string.h>
#include<CUnit/Basic.h>
#include "testJoueur.h"
#include "strategie.h"
#include "joueur.h"

void test_joueur_obtenirCouleur(void)
{
  Couleur couleur = Couleur_blanc();
  Strategie strat = Strategie_humain();
  Joueur joueur = Joueur_creerJoueur(strat,couleur);
  CU_ASSERT_TRUE(couleur == Joueur_obtenirCouleur(joueur));
}

void test_joueur_obtenirNom(void)
{
  Strategie strat = Strategie_humain();
  char* nom1 = "blanc"; 
  char* nom2 = "noir";
CU_ASSERT_TRUE(
Joueur_obtenirNom(Joueur_creerJoueur(strat,Couleur_blanc()))==nom1 &&
Joueur_obtenirNom(Joueur_creerJoueur(strat,Couleur_noir()))==nom2
);
}

void test_joueur_obtenirStrategie(void)
{
  Couleur couleur = Couleur_blanc();
  CU_ASSERT_TRUE(
		Strategie_humain() == Joueur_obtenirStrategie(Joueur_creerJoueur(Strategie_humain(),couleur)) &&
		Strategie_IAMinMax() == Joueur_obtenirStrategie(Joueur_creerJoueur(Strategie_IAMinMax(),couleur)) &&
		Strategie_IAAlphaBeta() == Joueur_obtenirStrategie(Joueur_creerJoueur(Strategie_IAAlphaBeta(),couleur))
);
}
