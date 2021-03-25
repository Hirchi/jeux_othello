#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "couleur.h"


const char* messageAide = "Aide du programme othello\n"
                          "Les options possibles sont :\n"
                          "  othello standard blanc|noir [profondeur] \n"
                          "    permet de jouer contre l’ ordinateur en prenant les blancs ou les noirs\n"
                          "    par défaut la profondeur d'analyse est à 7\n"
                          "  othello tournoi blanc|noir [profondeur]\n"
                          "    permet de faire jouer le programme dans un mode ’tournoi’ en lui donnant les\n"
                          "       blancs ou les noirs\n"
                          "    par défaut la profondeur d'analyse est à 7\n";

void afficherAide()
{
    printf("%s", messageAide);
}

void traiterEntree(int argc, char const *argv[], unsigned int* valide, Partie* partie, IHM* affichage)
{
    *valide = 1;
    if (argc==3 || argc == 4)
    {
        const char* mode = argv[1];
        const char* couleur = argv[2];
        int niveau;
        if(argc == 4)
        {
          niveau = atoi(argv[3]);
          if(niveau <= 2 || niveau > 8)
          {
            niveau = 7;
          }
        }
        else
        {
          niveau = 7;
        }

        if (strcmp(couleur, "blanc") == 0 || strcmp(couleur, "noir") == 0) //Strcmp vaut 0 quand deux strings sont égaux
        {
            if (strcmp(mode, "standard") == 0)
            {
                Joueur blanc, noir;
                if (strcmp(couleur, "blanc") == 0)
                {
                  blanc = Joueur_creerJoueur(Strategie_humain(), Couleur_blanc());
                  noir = Joueur_creerJoueurNiveau(Strategie_IAAlphaBeta(), Couleur_noir(),niveau);
                }
                else
                {
                  blanc = Joueur_creerJoueurNiveau(Strategie_IAAlphaBeta(), Couleur_blanc(),niveau);
                  noir = Joueur_creerJoueur(Strategie_humain(), Couleur_noir());
                }
                *affichage = IHM_creerConsole();
                Partie_creerPartieClassique(partie, noir, blanc);

            }
            else if (!strcmp(mode, "tournoi"))
            {
                Joueur blanc, noir;
                Couleur couleurProgramme;
                if (!strcmp(couleur, "blanc"))
                {
                    couleurProgramme = Couleur_blanc();
                    blanc = Joueur_creerJoueurNiveau(Strategie_IAAlphaBeta(), Couleur_blanc(),niveau);
                    noir = Joueur_creerJoueur(Strategie_humain(), Couleur_noir());
                }
                else
                {
                    couleurProgramme = Couleur_noir();
                    blanc = Joueur_creerJoueur(Strategie_humain(), Couleur_blanc());
                    noir = Joueur_creerJoueurNiveau(Strategie_IAAlphaBeta(), Couleur_noir(),niveau);
                }
                *affichage = IHM_Tournoi();
                Partie_creerPartieTournoi(partie, noir, blanc, couleurProgramme);
            }
            else
            {
                *valide = 0;
            }
        }
        else
        {
            *valide = 0;
        }
    }
    else
    {
        *valide = 0;
    }
}
