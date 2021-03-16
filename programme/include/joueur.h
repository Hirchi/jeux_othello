/**
 *  \file joueur.h
 *  \brief Implémentation du TAD Joueur
 *
 *  Implémentation du TAD Joueur
 */

#ifndef __JOUEUR__
#define __JOUEUR__

#include "strategie.h"
#include "couleur.h"

/**
 * \struct Joueur
 * \brief Représentation d'un joueur
 */
typedef struct
{
  Strategie strategie;
  Couleur couleur;
  char* nom;
  int niveau;
}Joueur;

#include "coup.h"
#include "plateau.h"
#include "humain.h"
#include "minmax.h"

//#include "plateau.h"

/**
 * \fn Joueur Joueur_creerJoueur(Strategie strategie, Couleur couleur)
 * \brief Crée un joueur en lui assignant une stratégie et une couleur
 * \note Cette fonction assigne automatiquement le nom du joueur (en appelant une fonction privée) en fonction de sa couleur
 *
 * \param strategie La stratégie que le joueur appliquera
 * \param couleur La couleur à assigner au joueur
 * \return Nouveau joueur
 */
Joueur Joueur_creerJoueur(Strategie strategie, Couleur couleur);

/**
 * \fn Joueur Joueur_creerJoueurProfondeur(Strategie strategie, Couleur couleur)
 * \brief Crée un joueur en lui assignant une stratégie et une couleur
 * \note Cette fonction assigne automatiquement le nom du joueur (en appelant une fonction privée) en fonction de sa couleur
 *
 * \param strategie La stratégie que le joueur appliquera
 * \param couleur La couleur à assigner au joueur
 * \param niveau Niveau du joueur
 * \return Nouveau joueur
 */
Joueur Joueur_creerJoueurNiveau(Strategie strategie, Couleur couleur, int niveau);

/**
 * \fn Strategie Joueur_obtenirStrategie(Joueur joueur)
 * \brief Retourne la stratégie d'un joueur
 *
 * \param joueur Le joueur dont il faut obtenir la stratégie
 * \return joueur.strategie
 */

Strategie Joueur_obtenirStrategie(Joueur joueur);

/**
 * \fn Couleur Joueur_obtenirCouleur(Joueur joueur)
 * \brief Retourne la couleur d'un joueur
 *
 * \param joueur Le joueur dont il faut obtenir la couleur
 * \return joueur.couleur
 */
Couleur Joueur_obtenirCouleur(Joueur joueur);

/**
 * \fn char* Joueur_obtenirNom(Joueur joueur)
 * \brief Retourne le nom d'un joueur
 *
 * \param joueur Le joueur dont il faut obtenir le nom
 * \return joueur.nom
 */
char* Joueur_obtenirNom(Joueur joueur);

/**
 * \fn char* Joueur_obtenirNiveau(Joueur joueur)
 * \brief Retourne le niveau d'un joueur
 *
 * \param joueur Le joueur dont il faut obtenir le nom
 * \return joueur.niveau
 */
int Joueur_obtenirNiveau(Joueur joueur);

/**
 * \fn Coup Joueur_obtenirCoup(Plateau p, Joueur joueur)
 * \brief Obtient un coup à partir d'un plteau et d'un joueur
 *
 * \param p Plateau pour laquelle il faut obtenir un coup
 * \param joueur Joueur pour lequel il faut obtenir un coup
 * \return Un coup selon la stratégie du joueur donné
 */

Coup Joueur_obtenirCoup(Plateau p, Joueur joueur);

//Coup Joueur_choisirCoup(Joueur joueur, Plateau plateau);
#endif
