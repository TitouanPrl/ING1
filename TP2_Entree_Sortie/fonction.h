#ifndef __FONCTION_H
#define __FONCTION_H

/*!
 *  \file fonction.h
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 26 October 2022 - 13:13:45
 *
 *  \brief Prototypes des fonctions
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
#define ERREUR(message) fprintf(stderr, '%s\n', message)

#endif
void verifEntree(int int_entree);

void afficherNb(int int_nb, int int_retour);

void afficher2Nb(int int_nb, int int_nb2, int int_retour);

void profil(int int_retour, char str_nom[29], char str_prenom[29], char str_date[20]);

void divisionEucli(int int_retour, int int_nb, int int_nb2, float float_res);

void multiplication(int int_retour, int int_nb, int int_nb2);

void compteRebours(int int_nb, int int_retour);


