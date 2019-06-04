#include <stdio.h>
#include <stdlib.h>

// O sa continui sa folosesc fseek pentru a va invata cu el si de asemenea
// va arat si o alta functie utila, ftell.
// Ca sa obtinem marimea unui fisier in octeti, exista o oarecare procedura standard.
// Deschidem fisierul normal si apoi folosim fseek pentru a ne muta la finalul
// fisierul (parametrul SEEK_END) face asta pentru noi.
// ftell ne spune valoarea indexului de citire in momentul actual sau cu alte cuvinte,
// numarul de caractere de pana in acel moment. Fiind la final, noi aflam numarul de caractere
// din tot fisierul.
// Este important apoi sa folosim fseek pentru a ne muta inapoi la inceputul fisierului.

// Cand am ajuns la exercitiul asta, m-am gandit ca nu am avut timp
// sa va arat alte doua functii importante. Sunt mult mai utile decat fgets si fputs.
// fread -> https://www.tutorialspoint.com/c_standard_library/c_function_fread.htm
// fwrite -> https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm
// Ca un scurt rezumat, fread ia 4 parametri.
// Primul este stringul sau bufferul in care sa puna ce trebuie sa citeasca.
// Al doilea este numarul de elemente pe care trebuie sa il citeasca.
// Al treilea este marimea in bytes a unui element.
// Al patrulea este fisierul.
// Noi ii spunem ca vrem sa ne puna in vectorul fileContent, de marime fsize, niste caractere (parametrul 3)
// toate luate din fisierul fp.
// Astfel, dupa fread vom avea in fileContent tot fisierul. Evident nu este optim sa incarcam tot fisierul in
// memorie...(sa ne imaginam ca aveam un fisier de 1GB...asta inseamna 1GB memorie RAM ocupata),
// dar este okay acum cand invatam.


// Am facut o structura ce tine o litera si numarul de aparitii al acesteia pentru ca este mai usor.
// Daca faceam cu un vector de int drept vector de frecventa, in momentul in care trebuia sa sortam
// rezultatele in ordinea aparitiilor, nu mai puteam sa stim ce valoare este pentru ce litera.
typedef struct litera
{
    int nr_aparitii;
    char lit;
} litera;

#define NUMAR_LITERE 26

int main()
{
    // Am pus in fisier.exe chiar codul acestui program :D. Inception!
    FILE *fp = fopen("fisier.txt", "r");

    // Ne mutam la final.
    fseek(fp, 0, SEEK_END);
    // Luam indexul de la final, practic marimea in octeti a fisierului.
    long fsize = ftell(fp);
    // Ne mutam la inceput.
    fseek(fp, 0, SEEK_SET);

    // Vector de marime fsize.
    char fileContent[fsize];

    // Citim fsize*sizeof(char) caractere din fp si le punem in fileContent.
    fread(fileContent, fsize, sizeof(char), fp);

    // Inlocuim EOF cu 0.
    fileContent[fsize] = 0;

    fclose(fp);
    printf("%s \n", fileContent);

    // un vector de frecventa pentru litere. pozitia 0 este pentru 'a', 1 este pentru 'b' etc.
    litera litere[NUMAR_LITERE];

    for(int i = 0; i < NUMAR_LITERE; i++)
    {
        litere[i].lit = i + 'a';
        litere[i].nr_aparitii = 0;
    }

    for(int i = 0; i < fsize; i++)
    {
        // Tranformam literele mari in mici, pentru ca cerinta spune ca nu conteaza case-ul.
        if (fileContent[i] >= 'A' && fileContent[i] <= 'Z')
            fileContent[i] += 32;

        // Daca am dat de o litera mica, incrementam numarul de aparitii de pe pozitia
        // corespunzatoare. De ex, daca fileContent[i] este litera c, atunci 'c' - 'a' ne
        // da 2, iar litere[2] stim ca este pozitia pentru litera c.
        if(fileContent[i] >= 'a' && fileContent[i] <= 'z')
        {
            litere[fileContent[i] - 'a'].nr_aparitii++;
        }
    }

    // Mai trebuie doar sa sortam vectorul. Folosim iar un bubble sort simplu.
   for (int i = 0; i < NUMAR_LITERE-1; i++)
   {
      for (int j = 0; j < NUMAR_LITERE-i-1; j++)
      {
          if (litere[j].nr_aparitii < litere[j+1].nr_aparitii)
          {
              litera temp = litere[j];
              litere[j] = litere[j+1];
              litere[j+1] = temp;
          }
      }
   }

    // Afisarea rezultatelor.
    for(int i = 0; i < NUMAR_LITERE; i++)
        printf("%c %d \n", litere[i].lit, litere[i].nr_aparitii);
 ///scanf("%s %d %s", &vec[i].nume, &vec[i].etaj, &vec[i].cotizatie);
    return 0;
}
