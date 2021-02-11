#ifndef RETURTIPES_H
#define RETURTIPES_H
#include <string>
#include <list>
using namespace std;

struct piernaIzquieraExodiaReturn{
    string dir;
    string id;
    int tipo;
    int arreglo;

    piernaIzquieraExodiaReturn(){}

    piernaIzquieraExodiaReturn(string dir, string id, int tipo, int arreglo){
        this -> dir = dir;
        this -> id = id;
        this -> tipo = tipo;
        this -> arreglo = arreglo;
    }
};

struct pttReturn{
    string dir;
    int tipo;
    int arreglo;

    pttReturn(){}

    pttReturn(string dir, int tipo, int arreglo){
        this -> dir = dir;
        this -> tipo = tipo;
        this -> arreglo = arreglo;
    }
};

struct boolReturn{
    string dir;
    int tipo;

    boolReturn(){}

    boolReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

struct boolPReturn{
    string dir;
    string verdadero;
    string falso;
    int tipo;
    list<string> listaIndices;

    boolPReturn(){}

    boolPReturn(string dir,string verdadero, string falso, int tipo, list<string> listaIndices){
        this -> dir = dir;
        this -> verdadero = verdadero;
        this -> falso = falso;
        this -> tipo = tipo;
        this -> listaIndices = listaIndices;
    }
};

struct combReturn{
    string dir;
    int tipo;

    combReturn(){}

    combReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

struct combPReturn{
    string dir;
    int tipo;
    list<string> listaIndices;

    combPReturn(){}

    combPReturn(string dir, int tipo, list<string> listaIndices){
        this -> dir = dir;
        this -> tipo = tipo;
        this -> listaIndices = listaIndices;
    }
};

struct igualdadReturn{
    string dir;
    string verdadero;
    int tipo;

    igualdadReturn(){}

    igualdadReturn(string dir, int tipo, string verdadero){
        this -> dir = dir;
        this -> tipo = tipo;
        this -> verdadero = verdadero;
    }
};

struct iguPReturn{
    string verdadero;
    string falso;
    string dir;
    int tipo;

    iguPReturn(){}

    iguPReturn(string verdadero, string falso, string dir, int tipo){
        this -> verdadero = verdadero;
        this -> falso = falso;
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

struct relReturn{
    string verdadero;
    string falso;
    string dir;
    int tipo;

    relReturn(){}

    relReturn(string verdadero, string falso, string dir, int tipo){
        this -> verdadero = verdadero;
        this -> falso = falso;
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

struct xpReturn{
    string verdadero;
    string falso;
    string dir;
    int tipo;

    xpReturn(){}

    xpReturn(string verdadero, string falso, string dir, int tipo){
        this -> verdadero = verdadero;
        this -> falso = falso;
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

struct expReturn{
    string dir;
    int tipo;

    expReturn(){}

    expReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

struct exReturn{
    string dir;
    int tipo;

    exReturn(){}

    exReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

struct termReturn{
    string dir;
    int tipo;

    termReturn(){}

    termReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

struct terPReturn{
    string dir;
    int tipo;

    terPReturn(){}

    terPReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

struct unarioReturn{
    string dir;
    int tipo;

    unarioReturn(){}

    unarioReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

struct factorReturn{
    string dir;
    int tipo;

    factorReturn(){}

    factorReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

struct faaccReturn{
    string dir;
    int tipo;

    faaccReturn(){}

    faaccReturn(string dir, int tipo){
        this -> dir = dir;
        this -> tipo = tipo;
    }
};

struct localizationReturn{
    string dir;
    int tipo;
    int tam;        

    localizationReturn(){}

    localizationReturn(string dir, int tipo, int tam ){
        this -> dir = dir;
        this -> tipo = tipo;
        this -> tam = tam;
    }
};

struct localPReturn{
    string dir;
    int tipo;
    int tam;

    localPReturn(){}

    localPReturn(string dir, int tipo, int tam){
        this -> dir = dir;
        this -> tipo = tipo;
        this -> tam = tam;
    }
};

#endif