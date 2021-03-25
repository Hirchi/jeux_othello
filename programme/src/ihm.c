#include <stdio.h>
#include "ihm.h"
#include "couleur.h"

/***********************/
/*                     */
/*       CONSOLE       */
/*                     */
/***********************/

IHM IHM_creerConsole()
{
  IHM console;
  console.afficherPlateau = &IHM_affichagePlateauConsole2;
  console.afficherText = &IHM_affichageTexteConsole;
  return console;
}

void IHM_affichagePlateauConsole(Plateau plateau)
{
  unsigned int hauteur = Plateau_obtenirHauteur(plateau);
  unsigned int largeur = Plateau_obtenirLargeur(plateau);

  Position position;
  Cellule cellule;
  Couleur couleur;
  for (char i = 'a'; i < 'a'+largeur; i++) {
    printf("%c ",i );
  }
    printf("\n");
  for (int row = 0; row < hauteur; row++) {
    printf("%d ",row+1 );
    for (int col = 0; col < largeur; col++) {
      position = Position_creerPosition(col+1,row+1);
      cellule = *(Plateau_obtenirCellule(plateau,position));
      couleur = Cellule_obtenirCouleur(cellule);
      printf("%c ", Couleur_couleurVersChar(couleur) );
    }
    printf("\n");
  }
}

void IHM_affichagePlateauConsole2(Plateau plateau)
{
  unsigned int hauteur = Plateau_obtenirHauteur(plateau);
  unsigned int largeur = Plateau_obtenirLargeur(plateau);

    Position position;
    Cellule cellule;
    Couleur couleur;
  //LIGNE DES LETTRE
  printf("   ");
  for (char i = 'a'; i < 'a'+largeur; i++) {
    printf(" %c  ",i);
  }
    printf("\n");

  //LIGNE DU HAUT
    printf("  ╔");
  for (int i = 1; i <= largeur; i++) {
    printf("═══");
    if(i != largeur)
    {
      printf("╦");
    }
    else
    {
      printf("╗");
    }
  }
  printf("\n");

  //LIGNE AFFICHAGE
  for (int row = 0; row < hauteur; row++) {
    printf("%d ", row+1);
    for (int col = 0; col < largeur; col++) {
      printf("║");
      position = Position_creerPosition(col+1,row+1);
      cellule = *(Plateau_obtenirCellule(plateau,position));
      couleur = Cellule_obtenirCouleur(cellule);
      printf(" ");
      AffichePion(couleur);
      printf(" ");
    }
    printf("║\n");

    // LIGNE SEPARATION
    if(row != hauteur-1)
    {
      printf("  ╠");
      for (int i = 0; i < largeur; i++) {
        printf("═══");
        if(i != largeur-1)
        {
          printf("╬");
        }
        else
        {
          printf("╣");
        }
      }
      printf("\n");
    }
  }

  //ligne de fin
  printf("  ╚");
  for (int i = 0; i < largeur; i++) {
    printf("═══");
    if (i != largeur-1) {
      printf("╩");
    }
    else
    {
      printf("╝");
    }
  }
  printf("\n");
}

void IHM_affichageTexteConsole(char* texte)
{
  printf("%s\n", texte);
  fflush(stdout);
}



void IHM_affichePlateau(IHM ihm, Plateau plateau)
{
  if(ihm.afficherPlateau != NULL)
  {
      (*(ihm.afficherPlateau))(plateau);
  }
}

void IHM_afficheTexte(IHM ihm, char* texte)
{
  if(ihm.afficherText != NULL)
  {
    (*(ihm.afficherText))(texte);
  }
}


IHM IHM_Tournoi()
{
    IHM affichage;
    affichage.afficherPlateau = NULL;
    affichage.afficherText = IHM_affichageTexteConsole;
    return affichage;
}
/************************/
/*                      */
/*    SANS AFFICHAGE    */
/*                      */
/************************/
IHM IHM_NULL()
{
  IHM affichage;
  affichage.afficherPlateau = NULL;
  affichage.afficherText = NULL;
  return affichage;
}


/***********************/
/*                     */
/*       COULEUR       */
/*                     */
/***********************/
void AffichePion(Couleur couleur)
{
  if(couleur == Couleur_blanc())
  {
    SetTextColorToWhite();
  }
  else
  {
    if (couleur == Couleur_noir()) {
      SetTextColorToBlack();
    }
  }
  printf("%c", Couleur_couleurVersChar(couleur));
  ResetTextColor();
}
void SetTextColorToBlack()
{
    printf("\033[0;34m");
}
void SetTextColorToWhite()
{
    printf("\033[0;37m");
}
void ResetTextColor()
{
    printf("\033[0m");
}
