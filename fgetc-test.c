#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char c = '\0';
    const char file_name[] = "input_files/life_is_funny.txt";
    FILE *f_input = NULL;

    f_input = fopen(file_name, "r");

    if (NULL == f_input)
    {
        fprintf(stderr, "problème avec l'ouverture du fichier %s\n", file_name);
    }

    while (EOF != (c = fgetc(f_input)))
    {
        printf("c=%c\n", c);
    }

    fclose(f_input);
    f_input = NULL;

    return EXIT_SUCCESS;
}