/*!
 *  \file fonctions.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 15 November 2022 - 07:03:58
 *
 *  \brief Corps des fonctions
 *
 *
 */

#include "fonctions.h"

void verifEntree(int int_entree)
{
   if (int_entree == 0)
   {
      ERREUR("saisie non valide");
      exit(ERREUR_SAISIE);
   }
}

int saisie()
{
   /* Déclaration des variables */
   int int_entree;
   int int_res;

   printf("Saisissez le nombre d'itérations : \n");
   int_entree = scanf("%d", &int_res);

   /* on vérifie que l'entrée est bien conforme */
   verifEntree(int_entree);

   /* Si c'est le cas on retourne l'entrée */
   return (int_res);
}

/* Méthode Aire */
float piAire(int int_nb)
{
   /* Déclaration des variables */
   float float_pi;
   float float_randX; /* Coord X */
   float float_randY; /* Coord Y */
   int int_cpt;       /* Compteur de pts dans le cercle */
   float float_ratio; /* Ratio pts dans le cercle en fct du nb de points total */

   /* Initialisation de la seed du random */
   srand(time(NULL));
   int_cpt = 0;

   /* On crée des pts aléatoires et on vérifie s'ils sont dans le cercle */
   for (int i = 0; i < int_nb; i++)
   {
      float_randX = ((float)rand() / (float)(RAND_MAX)) * 2 - 1;
      float_randY = ((float)rand() / (float)(RAND_MAX)) * 2 - 1;

      if (sqrt(pow(float_randX, 2) + pow(float_randY, 2)) <= 1)
      {
         int_cpt++;
      }
   }

   /* Ratio pts dans le cercle en fct des pts hors cercle */
   float_ratio = (float)int_cpt / int_nb;

   /* On utilise la formule ratio = aire cercle / aire carrée */
   float_pi = float_ratio * 4;

   return (float_pi);
}

/* Méthode Madhava */
float piMadhava(int int_nb)
{
   /* On initialise pi à 0 */
   return (appelPiMadhava(int_nb, 0));
}

/* Appel récursif de Madhava */
float appelPiMadhava(int int_nb, float float_pi)
{
   /* Cas où la boucle est finie */
   if (int_nb < 0)
   {
      return (4 * float_pi);
   }
   /* Si la boucle n'est pas finie on réitère */
   else
   {
      float_pi = float_pi + (pow(-1, int_nb) / (2 * int_nb + 1));
      return (appelPiMadhava(int_nb - 1, float_pi));
   }
}

/* Méthode Wallis */
float piWallis(int int_nb)
{
   /* On initialise pi à 0 */
   return (2 * appelPiWallis(int_nb, 1));
}

/* Appel récursif Wallis */
float appelPiWallis(int int_nb, float float_pi)
{
   /* Cas où la boucle est finie */
   if (int_nb < 1)
   {
      return (float_pi);
   }
   /* Si la boucle n'est pas finie on réitère */
   else
   {
      float_pi = float_pi * (pow(2 * int_nb, 2) / (pow(2 * int_nb, 2) - 1));
      return (appelPiWallis(int_nb - 1, float_pi));
   }
}

/* Méthode Newton */
float sqrtNewton(int int_nb)
{
   /* Déclaration et initialisation des variables */
   float float_sqrt;
   float_sqrt = 1;

   /* On calcule le nb-ième terme de la suite */
   for (int i = 0; i < int_nb; i++)
   {
      float_sqrt = (float_sqrt / 2) + (1 / float_sqrt);
   }

   return (float_sqrt);
}

/* Méthode Halley */
float sqrtHalley(int int_nb)
{
   /* Déclaration et initialisation des variables */
   float float_sqrt;
   float_sqrt = 1;

   /* On calcule le nb-ième terme de la suite */
   for (int i = 0; i < int_nb; i++)
   {
      float_sqrt = float_sqrt * ((pow(float_sqrt, 2) + 6) / (3 * pow(float_sqrt, 2) + 2));
   }
   return (float_sqrt);
}

/* Méthode Smyrne */
float sqrtSmyrne(int int_nb)
{
   /* Déclaration et initialisation des variables */
   float float_pn;
   float float_qn;
   float float_tmp; /* Var temporaire pour stocker float_pn */

   float_pn = 1;
   float_qn = 1;

   /* On calcule le nb-ième terme de la suite */
   for (int i = 0; i < int_nb; i++)
   {
      float_tmp = float_pn;

      /* Première suite */
      float_pn = float_pn + (2 * float_qn);

      /* Deuxième suite */
      float_qn = float_tmp + float_qn;
   }

   /* On retourne la division des deux suites */
   return (float_pn / float_qn);
}
