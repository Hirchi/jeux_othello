/**
 *  \file coups.h
 *  \brief Liste de coups
 *
 *  Utilisation d'une liste chaînée générique (voir listeChaineeGenerique.h) pour représenter plusieurs coups
 */
#ifndef COUPS
#define COUPS
#include "listeChaineeGenerique.h"
#include "coup.h"

/**
 * \struct Coups
 * \brief Pointeur sur une instance de la structure Noeud. Voir listeChaineeGenerique.h
 */
typedef Noeud* Coups;

/**
 * \fn Coups Coups_creerVide()
 * \brief Fonction permettant d'initialiser une liste de coups vide
 *
 * \return Liste de coups vide
 */
Coups Coups_creerVide();

/**
 * \fn void Coups_ajouterCoup(Coups* liste, Coup aAjouter)
 * \brief Permet d'ajouter un coup à une liste de coups
 *
 * \param liste Pointeur vers la liste à la quelle ajouter le coup
 * \param aAjouter Coup à ajouter à la liste
 */
void Coups_ajouterCoup(Coups* liste, Coup aAjouter);

/**
 * \fn Coup Coups_obtenirCoup(Coups liste, int position)
 * \brief Permet d'obtenir un coup à une certaine position dans une liste de coups
 * \pre position <= Coups_longueur(liste) && position > 0
 * \note L'indexation commence à 1 pour respecter la conception
 *
 * \param liste La liste dans laquelle obtenir le coup
 * \param position Position du coup à obtenir dans la liste
 * \return Le i-ème coup de la liste
 */
Coup Coups_obtenirCoup(Coups liste, int position);

/**
 * \fn void Coups_libererCoups(Coups liste)
 * \brief Libère l'espace mémoire associé à une liste de coups
 *
 * \param liste La liste à libérer
 */
void Coups_libererCoups(Coups liste);

/**
 * \fn unsigned int Coups_longueur(Coups liste)
 * \brief Obtient la longueur d'une liste de coups
 *
 * \param liste La liste dont il faut obtenir la longueur
 * \return La longueur (nombre d'éléments de la liste)
 */
unsigned int Coups_longueur(Coups liste);

/**
 * \fn int Coups_estVide(Coups liste)
 * \brief Vérifie si une liste de coups est vide
 *
 * \param liste La liste dont il faut vérifier si elle est vide
 * \return 1 si liste est vide, 0 sinon
 */
int Coups_estVide(Coups liste);

#endif
