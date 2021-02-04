/**
 * Práctica 7: Compiladores
 * Figueroa Sandoval Gerardo Emiliano
 * Hernández Ferreiro Enrique Ehecatl
 * López Soto Ramses Antonio
 * Quintero Villeda Erik
*/

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "tokens.h"


extern FILE *yyin;
extern token *yylex();
token *tokenActual;

int main(int argc, char **argv) {
  if(argc < 2) {
    puts("Falta archivo de entrada.");
    exit(1);
  }
  printf("Archivo de entrada: ");
  puts(argv[1]);
  FILE *fin = fopen(argv[1], "r");
  yyin = fin;

  puts("Comenzando analisis...");
  tokenActual = yylex();
  //puts(tokenActual -> valor);
  parse(tokenActual);
}
