#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo* izqo; // Puntero al hijo izquierdo
    struct nodo* dcho; // Puntero al hijo derecho
} Nodo;

typedef Nodo Arbol; // De esta forma podemos hacer operaciones para crear y destruir nodos sin tener que crear necesariamente árboles

Nodo* CrearNodo(int valor){
    Nodo* nuevoNodo = (Nodo *) malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    // Como no sabemos a lo que apunta este nodo, hacemos que sus hijos apunten a NULL
    nuevoNodo->izqo = NULL;
    nuevoNodo->dcho = NULL;
    return nuevoNodo;
}

void DestruirNodo(Nodo* nodo){
    nodo->izqo = NULL; // Asignamos a null por si acaso
    nodo->dcho = NULL; // Asignamos a null por si acaso
    free(nodo); // Eliminamos los datos del nodos
}

// Recordemos que si vamos a modificar el árbol es necesario que lo que me pases no sea un puntero al árbol
// sino el puntero al puntero arbol para que yo pueda modificar lo que vale esto (Nodo *arbol = NULL;)
void Insertar(Nodo** arbol, int valor){

    // Tenemos que distinguir entre si el árbol que se pasa por parámetro está vacío o no
    if (*arbol == NULL){ // Si lo que me has pasado es un árbol vacío
        *arbol = CrearNodo(valor); // Te modifico ese valor para que ahora apunte a mi nuevo nodo
    } else { // Tenemos que distinguir cuánto vale la raíz del árbol puesto que en árboles binarios siempre insertamos en las hojas y siempre en función de un criterio, 
             // los elementos menores a la izquierda y los elementos mayores a la derecha.
        int valorRaiz = (*arbol)->valor; // Extraemos el valor de la raíz del árbol

        // Determinamos si lo que intentamos insertar es mayor o menor que el valor del nodo raíz
        if (valor < valorRaiz){
            Insertar(&(*arbol)->izqo, valor); // Probamos a insertalo por el subárbol izquierdo, tenemos que indicar el & para pasar como puntero por si hay que modificar el valor
        } else { 
            Insertar(&(*arbol)->dcho, valor); // Probamos a insertarlo por el subárbol derecho
        }
    }

}

// Determina si dentro de un árbol existe el valor que se proporciona por parámetro. Recordemos que en C no existe el booleano
int Existe(Nodo* arbol, int valor){

    // Si el árbol que me has pasado está vacío
    if (arbol == NULL){
        return 0; // Para valores falsos
    } else if (arbol->valor == valor) { // Si el árbol existe y además tiene un valor que es exactamente igual que el valor
        return 1; // Para valores true
    } else if (valor < arbol->valor){ // Si lo que buscamos es menor que la raíz tiramos por el subárbol izquierdo        
        return Existe(arbol->izqo, valor);
    } else { // En caso contrario tiramos por el subárbol derecho
        return Existe(arbol->dcho, valor);
    }

}

void DeterminarExistencia(Nodo* arbol, int valor){
    if (Existe(arbol, valor)){
        printf("El nodo %d existe en el arbol.\n", valor);
    } else {
        printf("El nodo %d NO existe en el arbol.\n", valor);
    }
}   

int main(int argc, char **argv){
    //Nodo *arbol = CrearNodo(10); // Creamos un árbol y guardamos el elemento número 10
    Nodo *arbol = NULL; // Creamos un árbol vacío
    Insertar(&arbol, 5);
    Insertar(&arbol, 10);
    Insertar(&arbol, 4);
    Insertar(&arbol, 9);
    Insertar(&arbol, 15);

    DeterminarExistencia(arbol, 10);
    DeterminarExistencia(arbol, 3);
    DeterminarExistencia(arbol, 9);

    return 0; 
}