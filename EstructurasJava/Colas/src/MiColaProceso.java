public class MiColaProceso implements ColaProceso {
    
    // Clase que representa un nodo en mi cola de proceso
    private class NodoProceso {

        public Trabajo trabajo;

        public NodoProceso siguiente; // "Puntero" a mi siguiente

        public NodoProceso(Trabajo trabajo){
            this.trabajo = trabajo;
            // this.siguiente = null; No es necesario porque al crear el atributo siguiente ya se pone por defecto a null
        }

    }

    // Creamos los dos "punteros" más importantes
    private NodoProceso cabeza, ultimo; // Como estamos en Java se van a inicializar a NULL

    @Override
    public void encolar(Trabajo t){
        
        NodoProceso nuevoNodo = new NodoProceso(t);

        if (cabeza == null){
            cabeza = nuevoNodo;
        } else {
            ultimo.siguiente = nuevoNodo;
        }

        ultimo = nuevoNodo;

    }

    @Override
    public void eliminar() {
        if (cabeza != null){
            NodoProceso eliminado = cabeza;
            cabeza = cabeza.siguiente;
            eliminado.siguiente = null;

            // Si la cabeza ahora apunta a null
            if (cabeza == null){
                ultimo = null;
            }
        } 
    }

    @Override
    public Trabajo obtener() {
        if (cabeza == null){
            return null;
        } else {
            return cabeza.trabajo;
        }
    }

}
