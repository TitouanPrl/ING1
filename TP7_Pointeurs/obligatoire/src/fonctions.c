/*!
 *  \file fonctions.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 30 November 2022 - 14:18:40
 *
 *  \brief corps des fonctions
 *
 *
 */

#include "fonctions.h"

/* Permet de remplir un tableau */
void defTab(int *pint_tab, int int_taille)
{
    /* Initialisation de la seed du random */
    srand(time(NULL));

    /* On remplit aléatoirement les cases du tableau avec des entiers (compris entre 0 et 99 pour que ce soit plus lisible) */
    for (int i = 0; i < int_taille; i++)
    {
        pint_tab[i] = rand() % 100;
    }
}

/* Vérifie la bonne saisie d'une entrée */
void verifEntree(int int_entree)
{
    /* S'il y a une mauvaise saisie on le signale */
    if (int_entree == 0)
    {
        ERREUR("saisie non valide");
        exit(ERREUR_SAISIE);
    }
}

/* Demande la saisie d'une variable */
int saisie()
{
    /* Déclaration des variables */
    int int_entree;
    int int_res;

    /* Initialisation */
    int_entree = scanf("%d", &int_res);

    /* on vérifie que l'entrée est bien conforme */
    verifEntree(int_entree);

    /* Si c'est le cas on retourne l'entrée */
    return (int_res);
}

/* Affiche un tableau donné en entrée */
void afficherTab(int *pint_tab, int int_taille)
{
    for (int i = 0; i < (int_taille - 1); i++)
    {
        printf(" %d |", pint_tab[i]);
    }
    printf(" %d \n", pint_tab[int_taille - 1]);
}

/* Permet de copier dans un tableau dest les valeurs du tableau src allant de l'indice début à l'indice fin */
int *copierSousTab(int *pint_src, int int_debut, int int_fin)
{
    /* Déclaration */
    int *pint_dest; /* Sous tableau */
    int int_taille; /* Taille du sous tableau */

    /* Initialisation */
    int_taille = int_fin - int_debut + 1;

    /* Allocation de la mémoire */
    pint_dest = malloc(int_taille * sizeof(int));

    /* Remplissage du tableau */
    for (int i = int_debut; i <= int_fin; i++)
    {
        pint_dest[i - int_debut] = pint_src[i];
    }

    return (pint_dest);
}

/* Fusionne deux tab triés dans un tab res lui aussi trié */
void fusion(int *pint_tab1, int int_taille1, int *pint_tab2, int int_taille2, int *pint_tabRes)
{
    /* Déclaration */
    int i;
    int j;
    int int_act;
    /* Les 3 var vont servir dans les paramètres des boucles */

    /* Déclaration */
    i = 0;
    j = 0;
    int_act = 0;

    /* On fusionne les 2 sous tab en un seul tableau trié par ordre croissant */
    while (i < int_taille1 && j < int_taille2)
    {
        if (pint_tab1[i] < pint_tab2[j])
        {
            pint_tabRes[int_act] = pint_tab1[i];
            i++;
        }
        else
        {
            pint_tabRes[int_act] = pint_tab2[j];
            j++;
        }
        int_act++;
    }

    /* S'il reste des val dans le premier sous tab on les ajoute */
    while (i < int_taille1)
    {
        pint_tabRes[int_act] = pint_tab1[i];
        i++;
        int_act++;
    }

    /* S'il reste des val dans le deuxième sous tab on les ajoute */
    while (j < int_taille2)
    {
        pint_tabRes[int_act] = pint_tab2[j];
        j++;
        int_act++;
    }
}

/* Permet de trier un tableau par ordre croissant avec la méthode par fusion */
void triFusion(int *pint_tab, int int_taille)
{
    /* On vérifie s'il y a plusieurs éléments, sinon on ne fait rien */
    if (int_taille > 1)
    {
        /* Déclaration */
        int int_taille1;
        int int_taille2;
        int *pint_tab1;
        int *pint_tab2;      

        /* Initialisation */
        int_taille1 = int_taille / 2;
        int_taille2 = int_taille - int_taille1;

        /* On crée les sous tableaux */
        pint_tab1 = copierSousTab(pint_tab, 0, int_taille1 - 1);
        pint_tab2 = copierSousTab(pint_tab, int_taille1, int_taille - 1);

        /* On tri les sous tableaux et on les fusionne*/
        triFusion(pint_tab1, int_taille1);
        triFusion(pint_tab2, int_taille2);
        fusion(pint_tab1, int_taille1, pint_tab2, int_taille2, pint_tab);

        /* On libère la mémoire des sous tableaux */
        free(pint_tab1);
        free(pint_tab2);
        pint_tab1 = NULL;
        pint_tab2 = NULL;
    }
}