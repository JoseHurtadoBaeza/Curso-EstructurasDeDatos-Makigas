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
    lista->longitud++;
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

    lista->longitud++;

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

    lista->longitud++;

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

// Cuenta el número de elementos que hay en una lista
int Contar(Lista* lista) {
    return lista->longitud;
}

// Devuelve 1 si la lista no está vacía y 0 en caso contrario
int EstaVacia(Lista* lista){
    return lista->cabeza == NULL;
}

// Elimina el primer elemento de la lista
void EliminarPrincipio(Lista* lista){

    if(lista->cabeza){
        Nodo* eliminado = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        DestruirNodo(eliminado);
        lista->longitud--;
    }

}

// Elimina el último elemento de la lista
void EliminarUltimo(Lista* lista){
    
    if(lista->cabeza){

        // Si la lista sólamente tiene más de 1 elemento
        if (lista->cabeza->siguiente){
            Nodo* puntero = lista->cabeza;
            while(puntero->siguiente->siguiente){
                puntero = puntero->siguiente;
            }

            // Hemos llegado al penúltimo, pero tenemos que mantener una referencia al nodo que vamos a eliminar
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = NULL;
            DestruirNodo(eliminado);
            lista->longitud--;
        } else {
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = NULL;
            DestruirNodo(eliminado);
            lista->longitud--;
        }

    }
}  

// Elimina el elemento n de mi lista
void EliminarElemento(int n, Lista* lista){

    // Comprobamos que la lista no esté vacía
    if(lista->cabeza){

        // Caso particular en el que se nos pide eliminar el primer elemento de la lista
        if (n == 0){
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = lista->cabeza->siguiente;
            DestruirNodo(eliminado);
            lista->longitud--;
        } else if (n < lista->longitud) { // Comprobamos que n se encuentre en los límites de mi lista

            Nodo* puntero = lista->cabeza;
            int posicion = 0;
            while(posicion < (n-1)){
                puntero = puntero->siguiente;
                posicion++;
            }

            // Una vez estemos en el nodo anterior al que queremos eliminar
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = eliminado->siguiente;
            DestruirNodo(eliminado);
            lista->longitud--;

        }

    }

} 