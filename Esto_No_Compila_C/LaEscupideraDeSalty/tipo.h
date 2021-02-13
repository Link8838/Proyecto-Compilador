#ifndef TIPTIPE_H
#define TIPTIPE_H
#include <string>
#include <list>
using namespace std;

struct TipTipe {
    int id;
    string tipo;
    int tam;
    int elem;
    int tipoBase;

    TipTipe(){}

    TipTipe(int id, string tipo, int tam, int elem, int tipoBase){
        this -> id = id;
        this -> tipo = tipo;
        this -> tam = tam;
        this -> elem = elem;
        this -> tipoBase = tipoBase;
    }

    /**
    * Inicialización de tipo.
    */
    TipTipe crea_tipo(int id, string tipo, int tam, int elem, int tipoBase){
      return TipTipe(id, tipo, tam, elem, tipoBase);
    }

    string printTipo(){
        string simb;        
        string spc = " ";
        simb += to_string(id) + spc + tipo + to_string(tam) + to_string(elem) + spc + to_string(tipoBase);
        return simb;
    }

};

#endif