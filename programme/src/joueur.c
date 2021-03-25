#include <stdio.h>
#include <assert.h>
#include "joueur.h"
#include "couleur.h"
#include "coup.h"
#include "strategie.h"


void Joueur_assignerNom(Joueur* joueur)
{
    if (Couleur_estBlanc(Joueur_obtenirCouleur(*joueur)))
    {
        joueur->nom="blanc";
    }
    else if (Couleur_estNoir(Joueur_obtenirCouleur(*joueur)))
    {
        joueur->nom="noir";
    }
    else
    {
        joueur->nom="inconnu";
    }
}

Joueur Joueur_creerJoueur(Strategie strategie, Couleur couleur)
{
  Joueur joueur;
  joueur.strategie = strategie;
  joueur.couleur = couleur;
  joueur.niveau = 5;
  Joueur_assignerNom(&joueur);
  return joueur;
}

Joueur Joueur_creerJoueurNiveau(Strategie strategie, Couleur couleur, int niveau)
{
  Joueur joueur = Joueur_creerJoueur(strategie, couleur);
  joueur.niveau = niveau;
  return joueur;
}

char* Joueur_obtenirNom(Joueur joueur)
{
    return joueur.nom;
}

int Joueur_obtenirNiveau(Joueur joueur)
{
    assert(Joueur_obtenirStrategie(joueur) != Strategie_humain());
    return joueur.niveau;
}

Strategie Joueur_obtenirStrategie(Joueur joueur)
{
  return joueur.strategie;
}

Couleur Joueur_obtenirCouleur(Joueur joueur)
{
    return joueur.couleur;
}

Coup Joueur_obtenirCoup(Plateau p, Joueur joueur)
{
  Strategie strat = Joueur_obtenirStrategie(joueur);
  Coup resultat;
  //Impossible de faire un switch-case sans casser l'encapsulation car le compilateur ne reconnait pas Strategie_humain()
  //comme une constante
  if(strat == Strategie_humain())
  {
    resultat = obtenirCoupHumain(p, joueur);
  }
  else
  {
    if(strat == Strategie_IAMinMax())
    {
      resultat = obtenirCoupMinMax(p, joueur, Joueur_obtenirNiveau(joueur));
    }
    else
    {
      if(strat == Strategie_IAAlphaBeta())
      {
          resultat = obtenirCoupAlphaBeta(p, joueur, Joueur_obtenirNiveau(joueur));
      }
    }
  }
  return resultat;
}
