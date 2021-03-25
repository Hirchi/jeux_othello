#include<stdlib.h>
#include<CUnit/Basic.h>
#include "testListeChaineeGenerique.h"
#include "testCouleur.h"
#include "testPosition.h"
#include "testJoueur.h"
#include "testCoup.h"
#include "testCellule.h"
#include "testPlateau.h"
#include "testStrategie.h"
#include "testCoups.h"
#include "testPartie.h"
#include "testUtiles.h"
#define TRUE 1
#define FALSE 0

int init_suite_success(void) {
	return 0;
}

int clean_suite_success(void) {
	return 0;
}


int main(int argc, char** argv){
	CU_pSuite pSuite = NULL;

	/* initialisation du registre de tests */
	if (CUE_SUCCESS != CU_initialize_registry())
	return CU_get_error();

	/* ajout d'une suite de test */
	pSuite = CU_add_suite("Tests boite noire : nb voisins", init_suite_success, clean_suite_success);
	if (NULL == pSuite) {
	CU_cleanup_registry();
	return CU_get_error();
	}

	/* Ajout des tests à la suite de tests boite noire */
	if ((NULL == CU_add_test(pSuite, "LCG : estVide", test_LC_est_vide))
	  || (NULL == CU_add_test(pSuite, "LCG : non estVide", test_LC_non_est_vide))
	  || (NULL == CU_add_test(pSuite, "LCG : obtenirElement", test_LC_obtenir_element))
	  || (NULL == CU_add_test(pSuite, "LCG : obtenirIemeElement", test_LC_obtenir_ieme_element))
	  || (NULL == CU_add_test(pSuite, "LCG : longueur liste vide", test_LC_longueur_vide))
	  || (NULL == CU_add_test(pSuite, "LCG : longueur liste non vide", test_LC_longueur_nonVide))
	  || (NULL == CU_add_test(pSuite, "Couleur : estBlanc", test_Couleur_est_blanc))
	  || (NULL == CU_add_test(pSuite, "Couleur : estNoir", test_Couleur_est_noir))
	  || (NULL == CU_add_test(pSuite, "Couleur : estSansCouleur", test_Couleur_est_sans_couleur))
	  || (NULL == CU_add_test(pSuite, "Couleur : couleurEnCaractere", test_Couleur_couleurEnChar))
	  || (NULL == CU_add_test(pSuite, "Couleur : caractereEnCouleur", test_Couleur_charEnCouleur))
	  || (NULL == CU_add_test(pSuite, "Couleur : complement", test_Couleur_complement))
	  || (NULL == CU_add_test(pSuite, "Position : abscisse", test_position_abscisse))
	  || (NULL == CU_add_test(pSuite, "Position : ordonnee", test_position_ordonnee))
	  || (NULL == CU_add_test(pSuite, "Position : abscisse", test_position_abscisse))
	  || (NULL == CU_add_test(pSuite, "Position : position en chaine", test_position_pEnChaine))
	  || (NULL == CU_add_test(pSuite, "Position : position en chaine cas limite debut", test_position_pEnChaine_casLimiteDebut))
	  || (NULL == CU_add_test(pSuite, "Position : position en chaine cas limite fin", test_position_pEnChaine_casLimiteFin))
	  || (NULL == CU_add_test(pSuite, "Position : chaine en position", test_position_cEnPosition))
	  || (NULL == CU_add_test(pSuite, "Position : chaine en position cas limite debut", test_position_cEnPosition_casLimiteDebut))
	  || (NULL == CU_add_test(pSuite, "Position : chaine en position cas limite fin", test_position_cEnPosition_casLimiteFin))
	  || (NULL == CU_add_test(pSuite, "Position : position en chaine en position", test_position_pEnPosition))
	  || (NULL == CU_add_test(pSuite, "Position : position adjacente",  test_position_positionAdjacente))
          || (NULL == CU_add_test(pSuite, "Position : position adjacentelimite",  test_position_positionAdjacenteCasLimite))
	  || (NULL == CU_add_test(pSuite, "Position : position egales",  test_position_positionEgales))

	  || (NULL == CU_add_test(pSuite, "Joueur : obtenirCouleur", test_joueur_obtenirCouleur))
	  || (NULL == CU_add_test(pSuite, "Joueur : obtenirNom", test_joueur_obtenirNom))
	  || (NULL == CU_add_test(pSuite, "Joueur : obtenirStartegie", test_joueur_obtenirStrategie))
	  || (NULL == CU_add_test(pSuite, "Coup : obtenirCouleur", test_coup_obtenirCouleur))
	  || (NULL == CU_add_test(pSuite, "Coup : obtenirPosition", test_coup_obtenirPosition))
	  || (NULL == CU_add_test(pSuite, "Coups : obtenirCoup", test_coups_obtenir_coup))
	  || (NULL == CU_add_test(pSuite, "Coups : CoupsVide", test_coups_coupsVide))
	  || (NULL == CU_add_test(pSuite, "Coups : CoupsAjouterCoup", test_coups_ajouterCoup))	
	  || (NULL == CU_add_test(pSuite, "Cellule : obtenirPosition", test_cellule_obtenirPosition))
	  || (NULL == CU_add_test(pSuite, "Cellule :estVide", test_cellule_estVide))
	  || (NULL == CU_add_test(pSuite, "Cellule : nonEstVide", test_cellule_nonEstVide))
	  || (NULL == CU_add_test(pSuite, "Cellule : obtenirCouleur", test_cellule_obtenirCouleur))
	  || (NULL == CU_add_test(pSuite, "Plateau : largeur", test_plateau_creation_dimention_largeur))
	  || (NULL == CU_add_test(pSuite, "Plateau : hauteur", test_plateau_creation_dimention_hauteur))
	  || (NULL == CU_add_test(pSuite, "Plateau : obtenirCellule", test_plateau_obtenirCellule))
	  || (NULL == CU_add_test(pSuite, "Plateau : pionDuDebut", test_plateau_creation_pion_Debut))
	  || (NULL == CU_add_test(pSuite, "Plateau : estRempli", test_plateau_estRempli))
	  || (NULL == CU_add_test(pSuite, "Plateau : jouer coup", test_plateau_jouerCoup))
	  || (NULL == CU_add_test(pSuite, "Plateau : nombre pions vide", test_plateau_nbPions_vide))
	  || (NULL == CU_add_test(pSuite, "Plateau : nombre pions initial", test_plateau_nbPions_debut))
	  || (NULL == CU_add_test(pSuite, "Plateau : nombre pions suite à coup", test_plateau_nbPions_coup))
	  || (NULL == CU_add_test(pSuite, "Plateau : coup possible début", test_plateau_nbPions_coup))
	  || (NULL == CU_add_test(pSuite, "Plateau : liste coups possibles début", test_plateau_listeCoupsPossibles_debut))
	  || (NULL == CU_add_test(pSuite, "Plateau : obtenirCouleur", test_plateau_obtenirCouleur))
  	  || (NULL == CU_add_test(pSuite, "Utile : nombreDigit", test_utile_nbDigit))
	  || (NULL == CU_add_test(pSuite, "Utile : prochainNombreDansChaine", test_utile_prochainNombreDansChaine))
	  || (NULL == CU_add_test(pSuite, "Partie : creerPartieClassique_Joueurs", test_cellule_creerPartieClassique_Joueurs))
	  || (NULL == CU_add_test(pSuite, "Partie : creerPartieClassique_Plateau", test_cellule_creerPartieClassique_Plateau))
	  || (NULL == CU_add_test(pSuite, "Strategie : humain", test_Strategie_humain))
	  || (NULL == CU_add_test(pSuite, "Strategie : IA minmax", test_Strategie_IAMinMax))
	  || (NULL == CU_add_test(pSuite, "Strategie : IA alpha-beta", test_Strategie_IAlphaBeta))
	  )
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Lancement des tests */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	printf("\n");
	CU_basic_show_failures(CU_get_failure_list());
	printf("\n\n");

	/* Nettoyage du registre */
	CU_cleanup_registry();
	return CU_get_error();
}
