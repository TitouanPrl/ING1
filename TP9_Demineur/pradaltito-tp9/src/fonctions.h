#ifndef __FONCTIONS_H
#define __FONCTIONS_H

/*!
 *  \file fonctions.h
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 20 December 2022 - 16:36:53
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
 \def TEST
  Message affiché pour faire des test
*/
#define TEST(message) printf("%s\n", message)

/*!
 *  \struct etat
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 29 December 2022 - 14:03:47
 *  \brief Structure définissant les différnets états possibles d'une case
 */

typedef struct etat
{
  int int_mine;      /* S'il y a une mine ou non */
  int int_drapeau;   /* S'il y a un drapeau ou non */
  int int_decouvert; /* Si la case a été découverte */
  int int_voisins;   /* Nb de mines voisines */
} etat;

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
 *  \fn int saisieLigne(int int_hauteur)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 15 November 2022 - 10:35:42
 *  \brief demande la saisie du numéro de la ligne où jouer
 *  \param int_hauteur la hauteur de la grille de jeu
 *  \return l'entier saisi
 */
int saisieLigne(int int_hauteur);

/*!
 *  \fn int saisieColonne(int int_longueur)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 15 November 2022 - 10:35:42
 *  \brief demande la saisie du numéro de la colonne où jouer
 *  \param int_longueur la longueur de la grille de jeu
 *  \return l'entier saisi
 */
int saisieColonne(int int_longueur);

/*!
 *  \fn void affichage(etat **pp_etat_tab, int int_longueur, int int_hauteur)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 20 December 2022 - 16:39:53
 *  \brief affichage de la grille de jeu
 *  \param pp_etat_tab le tableau contenant l'état de la partie
 *  \param int_longueur la longueur du tableau
 *  \param int_hauteur la hauteur du tableau
 */
void affichage(etat **pp_etat_tab, int int_longueur, int int_hauteur);

/*!
 *  \fn void initialisation(etat **pp_etat_tab, int int_longueur, int int_hauteur, int int_nbMines)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 29 December 2022 - 14:38:44
 *  \brief Initialise la grille de jeu en plaçant les bombes et en comptant les voisins
 *  \param pp_etat_tab le tableau contenant l'état de la partie
 *  \param int_longueur la longueur du tableau
 *  \param int_hauteur la hauteur du tableau
 *  \param int_nbMines le nombre de mine à placer dans la grille de jeu
 */
void initialisation(etat **pp_etat_tab, int int_longueur, int int_hauteur, int int_nbMines);

/*!
 *  \fn void nbVoisins(etat **pp_etat_tab, int int_longueur, int int_hauteur, int int_ligne, int int_col)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 30 December 2022 - 15:42:39
 *  \brief calcule le nombre de voisins d'une case
 *  \param pp_etat_tab le tableau contenant l'état de la partie
 *  \param int_longueur la longueur du tableau
 *  \param int_hauteur la hauteur du tableau
 *  \param int_ligne ligne de la case
 *  \param int_col colonne de la case
 */
void nbVoisins(etat **pp_etat_tab, int int_longueur, int int_hauteur, int int_ligne, int int_col);

/*!
 *  \fn int jouer(etat **pp_etat_tab, int int_longueur, int int_hauteur, int int_ligne, int int_col, int int_nbMines, int int_cpt)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 30 December 2022 - 16:12:54
 *  \brief Fonction permettant de jouer au démineur
 *  \param pp_etat_tab le tableau contenant l'état de la partie
 *  \param int_longueur la longueur du tableau
 *  \param int_hauteur la hauteur du tableau
 *  \param int_ligne ligne de la case
 *  \param int_col colonne de la case
 *  \param int_nbMines le nombre de mine placées par l'utilisateur
 *  \param int_cpt compteur du nombre de bombes restantes
 *  \return -1 si la partie est finie, sinon on réitère
 */
int jouer(etat **pp_etat_tab, int int_longueur, int int_hauteur, int int_ligne, int int_col, int int_nbMines, int int_cpt);

/*!
 *  \fn int appelJouer(etat **pp_etat_tab, int int_longueur, int int_hauteur)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 30 December 2022 - 16:18:00
 *  \brief Fonction permettant d'appeler la fonction jouer
 *  \param pp_etat_tab le tableau contenant l'état de la partie
 *  \param int_longueur la longueur du tableau
 *  \param int_hauteur la hauteur du tableau
 *  \return 0 si tout c'est bien passé, -1 sinon
 */
int appelJouer(etat **pp_etat_tab, int int_longueur, int int_hauteur);

/*!
 *  \fn int demandeMines(int int_longueur, int int_hauteur)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 30 December 2022 - 16:22:59
 *  \brief Demande au joueur combien il veut placer de mines
 *  \param int_longueur la longueur du tableau
 *  \param int_hauteur la hauteur du tableau
 *  \return Le nombre de mines souhaitées
 */
int demandeMines(int int_longueur, int int_hauteur);

/*!
 *  \fn void doser(int_nb)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 30 December 2022 - 16:29:18
 *  \brief Limite l'utilisateur à un entier inférieur à 50 par simplicité d'utilisation, et supérieur à 0
 *  \param int_nb l'entier à vérifier
 *  \remarks Le programme peut faire avec un entier supérieur à 50 si vous enlevez cette fonction, mais l'affichage sera moins aligné
 */
void doser(int int_nb);

/*!
 *  \fn int gagne(etat **pp_etat_tab, int int_longueur, int int_hauteur, int int_nbMines)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 30 December 2022 - 21:01:15
 *  \brief Vérifie si la condition de victoire est respectée (aka toutes les cases sans bombes sont révélées)
 *  \param pp_etat_tab le tableau contenant l'état de la partie
 *  \param int_longueur la longueur du tableau
 *  \param int_hauteur la hauteur du tableau
 *  \param int_nbMines nombres de mines demandées par le joueur
 *  \return 0 si c'est le cas, -1 sinon
 */
int gagne(etat **pp_etat_tab, int int_longueur, int int_hauteur, int int_nbMines);

/*!
 *  \fn void decouvre(etat **pp_etat_tab, int int_longueur, int int_hauteur)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 30 December 2022 - 21:04:21
 *  \brief Révèle la grille de jeu
 *  \param pp_etat_tab le tableau contenant l'état de la partie
 *  \param int_longueur la longueur du tableau
 *  \param int_hauteur la hauteur du tableau
 */
void decouvre(etat **pp_etat_tab, int int_longueur, int int_hauteur);

/*!
 *  \fn void decouverteCase(etat **pp_etat_tab, int int_longueur, int int_hauteur, int int_ligne, int int_col)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 30 December 2022 - 21:35:40
 *  \brief Découvre les cases vides à l'emplacement donné mais aussi à ceux voisins
 *  \param pp_etat_tab le tableau contenant l'état de la partie
 *  \param int_longueur la longueur du tableau
 *  \param int_hauteur la hauteur du tableau
 *  \param int_ligne ligne de la case
 *  \param int_col colonne de la case
 */
void decouverteCase(etat **pp_etat_tab, int int_longueur, int int_hauteur, int int_ligne, int int_col);

#endif