#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo* izqo; // Puntero al hijo izquierdo
    struct nodo* dcho; // Puntero al hijo derecho
    struct nodo* padre; 
} Nodo;

typedef Nodo Arbol; // De esta forma podemos hacer operaciones para crear y destruir nodos sin tener que crear necesariamente árboles

Nodo* CrearNodo(int valor, Nodo* padre){
    Nodo* nuevoNodo = (Nodo *) malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    // Como no sabemos a lo que apunta este nodo, hacemos que sus hijos apunten a NULL
    nuevoNodo->izqo = NULL;
    nuevoNodo->dcho = NULL;
    nuevoNodo->padre = padre;
    return nuevoNodo;
}

void DestruirNodo(Nodo* nodo){
    nodo->izqo = NULL; // Asignamos a null por si acaso
    nodo->dcho = NULL; // Asignamos a null por si acaso
    free(nodo); // Eliminamos los datos del nodos
}

// Recordemos que si vamos a modificar el árbol es necesario que lo que me pases no sea un puntero al árbol
// sino el puntero al puntero arbol para que yo pueda modificar lo que vale esto (Nodo *arbol = NULL;)
// ESTA VA A SER LA FUNCIÓN DE APOYO QUE HACE TODO
static void InsertarConPadre(Nodo** arbol, Nodo* padre, int valor){

    // Tenemos que distinguir entre si el árbol que se pasa por parámetro está vacío o no
    if (*arbol == NULL){ // Si lo que me has pasado es un árbol vacío
        *arbol = CrearNodo(valor, padre); // Te modifico ese valor para que ahora apunte a mi nuevo nodo
    } else { // Tenemos que distinguir cuánto vale la raíz del árbol puesto que en árboles binarios siempre insertamos en las hojas y siempre en función de un criterio, 
             // los elementos menores a la izquierda y los elementos mayores a la derecha.
        int valorRaiz = (*arbol)->valor; // Extraemos el valor de la raíz del árbol

        // Determinamos si lo que intentamos insertar es mayor o menor que el valor del nodo raíz
        if (valor < valorRaiz){
            InsertarConPadre(&(*arbol)->izqo, *arbol, valor); // Probamos a insertalo por el subárbol izquierdo, tenemos que indicar el & para pasar como puntero por si hay que modificar el valor
        } else { 
            InsertarConPadre(&(*arbol)->dcho, *arbol, valor); // Probamos a insertarlo por el subárbol derecho
        }
    }

}

// Y ESTA VA A SER LA FUNCIÓN BONITA QUE EXPONEMOS AL PÚBLICO
void Insertar(Nodo** arbol, int valor){
    InsertarConPadre(arbol, NULL, valor);
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

/* Devuelve el nodo de ese árbol que tiene el valor indicado por parámetro */
Nodo* Obtener(Nodo* arbol, int valor){
    if (arbol == NULL){
        return NULL;
    } else if (arbol-> valor == valor){
        return arbol;
    } else if (valor < arbol->valor){
        return Obtener(arbol->izqo, valor);
    } else {
        return Obtener(arbol->dcho, valor);
    }
}

void DeterminarExistencia(Nodo* arbol, int valor){
    if (Existe(arbol, valor)){
        printf("El nodo %d existe en el arbol.\n", valor);
    } else {
        printf("El nodo %d NO existe en el arbol.\n", valor);
    }
}   

/* Esta función le dice al padre del elemento a eliminar: "oye, donde esté tu anterior hijo, ahora tienes que poner tu nuevo hijo".
Esta función la vamos a usar también cuando eliminemos un nodo hoja, es decir, que reemplace en el padre de dicho nodo hoja a su hijo por NULL.
*/
static void Reemplazar(Nodo* arbol, Nodo* nuevoNodo){

    if (arbol->padre){ // Si el padre existe
        // Procedemos a colocar en el padre de arbol el nuevoNodo como nuevo hijo.
        if (arbol->valor == arbol->padre->izqo->valor){
            arbol->padre->izqo = nuevoNodo;
        } else if (arbol->valor == arbol->padre->dcho->valor){
            arbol->padre->dcho = nuevoNodo;
        }
    }
    if (nuevoNodo){ // Si nuestro nuevo nodo existe
        // Procedemos a poner como padre de nuevoNodo a arbol->padre
        nuevoNodo->padre = arbol->padre;
    }

}

/* Función a la que pasamos un árbol y te devuelve el nodo con menor valor */
static Nodo* Minimo(Nodo* arbol){
    if (arbol == NULL){
        return NULL;
    }
    if (arbol->izqo) { // Si tiene hijo izquierdo quiere decir que hay un nodo cuyo valor es menor
        return Minimo(arbol->izqo);
    } else { // Si no tiene hijo izquierdo pues me devuelvo a mi mismo
        return arbol;
    }
}

static void EliminarNodo(Nodo* nodoEliminar){
    if (nodoEliminar->izqo && nodoEliminar->dcho){ // Si el nodo a eliminar tiene 2 hijos
        // Tratar de eliminar con 2 hijos.
        Nodo* minimo = Minimo(nodoEliminar->dcho); // Obtenemos el nodo con menor valor de mi hijo derecho
        nodoEliminar->valor = minimo->valor; // Hago que mi valor sea el valor del mínimo
        EliminarNodo(minimo);
    } else if (nodoEliminar->izqo){ // Si el nodo a eliminar sólo tiene 1 hijo izquierdo
        // Tratar de eliminar con 1 hijo.
        Reemplazar(nodoEliminar, nodoEliminar->izqo);
        DestruirNodo(nodoEliminar);
    } else if (nodoEliminar->dcho){ // Si el nodo a eliminar sólo tiene 1 hijo derechos
        // Tratar de eliminar con 1 hijo.
        Reemplazar(nodoEliminar, nodoEliminar->dcho);
        DestruirNodo(nodoEliminar);
    } else { // Si el nodo a eliminar es un nodo hoja
        // Tratar eliminar con 0 hijos.
        Reemplazar(nodoEliminar, NULL); // Le decimos al padre que en mi posición ponga NULL
        DestruirNodo(nodoEliminar);
    }
}

void Eliminar(Nodo* arbol, int valor){
    if (arbol == NULL){ // Si se pasa un arbol vacío no hacemos nada
        return;
    } else if (valor < arbol->valor){ // Si tenemos que tirar por el subárbol izquierdo
        Eliminar(arbol->izqo, valor);
    } else if (valor > arbol->valor){ // Si tenemos que tirar por el subárbol derecho
        Eliminar(arbol->dcho, valor);
    } else {
        EliminarNodo(arbol);
    }
}

void Preorden(Nodo* arbol){
    if (arbol == NULL){ // Detectamos el caso base, que es cuando el árbol está vacío
        printf(" - ");
    } else { // Sino, tenemos que procesar este nodo que me pasas
        printf("( %d ", arbol->valor); // Procesamos la raíz
        Preorden(arbol->izqo);
        Preorden(arbol->dcho);
        printf(" )");
    }
}

void Inorden(Nodo* arbol){
    if (arbol == NULL){ // Caso base
        printf(" - ");
    } else {
        printf("( ");
        Inorden(arbol->izqo);
        printf(" %d ", arbol->valor);
        Inorden(arbol->dcho);
        printf(" )");
    }
}

void Postorden(Nodo* arbol){
    if (arbol == NULL){ // Caso base
        printf(" - ");
    } else {   
        printf("( ");
        Postorden(arbol->izqo);
        Postorden(arbol->dcho);
        printf(" %d )", arbol->valor);
    }
}

int main(int argc, char **argv){
    //Nodo *arbol = CrearNodo(10); // Creamos un árbol y guardamos el elemento número 10
    // Creamos un árbol vacío
    Nodo *arbol = NULL;     Inorden(arbol); printf("\n");
    Insertar(&arbol, 5);    Inorden(arbol); printf("\n");
    Insertar(&arbol, 10);   Inorden(arbol); printf("\n");
    Insertar(&arbol, 4);    Inorden(arbol); printf("\n");
    Insertar(&arbol, 9);    Inorden(arbol); printf("\n");
    Insertar(&arbol, 15);   Inorden(arbol); printf("\n");
    Insertar(&arbol, 20);   Inorden(arbol); printf("\n");
    Insertar(&arbol, 2);   Inorden(arbol); printf("\n");

    Eliminar(arbol, 4);   Inorden(arbol); printf("\n");
    Eliminar(arbol, 15);  Inorden(arbol); printf("\n");
    Eliminar(arbol, 5);  Inorden(arbol); printf("\n");

    /*DeterminarExistencia(arbol, 10);
    DeterminarExistencia(arbol, 3);
    DeterminarExistencia(arbol, 9);*/

    return 0; 
}