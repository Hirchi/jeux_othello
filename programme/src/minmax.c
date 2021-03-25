#include <stdio.h>
#include "coups.h"
#include "utile.h"
#include "couleur.h"
#include "minmax.h"

int scoreNombrePion(Plateau plateau, Couleur couleur)
{
  return Plateau_nombrePion(plateau, couleur);
}
int scorePosition(Plateau plateau, Couleur couleur)
{

  int score = 0;
  int pointPlateau[8][8] = {
    {500,-150,30,10,10,30,-150,500},
    {-150,-250,0,0,0,0,-250,-150},
    {30,0,1,2,2,1,0,30},
    {10,0,2,16,16,2,0,10},
    {10,0,2,16,16,2,0,10},
    {30,0,1,2,2,1,0,30},
    {-150,-250,0,0,0,0,-250,-150},
    {500,-150,30,10,10,30,-150,500}
  };
  int hauteur = Plateau_obtenirHauteur(plateau);
  int largeur = Plateau_obtenirLargeur(plateau);
  Couleur couleurCase;
  for (int row = 1; row <= hauteur; row++) {
    for (int col = 1; col <= largeur; col++) {
      couleurCase = Plateau_obtenirCouleur(plateau,Position_creerPosition(col,row));
      if(couleurCase == couleur)
      {
        score += pointPlateau[col-1][row-1];
      }
      else
      {
        if(couleurCase == Couleur_complement(couleur))
          score -= pointPlateau[col-1][row-1];
      }
    }
  }
  return score;
}

int scoreMix(Plateau plateau, Couleur couleur)
{
  return scorePosition(plateau, couleur) + scoreNombrePion(plateau,couleur)*50;
}



Coup MinMax(Plateau plateau, Joueur joueur, int (*eval)(Plateau,Couleur), int profondeur)
{
  Couleur couleurJoueurEnCours = Joueur_obtenirCouleur(joueur);
  Coups listeDeCoup = Plateau_listeCoupsPossibles(plateau,couleurJoueurEnCours);
  Coups listecoupMax;
  int nombreDeCoup = Coups_longueur(listeDeCoup);
  char* platString = Plateau_plateauEnString(plateau);
  Plateau platTmp = Plateau_stringEnPlateau(platString);
  int Max = -9999999;
  int tmp;

  for (int i = 1; i <= nombreDeCoup; i++) {
    Plateau_jouerCoup(&platTmp,Coups_obtenirCoup(listeDeCoup,i));
    tmp = MinMaxMin(platTmp,couleurJoueurEnCours,profondeur-1,eval);
    if(i == 1 || tmp > Max)
    {
      Max = tmp;
      listecoupMax = Coups_creerVide();
      Coups_ajouterCoup(&listecoupMax,Coups_obtenirCoup(listeDeCoup,i));
    }
    if(tmp == Max)
    {
      Coups_ajouterCoup(&listecoupMax,Coups_obtenirCoup(listeDeCoup,i));
    }
    Plateau_detruitPlateau(&platTmp);
    platTmp = Plateau_stringEnPlateau(platString);
  }

  Plateau_detruitPlateau(&platTmp);
  Coups_libererCoups(listeDeCoup);

  int nombreAlea = obtenirNaturelAleatoire(Coups_longueur(listecoupMax)-1)+1;
  return Coups_obtenirCoup(listecoupMax,nombreAlea);
}

int MinMaxMin(Plateau plateau, Couleur couleurJoueurEnCours, int profondeur, int (*eval)(Plateau,Couleur))
{
  if(profondeur <= 0 || Plateau_estRempli(plateau) )
  {
    return (*eval)(plateau,couleurJoueurEnCours);
  }
  if(Plateau_nombrePion(plateau, couleurJoueurEnCours) == 0)
  {
    return -10000;
  }
  if(Plateau_nombrePion(plateau,Couleur_complement(couleurJoueurEnCours)) == 0)
  {
    return 10000;
  }

  int Min = 999999;
  Coups listeDeCoup = Plateau_listeCoupsPossibles(plateau,Couleur_complement(couleurJoueurEnCours));
  int nombreDeCoup = Coups_longueur(listeDeCoup);
  if(nombreDeCoup==0) return MinMaxMax(plateau,couleurJoueurEnCours,profondeur-1,eval);
  char* platString = Plateau_plateauEnString(plateau);
  Plateau platTmp = Plateau_stringEnPlateau(platString);
  int tmp;
  int i = 1;
  while (i <= nombreDeCoup) {
    Plateau_jouerCoup(&platTmp,Coups_obtenirCoup(listeDeCoup,i));
    tmp = MinMaxMax(platTmp,couleurJoueurEnCours,profondeur-1,eval);
    if(i == 1 || tmp < Min)
    {
      Min = tmp;
    }
    Plateau_detruitPlateau(&platTmp);
    platTmp = Plateau_stringEnPlateau(platString);
    i++;
  }

  Plateau_detruitPlateau(&platTmp);
  Coups_libererCoups(listeDeCoup);
  return Min;
}

int MinMaxMax(Plateau plateau, Couleur couleurJoueurEnCours, int profondeur, int (*eval)(Plateau,Couleur))
{
  if(profondeur <= 0 || Plateau_estRempli(plateau) )
  {
    return (*eval)(plateau,couleurJoueurEnCours);
  }
  if(Plateau_nombrePion(plateau, couleurJoueurEnCours) == 0)
  {
    return -10000;
  }
  if(Plateau_nombrePion(plateau,Couleur_complement(couleurJoueurEnCours)) == 0)
  {
    return 10000;
  }
  Coups listeDeCoup = Plateau_listeCoupsPossibles(plateau,couleurJoueurEnCours);
  int nombreDeCoup = Coups_longueur(listeDeCoup);
  int Max = -999999;
  if(nombreDeCoup==0) return MinMaxMin(plateau,couleurJoueurEnCours,profondeur-1,eval);

  char* platString = Plateau_plateauEnString(plateau);
  Plateau platTmp = Plateau_stringEnPlateau(platString);
  int tmp;
  int i = 1;
  while(i <= nombreDeCoup)
  {
    Plateau_jouerCoup(&platTmp,Coups_obtenirCoup(listeDeCoup,i));
    tmp = MinMaxMin(platTmp,couleurJoueurEnCours,profondeur-1,eval);
    if(i == 1 || tmp > Max)
    {
      Max = tmp;
    }
    Plateau_detruitPlateau(&platTmp);
    platTmp = Plateau_stringEnPlateau(platString);

    i++;
  }

  Plateau_detruitPlateau(&platTmp);
  Coups_libererCoups(listeDeCoup);
  return Max;
}


Coup AlphaBeta(Plateau plateau, Joueur joueur, int (*eval)(Plateau,Couleur), int profondeur)
{
  Couleur couleurJoueurEnCours = Joueur_obtenirCouleur(joueur);
  Coups listeDeCoup = Plateau_listeCoupsPossibles(plateau,couleurJoueurEnCours);
  Coups listecoupMax;
  int nombreDeCoup = Coups_longueur(listeDeCoup);
  char* platString = Plateau_plateauEnString(plateau);
  Plateau platTmp = Plateau_stringEnPlateau(platString);
  int Max = -9999999;
  int tmp;

  for (int i = 1; i <= nombreDeCoup; i++) {
    Plateau_jouerCoup(&platTmp,Coups_obtenirCoup(listeDeCoup,i));
    tmp = AlphaBetaMin(platTmp,couleurJoueurEnCours,profondeur-1,eval,Max);
    if(i == 1 || tmp > Max)
    {
      Max = tmp;
      listecoupMax = Coups_creerVide();
      Coups_ajouterCoup(&listecoupMax,Coups_obtenirCoup(listeDeCoup,i));
    }
    if(tmp == Max)
    {
      Coups_ajouterCoup(&listecoupMax,Coups_obtenirCoup(listeDeCoup,i));
    }
    Plateau_detruitPlateau(&platTmp);
    platTmp = Plateau_stringEnPlateau(platString);
  }

  Plateau_detruitPlateau(&platTmp);
  Coups_libererCoups(listeDeCoup);

  int nombreAlea = obtenirNaturelAleatoire(Coups_longueur(listecoupMax)-1)+1;
  return Coups_obtenirCoup(listecoupMax,nombreAlea);
}

int AlphaBetaMin(Plateau plateau, Couleur couleurJoueurEnCours, int profondeur, int (*eval)(Plateau,Couleur), int MaxPrecedent)
{
  if(profondeur <= 0 || Plateau_estRempli(plateau) )
  {
    return (*eval)(plateau,couleurJoueurEnCours);
  }
  if(Plateau_nombrePion(plateau, couleurJoueurEnCours) == 0)
  {
    return -10000;
  }
  if(Plateau_nombrePion(plateau,Couleur_complement(couleurJoueurEnCours)) == 0)
  {
    return 10000;
  }

  int Min = 999999;
  Coups listeDeCoup = Plateau_listeCoupsPossibles(plateau,Couleur_complement(couleurJoueurEnCours));
  int nombreDeCoup = Coups_longueur(listeDeCoup);
  if(nombreDeCoup==0) return AlphaBetaMax(plateau,couleurJoueurEnCours,profondeur-1,eval,Min);
  char* platString = Plateau_plateauEnString(plateau);
  Plateau platTmp = Plateau_stringEnPlateau(platString);
  int tmp;
  int i = 1;
  while (i <= nombreDeCoup && Min > MaxPrecedent) {
    Plateau_jouerCoup(&platTmp,Coups_obtenirCoup(listeDeCoup,i));
    tmp = AlphaBetaMax(platTmp,couleurJoueurEnCours,profondeur-1,eval,Min);
    if(i == 1 || tmp < Min)
    {
      Min = tmp;
    }
    Plateau_detruitPlateau(&platTmp);
    platTmp = Plateau_stringEnPlateau(platString);
    i++;
  }

  Plateau_detruitPlateau(&platTmp);
  Coups_libererCoups(listeDeCoup);
  return Min;
}

int AlphaBetaMax(Plateau plateau, Couleur couleurJoueurEnCours, int profondeur, int (*eval)(Plateau,Couleur), int MinPrecedent)
{
  if(profondeur <= 0 || Plateau_estRempli(plateau) )
  {
    return (*eval)(plateau,couleurJoueurEnCours);
  }
  if(Plateau_nombrePion(plateau, couleurJoueurEnCours) == 0)
  {
    return -10000;
  }
  if(Plateau_nombrePion(plateau,Couleur_complement(couleurJoueurEnCours)) == 0)
  {
    return 10000;
  }
  Coups listeDeCoup = Plateau_listeCoupsPossibles(plateau,couleurJoueurEnCours);
  int nombreDeCoup = Coups_longueur(listeDeCoup);
  int Max = -999999;
  if(nombreDeCoup==0) return AlphaBetaMin(plateau,couleurJoueurEnCours,profondeur-1,eval,Max);

  char* platString = Plateau_plateauEnString(plateau);
  Plateau platTmp = Plateau_stringEnPlateau(platString);
  int tmp;
  int i = 1;
  while(i <= nombreDeCoup && MinPrecedent > Max)
  {
    Plateau_jouerCoup(&platTmp,Coups_obtenirCoup(listeDeCoup,i));
    tmp = AlphaBetaMin(platTmp,couleurJoueurEnCours,profondeur-1,eval,Max);
    if(i == 1 || tmp > Max)
    {
      Max = tmp;
    }
    Plateau_detruitPlateau(&platTmp);
    platTmp = Plateau_stringEnPlateau(platString);

    i++;
  }

  Plateau_detruitPlateau(&platTmp);
  Coups_libererCoups(listeDeCoup);
  return Max;
}
//*/

Coup obtenirCoupMinMax(Plateau plateau, Joueur joueur, int niveau)
{
  return MinMax(plateau,joueur, &scorePosition,niveau);
}

Coup obtenirCoupAlphaBeta(Plateau plateau, Joueur joueur, int niveau)
{
  Coup res = AlphaBeta(plateau,joueur, &scorePosition,niveau);
  return res;
}



//*/
