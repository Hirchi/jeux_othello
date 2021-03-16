/**
 *  \file partie.h
 *  \brief Implémentation du TAD Partie
 *
 *  Représentation d'une partie d'Othello et fonctions associées
 */

#ifndef __PARTIE__
#define __PARTIE__

#include "joueur.h"
#include "couleur.h"
#include "plateau.h"

/**
 * \struct Partie
 * \brief Représentation d'une partie d'Othello
 * \note Peut représenter des parties à plus de 2 joueurs si besoin est.
 */
typedef struct
{
    Joueur* listeJoueur;
    unsigned int nombreJoueur;
    Plateau plateau;
    unsigned int estTournoi;
    Couleur couleurProgramme; //Uniquement utilisé si tournoi

}Partie;
#include "strategie.h"
#include "ihm.h"
#include "coup.h"
#include "humain.h"

/**
 * \fn void Partie_creerPartieClassique(Partie* partie, Strategie strategieBlanc, Strategie strategieNoir)
 * \brief Cree une partie en mode classique (standard)
 *
 * \param partie Pointeur sur la variable à laquelle doit être affectée la partie crée
 * \param Blanc Joueur blanc
 * \param Noir Joueur noir
 *
 */
void Partie_creerPartieClassique(Partie* partie, Joueur Blanc, Joueur Noir);

/**
 * \fn void Partie_creerPartieTournoi(Partie* partie, Strategie strategieBlanc, Strategie strategieNoir, Couleur couleurProgramme)
 * \brief Cree une partie en mode tournoi
 *
 * \param partie Pointeur sur la variable à laquelle doit être affectée la partie crée
 * \param Blanc Joueur blanc
 * \param Noir Joueur noir
 * \param Couleur couleurProgramme La couleur associée au programme
 */
void Partie_creerPartieTournoi(Partie* partie, Joueur Blanc, Joueur Noir, Couleur couleurProgramme);

/**
 * \fn unsigned int Partie_obtenirNombreJoueur(Partie *partie)
 * \brief Obtient le nombre de joueurs d'une partie
 *
 * \param partie Pointeur sur la partie dont il faut obtenir le nombre de joueurs
 * \return (*partie).nombreJoueur
 */
unsigned int Partie_obtenirNombreJoueur(Partie *partie);

/**
 * \fn unsigned int Partie_estTournoi(Partie partie)
 * \brief Détermine si la partie est en mode tournoi ou non
 *
 * \param partie La partie dont il faut vérifier si elle est en mode tournoi
 * \return partie.estTournoi (1 si vrai, 0 si faux)
 */
unsigned int Partie_estTournoi(Partie partie);

/**
 * \fn Couleur Partie_obtenirCouleurProgramme(Partie partie)
 * \brief Obtient la couleur associée au programme
 * \pre Partie_estTournoi(partie)
 *
 * \param partie La partie pour laquelle on veut obtenir la couleur du programme
 * \return partie.couleurProgramme
 */
Couleur Partie_obtenirCouleurProgramme(Partie partie);

/**
 * \fn Joueur* Partie_obtenirJoueurs(Partie *partie)
 * \brief Obtient un tableau contenant les joueurs de la partie
 *
 * \param partie La partie dont on veut obtenir les joueurs
 * \return partie.listeJoueur
 */
Joueur* Partie_obtenirJoueurs(Partie *partie);

/**
 * \fn Plateau Partie_obtenirPlateau(Partie *partie)
 * \brief Permet d'obtenir le plateau de la partie
 *
 * \param partie La partie pour laquelle on souhaite obtenir le plateau
 * \return partie.plateau
 */
Plateau Partie_obtenirPlateau(Partie *partie);

/**
 * \fn void Partie_lancerPartie(Partie *partie, IHM ihm)
 * \brief Permet de lancer une partie avec une IHM donnée
 *
 * \param partie La partie à lancer
 * \param ihm L'IHM avec laquelle afficher la partie
 */
void Partie_lancerPartie(Partie *partie, IHM ihm);

/**
 * \fn void Partie_finirPartie(Partie *partie)
 * \brief Libère les espaces mémoires associés à la partie et affiche le gagnant dans le cas échéant
 *
 * \param partie Pointeur sur la partie à finir
 * \param ihm L'IHM avec laquelle afficher le gagnant
 */
void Partie_finirPartie(Partie *partie, IHM ihm);

/**
 * \fn int Partie_estFini(Partie partie)
 * \brief Détermine si une partie est finie ou non
 *
 * \param partie La partie dont il faut vérifier si elle est finie ou non
 * \return 1 si plus aucun joueur ne peut jouer de coup valide, 0 sinon
 */
int Partie_estFini(Partie partie);

/**
 * \fn int Partie_JoueurPeutJouer(Partie* Partie, Joueur joueur)
 * \brief Détermine si un joueur peut jouer dans une partie donnée
 *
 * \param Partie Pointeur sur la partie dans laquelle on souhaite vérifier si le joueur donné peut jouer
 * \param joueur Le joueur dont on souhaite vérifier si il peut jouer
 * \return 1 si le joueur a au moins un coup valide possible, 0 sinon
 */
int Partie_JoueurPeutJouer(Partie* Partie, Joueur joueur);


/**
 * \fn Joueur Partie_gagnant(Partie partie, unsigned int* estNulle)
 * \brief Détermine si la partie est nulle et dans le cas contraire retourne le gagnant
 * \warning La valeur de retour n'est pas définie si la partie est nulle, et doit donc être ignorée si la valeur déréférencée de estNulle vaut 1 suite à l'exécution de la fonction
 *
 * \param partie La partie pour laquelle on souhaite déterminer le gagnant (ou l'absence de gagnant)
 * \param estNulle Pointeur sur la variable à laquelle affecter 1 si la partie est nulle et 0 dans le cas contraire
 * \return Le joueur gagnant ou une valeur indéfinie si la partie est nulle
 */
Joueur Partie_gagnant(Partie partie, unsigned int* estNulle);

#endif
