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



    puts("Comenzando analisis...");
    tokenActual = yylex();
    parse(tokenActual);
    return 0;
}
