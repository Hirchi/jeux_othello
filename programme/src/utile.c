#include "utile.h"
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


unsigned int nbDigit(unsigned int nombre)
{
  unsigned int nombreDigit = 0;
  while((int)nombre) {
      nombre /= 10;
      nombreDigit++;
  }
  return nombreDigit;
}

unsigned int prochainNombreDansChaine(char* string)
{
  int i = 0;
  unsigned int nombre = 0;
  unsigned int start = 1;
  while (string[i] != '\0' && (isdigit(string[i]) || start))
  {
    if (isdigit(string[i]))
    {
        start = 0;
        nombre *= 10;
        nombre = nombre + (int) string[i] - ((int) '0');
    }
    i++;
  }
  return nombre;
}

unsigned int obtenirNaturelAleatoire(unsigned int borneMax)
{
  static time_t temps = 0;
  if(temps != time(NULL)) //Si on est pas a la même seconde que la dernière utilisation de obtenirNaturelAleatoire
  {
    temps = time(NULL);
    srand(temps);
  }
  return rand()%(borneMax+1);
}
