#include <stdlib.h>
#include <CUnit/Basic.h>
#include "partie.h"
#include "plateau.h"
#include "testPartie.h"
#include "joueur.h"

void test_cellule_creerPartieClassique_Joueurs(void)
{
  Strategie humain;
  humain = Strategie_humain();
  Partie partie;
  Joueur joueur1= Joueur_creerJoueur(humain,Couleur_blanc());
  Joueur joueur2= Joueur_creerJoueur(humain,Couleur_blanc());
  Partie_creerPartieClassique(&partie,joueur1,joueur2);

  Joueur* joueurs = Partie_obtenirJoueurs(&partie);

  CU_ASSERT_TRUE(Joueur_obtenirStrategie(joueurs[0]) == humain && Joueur_obtenirStrategie(joueurs[1]) == humain);

}

void test_cellule_creerPartieClassique_Plateau(void)
{
  Strategie humain;
  humain = Strategie_humain();
  Partie partie;
  Joueur joueur1= Joueur_creerJoueur(humain,Couleur_blanc());
  Joueur joueur2= Joueur_creerJoueur(humain,Couleur_blanc());
  Partie_creerPartieClassique(&partie,joueur1,joueur2);

  Plateau plateau = Partie_obtenirPlateau(&partie);

  CU_ASSERT_TRUE(Plateau_obtenirLargeur(plateau) == 8 && Plateau_obtenirHauteur(plateau) == 8)

}
