/**
 * Proyecto Final: Compiladores
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

/**
 * Método main que implementa la compilación del lenguaje.
 */
int main(int argc, char** argv) {
    string marco = "====================================================================";
    FILE *input;
    input = fopen(argv[1],"r");
    yyin = input;
    string flag;

    //Búsqueda de argumentos.
    if (argc < 2){
        printf(">No hay archivo de entrada...\n");
        return -1;
    } else if(argc < 3){
        flag = " ";
    } else {
        flag = argv[2];
    }

    //Apertura del archivo.
    input = fopen(argv[1], "r");
    if(!input){
        printf("No se puede abrir el archivo\n");
        return -1;
    }

    //Llamada al método de compilación.
    printf("\n%s\n>Comenzando analisis...\n%s\n\n",marco.c_str(),marco.c_str());
    tokenActual = yylex();
    parse(tokenActual, argv[1], flag);
    return 0;
}
