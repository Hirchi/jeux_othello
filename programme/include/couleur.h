/**
 *  \file couleur.h
 *  \brief Implémentation du TAD Couleur
 *
 *  Représentation d'une couleur
 */

#ifndef __COULEUR__
#define __COULEUR__

/**
 * \enum Couleur
 * \brief Représente une couleur ou une absence de couleur
 */
typedef enum {Blanc, Noir, SansCouleur} Couleur;

/**
 * \fn Couleur Couleur_blanc()
 * \brief Retourne la valeur représentant la couleur blanche
 *
 * \return Blanc
 */
Couleur Couleur_blanc();

/**
 * \fn Couleur Couleur_noir()
 * \brief Retourne la valeur représentant la couleur noire
 *
 * \return Noir
 */
Couleur Couleur_noir();

/**
 * \fn Couleur_Couleur_sansCouleur()
 * \brief Retourne la valeur représentant l'absence de couleur (dans le cas d'une cellule vide)
 *
 * \return SansCouleur
 */
Couleur Couleur_sansCouleur();

/**
 * \fn int Couleur_estBlanc(Couleur couleur)
 * \brief Verifie si couleur représente le blanc
 *
 * \param couleur La couleur dont on veut savoir si elle est blanche
 * \return 1 si couleur vaut Blanc, 0 sinon
 */
int Couleur_estBlanc(Couleur couleur);

/**
 * \fn int Couleur_estNoir(Couleur couleur)
 * \brief Verifie si couleur représente le noir
 *
 * \param couleur La couleur dont on veut savoir si elle est noire
 * \return 1 si couleur vaut Noir, 0 sinon
 */
int Couleur_estNoir(Couleur couleur);

/**
 * \fn int Couleur_estSansCouleur(Couleur couleur)
 * \brief Verifie si couleur représente l'absence de couleur
 *
 * \param couleur La variable de type couleur dont on veut savoir si elle est sans couleur
 * \return 1 si couleur vaut SansCouleur, 0 sinon
 */
int Couleur_estSansCouleur(Couleur couleur);

/**
 * \fn Couleur Couleur_complement(Couleur couleur)
 * \brief Renvoie la couleur opposée à celle représentée par couleur
 * \pre !Couleur_estSansCouleur(couleur)
 *
 * \param couleur La couleur dont on veut obtenir le complement
 * \return Noir si couleur vaut Blanc, Blanc si couleur vaut Noir
 */
Couleur Couleur_complement(Couleur couleur);

/**
 * \fn char Couleur_couleurVersChar(Couleur couleur)
 * \brief Renvoie le caractère représentant la couleur indiquée
 *
 * \param couleur La couleur dont on veut obtenir le caractère représentatif
 * \return 'N' si couleur vaut Blanc, 'B' si couleur vaut Noir, '.' sinon
 */
char Couleur_couleurVersChar(Couleur couleur); // A TESTER

/**
 * \fn Couleur Couleur_charVersCouleur(char caractere)
 * \brief Convertit un caractère en la couleur qu'il représente
 *
 * \param caractere Caractere à convertir en couleur
 * \return Blanc si caractere vaut 'B', Noir si caractere vaut 'N', SansCouleur sinon
 */
Couleur Couleur_charVersCouleur(char caractere);// A TESTER


#endif
