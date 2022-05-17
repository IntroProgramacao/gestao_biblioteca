all: gestao
gestao: gestao.c estrutura.c estrutura.h biblioteca.c biblioteca.h search.c search.h
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -o gestao gestao.c estrutura.c biblioteca.c search.c -lcs50 -lm

	
