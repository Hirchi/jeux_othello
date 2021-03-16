/**
 *  \file humain.h
 *  \brief Fonction(s) permettant de faire jouer un joueur humain (ou un autre programme se faisant passer pour un humain)
 */
#ifndef HUMAIN
#define HUMAIN

#include "coup.h"
#include "plateau.h"
#include "joueur.h"

/**
 * \fn obtenirCoupHumain(Plateau p, Joueur joueurReference)
 * \brief Fonction permettant de transformer l'entrée d'un humain en un coup vérifié valide
 *
 * \param p Le plateau sur lequel sera joué le coup crée
 * \param joueurReference Le joueur qui entre le coup
 * \return Nouveau coup de la couleur du joueur à la postion que ce dernier a entré
 */
Coup obtenirCoupHumain(Plateau p, Joueur joueurReference); //Pas un TAD donc nommage différent d'une fonction TAD

#endif
