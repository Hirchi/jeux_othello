/**
 *  \file listeChaineeGenerique.h
 *  \brief Implémentation d'une liste chaînée générique
 *
 *  Implémentation d'une liste chaînée pouvant contenir n'importe quel type de données (y compris ceux n'étant pas des types par défaut)
 *  Contenue dans liblistechainee.a
 */
#ifndef __LISTE_CHAINEE_GENERIQUE__
#define __LISTE_CHAINEE_GENERIQUE__

#include <stdlib.h>


/**
 * \struct Noeud
 * \brief Noeud de la liste chaînée.
 * \note Une liste chaînée est définie comme étant un pointeur sur un noeud.
 */
typedef struct Noeud
{
	void* element;
	struct Noeud* suivant;
} Noeud;

/**
 * \fn Noeud* LC_listeVide()
 * \brief Initialise une liste vide.
 *
 * \return Nouvelle liste
 */
Noeud* LC_listeVide();

/**
 * \fn Noeud* LC_estVide(Noeud* liste)
 * \brief Vérifie si une liste est vide
 *
 * \param liste Liste dont il faut vérifier si elle est vide
 * \return 1 si la liste est vide, 0 sinon
 */
int LC_estVide(Noeud* liste);

/**
 * \fn void LC_fixerListeSuivante(Noeud** liste1, Noeud* liste2)
 * \brief Assigne liste2 comme liste suivante de la liste pointée par liste1
 *
 * \param liste1 Pointeur sur la liste dont il faut modifier la liste suivante
 * \param liste2 Liste à assigner comme liste suivante à liste1
 */
void LC_fixerListeSuivante(Noeud** liste1, Noeud* liste2);

/**
 * \fn void LC_ajouter(Noeud** liste, void* element, size_t tailleDonnees)
 * \brief Ajoute l'élément pointé par element à la liste pointée par liste
 * \note Ne pas oublier de cast le pointeur de l'élément en void* avant d'appeler la fonction
 *
 * \param liste Pointeur sur la liste à laquelle ajouter l'élément
 * \param element Pointeur sur l'élément à ajouter
 * \param tailleDonnees Nombre d'octets de l'élément à ajouter
 */
void LC_ajouter(Noeud** liste, void* element, size_t tailleDonnees);

/**
 * \fn Noeud* LC_obtenirListeSuivante(Noeud* liste)
 * \brief Permet d'obtenir la liste suivante d'une liste
 * \pre !LC_estVide(liste)
 *
 * \param liste Liste dont il faut obtenir la liste suivante
 * \return (*liste).suivant
 */
Noeud* LC_obtenirListeSuivante(Noeud* liste);

/**
 * \fn void* LC_obtenirElement(Noeud* liste)
 * \brief Obtient l'élément du premier noeud d'une liste
 *
 * \param liste La liste dont il faut obtenir l'élément
 * \return NULL si la liste est vide, (*liste).element sinon
 */
void* LC_obtenirElement(Noeud* liste);

/**
 * \fn void* LC_obtenirIemeElement(Noeud* liste, int position)
 * \brief Permet d'obtenir un élément à une certaine position dans une liste
 * \pre position <= LC_longueur(liste) && LC_longueur(liste) > 0
 * \note L'indexation commence à 1 pour respecter la conception
 *
 * \param liste La liste dans laquelle obtenir l'élément
 * \param position Position de l'élément
 * \return Le i-ème élément de la liste
 */
void* LC_obtenirIemeElement(Noeud* liste, int position);

/**
 * \fn unsigned int LC_longueur(Noeud* liste)
 * \brief Obtient la longueur d'une liste
 *
 * \param liste Liste dont il faut obtenir la longueur
 * \return La longueur de la liste
 */
unsigned int LC_longueur(Noeud* liste);

/**
 * \fn void LC_liberer(Noeud* liste)
 * \brief Libère l'espace mémoire associé à une liste
 *
 * \param liste La liste à libérer
 */
void LC_liberer(Noeud* liste);




#endif
