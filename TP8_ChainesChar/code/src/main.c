/*!
 *  \file main.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 06 December 2022 - 12:08:26
 *
 *  \brief Programme principal
 *
 *
 */

#include "fonctions.h"

/*!
 *  \fn int main (int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Sun 11 December 2022 - 16:26:46
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres
 *  \return 0 si tout s'est bien passé
 */
int main(int argc, char **argv)
{
     /*Déclaration des variables */
     char *str_message; /* La ligne à lire */
     size_t nb1;        /* Nb de char alloués */
     int int_pos;       /* Donne la position de l'argument cherché s'il est rentré */
     int int_decal;     /* Décalage code César */
     char *str_tmp;     /* Var temporaire pour lire le décalage */
     char *str_cle;     /* Clé code Vigenère */

     /* Initialisation */
     str_message = NULL;
     str_tmp = NULL;
     str_cle = NULL;
     nb1 = 32;
     int_pos = 0;

     /* Allocation */
     str_message = malloc(nb1 * sizeof(char));
     str_tmp = malloc(2 * sizeof(char));
     str_cle = malloc(nb1 * sizeof(char));

     /*Vérification allocation */
     verifAlloc(str_message);
     verifAlloc(str_tmp);
     verifAlloc(str_cle);

     /* On vérifie que les arguments sont correctements rentrés */
     if (argc < 3)
     {
          ERREUR("Pas assez d'arguments");
          exit(ERREUR_SAISIE);
     }

     /* Entrée du message à crypter */

     /* On parcourt les arguments en entrée pour savoir si l'option -m est correctement rentrée */
     int_pos = posArg(argc, "-m", argv);

     /* Si c'est le cas on lit le message */
     if (int_pos != 0)
     {
          strcpy(str_message, argv[int_pos]);
     }
     /* Sinon on le demande */
     else
     {
          printf("Veuillez entrer le message à crypter : \n");
          getline(&str_message, &nb1, stdin);
     }

     /* On convertit le message en minuscule */
     for (int i = 0; i < strlen(str_message); i++)
     {
          str_message[i] = tolower(str_message[i]);
     }

     /* On affiche la phrase à crypter */
     printf("Le message à crypter est : %s \n", str_message);

     /* On vérifie la bonne entrée de l'option de codage */
     if (strcmp(argv[1], "-c") != 0)
     {
          ERREUR("Vérifiez les options d'entrées");
          exit(ERREUR_SAISIE);
     }

     /* On exécute le cryptage demandé */

     /* César */
     if (strcmp(argv[2], "cesar") == 0)
     {
          /* On parcourt les arguments en entrée pour savoir si l'option -d est correctement rentrée */
          int_pos = posArg(argc, "-d", argv);

          /* Si c'est le cas on lit le décalage */
          if (int_pos != 0)
          {
               /* Transformation de l'ASCII en chiffre */
               strcpy(str_tmp, argv[int_pos]);
               for (int i = 0; i < strlen(str_tmp); i++)
               {
                    int_decal = str_tmp[i] - 48;
               }
          }
          /* Sinon on le demande */
          else
          {
               printf("Veuillez entrer le décalage : \n");
               scanf("%d", &int_decal);
          }

          /* Vérification du décalage */
          verifDecalage(int_decal);

          /* On lance le cryptage */
          cesar(str_message, int_decal);
     }

     else if (strcmp(argv[2], "vigenere") == 0)
     {
          /* On parcourt les arguments en entrée pour savoir si l'option -k est correctement rentrée */
          int_pos = posArg(argc, "-k", argv);

          /* Si c'est le cas on lit le décalage */
          if (int_pos != 0)
          {
               strcpy(str_cle, argv[int_pos]);
          }
          /* Sinon on le demande */
          else
          {
               printf("Veuillez entrer la clé de cryptage : \n");
               getline(&str_cle, &nb1, stdin);
          }

          /* On convertit la clé en minuscule */
          for (int i = 0; i < strlen(str_cle); i++)
          {
               str_cle[i] = tolower(str_cle[i]);
          }

          /* On lance le cryptage */
          vigenere(str_message, str_cle);
     }

     else if (strcmp(argv[2], "scytale") == 0)
     {
          /* On lance le cryptage */
          scytale(str_message);
     }

     else
     {
          ERREUR("Vérifiez le nom de la méthode de cryptage (à entrer en minuscule)");
          exit(ERREUR_SAISIE);
     }

     /* On libère la mémoire */
     free(str_message);
     free(str_tmp);
     free(str_cle);

     str_message = NULL;
     str_tmp = NULL;
     str_cle = NULL;

     return (EXIT_SUCCESS);
}
