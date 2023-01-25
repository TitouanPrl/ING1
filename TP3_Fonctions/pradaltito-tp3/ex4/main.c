/*!
 *  \file main.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 07 November 2022 - 16:46:44
 *
 *  \brief Programme permettant au choix d'afficher, un triangle, une table de multiplication, et de définir si un nombre un Armstrong
 *
 *
 */

// Inclusion des entetes de librairies
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
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
		ERREUR("saisie non valide");
		exit(ERREUR_SAISIE);
	}
}

/*!
 *  \fn void triangle()
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 07 November 2022 - 18:23:39
 *  \brief affiche un triangle de la taille voulue
 */
void triangle()
{
	/* Déclaration des variables */
	int int_hauteur;
	int int_entree;

	/* Lecture et vérification de l'entrée */
	printf("Veuillez saisir la hauteur du triangle :\n");
	int_entree = scanf("%d", &int_hauteur);
	verifEntree(int_entree);

	for (int i = 0; i < int_hauteur; i++)
	{
		/* Affichage des espaces */
		for (int j = int_hauteur - i - 1; j > 0; j--)
		{
			printf(" ");
		}

		/* Affichage des étoiles */
		for (int j = (2 * i) + 1; j > 0; j--)
		{
			printf("*");
		}

		/* Retour à la ligne */
		printf("\n");
	}
}

/*!
 *  \fn void tableMulti()
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 07 November 2022 - 17:13:46
 *  \brief affiche la table de multiplication d'un nombre
 */
void tableMulti()
{
	/* Déclaration des variables */
	int int_nb;
	int int_entree;

	/* Lecture et vérification de l'entrée */
	printf("Veuillez saisir la table de multiplication que vous souhaitez afficher :\n");
	int_entree = scanf("%d", &int_nb);
	verifEntree(int_entree);

	/* Affichage de la table */
	printf("Table de multiplication de %d : \n", int_nb);
	for (int i = 1; i < 11; i++)
	{
		printf("%d x %d = %d \n", i, int_nb, (i * int_nb));
	}
}

/*!
 *  \fn int asciiToChar(int int_ascii)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 08 November 2022 - 21:22:08
 *  \brief transforme un code ascii au chiffre qui lui correspond
 *  \param ascii le code ascii a convertir en chiffre
 *  \return le chiffre associé au code ascii
 */
int asciiToChar(int int_ascii) {
	/* Déclaration des variables */
	 int int_res;

	 /* On soustrait au code ascii du chiffre le code ascii de 0 */
	 int_res = int_ascii - 48;

	 return (int_res);
}

/*!
 *  \fn void nbArmstrong()
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 07 November 2022 - 17:26:32
 *  \brief Définit si un nombre est Armstrong ou pas
 */
void nbArmstrong()
{
	/* Déclaration des variables */
	int int_nb;	
	int int_entree;
	char str_nb[10]; /* Nombre converti en chaine de char pour pouvoir accéder à chaque chiffre */
	int int_taille; /* Nombre de chiffres du nombre */
	int int_sum;	/* Somme des puissances de chaque chiffre du nombre */

	/* Lecture et vérification de l'entrée */
	printf("Veuillez saisir un nombre :\n");
	int_entree = scanf("%d", &int_nb);
	verifEntree(int_entree);
	
	/* On transforme l'entier en chaine de char pour séparer les chiffres */
	sprintf(str_nb, "%d", int_nb);

	/* On calcule la taille du nombre */
	int_taille = strlen(str_nb);
	int_sum = 0;

	/* On calcule la somme des chiffres avec leur exposant */
	for (int i = 0; i < int_taille; i++)
	{
		int_sum += pow(asciiToChar(str_nb[i]), int_taille);
	}

	/* On compare la somme avec le nombre de base pour définir s'il est Armstrong ou non */
	if (int_sum == int_nb)
	{
		printf("Le nombre entré est un nombre Armstrong \n");
	}
	else
	{
		printf("Le nombre entré n'est pas un nombre Armstrong \n");
	}
}

/*!
 *  \fn int main (int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 07 November 2022 - 16:47:46
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres
 *  \return 0 si tout s'est bien passé
 */
int main(int argc, char **argv)
{
	/* Déclaration des variables */
	int int_retour; /* Valeur de retour */
	int int_choix;	/* Choix de l'utilisateur */

	/* Affichage du menu */
	printf("1 - Affichage d'un triangle \n");
	printf("2 - Table de multiplication \n");
	printf("3 - Nombre d'Armstrong \n");

	/* Demande du choix a l'utilisateur */
	printf("Quel est votre choix : ");
	int_retour = scanf("%d", &int_choix);

	/* Verification de l'entree */
	verifEntree(int_retour);

	/* Exécution en fonction du choix */
	switch (int_choix)
	{
	case 1:
		/* Affichage d'un triangle */
		triangle();
		break;

	case 2:
		/* Table de multiplication */
		tableMulti();

		break;

	case 3:
		/* Nombre d'Armstrong */
		nbArmstrong();

		break;

	/* Dans le cas par defaut, on renvoit un message d'erreur */
	default:
		ERREUR("Le numéro saisi n'est pas valide");
		break;
	}
	return (EXIT_SUCCESS);
}