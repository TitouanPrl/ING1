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
    int int_choix;
    int int_retour;

    /* Affichage du menu */
    printf("1 - Tri par Insertion \n");
    printf("2 - Tri par Dénombrement \n");

    /* Demande du choix a l'utilisateur */
    printf("Quel est votre choix : ");
    int_retour = scanf("%d", &int_choix);

    /* Verification de l'entree */
    verifEntree(int_retour);

    /* Initialisation des variables */
    pint_tab = NULL;
    printf("Saisissez la taille du tableau : \n");
    int_taille = saisie();

    /* Allocation, remplissage, et affichage du tableau de base */
    pint_tab = malloc(int_taille * sizeof(int));
    defTab(pint_tab, int_taille);

    printf("Voici le tableau non-trié : \n");
    afficherTab(pint_tab, int_taille);

    /* Exécution en fonction du choix */
    switch (int_choix)
    {
    /* Tri par insertion */
    case 1:
        /* Exécution de l'algorithme de tri */
        triInsertion(pint_tab, int_taille);
        printf("\nTri en cours... \n\n");

        break;

    /* Tri par dénombrement */
    case 2:
        /* Exécution de l'algorithme de tri */
        triDenombrement(pint_tab, int_taille);
        printf("\nTri en cours... \n\n");

        break;

    /* Dans le cas par defaut, on renvoit un message d'erreur */
    default:
        ERREUR("L'exercice choisi n'est pas valide");
        exit(ERREUR_SAISIE);
        break;
    }

    /* Affichage du tableau trié */
    printf("Voici le tableau trié : \n");
    afficherTab(pint_tab, int_taille);

    /* On libère la mémoire */
    free(pint_tab);
    pint_tab = NULL;

    return (EXIT_SUCCESS);
}