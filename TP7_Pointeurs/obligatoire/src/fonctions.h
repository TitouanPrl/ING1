#ifndef __FONCTIONS_H
#define __FONCTIONS_H

/*!
 *  \file fonctions.h
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 30 November 2022 - 14:20:20
 *
 *  \brief Prototype des fonctions
 *
 *
 */

// Inclusion des entetes de librairies
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>
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
 *  \fn void defTab(int *pint_tab, int int_taille)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Sun 04 December 2022 - 12:10:26
 *  \brief Permet de remplir un tableau
 *  \param pint_tab le tableau à remplir
 *  \param int_taille la taille du tableau
 */
void defTab(int *pint_tab, int int_taille);

/*!
 *  \fn void verifEntree(int int_entree)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 25 October 2022 - 19:51:43
 *  \brief Vérifie que le scanf a lu une entrée correct
 *  \param int_entree : valeur retournée par le scanf (0 si la saisie a bien été effectuée)
 */
void verifEntree(int int_entree);

/*!
 *  \fn int saisie()
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 15 November 2022 - 10:35:42
 *  \brief demande la saisie d'un entier
 *  \return l'entier saisi
 */
int saisie();

/*!
 *  \fn void afficherTab(int tint_tab[M])
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 10:27:01
 *  \brief Affiche un tableau donné en entrée
 *  \param pint_tab le tableau à afficher
 */
void afficherTab(int *pint_tab, int int_taille);

/*!
 *  \fn void triFusion(int* pint_tab, int int_taille)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 05 December 2022 - 10:39:19
 *  \brief Permet de trier un tableau par ordre croissant avec la méthode par fusion
 *  \param pint_tab le tableau à trier
 *  \param int_taille la taille du tableau
 */
void triFusion(int *pint_tab, int int_taille);

/*!
 *  \fn void fusion (int* pint_tab1, int int_taille1, int* pint_tab2, int int_taille2, int* pint_tabRes)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Sun 04 December 2022 - 21:32:52
 *  \brief Fusionne deux tab triés dans un tab res lui aussi trié
 *  \param pint_tab1 premier sous tab trié
 *  \param int_taille1 taille de tab1
 *  \param pint_tab2 deuxième sous tab trié
 *  \param int_taille2 taille de tab2
 *  \param pint_tabRes tab final trié
 */
void fusion(int *pint_tab1, int int_taille1, int *pint_tab2, int int_taille2, int *pint_tabRes);

/*!
 *  \fn int* copierSousTab(int* pint_src, int int_debut, int int_fin)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Sun 04 December 2022 - 21:13:11
 *  \brief permet de copier dans un tableau dest les valeurs du tableau src allant de l'indice début à l'indice fin
 *  \param pint_src le tableau avec les valeurs à copier
 *  \param int_debut indice de début
 *  \param int_fin indice de fin
 *  \return pint_dest le sous tableau contenant les valeurs allant de debut à fin
 */
int *copierSousTab(int *pint_src, int int_debut, int int_fin);

#endif