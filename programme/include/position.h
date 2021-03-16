/**
 *  \file position.h
 *  \brief Implémentation du TAD Position
 *
 *  Représentation d'une position sur deux dimensions et fonctions associées
 */

#ifndef __POSITION__
#define __POSITION__

/**
 * \struct Position
 * \brief Représentation d'une position sur deux dimensions (vecteur à valeur enitères sur deux dimensions)
 */
typedef struct
{
	int abscisse;
	int ordonnee;
}Position;

#include "direction.h"

/**
 * \fn Position Position_creerPosition(int x, int y)
 * \brief Creer une nouvelle position avec l'abscisse et l'ordonée données
 *
 * \param x Abscisse de la position à créer
 * \param y Ordonnée de la position à créer
 * \return Nouvelle position
 */
Position Position_creerPosition(int x, int y);

/**
 * \fn int Position_abscisse(Position position)
 * \brief Retourne l'abscisse d'une position donnée
 *
 * \param position La position dont on souhaite obtenir l'abscisse
 * \return position.abscisse
 */
int Position_abscisse(Position position);

/**
 * \fn int Position_ordonnee(Position position)
 * \brief Retourne l'ordonnée d'une position donnée
 *
 * \param position La position dont on souhaite obtenir l'ordonnée
 * \return position.ordonnee
 */
int Position_ordonnee(Position position);

/**
 * \fn int Position_egales(Position position1, Position position2)
 * \brief Détermine si deux position ont des ordonnées et abscisse égales
 *
 * \param position1 Première position à comparer
 * \param position2 Deuxième position à comparer
 * \return 1 si les deux positions sont égales, 0 sinon
 */
int Position_egales(Position position1, Position position2);

/**
 * \fn char* Position_positionEnChaine(Position position)
 * \brief Convertit une position en une chaîne de caractères contenant sa représentation en notation standard d'Othello (abscisses numérotées de a à h, suivies des ordonnées numérotées de 1 à 8)
 * \param position Position à convertir en chaîne
 *
 * \return Chaîne correspondant à la position. Le premier caractère (étant une lettre comprise entre a et h) désigne l'abscisse, le second (chiffre entre 1 et 8) l'ordonnée.
 * Le dernier caractère est le terminateur nul.
 */
char* Position_positionEnChaine(Position position);

/**
 * \fn Position Position_chaineEnPosition(char* str)
 * \brief Opération inverse de Position_positionEnChaine(). Convertit une chaîne de caractères en la position qu'elle représente
 * \note Les deux premiers caractères de la chaîne doivent correspondre à la notation standard Othello (même format que Position_positionEnChaine()). Les caractères suivants ne sont pas évalués.
 *
 * \param str Chaîne à convertir en position
 * \return Position représentée par la chaîne donnée
 */
Position Position_chaineEnPosition(char* str);

/**
 * \fn Position Position_positionAdjacente(Position position, Direction direction)
 * \brief Retourne la position adjacente à la postion donnée dans la direction donnée
 *
 * \param position La position de départ à laquelle on souhaite obtenir une position adjacente
 * \param direction La direction dans laquelle obtenir la position adjacente
 * \return La position adjacente à la postion donnée dans la direction donnée
 */
Position Position_positionAdjacente(Position position, Direction direction);

#endif
