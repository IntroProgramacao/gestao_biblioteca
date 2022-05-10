# gestao_biblioteca
Sistema de gestão de biblioteca

– A biblioteca administra livros que são caracterizados por um título, um autor, um
ISBN, um ano de edição e uma editora. Um livro pode também estar em estado
emprestado ou não.

– A biblioteca tem uma capacidade máxima de 100 livros. Os 100 itens do vetor
são inicializado com o valor NULL.

– O sistema oferece as operações de:
    • Cadastrar um livro. O livro é inserido no primeiro espaço livre do vetor
    • Remover um livro (o livro é selecionado indicando o índice no vetor)
    • Emprestar um livro (o livro é selecionado indicando o índice no vetor)
    • Devolver um livro (o livro é selecionado indicando o índice no vetor)
    • Listar os livros emprestados
    • Listar os livros disponíveis

Não esquecer de administrar os casos quando tentamos remover ou emprestar/devolver
um livro que não foi criado ou que já foi removido do sistema
– As operações serão realizadas através de um menu