/*!
 *  \file fonctions.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 20 December 2022 - 16:36:32
 *
 *  \brief Corps des fonctions
 *
 *
 */

#include "fonctions.h"

/* Vérifie que le scanf a lu une entrée correct */
void verifEntree(int int_entree)
{
    if (int_entree == 0)
    {
        ERREUR("saisie non valide");
        exit(ERREUR_SAISIE);
    }
}

/* Affichage de la grille de jeu */
void affichage(etat **pp_etat_tab, int int_longueur, int int_hauteur)
{
    /* On affiche les numéros des colonnes */
    printf("     ");
    for (int i = 1; i <= int_longueur; i++)
    {
        if (i < 10)
        {
            printf("%d   ", i);
        }
        /* On supprime un espace pour compenser le chiffre des dizaines */
        else
        {
            printf("%d  ", i);
        }
    }
    printf("\n");

    /* On affiche la barre du haut */
    printf("   ┌");
    for (int i = 0; i < int_longueur - 1; i++)
    {
        printf("───┬");
    }
    printf("───┐\n");

    /* On affiche les lignes */
    for (int i = 0; i < int_hauteur; i++)
    {
        /* Affichage du numéro de la ligne */
        if (i < 9)
        {
            printf("%d  ", i + 1);
        }
        else
        {
            printf("%d ", i + 1);
        }

        /* Affichage de la ligne */
        for (int j = 0; j < int_longueur; j++)
        {
            /* Cas de la case non-découverte */
            if (pp_etat_tab[i][j].int_decouvert == -1)
            {
                /* Présence d'un drapeau ou non */
                if (pp_etat_tab[i][j].int_drapeau == 0)
                {
                    printf("│ 🏳 ");
                }
                else
                {
                    printf("│ ■ ");
                }
            }
            /* Case découverte */
            else
            {
                /* Bombe (ici on utilise 1 car l'initialisation à NULL dans le main empêche l'utilisation du 0)     */
                if (pp_etat_tab[i][j].int_mine == 1)
                {
                    printf("│💣 ");
                }
                /* Pas de bombe et pas de bombes voisines */
                else if ((pp_etat_tab[i][j].int_mine != 1) && (pp_etat_tab[i][j].int_voisins == 0))
                {
                    printf("│   ");
                }
                /* Pas de bombe mais voisins */
                else
                {
                    printf("│ %d ", pp_etat_tab[i][j].int_voisins);
                }
            }
        }
        printf("│\n");

        /* Affichage de la ligne séparatrice */
        if (i < int_hauteur - 1)
        {
            printf("   ├");
            for (int k = 0; k < int_longueur - 1; k++)
            {
                printf("───┼");
            }
            printf("───┤\n");
        }
    }

    /* Affichage de la dernière ligne */
    printf("   └");
    for (int i = 0; i < int_longueur - 1; i++)
    {
        printf("───┴");
    }
    printf("───┘\n");
}

/* Initialise la grille de jeu en plaçant les bombes et en comptant les voisins */
void initialisation(etat **pp_etat_tab, int int_longueur, int int_hauteur, int int_nbMines)
{
    /* Déclaration */
    int int_cpt; /* Compteur de bombes */

    /* Initialisation */
    int_cpt = 0;

    /* Initialisation de la grille de jeu, tant que le nombre de mines n'est pas atteint, on réitère */
    while (int_cpt < int_nbMines)
    {
        for (int i = 0; i < int_hauteur; i++)
        {
            for (int j = 0; j < int_longueur; j++)
            {
                /* On vérifie si on n'a pas déjà affecté */
                if ((pp_etat_tab[i][j].int_drapeau != -1))
                {
                    pp_etat_tab[i][j].int_drapeau = -1;
                    pp_etat_tab[i][j].int_decouvert = -1;
                    pp_etat_tab[i][j].int_voisins = 0;
                }

                /* On définit si la case va contenir une mine ou pas */
                if ((pp_etat_tab[i][j].int_mine != 1) && (int_cpt < int_nbMines))
                {
                    /* Une chance sur le nb de cases restantes sans mines d'avoir une mine */
                    if (rand() % ((int_longueur * int_hauteur) - int_cpt + 1) == 1)
                    {
                        pp_etat_tab[i][j].int_mine = 1;
                        int_cpt++;
                    }
                }
            }
        }
    }

    /* On attribut le nombre de mines voisines à chaque case */
    for (int i = 0; i < int_hauteur; i++)
    {
        for (int j = 0; j < int_longueur; j++)
        {
            nbVoisins(pp_etat_tab, int_longueur, int_hauteur, i, j);
        }
    }
}

/* Calcule le nombre de voisins d'une case */
void nbVoisins(etat **pp_etat_tab, int int_longueur, int int_hauteur, int int_ligne, int int_col)
{
    /* Décompte des voisins */
    for (int i = int_ligne - 1; i <= int_ligne + 1; i++)
    {
        if ((i >= 0) && (i < int_hauteur))
        {
            for (int j = int_col - 1; j <= int_col + 1; j++)
            {
                if ((j >= 0) && (j < int_longueur) && (pp_etat_tab[i][j].int_mine == 1))
                {
                    pp_etat_tab[int_ligne][int_col].int_voisins++;
                }
            }
        }
    }
}

/* Fonction permettant de jouer au démineur */
int jouer(etat **pp_etat_tab, int int_longueur, int int_hauteur, int int_ligne, int int_col, int int_nbMines, int int_cpt)
{
    /* Déclaration */
    int int_entree;
    int int_choix; /* Choix de l'action */

    /* Affichage du nombre de bombes restantes */
    printf("Mines : %d/%d \n", int_cpt, int_nbMines);

    /* On est tombé sur une bombe */
    if ((pp_etat_tab[int_ligne][int_col].int_mine == 1) && (pp_etat_tab[int_ligne][int_col].int_decouvert != -1))
    {
        /* On découvre la grille de jeu */
        decouvre(pp_etat_tab, int_longueur, int_hauteur);

        printf("BOOM ! \nVous aurez plus de chance la prochaine fois :) \n");

        return (EXIT_FAIL);
    }

    else if (gagne(pp_etat_tab, int_longueur, int_hauteur, int_nbMines) == 0)
    {
        /* On découvre la grille de jeu */
        decouvre(pp_etat_tab, int_longueur, int_hauteur);

        printf("Félicitations ! Vous avez triomphé du démineur :) \n");

        return (EXIT_SUCCESS);
    }

    /* La partie continue */
    else
    {
        /* Affichage du tableau de jeu */
        affichage(pp_etat_tab, int_longueur, int_hauteur);

        /* On demande ce que le joueur veut faire */
        printf("Que souhaitez-vous faire ? \n1- Découvrir une case \n2- Mettre un drapeau \n3- Enlever un drapeau \n");
        int_entree = scanf("%d", &int_choix);
        verifEntree(int_entree);

        /* On demande dans quelle ligne et colonne */
        int_ligne = saisieLigne(int_hauteur);
        int_col = saisieColonne(int_longueur);

        /* Choix d'actions */
        switch (int_choix)
        {
        /* Découvrir une case */
        case 1:
            /* Case déjà découverte */
            if (pp_etat_tab[int_ligne][int_col].int_decouvert != -1)
            {
                ERREUR("Case déjà découverte");
            }
            else
            {
                decouverteCase(pp_etat_tab, int_longueur, int_hauteur, int_ligne, int_col);
            }

            break;

        /* Placer un drapeau */
        case 2:
            if ((pp_etat_tab[int_ligne][int_col].int_decouvert == -1) && (pp_etat_tab[int_ligne][int_col].int_drapeau == -1) && (int_cpt < int_nbMines))
            {
                pp_etat_tab[int_ligne][int_col].int_drapeau = 0;
                int_cpt++;
            }
            else
            {
                ERREUR("\nIl y a déjà un drapeau, la case est déjà révélée, ou bien toutes les bombes ont déjà été supposées");
            }

            break;

        /* Enlever un drapeau */
        case 3:
            if ((pp_etat_tab[int_ligne][int_col].int_decouvert == -1) && (pp_etat_tab[int_ligne][int_col].int_drapeau != -1))
            {
                pp_etat_tab[int_ligne][int_col].int_drapeau = -1;
                int_cpt--;
            }
            else
            {
                ERREUR("\nIl n'y a pas de drapeau ou la case est déjà révélée");
            }

            break;

        default:
            ERREUR("\nErreur lors du choix de l'action");
            break;
        }

        /* On refait un tour de jeu */
        return (jouer(pp_etat_tab, int_longueur, int_hauteur, int_ligne, int_col, int_nbMines, int_cpt));
    }
}

/* Fonction permettant d'appeler la fonction jouer */
int appelJouer(etat **pp_etat_tab, int int_longueur, int int_hauteur)
{
    /* Déclaration */
    int int_res;     /* Le résultat de la partie */
    int int_nbMines; /* Le nombre de mines souhaitées par le joueur*/

    /* Initialisation du tableau de jeu */
    int_nbMines = demandeMines(int_longueur, int_hauteur);
    initialisation(pp_etat_tab, int_longueur, int_hauteur, int_nbMines);

    int_res = jouer(pp_etat_tab, int_longueur, int_hauteur, 0, 0, int_nbMines, 0);

    return (int_res);
}

/* Demande au joueur combien il veut placer de mines */
int demandeMines(int int_longueur, int int_hauteur)
{
    /* Déclaration */
    int int_entree;
    int int_res; /* Le nb de mines */

    /* Initialisation */
    printf("Combien souhaitez-vous placer de mines : ");
    int_entree = scanf("%d", &int_res);

    /* On vérifie que l'entrée est bien conforme */
    verifEntree(int_entree);

    /* On vérifie que le nombre de mines n'est pas supérieur ou égal à la taille de la grille de jeu */
    if ((int_res >= (int_longueur * int_hauteur)) || (int_res < 0))
    {
        /* Tant que ce n'est pas le cas, on le redemande */
        do
        {
            ERREUR("Erreur, facilitez-vous la vie :)");
            int_res = demandeMines(int_longueur, int_hauteur);
        } while (int_res >= (int_longueur * int_hauteur));
    }

    return (int_res);
}

/* Limite l'utilisateur à un entier inférieur à 50 par simplicité d'utilisation */
void doser(int int_nb)
{
    /* On vérifie que l'entrée est inférieure à 50 et supérieure à 0 */
    if ((int_nb >= 50) || (int_nb < 1))
    {
        ERREUR("Dosez.");
        exit(ERREUR_SAISIE);
    }
}

/* Demande la saisie du numéro de la ligne où jouer */
int saisieLigne(int int_hauteur)
{
    /* Déclaration des variables */
    int int_entree;
    int int_res;

    printf("Saisissez la ligne où vous souhaitez jouer : ");
    int_entree = scanf("%d", &int_res);

    /* on vérifie que l'entrée est bien conforme */
    verifEntree(int_entree);

    if ((int_res <= int_hauteur) && (int_res > 0))
    {
        /* Si c'est le cas on retourne l'entrée -1 pour passer des valeurs affichées aux valeurs utilisées en pratique */
        return (int_res - 1);
    }

    /* Sinon on redemande la saisie */
    else
    {
        ERREUR("Saisie non valide");
        return (saisieLigne(int_hauteur));
    }
}

/* Demande la saisie du numéro de la colonne où jouer */
int saisieColonne(int int_longueur)
{
    /* Déclaration des variables */
    int int_entree;
    int int_res;

    printf("Saisissez la colonne où vous souhaitez jouer : ");
    int_entree = scanf("%d", &int_res);

    /* on vérifie que l'entrée est bien conforme */
    verifEntree(int_entree);

    if ((int_res <= int_longueur) && (int_res > 0))
    {
        /* Si c'est le cas on retourne l'entrée -1 pour passer des valeurs affichées aux valeurs utilisées en pratique */
        return (int_res - 1);
    }

    /* Sinon on redemande la saisie */
    else
    {
        ERREUR("Saisie non valide");
        return (saisieColonne(int_longueur));
    }
}

/* Vérifie si la condition de victoire est respectée (aka toutes les cases sans bombes sont révélées) */
int gagne(etat **pp_etat_tab, int int_longueur, int int_hauteur, int int_nbMines)
{
    /* Déclaration */
    int int_cpt; /* Compteur du nombre de cases révélées */

    /* Initialisation */
    int_cpt = 0;

    /* Parcours de la grille de jeu et décompte du nombre de cases révélées */
    for (int i = 0; i < int_hauteur; i++)
    {
        for (int j = 0; j < int_longueur; j++)
        {
            if (pp_etat_tab[i][j].int_decouvert != -1)
            {
                int_cpt++;
            }
        }
    }

    /* Toutes les cases sans bombe sont découvertes */
    if (int_cpt == (int_hauteur * int_longueur) - int_nbMines)
    {
        return (EXIT_SUCCESS);
    }
    /* Il reste des cases cachées */
    else
    {
        return (EXIT_FAIL);
    }
}

/* Révèle la grille de jeu */
void decouvre(etat **pp_etat_tab, int int_longueur, int int_hauteur)
{
    /* On découvre toutes les cases du tableau */
    for (int i = 0; i < int_hauteur; i++)
    {
        for (int j = 0; j < int_longueur; j++)
        {
            pp_etat_tab[i][j].int_decouvert = 0;
            pp_etat_tab[i][j].int_voisins = 0;
        }
    }

    /* Affiche la grille de jeu */
    affichage(pp_etat_tab, int_longueur, int_hauteur);
}

/* Découvre les cases vides à l'emplacement donné mais aussi à ceux voisins */
void decouverteCase(etat **pp_etat_tab, int int_longueur, int int_hauteur, int int_ligne, int int_col)
{
    if (pp_etat_tab[int_ligne][int_col].int_decouvert == -1)
    {
        /* Case voisine d'une bombe */
        if (pp_etat_tab[int_ligne][int_col].int_voisins != 0)
        {
            pp_etat_tab[int_ligne][int_col].int_decouvert = 0;
        }

        /* Case sans bombe voisine */
        else
        {
            pp_etat_tab[int_ligne][int_col].int_decouvert = 0;

            /* On lance la vérification sur les voisins de cette case */
            for (int i = int_ligne - 1; i <= int_ligne + 1; i++)
            {
                if ((i >= 0) && (i < int_hauteur))
                {
                    for (int j = int_col - 1; j <= int_col + 1; j++)
                    {
                        if ((j >= 0) && (j < int_longueur))
                        {
                            decouverteCase(pp_etat_tab, int_longueur, int_hauteur, i, j);
                        }
                    }
                }
            }
        }
    }
}
