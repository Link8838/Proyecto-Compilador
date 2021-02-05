/**
 * Práctica 7: Compiladores
 * Figueroa Sandoval Gerardo Emiliano
 * Hernández Ferreiro Enrique Ehecatl
 * López Soto Ramses Antonio
 * Quintero Villeda Erik
*/

#include <assert.h>
#include <stdlib.h>
#include "lista.h"

struct _Lista {
        NodoLista* cabeza;
        NodoLista* rabo;
        int  longitud;
};

struct _NodoLista {
        void* elemento;
        NodoLista* anterior;
        NodoLista* siguiente;
};

static NodoLista* nodo_lista_nuevo(void* elemento) {
        struct _NodoLista *nuevo_nodo = (struct _NodoLista *) malloc(sizeof(struct _NodoLista));
        nuevo_nodo -> elemento = elemento;
        return nuevo_nodo;
}

Lista* lista_nueva(void) {
        struct _Lista *lista_nueva = (struct _Lista *) malloc(sizeof(struct _Lista));
        return lista_nueva;
}

NodoLista* lista_cabeza(Lista* lista) {
        assert(lista != NULL);
        return lista -> cabeza;
}

NodoLista* lista_rabo(Lista* lista) {
        assert(lista != NULL);
        return lista -> rabo;
}

int lista_longitud(Lista* lista) {
        assert(lista != NULL);
        return lista -> longitud;
}

void lista_agrega_inicio(Lista* lista, void*  elemento) {
        assert(lista != NULL && elemento != NULL);
        NodoLista* nodo = nodo_lista_nuevo(elemento);
        lista -> longitud++;
        if (lista -> cabeza == NULL) {
                lista -> cabeza = lista -> rabo = nodo;
        } else {
                (lista -> cabeza) -> anterior = nodo;
                nodo -> siguiente = lista -> cabeza;
                lista -> cabeza = nodo;
        }
}

void lista_agrega_final(Lista* lista, void*  elemento) {
        assert(lista != NULL && elemento != NULL);
        NodoLista* nodo = nodo_lista_nuevo(elemento);
        lista->longitud++;
        if (lista -> rabo == NULL) {
                lista -> rabo = lista -> cabeza = nodo;
        } else {
                (lista -> rabo) -> siguiente = nodo;
                nodo -> anterior = lista -> rabo;
                lista -> rabo = nodo;
        }
}



static void l_elimina_nodo(Lista* lista, NodoLista* nodo) {
        lista -> longitud--;
        if (lista -> cabeza == nodo && lista -> rabo == nodo) {
                lista -> cabeza = lista -> rabo = NULL;
        } else if (nodo == lista -> cabeza) {
                lista -> cabeza = lista ->cabeza->siguiente;
                (lista -> cabeza) -> anterior = NULL;
        } else if (nodo == lista -> rabo) {
                lista -> rabo = (lista -> rabo) -> anterior;
                (lista -> rabo) -> siguiente = NULL;
        } else {
                (nodo -> anterior) -> siguiente = nodo -> siguiente;
                (nodo -> siguiente) -> anterior = nodo -> anterior;
        }
        free(nodo);
}


void* lista_elimina_primero(Lista* lista) {
        assert(lista != NULL && lista -> cabeza != NULL);
        void* r = (lista -> cabeza) -> elemento;
        l_elimina_nodo(lista, lista -> cabeza);
        return r;
}

void* lista_elimina_ultimo(Lista* lista) {
        assert(lista != NULL && lista -> rabo != NULL);
        void* r = (lista -> rabo) -> elemento;
        l_elimina_nodo(lista, lista -> rabo);
        return r;
}

void lista_elimina_nodo(Lista* lista, NodoLista* nodo) {
        assert(lista != NULL && nodo != NULL);
        l_elimina_nodo(lista, nodo);
}

int lista_busca(Lista* lista, void* elemento) {
        assert(lista != NULL);
        return busca_nodo(lista -> cabeza, elemento);
}

int busca_nodo(NodoLista* nodo, void* elemento) {
        assert(elemento != NULL);
        if (nodo == NULL ){
        	return 0;
		}else if (nodo -> elemento == elemento) {
                return 1;
        } else {
                return busca_nodo(nodo -> siguiente, elemento);
        }
}

NodoLista* lista_dame(Lista* lista, int indice) {
        assert(lista != NULL && indice >= 0 && indice < lista -> longitud);
        NodoLista* tmp = lista -> cabeza;
        int c = 0;
        while (tmp != NULL) {
                if (c++ == indice)
                        return tmp;
                tmp = tmp -> siguiente;
        }
        return NULL;
}

Lista* lista_reversa(Lista* lista) {
        assert(lista != NULL);
        Lista* reversa = lista_nueva();
        NodoLista* tmp = lista -> cabeza;
        while (tmp != NULL) {
                lista_agrega_inicio(reversa, tmp -> elemento);
                tmp = tmp -> siguiente;
        }
        return reversa;
}



static void lista_libera_aux(Lista* lista, bool todo) {
        assert(lista != NULL);
        NodoLista* tmp = lista -> cabeza;
        while (tmp != NULL) {
                NodoLista* nodo = tmp;
                tmp = tmp -> siguiente;
                if (todo)
                        free(nodo -> elemento);
                free(nodo);
        }
}

void lista_libera(Lista* lista) {
        assert(lista != NULL);
        lista_libera_aux(lista, false);
}

void lista_libera_todo(Lista* lista) {
        assert(lista != NULL);
        lista_libera_aux(lista, true);
}

void* nodo_lista_elemento(NodoLista* nodo) {
        assert(nodo != NULL);
        return nodo -> elemento;
}

NodoLista* nodo_lista_anterior(NodoLista* nodo) {
        assert(nodo != NULL);
        return nodo -> anterior;
}

NodoLista* nodo_lista_siguiente(NodoLista* nodo) {
        assert(nodo != NULL);
        return nodo -> siguiente;
}
