#include<cs50.h>
#include<stdlib.h>
#include <stdio.h>

//bibliotecas do programa
#include"biblioteca.h"
#include"estrutura.h"

//add to book
void add(Book **book){

    char *tittle = (char *)malloc(50*sizeof(char));
    tittle = get_string("Digite o titulo: \n");

    char *autor = (char *)malloc(50*sizeof(char));
    autor = get_string("Digite o autor: \n");

    char *isbn = (char *)malloc(50*sizeof(char));
    isbn = get_string("Digite o isbn: \n");

    int edic = get_int("De o ano da edicao: zn");

    char *editora = (char *)malloc(50*sizeof(char));
    editora = get_string("Digite a editora: \n");

    //add to struct
    bool free = false;
    for (int i = 0; i < 100; i++)
    {
        if(book[i] == NULL && i<100){
            book[i] = newBook(tittle, autor, isbn, edic, editora);;
            free = true;
            break;
        }
    }
    if (!free)
    {
        printf("Biblioteca cheia!\n");
    }
    
    //release
    free(tittle);
    free(autor);
    free(isbn);
    free(editora);
}

//remove a book
void release(Book **unit, char *index){
    
    //index search 
    int ind = 0;
    for (; ind < 100; ind++)
    {
        if (unit[ind] ->tittle == index)
        {
            break;
        }
        
    }
    
    //create a new book type
    freeBook (unit[ind]);
    unit[ind] = NULL;
}