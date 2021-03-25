#include<stdlib.h>
#include<CUnit/Basic.h>
#include "couleur.h"
#include "testCouleur.h"

void test_Couleur_est_blanc(void)
{
	CU_ASSERT_TRUE(Couleur_estBlanc(Couleur_blanc()));
}

void test_Couleur_est_noir(void)
{
	CU_ASSERT_TRUE(Couleur_estNoir(Couleur_noir()));
}

void test_Couleur_est_sans_couleur(void)
{
	CU_ASSERT_TRUE(Couleur_estSansCouleur(Couleur_sansCouleur()));
}

void test_Couleur_complement(void)
{
	CU_ASSERT_TRUE(Couleur_estBlanc(Couleur_complement(Couleur_noir())) && Couleur_estNoir(Couleur_complement(Couleur_blanc())));
}

void test_Couleur_couleurEnChar(void)
{
	CU_ASSERT_TRUE(Couleur_couleurVersChar(Couleur_blanc()) == 'B' && Couleur_couleurVersChar(Couleur_noir()) == 'N' && Couleur_couleurVersChar(Couleur_sansCouleur()) == '.');
}

void test_Couleur_charEnCouleur(void)
{
	CU_ASSERT_TRUE(Couleur_estBlanc(Couleur_charVersCouleur('B')) && Couleur_estNoir(Couleur_charVersCouleur('N')) && Couleur_estSansCouleur(Couleur_charVersCouleur('.')));
}
