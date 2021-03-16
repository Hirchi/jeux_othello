/**
 *  \file testPosition.h
 *  \brief Test des fonctions de position.h
 *
 *  Test des fonctions de position.h
 */
#ifndef __TEST_POS__
#define __TEST_POS__

/**
 * \fn void test_position_abscisse(void)
 * \brief Test de Position_abscisse()
 */
void test_position_abscisse(void);

/**
 * \fn void test_position_ordonnee(void)
 * \brief Test de Position_ordonnee()
 */
void test_position_ordonnee(void);

/**
 * \fn void test_position_pEnChaine(void)
 * \brief Test de Position_positionEnChaine() dans le cas général
 */
void test_position_pEnChaine(void);

/**
 * \fn void test_position_pEnChaine_casLimiteDebut(void)
 * \brief Test de Position_positionEnChaine() dans le cas d'une position valant (1,1)
 */
void test_position_pEnChaine_casLimiteDebut(void);

/**
 * \fn void test_position_pEnChaine_casLimiteFin(void)
 * \brief Test de Position_positionEnChaine() dans le cas d'une position valant (8,8)
 */
void test_position_pEnChaine_casLimiteFin(void);

/**
 * \fn void test_position_cEnPosition(void)
 * \brief Test de Position_chaineEnPosition() dans le cas général
 */
void test_position_cEnPosition(void);

/**
 * \fn void test_position_cEnPosition_casLimiteDebut(void)
 * \brief Test de Position_chaineEnPosition() dans le cas d'une chaîne valant "a1"
 */
void test_position_cEnPosition_casLimiteDebut(void);

/**
 * \fn void test_position_cEnPosition_casLimiteFin(void)
 * \brief Test de Position_chaineEnPosition() dans le cas d'une chaîne valant "h8"
 */
void test_position_cEnPosition_casLimiteFin(void);

/**
 * \fn void test_position_pEnPosition(void)
 * \brief Test de Position_positionEnChaine() suivi de Position_chaineEnPosition()
 */
void test_position_pEnPosition(void);

/**
 * \fn void test_position_positionAdjacente(void)
 * \brief Test de Position_positionAdjacente() dans le cas général
 */
void test_position_positionAdjacente(void);

/**
 * \fn void test_position_positionAdjacenteCasLimite(void)
 * \brief Test de Position_positionAdjacente() dans le cas d'une position valant (8,8)
 */
void test_position_positionAdjacenteCasLimite(void);

/**
 * \fn void test_position_positionEgales(void)
 * \brief Test de Position_egales()
 */
void test_position_positionEgales(void);
#endif
