/**
 *  \file testListeChaineeGenerique.h
 *  \brief Test des fonctions de listeChaineeGenerique.h
 *
 *  Test des fonctions de listeChaineeGenerique.h
 */
#ifndef __TEST_LCG__
#define __TEST_LCG__

/**
 * \fn void test_LC_est_vide(void)
 * \brief Test de LC_estVide() sur une liste vide
 */
void test_LC_est_vide(void);

/**
 * \fn void test_LC_non_est_vide(void)
 * \brief Test de LC_estVide() sur une liste non vide
 */
void test_LC_non_est_vide(void);

/**
 * \fn void test_LC_longueur_vide(void)
 * \brief Test de LC_longueur() sur une liste vide
 */
void test_LC_longueur_vide(void);

/**
 * \fn void test_LC_longueur_nonVide(void)
 * \brief Test de LC_longueur() sur une liste non vide
 */
void test_LC_longueur_nonVide(void);

/**
 * \fn void test_LC_obtenir_element(void)
 * \brief Test de LC_obtenirElement()
 */
void test_LC_obtenir_element(void);

/**
 * \fn void test_LC_obtenir_ieme_element(void)
 * \brief Test de LC_obtenirIemeElement()
 */
void test_LC_obtenir_ieme_element(void);

#endif
