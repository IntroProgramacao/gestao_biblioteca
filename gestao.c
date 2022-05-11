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
struct book{
    int status;
    char *title;
    char *autor;
    char *edicao;
    char *editora;
    int isbn;
};
//define um tipo de estrutura livro
typedef struct book Book;

//função que cria um novo livro
Book *NewBook(char *tit, char *aut, char *edi, char *edt, int isb){
    
    /*cria uma instancia novo que recebe atribui um valor na var indicada
    esse valor é recebido no cabeçalho*/
    Book *new = (Book *) malloc(sizeof (Book));
    
    //manda o valor recebido para dentro da var na estrutura book
    new -> title = tit;
    new -> autor = aut;
    new -> edicao = edi;
    new -> editora = edt;
    new -> isbn = isb;

    //retorna a intancia novo
    return new;
}

//altera a situação o status do livro
Book *NewStatus(int sT){
    //Instancia uma var
    Book *nStatus = (Book *) malloc(sizeof(Book));

    //joga o valor recebido dentro da var status
    nStatus -> status = sT;

    return nStatus;
}

//remove um book
void del(Book *li){
    free (li -> autor);
    free (li->title);
    free (li->autor);
    free (li->edicao);
    free (li->editora);
    free(li);
}

int
main(int argc, char const *argv[]){
    /*Cria um vetor de books com 100 posições onde cada posição indica um book da biblioteca*/
    Book **book =(Book **)malloc(101 * sizeof (Book*));

    //inicializa com NULL
    for (int i = 0; i < 100; i++){
        book[i] = NewBook(NULL,NULL,NULL,NULL,0000);
        book[i] = NewStatus(0);
    }

    //controle de parada
    bool stop = true;
    do
    {
        //armazenará a opção
        int option;

        //tela 1 menu de execução, printf
        bool error = true;
        do{
            printf("Digite o valor da opção e de enter.\n");
	        printf("1 - Cadastrar livro\t\t");          printf("2 - remover livro\n");
	        printf("3 - consultar livros\t\t");         printf("4 - emprestar livro\n");
	        printf("5 - devolver livro\t\t");           printf("6 - listar livros emprestados\n");
	        printf("7 - listar livros disponíveis\t");  printf("8 - listar livros cadastrados\n");
            printf("0 - encerrar\n");

            //lê a opção
            scanf("%d", &option);

            //verifica a validade da opção
            if (option > 0 && option <= 8){
                error = true;
            }else if(option == 0){
                error = false;
                stop = true;
            }else {
                printf("valor inválido!");
            }
        }while (error == false);

        

        //menu
        switch (option)
        {
            //cadastra um novo livro
            case 1:{

                //arrays para receber a identificação do livro
                printf("Titulo: ");
                char *title = (char *) malloc(50 * sizeof(char));
                scanf("%s", title);

                printf("\nAutor: ");
                char *autor = (char *) malloc(25 * sizeof(char));
                scanf("%s", autor);

                printf("\nedição: ");
                char *edit = (char *) malloc(25 * sizeof(char));
                scanf("%s", edit);

                printf("\nEditora: ");
                char *pub = (char *) malloc(25 * sizeof(char));
                scanf("%s", pub);

                printf("\nISBN: ");
                int isbn;
                scanf("%d", &isbn);


                for (int i = 0; i < 100; i++)
                {
                    
                   if (book[i] -> status == 0)
                    {
                        book[i] = NewBook(title, autor, edit, pub, isbn);
                        book[i] = NewStatus(1);

                        printf(" Dados: \n");
                        printf(" Titulo: %s \n Autor: %s", book[i] -> title, book[i] -> autor);
                        printf(" Edição: %s \n Editora: %s", book[i] -> edicao, book[i] -> editora);
                        printf(" ISBN: %d", book[i] -> isbn);

                        i = 100;
                    }
                
                }            
                break;
            }

            //deleta um livro
            case 2:{
                //recebe o indice do livro
                int id;
                printf("Digite o ID do livo: \n");
                scanf("%d", id);

                //limpa o registro do livo
                del(book[id]);
            }
            
            //consulta um livro
            case 3:{
                //pega um tipo de consulta
                printf("Digite o tipo de busca.\n");
    	        printf("1 - Titulo\t\t");                   printf("2 - Autor\n");
	            printf("3 - Editora\t\t");                  printf("4 - ISBN\n");
	            printf("5 - Indice\t\t");
                
                int busca;
                scanf("%d", &busca);

                switch (busca)
                {
                    //busca por titulo
                    case 1:{
                        //lê o titulo
                        char *tit = (char *) malloc(25 * sizeof(char))
                        scanf("%s", tit);

                        //efetua a busca
                        for (int i = 0; i < 100; i++)
                        {
                            if (book[i] -> title == tit)
                            {
                                printf(" Dados: \n");
                                printf("Titulo: %s \n", book[i] -> title)
                                printf("Autor: %s\n", book[i] -> autor);
                                printf("Edição: %s\n", book[i] -> edicao)
                                printf("Editora: %s\n", book[i] -> editora);
                                printf(" ISBN: %d\n", book[i] -> isbn);
                            }
                            
                        }
                        break;
                    }
                    //busca por autor
                    case 2:{
                        //lê o autor
                        char *busca = (char *) malloc(25 * sizeof(char));
                        scanf("%s", busca);

                        //efetua a busca
                        for (int i = 0; i < 100; i++)
                        {
                            if (book[i] -> autor == busca)
                            {
                                printf(" Dados: \n");
                                printf("Titulo: %s \n", book[i] -> title)
                                printf("Autor: %s\n", book[i] -> autor);
                                printf("Edição: %s\n", book[i] -> edicao)
                                printf("Editora: %s\n", book[i] -> editora);
                                printf(" ISBN: %d\n", book[i] -> isbn);
                            }
                            
                        }
                        break;
                    }

                    //pela editora
                    case 3:{
                        //lê a editora
                        char *busca = (char *) malloc(25 * sizeof(char));
                        scanf("%s", busca);

                        //efetua a busca
                        for (int i = 0; i < 100; i++)
                        {
                            if (book[i] -> editora == busca)
                            {
                                printf(" Dados: \n");
                                printf("Titulo: %s \n", book[i] -> title)
                                printf("Autor: %s\n", book[i] -> autor);
                                printf("Edição: %s\n", book[i] -> edicao)
                                printf("Editora: %s\n", book[i] -> editora);
                                printf(" ISBN: %d\n", book[i] -> isbn);
                            }
                            
                        }
                        break;
                    }

                    //pelo ISBN
                    case 4:{
                        //lê a editora
                        int busca;
                        scanf("%d", &busca);

                        //efetua a busca
                        for (int i = 0; i < 100; i++)
                        {
                            if (book[i] -> isbn == busca)
                            {
                                printf(" Dados: \n");
                                printf("Titulo: %s \n", book[i] -> title)
                                printf("Autor: %s\n", book[i] -> autor);
                                printf("Edição: %s\n", book[i] -> edicao)
                                printf("Editora: %s\n", book[i] -> editora);
                                printf(" ISBN: %d\n", book[i] -> isbn);
                            }
                            
                        }
                        break;
                    }
                
                default:
                    break;
                }

            }
        default:
            break;
        }
        
        
        


    } while (stop == false);
    


    return 0;
}
