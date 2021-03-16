/**
 *  \file plateau.h
 *  \brief Implémentation du TAD Plateau
 *
 *  Représentation du plateau de jeu et fonctions associées
 */
#ifndef __PLATEAU__
#define __PLATEAU__

#include "cellule.h"

/**
 * \struct Plateau
 * \brief Représentation du plateau de jeu
 */
typedef struct
{
  Cellule* tableauCellule;
  unsigned int largeur;
  unsigned int hauteur;
}Plateau;
#include "coup.h"
#include "coups.h"
#include "couleur.h"
#include "joueur.h"
#include "direction.h"


/**
 * \fn Plateau_creePlateau(unsigned int largeur, unsigned int hauteur)
 * \brief Permet de créer un plateau de largeur et de hauteur données
 *
 * \param largeur Largeur du plateau à créer
 * \param hauteur Hauteur du plateau à créer
 * \return Nouveau plateau de hauteur et largeur données
 */
Plateau Plateau_creePlateau(unsigned int largeur ,unsigned int hauteur);

/**
 * \fn void Plateau_initialisePionDebut(Plateau *plateau)
 * \brief Place les pions de début d'une partie classique d'Othello
 *
 * \param plateau Plateau sur lequel placer les pions
 */
void Plateau_initialisePionDebut(Plateau *plateau);

/**
 * \fn Cellule* Plateau_obtenirCellules(Plateau *plateau)
 * \brief Obtient un tableau contenant les cellules d'un plateau
 *
 * \param plateau Plateau dont on veut obtenir les cellules
 * \return (*plateau).tableauCellule
 */
Cellule* Plateau_obtenirCellules(Plateau *plateau);

/**
 * \fn Cellule* Plateau_obtenirCellule(Plateau plateau, Position position)
 * \brief Obtient un pointeur sur la cellule d'un plateau à une position donnée
 *
 * \param plateau Plateau sur lequel on souhaite obtenir la cellule
 * \param position Position de la cellule recherchée
 * \return Pointeur sur la cellule du plateau à la position donnée
 */
Cellule* Plateau_obtenirCellule(Plateau plateau,Position position);

/**
 * \fn int Plateau_estRempli(Plateau plateau)
 * \brief Détermine si un plateau est rempli
 *
 * \param plateau Plateau dont on souhaite vérifier si il est rempli
 * \return 1 si le plateau est rempli, 0 sinon
 */
int Plateau_estRempli(Plateau plateau);

/**
 * \fn int Plateau_jouerCoup(Plateau *plateau, Coup coup)
 * \brief Joue un coup sur un plateau donné
 *
 * \param plateau Pointeur sur le plateau sur lequel jouer le coup
 * \param coup Coup à joeur
 * \return 1 si absence d'erreur, 0 sinon
 */
int Plateau_jouerCoup(Plateau *plateau, Coup coup);

/**
 * \fn int Plateau_estUnCoupPossible(Plateau plateau, Coup coup)
 * \brief Vérifie si un coup donné est possible sur un plateau donné
 *
 * \param plateau Plateau sur lequel vérifier si le coup est valide
 * \param coup Coup à vérifier
 * \return 1 si le coup est possible, 0 sinon
 */
int Plateau_estUnCoupPossible(Plateau plateau, Coup coup);

/**
 * \fn unsigned int Plateau_nombrePion(Plateau plateau, Couleur couleurDuJoueur)
 * \brief Retourne le nombre de pions de la couleur donnée sur un plateau donné
 *
 * \param plateau Plateau sur lequel compter les pions
 * \param couleurDuJoueur Couleur des pions à compter
 * \return Nombre de pions de la couleur donnée sur le plateau donné
 */
unsigned int Plateau_nombrePion(Plateau plateau, Couleur couleurDuJoueur);

/**
 * \fn char* Plateau_plateauEnString(Plateau plateau)
 * \brief Retourne une représentation du plateau donné en chaîne de caractères
 *
 * \param plateau Plateau à convertir en chaîne de caractère
 * \return Une chaîne de caractères représentant le plateau. Celle ci commence par deux nombres séparés par le caractère ':', représentant respectivement la hauteur et la largeur du plateau.
 *  Ceux ci sont suivis d'une nouvelle occurence du caractère ':', puis pour chaque cellule du plateau (parcours dans le sens de la largeur puis de la hauteur) du résultat de la conversion de sa couleur par la fonction Couleur_couleurVersChar()
 */
char* Plateau_plateauEnString(Plateau plateau);

/**
 * \fn char* Plateau_stringEnPlateau(char* plateau)
 * \brief Opération inverse de Plateau_plateauEnString(). Convertit une représentation en chaîne de caractères d'un plateau en l'instance de la structure Plateau qui lui correspond
 * \note La chaîne de caractères en entrée doit être au même format que celui retourné par la fonction Plateau_plateauEnString()
 *
 * \param plateau Chaîne représentant un plateau à convertir en instance de la structure Plateau
 * \return Plateau correspondant à la chaîne de caractères
 */
Plateau Plateau_stringEnPlateau(char* plateau);

/**
 * \fn unsigned int Plateau_obtenirLargeur(Plateau plateau)
 * \brief Obtient la largeur d'un plateau donné
 *
 * \param plateau Plateau dont il faut obtenir la largeur
 * \return plateau.largeur
 */
unsigned int Plateau_obtenirLargeur(Plateau plateau);

/**
 * \fn unsigned int Plateau_obtenirHauteur(Plateau plateau)
 * \brief Obtient la hauteur d'un plateau donné
 *
 * \param plateau Plateau dont il faut obtenir la hauteur
 * \return plateau.hauteur
 */
unsigned int Plateau_obtenirHauteur(Plateau plateau);

/**
 * \fn void Plateau_detruitPlateau(Plateau *plateau)
 * \brief Libère l'espace mémoire associé au plateau donné
 *
 * \param plateau Pointeur sur le plateau à détruire
 */
void Plateau_detruitPlateau(Plateau *plateau);

/**
 * \fn Couleur Plateau_obtenirCouleur(Plateau plateau, Position position)
 * \brief Obtient la couleur de la cellule du plateau donné à la position donné. Raccourci de Cellule_obtenirCouleur(Plateau_obtenirCellule())) pour alléger le code
 *
 * \param plateau Plateau sur lequel on veut connaître la couleur d'une cellule
 * \param position Position de la cellule dont on veut connaître la couleur
 * \return Cellule_obtenirCouleur(*(Plateau_obtenirCellule(plateau,position)))
 */
Couleur Plateau_obtenirCouleur(Plateau plateau, Position position);

/**
 * \fn int Plateau_estDansLePlateau(Plateau plateau, Position position)
 * \brief Détermine si la position donnée correspond à une cellule du plateau donné
 *
 * \param plateau Plateau dont on souhaite déterminer si la position donnée correspond à une de ses cellules
 * \param position Position à vérifier
 * \return 1 si la position donnée correspond à celle d'une cellule du plateau donnée, 0 sinon
 */
int Plateau_estDansLePlateau(Plateau plateau, Position position);

/**
 * \fn Coups Plateau_listeCoupsPossibles(Plateau plateau, Couleur couleurRef)
 * \brief Retourne la liste des coups possibles sur le plateau donné par le joueur de la couleur donnée
 *
 * \param plateau Plateau sur lequel rechercher les coups possibles
 * \param couleurRef Couleur du joueur pour lequel rechercher les coups possibles
 * \return Liste (pouvant être vide le cas échéant) contenant tous les coups possibles du joueur de la couleur donnée sur le plateau donné
 */
Coups Plateau_listeCoupsPossibles(Plateau plateau, Couleur couleurRef);




#endif
