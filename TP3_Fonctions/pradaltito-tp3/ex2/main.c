/*!
 *  \file main.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 07 November 2022 - 15:38:44
 *
 *  \brief Algo qui montre la portée d'une variable
 *
 *
 */

// Inclusion des entetes de librairies
#include <stdlib.h>
#include <stdio.h>
/*!
 \def EXIT_SUCCESS
  Code confirmant la bonne exécution du programme
*/
#define EXIT_SUCCESS 0
/*!
 \def ERREUR_SAISIE
  Code d'erreur attestant qu'une erreur de saisie s'est produite
*/
#define ERREUR_SAISIE -1
/*!
 \def EXIT_FAIL
  Code d'erreur attestant qu'une erreur s'est produite dans l'exécution
*/
#define EXIT_FAIL -1
/*!
 \def ERREUR
  Message affiché quand il y a une erreur
*/
#define ERREUR(message) fprintf(stderr, "%s\n", message)

/*!
 *  \fn void verifEntree(int int_entree)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 25 October 2022 - 19:51:43
 *  \brief Vérifie que le scanf a lu une entrée correct
 *  \param int_entree : valeur retournée par le scanf (0 si la saisie a bien été effectuée)
 */
void verifEntree(int int_entree)
{
  if (int_entree == 0)
  {
    ERREUR("saisie non valide");
    exit(ERREUR_SAISIE);
  }
}

/*!
 *  \fn void bidon()
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 07 November 2022 - 15:41:30
 *  \brief saisie et lecture d'un entier
 */
void bidon()
{
  /* Déclaration des variables */
  int int_nb;
  int int_entree;

  /* Lecture, vérification et affichage de l'entrée */
  printf("Votre saisie est : %d \n", int_nb);

  printf("Veuillez saisir un entier :\n");
  int_entree = scanf("%d", &int_nb);
  verifEntree(int_entree);

  printf("Votre saisie est : %d \n", int_nb);
}

/*!
 *  \fn int main (int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 07 November 2022 - 16:08:15
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres
 *  \return 0 si tout s'est bien passé
 */
int main(int argc, char **argv)
{
  /* Déclaration des variables */
  int int_nb;
  int int_entree;

  /* Lecture, vérification et affichage de l'entrée */
  printf("Votre saisie est : %d \n", int_nb);
  printf("Veuillez saisir un entier :\n");
  int_entree = scanf("%d", &int_nb);
  verifEntree(int_entree);

  printf("Votre saisie est : %d \n", int_nb);

  bidon();

  printf("Votre saisie est : %d \n", int_nb);

  return (EXIT_SUCCESS);
}