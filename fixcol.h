#ifndef FIXCOL_FIXCOL_H
#define FIXCOL_FIXCOL_H
#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>

/*fixcol es una funcion que dado un archivo de entrada
 *fija una cantidad de columnas de caracteres por cada
 *por cada linea y las imprime por el standard output
 * */
//Pre: columnas > 0,
//Post: Se imprime por el standard output (consola en este caso)
//texto del archivo de entrada de forma que una linea
//tenga una cantidad de columnas fijas de caracteres
//(si no se le pasa ningun archivo este toma el standard input)
//Devuelve 0 si no hubo error, 2 en otro caso abrir
int fixcol(int columnas, FILE* entrada);

#endif //FIXCOL_FIXCOL_H
