/*!
 *  \file main.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 07 November 2022 - 16:19:12
 *
 *  \brief Programme d'échange de valeurs
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
 *  \fn void echange(int int_nb1, int int_nb2)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 07 November 2022 - 16:21:07
 *  \brief échange 2 entiers
 *  \param int_nb1 premier entier
 *  \param int_nb2 deuxième entier
 */
void echange(int int_nb1, int int_nb2)
{
  /* Déclaration des variables */
  int int_tmp;

  /* Echange et affichage */
  printf("Avant échange : \n");
  printf("Nb1 = %d \n", int_nb1);
  printf("Nb2 = %d \n", int_nb2);

  int_tmp = int_nb1;
  int_nb1 = int_nb2;
  int_nb2 = int_tmp;

  printf("Après échange : \n");
  printf("Nb1 = %d \n", int_nb1);
  printf("Nb2 = %d \n", int_nb2);
}

/*!
 *  \fn int main (int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 07 November 2022 - 16:29:09
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres
 *  \return 0 si tout s'est bien passé
 */
int main(int argc, char **argv)
{
  /* Déclaration des variables */
  int int_nb1;
  int int_nb2;

  /* Initialisation des valeurs */
  int_nb1 = 5;
  int_nb2 = 7;

  /* Echange et affichage */
  printf("Avant appel de la fonction : \n");
  printf("Nb1 = %d \n", int_nb1);
  printf("Nb2 = %d \n", int_nb2);

  printf("Appel de la fonction échange : \n");
  echange(int_nb1, int_nb2);

  printf("Après appel de la fonction : \n");
  printf("Nb1 = %d \n", int_nb1);
  printf("Nb2 = %d \n", int_nb2);

  return (EXIT_SUCCESS);
}