#include "tipo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

tipo *crea_entrada_tipo(int id, char *tipo, int tam, int elem, int tipoBase) {
    struct tipo *tipo_out;
    tipo_out = malloc(sizeof(struct tipo));   
     
    tipo_out -> id = id;
    tipo_out -> tipo = malloc(sizeof(char));
    strcpy(tipo_out -> tipo, tipo);
    tipo_out -> tam = tam;
    tipo_out -> elem = elem;
    tipo_out -> tipoBase;
    return tipo_out;
}
