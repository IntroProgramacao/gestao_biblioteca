#ifndef ESTRUTURA_H
#define ESTRUTURA_H

//struct declaration
struct book
{
    char *tittle;
    char *autor;
    char *isbn;
    int edition;
    char *editora;
};

//new struct type
typedef struct book Book;

//function book creation
Book *newBook(char *tit, char *aut, char *isb, int edic, char *edit);

//function book delete
void freeBook(Book *book);


#endif