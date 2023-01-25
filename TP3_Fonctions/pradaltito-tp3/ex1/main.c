/*!
 *  \file main.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 07 November 2022 - 14:44:52
 *
 *  \brief Algo qui permet de vérifier qu'un nombre saisie en entrée est bien un entier
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
 *  \fn int SaisieEntier(void)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 1.1
 *  \date Mon 07 November 2022 - 14:48:22
 *  \brief vérifie que le nb en entrée est bien un entier
 *  \return 0 si nb est un entier, -1 sinon
 */
int SaisieEntier(void)
{
  /* Déclaration des variables */
  float float_nb;
  int int_tmp;
  int int_entree;

  /* Lecture et vérification de l'entrée */
  printf("Veuillez saisir un entier :\n");
  int_entree = scanf("%f", &float_nb);
  verifEntree(int_entree);

  /* On transforme l'entrée en entier */
  int_tmp = (int)float_nb;

  /* On vérifie que l'entrée corresponde bien à un entier */
  if (float_nb == int_tmp)
  {
    return (float_nb);
  }
  else
  {
    ERREUR("nb pas entier");
    exit(ERREUR_SAISIE);
  }
}

/*!
 *  \fn int main (int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 07 November 2022 - 14:46:15
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres
 *  \return 0 si tout s'est bien passé
 */
int main(int argc, char **argv)
{
  /* Déclaration des var */
  int float_nb;

  /* Appel de la fonction */
  float_nb = SaisieEntier();

  /* Affichage de l'entier */
  printf("Votre entier est : %d \n", float_nb);
  return (EXIT_SUCCESS);
}