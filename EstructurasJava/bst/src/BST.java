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
                // Podemos no hacer nada o tirar una excepción, podemos dar un mensaje de error.
                throw new RuntimeException("Insertando elemento duplicado.");
            }
        }
    }

    @Override /* Debe devolver true si encuentra el elemento en el árbol, falso en caso contrario */
    public boolean existe(int id) {
        if (valor != null){ // Comprobamos que el valor no sea vacío
            if (id == valor.getId()){
                return true;
            } else if (id < valor.getId() && izdo != null){
                return izdo.existe(id);
            } else if (id > valor.getId() && dcho != null){
                return dcho.existe(id);
            } else { // Si no existe lo que estamos buscando
                return false;
            }
        } else {
            return false;
        }
    }

    @Override /* Devolvemos el propio empleado si lo encuentro y sino un null */
    public Empleado obtener(int id) {
        if (valor != null){ // Comprobamos que el valor no sea vacío
            if (id == valor.getId()){
                return valor;
            } else if (id < valor.getId() && izdo != null){
                return izdo.obtener(id);
            } else if (id > valor.getId() && dcho != null){
                return dcho.obtener(id);
            } else { // Si no existe lo que estamos buscando
                return null;
            }
        } else {
            return null;
        }
    }

    /* De forma recursiva se ponga un margen a medida que nos vamos hundiendo*/
    private void preordenImpl(String prefijo){
        if (valor != null){ // Si el árbol no es vacío
            System.out.println(prefijo + valor); // Procesamos la raíz
            if (izdo != null) izdo.preordenImpl(prefijo + "  ");
            if (dcho != null) dcho.preordenImpl(prefijo + "  ");
        }
    }

    @Override
    public void preorden() {
        preordenImpl("");
    }

    private void inordenImpl(String prefijo){
        if (valor != null){ // Si el árbol no es vacío
            if (izdo != null) izdo.inordenImpl(prefijo + "  ");
            System.out.println(prefijo + valor); // Procesamos la raíz
            if (dcho != null) dcho.inordenImpl(prefijo + "  ");
        }
    }

    @Override
    public void inorden() {
        inordenImpl("");
    }

    private void postordenImpl(String prefijo){
        if (valor != null){ // Si el árbol no es vacío
            if (izdo != null) izdo.postordenImpl(prefijo + "  ");
            if (dcho != null) dcho.postordenImpl(prefijo + "  ");
            System.out.println(prefijo + valor); // Procesamos la raíz
        }
    }

    @Override
    public void postorden() {
        postordenImpl("");
    }

    @Override
    public void eliminar(int id) {
        // TODO Auto-generated method stub
        
    }
    
    

}
