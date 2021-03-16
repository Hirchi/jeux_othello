/**
 *  \file utile.h
 *  \brief Fonctions utilitaires
 *
 *  Fonctions utilitaires
 */
#ifndef __UTILE__
#define __UTILE__

/**
 * \fn unsigned int nbDigit(unsigned int nombre)
 * \brief Retourne le nombre de chiffres d'un naturel
 *
 * \param nombre Le naturel dont on souhaite connaitre le nombre de chiffres
 * \return Nombre de chiffres du naturel donné
 */

  unsigned int nbDigit(unsigned int nombre);

/**
 * \fn unsigned int prochainNombreDansChaine(char* string)
 * \brief Retourne le prochain naturel dans une chaîne donnée
 * \note Exemple : prochainNombreDansChaine("abc19de2f3") = 19
 *
 * \param string La chaîne dans laquelle on veut obtenir le prochain naturel
 * \return Le prochain naturel dans la chaîne donnée
 */
  unsigned int prochainNombreDansChaine(char* string);
/**
 * \fn unsigned int obtenirNaturelAleatoire(unsigned int borneMax)
 * \brief Retourne un naturel aléatoire entre 0 et une borne supérieure donnée
 *
 * \param borneMax La borne supérieure du naturel aléatoire
 * \return Un naturel aléatoire entre 0 et une borne supérieure donnée
 */
  unsigned int obtenirNaturelAleatoire(unsigned int borneMax);

#endif
