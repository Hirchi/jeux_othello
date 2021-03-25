#include "cellule.h"

Cellule Cellule_creerCellule(Position position)
{
  Cellule cellule;
  cellule.couleur = SansCouleur;
  cellule.position = position;
  return cellule;
}

Position Cellule_obtenirPosition(Cellule cellule)
{
  return cellule.position;
}

Couleur Cellule_obtenirCouleur(Cellule cellule)
{
  //assert(!Cellule_estVide(cellule));
  return cellule.couleur;
}

void Cellule_placerCouleur(Cellule *cellule,Couleur couleur)
{
  cellule->couleur = couleur;
}

int Cellule_estVide(Cellule cellule)
{
  return Couleur_estSansCouleur(Cellule_obtenirCouleur(cellule));
}
