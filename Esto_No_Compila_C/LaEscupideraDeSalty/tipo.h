#ifndef TIPO_H
#define TIPO_H
#include <string>
using namespace std;

struct Tipo {
    int id;
    string tipo;
    int tam;
    int elem;
    int tipoBase;

    Tipo();

    Tipo(int id, string tipo, int tam, int elem, int tipoBase){
		this -> id = id;
		this -> tipo = tipo;
		this -> tam = tam;
		this -> elem = elem;
		this -> tipoBase = tipoBase;
    }

    /**
    * Inicialización de tipo.
    */
    Tipo crea_tipo(int id, string tipo, int tam, int elem, int tipoBase){
      return Tipo(id, tipo, tam, elem, tipoBase);
    }

};

#endif