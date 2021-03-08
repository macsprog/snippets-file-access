#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    const char file_name[] = "output_files/fprintf_test.txt";
    FILE *f_output = NULL;
    double a = 1.2;
    double b = 3.0;
    double res = a * b;

    f_output = fopen(file_name, "w");

    if (NULL == f_output)
    {
        fprintf(stderr, "problème avec l'ouverture du fichier %s\n", file_name);
    }

    fprintf(f_output, "Le résultat de la multiplication de %g par %g est %g\n", a, b, res);

    fclose(f_output);
    f_output = NULL;

    return EXIT_SUCCESS;
}