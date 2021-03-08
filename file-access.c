#include <stdlib.h>

#include <stdio.h> /* stdio.h est nécessaire pour accéder aux fonctions et type 
                        qui permettent de manipuler les fichiers 
                    */

int main(void)
{
    char c = '\0';         // on va utiliser cette variable plus tard
    FILE *f_output = NULL; /* FILE est un type défini dans stdio.h 
                        on accède à un elt de type FILE via un pointeur
                        "sous le capot" c'est cet élément de type FILE
                        qui va servir de "pont" entre les octets utilisés 
                        en mémoire par notre programme et
                        des octets stockés dans un fichier sur un
                         disque/clef usb/ (ou même plus...)
                    */
    FILE *f_input = NULL;

    /* On "pose" le pont entre un fichier du disque et  */
    f_input = fopen("input_files/life_is_funny.txt", /* c'est le nom du fichier sur le disque (string)*/
                    "r"                              /* mode d'ouverture du fichier: 
                                - "r": mode lecture
                                - "w": mode écriture
                                - voir aussi: "w+", "a", etc.
                                */
    );

    f_output = fopen("output_files/life_is_funny-MOD.txt", "w"); /* if on "ouvre" en écriture */

    if (NULL == f_input)
    {
        /* il est prudent de vérifier que fopen() a été exécutée correctement.
                       En cas de problème fopen() retourne NULL.*/
    }

    if (NULL == f_output)
    {
        /* faire quelque chose d'intelligent! */
    }

    /*
     le "pont" est ouvert entre la zone mémoire du programme et 
     le fichier appelé "life_is_funny.txt" sur le disque
     */

    /* un jeu de fonctions de la bibliothèque standard est disponible pour faire
    transiter les données: 
        - de la mémoire vers le disque (écriture):
            fputc()
            fputs()
            fprintf()

        - du disque vers de la mémoire (lecture)
            fgetc()
            fgets()
            fscanf()

    */

    c = fgetc(f_input); /* on lit un caractère depuis f_input, 
                        si on a atteint la fin du fichier, fgetc() retourne EOF
                        */
    while (EOF != c)
    {
        if (c == '.')
        {
            c = '!';
        }
        fputc(c, f_output); /* on ecrit le caractère lu 
                                        dans le fichier de sortie*/
        c = fgetc(f_input); /* on lit le caractère suivant */
    }

    fclose(f_input); /* on ferme le "pont" ouvert 
                    entre la zone mémoire du programme et 
                    le fichier */
    f_input = NULL;  /* par sécurité! */

    fclose(f_output);
    f_output = NULL;

    return EXIT_SUCCESS;
}