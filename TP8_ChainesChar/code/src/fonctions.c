/*!
 *  \file fonctions.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 06 December 2022 - 12:08:15
 *
 *  \brief Corps des fonctions
 *
 *
 */

#include "fonctions.h"

/* Cryptage de Cesar */
void cesar(char *str_message, int int_decal)
{
   /* Déclaration */
   int int_longueur; /* Longueur du mot à crypter */

   /* Initialisation */
   int_longueur = strlen(str_message);

   /* On crypte en décalant la lettre de int_décal lettres */
   for (int i = 0; i < int_longueur; i++)
   {
      /* Si le char actuel n'est pas une lettre, on le laisse tel quel */
      if (((int)str_message[i] >= 97) && ((int)str_message[i] <= 122))
      {
         /* Si le code ASCII de la nouvelle lettre dépasse celui de z on revient au début de l'alphabet */
         if (((int)str_message[i] + int_decal) > 122)
         {
            str_message[i] = (((int)str_message[i] + int_decal + 96) % 122);
         }
         /* Sinon on affiche la nouvelle lettre */
         else
         {
            str_message[i] = ((int)str_message[i] + int_decal);
         }
      }
   }

   printf("Le message crypté est : %s \n", str_message);
}

/* Cryptage de Vigenère (décalage d'indice selon un mot clé) */
void vigenere(char *str_message, char *str_cle)
{
   /* Déclaration */
   int int_longueur;    /* Longueur du mot à crypter */
   int int_longueurCle; /* Longueur de la clé */

   /* Initialisation */
   int_longueur = strlen(str_message);
   int_longueurCle = strlen(str_cle);

   /* On crypte en décalant la lettre en fonction de la clé */
   for (int i = 0; i < int_longueur; i++)
   {
      /* Si le char actuel n'est pas une lettre, on le laisse tel quel */
      if (((int)str_message[i] >= 97) && ((int)str_message[i] <= 122))
      {
         /* Si le code ASCII de la nouvelle lettre dépasse celui de z on revient au début de l'alphabet */
         if (((int)str_message[i] + ((int)str_cle[i % (int_longueurCle - 1)] % 97)) > 122)
         {
            str_message[i] = (((int)str_message[i] + ((int)str_cle[i % (int_longueurCle - 1)] % 97) + 96) % 122);
         }
         /* Sinon on affiche la nouvelle lettre */
         else
         {
            str_message[i] = (int)str_message[i] + ((int)str_cle[i % (int_longueurCle - 1)] % 97);
         }
      }
   }

   printf("Le message crypté est : %s \n", str_message);
}

/* Crypte un message avec la méthode de Scytale */
void scytale(char *str_message)
{
   /* Déclaration */
   int int_longueur;  /* Longueur du mot à crypter */
   char **pp_str_tab; /* Grille permettant de crypter */
   int int_cpt;       /* Compte le nombre de lettres déjà insérées dans le tableau */
   int int_taille;    /* La taille de la matrice carrée */

   /* Initialisation */
   int_longueur = strlen(str_message);
   int_cpt = 0;
   int_taille = sqrtEntiere(int_longueur);

   /* Allocation du tableau 2D */
   pp_str_tab = NULL;
   pp_str_tab = malloc(int_taille * sizeof(char *));

   for (int i = 0; i < int_taille; i++)
   {
      pp_str_tab[i] = NULL;
      pp_str_tab[i] = malloc(int_taille * sizeof(char));
   }

   /* Initialisation de la grille */
   initGrille(pp_str_tab, int_taille);

   /* On remplit la grille avec le message à crypter */
   for (int i = 0; i < int_taille; i++)
   {
      for (int j = 0; j < int_taille; j++)
      {
         if (int_cpt < int_longueur)
         {
            pp_str_tab[i][j] = str_message[int_cpt];
            int_cpt++;
         }
      }
   }

   /* On affiche le message crypté */
   printf("Le message crypté est : \n");
   for (int j = 0; j < int_taille; j++)
   {
      for (int i = 0; i < int_taille; i++)
      {
         printf("%c", pp_str_tab[i][j]);
      }
   }
   printf("\n");

   /* On libère la mémoire */
   for (int i = 0; i < int_taille; i++)
   {
      free(pp_str_tab[i]);
   }
   free(pp_str_tab);
}

/* Vérifie que le décalage est inférieur à 26 */
void verifDecalage(int int_decal)
{
   if (int_decal > 25)
   {
      ERREUR("Décalage trop grand");
      exit(ERREUR_SAISIE);
   }
}

/* Vérifie la bonne allocation d'une chaine */
void verifAlloc(char *str_chaine)
{
   if (str_chaine == NULL)
   {
      ERREUR("Erreur d'allocation");
      exit(ERREUR_SAISIE);
   }
}

/* Initialise la grille de Scytale avec des espaces */
void initGrille(char **pp_str_tab, int int_taille)
{
   for (int i = 0; i < int_taille; i++)
   {
      for (int j = 0; j < int_taille; j++)
      {
         pp_str_tab[i][j] = ' ';
      }
   }
}

/* Fait la racine carrée d'un nb, si elle n'est pas entière on fait +1 à la racine en prenant la partie entière */
int sqrtEntiere(int int_nb)
{
   /* Déclaration */
   float float_sqrt; /* La racine*/

   /* Initialisation */
   float_sqrt = sqrt(int_nb);

   /* Si le carré de la racine est bien égale à la racine alors on renvoit la racine */
   if (float_sqrt * float_sqrt == int_nb)
   {
      return (float_sqrt);
   }

   /* Sinon on renvoit la racine + 1 */
   else
   {
      return (float_sqrt + 1);
   }
}

/* Cherche la position de l'argument demandé */
int posArg(int int_nbArg, char *str_option, char **argv)
{
   /* Déclaration */
   int int_pos; /* Position de l'argument */

   /* Initialisation */
   int_pos = 0;

   for (int i = 1; i < int_nbArg; i++)
   {
      /* Si l'option est demandée mais pas renseignée, on stop */
      if ((strcmp(argv[i], str_option) == 0) && (int_pos == 0))
      {
         if ((i + 1 >= int_nbArg))
         {
            ERREUR("Manque d'arguments");
            exit(ERREUR_SAISIE);
         }

         else
         {
            int_pos = i + 1;
         }
      }
   }

   return (int_pos);
}
