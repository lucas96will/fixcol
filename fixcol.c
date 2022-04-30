#include "fixcol.h"
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define ARGUMENTO_CARACTERES 1
#define NOMBRE_ARCHIVO 2
#define MAX_ARGC 3
#define MIN_ARGC 2

/* Funcion para verificar si dado un string contiene solo numeros
 * Post: devuelve true si es un digito, 0 en otro caso*/
bool solo_digitos(const char* s){
    while(*s){
        if(isdigit(*s++) == 0){
            return false;
        }
    }
    return true;
}

/*Imprime, por stderr, solo si el estado == true lo que hay en imprimir*/
void imprimir_si_hay_error(bool estado, char* imprimir){
    if(estado){
        fprintf(stderr, "%s", imprimir);
    }
}

void imprimir_columnas(char* str){
    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }
    if(strlen(str) > 0 && str[0] != '\n'){
        printf("%s\n", str);
    }
}

void fixcol(int columnas, FILE* entrada){
    /*Si la entrada es NULL entonces hay un error*/
    if(entrada == NULL){
        fprintf(stderr, "Error: archivo fuente inaccesible\n");
    }

    /*Por cada cadena de columnas +1 (del /0) de largo
     * imprimo por stdout, (No imprimo lineas vacias 0 de 1 caracter del \n)*/
    char linea[columnas+1];
    while(fgets(linea, columnas+1, entrada) != NULL){
        imprimir_columnas(linea);
    }
}



void fixcol_wrapp(int argc, char* argv[], int columnas){
    if(argc == 2){
        fixcol(columnas, stdin);
    }

    if(argc == 3){
        FILE* archivo = fopen(argv[NOMBRE_ARCHIVO], "r");
        fixcol(columnas, archivo);
        fclose(archivo);
    }
}

bool hay_errores(int argc, char* argv[]){
    bool cant_argc_incorrecta = (argc < MIN_ARGC || argc > MAX_ARGC);
    bool argumento_solo_digitos = solo_digitos(argv[ARGUMENTO_CARACTERES]);

    imprimir_si_hay_error(cant_argc_incorrecta, "Error: Cantidad erronea de parametros\n");
    imprimir_si_hay_error(!argumento_solo_digitos, "Error: Cantidad erronea de parametros\n");

    return (cant_argc_incorrecta || !argumento_solo_digitos);
}

#ifndef CORRECTOR

int main(int argc, char* argv[]){
    /*Valido si la cantidad de argumentos son correctos (min 2, max 3) y si el segundo parametro son solo digitos!*/
    if(hay_errores(argc, argv)){
        return 0;
    }

    int columnas = atoi(argv[ARGUMENTO_CARACTERES]);
    if(columnas <= 0){
        return 0;
    }

    //llamo a fixcol segun la cantidad de parametros (argc)
    fixcol_wrapp(argc, argv, columnas);

    return 0;
}

#endif // CORRECTOR