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
  #define YY_DECL Token yylex(void)
  struct Token token;

%}


%option noyywrap
%option yylineno

num_ent [0-9]+
num_float [0-9]*"."[0-9]+
num_double [0-9]*"."[0-9]+
id [a-zA-Z][a-zA-Z0-9]*
whitespace [ \t\n]
str \"(\\.|[^"\\])*\"|\'(\\.|[^'\\])*\'
comeUn "--"[^\n]*
comeMul "<*"[^"*>"]*"*>"

%%

"," { ECHO; return token.crea_token(COMA, yytext,-1); }
";" { ECHO; return token.crea_token(PCOMA, yytext,-1); }
"{" { ECHO; return token.crea_token(LLAIZQ, yytext,-1); }
"}" { ECHO; return token.crea_token(LLADER, yytext,-1); }
"int" { ECHO; return token.crea_token(INT, yytext,-1); }
"float" { ECHO; return token.crea_token(FLOAT, yytext,-1);}
"char" { ECHO; return token.crea_token(CHAR, yytext,-1);}
"double" { ECHO; return token.crea_token(DOUBLE, yytext,-1);}
"void" { ECHO; return token.crea_token(VOID, yytext,-1);}
"func" { ECHO; return token.crea_token(FUNC, yytext,-1);}
"(" { ECHO; return token.crea_token(PIZQ, yytext,-1);}
")" { ECHO; return token.crea_token(PDER, yytext,-1);}
"if" { ECHO; return token.crea_token(IF, yytext,-1);}
"else" { ECHO; return token.crea_token(ELSE, yytext,-1);}
"while" { ECHO; return token.crea_token(WHILE, yytext,-1);}
"break" { ECHO; return token.crea_token(BREAK, yytext,-1);}
"switch" { ECHO; return token.crea_token(SWITCH, yytext,-1);}
"case" { ECHO; return token.crea_token(CASE, yytext,-1);}
"default" { ECHO; return token.crea_token(DEFAULT, yytext,-1);}
"return" { ECHO; return token.crea_token(RETURN, yytext,-1);}
"print" { ECHO; return token.crea_token(PRINT, yytext,-1);}
"scan" { ECHO; return token.crea_token(SCAN, yytext,-1);}
":" { ECHO; return token.crea_token(DOSPUNTOS, yytext,-1);}
"||" { ECHO; return token.crea_token(OR, yytext,-1);}
"&&" { ECHO; return token.crea_token(AND, yytext,-1);}
"==" { ECHO; return token.crea_token(IGUAL, yytext,-1);}
"!=" { ECHO; return token.crea_token(DIFF, yytext,-1);}
"<" { ECHO; return token.crea_token(MENOR, yytext,-1);}
"<=" { ECHO; return token.crea_token(MENOREQ, yytext,-1);}
">" { ECHO; return token.crea_token(MAYOR, yytext,-1);}
">=" { ECHO; return token.crea_token(MAYOREQ, yytext,-1);}
"=" { ECHO; return token.crea_token(ASIG, yytext,-1);}
"+" { ECHO; return token.crea_token(MAS, yytext,-1);}
"-" { ECHO; return token.crea_token(MENOS, yytext,-1);}
"*" { ECHO; return token.crea_token(MULT, yytext,-1);}
"/" { ECHO; return token.crea_token(DIV, yytext,-1);}
"%" { ECHO; return token.crea_token(MOD, yytext,-1);}
"!" { ECHO; return token.crea_token(NEGA, yytext,-1);}
"-" { ECHO; return token.crea_token(NEG, yytext,-1);}
"true" { ECHO; return token.crea_token(TRUE, yytext,-1);}
"false" { ECHO; return token.crea_token(FALSE, yytext,-1);}
"[" { ECHO; return token.crea_token(CIZQ, yytext,-1);}
"]" { ECHO; return token.crea_token(CDER, yytext,-1);}
{num_ent} { ECHO; return token.crea_token(NUM, yytext, 0); }
{num_float} { ECHO; return token.crea_token(NUM, yytext, 1); }
{num_double} { ECHO; return token.crea_token(NUM, yytext, 2); }
{comeUn} { ECHO;}
{comeMul} { ECHO;}
{id} { ECHO; return token.crea_token(ID, yytext,-1); }
{str} { ECHO; return token.crea_token(STR, yytext,-1); }
{whitespace} { ECHO; }

<<EOF>> { puts("\n>Fin de analisis Lexico."); return token.crea_token(FIN, "",-1); }
. { printf("\n\n >Error lexico en la linea: %i\n", yylineno); exit(1); }

%%
