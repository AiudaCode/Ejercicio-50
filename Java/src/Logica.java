public class Logica
{
    private Laptop [] vector;
    private int tamaño;
    
    public Logica()
    {
        // se le asignan valores por defecto a los atributos en el constructor de la clase
        vector = null;
        tamaño = 0;
    }
    
    // método para crear el vector
    public void crearVector()
    {
        // le asigno al vector de tipo Laptop el tamaño del valor de la variable tamano
        vector = new Laptop[tamaño];
    }
    
    // métodos Setters y Getters de los atributos de la clase
    public void setVector(int pos, Laptop val)
    {
        vector[pos] = val;
    }
    
    public Laptop getVector(int pos)
    {
        return vector[pos];
    }
    
    public void setTamaño(int val)
    {
        tamaño = val;
    }
    
    public int getTamaño()
    {
        return tamaño;
    }
    
    // método para buscar una referencia
    public int buscar(String nom)
    {
        // recorremos el vector con el ciclo for
        for (int i = 0; i < getTamaño(); i++)
        {
            // si la referencia de la posicion i del vector es igual al valor de la vatiable nom pasada como parametro
            if (getVector(i).getReferencia().equals(nom))
            {
                // entonces, se retorna la posicion i
                return i;
            }
        }
        // si no se encontro nada, se retorna -1
        return -1;
    }
    
    // método para buscar una marca
    public int buscarMarca(String nom)
    {
        // recorremos el vector con el ciclo for
        for (int i = 0; i < getTamaño(); i++)
        {
            // si la marca de la posicion i del vector es igual al valor de la vatiable mar pasada como parametro
            if (getVector(i).getMarca().equals(nom))
            {
                // entonces, se retorna la posicion i
                return i;
            }
        }
        // si no se encontro nada, se retorna -1
        return -1;
    }
    
    // método para buscar el equipo mas economico de una marca
    public int buscarEquipoEconomicoMarca(String mar)
    {
        // inicializo una variable de tipo double llamada men, en el precio del equipo mas costoso por la marca especifica mar
        float men = getVector(buscarEquipoCostosoMarca(mar)).getPrecio();
        // declaro una variable de tipo double llamada def
        float def;
        // inicializo una variable de tipo int llamada pos_menor, en -1
        int pos_menor = -1;
        // recorremos el vector con el ciclo for
        for (int i = 0; i < getTamaño(); i++)
        {
            // le asignamos a la variable def, el precio de la posicion i del vector
            def = getVector(i).getPrecio();
            // si la marca de la posicion i del vector es igual al valor de la variable mar pasada
            // como parametro y si def es menor a la variable men
            if (getVector(i).getMarca().equals(mar) && def < men)
            {
                // entonces le asigno a la variable men el valor de la variable def
                men = def;
                // y a la variable pos_menor le asigno el valor de i
                pos_menor = i;
            }
        }
        // retorno el valor de la variable pos_menor
        return pos_menor;
    }
    
    // método para buscar el equipo mas economico de todas las marcas
    public int buscarEquipoEconomicoTodos()
    {
        // inicializo una variable de tipo double llamada men, en el precio del equipo mas costoso de todas las marcas
        float men = getVector(buscarEquipoCostosoTodos()).getPrecio();
        // declaro una variable de tipo double llamada def
        float def;
        // inicializo una variable de tipo int llamada pos_menor, en -1
        int pos_menor = -1;
        // recorremos el vector con el ciclo for
        for (int i = 0; i < getTamaño(); i++)
        {
            // le asignamos a la variable def, el precio de la posicion i del vector
            def = getVector(i).getPrecio();
            // si el valor de la variable def es menor al valor de la variable men
            if(def < men)
            {
                // entonces le asigno a la variable men el valor de la variable def
                men = def;
                // y a la variable pos_menor le asigno el valor de i
                pos_menor = i;
            }
        }
        // retorno el valor de la variable pos_menor
        return pos_menor;
    }
    
    // método para buscar el equipo mas costoso de una marca
    public int buscarEquipoCostosoMarca(String mar)
    {
        // inicializamos una variable de tipo double llamada max, en 0
        float max = 0;
        // método para buscar el equipo mas economico de una marca
        float def;
         // inicializo una variable de tipo int llamada pos_mayor, en -1
        int pos_mayor = -1;
        // recorremos el vector con el ciclo for
        for (int i = 0; i < getTamaño(); i++)
        {
            // le asignamos a la variable def, el precio de la posicion i del vector
            def = getVector(i).getPrecio();
            // si la marca de la posicion i del vector es igual al valor de la variable nom pasada como parametro
            // y si el valor de la varianle def es mayor al valor de la variable max
            if (getVector(i).getMarca().equals(mar) && def > max)
            {
                // entonces le asigno a la variable max el valor de la variable def
                max = def;
                // y a la variable pos_mayor le asigno el valor de i
                pos_mayor = i;
            }
        }
        // retorno el valor de la variable pos_mayor
        return pos_mayor;
    }
    
    // método para buscar el equipo mas costoso de todas las marca
    public int buscarEquipoCostosoTodos()
    {
        // inicializamos una variable de tipo double llamada max, en 0
        float max = 0;
        // método para buscar el equipo mas economico de una marca
        float def;
        // inicializo una variable de tipo int llamada pos_mayor, en -1
        int pos_mayor = -1;
        // recorremos el vector con el ciclo for
        for (int i = 0; i < getTamaño(); i++)
        {
            // le asignamos a la variable def, el precio de la posicion i del vector
            def = getVector(i).getPrecio();
            // si el valor de la variable def es mayor al valor de la variable max
            if(def > max)
            {
                // entonces le asigno a la variable max el valor de la variable def
                max = def;
                // y a la variable pos_mayor le asigno el valor de i
                pos_mayor = i;
            }
        }
        // retorno el valor de la variable pos_mayor
        return pos_mayor;
    }
    
    // método para ordenar por referencia
    public void ordenarPorReferencia()
    {
        for (int i = 0; i < getTamaño(); i++)
        {
            for (int j = i+1; j < getTamaño(); j++)
            {
                // si la referencia de la posicion es menor a la referencia de la posicion j del vector
                if (getVector(i).getReferencia().compareTo(getVector(j).getReferencia()) < 0)
                {
                    // cambiamos la posicion i con j
                    cambiar(i, j);
                }
            }
        }
    }
    
    // método para cambiar la posicion de un objeto del vector con otra
    public void cambiar(int p1, int p2)
    {
        // declaro un objeto de tipo Laptop llamado temp
        Laptop temp;
        // le asigno a la variable temp el objeto que esta en la posicion p1 del vector
        temp = getVector(p1);
        // a la posicion p1 del vector se le asignara el objeto que esta en la posicion p2
        setVector(p1, getVector(p2));
        // a la posicion p2 del vector se le asignara el objeto temp
        setVector(p2, temp);
    }
}