#include <cs50.h>
#include<stdbool.h>

#include"estrutura.h"
#include"search.h"


//search by tittle
int sTittle(Book **book, char *tit){
    
    //stores book position
    int local;

    bool find = false;

    //find the position
    for (local = 0; local < 100; local++)
    {
        if (book[local]->tittle == tit)
        {
            find = true;
            break;
        }
    }
    
    //assing error
    if (!find)
    {
        local = 101;
    }

    //search return
    return local;
}
