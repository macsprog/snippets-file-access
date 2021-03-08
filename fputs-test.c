#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    const char file_name[] = "output_files/fputs_test.txt";
    FILE *f_output = NULL;
    char str[] = "Three little birds\nPerch by my doorstep";

    if (NULL == (f_output = fopen(file_name, "w")))
    {
        fprintf(stderr, "problème avec l'ouverture du fichier %s\n", file_name);
    }

    fputs(str, f_output);

    fclose(f_output);
    f_output = NULL;

    return EXIT_SUCCESS;
}