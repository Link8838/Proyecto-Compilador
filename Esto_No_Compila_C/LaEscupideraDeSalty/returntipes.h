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

struct combReturn{
    string fls;
    int tipo;

    combReturn(){}

    combReturn(string fls, int tipo){
        this -> fls = fls;
        this -> tipo = tipo;
    }
};

struct igualdadReturn{
    string dir;
    int tipo;

    igualdadReturn(){}

    igualdadReturn(string dir, int tipo){
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

struct exxReturn{
    string dir;
    int tipo;

    exxReturn(){}

    exxReturn(string dir, int tipo){
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

struct terrrReturn{
    string dir;
    int tipo;

    terrrReturn(){}

    terrrReturn(string dir, int tipo){
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