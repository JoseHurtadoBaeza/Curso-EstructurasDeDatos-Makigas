#ifndef lista_h
#define lista_h

#include <stdio.h>
#include <libro.h>

typedef struct Nodo {
    Libro libro;
    struct Nodo* siguiente;
} Nodo;

typedef struct Lista {
    Nodo* cabeza;
} Lista;

#endif