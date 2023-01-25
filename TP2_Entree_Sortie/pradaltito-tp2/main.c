/*!
 *  \file main.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 25 October 2022 - 8:39:33
 *
 *  \brief Programme permettant d'exécuter différentes actions en fonction du choix de l'exercice
 *
 *
 */

// Inclusion des entetes de librairies
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/*!
 \def EXIT_SUCCESS
  Code confirmant la bonne exécution du programme
*/
#define EXIT_SUCCESS 0
/*!
 \def ERREUR_SAISIE
  Code d'erreur attestant qu'une erreur de saisie s'est produite
*/
#define ERREUR_SAISIE -1
/*!
 \def EXIT_FAIL
  Code d'erreur attestant qu'une erreur s'est produite dans l'exécution
*/
#define EXIT_FAIL -1
/*!
 \def ERREUR
  Message affiché quand il y a une erreur
*/
#define ERREUR(message) fprintf(stderr, "%s\n", message)



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
	int int_jour;
	char str_mois[10];
	int int_annee;

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
	/* Saisie et affichage d'un entier */
	case 1:
		/* Saisie */
		printf("Veuillez saisir un entier : \n");

		int_retour = scanf("%d", &int_nb);
		verifEntree(int_retour);

		/* Affichage */
		printf("L'entier saisi est %d \n", int_nb);

		/* Si on entre autre chose qu'un entier il y aura une erreur avec le scanf */
		break;

	/* Saisie et affichage de 2 entiers */
	case 2:
		/* Saisies */ 
		printf("Veuillez saisir un premier entier : \n");
		int_retour = scanf("%d", &int_nb);
		verifEntree(int_retour);

		printf("Veuillez saisir un deuxième  entier : \n");
		int_retour = scanf("%d", &int_nb2);
		verifEntree(int_retour);

		/* Affichage */
		printf("Les entiers saisis sont %d et %d \n", int_nb, int_nb2);

		/* Si un réel est saisi il y aura une erreur dans le scanf, on peut s'en apercevoir pendant l'exécution du programme grâce à un assert ou en vérifiant la valeur renvoyé par le scanf */
		break;

	/* Saisie et affichage d'un profil */
	case 3:
		/* Saisie des données */
		printf("Entrez votre nom : \n");
		int_retour = scanf("%s", str_nom);
		verifEntree(int_retour);

		printf("Entrez votre prénom : \n");
		int_retour = scanf("%s", str_prenom);
		verifEntree(int_retour);

		printf ("Entrez votre date de naissance (format JJ mois AAAA) : \n");
		printf ("Entrez le jour : \n");
		int_retour = scanf("%d", &int_jour);
		verifEntree(int_retour);
		printf ("Entrez le mois : \n");
		int_retour = scanf("%s", str_mois);
		verifEntree(int_retour);
		printf ("Entrez l'année : \n"); 
		int_retour = scanf("%d", &int_annee);
		verifEntree(int_retour);

		/* Affichage des données rentrées */
		printf("Vous avez rentré : \n\n");
		printf("Nom : %s \n", str_nom);
		printf("Prénom : %s \n", str_prenom);
		printf("Date de naissance : %d %s %d \n", int_jour, str_mois, int_annee);

		break;

	/* Division d'un entier */
	case 4:
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
			printf ("%d / %d = %f \n", int_nb, int_nb2, float_res);
		}
		else
		{
			printf("Division impossible \n");
		}

		/* Il y aura un message d'erreur car les paramètres d'entrées sont des réels au lieu d'entiers */
		break;

	/* Produit de deux nombres (affiche si positif ou négatif) */
	case 5:
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

	/* Prédiction */
	case 6:
		/* On demande de saisir la date actuelle */
		printf("Entrez le jour : \n");
		int_retour = scanf("%d", &int_nb);
		verifEntree(int_retour);

		printf("Entrez le mois : \n");
		int_retour = scanf("%d", &int_nb2);
		verifEntree(int_retour);

		printf("Entrez l'année : \n");
		int_retour = scanf("%d", &int_nb3);
		verifEntree(int_retour);

		/* On calcul la date dans un jour */

		/* Cas d'un mois de 31 jours */
		if ((int_nb2 == 1 || int_nb2 == 3 || int_nb2 == 5 || int_nb2 == 7 || int_nb2 == 8 || int_nb2 == 10) && (int_nb == 31))
		{
			printf ("ALLOOOOOO");
			printf ("01/%d/%d \n", int_nb2+1, int_nb3);
		}
		/* Cas d'un mois de 30 jours */
		else if ((int_nb2 == 4 || int_nb2 == 6 || int_nb2 == 9 || int_nb2 == 11) && (int_nb == 30))
		{
			printf ("01/%d/%d \n", int_nb2+1, int_nb3);
		}
		/* Cas de décembre */
		else if ((int_nb2 == 12) && (int_nb == 31))
		{
			printf ("01/01/%d \n", int_nb3+1);
		}
		/* Cas d'un 28 février hors bissextile */
		else if ((int_nb2 == 2) && !((int_nb3 % 4 == 0 && !(int_nb3 % 100 == 0)) || (int_nb3 % 400 == 0)) && (int_nb == 28))
		{
			printf ("01/03/%d \n", int_nb3);
		}
		/* Cas d'un 29 février bissextile */
		else if ((int_nb2 == 2) && ((int_nb3 % 4 == 0 && !(int_nb3 % 100 == 0)) || (int_nb3 % 400 == 0)) && (int_nb == 29))
		{
			printf ("01/03/%d \n", int_nb3);
		}
		else
		/* Cas autre */
		{
			printf ("%d/%d/%d \n", int_nb+1, int_nb2, int_nb3);
		}
		break;

	/* Compte à rebours */
	case 7:
		/* On demande la durée du compte à rebours */
		printf("Entrez la durée du compte à rebours : \n");
		int_retour = scanf("%d", &int_nb);
		verifEntree(int_retour);

		/* Affichage du compte à rebours */
		for (int i = int_nb; i >= 0; i--)
		{
			printf ("%d \n", i);
			sleep(1);
		}

		break;
		/* On peut faire avec un Tant Que au lieu d'un Pour */

	/* Dans le cas par defaut, on ne fait rien */
	default:
		break;
	}

	/* Fin du programme, Il se termine normalement, et donc retourne 0 */
	return (EXIT_SUCCESS);
}