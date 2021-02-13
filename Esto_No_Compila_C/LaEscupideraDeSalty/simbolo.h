#ifndef SIMBOLO_H
#define SIMBOLO_H
#include <string>
#include <list>
using namespace std;

struct Simbolo {
    string id;
    int dir;
    int type;
    int var;
    list<int> args;

    Simbolo(){}

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

    string printSimbolo(){
        string simb;
        string list = "[";
        string coma = ",";
        string spc = " ";
        for(int i : args){
            list += to_string(i) + coma;
        }
        list += "]";
        simb += id + spc + to_string(dir) + spc + to_string(type) + spc + to_string(var) + spc + list;
        return simb;
    }

};

#endif