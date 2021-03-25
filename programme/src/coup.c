#include "coup.h"

Coup Coup_creerCoup(Position position, Couleur couleur)
{
  Coup coup;
  coup.position = position;
  coup.couleur = couleur;
  return coup;
}

Couleur Coup_obtenirCouleur(Coup coup)
{
  return coup.couleur;
}

Position Coup_obtenirPosition(Coup coup)
{
  return coup.position;
}
