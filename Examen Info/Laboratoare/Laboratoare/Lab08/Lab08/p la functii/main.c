#include <stdio.h>
#include <stdlib.h>

struct Book
{
    int book_id;
    char title[50];
    char author[50];
    char subject[100];
    void (*printBook)(struct Book *book);
};
void printBook1(struct Book *book)
{
    printf("Book title: %s\n", book->title);
    printf("Book author: %s\n", book->author);
    printf("Book subject: %s\n", book->subject);
    printf("Book identifier: %d\n", book->book_id);
}
void printBook2(struct Book *book)
{
    printf("Details: %s, %s, %s, %d ", book->title, book->author, book->subject, book->book_id);
}
int main ()
{
    /* declaratii, initalizari,… citiri */
    int x;
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        book1.printBook=&printBook1;
        break;
    default:
        book1.printBook=&printBook2;
    }
    book1.printBook(&book1);
    return 0;
}
