/*! 
 *  \file main.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 18 October 2022 - 08:51:05
 *
 *  \brief Affiche Hello World
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
 \def EXIT_FAIL
  Code d'erreur attestant qu'une erreur s'est produite pendant l'exécution du programme
*/
#define EXIT_FAIL -1
/*! 
 \def ERREUR
  Message affiché quand il y a une erreur
*/
#define ERREUR(message) fprintf(stderr, "%s\n", message)

/*!
 *  \fn int main (int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 18 October 2022 - 08:52:09
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres 
 *  \return 0 si tout s'est bien passé
 */
int main (int argc, char** argv) {
     printf("Hello World ! \n");
     return (EXIT_SUCCESS);
}

/* Les séquences d'échappement permettent de modifier l'affichage, ici le \n fait un retour à la ligne */


fot
