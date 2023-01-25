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

/* Affiche un tableau donné en entrée */
void afficherTab(int tint_tab[M])
{
    for (int i = 0; i < M - 1; i++)
    {
        printf(" %d |", tint_tab[i]);
    }
    printf(" %d \n", tint_tab[M-1]);
}

/* Affiche un tableau de taille 2*M donné en entrée */
void afficherTab2M(int tint_tab[2 * M])
{
    for (int i = 0; i < 2 * M - 1; i++)
    {
        printf(" %d |", tint_tab[i]);
    }
    printf(" %d \n", tint_tab[(2 * M) - 1]);
}

/* Vérifie la bonne saisie d'une entrée */
void verifEntree(int int_entree)
{
    if (int_entree == 0)
    {
        ERREUR("saisie non valide");
        exit(ERREUR_SAISIE);
    }
}

/* Inverse les éléments d'un tableau sans passer par un tableau temporaire */
void inverser(int tint_tab[M])
{
    int int_tmp;
    for (int i = 0; i < M / 2; i++)
    {
        int_tmp = tint_tab[i];
        tint_tab[i] = tint_tab[M - i - 1];
        tint_tab[M - i - 1] = int_tmp;
    }
}

/* Concatène deux tableaux dans un troisième */
void somme(int tint_tab1[M], int tint_tab2[M], int tint_tabRes[2 * M])
{
    for (int i = 0; i < M; i++)
    {
        tint_tabRes[i] = tint_tab1[i];
        tint_tabRes[M + i] = tint_tab2[i];
    }
}

/* Permet de savoir si un tableau est traversable */
int traversable(int tint_tab[M])
{
    int int_pos; /* Position dans le tableau */
    int int_cpt; /* Compte le nb de cases parcourues */

    int_pos = 0;
    int_cpt = 0;

    while (int_cpt != (M - 2))
    {
        int_pos = int_pos + tint_tab[int_pos];
        int_cpt++;

        /* Si la case que l'on essaie d'atteindre n'existe pas, on arrête le code pour ne pas seg fault*/
        if (int_pos > M-1)
        {
            ERREUR("La tableau n'est pas traversable \n");
            exit(EXIT_FAIL);
        }
        
    }

    /* Le tableau est traversable */
    if (tint_tab[int_pos] == tint_tab[M - 1])
    {
        return (EXIT_SUCCESS); 
    }
    /* Le tableau n'est pas traversable */
    else
    {
        return (EXIT_FAIL); 
    }
}

/* ======= PUISSANCE 4 ======= */

/* initialise la grille de jeu */
void initialisation(int ttint_tab[M][M])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            ttint_tab[i][j] = -1; /* On initialise toutes les cases à -1 */
        }
    }
}

/* affiche la grille de jeu */
void afficher(int ttint_tab[M][M])
{
    for (int i = 0; i < M; i++)
    {
        printf("------------------------- \n");
        for (int j = 0; j < M; j++)
        {
            switch (ttint_tab[i][j])
            {
            case 1:
                printf("| " RED "X " reset);
                break;

            case 2:
                printf("| " YEL "O " reset);
                break;

            default:
                printf("|   ");
                break;
            }
        }
        printf("|");
        printf("\n");
    }
    printf("------------------------- \n\n");
}

/* demande la colonne où jouer */
int demandeVal()
{
    int valeur = 0;
    int retour = 0;

    printf("Veuillez saisir la colonne où vous voulez jouer (entre 0 la première colonne et %d la dernière) \n", M-1);
    retour = scanf("%d", &valeur);
    if (retour == 0)
    {
        ERREUR("une erreur de lecture s'est produite. \n");
        exit(ERREUR_SAISIE);
    }

    return (valeur);
}

/* Place le jeton du joueur en cours */
int jouer(int ttint_tab[M][M], int int_joueur)
{
    int res;
    int colonne;
    int i = M - 1;
    colonne = demandeVal();

    if (colonne > -1 && colonne < M)
    {
        /* Vérifie si la colonne n'est pas pleine */
        if (ttint_tab[0][colonne] == -1)
        {
            res = 1;

            /* Remonte dans la colonne tant que la case n'est pas vide */
            while (ttint_tab[i][colonne] != -1)
            {
                i--;
            }

            /* Définit le symbole à jouer en fonction du joueur dont c'est le tour */
            if (int_joueur == 1)
            {
                ttint_tab[i][colonne] = 1;
            }
            else if (int_joueur == 2)
            {
                ttint_tab[i][colonne] = 2;
            }
            else
            {
                ERREUR("une erreur de lecture s'est produite. \n");
            }
        }
        else
        {
            ERREUR("la colonne est pleine \n");
            res = 0;
        }
    }
    else
    {
        res = 0;
    }

    return (res);
}

/* Vérifie l'état de la partie (Victoire, Nulle, En cours) */
int aGagne(int ttint_tab[M][M])
{
    int int_gagne;
    int int_cpt;

    int_gagne = -1;
    int_cpt = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            /* Tests des colonnes */
            if (ttint_tab[i][j] != -1 && ttint_tab[i][j + 1] == ttint_tab[i][j] && ttint_tab[i][j + 2] == ttint_tab[i][j] && ttint_tab[i][j + 3] == ttint_tab[i][j] && j + 3 < M)
            {
                int_gagne = ttint_tab[i][j];
            }

            /* Tests des lignes */
            else if (ttint_tab[i][j] != -1 && ttint_tab[i + 1][j] == ttint_tab[i][j] && ttint_tab[i + 2][j] == ttint_tab[i][j] && ttint_tab[i + 3][j] == ttint_tab[i][j] && i + 3 < M)
            {
                int_gagne = ttint_tab[i][j];
            }

            /* Tests des diagonales */
            else if (ttint_tab[i][j] != -1 && ttint_tab[i + 1][j + 1] == ttint_tab[i][j] && ttint_tab[i + 2][j + 2] == ttint_tab[i][j] && ttint_tab[i + 3][j + 3] == ttint_tab[i][j] && j + 3 < M && i + 3 < M)
            {
                int_gagne = ttint_tab[i][j];
            }

            else if (ttint_tab[i][j] != -1 && ttint_tab[i - 1][j + 1] == ttint_tab[i][j] && ttint_tab[i - 2][j + 2] == ttint_tab[i][j] && ttint_tab[i - 3][j + 3] == ttint_tab[i][j] && j + 3 < M && i - 3 > -1)
            {
                int_gagne = ttint_tab[i][j];
            }

            /* On incrémente le nombre de cases vides */
            else if (ttint_tab[i][j] == -1)
            {
                int_cpt++;
            }
        }
    }

    /* On vérifie si la grille est pleine et que personne n'a gagné */
    if ((int_cpt == 0) && (int_gagne == -1))
    {
        int_gagne = 0;
    }

    return (int_gagne);
}

/* permet de jouer en alternant les joueurs jusqu'à ce que la partie soit terminée */
void tourDeJeu(int ttint_tab[M][M])
{
    int int_gagne = -1;
    int int_joueur = 1;

    initialisation(ttint_tab);
    while (int_gagne == -1)
    {
        afficher(ttint_tab);
        jouer(ttint_tab, int_joueur);
        int_gagne = aGagne(ttint_tab);

        int_joueur = (int_joueur % 2) + 1;
    }

    if (int_gagne == 1)
    {
        afficher(ttint_tab);
        printf("Bravo Joueur 1 ! Tu as gagné ! \n");
    }
    else if (int_gagne == 2)
    {
        afficher(ttint_tab);
        printf("Bravo Joueur 2 ! Tu as gagné ! \n");
    }
    else if (int_gagne == 0)
    {
        afficher(ttint_tab);
        printf("C'est match nul ! Laisse le gagner la prochaine fois ! \n");
    }
    else
    {
        ERREUR("Ah il y a eu une erreur \n");
    }
}

/* Demande à l'utilisateur de remplir un tableau */
void initTab(int tint_tab[M])
{
    for (int i = 0; i < M; i++)
    {
        printf("Remplissez la %dème case du tableau : \n", i + 1);
        scanf("%d", &tint_tab[i]);
    }
}
