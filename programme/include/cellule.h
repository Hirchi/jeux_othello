/**
 *  \file cellule.h
 *  \brief Implémentation du TAD Cellule
 *
 *  Représentation d'une cellule du plateau de jeu et fonctions associées
 */
#ifndef __CELLULE__
#define __CELLULE__

#include "couleur.h"
#include "position.h"

/**
 * \struct Cellule
 * \brief Cellule du plateau
 */
typedef struct
{
  Couleur couleur; /*!< Couleur du contenu de la cellule */
  Position position; /*!< Position de la cellule */
}Cellule;


/**
 * \fn Cellule Cellule_creerCellule(Position position)
 * \brief Fonction permettant de créer une cellule
 *
 * \param position Position à laquelle initialiser la cellule
 * \return Nouvelle cellule
 */
Cellule Cellule_creerCellule(Position position);

/**
 * \fn Cellule_obtenirPosition(Cellule cellule)
 * \brief Fonction permettant d'obtenir la position d'une cellule
 *
 * \param cellule Cellule dont on souhaite obtenir la position
 * \return cellule.position
 */
Position Cellule_obtenirPosition(Cellule cellule);

/**
 * \fn int Cellule_estVide(Cellule cellule)
 * \brief Fonction permettant de savoir si une cellule est vide
 *
 * \param cellule Cellule dont on veut savoir si elle est vide
 * \return 1 si la cellule est vide, 0 sinon
 */
int Cellule_estVide(Cellule cellule);

/**
 * \fn Couleur Cellule_obtenirCouleur(Cellule cellule)
 * \brief Fonction permettant d'obtenir la couleur d'une cellule
 *
 * \param cellule Cellule dont on veut obtenir la couleur
 * \return cellule.couleur
 */
Couleur Cellule_obtenirCouleur(Cellule cellule);

/**
 * \fn void Cellule_placerCouleur(Cellule *cellule, Couleur couleur)
 * \brief Fonction (procédure dans la conception) permettant de changer la couleur présente dans une cellule
 *
 * \param cellule Pointeur sur la cellule dont il faut modifier la couleur
 * \param couleur Couleur à assigner à la cellule
 */
void Cellule_placerCouleur(Cellule *cellule, Couleur couleur);

#endif
