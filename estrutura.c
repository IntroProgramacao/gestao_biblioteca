#include<stdlib.h>


#include"biblioteca.h"
#include"estrutura.h"


//typedef struct *book Book;


Book *newBook(char *tit, char *aut, char *isb, int edic, char *edit){
    Book *new = (Book *) malloc(100* sizeof(Book));

    new -> tittle = tit;
    new -> autor = aut;
    new -> isbn = isb;
    new -> edition = edic;
    new -> editora = edit;

    return new;
}

//remove a book space
void freeBook(Book *book){
    free(book->tittle);
    free(book->autor);
    free(book->isbn);
    free(book->editora);
    free(book);
}
