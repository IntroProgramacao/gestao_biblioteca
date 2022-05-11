/****************************************************************************************************
Objetivo:
Criar o sistema de gestão de Biblioteca com as características a seguir:

    A biblioteca administra livros que são caracterizados por um título, um autor, um
    ISBN, um ano de edição e uma editora. Um livro pode também estar em estado
    emprestado ou não.

    A biblioteca tem uma capacidade máxima de 100 livros. Os 100 itens do vetor
    são inicializado com o valor NULL.

    O sistema oferece as operações de:

          ->Cadastrar um livro. O livro é inserido no primeiro espaço livre do vetor
          ->Remover um livro (o livro é selecionado indicando o índice no vetor)
          ->Emprestar um livro (o livro é selecionado indicando o índice no vetor)
          ->Devolver um livro (o livro é selecionado indicando o índice no vetor)
          ->Listar os livros emprestados
          ->Listar os livros disponíveis
          ->saída de erro para quando tentar emprestar/devolver um livro não cadastrado

    As operações serão realizadas através de um menu




Autor: Lucasitron
****************************************************************************************************/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura com os dados do livro.
struct livro{
    char *titulo;
    char *autor;
    char *edicao;
    char *editora;
};
//define um tipo de estrutura livro
typedef struct livro Livro;

//função que cria um novo livro
Livro *criar_livro(char *tit, char *aut, char *edi, char *edt){
    
    /*cria uma instancia novo que recebe atribui um valor na var indicada
    esse valor é recebido no cabeçalho*/
    Livro *novo = (Livro *) malloc(sizeof (Livro));
    
    //manda o valor recebido para dentro da var na estrutura livro
    novo -> titulo = tit;
    novo -> autor = aut;
    novo -> edicao = edi;
    novo -> editora = edt;

    //retorna a intancia novo
    return novo;
}

//remove um livro
void remover(Livro *li){
    free (li->titulo);
    free (li->autor);
    free (li->edicao);
    free (li->editora);
}

int
main(int argc, char const *argv[]){
    /*Cria um vetor de livros com 100 posições onde cada posição indica um livro da biblioteca*/
    //Livro **livro = (Livro **)malloc(100 * sizeof (Livro*));
    
    //inicializa todos as posições do vetor com NULL
    //memcpy(livro, NULL, 100);

    //menu de execução, printf
    bool stop = false;
    do
    {
        printf("Digite o valor da opção e de enter.\n");
        printf("1 - Cadastrar livro\t\t");
        printf("2 - remover livro\n");
        printf("3 - consultar livros\t\t");
        printf("4 - emprestar livro\n");
        printf("5 - devolver livro livro\t");
        printf("6 - listar livros emprestados\n");
        printf("7 - listar livros disponíveis\t");
        printf("8 - listar livros cadastrados\n");
    } while (stop == false);
    


    return 0;
}
