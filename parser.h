/**
 * Práctica 7: Compiladores
 * Figueroa Sandoval Gerardo Emiliano
 * Hernández Ferreiro Enrique Ehecatl
 * López Soto Ramses Antonio
 * Quintero Villeda Erik
*/

#include <stdbool.h>
#include "lista.h"


/* Dirección disponible en la TT */
int dir;

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
void Tipo();

/**
 * Función para prueba y empate del (Lista_Var)
 */
void Lista_Var();

/**
 * Función para prueba y empate del (Basico)
 */
void Basico();

/**
 * Función para prueba y empate del No-terminal (Compuesto)
 */
void Compuesto();

/**
 * Función para prueba y empate del No-terminal (Lop)
 */
void Lop();

/**
 * Función para prueba y empate del No-terminal (Funciones)
 */
void Funciones();

/**
 * Función para prueba y empate del No-terminal (Argumentos)
 */
void Argumentos();

/**
 * Función para prueba y empate del No-terminal (Bloque)
 */
void Bloque();

/**
 * Función para prueba y empate del No-terminal (Lista_Args)
 */
void Lista_Args();

/**
 * Función para prueba y empate del No-terminal (Lista_ArgsP)
 */
void Lista_ArgsP();

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
void Pierna_Izquierda_Exodia();

/**
 * Función para prueba y empate del No-terminal (Bool)
 */
void Bool();

/**
 * Función para prueba y empate del No-terminal (Casos)
 */
void Casos();

/**
 * Función para prueba y empate del No-terminal (Exp)
 */
void Exp();

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
void Ptt();

/**
 * Función para prueba y empate del No-terminal (Localization)
 */
void Localization();

/**
 * Función para prueba y empate del No-terminal (Comb)
 */
void Comb();

/**
 * Función para prueba y empate del No-terminal (BoolP)
 */
void BoolP();

/**
 * Función para prueba y empate del No-terminal (Igualdad)
 */
void Igualdad();

/**
 * Función para prueba y empate del No-terminal (Rel)
 */
void Rel();

/**
 * Función para prueba y empate del No-terminal (IgualdadP)
 */
void IgualdadP();

/**
 * Función para prueba y empate del No-terminal (CombP)
 */
void CombP();

/**
 * Función para prueba y empate del No-terminal (Xp)
 */
void Xp();

/**
 * Función para prueba y empate del No-terminal (Term)
 */
void Term();

/**
 * Función para prueba y empate del No-terminal (Exx)
 */
void Exx();

/**
 * Función para prueba y empate del No-terminal (ExP)
 */
void ExP();

/**
 * Función para prueba y empate del No-terminal (Unario)
 */
void Unario();

/**
 * Función para prueba y empate del No-terminal (Terrr)
 */
void Terrr();

/**
 * Función para prueba y empate del No-terminal (TerP)
 */
void TerP();

/**
 * Función para prueba y empate del No-terminal (Factor)
 */
void Factor();

/**
 * Función para prueba y empate del No-terminal (Faacc)
 */
void Faacc();

/**
 * Función para prueba y empate del No-terminal (Parametros)
 */
void Parametros();

/**
 * Función para prueba y empate del No-terminal (Lista_Param)
 */
void Lista_Param();

/**
 * Función para prueba y empate del No-terminal (ListP)
 */
void ListP();

/**
 * Función para prueba y empate del No-terminal (LocalP)
 */
void LocalP();

/**
 * Función para consumo de componente léxico actual al hacer empate
 */
int eat(int clase);

/**
 * Función principal de análisis sintáctico.
 * Debe llamar a función de símbolo inicial de la gramática.
 * También inicializar las tablas de símbolos y tipos.
 */
void parse();

/**
 * Función para reporte de errores sintácticos y semánticos.
 */
void error();
