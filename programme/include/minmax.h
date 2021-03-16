/**
 *  \file minmax.h
 *  \brief Fonctions liées à l'intelligence artificielle
 *
 *  Fonctions liées à l'intelligence artificielle
 */

#include <stdlib.h>
#include "plateau.h"
#include "joueur.h"

/**
 * \fn Coup obtenirCoupMinMax(Plateau plateau, Joueur joueur)
 * \brief Obtient un coup en utilisant l'algorithme du minmax
 *
 * \param plateau Le plateau sur lequel obtenir le coup
 * \param joueur Le joueur pour lequel il faut obtenir le coup
 * \return Le coup optimal selon le minmax
 */
Coup obtenirCoupMinMax(Plateau plateau, Joueur joueur, int niveau);

/**
 * \fn Coup obtenirCoupAlphaBeta(Plateau plateau, Joueur joueur)
 * \brief Obtient un coup en utilisant l'algorithme d'alpha-beta
 *
 * \param plateau Le plateau sur lequel obtenir le coup
 * \param joueur Le joueur pour lequel il faut obtenir le coup
 * \return Le coup optimal selon l'alpha-beta
 */
Coup obtenirCoupAlphaBeta(Plateau plateau, Joueur joueur, int niveau);

int AlphaBetaMin(Plateau plateau, Couleur couleurJoueurEnCours, int profondeur, int (*eval)(Plateau,Couleur), int MaxPrecedent);
int AlphaBetaMax(Plateau plateau, Couleur couleurJoueurEnCours, int profondeur, int (*eval)(Plateau,Couleur), int MinPrecedent);
int MinMaxMax(Plateau plateau, Couleur couleurJoueurEnCours, int profondeur, int (*eval)(Plateau,Couleur));
int MinMaxMin(Plateau plateau, Couleur couleurJoueurEnCours, int profondeur, int (*eval)(Plateau,Couleur));
Coup MinMax(Plateau plateau, Joueur joueur, int (*eval)(Plateau,Couleur), int profondeur);
