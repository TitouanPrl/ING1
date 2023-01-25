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
#include<math.h>
#include <string.h>
#include <time.h>
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
void verifEntree(int int_entree);

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
 *  \fn void triInsertion(int *pint_tab, int int_taille);
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Sun 04 December 2022 - 19:58:15
 *  \brief Tri par Insertion
 *  \param pint_tab le tableau à trier
 *  \param int_taille la taille de pint_tab
 */
void triInsertion(int *pint_tab, int int_taille);

/*!
 *  \fn void minMaxTab(int* pint_tab, int int_taille, int* pint_min, int* pint_max)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 05 December 2022 - 14:47:41
 *  \brief Trouve le min et le max d'un tableau
 *  \param pint_tab le tableau dont on cherche le min et le max
 *  \param int_taille la taille du tableau
 *  \param pint_min le minimum
 *  \param pint_max le maximum
 */
void minMaxTab(int *pint_tab, int int_taille, int *pint_min, int *pint_max);

/*!
 *  \fn void historigramme(int* pint_tab, int int_taille, int* pint_histo, int int_tailleH, int int_min)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 06 December 2022 - 09:14:06
 *  \brief détermine la fréquence d'apparition de chaque élément dans le tableau
 *  \param pint_tab le tableau à tester
 *  \param int_taille la taille du tableau
 *  \param pint_histo tableau historigramme
 *  \param int_tailleH taille du tableau historigramme
 *  \param int_min minimum du tableau
 */
void historigramme(int *pint_tab, int int_taille, int *pint_histo, int int_tailleH, int int_min);

/*!
 *  \fn void triDenombrement(int* pint_tab, int int_taille)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 06 December 2022 - 09:54:17
 *  \brief Trie une tableau de façon croissante
 *  \param pint_tab le tableau à trier
 *  \param int_taille la taille du tableau
 */
void triDenombrement(int *pint_tab, int int_taille);




#endif