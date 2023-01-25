#ifndef __FONCTIONS_H
#define __FONCTIONS_H

/*!
 *  \file fonctions.h
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 15 November 2022 - 07:03:21
 *
 *  \brief Prototypes des fonctions
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
 *  \fn float piAire(int int_nb)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 15 November 2022 - 07:15:17
 *  \brief calcule pi via l'aire d'un cercle
 *  \param int_nb le nombre de pts (x,y) à tirer aléatoirement
 *  \return la valeur de pi calculée
 */
float piAire(int int_nb);

/*!
 *  \fn float piMadhava(int int_nb)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.2
 *  \date Tue 15 November 2022 - 07:18:28
 *  \brief calcule pi via la méthode de madhava
 *  \param int_nb le nombre d'itération à effectuer
 *  \return la valeur de pi calculée
 */
float piMadhava(int int_nb);

/*!
 *  \fn float appelPiMadhava(int int_nb, int float_pi)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 15 November 2022 - 07:18:57
 *  \brief calcule pi via la méthode de madhava
 *  \param int_nb le nombre d'itération à effectuer
 *  \return la valeur de pi calculée
 */
float appelPiMadhava(int int_nb, float float_pi);

/*!
 *  \fn float piWallis(int int_nb)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 15 November 2022 - 18:15:15
 *  \brief Calcule pi via la méthode de John Wallis
 *  \param int_nb nombre d'itération
 *  \return la valeur de pi calculée
 */
float piWallis(int int_nb);

/*!
 *  \fn float appelPiWallis(int int_nb, int float_pi)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 15 November 2022 - 18:18:57
 *  \brief calcule pi via la méthode de Wallis
 *  \param int_nb le nombre d'itération à effectuer
 *  \return la valeur de pi calculée
 */
float appelPiWallis(int int_nb, float float_pi);

/*!
 *  \fn float sqrtNewton(int int_nb)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 1.1
 *  \date Tue 15 November 2022 - 18:15:15
 *  \brief Calcule sqrt2 via la méthode de Newton
 *  \param int_nb nombre d'itération
 *  \return la valeur de sqrt2 calculée
 */
float sqrtNewton(int int_nb);

/*!
 *  \fn float sqrtHalley(int int_nb)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 16 November 2022 - 14:36:10
 *  \brief Calcule sqrt2 via la méthode de Edmund Halley
 *  \param int_nb le nombre d'itération
 *  \return la valeur de sqrt2 calculée
 */
float sqrtHalley(int int_nb);

/*!
 *  \fn float sqrtSmyrne(int int_nb)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 16 November 2022 - 14:46:10
 *  \brief Calcule sqrt2 via la méthode de Théon de Smyrne
 *  \param int_nb le nombre d'itération
 *  \return la valeur de sqrt2 calculée
 */
float sqrtSmyrne(int int_nb);

#endif