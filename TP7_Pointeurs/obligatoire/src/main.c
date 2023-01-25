/*!
 *  \file main.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 10:10:42
 *
 *  \brief Programme
 *
 *
 */

#include "fonctions.h"

/*!
 *  \fn int main (int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 02 December 2022 - 10:10:58
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres
 *  \return 0 si tout s'est bien passé
 */
int main(int argc, char **argv)
{
    /* Déclaration des variables */
    int *pint_tab;
    int int_taille;

    printf("==== Bienvenue dans l'algorithme de tri Fusion ====\n\n");

    /* Initialisation des variables */
    pint_tab = NULL;
    printf("Saisissez la taille du tableau : \n");
    int_taille = saisie();

    /* Allocation, remplissage, et affichage du tableau de base */
    pint_tab = malloc(int_taille * sizeof(int));
    defTab(pint_tab, int_taille);

    printf("Voici le tableau non-trié : \n");
    afficherTab(pint_tab, int_taille);

    /* Exécution de l'algorithme de tri et affichage du tableau trié */
    triFusion(pint_tab, int_taille);
    printf("\nTri en cours... \n\n");

    printf("Voici le tableau trié : \n");
    afficherTab(pint_tab, int_taille);

    /* On libère la mémoire */
    free(pint_tab);
    pint_tab = NULL;

    return (EXIT_SUCCESS);
}