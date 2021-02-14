/**
 * Proyecto Final: Compiladores
 * Figueroa Sandoval Gerardo Emiliano
 * Hernández Ferreiro Enrique Ehecatl
 * López Soto Ramses Antonio
 * Quintero Villeda Erik
*/

#ifndef TIPTIPE_H
#define TIPTIPE_H
#include <string>
#include <list>
using namespace std;

/**
 * Estructura que define el Tipo.
 * (se llama TipTipe porque nunca compiló con el nombre Tipo)
 * (no sabemos por qué).
 */
struct TipTipe {
    int id;
    string tipo;
    int tam;
    int elem;
    int tipoBase;

    //Constructor por omisión del Tipo.
    TipTipe(){}

    //Constructor con paso de parámetros.
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

    /**
     * Función que convierte un tipo a cadena.
     * @return cadena con la representación del Tipo.
     */
    string printTipo(){
        string simb = "         ";        
        string spc = " ";
        int res;
        simb += to_string(id);
        res = 7 - to_string(id).length();
        for(int i = 0; i<res; i++){
          simb += spc;
        }
        simb += tipo;
        res = 12 - tipo.length();
        for(int i = 0; i<res; i++){
          simb += spc;
        }
        simb += to_string(tam);
        res = 11 - to_string(tam).length();
        for(int i = 0; i<res; i++){
          simb += spc;
        }
        simb += to_string(elem);
        res = 13 - to_string(elem).length();
        for(int i = 0; i<res; i++){
          simb += spc;
        }
        simb += to_string(tipoBase);
        return simb;
    }

};

#endif