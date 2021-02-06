%{
  /**
 * Práctica 7: Compiladores
 * Figueroa Sandoval Gerardo Emiliano
 * Hernández Ferreiro Enrique Ehecatl
 * López Soto Ramses Antonio
 * Quintero Villeda Erik
*/

  #include <stdio.h>
  #include "tokens.h"
  #define YY_DECL token *yylex(void)

%}

%option noyywrap
%option yylineno

num_ent [0-9]+
num_float [0-9]*"."[0-9]+
num_double [0-9]*"."[0-9]+
id [a-zA-Z][a-zA-Z0-9]*
whitespace [ \t\n]
str \"(\\.|[^"\\])*\"|\'(\\.|[^'\\])*\'

%%

"," { ECHO; return crea_token(COMA, yytext); }
";" { ECHO; return crea_token(PCOMA, yytext); }
"{" { ECHO; return crea_token(LLAIZQ, yytext); }
"}" { ECHO; return crea_token(LLADER, yytext); }
"int" { ECHO; return crea_token(INT, yytext); }
"float" { ECHO; return crea_token(FLOAT, yytext);}
"char" { ECHO; return crea_token(CHAR, yytext);}
"double" { ECHO; return crea_token(DOUBLE, yytext);}
"void" { ECHO; return crea_token(VOID, yytext);}
"func" { ECHO; return crea_token(FUNC, yytext);}
"(" { ECHO; return crea_token(PIZQ, yytext);}
")" { ECHO; return crea_token(PDER, yytext);}
"if" { ECHO; return crea_token(IF, yytext);}
"else" { ECHO; return crea_token(ELSE, yytext);}
"while" { ECHO; return crea_token(WHILE, yytext);}
"break" { ECHO; return crea_token(BREAK, yytext);}
"switch" { ECHO; return crea_token(SWITCH, yytext);}
"case" { ECHO; return crea_token(CASE, yytext);}
"default" { ECHO; return crea_token(DEFAULT, yytext);}
"return" { ECHO; return crea_token(RETURN, yytext);}
"print" { ECHO; return crea_token(PRINT, yytext);}
"scan" { ECHO; return crea_token(SCAN, yytext);}
":" { ECHO; return crea_token(DOSPUNTOS, yytext);}
"||" { ECHO; return crea_token(OR, yytext);}
"&&" { ECHO; return crea_token(AND, yytext);}
"==" { ECHO; return crea_token(IGUAL, yytext);}
"!=" { ECHO; return crea_token(DIFF, yytext);}
"<" { ECHO; return crea_token(MENOR, yytext);}
"<=" { ECHO; return crea_token(MENOREQ, yytext);}
">" { ECHO; return crea_token(MAYOR, yytext);}
">=" { ECHO; return crea_token(MAYOREQ, yytext);}
"=" { ECHO; return crea_token(ASIG, yytext);}
"+" { ECHO; return crea_token(MAS, yytext);}
"-" { ECHO; return crea_token(MENOS, yytext);}
"*" { ECHO; return crea_token(MULT, yytext);}
"/" { ECHO; return crea_token(DIV, yytext);}
"%" { ECHO; return crea_token(MOD, yytext);}
"!" { ECHO; return crea_token(NEGA, yytext);}
"-" { ECHO; return crea_token(NEG, yytext);}
"true" { ECHO; return crea_token(TRUE, yytext);}
"false" { ECHO; return crea_token(FALSE, yytext);}
"[" { ECHO; return crea_token(CIZQ, yytext);}
"]" { ECHO; return crea_token(CDER, yytext);}
{num_ent} { ECHO; return crea_token_tipo(NUM, yytext, 0); }
{num_float} { ECHO; return crea_token_tipo(NUM, yytext, 1); }
{num_double} { ECHO; return crea_token_tipo(NUM, yytext, 2); }
{id} { ECHO; return crea_token(ID, yytext); }
{str} { ECHO; return crea_token(STR, yytext); }
{whitespace} { ECHO; }

<<EOF>> { puts("Fin de analisis lexico."); return crea_token(FIN, ""); }
. { printf("Error léxico en la linea: %i\n", yylineno); exit(1); }

%%
