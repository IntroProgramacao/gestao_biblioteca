#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"biblioteca.h"
#include"estrutura.h"
#include"search.h"

int
main(int argc, char *argv[])
{
    //book intance
    Book **book = (Book **)malloc(100*sizeof(Book));

    while (1)
    {
        //user interface
        printf("1 - Cadastrar novo livro. \t");     printf("2 - Remover um livro.\n");
        printf("3 - Consultar um livro. \t\t");     printf("4 - Listar livros.\n");
        printf("5 - Emprestar um livro. \t\t");     printf("6 - Devolver um livro.\n");
        printf("7 - listar emprestimos. \t");       printf("0 - Sair.\n");

        //input
        int option = get_int("Digite a opção desejada: \n");

        //cases
        switch (option)
        {
        case 1:
            add(book);
            break;
        
        case 2:
            char *index = (char *)malloc(50*sizeof(char));
            index = "null";
            release(book, index);

        default:
            break;
        }
    }
    
    return 0;
}
