#include "fixcol.h"
#include <ctype.h>
#include <string.h>

#define CANT_BYTES 1
#define NOMBRE_ARCHIVO 2

/* Funcion para verificar si dado un string contiene solo numeros
 * Post: devuelve 1 si es un digito, 0 en otro caso*/
int solo_digitos(const char* s);


int solo_digitos(const char* s){
    while(*s){
        if(isdigit(*s++) == 0){
            return 0;
        }
    }
    return 1;
}


int fixcol(int columnas, FILE* entrada){
    FILE* archivo = entrada;
    /*Si la entrada es NULL entonces hay un error*/
    if(archivo == NULL){
        fprintf(stderr, "Error: archivo fuente inaccesible\n");
        return 2;
    }

    /*Por cada cadena de columnas +1 (del /0) de largo
     * imprimo por stdout, (Reemplazo el \n de todas las cadenas posibles)*/
    char linea[columnas+1];
    while(fgets(linea, columnas+1, archivo) != NULL){
        if(linea[strlen(linea)-1] == '\n'){
            linea[strlen(linea)-1] = '\0';
        }
        if(strlen(linea) > 0 && linea[0] != '\n'){
            printf("%s\n", linea);
        }
    }

    fclose(archivo);

    return 0;
}


#ifndef FUNCION_MAIN_
#define FUNCION_MAIN_

int main(int argc, char* argv[]){
    if(argc < 2 || argc > 3){
        /*Valido que la cantidad de parametros sea la aceptada */
        fprintf(stderr, "Error: Cantidad erronea de parametros\n");
        return 2;
    }

    /*Valido que el primer parametro sea un numerous*/
    if(!solo_digitos(argv[CANT_BYTES])){
        fprintf(stderr, "Error: Cantidad erronea de parametros\n");
        return 2;
    }

    int columnas = atoi(argv[CANT_BYTES]);

    if(columnas <= 0){
        return 2;
    }

    if(argc == 2){
        return fixcol(columnas, stdin);
    }

    if(argc == 3){
        FILE* archivo = fopen(argv[NOMBRE_ARCHIVO], "r");
        return fixcol(columnas, archivo);
    }
    return 0;
}

#endif // FUNCION_MAIN_