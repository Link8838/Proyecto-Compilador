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

};

#endif