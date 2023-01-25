/*! 
 *  \file main.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 26 October 2022 - 14:23:15
 *
 *  \brief Programme permettant d'exécuter les différents execrices du TP
 *
 *
 */

#include "fonction.h"

/*!
 *  \fn int main (int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 25 October 2022 - 8:40:11
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres
 *  \return 0 si tout s'est bien passé
 */
int main(int argc, char **argv)
{
	int int_retour;	 /* Valeur de retour */
	int int_choix;	 /* Choix de l'utilisateur */
	int int_nb;		 /* Nombre */
	int int_nb2;	 /* Nombre */
	int int_nb3;	 /* Nombre */
	float float_res; /* Résultat numérique */
	char str_nom[29];
	char str_prenom[29];
	char str_date[50];

	/* Affichage du menu */
	printf("1 - Saisie d'un nombre\n");
	printf("2 - Saisie de 2 entiers\n");
	printf("3 - Saisie d'une personne\n");
	printf("4 - Division d'entier\n");
	printf("5 - Produit de 2 nombres\n");
	printf("6 - Prédiction\n");
	printf("7 - Compte à rebours\n\n");

	/* Demande du choix a l'utilisateur */
	printf("Quel est votre choix : ");
	int_retour = scanf("%d", &int_choix);

	/* Verification de l'entree */
	verifEntree(int_retour);

	/* Affichage du message en fonction du choix */
	switch (int_choix)
	{
	case 1:
		afficherNb(int_nb, int_retour);

		/* Si on entre autre chose qu'un entier il y aura une erreur avec le scanf */
		break;

	case 2:
		/* Saisie et affichage de 2 entiers */
		printf("Veuillez saisir un premier entier : \n");
		int_retour = scanf("%d", &int_nb);
		verifEntree(int_retour);

		printf("Veuillez saisir un deuxième  entier : \n");
		int_retour = scanf("%d", &int_nb2);
		verifEntree(int_retour);

		printf("Les entiers saisis sont %d et %d \n", int_nb, int_nb2);

		/* Si un réel est saisi il y aura une erreur dans le scanf, on peut s'en apercevoir pendant l'exécution du programme grâce à un assert ou en vérifiant la valeur renvoyé par le scanf */
		break;

	case 3:
		/* Saisie et affichage d'un profil */

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

		break;

	case 4:
		/* Division d'un entier */

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

		/* Il y aura un message d'erreur car les paramètres d'entrées sont des réels au lieu d'entiers */
		break;

	case 5:
		/* Produit de deux nombres (affiche si positif ou négatif) */

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

		break;

	case 6:
		printf("Entrez le jour : \n");
		int_retour = scanf("%d", &int_nb);
		verifEntree(int_retour);

		printf("Entrez le mois : \n");
		int_retour = scanf("%d", &int_nb2);
		verifEntree(int_retour);

		printf("Entrez l'année : \n");
		int_retour = scanf("%d", &int_nb3);
		verifEntree(int_retour);

		break;

	case 7:
		printf("Entrez la durée du compte à rebours : \n");
		int_retour = scanf("%d", &int_nb);
		verifEntree(int_retour);

		for (int i = int_nb; i >= 0; i--)
		{
			printf ("%d", i);
		}

		break;

	/* Dans le cas par defaut, on ne fait rien */
	default:
		break;
	}

	/* Fin du programme, Il se termine normalement, et donc retourne 0 */
	return (EXIT_SUCCESS);
}
