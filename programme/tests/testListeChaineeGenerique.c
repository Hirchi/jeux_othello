#include<stdlib.h>
#include<CUnit/Basic.h>
#include "listeChaineeGenerique.h"
#include "testListeChaineeGenerique.h"

void test_LC_est_vide(void){
	Noeud* liste = LC_listeVide();
	CU_ASSERT_TRUE(LC_estVide(liste));
	LC_liberer(liste);
}

void test_LC_non_est_vide(void){
	Noeud* liste = LC_listeVide();
	int e = 42;
	LC_ajouter(&liste, (void*)&e, sizeof(int));
	CU_ASSERT_FALSE(LC_estVide(liste));
	LC_liberer(liste); 
}

void test_LC_longueur_vide(void)
{
	Noeud* liste = LC_listeVide();
	CU_ASSERT_TRUE(LC_longueur(liste) == 0);
	LC_liberer(liste);
}
void test_LC_longueur_nonVide(void)
{
	Noeud* liste = LC_listeVide();
	int e1 = 42;
	int e2 = 35;
	LC_ajouter(&liste, (void*)&e1, sizeof(int));
	LC_ajouter(&liste, (void*)&e2, sizeof(int));
	CU_ASSERT_TRUE(LC_longueur(liste) == 2);
	LC_liberer(liste);
}

void test_LC_obtenir_element(void){
	Noeud* liste = LC_listeVide();
	int e = 42;
	LC_ajouter(&liste, (void*)&e, sizeof(int));
	int resultat = *(int*)LC_obtenirElement(liste);
	CU_ASSERT_TRUE(resultat == e);
	LC_liberer(liste);
}

void test_LC_obtenir_ieme_element(void){
	Noeud* liste = LC_listeVide();
	const int TAB_SIZE = 3;
	int tabElems[] = {42, 420, 66};
	for (int i=0; i<TAB_SIZE; i++)
	{
		LC_ajouter(&liste, (void*)&tabElems[i], sizeof(int));
	}
	int tabResultats[TAB_SIZE];
	for (int j=0; j<TAB_SIZE; j++)
	{
		tabResultats[j] = *(int*)LC_obtenirIemeElement(liste,j+1);
	}
	CU_ASSERT_TRUE((tabResultats[0] == tabElems[TAB_SIZE - 1]) && (tabResultats[1] == tabElems[1]) && (tabResultats[TAB_SIZE - 1] == tabElems[0]));
	LC_liberer(liste);
}
