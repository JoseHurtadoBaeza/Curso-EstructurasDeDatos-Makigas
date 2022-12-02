import java.util.logging.LogManager;

public class MiPila implements Pila {
    
    public class Nodo{
        
        public URL url;

        public Nodo siguiente = null;

        public Nodo(URL url){
            this.url = url;
        }

    }

    private Nodo cima = null;

    private int longitud = 0;

    @Override
    public void apilar(URL url){
        Nodo nodo = new Nodo(url);
        nodo.siguiente = cima;
        cima = nodo;
        longitud++;
    }

    @Override
    public void desapilar(){
        if (cima != null){ // Comprobamos que la pila tenga cosas
            Nodo eliminar = cima;
            cima = cima.siguiente;
            eliminar.siguiente = null;
            longitud--;
        }
    }

    @Override
    public URL obtener(){
        if (cima == null){ // Comprobamos si la pila está vacía
            return null; // Alternativamente podríamos devolver una excepción o lanzar una excepción diciendo que la pila está vacía y no puedes obtener nada
        } else {
            return cima.url;
        }

    }

    // Nos informa de cuantos elementos hay en mi pila
    @Override
    public int longitud(){
        return longitud;
    }

    @Override
    public boolean vacia(){
        return longitud == 0;
    }

}
