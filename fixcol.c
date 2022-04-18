#include "fixcol.h"
#include <stdio.h>






#ifndef _MAIN_
#define _MAIN_

int main(int argc, char* argv[]){
    if(argc < 2 || argc > 3){
        fprintf(stderr, "Error: Cantidad erronea de parametros.");
        return 2;
    }

    if(argc == 2){
        /* argv[2] deberia ser el numero de bytes */
        /* porque el primer parámetro no es un número   Error: Cantidad erronea de parametros.*/
        argv[2];
    }

    if(argc == 3){

    }

    return 0;
}

#endif // _MAIN_