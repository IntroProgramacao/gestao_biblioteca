#include<cs50.h>
#include<stdlib.h>
#include <stdio.h>

//bibliotecas do programa
#include"biblioteca.h"
#include"estrutura.h"

//add to book
void add(Book **book){

    /*data array
    **data[0] = tittle
    **data[1] = author
    **data[2] = ISBN
    **data[3] = publishing
    */
    char **data = (char **)malloc(4*sizeof(char *));
    data[0] = get_string("Digite o titulo: \n");
    data[1] = get_string("Digite o autor: \n");
    data[2] = get_string("Digite o isbn: \n");
    int edic = get_int("De o ano da edicao: zn");
    data[3] = get_string("Digite a editora: \n");

    //add to struct
    bool fre = false;
    for (int i = 0; i < 100; i++)
    {
        if(book[i] == NULL && i<100){
            book[i] = newBook(data[0], data[1], data[2], edic, data[4]);;
            fre = true;
            break;
        }
    }
    if (!fre)
    {
        printf("Biblioteca cheia!\n");
    }
    
    //release
    free(data);
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
    
    //memory release
    freeBook (unit[ind]);
    unit[ind] = NULL;
}