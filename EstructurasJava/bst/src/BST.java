public class BST implements IBST<Empleado> {

    private Empleado valor;

    private BST izdo, dcho; // Al ser Java inicialmente les asigna NULL

    @Override // Un árbol será vacío cuando no tenga nada
    public boolean esVacio() {
        return valor == null; // Si valor es nulo quiere decir que no le hemos metido ningún empleado por lo que el árbol va a estar vacío
    }

    @Override // Para ser hoja tiene que haber valor y a la vez que no haya izquierdo ni derecho
    public boolean esHoja() {
        return valor != null && izdo == null && dcho == null;
    }

    @Override
    public void insertar(Empleado empl) {
        if (valor == null){ // Si el árbol está vacío por no tener valor, lo insertamos directamente
            this.valor = empl;
        } else {
            if (empl.compareTo(valor) < 0) { // Si el empleado que intentas insertar tiene un id menor que el que hay en valor
                if (izdo == null) izdo = new BST(); // Así nos aseguramos de que izquierdo no valga null para evitar NullPointerException
                izdo.insertar(empl);
            } else if (empl.compareTo(valor) > 0) {
                if (dcho == null) dcho = new BST();
                dcho.insertar(empl);
            } else { // Por si se da el caso de que el compareTo da 0, por lo que tendríamos un duplicado
                // Podemos no hacer nada o tirar una excepción, podemos dar un mensaje de error. En este caso no vamos a hacer nada.
            }
        }
    }

    @Override
    public boolean existe(int id) {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public Empleado obtener(int id) {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public void preorden() {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void inorden() {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void postorden() {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void eliminar(int id) {
        // TODO Auto-generated method stub
        
    }
    
    

}
