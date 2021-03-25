#include<stdlib.h>
#include<CUnit/Basic.h>
#include "coup.h"


void test_coup_obtenirCouleur(void)
{
  Position position = Position_creerPosition(5,5);
  Couleur couleur = Couleur_blanc();
  Coup coup = Coup_creerCoup(position,couleur);
  CU_ASSERT_TRUE(Couleur_estBlanc(Coup_obtenirCouleur(coup))); //problème ca m'étonnerai que ca marche.
}

void test_coup_obtenirPosition(void)
{
  Position position = Position_creerPosition(5,5);
  Couleur couleur = Couleur_blanc();
  Coup coup = Coup_creerCoup(position,couleur);
  CU_ASSERT_TRUE(Position_egales(position,Coup_obtenirPosition(coup))); //problème ca m'étonnerai que ca marche.

}
