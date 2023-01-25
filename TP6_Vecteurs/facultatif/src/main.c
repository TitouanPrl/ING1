/*!
 *  \file main.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 15:36:21
 *
 *  \brief Fonction facultative TP6
 *
 *
 */

// Inclusion des entetes de librairies
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
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
 *  \def N
 *  \brief taille du mot
 */
#define N 11
   


/*!
 *  \fn int palindrome(char mot[10])
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 15:37:52
 *  \brief permet de savoir si un mot est un palindrome ou non
 *  \param mot le mot à tester
 *  \return 0 si palindrome, -1 sinon
 */
int palindrome(char str_mot[N])
{
    int int_cpt;    /* Compteur du nombre de lettres qui correspondent*/
    int int_lenght;

    int_lenght = strlen(str_mot);
    int_cpt = 0;
    

    for (int i = 0; i < int_lenght/2; i++)
    {
        if (str_mot[i] == str_mot[int_lenght - 1 - i])
        {
            int_cpt++;
        }
    }

    /* On vérifie pour une taille de mot paire et impaire */
    if (int_cpt == (int_lenght / 2))
    {
        return (EXIT_SUCCESS);
    }
    else
    {
        return (EXIT_FAIL);
    }
       

}

/*!
 *  \fn int main (int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 15:37:30
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres
 *  \return 0 si tout s'est bien passé
 */
int main(int argc, char **argv)
{
    char str_mot[10]; /* mot à vérifier */
    int int_res; 

    printf("Veuillez saisir votre mot : \n");
    scanf("%s", str_mot);

    int_res = palindrome(str_mot);

    if (int_res == 0)
    {
        printf("Le mot est un palindrome \n");
    }
    else
    {
        printf("Le mot n'est pas un palindrome \n");
    }
    
    
    
    return (EXIT_SUCCESS);
}