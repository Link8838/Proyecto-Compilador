/**
 * Proyecto Final: Compiladores
 * Figueroa Sandoval Gerardo Emiliano
 * Hernández Ferreiro Enrique Ehecatl
 * López Soto Ramses Antonio
 * Quintero Villeda Erik
*/

#ifndef SIMBOLO_H
#define SIMBOLO_H
#include <string>
#include <list>
using namespace std;

/**
 * Estructura que definie los simbolos.
 */
struct Simbolo {
    string id;
    int dir;
    int type;
    int var;
    list<int> args;

    //Construcción por omisión.
    Simbolo(){}

    //Construcctor con paso de parámetros.
    Simbolo(string id, int dir, int type, int var, list<int> args){
    	this -> id = id;
    	this -> dir = dir;
    	this -> type = type;
    	this -> var = var;
    	this -> args = args;
    }

    /**
    * Inicialización de simbolo.
    */
    Simbolo crea_simbolo(string id, int dir, int type, int var, list<int> args){
      return Simbolo(id, dir, type, var, args);
    }

    /**
     * Función que convierte un símbolo a cadena para su impresión.
     * @return cadena que representa un simbolo.
     */
    string printSimbolo(){
        string simb = "           ";
        string list = "[";
        string coma = ",";
        string spc = " ";

        if(args.size() > 0){
            for(int i : args){
                list += to_string(i) + coma;
            }
            list = list.substr(0,list.length()-1);
        }
        list += "]";

        simb += id;
        int res = 11 - id.length();
        for(int i = 0; i<res; i++){
          simb += spc;
        }
        simb += to_string(dir);
        res = 8 - to_string(dir).length();
        for(int i = 0; i<res; i++){
          simb += spc;
        }
        simb += to_string(type);
        res = 8 - to_string(type).length();
        for(int i = 0; i<res; i++){
          simb += spc;
        }
        simb += to_string(var);
        res = 9 - to_string(var).length();
        for(int i = 0; i<res; i++){
          simb += spc;
        }
        simb += list;
        return simb;
    }

};

#endif