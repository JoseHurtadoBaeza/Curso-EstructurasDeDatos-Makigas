public class Lista {
    
    private Nodo cabeza; // Variable que hace referencia al primer elemento de la lista

    private int longitud = 0; // Variable que indica el número de elementos que contiene la lista

    public class Nodo {
        public Libro libro;
        public Nodo siguiente = null;

        public Nodo(Libro libro){
            this.libro = libro;
        }

    }

    public void insertarPrincipio(Libro libro){
        Nodo nodo = new Nodo(libro);
        nodo.siguiente = cabeza;
        cabeza = nodo;
        longitud++;
    }    

    public void insertarFinal(Libro libro){
        Nodo nodo = new Nodo(libro);

        if (cabeza == null){ // Si la lista está vacías
            cabeza = nodo;
        } else {
            Nodo puntero = cabeza; // Este nodo va a tener que ir avanzando hasta llegar al final de la lista

            while(puntero.siguiente != null){
                puntero = puntero.siguiente;
            }
    
            // Hemos llegado al final de la lista
            puntero.siguiente = nodo;
        }

        longitud++;

    }

    public void insertarDespues(int n, Libro libro){
        Nodo nodo = new Nodo(libro);
        
        if (cabeza == null){ // Si la lista está vacía
            cabeza = nodo;
        } else {
            // Buscamos el libro n
            Nodo puntero = cabeza;
            int contador = 0;
            while(contador < n && puntero.siguiente != null){
                puntero = puntero.siguiente;
                contador++;
            }

            nodo.siguiente = puntero.siguiente; // Conectamos el nuevo nodo por la derecha a la lista
            puntero.siguiente = nodo; // Y luego lo conectamos por la izquierda

        }

        longitud++;

    }

    public Libro obtener(int n){
        if (cabeza == null){ // Si la lista está vacía
            return null;
        } else {
            Nodo puntero = cabeza;
            int contador = 0;
            while (contador < n && puntero.siguiente != null){
                puntero = puntero.siguiente;
                contador++;
            }
            if (contador != n) {
                return null;
            } else {
                return puntero.libro;
            } 
        }
    }
    /* Método que nos diga cuántos libros tenemos en la lista */
    public int contar() {
        return longitud;
    }

    public boolean estaVacia(){
        return cabeza == null;
    }

    public void eliminarPrincipio(){

        if (cabeza != null){ // Si la lista no está vacía
            Nodo primer = cabeza;
            cabeza = cabeza.siguiente;
            primer.siguiente = null;
            longitud--;   
        }

    }

    public void eliminarUltimo(){

        if (cabeza != null) { // Comprobamos que la lista no esté vacía

            if (cabeza.siguiente == null){ // Si la lista sólo tiene un elemento
                cabeza = null;
            } else {
                Nodo puntero = cabeza;

                while (puntero.siguiente.siguiente != null){
                    puntero = puntero.siguiente;
                }
    
                // Cuando hemos llegado al penúltimo elemento simplemente eliminamos la referencia al último
                puntero.siguiente = null;
            }

            longitud--;

        }

    }

    public void eliminarLibro(int n){
        
        if (cabeza != null){ // Comprobamos que la lista no esté vacía

            if (n == 0){ // Si se nos pide eliminar el primer libro
                Nodo primer = cabeza;
                cabeza = cabeza.siguiente;
                primer.siguiente = null;
                longitud--;   
            } else if (n < longitud){
                // Buscamos el elemento n-1
                Nodo puntero = cabeza;
                int contador = 0;
                while (contador < (n - 1)){
                    puntero = puntero.siguiente;
                    contador++;
                }

                Nodo temp = puntero.siguiente;
                puntero.siguiente = temp.siguiente;
                temp.siguiente = null;
                longitud--;
            }

        }

    }

}
