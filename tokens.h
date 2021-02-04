/**
 * Práctica 7: Compiladores
 * Figueroa Sandoval Gerardo Emiliano
 * Hernández Ferreiro Enrique Ehecatl
 * López Soto Ramses Antonio
 * Quintero Villeda Erik
*/

#define COMA 1001
#define PCOMA 1002
#define LLAIZQ 1003
#define LLADER 1004
#define INT 1005
#define FLOAT 1006
#define NUM 1007
#define ID 1008
#define CHAR 1009
#define DOUBLE 1010
#define VOID 1011
#define PIZQ 1012
#define PDER 1013
#define FUNC 1014
#define IF 1015
#define ELSE 1016
#define WHILE 1017
#define DO 1018
#define SWITCH 1019
#define BREAK 1020
#define CASE 1021
#define DOSPUNTOS 1022
#define DEFAULT 1023
#define OR 1024
#define AND 1025
#define IGUAL 1026
#define DIFF 1027
#define MENOR 1028
#define MENOREQ 1029
#define MAYOR 1030
#define MAYOREQ 1031
#define MAS 1032
#define MENOS 1033
#define MULT 1034
#define DIV 1035
#define MOD 1036
#define NEGA 1037
#define NEG 1038
#define STR 1039
#define TRUE 1040
#define FALSE 1041
#define CIZQ 1042
#define CDER 1043
#define RETURN 1044
#define PRINT 1045
#define SCAN 1046
#define ASIG 1047
#define FIN 9001

#include <string.h>
#include <stdlib.h>

/**
 * Estructura para modelar tokens (componentes léxicos)
 */
typedef struct token {
  int clase; //léxica
  char *valor; //lexema
  int tipo; //para diferenciar entre diferentes lexemas de una misma clase léxica
} token;

/**
 * Inicialización de tokens sin tipo
 */
 token *crea_token();

/**
 * Inicialización de tokens con tipo
 */
 token *crea_token_tipo();

/**
 * Verificación de token perteneciente a una clase léxica
 */
 int equals();

/**
 * Liberación de memoria de un token
 */
//void libera(token *t);
