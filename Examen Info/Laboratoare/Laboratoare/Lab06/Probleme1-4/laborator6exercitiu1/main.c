#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fileInput = fopen("fisier.txt", "r");
    char litera, linie[255];
    int i,j;

    litera = fgetc(fileInput); // citeste litera de pe primul rand
    fgetc(fileInput); // ne scapa de newline-ul ce ne trece pe randul al doilea
    fgets(linie, sizeof(linie),fileInput); // citeste linia de pe randul 2, pana la EOF.
    fclose(fileInput); // Inchidem fisierul cand stim ca am terminat de citit.

    printf("%c %s\n", litera, linie);

    int lungimeLinie = strlen(linie);
    for( i=0; i < lungimeLinie; i++)
    {
        if(linie[i]==litera)
        {
            // Mutam toate elementele cu o pozitie la stanga cand gasim
            // o litera ce trebuie eliminata.
            for (j = i; j < lungimeLinie - 1; j++)
                linie[j] = linie[j+1];

            // Pentru ca noi tot duplicam ultimul element, este necesar mutam si
            // finalul stringului. Incercati sa rulati programul si fara linia asta.
            linie[lungimeLinie-1] = '\0';
        }
    }

    printf("%s\n", linie);

    // Scriem in alt fisier.
    FILE *fileOutput = fopen("fisierOutput.txt", "w");
    fputs(linie, fileOutput);

    //
    fileInput = fopen("fisier.txt", "a");
    fputc('\n', fileInput);
    fputs(linie, fileInput);

    return 0;
}
