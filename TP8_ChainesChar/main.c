/*! 
 *  \file main.c
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 06 December 2022 - 12:08:26
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
 *  \date Sun 11 December 2022 - 16:26:46
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres 
 *  \return 0 si tout s'est bien passé
 */
int main (int argc, char** argv) {
     /*Déclaration des variables */
    char* str_line; /* La ligne à lire */
    size_t nb1; /* Nb de char alloués */
    int int_nb2; /* Nb réel de char de la chaine */

    /* Initialisation */
    str_line = NULL;
    nb1 = 32;

    /* Allocation */
    str_line = malloc(nb1 * sizeof(char));

    /*Vérification allocation */
    if (str_line == NULL)
    {
        ERREUR("Erreur d'allocation \n");
        exit(ERREUR_SAISIE);
    }

    /* Entrée du message à crypter */
    printf("Veuillez entrer le message à crypter : \n");
    int_nb2 = getline(&str_line, &nb1, stdin);
    printf("Le message à crypter est %s \n", str_line);
    

    printf("%d \n", (int)nb1);

     return (EXIT_SUCCESS);
}
