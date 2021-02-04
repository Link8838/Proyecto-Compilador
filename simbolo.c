#include "simbolo.h"

simbolo *crea_simbolo(char *id, int dir, int type, int var, Lista *args) {
  simbolo *t_out = malloc(sizeof(token));
  t_out -> dir = dir;
  t_out -> id = malloc(sizeof(char));
  t_out -> args = malloc(sizeof(Lista*));
  t_out -> args = args;
  strcpy(t_out -> id, id);
  t_out -> tipo = type;
  t_out -> var = var;
  return t_out;
}
