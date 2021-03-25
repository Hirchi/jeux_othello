#include <stdlib.h>
#include <CUnit/Basic.h>
#include "cellule.h"
#include "testCellule.h"

void test_cellule_obtenirPosition(void)
{
  Position position = Position_creerPosition(2,4);
  Cellule cellule = Cellule_creerCellule(position);
  CU_ASSERT_TRUE(Position_egales(Cellule_obtenirPosition(cellule),position)); //problème ca m'étonnerai que ca marche.
}

void test_cellule_estVide(void)
{
  Position position = Position_creerPosition(2,4);
  Cellule cellule = Cellule_creerCellule(position);
  CU_ASSERT_TRUE(Cellule_estVide(cellule) == 1); // 1=VRAI
}

void test_cellule_nonEstVide(void)
{
  Position position = Position_creerPosition(2,4);
  Cellule cellule = Cellule_creerCellule(position);
  Cellule_placerCouleur(&cellule,Couleur_blanc());
  CU_ASSERT_TRUE(!Cellule_estVide(cellule));
}

void test_cellule_obtenirCouleur(void)
{
  Position position = Position_creerPosition(2,4);
  Cellule cellule = Cellule_creerCellule(position);
  Cellule_placerCouleur(&cellule,Couleur_blanc());
  Couleur couleurObtenue = Cellule_obtenirCouleur(cellule);
  CU_ASSERT_TRUE(Couleur_estBlanc(couleurObtenue));
}
