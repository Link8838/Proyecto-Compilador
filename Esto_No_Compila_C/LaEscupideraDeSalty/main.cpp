/**
 * Práctica 7: Compiladores
 * Figueroa Sandoval Gerardo Emiliano
 * Hernández Ferreiro Enrique Ehecatl
 * López Soto Ramses Antonio
 * Quintero Villeda Erik
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "tokens.h"
#include "parser.h"
using namespace std;
extern FILE *yyin;
extern Token yylex();
struct Token tokenActual;


int main(int argc, char** argv) {
    FILE *input;
    input = fopen(argv[1],"r");
    yyin = input;

    if (argc < 2){
        printf(">No hay archivo de entrada...\n");
        return -1;
    }
    input = fopen(argv[1], "r");
    if(!input){
        printf("No se puede abrir el archivo\n");
        return -1;
    }

    puts(">Comenzando analisis...\n");
    tokenActual = yylex();
    parse(tokenActual, argv[1]);
    return 0;
}
