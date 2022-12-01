#ifndef pila_h
#define pila_h

#include <stdio.h>

// Vamos a implementar la pila como si fuera una lista enlazada

typedef char* URL;

typedef struct nodo {
    URL url;
    struct nodo* siguiente;
} Nodo;

typedef struct pila {
    Nodo* cima;
    int longitud;
} Pila;

Nodo* CrearNodo(URL url);

void DestruirNodo(Nodo* nodo);

Pila* CrearPila();

void DestruirPila(Pila* pila);

void Apilar(Pila* pila, URL url);

void Desapilar(Pila* pila);

URL Cima(Pila* pila);

int Longitud(Pila* pila);

int EstaVacia(Pila* pila);

#endif