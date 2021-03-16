/**
 *  \file strategie.h
 *  \brief Implémentation du TAD Strategie
 *
 *  Représentation d'une stratégie d'obtention de coup
 */
#ifndef __STRATEGIE__
#define __STRATEGIE__

/**
 * \enum Strategie
 * \brief Enumération désignant les différentes manières d'obtenir un coup
 */
typedef enum {HUMAIN, MINMAX, ALPHABETA} Strategie;

/**
 * \fn Strategie Strategie_humain()
 * \brief Retourne la stratégie associée à un joueur humain
 *
 * \return HUMAIN
 */
Strategie Strategie_humain();

/**
 * \fn Strategie Strategie_IAMinMax()
 * \brief Retourne la stratégie associée à une IA basée sur l'algorithme minmax.
 *
 * \return MINMAX
 */
Strategie Strategie_IAMinMax();

/**
 * \fn Strategie Strategie_IAAlphaBeta()
 * \brief Retourne la stratégie associée à une IA basée sur l'algorithme alpha-beta.
 *
 * \return ALPHABETA
 */
Strategie Strategie_IAAlphaBeta();

#endif
