#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("fisier.txt", "r");
    char litera1, litera2, linie[255];

    litera1 = fgetc(file); // citim litera ce trebuie inlocuita
    fgetc(file); // citim spatiul dintre litere

    litera2 = fgetc(file); // citim litera cu care trebuie sa inlocuim
    fgetc(file); // citim newline-ul ce ne trece pe randul 2.

    fgets(linie, sizeof(linie),file); // citim linia
    fclose(file); // inchidem fisierul

    printf("%c %c %s\n", litera1, litera2, linie);

    int lungimeLinie = strlen(linie);
    for(int i=0; i < lungimeLinie; i++)
    {
        if(linie[i]==litera1)
            linie[i] = litera2;
    }

    // Deschidem fisierul cu w+ pentru a sterge tot ce era in fisier inainte.
    // Cum am zis la laborator, w+ e singurul mod de deschidere cu aceasta functionalitate.
    file = fopen("fisier.txt", "w+");
    fputs(linie, file);

    return 0;
}
