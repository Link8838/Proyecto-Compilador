/**
 * Práctica 7: Compiladores
 * Figueroa Sandoval Gerardo Emiliano
 * Hernández Ferreiro Enrique Ehecatl
 * López Soto Ramses Antonio
 * Quintero Villeda Erik
*/

#include "parser.h"
#include "tokens.h"
#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Programar a parte las funciones auxiliares

extern token *yylex();
extern int yylineno;
token *tA;

/* Tabla de símbolos */
Lista *tablaSimbolos;
/* Tabla de tipos */
Lista *tablaTipos;

Stack *piladeTipos;

Stack *piladeSimbolos;

int eat(int clase){
  int f = 0;
  if (equals(tA, clase)) {
    f = 1;
  }
  //printf("\nEAT: %i\n",f);
  return f;
}

void parse(token *tk) {
  tA = tk;
  piladeTipos = createStack();

  piladeSimbolos = createStack();
  /* Tabla de símbolos */
  tablaSimbolos = lista_nueva();
  /* Tabla de tipos */
  tablaTipos = lista_nueva();

  Programa();

}

void Programa(){

  push(piladeTipos,tablaTipos);
  push(piladeSimbolos,tablaSimbolos);
  dir = 0;
  Declaraciones();
  //printf("**VAMONOS**%s\n");
  Funciones();
}

void Declaraciones(){
  //printf("Aguacate %s\n",tA -> valor);
  if(eat(FLOAT) || eat(CHAR) || eat(DOUBLE) || eat(VOID) || eat(INT)){
    //printf("**DECLARACIONES**%s\n");
    Tipo();
    Lista_Var();
    if (eat(PCOMA)) {
      //printf("Aguacate %s\n",tA -> valor);
      tA = yylex();
      Declaraciones();
    }else{
      error();
    }
  }
}

void Tipo(){
  Basico();
  Compuesto();
}

void Lista_Var(){
  if (eat(ID)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Lop();
  }else{
    error();
  }
}

int Basico(){
  if (eat(INT)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
  } else if (eat(FLOAT)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
  } else if (eat(CHAR)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
  } else if (eat(DOUBLE)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
  } else if (eat(VOID)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
  } else {
    error();
  }
}

void Compuesto(){
  if (eat(CIZQ)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      if (eat(NUM)) {
        //printf("%s\n",tA -> valor);
        tA = yylex();
        if (eat(CDER)) {
          //printf("%s\n",tA -> valor);
          tA = yylex();
          Compuesto();
      }else{
        error();
      }
    }else {
      error();
    }
  }
}

void Lop(){
  if (eat(COMA)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      if (eat(ID)) {
          //printf("%s\n",tA -> valor);
          tA = yylex();
          Lop();
      }
  }
}

void Funciones(){
  //printf("**FUNCIONES!**%s\n");
  if (eat(FUNC)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      Tipo();
      if (eat(ID)) {
          //printf("%s\n",tA -> valor);
          tA = yylex();
          if (eat(PIZQ)) {
              //printf("%s\n",tA -> valor);
              tA = yylex();
              Argumentos();
              if (eat(PDER)) {
                  //printf("%s\n",tA -> valor);
                  tA = yylex();
                  Bloque();
                  Funciones();
              }
          }
      }
  } else if(eat(FIN)){
    printf("**CADENA ACEPTADA**\n");
  }
}

void Argumentos(){
  if (eat(FLOAT) || eat(CHAR) || eat(DOUBLE) || eat(VOID) || eat(INT)) {
    Lista_Args();
  }
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
      error();
    }
  }else{
    error();
  }
}

void Lista_Args(){
  Tipo();
  if (eat(ID)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      Lista_ArgsP();
  }else{
    error();
  }
}

void Lista_ArgsP(){
  if (eat(COMA)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      Tipo();
      if (eat(ID)) {
          //printf("%s\n",tA -> valor);
          tA = yylex();
          Lista_ArgsP();
      }
  }
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
            error();
          }
      }else{
        error();
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
        error();
      }
    }else{
      error();
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
          error();
        }
      }else{
        error();
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
          error();
        }
      }else{
        error();
      }
    }else{
      error();
    }
  } else if (eat(BREAK)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    if (eat(PCOMA)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
    }else{
      error();
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
            error();
          }
        }else{
          error();
        }
      }else{
        error();
      }
    }else{
      error();
    }
  } else if (eat(PRINT)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Exp();
    if (eat(PCOMA)) {
        //printf("%s\n",tA -> valor);
        tA = yylex();
    }else{
      error();
    }
  } else if (eat(SCAN)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      Pierna_Izquierda_Exodia();
  }else{
    error();
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
      error();
    }
  } else if (eat(PCOMA)) {
        //printf("%s\n",tA -> valor);
        tA = yylex();
  }else{
    error();
  }
}

void Pierna_Izquierda_Exodia(){
  if (eat(ID)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      Ptt();
  }else{
    error();
  }
}

void Bool(){
  Comb();
  BoolP();
}

void Casos(){
  if (eat(CASE)) {
      Caso();
      Casos();
  } else if (eat(DEFAULT)) {
      Predeterminado();
  }
}

void Exp(){
  Term();
  Exx();
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
        error();
      }
    }else{
      error();
    }
  }else{
    error();
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
      error();
    }
  }else{
    error();
  }
}

void Ptt(){
  if (eat(CIZQ)) {
    Localization();
  }
}

void Localization(){
  if (eat(CIZQ)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Bool();
    if (eat(CDER)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      LocalP();
    }else{
      error();
    }
  }else{
    error();
  }
}

void Comb(){
  Igualdad();
  CombP();
}

void BoolP(){
  if (eat(OR)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Comb();
    BoolP();
  }
}

void Igualdad(){
  Rel();
  IgualdadP();
}

void Rel(){
  Exp();
  Xp();
}

void IgualdadP(){
  if (eat(IGUAL)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Rel();
    IgualdadP();
  } else if (eat(DIFF)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Rel();
    IgualdadP();
  }
}

void CombP(){
  if (eat(AND)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Igualdad();
    CombP();
  }
}

void Xp(){
  if (eat(MENOR)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Exp();
  } else if (eat(MENOREQ)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Exp();
  } else if (eat(MAYOREQ)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Exp();
  } else if (eat(MAYOR)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Exp();
  }
}

void Term(){
  Unario();
  Terrr();
}

void Exx(){
  if (eat(MAS)||eat(MENOS)) {
    ExP();
    Exx();
  }
}

void ExP(){
  if (eat(MAS)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Term();
  } else if (eat(MENOS)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Term();
  }else{
    error();
  }
}

void Unario(){
  if (eat(NEGA)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Unario();
  } else if (eat(MENOS)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Unario();
  } else if (eat(ID) || eat(NUM) || eat(PIZQ) || eat(STR) || eat(TRUE) || eat(FALSE)) {
    Factor();
  }else{
    error();
  }
}

void Terrr(){
  if (eat(MULT)||eat(DIV)||eat(MOD)) {
    TerP();
    Terrr();
  }
}

void TerP(){
  if (eat(MULT)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Unario();
  } else if (eat(DIV)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Unario();
  } else if (eat(MOD)) {
    Unario();
  }else{
    error();
  }
}

void Factor(){
  if (eat(ID)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Faacc();
  }else if (eat(PIZQ)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Bool();
    if (eat(PDER)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
    }else{
      error();
    }
  } else if (eat(NUM)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
  } else if (eat(TRUE)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
  } else if (eat(FALSE)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
  } else if (eat(STR)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
  }else{
    error();
  }
}

void Faacc(){
  if (eat(CIZQ)) {
    Localization();
  }else if (eat(PIZQ)) {
        //printf("%s\n",tA -> valor);
        tA = yylex();
        Parametros();
        if (eat(PDER)) {
          //printf("%s\n",tA -> valor);
          tA = yylex();
        }else{
          error();
        }
      }
    }

void Parametros(){
  if (eat(NEGA)||eat(MENOS)||eat(ID)||eat(PIZQ)||eat(NUM)||eat(STR)||eat(TRUE)||eat(FALSE)) {
    Lista_Param();
  }
}

void Lista_Param(){
  Bool();
  ListP();
}

void ListP(){
  if (eat(COMA)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Bool();
    ListP();
  }
}

void LocalP(){
  if (eat(CIZQ)) {
    //printf("%s\n",tA -> valor);
    tA = yylex();
    Bool();
    if (eat(CDER)) {
      //printf("%s\n",tA -> valor);
      tA = yylex();
      LocalP();
    }else{
      error();
    }
  }
}

void error() {
  printf("\n Error :,c \n Token inesperado: %s\n En la linea: %i\n",tA -> valor, yylineno);
  exit(0);
}

//int main(){return 0;}
