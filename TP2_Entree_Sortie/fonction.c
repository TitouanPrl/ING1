/*!
 *  \file fonction.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 26 October 2022 - 13:14:41
 *
 *  \brief Corps des fonctions
 *
 *
 */

#include "fonction.h"

/*!
 *  \fn void verifEntree(int int_entree)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 25 October 2022 - 19:51:43
 *  \brief Vérifie que le scanf a lu une entrée correct
 *  \param int_entree : valeur retournée par le scanf (0 si la saisie a bien été effectuée)
 */
void verifEntree(int int_entree)
{
	if (int_entree == 0)
	{
		printf("Probleme de saisie\n");
		exit(ERREUR_SAISIE);
	}
}

/*!
 *  \fn void afficherNb(int int_nb, int int_retour)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 26 October 2022 - 13:17:33
 *  \brief Permet la saisie et l'affichage d'un entier
 *  \param int_nb le nombre saisie
 *  \param int_retour permet de vérifier le retour du scanf
 */
void afficherNb(int int_nb, int int_retour)
{
    printf("Veuillez saisir un entier : \n");

    int_retour = scanf("%d", &int_nb);
    verifEntree(int_retour);

    printf("L'entier saisi est %d \n", int_nb);
}

/*!
 *  \fn void afficher2Nb(int int_nb, int int_nb2, int int_retour)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 26 October 2022 - 13:22:11
 *  \brief Permet de saisir et d'afficher 2 nombres
 *  \param
 */
void afficher2Nb(int int_nb, int int_nb2, int int_retour)
{
    printf("Veuillez saisir un premier entier : \n");
    int_retour = scanf("%d", &int_nb);
    verifEntree(int_retour);

    printf("Veuillez saisir un deuxième  entier : \n");
    int_retour = scanf("%d", &int_nb2);
    verifEntree(int_retour);

    printf("Les entiers saisis sont %d et %d \n", int_nb, int_nb2);
}

/*!
 *  \fn void profil(int int_retour, char[29] str_nom, char[29] str_prenom, char[20] str_date)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 26 October 2022 - 13:54:30
 *  \brief
 *  \param
 *  \remarks
 */
void profil(int int_retour, char str_nom[29], char str_prenom[29], char str_date[20])
{
    /* Saisie des données */
    printf("Entrez votre nom : \n");
    int_retour = scanf("%s", &str_nom);
    verifEntree(int_retour);

    printf("Entrez votre prénom : ");
    int_retour = scanf("%s", &str_prenom);
    verifEntree(int_retour);

    printf("Entrez votre date de naissance (format JJ mois AAAA) : \n\n");
    int_retour = scanf("%d", &str_date);
    verifEntree(int_retour);

    /* Affichage des données rentrées */
    printf("Vous avez rentré : \n");
    printf("Nom : %s", &str_nom);
    printf("Prénom : %s", &str_prenom);
    printf("Date de naissance : %s", &str_date);
}

/*!
 *  \fn void divisionEucli(int int_retour, int int_nb, int int_nb2, float float_res)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 26 October 2022 - 14:03:00
 *  \brief
 *  \param
 *  \remarks
 */
void divisionEucli(int int_retour, int int_nb, int int_nb2, float float_res)
{
    /*	Saisie num et dénum */
    printf("Veuillez saisir le numérateur : \n");
    int_retour = scanf("%d", &int_nb);
    verifEntree(int_retour);

    printf("Veuillez saisir le dénominateur : \n");
    int_retour = scanf("%d", &int_nb2);
    verifEntree(int_retour);

    /* On vérifie que le dénum n'est pas nul */
    if (int_nb2 != 0)
    {
        float_res = int_nb / int_nb2;
        printf("%d / %d = %f \n", &int_nb, &int_nb2, &float_res);
    }
    else
    {
        printf("Division impossible \n");
    }
}

/*!
 *  \fn void multiplication(int int_retour, int int_nb, int int_nb2)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 26 October 2022 - 14:13:39
 *  \brief
 *  \param
 *  \remarks
 */
void multiplication(int int_retour, int int_nb, int int_nb2)
{
    /*	Saisie */
    printf("Veuillez saisir le premier entier : \n");
    int_retour = scanf("%d", &int_nb);
    verifEntree(int_retour);

    printf("Veuillez saisir le deuxième entier : \n");
    int_retour = scanf("%d", &int_nb2);
    verifEntree(int_retour);

    /* On vérifie le signe de chaque nombre pour savoir le signe du produit */
    if ((int_nb > 0 && int_nb2 > 0) || (int_nb < 0 && int_nb2 < 0))
    {
        printf("Le produit est positif \n");
    }
    else
    {
        printf("Le produit est négatif \n");
    }
}

/*!
 *  \fn void compteRebours(int int_nb, int int_retour)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 26 October 2022 - 14:19:48
 *  \brief
 *  \param
 *  \remarks
 */
void compteRebours(int int_nb, int int_retour)
{
    printf("Entrez la durée du compte à rebours : \n");
    int_retour = scanf("%d", &int_nb);
    verifEntree(int_retour);

    for (int i = int_nb; i >= 0; i--)
    {
        printf("%d", i);
    }
}