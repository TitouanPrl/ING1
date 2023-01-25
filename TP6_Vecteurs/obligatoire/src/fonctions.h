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
/*!
*  \def EXIT_SUCCESS
*  \brief  Code confirmant la bonne exécution du programme
*/
#define EXIT_SUCCESS 0
/*!
*  \def ERREUR_SAISIE
*  \brief  Code d'erreur attestant qu'une erreur de saisie s'est produite
*/
#define ERREUR_SAISIE -1
/*!
*  \def EXIT_FAIL
*  \brief  Code d'erreur attestant qu'une erreur s'est produite dans l'exécution
*/
#define EXIT_FAIL -1
/*!
*  \def ERREUR
*  \brief  Message affiché quand il y a une erreur
*/
#define ERREUR(message) fprintf(stderr, "%s\n", message)
/*!
*  \def TEST
*  \brief  Message affiché pour faire des test
*/
#define TEST(message) printf("%s\n", message)
/*!
*  \def M 20
*  \brief  Taille du tableau utilisé dans le programme
*/
#define M 6
/*! 
 *  \def RED "\e[0;31m"
 *  \brief couleur rouge
 */
#define RED "\e[0;31m" 
/*! 
 *  \def YEL "\e[0;33m"
 *  \brief couleur jaune
 */
#define YEL "\e[0;33m" 
/*! 
 *  \def reset "\e[0m"
 *  \brief couleur par défaut
 */
#define reset "\e[0m" 

/*!
 *  \fn void afficherTab(int tint_tab[M])
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 10:27:01
 *  \brief Affiche un tableau donné en entrée
 *  \param tint_tab le tableau à afficher
 */
void afficherTab(int tint_tab[M]);

/*!
 *  \fn void afficherTab2M(int tint_tab[2 * M])
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 10:27:01
 *  \brief Affiche un tableau donné en entrée
 *  \param tint_tab le tableau à afficher
 */
void afficherTab2M(int tint_tab[2 * M]);

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
 *  \fn void inverser(int tab[M])
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 10:19:21
 *  \brief inverse les éléments d'un tableau sans passer par un tableau temporaire
 *  \param tab le tableau à inverser
 */
void inverser(int tint_tab[M]);

/*!
 *  \fn void somme(int tint_tab1[M], int tint_tab2[M], int tint_tabRes[2 * M])
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 11:13:39
 *  \brief Concatène deux tableaux dans un troisième
 *  \param tint_tab1 premier tableau
 *  \param tint_tab2 deuxième tableau
 *  \param tint_tabRes tableau contenant la concaténation
 */
void somme(int tint_tab1[M], int tint_tab2[M], int tint_tabRes[2 * M]);

/*!
 *  \fn int traversable(int tint_tab[M])
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 11:22:23
 *  \brief Permet de savoir si un tableau est traversable
 *  \param tint_tab tableau à vérifier
 *  \return 0 si le tab est traversable, -1 sinon
 */
int traversable(int tint_tab[M]);

/* ======= PUISSANCE 4 ======= */

/*!
 *  \fn void initialisation(int ttint_tab[M][M])
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 11:48:54
 *  \brief initialise la grille de jeu
 *  \param ttint_tab la grille de jeu
 */
void initialisation(int ttint_tab[M][M]);

/*!
 *  \fn void afficher(int ttint_tab[M][M])
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 11:51:03
 *  \brief affiche la grille de jeu
 *  \param ttint_tab la grille de jeu
 */
void afficher(int ttint_tab[M][M]);

/*!
 *  \fn int demandeVal()
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 11:57:26
 *  \brief demande la colonne où jouer
 *  \return la valeur à jouer
 */
int demandeVal();

/*!
 *  \fn int jouer(int ttint_tab[M][M], int int_joueur)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 11:59:14
 *  \brief Place le jeton du joueur en cours
 *  \param ttint_tab la grille de jeu
 *  \param int_joueur le joueur dont c'est le tour
 *  \return la valeur à jouer
 */
int jouer(int ttint_tab[M][M], int int_joueur);

/*!
 *  \fn int aGagne(int ttint_tab[M][M])
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 12:18:14
 *  \brief Vérifie l'état de la partie (Victoire, Nulle, En cours)
 *  \param ttint_tab la grille de jeu
 *  \return le numéro du joueur gagnant, 0 si nulle, -1 si en cours
 */
int aGagne(int ttint_tab[M][M]);

/*!
 *  \fn void tourDeJeu(int ttint_tab[M][M])
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 12:51:29
 *  \brief permet de jouer en alternant les joueurs jusqu'à ce que la partie soit terminée
 *  \param ttint_tab la grille de jeu
 */
void tourDeJeu(int ttint_tab[M][M]);

/*!
 *  \fn void initTab(int tint_tab[M])
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 14:19:06
 *  \brief Demande à l'utilisateur de remplir un tableau
 *  \param tint_tab le tableau à remplir
 */
void initTab(int tint_tab[M]);

#endif