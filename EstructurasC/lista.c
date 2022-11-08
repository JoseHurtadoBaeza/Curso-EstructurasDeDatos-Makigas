#include "lista.h"
#include <stdlib.h>
#include <string.h>

Nodo* CrearNodo(Libro* libro){
    
    Nodo* nodo = (Nodo *) malloc(sizeof (Nodo));
    
    strncpy(nodo->libro.titulo, libro->titulo, 50);
    strncpy(nodo->libro.autor, libro->autor, 50);
    strncpy(nodo->libro.isbn, libro->isbn, 50);
    
    nodo->siguiente = NULL;
    
    return nodo;

}

/* Función para destruir un nodo que ya no queramos mantener en memoria */
void DestruirNodo(Nodo* nodo){
    free(nodo);
}

/* Insertar un libro al principio de una lista */
void InsertarPrincipio(Lista* lista, Libro* libro){
    Nodo* nodo = CrearNodo(libro); // Crea un nuevo nodo a partir de los datos de mi libro
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
}

/* Insertar un libro al final de lista */
void InsertarFinal(Lista* lista, Libro* libro){

    Nodo* nodo = CrearNodo(libro);

    // Si la lista está vacía
    if (lista->cabeza == NULL) {
        lista->cabeza = nodo;
    } else {

        Nodo* puntero = lista->cabeza;

        while(puntero->siguiente){
            puntero = puntero->siguiente;
        }

        puntero->siguiente = nodo;

    }

}

/* Insertar un libro después del nodo n*/
void InsertarDespues(int n, Lista* lista, Libro* libro){

    Nodo* nodo = CrearNodo(libro);

    // Si la lista está vacía
    if (lista->cabeza == NULL){
        lista->cabeza = nodo;
    } else {

        // Buscamos el libro n
        Nodo* puntero = lista->cabeza;
        int posicion = 0;

        while(posicion < n && puntero->siguiente){
            puntero = puntero->siguiente;
            posicion++;
        }

        nodo->siguiente = puntero->siguiente;
        puntero->siguiente = nodo;

    }


}

/* Obtener el libro n de una lista */
Libro* Obtener(int n, Lista* lista){

    if (lista->cabeza == NULL){
        return NULL;
    } else {

        // Buscamos el libro n
        Nodo* puntero = lista->cabeza;
        int posicion = 0;

        while(posicion < n && puntero->siguiente){
            puntero = puntero->siguiente;
            posicion++;
        }
        if(posicion != n){
            return NULL;
        } else {
            return &puntero->libro;
        }

    }

}

// 
int Contar() {

}