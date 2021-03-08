#include <stdlib.h>
#include <stdio.h>

#define MAX_NB_CHAR_IN_LINE 1024

int main(void)
{
    char str[MAX_NB_CHAR_IN_LINE] = "";
    const char file_name[] = "input_files/numbers.txt";
    FILE *f_input = NULL;

    f_input = fopen(file_name, "r");

    if (NULL == f_input)
    {
        fprintf(stderr, "problème avec l'ouverture du fichier %s\n", file_name);
    }

    while ((fgets(str, MAX_NB_CHAR_IN_LINE, f_input)) != NULL)
    {
        double d = 0.0;
        printf("str=%s\n", str);
        d = atof(str);
        printf("d=%g\n", d);
    }

    fclose(f_input);
    f_input = NULL;

    return EXIT_SUCCESS;
}