#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "partie.h"
#include "plateau.h"
#include "position.h"
#include "strategie.h"
#include "cellule.h"
#include "ihm.h"
#include "humain.h"
#include "coups.h"
#include "joueur.h"
#include "minmax.h"
#define MAX_INPUT_SIZE  8

const char* chainePasse = "passe";

  void Partie_creerPartieClassique(Partie* partie, Joueur Noir, Joueur Blanc)
  {
    int nombreJoueur = 2;
    Joueur *tabJoueur = malloc(sizeof(Joueur)*nombreJoueur);
    tabJoueur[0] = Noir;
    tabJoueur[1] = Blanc;
    Plateau plateau = Plateau_creePlateau(8,8);
    Plateau_initialisePionDebut(&plateau);
    partie->nombreJoueur = nombreJoueur;
    partie->listeJoueur = tabJoueur;
    partie->plateau = plateau;
    partie->estTournoi = 0;
    partie->couleurProgramme = Couleur_sansCouleur();
  }

  void Partie_creerPartieTournoi(Partie* partie, Joueur Noir, Joueur Blanc, Couleur couleurProgramme)
  {
      int nombreJoueur = 2;
      Joueur *tabJoueur = malloc(sizeof(Joueur)*nombreJoueur);
      tabJoueur[0] = Noir;
      tabJoueur[1] = Blanc;
      Plateau plateau = Plateau_creePlateau(8,8);
      Plateau_initialisePionDebut(&plateau);
      partie->nombreJoueur = nombreJoueur;
      partie->listeJoueur = tabJoueur;
      partie->plateau = plateau;
      partie->estTournoi = 1;
      partie->couleurProgramme = couleurProgramme;
  }

  unsigned int Partie_estTournoi(Partie partie)
  {
    return partie.estTournoi;
  }

  Couleur Partie_obtenirCouleurProgramme(Partie partie)
  {
    assert(Partie_estTournoi(partie));
    return partie.couleurProgramme;
  }

  void Partie_lancerPartie(Partie *partie, IHM ihm)
  {
    Joueur* listeJoueur = Partie_obtenirJoueurs(partie);
    unsigned int nombreJoueur = Partie_obtenirNombreJoueur(partie);
    Plateau plateau = Partie_obtenirPlateau(partie);

    unsigned int nombreTour = 0;
    Joueur joueurQuiJoue;
    Coup coup;
    //Position posaffichage;
    do
    {
      joueurQuiJoue = listeJoueur[nombreTour % nombreJoueur];
      IHM_affichePlateau(ihm,plateau);
      if(Partie_JoueurPeutJouer(partie,joueurQuiJoue))
      {
        /*
        if(nombreTour != 0)
        {
          posaffichage = Coup_obtenirPosition(coup);
          char phrase[24] = "L'adversaire à jouer ";
          char phrase2[24];
          phrase2 = strcat(phrase,Position_positionEnChaine(posaffichage));
          IHM_afficheTexte(ihm, phrase2);
          //printf("Jouer joué %s\n", Position_positionEnChaine(posaffichage));
        }
        */
        coup = Joueur_obtenirCoup(plateau,joueurQuiJoue);
        if(Plateau_estUnCoupPossible(plateau,coup))
        {
          if (Partie_estTournoi(*partie) && Joueur_obtenirCouleur(joueurQuiJoue) == Partie_obtenirCouleurProgramme(*partie))
          {
              char* chainePosition = Position_positionEnChaine(Coup_obtenirPosition(coup));
              //printf("%s", chainePosition);
              IHM_afficheTexte(ihm, chainePosition);
              free(chainePosition);
          }
          Plateau_jouerCoup(&plateau,coup);
        }
      }
      else if (Partie_estTournoi(*partie))
      {
        if (Joueur_obtenirCouleur(joueurQuiJoue) == Partie_obtenirCouleurProgramme(*partie))
        {
          //printf("%s", chainePasse);
          IHM_afficheTexte(ihm, (char*)chainePasse);
        }
        else
        {
          char entreeAdversaire[MAX_INPUT_SIZE]; //Pour enlever le warning "maybe uninitialized"
          if (scanf("%s", entreeAdversaire) == 1)
          {
              if(strcmp(entreeAdversaire, chainePasse)) //strcmp retourne 0 si les deux chaines sont identiques
            {
              entreeAdversaire[1]= 'e'; //On fait ceci pour ne pas avoir de warning "variable inutilisée" (car on doit faire un scanf pour
                                              // attendre l'entrée de l'adversaire mais le résultat est inutile et
                                              // ecrire un message pourrait faire planter l'autre programme)
            }
          }
        }
      }

      nombreTour++;
    }
    while(!Partie_estFini(*partie));
    }

  unsigned int Partie_obtenirNombreJoueur(Partie *partie)
  {
    return partie->nombreJoueur;
  }

  Joueur* Partie_obtenirJoueurs(Partie *partie)
  {
    return partie->listeJoueur;
  }

  Plateau Partie_obtenirPlateau(Partie *partie)
  {
      return partie->plateau;
  }


  int Partie_JoueurPeutJouer(Partie* Partie, Joueur joueur)
  {
    Plateau plateau = Partie_obtenirPlateau(Partie);
    Couleur couleurJoueur = Joueur_obtenirCouleur(joueur);

    Coups listeCoups = Plateau_listeCoupsPossibles(plateau, couleurJoueur);
    int peuxJouer = (!Coups_estVide(listeCoups));
    Coups_libererCoups(listeCoups);

    return peuxJouer;

  }

  int Partie_estFini(Partie partie)
  {
    Plateau plateau = Partie_obtenirPlateau(&partie);
    Joueur* joueurs = Partie_obtenirJoueurs(&partie);
    int nbJoueur = Partie_obtenirNombreJoueur(&partie);
    int i = 0;
    Couleur couleurJoueur;
    while (i < nbJoueur) {
      couleurJoueur = Joueur_obtenirCouleur(joueurs[i]);
      Coups listcoups = Plateau_listeCoupsPossibles(plateau,couleurJoueur);
      int condition = !Coups_estVide(listcoups);
      Coups_libererCoups(listcoups);
      if(condition)
      {
        return 0;
      }
      i++;
    }
    return 1;

  }

  Joueur Partie_gagnant(Partie partie, unsigned int* estNulle)
  {
    Joueur* joueurs = Partie_obtenirJoueurs(&partie);
    int nbJoueur = Partie_obtenirNombreJoueur(&partie);
    Joueur winner;
    Plateau plateau = Partie_obtenirPlateau(&partie);
    int scoreWinner = 0;
    int nbPion;
    Couleur couleurDuJoueur;
    unsigned int tousEgaux = 1;
    for (int i = 0; i < nbJoueur; i++) {
      couleurDuJoueur = Joueur_obtenirCouleur(joueurs[i]);
      nbPion = Plateau_nombrePion(plateau,couleurDuJoueur);
      if (i!=0 && scoreWinner!=nbPion)
      {
          tousEgaux=0;
      }
      if(i == 0 || scoreWinner < nbPion)
      {
        scoreWinner = nbPion;
        winner = joueurs[i];
      }
    }
    *estNulle = tousEgaux;
    return winner;
  }

  void Partie_afficherGagnant(Partie partie, IHM ihm)
  {
      if (Partie_estFini(partie))
      {
          unsigned int estNulle;
          Joueur gagnant = Partie_gagnant(partie, &estNulle);
          if (estNulle)
          {
              //printf("%s\n", "nulle");
              IHM_afficheTexte(ihm, "nulle");
          }
          else
          {
              //printf("%s\n", Joueur_obtenirNom(gagnant));
              IHM_afficheTexte(ihm, Joueur_obtenirNom(gagnant));
          }
      }
  }

  void Partie_finirPartie(Partie *partie, IHM ihm)
  {
      Partie_afficherGagnant(*partie, ihm);
      free(Partie_obtenirJoueurs(partie));
  }
