/**
 * Práctica 7: Compiladores
 * Figueroa Sandoval Gerardo Emiliano
 * Hernández Ferreiro Enrique Ehecatl
 * López Soto Ramses Antonio
 * Quintero Villeda Erik
*/

#ifndef TOKENS_H
#define TOKENS_H
#include <string>
using namespace std;

/**
 * Estructura para modelar tokens (componentes léxicos)
 */
struct Token {
  int clase; //léxica
  string valor; //lexema
  int tipo; //para diferenciar entre diferentes lexemas de una misma clase léxica

  Token(){}

  Token(int clase, string valor, int tipo){
    this->clase = clase;
    this->valor = valor;
    this->tipo = tipo;
  }

    /**
    * Inicialización de tokens.
    */
    Token* crea_token(int clase, string valor, int tipo){
      return new Token(clase, valor, tipo);
    }

    int equals(Token t1, int clase) {
      return t1.clase == clase;
    }

};

const int COMA = 1001;
const int PCOMA = 1002;
const int LLAIZQ = 1003;
const int LLADER = 1004;
const int INT = 1005;
const int FLOAT = 1006;
const int NUM = 1007;
const int ID = 1008;
const int CHAR = 1009;
const int DOUBLE = 1010;
const int VOID = 1011;
const int PIZQ = 1012;
const int PDER = 1013;
const int FUNC = 1014;
const int IF = 1015;
const int ELSE = 1016;
const int WHILE = 1017;
const int DO = 1018;
const int SWITCH = 1019;
const int BREAK = 1020;
const int CASE = 1021;
const int DOSPUNTOS = 1022;
const int DEFAULT = 1023;
const int OR = 1024;
const int AND = 1025;
const int IGUAL = 1026;
const int DIFF = 1027;
const int MENOR = 1028;
const int MENOREQ = 1029;
const int MAYOR = 1030;
const int MAYOREQ = 1031;
const int MAS = 1032;
const int MENOS = 1033;
const int MULT = 1034;
const int DIV = 1035;
const int MOD = 1036;
const int NEGA = 1037;
const int NEG = 1038;
const int STR = 1039;
const int TRUE = 1040;
const int FALSE = 1041;
const int CIZQ = 1042;
const int CDER = 1043;
const int RETURN = 1044;
const int PRINT = 1045;
const int SCAN = 1046;
const int ASIG = 1047;
const int FIN = 9001;

#endif
