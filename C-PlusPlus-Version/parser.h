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
 * Función para paso de prueba y empate del (Programa).
 */
void Programa();

/**
 * Función para paso de prueba y empate del (Declaraciones).
 */
void Declaraciones();

/**
 * Función para prueba y empate del (Tipo).
 * @return entero que define el tipo.
 */
int Tipo();

/**
 * Función para prueba y empate del (Lista_Var).
 * @param lista_varTipoH entero del tipo.
 */
void Lista_Var(int lista_varTipoH);

/**
 * Función para prueba y empate del (Basico).
 * @return entero del tipo.
 */
int Basico();

/**
 * Función para prueba y empate del No-terminal (Compuesto).
 * @param base entero del tipo.
 * @return entero del tipo.
 */
int Compuesto(int base);

/**
 * Función para prueba y empate del No-terminal (Lop).
 * @param lista_varTipoH entero del tipo heredado.
 */
void Lop(int lista_varTipoH);

/**
 * Función para prueba y empate del No-terminal (Funciones).
 */
void Funciones();

/**
 * Función para prueba y empate del No-terminal (Argumentos).
 * @return lista de enteros que representan argumentos.
 */
list<int> Argumentos();

/**
 * Función para prueba y empate del No-terminal (Bloque).
 */
void Bloque();

/**
 * Función para prueba y empate del No-terminal (Lista_Args).
 * @return lista de enteros que representan argumentos.
 */
list<int> Lista_Args();

/**
 * Función para prueba y empate del No-terminal (Lista_ArgsP).
 * @param lista de enteros que representan argumentos.
 * @retrun lista de entero que representan argumentos.
 */
list<int> Lista_ArgsP(list<int> l);

/**
 * Función para prueba y empate del No-terminal (Instrucciones).
 * @return cadena con la instrucción siguiente.
 */
string Instrucciones();

/**
 * Función para prueba y empate del No-terminal (Sentencia).
 * @return cadena con la instrucción siguiente.
 */
string Sentencia(string sentencia);

/**
 * Función para prueba y empate del No-terminal (InstruccionesP).
 * @return cadena con la instrucción siguiente.
 */
string InstruccionesP();

/**
 * Función para prueba y empate del No-terminal (Sent).
 * @return lista de cadenas que contiene los indices.
 * @return cadena con la instrucción siguiente. 
 */
void Sent(list<string> listaI, string sig);

/**
 * Función para prueba y empate del No-terminal (Ret).
 */
void Ret();

/**
 * Función para prueba y empate del No-terminal (Pierna_Izquierda_Exodia).
 * @return estructrua del tipo piernaIzquierdaExodiaReturn.
 */
piernaIzquieraExodiaReturn Pierna_Izquierda_Exodia();

/**
 * Función para prueba y empate del No-terminal (Bool).
 * @param v cadena con la etiqueta verdadera.
 * @param f cadena con la etiqueta falsa.
 * @return estructura del tipo boolRetrun.
 */
boolReturn Bool(string v, string f);

/**
 * Función para prueba y empate del No-terminal (Casos).
 * @param siguiente etiqueta que define el siguiente.
 * @return estructura del tipo casosReturn.
 */
casosReturn Casos(string siguiente);

/**
 * Función para prueba y empate del No-terminal (Exp).
 * @return estructrua del tipo expReturn.
 */
expReturn Exp();

/**
 * Función para prueba y empate del No-terminal (Caso).
 * @param siguiente cadena de la instrucción siguiente.
 * @retrun estructura del tipo casoRetrun.
 */
casoReturn Caso(string siguiente);

/**
 * Función para prueba y empate del No-terminal (Predeterminado).
 * @param siguiente cadena de la instrucción siguiente.
 * @return estrutura del tipo predeterminadoRetrun.
 */
predeterminadoReturn Predeterminado(string siguiente);

/**
 * Función para prueba y empate del No-terminal (Ptt).
 * @param pttBase cadena con el valor léxico de una cadena.
 * @return estructura del tipo pttReturn.
 */
pttReturn Ptt(string pttBase);

/**
 * Función para prueba y empate del No-terminal (Localization).
 * @param localizationBase estructura del tipo localizationBase.
 * @return estructura del tipo localizationReturn.
 */
localizationReturn Localization(string localizationBase);

/**
 * Función para prueba y empate del No-terminal (Comb).
 * @param vddr cadena del valor verdadero.
 * @param fls cadena del valor falso.
 * @return estructrua del tipo combRetrun.
 */
combReturn Comb(string vddr, string fls);

/**
 * Función para prueba y empate del No-terminal (BoolP).
 * @param boolpAux estructura del tipo bollPReturn.
 * @return estructura del tipo boolPReturn.
 */
boolPReturn BoolP(boolPReturn boolpAux);

/**
 * Función para prueba y empate del No-terminal (Igualdad).
 * @param vddr cadena de la etiqueta verdadera.
 * @param fls cadena de la etiqueta falsa.
 * @return estructura del tipo igualdadReturn.
 */
igualdadReturn Igualdad(string vddr, string fls);

/**
 * Función para prueba y empate del No-terminal (Rel).
 * @param relVddr cadena de la etiqueta verdadera.
 * @param relFls cadena de la etiqueta falsa.
 * @return estrcutura del tipo relReturn.
 */
relReturn Rel(string relVddr, string relFls);

/**
 * Función para prueba y empate del No-terminal (IgualdadP).
 * @param relVddr cadena de la etiqueta verdadera.
 * @param relFls cadena de la etiqueta falsa.
 * @param tipoH entero del tipo.
 * @param dir cadena de la dirección.
 * @return estructura del tipo iguPReturn.
 */
iguPReturn IguP(string relVddr, string relFls, int tipoH, string dir);

/**
 * Función para prueba y empate del No-terminal (CombP).
 * @param combPP estrucutra del tipo combPReturn.
 * @return estrucutra del tipo combPReturn.
 */
combPReturn CombP(combPReturn combPP);

/**
 * Función para prueba y empate del No-terminal (Xp).
 * @param v cadena de la etiqueta verdadera.
 * @param f cadena de la etiqueta falsa.
 * @param tipo entero que define el tipo.
 */
xpReturn Xp(string v, string f, int tipo);

/**
 * Función para prueba y empate del No-terminal (Term).
 * @return estructura del tipo termReturn.
 */
termReturn Term();

/**
 * Función para prueba y empate del No-terminal (ExP).
 * @param tipe entero que define el tipo.
 * @param dir cadena que define la dirección.
 * @retrun estructura del tipo exReturn.
 */
exReturn Ex(int tipe, string dir);

/**
 * Función para prueba y empate del No-terminal (Unario).
 * @return estructura del tipo unarioReturn.
 */
unarioReturn Unario();

/**
 * Función para prueba y empate del No-terminal (TerP).
 * @param tipe entero que define el tipo.
 * @param dire cadena de la dirección.
 * @return estrctura del tipo terPReturn.
 */
terPReturn TerP(int tipe, string dire);

/**
 * Función para prueba y empate del No-terminal (Factor).
 * @return estructura del tipo factorReturn.
 */
factorReturn Factor();

/**
 * Función para prueba y empate del No-terminal (Faacc).
 * @param id cadena con el valor léxico de un id.
 * @return estructura del tipo faaccReturn.
 */
faaccReturn Faacc(string id);

/**
 * Función para prueba y empate del No-terminal (Parametros).
 * @return lista de enteros con los parametros.
 */
list<int> Parametros();

/**
 * Función para prueba y empate del No-terminal (Lista_Param).
 * @return lista de enteros que con los parametros.
 */
list<int> Lista_Param();

/**
 * Función para prueba y empate del No-terminal (ListP).
 * @param listaH lista de enteros heredada.
 * @return lista de enteros con los parametros.
 */
list<int> ListP(list<int> listaH);

/**
 * Función para prueba y empate del No-terminal (LocalP).
 * @param localPBase cadena con el valor léxico de un id.
 * @param tipo entero que define el tipo.
 * @param direc cadena con la dirección.
 * @return estructura del tipo localPRetrun.
 */
localPReturn LocalP(string localPBase, int tipo, string direc);

/**
 * Función para consumo de componente léxico actual al hacer empate.
 * @param clase entero con una clase léxica.
 * @return entero del empate con un valor léxico.
 */
int eat(int clase);

/**
 * Función principal del compilador que manda llamar las funciones necesarias.
 * @param t Token inicial del compilado.
 * @param name cadena con el nombre del archivo a leer.
 * @param falg bandera que indica si se mostrarán tablas al final de la ejecucion.
 */
void parse(Token t, string name, string flag);

/**
 * Función que inicializa la tabla de tipos.
 */
void construirTablaTipos();

/**
 * Función que inicializa la tabla de simbolos.
 */
void construirTablaSimbolos();

/**
 * Función que busca un identificador en la tabla de simbolos.
 * @param str identificador a buscar.
 * @return entero que indica si se encontró el identificador.
 */
int buscarIDTS(string str);

/**
 * Función que busca en el fondo de la tabla un idenficador.
 * @param id idenficador a buscar.
 * @return entero que indica si se encontró el identificador.
 */
int buscarIDTSFondo(string id);

/**
 * Función que inserta un tipo en la tabla de tipos.
 * @param tipooo estructura del tipo TipTipe.
 */
void insertarTipoTop(TipTipe tipooo);

/**
 * Función que inserta un simbolo en la tabla de simbolos.
 * @param id cadena que define un indetificador.
 * @param dir entero de la dirección del simbolo.
 * @param type entero del tipo del identificador.
 * @param var entero que define la variable del indentificador.
 * @param args lista de argumentos del simbolo.
 */
void insertarSimbolo(string id, int dir, int type, int var, list<int> args);

/**
 * Función para reporte de errores sintácticos y semánticos.
 */
void errorSintactico();

/**
 * Función para reporte de errores sintácticos y semánticos.
 * @param fail cadena con el error a mostar.
 * @param linea entero con la linea del error.
 * @param error token a mostrar en el error.
 */
void errorSemantico(string fail, int linea, string error);

/**
 * Función que determina si los tipos de la lista son iguales al tipo.
 * @param tipo entero a comparar con la lista de retorno.
 */
int equivalentesLista(int tipo);

/**
 * Función que genera código.
 * @param opcion cadena de la operación.
 * @param arg1 cadena de primer argumento de la operación.
 * @param arg2 cadena de segundo argumento de la operación.
 * @param res cadena de resultado de operación.
 */
void generarCodigo(string opcion, string arg1,  string arg2, string res);

/**
 * Función que genera una nueva etiqueta.
 * @return cadena de la nueva etiqueta.
 */
string nuevaEtiqueta();

/**
 * Función que genera un nuevo indice.
 * @return cadena del nuevo indice.
 */
string nuevoIndice();

/**
 * Función que genera una nueva temporal.
 * @return cadena de la nueva temporal.
 */
string nuevaTemporal();

/**
 * Función que obtiene el tipo de un identificador.
 * @param id identificador a buscar.
 * @return entero del tipo.
 */
int getTipoTS(string id);

/**
 * Función que obtiene el nombre de un tipo.
 * @param tipoTemp entero del tipo a buscar.
 * @param strTipo cadena a comparar.
 * @return entero que indica si se encontró.
 */
int getNombre(int tipoTemp, string strTipo);

/**
 * Función que obtiene el tamaño de un tipo.
 * @param tipo entero del tipo a buscar.
 * @return entero del tamaño a buscar.
 */
int getTamTT(int tipo);

/**
 * Función que devuele la tabla del fondo de la pila de simbolos.
 * @param ts pila de listas de simbolos.
 * @return lista de simbolos.
 */
list<Simbolo> fondo(stack<list<Simbolo>> ts);

/**
 * Función que obtiene la variable del fondo de la pila de simbolos.
 * @param id cadena a buscar.
 * @return entero de la variable del id.
 */
int getVarPTSFondo(string id);

/**
 * Función que obtiene la lista de variables de un simbolo en el fondo.
 * @param id cadena de identificador a buscar.
 * @return lista de enteros de las variables.
 */
list<int> getVarListPTSFondo(string id);

/**
 * Función que determina si dos listas son iguales.
 * @param uno primera lista de enteros.
 * @param  dos segunda lista de enteros.
 * @return entero que determina si las listas son iguales.
 */
int equivalenteListas(list<int> uno, list<int> dos);

/**
 * Función que determina si dos enteros son iguales.
 * @param tipoH primer entero a comparar.
 * @param unarioH segundo entero a comparar.
 * @return entero que indica si son iguales.
 */
int equivalentes(int tipoH, int unarioH);

/**
 * Función que escribe el código en un archivo,
 * @param codigo cadena de código a escribir en el archivo.
 * @param name cadena de nombre del archivo a escribir. 
 */
void escribirCodigo(string codigo, string name);

/**
 * Función que construye la cadena del código.
 * @return cadena con el código construido.
 */
string obtenerCodigo();

/**
 * Función que 
 * @return cadena con la tabla de simbolos.
 */
string verTablasSimbolos();

/**
 * Función que 
 * @return cadena con la tabla de tipos.
 */
string verTablasTipos();

/**
 * Función que muestra las tablas de simbolos y tipos.
 * @param flag bandera que determina si se muestran las tablas o no.
 */
void mostrarTablas(string flag);

#endif