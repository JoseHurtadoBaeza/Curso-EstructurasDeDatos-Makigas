#include "cola.h"

#include <stdlib.h>

NodoPedido* CrearNodo(Pedido* pedido){
    NodoPedido* nodo = (NodoPedido *) malloc(sizeof (NodoPedido));
    nodo->pedido = pedido;
    nodo->siguiente = NULL;
    return nodo;
}

void DestruirNodo(NodoPedido* nodo){
    nodo->pedido = NULL;
    nodo->siguiente = NULL;
    free(nodo);
}

Cola* CrearCola() {
    Cola* cola = (Cola *) malloc(sizeof(Cola));
    cola->primer = NULL;
    cola->ultimo = NULL;
    return cola;
}

/* Destruye la cola completa */
void DestruirCola(Cola* cola) {
    while(cola->primer){ // Mientras la cola no esté vacía
        Eliminar(cola);
    }
    free(cola);
}

/* Encola un pedido al final de la cola */
void Encolar(Cola* cola, Pedido* pedido){
    NodoLineaPedido* nodo = CrearNodo(pedido);
    if (!cola->primer){
        cola->primer = nodo;
        cola->ultimo = nodo;
    } else {
        cola->ultimo->siguiente = nodo;
        cola->ultimo = nodo;
    }
}
/* Esta función tiene que devolver el pedido que haya en la cabeza de nuestra cola */
Pedido* Consultar(Cola* cola){
    if(cola->primer){
        return cola->primer->pedido;
    } else {
        return NULL;
    }
}

/* Elimina el primer pedido de la cola */
void Eliminar(Cola* cola){
    if (cola->primer){
        NodoPedido* eliminado = cola->primer;
        cola->primer = cola->primer->siguiente;
        DestruirNodo(eliminado);

        if (!cola->primer){
            cola->ultimo = NULL;
        }

    }
}
