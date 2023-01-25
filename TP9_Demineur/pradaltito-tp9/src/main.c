/*!
 *  \file main.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 20 December 2022 - 16:36:41
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
 *  \date Sat 31 December 2022 - 10:16:45
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres
 *  \return 0 si tout s'est bien passé
 */
int main(int argc, char **argv)
{
    /* Déclaration */
    int int_entree;     /* sortie d'un scanf */
    int int_hauteur;    /* hauteur de la grille de jeu */
    int int_longueur;   /* longueur de la grille de jeu */
    etat **pp_etat_tab; /* grille de jeu */
    int int_res;        /* résultat de la partie */

    /* Initialisation */
    int_entree = 0;

    /* Définition de la graine de  l'aléatoire */
    srand(time(NULL));

    printf("Bienvenue dans le Démineur ! \n");

    /* On fait saisir la hauteur de la grille de jeu */
    printf("Veuillez rentrer la hauteur de la grille de jeu : ");
    int_entree = scanf("%d", &int_hauteur);

    /* On vérifie que la hauteur est bien rentrée et conforme */
    verifEntree(int_entree);
    doser(int_hauteur);

    /* On fait saisir la longueur de la grille de jeu */
    printf("Veuillez rentrer la longueur de la grille de jeu : ");
    int_entree = scanf("%d", &int_longueur);

    /* On vérifie que la longueur est bien rentrée et conforme */
    verifEntree(int_entree);
    doser(int_longueur);

    /* On alloue la mémoire de la grille de jeu */
    pp_etat_tab = NULL;
    pp_etat_tab = malloc(int_hauteur * sizeof(etat *));

    for (int i = 0; i < int_hauteur; i++)
    {
        pp_etat_tab[i] = NULL;
        pp_etat_tab[i] = malloc(int_longueur * sizeof(etat));
    }

    /* On fait tourner le jeu */
    int_res = appelJouer(pp_etat_tab, int_longueur, int_hauteur);

    /* On libère la mémoire */
    for (int i = 0; i < int_hauteur; i++)
    {
        free(pp_etat_tab[i]);
        pp_etat_tab[i] = NULL;
    }
    free(pp_etat_tab);
    pp_etat_tab = NULL;

    return (int_res);
}
