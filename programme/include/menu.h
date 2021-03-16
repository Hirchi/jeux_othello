/**
 *  \file menu.h
 *  \brief Implémentation du traitement des arguments et de l'affichage de l'aide
 *
 *  Implémentation du traitement des arguments et de l'affichage de l'aide
 */
#ifndef PROGRAMME_MENU_H
#define PROGRAMME_MENU_H

#include "strategie.h"
#include "partie.h"
#include "ihm.h"

/**
 * \fn void afficherAide()
 * \brief Affiche l'aide du programme
 */
void afficherAide();

/**
 * \fn void traiterEntree(int argc, char const *argv[], unsigned int* valide, Partie* partie, IHM* affichage)
 * \brief Lis les arguments d'entrée du programme, vérifie qu'ils sont valides et crée en conséquence une partie et une IHM
 * \warning Si à l'issue de cette fonction la valeur déréférencée de valide vaut 0, partie et affichage ne sont pas définies
 *
 * \param argc Nombre d'arguments
 * \param argv Tableau contenant les arguments d'entrée
 * \param valide Pointeur sur une variable indiquant si les arguments d'entrée sont valides
 * \param partie Pointeur sur la variable à laquelle la partie crée doit être affectée
 * \param affichage Pointeur sur la variable à laquelle l'IHM crée doit être affectée
 */
void traiterEntree(int argc, char const *argv[], unsigned int* valide, Partie* partie, IHM* affichage);

#endif
