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

/* Vérifie la bonne saisie d'une entrée */
void verifEntree(int int_entree)
{
    if (int_entree == 0)
    {
        ERREUR("saisie non valide");
        exit(ERREUR_SAISIE);
    }
}

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

/* Demande la saisie d'une variable */
int saisie()
{
    /* Déclaration des variables */
    int int_entree;
    int int_res;

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

/*========= TRI INSERTION =========*/

/* Tri par Insertion */
void triInsertion(int *pint_tab, int int_taille)
{
    int int_eltEnCours;
    int i;
    int j;

    /* On parcourt le tableau en entier */
    for (i = 0; i < int_taille; i++)
    {
        int_eltEnCours = pint_tab[i];

        /* En déplaçant au fur et à mesure la valeur la plus petite de la sélection en cours */
        for (j = i; (j > -1) && (pint_tab[j - 1] > int_eltEnCours); j--)
        {
            pint_tab[j] = pint_tab[j - 1];
        }
        pint_tab[j] = int_eltEnCours;
    }
}


        /* Seg Fault non résolue :/ */
///*========= TRI DENOMBREMENT =========*/            
//
///* Trouve le min et le max d'un tableau */
//void minMaxTab(int *pint_tab, int int_taille, int *pint_min, int *pint_max)
//{
//    /* Initialisation */
//    pint_min = &pint_tab[0];
//    pint_max = &pint_tab[0];
//
//    /* Parcours du tableau */
//    for (int i = 0; i < int_taille; i++)
//    {
//        /* On compare l'élément en cours et le max */
//        if (pint_tab[i] > *pint_max)
//        {
//            pint_max = &pint_tab[i];
//        }
//
//        /* On compare l'élément en cours et le min */
//        if (pint_tab[i] < *pint_min)
//        {
//            pint_min = &pint_tab[i];
//        }
//    }
//}
//
///* Détermine la fréquence d'apparition de chaque élément dans le tableau */
//void historigramme(int *pint_tab, int int_taille, int *pint_histo, int int_tailleH, int int_min)
//{
//    /* On initialise les cases de l'histo à 0 */
//    for (int i = 0; i < int_tailleH; i++)
//    {
//        pint_histo[i] = 0;
//    }
//
//    /* Parcours du tableau et incrémentation du nombre d'apparitions de chaque valeur */
//    for (int i = 0; i < int_taille; i++)
//    {
//        pint_histo[pint_tab[i] - int_min]++;
//    }
//}
//
///* Trie une tableau de façon croissante */
//void triDenombrement(int *pint_tab, int int_taille)
//{
//    /* Déclaration */
//    int *pint_min;   /* Min du tab à trier */
//    int *pint_max;   /* Max du tab  à trier */
//    int *pint_histo; /* Tab histo */
//    int int_tailleH; /* Taille du tab histo */
//    int k;           /* Var de boucle */
//
//    /* Initialisation */
//    pint_histo = NULL;
//    k = 0;
//    pint_min = NULL;
//    pint_max = NULL;
//    int_tailleH = 0;
//
//    /* On trouve le min et le max */
//    minMaxTab(pint_tab, int_taille, pint_min, pint_max);
//
//    /* Création de l'historigramme */
//    int_tailleH = *pint_max - *pint_min + 1;
//
//    /* Allocation */
//    pint_histo = malloc(int_tailleH * sizeof(int));
//
//    historigramme(pint_tab, int_taille, pint_histo, int_tailleH, *pint_min);
//
//    /* Création du tableau trié */
//    for (int i = 0; i < int_tailleH; i++)
//    {
//        for (int j = 0; j < pint_histo[i]; j++)
//        {
//            pint_tab[k] = i + *pint_min;
//            k++;
//        }
//    }
//
//    /* On libère la mémoire */
//    free(pint_histo);
//    pint_histo = NULL;
//}
//