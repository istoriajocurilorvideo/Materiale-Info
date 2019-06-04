#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int changeCase(int litera)
{
    if (litera >= 'a' && litera <= 'z')
        litera = litera - 32;
    else if (litera >= 'A' && litera <= 'Z')
        litera = litera + 32;

    return litera;
}

int main()
{
    /// deschidem fisierul cu r+ ca sa putem sa si scriem, sa si citim, dar
    /// sa nu ne stearga tot continutul, cum ar fi facut w+.
    FILE *file = fopen("fisier.txt", "r+");
    /// este important ca variabila cu care citim sa fie int si nu char
    /// pentru ca EOF are o valoare ce depaseste un char, dar nu depaseste un int.
    int litera;

    /// Citim litera si o verificam de EOF in aceeasi linie.
    while((litera = fgetc(file)) != EOF)
    {
        /// Citim litera si o trecem la litera mare sau mica.
        litera = changeCase(litera);

        /// Mutam indexul de scriere/citire cu o pozite la stanga
        /// Parametrul 1 este fisierul, parametrul 2 reprizinta cate pozitii ne mutam si
        /// semnul parametrului ne spune daca ne mutam la stanga sau la dreapta.
        /// Parametrul 3 are 3 optiuni: SEEK_SET ne muta indexul la 0 si apoi muta cu pozitia din
        /// parametrul 2. SEEK_CUR lasa indexul unde este si SEEK_END muta indexul la final.
        fseek(file, -1, SEEK_CUR);

        /// Scriem litera inapoi in fisier, suprascriind litera citita mai devreme.
        fputc(litera, file);

        /// Lucrul cu descriptori ce pot sa scrie si sa citeasca este putin tricky. Am uitat
        /// sa va zic la laborator, dar daca folosim acelasi FILE* pentru a scrie si a citi,
        /// este nevoie sa punem un fflush(file) pentru a finaliza update-ul.
        fflush(file);
    }

    fclose(file);
    return 0;
}
