#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    const char file_name[] = "output_files/fputc_test.txt";
    FILE *f_output = NULL;
    char str[] = "Three little birds";

    f_output = fopen(file_name, "w");

    if (NULL == f_output)
    {
        fprintf(stderr, "problème avec l'ouverture du fichier %s\n", file_name);
    }

    for (char *ptr = str; *ptr != '\0'; ptr++)
    {
        fputc(*ptr, f_output);
        fputc('\n', f_output);
    }

    fclose(f_output);
    f_output = NULL;

    return EXIT_SUCCESS;
}