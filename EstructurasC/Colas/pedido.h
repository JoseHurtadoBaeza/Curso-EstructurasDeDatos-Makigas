#ifndef pedido_h
#define pedido_h

#include <stdio.h>

typedef struct LineaPedido {
    int id_producto;
    int cantidad;
    float precio_unidad;
} LineaPedido;

typedef struct NodoLineaPedido {
    LineaPedido linea;
    struct NodoLineaPedido* siguiente;
} NodoLineaPedido;

typedef struct Pedido {
    int id_cliente;
    NodoLineaPedido* lista_productos;
} Pedido;

#endif 