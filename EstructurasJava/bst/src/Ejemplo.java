import java.util.Arrays;

public class Ejemplo {

    public static void main(String[] args){
        Empleado e1 = new Empleado(20, "Pepito Pérez", "Ventas", "A-252");
        Empleado e2 = new Empleado(44, "Ana López", "Recursos Humanos", "B-198");
        Empleado e3 = new Empleado(18, "Elena Nito", "Ventas", "A-241");
        Empleado e4 = new Empleado(33, "José Gómez", "Contabilidad", "B-96");
        Empleado e5 = new Empleado(64, "Francisco Pérez", "Márketing", "A-69");
        Empleado e6 = new Empleado(55, "Javier López", "Informática", "B-161");
    
        BST bst = new BST();
        Arrays.asList(e1, e2, e3, e4, e5, e6).forEach(e -> bst.insertar(e)); // Coge cada uno de los elementos de la lista y los mete en el árbol bst

        bst.postorden();

        /*BST bst = new BST();
        System.out.println("Está vacío: " + bst.esVacio() + " - Es hoja:" + bst.esHoja());
        bst.insertar(e1);
        System.out.println("Está vacío: " + bst.esVacio() + " - Es hoja:" + bst.esHoja());
        bst.insertar(e2);
        System.out.println("Está vacío: " + bst.esVacio() + " - Es hoja:" + bst.esHoja());
        //bst.insertar(e2); // Probando insertar duplicado tras añadir excepción para este caso en el método insertar

        localizar(bst, 44);
        localizar(bst, 5);*/

    }

    /*private static void localizar(BST bst, int id){
        if (bst.existe(id)){
            System.out.println(bst.obtener(id));
        } else {
            System.out.println("No encuentro el empleado " + id);
        }
    }*/


}