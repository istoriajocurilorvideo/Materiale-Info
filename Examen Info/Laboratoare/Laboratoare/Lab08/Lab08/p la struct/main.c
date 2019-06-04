#include <stdio.h>
#include <stdlib.h>

struct Book
{
    int book_id;
    char title[50];
    char author[50];
    char subject[100];
};

///void printBook(struct Book *book);

int main ()
{
    struct Book *book_pointer, book1;
    book_pointer = &book1;
//specificatia pentru book1:
    book1.book_id = 2000;
    strcpy(book1.title, "Defence Against the Dark Arts");
    strcpy(book1.author, "Severus Snape");
    strcpy(book1.subject, "Defence Against the Dark Arts");
    printBook(&book1);
    return 0;
}

void printBook(struct Book *book)
{
    printf("Book title: %s\n", book->title);
    printf("Book author: %s\n", book->author);
    printf("Book subject: %s\n", book->subject);
    printf("Book identifier: %d\n", book->book_id);
}

