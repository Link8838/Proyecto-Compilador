#ifndef RETURTIPES_H
#define RETURTIPES_H
#include <string>
#include <list>
using namespace std;

/**
 * Estructura que define el tipo de retorno para la función piernaIzquieraExodia.
 */
struct piernaIzquieraExodiaReturn{
    string dir = " ";
    string id = " ";
    int tipo;
    int arreglo;

    //Constructor por omisión.
    piernaIzquieraExodiaReturn(){}

    //Constructro con paso de parámetros.
    piernaIzquieraExodiaReturn(string dir, string id, int tipo, int arreglo){
        this -> dir = dir;
        this -> id = id;
        this -> tipo = tipo;
        this -> arreglo = arreglo;
    }
};

/**
 * Estructura que define el tipo de retorno para la función casos.
 */
struct casosReturn{
    string siguiente = " ";
    string prueba = " ";

    //Constructor por omisión.
    casosReturn(){}

    //Constructro con paso de parámetros.
    casosReturn(string siguiente, string prueba){
        this -> siguiente = siguiente;
        this -> prueba = prueba;
    }
};

/**
 * Estructura que define el tipo de retorno para la función caso.
 */
struct casoReturn{
    string inicio = " ";
    string prueba = " ";
    string siguiente = " ";

    //Constructor por omisión.
    casoReturn(){}

    //Constructro con paso de parámetros.
    casoReturn(string inicio, string prueba, string siguiente){
        this -> inicio = inicio;
        this -> prueba = prueba;
        this -> siguiente = siguiente;
    }
};

/**
 * Estructura que define el tipo de retorno para la función predeterminado.
 */
struct predeterminadoReturn{
    string inicio = " ";
    string prueba = " ";
    string siguiente = " ";

    //Constructor por omisión.
    predeterminadoReturn(){}

    //Constructro con paso de parámetros.
    predeterminadoReturn(string inicio, string prueba, string siguiente){
        this -> inicio = inicio;
        this -> prueba = prueba;
        this -> siguiente = siguiente;
    }
};

/**
 * Estructura que define el tipo de retorno para la función ptt.
 */
struct pttReturn{
    string dir = " ";
    int tipo;
    int arreglo;

    //Constructor por omisión.
    pttReturn(){}

    //Constructro con paso de parámetros.
    pttReturn(string dir, int tipo, int arreglo){
        this -> dir = dir;
        this -> tipo = tipo;
        this -> arreglo = arreglo;
    }
};

/**
 * Estructura que define el tipo de retorno para la función bool.
 */
struct boolReturn{
    string dir = " ";
    string verdadero = " ";
    string falso = " ";
    int tipo;

    //Constructor por omisión.
    boolReturn(){}

    //Constructro con paso de parámetros.
    boolReturn(string dir,string verdadero, string falso, int tipo){
        this -> dir = dir;
        this -> verdadero = verdadero;
        this -> falso = falso;
        this -> tipo = tipo;
    }
};

/**
 * Estructura que define el tipo de retorno para la función boolP.
 */
struct boolPReturn{
    string dir = " ";
    string verdadero = " ";
    string falso = " ";
    int tipo;
    list<string> listaIndices;

    //Constructor por omisión.
    boolPReturn(){}

    //Constructro con paso de parámetros.
    boolPReturn(string dir,string verdadero, string falso, int tipo, list<string> listaIndices){
        this -> dir = dir;
        this -> verdadero = verdadero;
        this -> falso = falso;
        this -> tipo = tipo;
        this -> listaIndices = listaIndices;
    }
};

/**
 * Estructura que define el tipo de retorno para la función comb.
 */
struct combReturn{
    string dir = " ";
    int tipo;

    //Constructor por omisión.
    combReturn(){}

    //Constructro con paso de parámetros.
    combReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

/**
 * Estructura que define el tipo de retorno para la función combP.
 */
struct combPReturn{
    string dir = " ";
    int tipo;
    list<string> listaIndices;

    //Constructor por omisión.
    combPReturn(){}

    //Constructro con paso de parámetros.
    combPReturn(string dir, int tipo, list<string> listaIndices){
        this -> dir = dir;
        this -> tipo = tipo;
        this -> listaIndices = listaIndices;
    }
};

/**
 * Estructura que define el tipo de retorno para la función igualdad.
 */
struct igualdadReturn{
    string dir = " ";
    string verdadero = " ";
    int tipo;

    //Constructor por omisión.
    igualdadReturn(){}

    //Constructro con paso de parámetros.
    igualdadReturn(string dir, int tipo, string verdadero){
        this -> dir = dir;
        this -> tipo = tipo;
        this -> verdadero = verdadero;
    }
};

/**
 * Estructura que define el tipo de retorno para la función iguP.
 */
struct iguPReturn{
    string verdadero = " ";
    string falso = " ";
    string dir = " ";
    int tipo;

    //Constructor por omisión.
    iguPReturn(){}

    //Constructro con paso de parámetros.
    iguPReturn(string verdadero, string falso, string dir, int tipo){
        this -> verdadero = verdadero;
        this -> falso = falso;
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

/**
 * Estructura que define el tipo de retorno para la función rel.
 */
struct relReturn{
    string verdadero = " ";
    string falso = " ";
    string dir = " ";
    int tipo;

    //Constructor por omisión.
    relReturn(){}

    //Constructro con paso de parámetros.
    relReturn(string verdadero, string falso, string dir, int tipo){
        this -> verdadero = verdadero;
        this -> falso = falso;
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

/**
 * Estructura que define el tipo de retorno para la función xp.
 */
struct xpReturn{
    string verdadero = " ";
    string falso = " ";
    string dir = " ";
    int tipo;

    //Constructor por omisión.
    xpReturn(){}

    //Constructro con paso de parámetros.
    xpReturn(string verdadero, string falso, string dir, int tipo){
        this -> verdadero = verdadero;
        this -> falso = falso;
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

/**
 * Estructura que define el tipo de retorno para la función exp.
 */
struct expReturn{
    string dir = " ";
    int tipo;

    //Constructor por omisión.
    expReturn(){}

    //Constructro con paso de parámetros.
    expReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

/**
 * Estructura que define el tipo de retorno para la función ex.
 */
struct exReturn{
    string dir = " ";
    int tipo;

    //Constructor por omisión.
    exReturn(){}

    //Constructro con paso de parámetros.
    exReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

/**
 * Estructura que define el tipo de retorno para la función term.
 */
struct termReturn{
    string dir = " ";
    int tipo;

    //Constructor por omisión.
    termReturn(){}

    //Constructro con paso de parámetros.
    termReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

/**
 * Estructura que define el tipo de retorno para la función terP.
 */
struct terPReturn{
    string dir = " ";
    int tipo;

    //Constructor por omisión.
    terPReturn(){}

    //Constructro con paso de parámetros.
    terPReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

/**
 * Estructura que define el tipo de retorno para la función unario.
 */
struct unarioReturn{
    string dir = " ";
    int tipo;

    //Constructor por omisión.
    unarioReturn(){}

    //Constructro con paso de parámetros.
    unarioReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

/**
 * Estructura que define el tipo de retorno para la función factor.
 */
struct factorReturn{
    string dir = " ";
    int tipo;

    //Constructor por omisión.
    factorReturn(){}

    //Constructro con paso de parámetros.
    factorReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

/**
 * Estructura que define el tipo de retorno para la función faacc.
 */
struct faaccReturn{
    string dir = " ";
    int tipo;

    //Constructor por omisión.
    faaccReturn(){}

    //Constructro con paso de parámetros.
    faaccReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

/**
 * Estructura que define el tipo de retorno para la función localization.
 */
struct localizationReturn{
    string dir = " ";
    int tipo;
    int tam;        

    //Constructor por omisión.
    localizationReturn(){}

    //Constructro con paso de parámetros.
    localizationReturn(string dir, int tipo, int tam ){
        this -> dir = dir;
        this -> tipo = tipo;
        this -> tam = tam;
    }
};

/**
 * Estructura que define el tipo de retorno para la función localP.
 */
struct localPReturn{
    string dir = " ";
    int tipo;
    int tam;

    //Constructor por omisión.
    localPReturn(){}

    //Constructro con paso de parámetros.
    localPReturn(string dir, int tipo, int tam){
        this -> dir = dir;
        this -> tipo = tipo;
        this -> tam = tam;
    }
};

#endif