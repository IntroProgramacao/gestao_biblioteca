#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include<cs50.h>
#include"estrutura.h"

//function add a book
void add(Book **book);

//function remove a book
void release(Book **unit, char *index);


#endif