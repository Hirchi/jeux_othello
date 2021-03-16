/**
 *  \file testPlateau.h
 *  \brief Test des fonctions de plateau.h
 *
 *  Test des fonctions de plateau.h
 */
#ifndef __TEST_PLATEAU__
#define __TEST_PLATEAU__

/**
 * \fn void test_plateau_creation_dimention_largeur(void)
 * \brief Test de la largeur suite à la création d'un plateau
 */
void test_plateau_creation_dimention_largeur(void);

/**
 * \fn void test_plateau_creation_dimention_hauteur(void)
 * \brief Test de la hauteur suite à la création d'un plateau
 */
void test_plateau_creation_dimention_hauteur(void);

/**
 * \fn void test_plateau_obtenirCellule(void)
 * \brief Test de Plateau_obtenirCellule()
 */
void test_plateau_obtenirCellule(void);

/**
 * \fn void test_plateau_creation_pion_Debut(void)
 * \brief Test de Plateau_initialisePionDebut()
 */
void test_plateau_creation_pion_Debut(void);

/**
 * \fn void test_plateau_estRempli(void)
 * \brief Test de Plateau_estRempli()
 */
void test_plateau_estRempli(void);

/**
 * \fn void test_plateau_jouerCoup(void)
 * \brief Test de Plateau_jouerCoup()
 */
void test_plateau_jouerCoup(void);

/**
 * \fn void test_plateau_nbPions_vide(void)
 * \brief Test de Plateau_nombrePion() sur un plateau vide
 */
void test_plateau_nbPions_vide(void);

/**
 * \fn void test_plateau_nbPions_debut(void)
 * \brief Test de Plateau_nombrePion() suite à Plateau_initialisePionDebut()
 */
void test_plateau_nbPions_debut(void);

/**
 * \fn void test_plateau_nbPions_coup(void)
 * \brief Test de Plateau_nombrePion() suite à Plateau_jouerCoup()
 */
void test_plateau_nbPions_coup(void);

/**
 * \fn test_plateau_coupPossible_debut(void)
 * \brief Test de Plateau_estUnCoupPossible() suite à Plateau_initialisePionDebut()
 */
void test_plateau_coupPossible_debut(void);

/**
 * \fn test_plateau_listeCoupsPossibles_debut(void)
 * \brief Test de Plateau_listeCoupsPossibles() suite à Plateau_initialisePionDebut()
 */
void test_plateau_listeCoupsPossibles_debut(void);

/**
 * \fn test_plateau_obtenirCouleur(void)
 * \brief Test de Plateau_obtenirCouleur()
 */
void test_plateau_obtenirCouleur(void);
#endif
