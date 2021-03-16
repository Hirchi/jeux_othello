/**
 *  \file testPartie.h
 *  \brief Test des fonctions de partie.h
 *
 *  Test des fonctions de partie.h
 */
#ifndef _TESTPARTIE_
#define _TESTPARTIE_
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "partie.h"

/**
 * \fn void test_cellule_creerPartieClassique_Joueurs(void)
 * \brief Test de la création des joueurs par Partie_creerPartieClassique()
 */
void test_cellule_creerPartieClassique_Joueurs(void);

/**
 * \fn void test_cellule_creerPartieClassique_Plateau(void)
 * \brief Test de la création du plateau par Partie_creerPartieClassique()
 */
void test_cellule_creerPartieClassique_Plateau(void);

#endif
