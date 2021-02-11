/**
 * Práctica 7: Compiladores
 * Figueroa Sandoval Gerardo Emiliano
 * Hernández Ferreiro Enrique Ehecatl
 * López Soto Ramses Antonio
 * Quintero Villeda Erik
*/

#ifndef PARSER_SEM_H
#define PARSER_SEM_H

#include "tokens.h"
#include "tipo.h"
#include "simbolo.h"
#include "returntipes.h"
#include <vector>
#include <stack>
#include <list>


/**
 * Función para paso de prueba y empate del (Programa)
 */
void Programa();

/**
 * Función para paso de prueba y empate del (Declaraciones)
 */
void Declaraciones();

/**
 * Función para prueba y empate del (Tipo)
 */
int Tipo();

/**
 * Función para prueba y empate del (Lista_Var)
 */
void Lista_Var(int lista_varTipoH);

/**
 * Función para prueba y empate del (Basico)
 */
int Basico();

/**
 * Función para prueba y empate del No-terminal (Compuesto)
 */
int Compuesto(int base);

/**
 * Función para prueba y empate del No-terminal (Lop)
 */
void Lop(int lista_varTipoH);

/**
 * Función para prueba y empate del No-terminal (Funciones)
 */
void Funciones();

/**
 * Función para prueba y empate del No-terminal (Argumentos)
 */
list<int> Argumentos();

/**
 * Función para prueba y empate del No-terminal (Bloque)
 */
void Bloque();

/**
 * Función para prueba y empate del No-terminal (Lista_Args)
 */
list<int> Lista_Args();

/**
 * Función para prueba y empate del No-terminal (Lista_ArgsP)
 */
list<int> Lista_ArgsP(list<int> l);

/**
 * Función para prueba y empate del No-terminal (Instrucciones)
 */
void Instrucciones();

/**
 * Función para prueba y empate del No-terminal (Sentencia)
 */
void Sentencia();

/**
 * Función para prueba y empate del No-terminal (InstruccionesP)
 */
void InstruccionesP();

/**
 * Función para prueba y empate del No-terminal (Sent)
 */
void Sent();

/**
 * Función para prueba y empate del No-terminal (Ret)
 */
void Ret();

/**
 * Función para prueba y empate del No-terminal (Pierna_Izquierda_Exodia)
 */
piernaIzquieraExodiaReturn Pierna_Izquierda_Exodia();

/**
 * Función para prueba y empate del No-terminal (Bool)
 */
boolReturn Bool();

/**
 * Función para prueba y empate del No-terminal (Casos)
 */
void Casos();

/**
 * Función para prueba y empate del No-terminal (Exp)
 */
expReturn Exp();

/**
 * Función para prueba y empate del No-terminal (Caso)
 */
void Caso();

/**
 * Función para prueba y empate del No-terminal (Predeterminado)
 */
void Predeterminado();

/**
 * Función para prueba y empate del No-terminal (Ptt)
 */
pttReturn Ptt(string pttBase);

/**
 * Función para prueba y empate del No-terminal (Localization)
 */
localizationReturn Localization(string localizationBase);

/**
 * Función para prueba y empate del No-terminal (Comb)
 */
combReturn Comb();

/**
 * Función para prueba y empate del No-terminal (BoolP)
 */
void BoolP();

/**
 * Función para prueba y empate del No-terminal (Igualdad)
 */
igualdadReturn Igualdad(string vddr, string fls);

/**
 * Función para prueba y empate del No-terminal (Rel)
 */
relReturn Rel(string relVddr, string relFls);

/**
 * Función para prueba y empate del No-terminal (IgualdadP)
 */
iguPReturn IguP(string relVddr, string relFls, int tipoH, string dir);

/**
 * Función para prueba y empate del No-terminal (CombP)
 */
combPReturn CombP(combPReturn combPP);

/**
 * Función para prueba y empate del No-terminal (Xp)
 */
xpReturn Xp(string v, string f, int tipo);

/**
 * Función para prueba y empate del No-terminal (Term)
 */
termReturn Term();

/**
 * Función para prueba y empate del No-terminal (ExP)
 */
exReturn Ex(int tipe, string dir);

/**
 * Función para prueba y empate del No-terminal (Unario)
 */
unarioReturn Unario();

/**
 * Función para prueba y empate del No-terminal (TerP)
 */
terPReturn TerP(int tipe, string dire);

/**
 * Función para prueba y empate del No-terminal (Factor)
 */
factorReturn Factor();

/**
 * Función para prueba y empate del No-terminal (Faacc)
 */
faaccReturn Faacc(string id);

/**
 * Función para prueba y empate del No-terminal (Parametros)
 */
list<int> Parametros();

/**
 * Función para prueba y empate del No-terminal (Lista_Param)
 */
list<int> Lista_Param();

/**
 * Función para prueba y empate del No-terminal (ListP)
 */
list<int> ListP(list<int> listaH);

/**
 * Función para prueba y empate del No-terminal (LocalP)
 */
localPReturn LocalP(string localPBase, int tipo, string direc);

/**
 * Función para consumo de componente léxico actual al hacer empate
 */
int eat(int clase);

/**
 * Función principal de análisis sintáctico.
 * Debe llamar a función de símbolo inicial de la gramática.
 * También inicializar las tablas de símbolos y tipos.
 */
void parse(Token t);

/**
 * Función que inicializa la tabla de tipos.
 */
void construirTablaTipos();

/**
 * Función que inicializa la tabla de simbolos.
 */
void construirTablaSimbolos();

/**
 * Función que 
 */
int buscarIDTS(string str);

/**
 *
 */
int buscarIDTSFondo(string id);

/**
 * Función que 
 */
void insertarTipoTop(TipTipe tipooo);
/**
 * Función que 
 */
void insertarSimbolo(string id, int dir, int type, int var, list<int> args);

/**
 * Función para reporte de errores sintácticos y semánticos.
 */
void errorSintactico();

/**
 * Función para reporte de errores sintácticos y semánticos.
 */
void errorSemantico(string fail, int linea, string error);

/**
 * Función que determina si los tipos de la lista son iguales al tipo.
 */
int equivalentesLista(int tipo);

/**
 * Función que genera código.
 */
void generarCodigo(string opcion, string arg1,  string arg2, string res);

/**
 * Función que genera una nueva etiqueta.
 */
string nuevaEtiqueta();

/**
 * Función que genera un nuevo indice.
 */
string nuevoIndice();

string nuevaTemporal();

int getTipoTS(string id);

int getNombre(int tipoTemp, string strTipo);

int getTamTT(int tipo);

list<Simbolo> fondo(stack<list<Simbolo>> ts);

int getVarPTSFondo(string id);

list<int> getVarListPTSFondo(string id);

int equivalenteListas(list<int> uno, list<int> dos);

int equivalentes(int tipoH, int unarioH);

#endif