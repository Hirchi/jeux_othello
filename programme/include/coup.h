/**
 *  \file coup.h
 *  \brief Implémentation du TAD Coup
 *
 *  Représentation d'une coup d'Othello
 */
#ifndef __COUP__
#define __COUP__


#include "position.h"
#include "couleur.h"

/**
 * \struct Coup
 * \brief Représente un coup d'Othello
 */
typedef struct
{
  Position position;
  Couleur couleur;
}Coup;

/**
 * \fn Coup Coup_creerCoup(Position position, Couleur couleur)
 * \brief Permet de créer un coup
 *
 * \param position Position à la quelle le coup sera joué
 * \param couleur Couleur du pion placé lors du coup
 * \return Nouveau coup
 */
Coup Coup_creerCoup(Position position, Couleur couleur);

/**
 * \fn Coup_obtenirCouleur(Coup coup)
 * \brief Obtient la couleur du pion placé lors du coup indiqué
 *
 * \param coup Coup pour lequel on souhaite obtenir la couleur
 * \return coup.couleur
 */
Couleur Coup_obtenirCouleur(Coup coup);

/**
 * \fn Coup_obtenirPosition(Coup coup)
 * \brief Obtient la position du coup
 *
 * \param coup Coup pour lequel on souhaite obtenir la position
 * \return coup.position
 */
Position Coup_obtenirPosition(Coup coup);

#endif
