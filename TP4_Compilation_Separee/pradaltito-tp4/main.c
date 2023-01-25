/*!
 *  \file main.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 15 November 2022 - 07:07:21
 *
 *  \brief Programme principal
 *
 *
 */

#include "fonctions.h"

/*!
 *  \fn int main (int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 15 November 2022 - 07:07:58
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres
 *  \return 0 si tout s'est bien passé
 */
int main(int argc, char **argv)
{
    /* Déclaration des variables */
    int int_retour; /* Valeur de retour */
    int int_choix;  /* Choix de l'utilisateur */

    /* Affichage du menu */
    printf("1 - Aire d'un disque par quadrillage \n");
    printf("2 - Madhava de Sangamagrama \n");
    printf("3 - John Wallis \n");
    printf("4 - Isaac Newton \n");
    printf("5 - Edmund Halley \n");
    printf("6 - Méthode de Théon de Smyrne \n");

    /* Demande du choix a l'utilisateur */
    printf("Quel est votre choix : ");
    int_retour = scanf("%d", &int_choix);

    /* Verification de l'entree */
    verifEntree(int_retour);

    /* Exécution en fonction du choix */
    switch (int_choix)
    {
    /* Méthode Aire */
    case 1:
        printf("PI = %f \n", piAire(saisie()));
        break;

    /* Méthode Madhava */
    case 2:
        printf("PI = %f \n", piMadhava(saisie()));

        break;

    /* Méthode Wallis */
    case 3:
        printf("PI = %f \n", piWallis(saisie()));
        break;

    /* Méthode Newton */
    case 4:
        printf("sqrt(2) = %f \n", sqrtNewton(saisie()));

        break;

    /* Méthode Halley */
    case 5:
        printf("sqrt(2) = %f \n", sqrtHalley(saisie()));
        break;

    /* Méthode Smyrne */
    case 6:
        printf("sqrt(2) = %f \n", sqrtSmyrne(saisie()));

        break;

    /* Dans le cas par defaut, on renvoit un message d'erreur */
    default:
        ERREUR("L'exercice choisi n'est pas valide");
        break;
    }
    return (EXIT_SUCCESS);
}