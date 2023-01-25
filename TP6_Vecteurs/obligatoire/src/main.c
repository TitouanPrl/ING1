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
    int int_retour; /* Valeur de retour */
    int int_choix;  /* Choix de l'utilisateur */
    int int_res;
    int tint_tab[M]; /* Tableau utilisé pour les 3 premiers exos */
    int tint_tab2[M];
    int tint_tabRes[2 * M];
    int ttint_tab[M][M];

    /* Affichage du menu */
    printf("1 - Inversion Tab \n");
    printf("2 - Somme Tab \n");
    printf("3 - Tab traversable \n");
    printf("4 - Puissance 4 \n");

    /* Demande du choix a l'utilisateur */
    printf("Quel est votre choix : ");
    int_retour = scanf("%d", &int_choix);

    /* Verification de l'entree */
    verifEntree(int_retour);

    /* Exécution en fonction du choix */
    switch (int_choix)
    {
    /* Inversion */
    case 1:
        /* Initialisations et affichages des tableaux */
        initTab(tint_tab);
        printf("Voici votre tableau : \n");
        afficherTab(tint_tab);

        /* Inversion */
        printf("On inverse : \n");
        inverser(tint_tab);
        afficherTab(tint_tab);

        break;

    /* Somme */
    case 2:
        /* Initialisations et affichages des tableaux */
        printf("Remplissez le premier tableau : \n");
        initTab(tint_tab);

        printf("Remplissez le deuxième tableau : \n");
        initTab(tint_tab2);

        /* Somme */
        printf("On fait la somme : \n");
        somme(tint_tab, tint_tab2, tint_tabRes);
        afficherTab2M(tint_tabRes);

        break;

    /* Traversable */
    case 3:
        /* Initialisations et affichages des tableaux */
        initTab(tint_tab);
        printf("Voici votre tableau : \n");
        afficherTab(tint_tab);

        /* Traversable */
        int_res = traversable(tint_tab);

        if (int_res == 0)
        {
            printf("Le tableau est traversable \n");
        }
        else
        {
            printf("Le tableau n'est pas traversable \n");
        }

        break;

    /* Puissance 4 */
    case 4:
        tourDeJeu(ttint_tab);

        break;

    /* Dans le cas par defaut, on renvoit un message d'erreur */
    default:
        ERREUR("L'exercice choisi n'est pas valide");
        break;
    }
    return (EXIT_SUCCESS);
}