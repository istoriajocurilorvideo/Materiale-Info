#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sterg (char *p, int poz, int cate)
{
    int i;
    int pLenght = strlen(p);
    int newLenght = pLenght - cate + 1;

    char *sirNou = malloc(newLenght*sizeof(char));
    for(i=0; i<poz; i++)
    {
        sirNou[i]=p[i];

    }
    for(i=poz+cate; i<pLenght; i++)
    {
        sirNou[i-cate]=p[i];

    }
    sirNou[i]=0;
    return sirNou;
}

char *inserare (char *p, char *s)
{
    int i, poz2,a,b;

    int NewLenght2 = strlen (p) + strlen (s) +1;
    scanf("%d", &poz2);
    char *sirNou2 = malloc (NewLenght2*sizeof(char));
    for(i=0; i<poz2; i++)
    {
        sirNou2[i] = p[i];

    }
    a=i;
    for(i=poz2; i<poz2 + strlen (s); i++)
    {
        sirNou2[i] = s[i-poz2];
    }

    for(i=poz2 + strlen(s); i<NewLenght2; i++)
    {
        sirNou2[i] = p[a];
        a++;
    }
    sirNou2[NewLenght2]=0;
    return sirNou2;

}
int main()
{
    int i,n,poz,cate;
    char p[20];
    printf("Pentru 1: ");
    scanf("%s", &p);
    scanf("%d%d", &poz, &cate);
    char *rez = sterg(p, poz, cate);
    printf("%s", rez);



    scanf("Pentru 2: ");
    char *rez2 = inserare ("CADOU", "DAR");
    printf("%s", rez2);


}
