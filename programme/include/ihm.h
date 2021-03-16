/**
 *  \file IHM.h
 *  \brief Implémentation des fonctions liées à l'IHM
 *
 *  Fonctions d'IHM
 */

#ifndef __IHM__
#define __IHM__


#include "plateau.h"

/**
 * \struct IHM
 * \brief Structure définissant un type d'IHM avec son propre type d'affichage
 */
typedef struct
{
  void (*afficherPlateau)(Plateau);
  void (*afficherText)(char*);
}IHM;

/**
 * \fn void IHM_affichePlateau(IHM ihm, Plateau plateau)
 * \brief Affiche un plateau en utilisant la fonction d'affichage de l'IHM passée en paramètre
 *
 * \param ihm Le type d'IHM avec le quel afficher le plateau
 * \param plateau Le plateau à afficher
 */
void IHM_affichePlateau(IHM ihm, Plateau plateau);

/**
 * \fn void IHM_afficheTexte(IHM ihm, char* texte)
 * \brief Affiche un texte en utilisant la fonction d'affichage de l'IHM passée en paramètre
 *
 * \param ihm Le type d'IHM avec le quel afficher le texte
 * \param plateau Le texte à afficher
 */
void IHM_afficheTexte(IHM ihm, char* texte);

// Console
/**
 * \fn void IHM_affichagePlateauConsole(Plateau plateau)
 * \brief Affichage console basique d'un plateau
 *
 * \param plateau Plateau à afficher
 */
void IHM_affichagePlateauConsole(Plateau plateau);

/**
 * \fn void IHM_affichagePlateauConsole2(Plateau plateau)
 * \brief Affichage console amélioré d'un plateau
 *
 * \param plateau Plateau à afficher
 */
void IHM_affichagePlateauConsole2(Plateau plateau);

/**
 * \fn void IHM_affichageTexteConsole
 * \brief Affichage console d'un texte
 *
 * \param texte Texte à afficher
 */
void IHM_affichageTexteConsole(char* texte);

/**
 * \fn IHM_creerConsole()
 * \brief Crée une IHM console
 *
 * \return Une IHM avec des fonctions d'affichage sur console
 */
IHM IHM_creerConsole();

//Sans Affichage
/**
 * \fn IHM_NULL()
 * \brief Crée une IHM sans affichage
 *
 * \return Une IHM sans affichage
 */
IHM IHM_NULL();

/**
 * \fn IHM_Tournoi()
 * \brief Crée une IHM dédiée au mode tournoi (affichage texte uniquement)
 *
 * \return Une IHM pour le mode tournoi
 */
IHM IHM_Tournoi();

//Pion
/**
 * \fn AffichePion(Couleur couleur)
 * \brief Affiche un pion de la couleur définie
 *
 * \param couleur La couleur du pion à afficher
 */
void AffichePion(Couleur couleur);

/**
 * \fn SetTextColorToBlack()
 * \brief Définit la couleur d'affichage sur noir
 */
void SetTextColorToBlack();

/**
 * \fn SetTextColorToWhite()
 * \brief Définit la couleur d'affichage sur blanc
 */
void SetTextColorToWhite();

/**
 * \fn ResetTextColor
 * \brief Réinitialise la couleur d'affichage
 */
void ResetTextColor();
#endif