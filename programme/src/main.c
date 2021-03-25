/**
* \file main.c
* \brief Programme principal
* \author Abdelhadi.Hirchi Marie.Lanternier Gawein.Le-Goff Leo.Pacary
*/
#include <time.h>
#include <stdio.h>
#include "partie.h"
#include "strategie.h"
#include "ihm.h"
#include "menu.h"


void testDev()
{
  clock_t start_t, end_t;


  int nombrePartie = 5;
  Partie partie;
  IHM affichage;
  unsigned int partieNulle;
  int victoir[3] = {0,0,0};
  Joueur winner;

  Joueur blanc = Joueur_creerJoueur(Strategie_IAAlphaBeta(), Couleur_blanc());
  Joueur noir = Joueur_creerJoueurNiveau(Strategie_IAAlphaBeta(), Couleur_noir(),7);

  //affichage = IHM_NULL();
  affichage = IHM_creerConsole();

    printf("blanc %d\n",blanc.niveau );
      printf("noir %d\n",noir.niveau );

  start_t = clock();
  for (int i = 0; i < nombrePartie; i++) {
    Partie_creerPartieClassique(&partie, noir, blanc);
    Partie_lancerPartie(&partie, affichage);
    winner = Partie_gagnant(partie,&partieNulle);
    Partie_finirPartie(&partie, affichage);
    if(partieNulle == 1)
    {
      victoir[2]++;
    }
    else
    {
      victoir[Joueur_obtenirCouleur(winner)]++;
    }
  }
    end_t = clock();
  printf("blanc : %d | noir : %d | nulle : %d\n",victoir[0],victoir[1],victoir[2] );
  printf("Temps total %f\n", (double)(end_t-start_t)/CLOCKS_PER_SEC);
  printf("Temps par partie %f\n", (double)(end_t-start_t)/CLOCKS_PER_SEC/nombrePartie);

}

int main(int argc, char const *argv[]) {
  Partie partie;
  IHM affichage;
  unsigned int valide = 1;
  traiterEntree(argc, argv, &valide, &partie, &affichage);
  if (valide)
  {
      Partie_lancerPartie(&partie, affichage);
      Partie_finirPartie(&partie, affichage);
  }
  else
  {
      afficherAide();
  }
  return 0;
}
