#ifndef cola_h
#define cola_h

#include <stdio.h>
#include "pedido.h"

typedef struct NodoPedido {
    Pedido* pedido;
    struct NodoPedido* siguiente;
} NodoPedido;

typedef struct Cola {
    NodoPedido* primer;
    NodoPedido* ultimo;
} Cola;

NodoPedido* CrearNodo(Pedido* pedido);
void DestruirNodo(NodoPedido* pedido);

Cola* CrearCola();
void DestruirCola(Cola* cola);

void Encolar(Cola* cola, Pedido* pedido);
Pedido* Consultar(Cola* cola);
void Eliminar(Cola* cola);

#endif