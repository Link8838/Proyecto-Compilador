#include "tipo.h"

tipo *crea_entrada_tipo(int id, char *tipo, int tam, int elem, int tipoBase) {
  tipo *t_out = malloc(sizeof(tipo));
  t_out -> id = id;
  t_out -> tipo = malloc(sizeof(char));
  strcpy(t_out -> tipo, tipo);
  t_out -> tam = tam;
  t_out -> elem = elem;
  t_out -> tipoBase;
  return t_out;
}
