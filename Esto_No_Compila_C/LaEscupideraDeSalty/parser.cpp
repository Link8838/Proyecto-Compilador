/**
 * Práctica 7: Compiladores
 * Figueroa Sandoval Gerardo Emiliano
 * Hernández Ferreiro Enrique Ehecatl
 * López Soto Ramses Antonio
 * Quintero Villeda Erik
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include "parser.h"

//Programar a parte las funciones auxiliares
using namespace std;
extern Token yylex();
extern int yylineno;

int auxlinea = 0;
string auxID = "";

int dir = -1;
int iE = 0;
int iI = 0;
int iT = 0;

Token tA;
TipTipe tipo;
Simbolo simb;

list<TipTipe> tablaTipos;
list<Simbolo> tablaSimbolos;
list<int> listaRetorno;

stack<list<TipTipe>> pilaTablaTipos;
stack<list<Simbolo>> pilaTablaSimbolos;
stack<string> tablaCadenas;

list<vector<string>> codigo;



int eat(int clase){
  int f = 0;
  if (tA.clase == clase) {
    f = 1;
  }
  return f;
}

void parse(Token tk) {
  tA = tk;
  construirTablaTipos();
  Programa();
  //printf("\nDIRECCION: %i\n", dir);
}

void Programa(){
  pilaTablaTipos.push(tablaTipos);
  pilaTablaSimbolos.push(tablaSimbolos);
  dir = 0;
  Declaraciones();  
  Funciones();
}

void Declaraciones(){
  //printf("Aguacate %s\n",tA -> valor);
  if(eat(FLOAT) || eat(CHAR) || eat(DOUBLE) || eat(VOID) || eat(INT)){//FIRST DE TIPO
    int lista_varTipoH = Tipo();
    Lista_Var(lista_varTipoH);
    if (eat(PCOMA)) {
      //printf("Aguacate %s\n",tA -> valor);
      tA = yylex();
      Declaraciones();
    }else{
      errorSintactico();
    }
  }
}

int Tipo(){
//  printf("\n**PROGRAMA**\n");
  int compuestoBase = Basico();
  //printf("Aguacate %i\n", compuestoTipo);
  int tipoTipo = Compuesto(compuestoBase);
  return tipoTipo;
}

void Lista_Var(int lista_varTipoH){
  if (eat(ID)) {
    //printf("%s\n",tA -> valor);
    auxID = tA.valor;
    int linea = yylineno;
    if(!buscarIDTS(tA.valor)){      
      list<int> arrgs;
      insertarSimbolo(tA.valor, dir, lista_varTipoH, 0, arrgs);//QUIZÁ NO ES 0
      dir += pilaTablaTipos.top().front().tam;
    } else {
      errorSemantico("El ID ya fue declarado:", linea, tA.valor);
    }
    tA = yylex();
    Lop(lista_varTipoH);
  }else{
    errorSintactico();
  }
}

int Basico(){
  int basicoTipo = -1;
  if (eat(INT)) {
    //printf("INT: %s\n",tA -> valor);
    basicoTipo = 1;    
    tA = yylex();
  } else if (eat(FLOAT)) {
    //printf("%s\n",tA -> valor);
    basicoTipo = 3;    
    tA = yylex();
  } else if (eat(CHAR)) {
    //printf("%s\n",tA -> valor);
    basicoTipo = 4;    
    tA = yylex();
  } else if (eat(DOUBLE)) {
    //printf("%s\n",tA -> valor);
    basicoTipo = 2;    
    tA = yylex();
  } else if (eat(VOID)) {
    //printf("%s\n",tA -> valor);
    basicoTipo = 0;    
    tA = yylex();
  } else {
    errorSintactico();
  }
  return basicoTipo;
}

int Compuesto(int base){
  int compuestoTipo = -1;
  int tamArr, tipeArr;
  if (eat(CIZQ)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      if (eat(NUM)) {
        //printf("%s\n",tA -> valor);
        tA = yylex();
        tamArr = atoi(tA.valor.c_str());
        tipeArr = tA.tipo;
        if (eat(CDER)) {
          //printf("%s\n",tA -> valor);
          TipTipe array = TipTipe(5,"ARRAY",tamArr,-1,tipeArr);
          insertarTipoTop(array);
          compuestoTipo = tipeArr;//COSAS RARAS        
          tA = yylex();
          Compuesto(base);
      }else{
        errorSintactico();
      }
    }else {
      errorSintactico();
    }
  } else {
    compuestoTipo = base;
  }
  return compuestoTipo;
}

void Lop(int lista_varTipoH){
  if (eat(COMA)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      if (eat(ID)) {
          //printf("%s\n",tA -> valor);
            int linea = yylineno;
            if(!buscarIDTS(tA.valor)){
              list<int> arrgs;
              insertarSimbolo(tA.valor, dir, lista_varTipoH, 0, arrgs);//QUIZÁ NO ES 0
              dir += pilaTablaTipos.top().front().tam;
            } else {
              errorSemantico("El ID ya fue declarado:", linea, tA.valor);
            }
          tA = yylex();
          Lop(lista_varTipoH);
      }
  }
}

void Funciones(){
  //printf("**FUNCIONES!**%s\n");
  if (eat(FUNC)) {
      //printf("%s\n",tA -> valor);      
      list<Simbolo> nuevaTablaSimb;
      list<TipTipe> nuevaTablaTipo;
      list<int> nuevaListaRetorno;
      listaRetorno = nuevaListaRetorno;
      stack<int> pilaDir;
      pilaTablaSimbolos.push(nuevaTablaSimb);
      pilaTablaTipos.push(nuevaTablaTipo);
      pilaDir.push(dir);
      dir = 0;      
      tA = yylex();
      int tipoTipo = Tipo();
      int linea;
      //printf("FUNCIONES TIPO: %i\n", tipoTipo);
      if (eat(ID)) {
          //printf("%s\n",tA -> valor);
          string idAux = tA.valor;
          linea = yylineno;
          tA = yylex();
          if (eat(PIZQ)) {
              //printf("%s\n",tA -> valor);
              tA = yylex();
              list<int> argumentosLista = Argumentos();
              if (eat(PDER)) {
                  //printf("%s\n",tA -> valor);
                  tA = yylex();
                  Bloque();
                  pilaTablaSimbolos.pop();
                  pilaTablaTipos.pop();  
//                  listaRetorno.push_front(0);
                  if(!buscarIDTS(idAux)){
                    //printf("BUSCAR ID FUNC\n");
                    if(equivalentesLista(tipoTipo)){
                      insertarSimbolo(idAux, dir, tipoTipo, 2, argumentosLista);//QUIZÁ NO ES 0
                      generarCodigo(nuevaEtiqueta(), idAux, "", nuevoIndice());
                    } else {
                      errorSemantico("Los tipos de retorno no coinciden:", linea, idAux);
                    }
                  } else {
                    errorSemantico("El ID ya fue declarado:", linea, idAux);
                  }
                  Funciones();                  
              } else{
                errorSintactico();
              }
          }else{
            errorSintactico();
          }
      } else {
        errorSintactico();
      }
  } else if(eat(FIN)){
    printf(">Fin del analisis Sintantico\n**CADENA ACEPTADA**\n");
  }
}

list<int> Argumentos(){
  list<int> argumentosLista;
  if (eat(FLOAT) || eat(CHAR) || eat(DOUBLE) || eat(VOID) || eat(INT)) {//FIRST TIPO    
    argumentosLista = Lista_Args();
  } 
  return argumentosLista;
}

void Bloque(){
  if (eat(LLAIZQ)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Declaraciones();
    Instrucciones();
    if (eat(LLADER)) {
        //printf("%s\n",tA -> valor);
        tA = yylex();
    }else{
      errorSintactico();
    }
  }else{
    errorSintactico();
  }
}

list<int> Lista_Args(){
  int tipoTipo = Tipo();
  list<int> lista_argsLista;
  if (eat(ID)) {
      //printf("%s\n",tA -> valor);
    int linea = yylineno;
    if(!buscarIDTS(tA.valor)){
      list<int> arrgs;
      insertarSimbolo(tA.valor, dir, tipoTipo, 1, arrgs);//QUIZÁ NO ES 0
      dir += pilaTablaTipos.top().front().tam;
    } else {
      errorSemantico("El ID ya fue declarado:", linea, tA.valor);
    }

    tA = yylex();
    list<int> nuevaListaArgs;
    nuevaListaArgs.push_front(tipoTipo);
    lista_argsLista = Lista_ArgsP(nuevaListaArgs);
  }else{
    errorSintactico();
  }
  return lista_argsLista;
}

list<int> Lista_ArgsP(list<int> lista_argsPListaH){
  list<int> lista_argsPListaS;
  if (eat(COMA)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    int tipoTipo = Tipo();
    if (eat(ID)) {
      //printf("%s\n",tA -> valor);
      int linea = yylineno;
      if(!buscarIDTS(tA.valor)){
        list<int> arrgs;
        insertarSimbolo(tA.valor, dir, tipoTipo, 1, arrgs);//QUIZÁ NO ES 0
        dir += pilaTablaTipos.top().front().tam;
      } else {
        errorSemantico("El ID ya fue declarado:", linea, tA.valor);
      }      
      tA = yylex();
      lista_argsPListaH.push_front(tipoTipo);
      lista_argsPListaS = Lista_ArgsP(lista_argsPListaH);
    }
  } else{
    lista_argsPListaS = lista_argsPListaH;
  }
  return lista_argsPListaS;
}

void Instrucciones(){
  Sentencia();
  InstruccionesP();
}

void Sentencia(){
  if (eat(IF)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      if (eat(PIZQ)) {
          //printf("%s\n",tA -> valor);
          tA = yylex();
          Bool();
          if (eat(PDER)) {
              //printf("%s\n",tA -> valor);
              tA = yylex();
              Sentencia();
              Sent();
          }else{
            errorSintactico();
          }
      }else{
        errorSintactico();
      }
  } else if (eat(RETURN)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      Ret();
  } else if (eat(ID)) {
    Pierna_Izquierda_Exodia();
    if (eat(ASIG)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      Bool();
      if (eat(PCOMA)) {
        //printf("%s\n",tA -> valor);
        tA = yylex();
      }else{
        errorSintactico();
      }
    }else{
      errorSintactico();
    }
  } else if (eat(WHILE)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      if (eat(PIZQ)) {
        //printf("%s\n",tA -> valor);
        tA = yylex();
        Bool();
        if (eat(PDER)) {
          //printf("%s\n",tA -> valor);
          tA = yylex();
          Sentencia();
        }else{
          errorSintactico();
        }
      }else{
        errorSintactico();
      }
  } else if (eat(DO)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Sentencia();
    if (eat(WHILE)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      if (eat(PIZQ)) {
        //printf("%s\n",tA -> valor);
        tA = yylex();
        Bool();
        if (eat(PDER)) {
          //printf("%s\n",tA -> valor);
          tA = yylex();
          Sentencia();
        }else{
          errorSintactico();
        }
      }else{
        errorSintactico();
      }
    }else{
      errorSintactico();
    }
  } else if (eat(BREAK)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    if (eat(PCOMA)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
    }else{
      errorSintactico();
    }
  } else if (eat(LLAIZQ)) {
    Bloque();
  } else if (eat(SWITCH)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    if (eat(PDER)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      Bool();
      if (eat(PIZQ)) {
        //printf("%s\n",tA -> valor);
        tA = yylex();
        if (eat(LLAIZQ)) {
          //printf("%s\n",tA -> valor);
          tA = yylex();
          Casos();
          if (eat(LLADER)) {
            //printf("%s\n",tA -> valor);
            tA = yylex();
          }else{
            errorSintactico();
          }
        }else{
          errorSintactico();
        }
      }else{
        errorSintactico();
      }
    }else{
      errorSintactico();
    }
  } else if (eat(PRINT)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Exp();
    if (eat(PCOMA)) {
        //printf("%s\n",tA -> valor);
        tA = yylex();
    }else{
      errorSintactico();
    }
  } else if (eat(SCAN)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      Pierna_Izquierda_Exodia();
  }else{
    errorSintactico();
  }
}

void InstruccionesP(){
  if(eat(IF)||eat(RETURN)||eat(ID)||eat(WHILE)||eat(DO)||eat(BREAK)||eat(LLAIZQ)||eat(SWITCH)||eat(PRINT)||eat(SCAN)){
    Sentencia();
    InstruccionesP();
  }
}

void Sent(){
  if (eat(ELSE)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      Sentencia();
  }
}

void Ret(){
  if (eat(NEGA) || eat(MENOS) || eat(ID)) {
    Exp();
    if (eat(PCOMA)) {
        //printf("%s\n",tA -> valor);
        tA = yylex();
    }else{
      errorSintactico();
    }
  } else if (eat(PCOMA)) {
        //printf("%s\n",tA -> valor);
        tA = yylex();
  }else{
    errorSintactico();
  }
}

piernaIzquieraExodiaReturn Pierna_Izquierda_Exodia(){
  piernaIzquieraExodiaReturn piE;
  if (eat(ID)) {
    //printf("%s\n",tA -> valor);    
    string idLexVal = tA.valor;
    auxlinea = yylineno;
    auxID = tA.valor;
    tA = yylex();

    pttReturn aux = Ptt(idLexVal);

    piE.dir = aux.dir;
    piE.tipo = aux.tipo;
    piE.id = idLexVal;
    piE.arreglo = aux.arreglo;

  }else{
    errorSintactico();
  }
  return piE;
}

boolReturn Bool(){
  boolReturn bul;  
  Comb();
  BoolP();
  bul.tipo = 1;
  return bul;/////////////////ARREGLAR BOOL!
}

void Casos(){
  if (eat(CASE)) {
      Caso();
      Casos();
  } else if (eat(DEFAULT)) {
      Predeterminado();
  }
}

expReturn Exp(){
  expReturn exp;
  if(eat(NEGA)||eat(MENOS)||eat(ID)||eat(PIZQ)||eat(NUM)||eat(STR)||eat(TRUE)||eat(FALSE)){
    termReturn term = Term();
    exReturn ex = Ex(term.tipo, term.dir);
    exp.tipo = term.tipo;
    exp.dir = term.dir;
    //printf(" EXP: %i\n", exp.tipo);
  } else {
    errorSintactico();
  }
  return exp;
}

void Caso(){
  if (eat(CASE)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    if (eat(NUM)) {
        //printf("%s\n",tA -> valor);
        tA = yylex();
      if (eat(DOSPUNTOS)) {
        //printf("%s\n",tA -> valor);
        tA = yylex();
        Instrucciones();
      }else{
        errorSintactico();
      }
    }else{
      errorSintactico();
    }
  }else{
    errorSintactico();
  }
}

void Predeterminado(){
  if (eat(DEFAULT)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    if (eat(PCOMA)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      Instrucciones();
    }else{
      errorSintactico();
    }
  }else{
    errorSintactico();
  }
}

pttReturn Ptt(string pttBase){
  pttReturn ptt;
  if (eat(CIZQ)) {
    localizationReturn aux = Localization(pttBase);
    ptt.tipo = aux.tipo;
    ptt.dir = aux.dir;
    ptt.arreglo = 1;
  } else {
    if(buscarIDTS(pttBase)){
      ptt.tipo = getTipoTS(pttBase);
      ptt.dir = pttBase;
      ptt.arreglo = -1;
    } else{
      errorSemantico("El id no esta declarado: ", auxlinea, pttBase);
    }

  }
  return ptt;
}

localizationReturn Localization(string localizationBase){
  localizationReturn localization;
  if (eat(CIZQ)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    boolReturn bul = Bool();
    int boolTipo = bul.tipo;
    if (eat(CDER)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      localPReturn localP = LocalP(localizationBase, -1, "");
      if(buscarIDTS(localizationBase)){
        if(boolTipo == 1){//bool.tipo = int
          int tipoTemp = getTipoTS(localizationBase);
          if(getNombre(tipoTemp, "ARRAY")){
            localP.tipo = pilaTablaTipos.top().front().tipoBase;
            localP.dir = nuevaTemporal();            
            localP.tam = getTamTT(tipoTemp);
            generarCodigo(localP.dir, "=", "bool.dir *", to_string(localP.tam));
            localization.dir = localP.dir;
            localization.tipo = localP.tipo;
          } else {
            errorSemantico("El identificador no es un arreglo: ", auxlinea, auxID);
          }
        } else {
         errorSemantico("El indice del arregloo debe ser entero: ", auxlinea, auxID);
        }
      } else {
        errorSemantico("El id no está declarado: ", auxlinea, auxID);
      }
    }else{
      errorSintactico();
    }
  }else{
    errorSintactico();
  }
  return localization;
}

combReturn Comb(){
  combReturn comb;
  if(eat(NEGA)||eat(MENOS)||eat(ID)||eat(PIZQ)||eat(NUM)||eat(STR)||eat(TRUE)||eat(FALSE)){
    string iglVddr = nuevoIndice();
    string iglFls = nuevoIndice();
    igualdadReturn igualdad = Igualdad(iglVddr, iglFls);

    combPReturn combPP;
    combPP.tipo = igualdad.tipo;
    combPP.dir = igualdad.dir;
    list<string> listaIn;
    listaIn.push_front(igualdad.verdadero);
    combPP.listaIndices = listaIn;

    combPReturn combp = CombP(combPP);
    comb.tipo = combp.tipo;
    comb.dir = combp.dir;
    generarCodigo(igualdad.verdadero, "", "", "");
  } else {
    errorSintactico();
  }
  return comb;
}

void BoolP(){
  if (eat(OR)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Comb();
    BoolP();
  }
}

igualdadReturn Igualdad(string igVddr, string igFls){
  igualdadReturn igualdad;
  if(eat(NEGA)||eat(MENOS)||eat(ID)||eat(PIZQ)||eat(NUM)||eat(STR)||eat(TRUE)||eat(FALSE)){
    string relVddr = igVddr;
    string relFls = igFls;
    relReturn rel = Rel(relVddr, relFls);
    iguPReturn igup = IguP(relVddr, relFls, rel.tipo, rel.dir);
    igualdad.tipo = igup.tipo;
    igualdad.dir = igup.dir;
  } else {
    errorSintactico();
  }
  return igualdad;
}

relReturn Rel(string relVddr, string relFls){
  relReturn rel;
  if(eat(NEGA)||eat(MENOS)||eat(ID)||eat(PIZQ)||eat(NUM)||eat(STR)||eat(TRUE)||eat(FALSE)){
    string vddr = relVddr;
    string fls = relFls;
    expReturn exp = Exp();
    xpReturn xp = Xp(vddr, fls, exp.tipo);
    rel.tipo = xp.tipo;
    //printf("REL: %i\n", rel.tipo);
    rel.dir = xp.dir;
  } else {
    errorSintactico();
  }
  return rel;
}

iguPReturn IguP(string relVddr, string relFls, int tipoH, string direc){
  iguPReturn igup;
  if (eat(IGUAL)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    relReturn rel = Rel(relVddr, relFls);
    igup.verdadero = relVddr;
    igup.falso = relFls;
    if(equivalentes(tipoH, rel.tipo)){
      igup.dir = nuevaTemporal();
      int tipoTemp = max(tipoH, rel.tipo);
      //int d1;
      //int d2;
      generarCodigo(igup.dir, "=", "==", igup.dir);
      generarCodigo("if", direc, "goto", rel.verdadero);
      generarCodigo("goto", "", "", rel.falso);
    } else {
      errorSemantico("Tipos incompatibles: ", auxlinea, auxID);
    }
    igup = IguP(igup.verdadero, igup.falso, tipoH, igup.dir);
  } else if (eat(DIFF)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    relReturn rel = Rel(relVddr, relFls);
    igup.verdadero = relVddr;
    igup.falso = relFls;
    if(equivalentes(tipoH, rel.tipo)){      
      igup.dir = nuevaTemporal();
      int tipoTemp = max(tipoH, rel.tipo);
      //int d1;
      //int d2;      
      generarCodigo(igup.dir, "=", "!=", igup.dir);
      generarCodigo("if", direc, "goto", rel.verdadero);
      generarCodigo("goto", "", "", rel.falso);
    } else {
      errorSemantico("Tipos incompatibles: ", auxlinea, auxID);
    }    
    igup = IguP(igup.verdadero, igup.falso, tipoH, igup.dir);
  } else {
    igup.tipo = tipoH;
    igup.dir = direc;
    igup.verdadero = relVddr;
    igup.falso = relFls;
  }
  return igup;
}

combPReturn CombP(combPReturn combPP){
  combPReturn combp;
  if (eat(AND)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    string iglVddr = nuevoIndice();
    string iglFls = nuevoIndice();
    igualdadReturn igualdad = Igualdad(iglVddr, iglFls);
    combPReturn combp1;
    if(combPP.tipo, igualdad.tipo){
      combp1.tipo = combPP.tipo;
      combp1.dir = combPP.dir;
      combp1.listaIndices = combPP.listaIndices;
      combp1.listaIndices.push_front(igualdad.verdadero);
      generarCodigo(igualdad.verdadero,"","","");
    } else {
      errorSemantico("Tipos incompatibles: ", auxlinea, auxID);
    }
    combPReturn combpN = CombP(combp1);
    combp.tipo = combpN.tipo;
  } else {
    //REEMPLAZARINDICES();
    combp.tipo = 1;
  }
  return combp;
}

xpReturn Xp(string v, string f, int tipo){
  xpReturn xp;
  if (eat(MENOR)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    expReturn exp = Exp();
    if(equivalentes(tipo, exp.tipo)){
      xp.tipo = max(tipo, exp.tipo);
      xp.dir = nuevaTemporal();
      int d1 = max(xp.tipo, exp.tipo);
      int d2 = max(xp.tipo, exp.tipo);
      generarCodigo(xp.dir+"=", xp.dir, "<", exp.dir);
      generarCodigo("if", xp.dir, "goto", xp.verdadero);
      generarCodigo("goto", "", "", xp.falso);
    } else {
      errorSemantico("Tipos no compatibles: ", auxlinea, auxID);
    }
  } else if (eat(MENOREQ)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    expReturn exp = Exp();
    if(equivalentes(tipo, exp.tipo)){
      xp.tipo = max(tipo, exp.tipo);
      xp.dir = nuevaTemporal();
      int d1 = max(xp.tipo, exp.tipo);
      int d2 = max(xp.tipo, exp.tipo);
      generarCodigo(xp.dir+"=", xp.dir, "<=", exp.dir);
      generarCodigo("if", xp.dir, "goto", xp.verdadero);
      generarCodigo("goto", "", "", xp.falso);
    } else {
      errorSemantico("Tipos no compatibles: ", auxlinea, auxID);
    }
  } else if (eat(MAYOREQ)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    expReturn exp = Exp();
    if(equivalentes(tipo, exp.tipo)){
      xp.tipo = max(tipo, exp.tipo);
      xp.dir = nuevaTemporal();
      int d1 = max(xp.tipo, exp.tipo);
      int d2 = max(xp.tipo, exp.tipo);
      generarCodigo(xp.dir+"=", xp.dir, ">=", exp.dir);
      generarCodigo("if", xp.dir, "goto", xp.verdadero);
      generarCodigo("goto", "", "", xp.falso);
    } else {
      errorSemantico("Tipos no compatibles: ", auxlinea, auxID);
    }
  } else if (eat(MAYOR)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    expReturn exp = Exp();
    if(equivalentes(tipo, exp.tipo)){
      xp.tipo = max(tipo, exp.tipo);
      xp.dir = nuevaTemporal();
      int d1 = max(xp.tipo, exp.tipo);
      int d2 = max(xp.tipo, exp.tipo);
      generarCodigo(xp.dir+"=", xp.dir, ">", exp.dir);
      generarCodigo("if", xp.dir, "goto", xp.verdadero);
      generarCodigo("goto", "", "", xp.falso);
    } else {
      errorSemantico("Tipos no compatibles: ", auxlinea, auxID);
    }
  } else {
    xp.tipo = tipo;
    xp.verdadero = v;
    xp.falso = f;
  }
  return xp;
}

termReturn Term(){
  termReturn term;
  if(eat(NEGA)||eat(MENOS)||eat(ID)||eat(PIZQ)||eat(NUM)||eat(STR)||eat(TRUE)||eat(FALSE)){
    unarioReturn unario = Unario();
    terPReturn terp = TerP(unario.tipo, unario.dir);
    term.tipo = terp.tipo;
    term.dir = terp.dir;
    //printf(" TERM: %i\n", term.tipo);
  } else {
    errorSintactico();
  }
  return term;
}

exReturn Ex(int tipe, string dire){
  exReturn ex;
  if (eat(MAS)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    auxlinea = yylineno;
    termReturn term = Term();
    if(equivalentes(tipe, term.tipo)){
      ex.tipo = max(tipe, term.tipo);
      ex.dir = nuevaTemporal();
      int d1 = max(tipe, term.tipo);
      int d2 = max(ex.tipo, term.tipo);
      generarCodigo(ex.dir + "=", to_string(d1), "+", to_string(d2));
    } else {
      errorSemantico("Tipos no compatibles: ", auxlinea, auxID);
    }
    Ex(ex.tipo, ex.dir);
  } else if (eat(MENOS)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    auxlinea = yylineno;
    termReturn term = Term();
    if(equivalentes(tipe, term.tipo)){
      ex.tipo = max(tipe, term.tipo);
      ex.dir = nuevaTemporal();
      int d1 = max(tipe, term.tipo);
      int d2 = max(ex.tipo, term.tipo);
      generarCodigo(ex.dir + "=", to_string(d1), "-", to_string(d2));
    } else {
      errorSemantico("Tipos no compatibles: ", auxlinea, auxID);
    }
    Ex(ex.tipo, ex.dir);
  } else {
    ex.tipo = tipe;
    ex.dir = dire;
  }
  return ex;
}

unarioReturn Unario(){
  unarioReturn unario;
  if (eat(NEGA)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    unarioReturn unaAux = Unario();
    unario.dir = nuevaTemporal();
    unario.tipo = unaAux.tipo;
    generarCodigo(unario.dir, "=", "!", unaAux.dir);
  } else if (eat(MENOS)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    unarioReturn unaAux = Unario();
    unario.dir = nuevaTemporal();
    unario.tipo = unaAux.tipo;
    generarCodigo(unario.dir, "=", "-", unaAux.dir);
  } else if (eat(ID) || eat(NUM) || eat(PIZQ) || eat(STR) || eat(TRUE) || eat(FALSE)) {
    factorReturn factor = Factor();
    unario.tipo = factor.tipo;
    unario.dir = factor.dir;
    //printf(" UNARIO: %i\n", unario.tipo);
  }else{
    errorSintactico();
  }
  return unario;
}

terPReturn TerP(int tipe, string dire){
  terPReturn terp;
  if (eat(MULT)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    auxlinea = yylineno;
    unarioReturn unario = Unario();
    if(equivalentes(tipe, unario.tipo)){
      terp.tipo = max(tipe, unario.tipo);
      terp.dir = nuevaTemporal();
      int d1 = max(tipe, unario.tipo);
      int d2 = max(terp.tipo, unario.tipo);
      generarCodigo(to_string(d1) + "=", to_string(terp.tipo), "*", to_string(d2));
    } else {
      errorSemantico("Tipos no compatibles: ", auxlinea, auxID);
    }
    TerP(terp.tipo, terp.dir);
  } else if (eat(DIV)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    auxlinea = yylineno;
    unarioReturn unario = Unario();
    if(equivalentes(tipe, unario.tipo)){
      terp.tipo = max(tipe, unario.tipo);
      terp.dir = nuevaTemporal();
      int d1 = max(tipe, unario.tipo);
      int d2 = max(terp.tipo, unario.tipo);
      generarCodigo(to_string(d1) + "=", to_string(terp.tipo), "/", to_string(d2));
    } else {
      errorSemantico("Tipos no compatibles: ", auxlinea, auxID);
    }
    TerP(terp.tipo, terp.dir);
  } else if (eat(MOD)) {
    tA = yylex();
    auxlinea = yylineno;
    unarioReturn unario = Unario();
    if(equivalentes(tipe, unario.tipo)){
      terp.tipo = max(tipe, unario.tipo);
      terp.dir = nuevaTemporal();
      int d1 = max(tipe, unario.tipo);
      int d2 = max(terp.tipo, unario.tipo);
      generarCodigo(to_string(d1) + "=", to_string(terp.tipo), "%", to_string(d2));
    } else {
      errorSemantico("Tipos no compatibles: ", auxlinea, auxID);
    }
    TerP(terp.tipo, terp.dir);
  } else {
    terp.tipo = tipe;
    terp.dir = dire;
  }
  return terp;
}

factorReturn Factor(){
  factorReturn factor;
  if (eat(ID)) {
    //printf("%s\n",tA -> valor);    
    string idLexVal = tA.valor;
    auxlinea = yylineno;
    auxID = tA.valor;
    tA = yylex();    
    faaccReturn faacc = Faacc(idLexVal);
    factor.dir = faacc.dir;
    factor.tipo = faacc.tipo;
    //printf(" FACTOR: %i\n",factor.tipo);

  }else if (eat(PIZQ)) {
    //printf("%s\n",tA -> valor);
    auxID = tA.valor;
    tA = yylex();
    boolReturn bul = Bool();
    if (eat(PDER)) {
      //printf("%s\n",tA -> valor);
      factor.tipo = bul.tipo;
      factor.dir = bul.dir;
      tA = yylex();
    }else{
      errorSintactico();
    }
  } else if (eat(NUM)) {
    //printf("%s\n",tA -> valor);
    factor.tipo = tA.tipo;
    factor.dir = atoi(tA.valor.c_str());
    auxID = tA.valor;
    tA = yylex();
  } else if (eat(TRUE)) {
    //printf("%s\n",tA -> valor);
    auxID = tA.valor;
    factor.dir = "TRUE";
    factor.tipo = 1;
    tA = yylex();
  } else if (eat(FALSE)) {
    //printf("%s\n",tA -> valor);
    factor.dir = "FALSE";
    factor.tipo = 1;    
    tA = yylex();
  } else if (eat(STR)) {
    //printf("FACTOR: %s\n",tA.valor);
    auxID = tA.valor;
    tablaCadenas.push(tA.valor);
    factor.dir = tablaCadenas.top();
    factor.tipo = 6; //CADENA
    tA = yylex();
  }else{
    errorSintactico();
  }
  return factor;
}

faaccReturn Faacc(string faaccBase){
  faaccReturn faacc;
  if (eat(CIZQ)) {    
    localizationReturn localization = Localization(faaccBase);
    faacc.dir = nuevaTemporal();
    faacc.tipo = localization.tipo;
    generarCodigo(faacc.dir, "=", faaccBase, localization.dir);
  }else if (eat(PIZQ)){
    //printf("%s\n",tA -> valor);
    tA = yylex();
    auxlinea = yylineno;
    list<int> parametrosLista = Parametros();
    if (eat(PDER)) {
      //printf("%s\n",tA -> valor);
      if(buscarIDTSFondo(faaccBase)){
        if(getVarPTSFondo(faaccBase) == 2){
          list<int> args = getVarListPTSFondo(faaccBase);
          if(equivalenteListas(args, parametrosLista)){
            faacc.tipo = getTipoTS(faaccBase);
            faacc.dir = nuevaTemporal();
            generarCodigo(faacc.dir, "= call", faaccBase,to_string(parametrosLista.size()));
          } else {
            errorSemantico("El numero o tipo de parametros no coinciden:", auxlinea, auxID);
          }
        } else {
          errorSemantico("El id no es una funcion", auxlinea, auxID);
        }
      } else {
        errorSemantico("El id no está declarado: ", auxlinea, auxID);
      }
      tA = yylex();
    } else {
      errorSintactico();
    }
  } else {
    faacc.dir = faaccBase;
    faacc.tipo = getTipoTS(faaccBase);
    //printf(" FAACC: %i\n", faacc.tipo);
  }
  return faacc;
}

list<int> Parametros(){
  list<int> parametrosLista;
  if (eat(NEGA)||eat(MENOS)||eat(ID)||eat(PIZQ)||eat(NUM)||eat(STR)||eat(TRUE)||eat(FALSE)) {
    parametrosLista = Lista_Param();
  }
  return parametrosLista;
}

list<int> Lista_Param(){
  list<int> lista_param;
  boolReturn bul = Bool();
  list<int> nuevaLista;
  nuevaLista.push_front(bul.tipo);
  lista_param = ListP(nuevaLista);
  generarCodigo("PARAM", "", "", bul.dir);
  return lista_param;
}

list<int> ListP(list<int> listaH){
  list<int> listaS;
  if (eat(COMA)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    boolReturn bul = Bool();
    listaH.push_front(bul.tipo);
    listaS = ListP(listaH);
  } else {
    listaS = listaH;
  }
  return listaS;
}

localPReturn LocalP(string localPBase, int localPTipo, string direc){
  localPReturn localP;  
  if (eat(CIZQ)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    boolReturn bul = Bool();
    int boolTipo = bul.tipo;
    if (eat(CDER)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      localPReturn temp = LocalP(localPBase, localPTipo, direc);
      if(buscarIDTS(localPBase)){
        if(boolTipo == 1){//bool.tipo = int
          int tipoTemp = getTipoTS(localPBase);
          if(getNombre(tipoTemp, "ARRAY")){
            localP.tipo = pilaTablaTipos.top().front().tipoBase;
            localP.dir = nuevaTemporal();
            localP.tam = getTamTT(tipoTemp);
            generarCodigo(localP.dir, "*", to_string(localP.tam), localP.dir);
            localP.tipo = temp.tipo;
            localP.dir = temp.dir;
          } else {
            errorSemantico("El identificador no es un arreglo: ", auxlinea, auxID);
          }
        } else {
         errorSemantico("El indice del arreglo debe ser entero: ", auxlinea, auxID);
        }
      } else {
        errorSemantico("El id no está declarado: ", auxlinea, auxID);
      }
    }else{
      errorSintactico();
    }
  }
  return localP;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void errorSintactico() {
  printf("\n\n >Error Sintantico \n >Token inesperado: %s\n >En la linea: %i\n",tA.valor.c_str(), yylineno);
  exit(0);
}

void errorSemantico(string fail, int linea, string error){
  printf("\n\n >Error Semantico en la linea: %i\n >%s %s\n", linea, fail.c_str(), error.c_str());
  exit(0);
}

void construirTablaTipos(){
  struct TipTipe tipoV = tipoV.crea_tipo(0,"VOID",4,-1,-1);
  struct TipTipe tipoI = tipoV.crea_tipo(1,"INT",4,-1,-1);
  struct TipTipe tipoD = tipoV.crea_tipo(2,"DOUBLE",8,-1,-1);
  struct TipTipe tipoF = tipoV.crea_tipo(3,"FLOAT",4,-1,-1);
  struct TipTipe tipoC = tipoV.crea_tipo(4,"CHAR",4,-1,-1);
  tablaTipos.push_front(tipoV);
  tablaTipos.push_front(tipoI);
  tablaTipos.push_front(tipoD);
  tablaTipos.push_front(tipoF);
  tablaTipos.push_front(tipoC);
  //printf("A ver si jala: %s\n", tipoV.tipo.c_str());
}

void construirTablaSimbolos(){

}

int buscarIDTS(string id){
  int busca = 0;
  for(Simbolo s : pilaTablaSimbolos.top()){
    //printf("\nBUSCA: %s, %s\n", s.id.c_str(), id.c_str());
    if(strcmp(s.id.c_str(), id.c_str()) == 0){
      busca = 1;      
    }    
  }
  return busca;
}

int buscarIDTSFondo(string id){
  int busca = 0;
  list<Simbolo> aux = fondo(pilaTablaSimbolos);
  for(Simbolo s : aux){
    //printf("\nBUSCA: %s, %s\n", s.id.c_str(), id.c_str());
    if(strcmp(s.id.c_str(), id.c_str()) == 0){
      busca = 1;      
    }    
  }
  return busca;
}

void insertarTipoTop(TipTipe tipooo){  
  pilaTablaTipos.top().push_front(tipooo);
}

void insertarSimbolo(string id, int dir, int type, int var, list<int> args){
  Simbolo simb = Simbolo(id, dir, type, var, args);
  pilaTablaSimbolos.top().push_front(simb);
  //printf("\nINSERTAR SIMB: %s TAM: %i\n", id.c_str(), pilaTablaSimbolos.top().size());
}

int equivalentesLista(int tipo){
  int equi = 1;
  for(int i : listaRetorno){
    //printf("\nLISTA RETORNO: %i, %i\n", i, tipo);
    if(i != tipo){
      equi = 0;
    }
  }
  //printf("EQUIVALENTES LISTA\n");
  return equi;
}

void generarCodigo(string opcion, string arg1,  string arg2, string res){
  vector<string> lineaCodigo;
  lineaCodigo.push_back(opcion);
  lineaCodigo.push_back(arg1);
  lineaCodigo.push_back(arg2);
  lineaCodigo.push_back(res);
  codigo.push_front(lineaCodigo);
}

string nuevaEtiqueta(){
  iE++;
  return "L" + to_string(iE);
}

string nuevoIndice(){
  iI++;
  return "I" + to_string(iI);
}

string nuevaTemporal(){
  iT++;
  return "T" + to_string(iT);
}

int getTipoTS(string id){
  int tipo = -1;
  for(Simbolo s : pilaTablaSimbolos.top()){
    if(strcmp(s.id.c_str(), id.c_str()) == 0){
      tipo = s.type;    
    }
  }
  return tipo;
}

int getNombre(int tipoTemp, string strTipo){
  int tipo = 0;
  if(strcmp(pilaTablaTipos.top().front().tipo.c_str(), strTipo.c_str()) == 0){
    tipo = 1;
  }
  return tipo;
}

int getTamTT(int tipo){
  if(tipo == 0){
    return 4;
  } else if(tipo == 1){
    return 4;
  } else if(tipo == 2){
    return 8;
  } else if(tipo == 3){
    return 4;
  } else {
    return 1;
  }
}

list<Simbolo> fondo(stack<list<Simbolo>> ts){
  stack<list<Simbolo>> duracel = ts;
  stack<list<Simbolo>> energizee;
  while(!duracel.empty()){
    list<Simbolo> aux = duracel.top();
    energizee.push(aux);
    duracel.pop();
  }
  return energizee.top();
}

int getVarPTSFondo(string id){
  int var = -1;
  list<Simbolo> aux = fondo(pilaTablaSimbolos);
  for(Simbolo s : aux){
    //printf("\nBUSCA: %s, %s\n", s.id.c_str(), id.c_str());
    if(strcmp(s.id.c_str(), id.c_str()) == 0){
      var = s.var;
      break;
    }    
  }
  return var;
}

list<int> getVarListPTSFondo(string id){
  list<int> args;
  list<Simbolo> aux = fondo(pilaTablaSimbolos);
  for(Simbolo s : aux){
    //printf("\nBUSCA: %s, %s\n", s.id.c_str(), id.c_str());
    if(strcmp(s.id.c_str(), id.c_str()) == 0){
      args = s.args;
      break;
    }    
  }
  return args;
}

int equivalenteListas(list<int> uno, list<int> dos){
  int compare = 0;
  if(uno.size() == dos.size()){
    if(uno == dos){
      compare = 1;
    }
  }
  return compare;
}

int equivalentes(int tipoH, int unarioH){
  //printf("\n EQUIVALENTES: %i, %i\n", tipoH, unarioH);
  if(tipoH == unarioH){
    return 1;
  } else {
    return 0;
  }
}

//int main(){return 0;}
