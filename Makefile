all: gestao 
	gestao: gestao.c
		gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -o gestao gestao.c -lcs50