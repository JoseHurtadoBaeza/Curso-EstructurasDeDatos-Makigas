public class Empleado implements Comparable<Empleado>{
    
    private int id;

    private String nombre;

    private String puesto;

    private String despacho;

    public Empleado(int id, String nombre, String puesto, String despacho){
        this.id = id;
        this.nombre = nombre;
        this.puesto = puesto;
        this.despacho = despacho;
    }

    public int getId(){
        return id;
    }

    public void setId(int id){
        this.id = id;
    }

    public String getNombre(){
        return nombre;
    }

    public void setNombre(String nombre){
        this.nombre = nombre;
    }

    public String getPuesto(){
        return puesto;
    }

    public void setPuesto(String puesto){
        this.puesto = puesto;
    }

    public String getDespacho(){
        return despacho;
    }

    public void setDespacho(String despacho){
        this.despacho = despacho;
    }

    /*@Override
    public String toString(){

    }

    @Override
    public int hashCode(){

    }

    @Override
    public boolean equals(Object obj){

    }*/

    @Override /* Devolverá -1 o un número negativo si el elemento que tenemos en esta instancia es menor que el elemento que se pasa por parámetro.  
    Debe devolver +1 si empl es mayor que this y debe devolver 0 si son iguales */
    public int compareTo(Empleado empl){
        if (id == empl.id){
            return 0;
        } else if (id < empl.id){
            return -1;
        } else {
            return 1;
        }
    }

}
