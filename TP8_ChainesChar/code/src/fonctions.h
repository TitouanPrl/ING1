#ifndef __FONCTIONS_H
#define __FONCTIONS_H

/*!
 *  \file fonctions.h
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 06 December 2022 - 12:08:44
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
#include <ctype.h>
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
 *  \fn void cesar(char* str_message, int int_decal)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 06 December 2022 - 12:09:54
 *  \brief Cryptage de Cesar
 *  \param str_message le message à crypter
 *  \param int_decal le décalage de lettre du cryptage
 */
void cesar(char *str_message, int int_decal);

/*!
 *  \fn void vigenere(char* str_message, char* str_cle)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 09 December 2022 - 10:53:40
 *  \brief Cryptage de Vigenère (décalage d'indice selon un mot clé)
 *  \param str_message mot à crypter
 *  \param str_cle la clé utilisée pour le cryptage
 */
void vigenere(char *str_message, char *str_cle);

/*!
 *  \fn void scytale(char* str_message)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 09 December 2022 - 11:05:56
 *  \brief Crypte un message avec la méthode de Scytale
 *  \param str_message le message à crypter
 */
void scytale(char *str_message);

/*!
 *  \fn void verifDecalage(int int_decal)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Sun 01 January 2023 - 18:11:12
 *  \brief Vérifie que le décalage est inférieur à 26
 *  \param int_decal le décalage
 */
void verifDecalage(int int_decal);

/*!
 *  \fn void verifAlloc(char* str_chaine)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Sun 01 January 2023 - 18:22:45
 *  \brief Vérifie la bonne allocation d'une chaine
 *  \param str_chaine la chaine dont on vérifie l'allocation
 */
void verifAlloc(char *str_chaine);

/*!
 *  \fn void initGrille(char** pp_str_tab, int int_taille)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 02 January 2023 - 12:49:21
 *  \brief Initialise la grille de Scytale avec des espaces
 *  \param pp_str_tab la grille de scytale
 *  \param int_taille la taille de la grille
 */
void initGrille(char **pp_str_tab, int int_taille);

/*!
 *  \fn int sqrtEntiere(int int_nb)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 02 January 2023 - 13:03:50
 *  \brief Fait la racine carrée d'un nb, si elle n'est pas entière on fait +1 à la racine en prenant la partie entière
 *  \param int_nb le nombre dont on veut vérifier la racine
 *  \return float_sqrt la racine entière
 */
int sqrtEntiere(int int_nb);

/*!
 *  \fn int posArg(int int_nbArg, char* str_option, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 02 January 2023 - 15:37:22
 *  \brief Cherche la position de l'argument demandé
 *  \param int_nbArg le nombre d'arguments du programme
 *  \param str_option l'option dont on cherche la position de l'argument
 *  \param argv le tableau d'arguments en entrée
 *  \return la position de l'arguments
 */
int posArg(int int_nbArg, char *str_option, char **argv);

#endif