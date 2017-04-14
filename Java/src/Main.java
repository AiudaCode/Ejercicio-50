
import javax.swing.JOptionPane;

public class Main
{
    // método para llenar el vector
    public static void llenar(Laptop obj,Logica log,int pos)
    {
        // declaramos una variable de tipo string llamada ref
        String ref;
        // inicializamos una variable de tipo bool llamada existe en true
        boolean existe = true;
        // con el ciclo do-while validaremos si la referencia esta o no repetida
        do
        {
            // pedimos la referencia
            ref = JOptionPane.showInputDialog("Ingrese la referencia:");
            // inicializamos una variable de tipo bool llamada repetida en false
            boolean repetida = false;
            // recorremos hasta el valor de la variable pasada como parametro pos
            for (int i = 0; i < pos; i++)
            {
                // si la referencia de la posicion i del vector es igual al valor de la variable ref
                if(log.getVector(i).getReferencia().equals(ref))
                {
                    // entonces la referencia estara repetida, le asignamos a la variable repetida el valor de true
                    repetida = true;
                }
            }
            // si esta repetida
            if (repetida)
            {
                // entonces le mostramos al usuario un mensaje
                JOptionPane.showMessageDialog(null, "Error, esta referencia ya existe en el vector.");
            }
            else
            {
                // sino entonces le asignamos a la variable existe el valor de false
                existe = false;
            }
        }
        while(existe); // estas instrucciones anteriores se ejecutaran cada vez que el usuario ingrese una referencia que ya exista
        // encapsulamos la variable ref
        obj.setReferencia(ref);
        // pedimos la marca
        String mar = JOptionPane.showInputDialog("Ingrese la marca:");
        // encapsulamos la variable mar
        obj.setMarca(mar);
        // pedimos el modelo
        String mod = JOptionPane.showInputDialog("Ingrese el modelo:");
        // encapsulamos la variable mod
        obj.setModelo(mod);
        // pedimos el precio
        float pre = Float.parseFloat(JOptionPane.showInputDialog("Ingrese el precio:"));
        // encapsulamos la variable pre
        obj.setPrecio(pre);
        // pedimos la capacidad de memoria ram
        float mem = Float.parseFloat(JOptionPane.showInputDialog("Ingrese capacidad de memoria ram:"));
        // encapsulamos la variable mem
        obj.setMemoriaRam(mem);
        // pedimos la velocidad del procesador
        float ghz = Float.parseFloat(JOptionPane.showInputDialog("Ingrese velocidad del procesador:"));
        // encapsulamos la variable ghz
        obj.setGhz(ghz);
    }
    
    // método para mostrar la información de una posicion especifica del vector
    public static void mostrar(Logica obj, int pos)
    {
        String datos = "";
        datos += "Referencia: " + obj.getVector(pos).getReferencia() + "\n" +
                 "Marca: " + obj.getVector(pos).getMarca() + "\n" +
                 "Modelo: " + obj.getVector(pos).getModelo() + "\n" +
                 "Precio: " + obj.getVector(pos).getPrecio() + "\n" +
                 "Memoria Ram: " + obj.getVector(pos).getMemoriaRam()+ "gb\n" +
                 "Velocidad de procesador: " + obj.getVector(pos).getGhz()+ "ghz\n\n";
        JOptionPane.showMessageDialog(null, datos);
    }

    // método para listar toda la información del vector
    public static void listar(Logica obj)
    {
        for (int i = 0; i < obj.getTamaño(); i++)
        {
            mostrar(obj, i);
        }
    }

    // método para mostrar equipos por rango
    public static void mostrarPorRango(Logica obj, float p_inicial, float p_final)
    {
        // inicializamos una variable de tipo string llamada datos en ""
        String datos = "";
        // recorremos el vector con el ciclo for
        for (int i = 0; i < obj.getTamaño(); i++)
        {
            // si el precio de la posicion i esta entre el rango del precio inicial y el precio final
            if (obj.getVector(i).getPrecio() >= p_inicial && obj.getVector(i).getPrecio() <= p_final)
            {
                // entonces acumulo en la variable datos la informacion de la posicion i
                datos += "Referencia: " + obj.getVector(i).getReferencia() + "\n" +
                         "Marca: " + obj.getVector(i).getMarca() + "\n" +
                         "Modelo: " + obj.getVector(i).getModelo() + "\n" +
                         "Precio: " + obj.getVector(i).getPrecio() + "\n" +
                         "Memoria Ram: " + obj.getVector(i).getMemoriaRam()+ "gb\n" +
                         "Velocidad de procesador: " + obj.getVector(i).getGhz()+ "ghz\n\n";
            }
        }
        // si el valor de la variable datos es igual a  ""
        if (datos.equals(""))
        {
            // entonces se mostrara un mensaje
            JOptionPane.showMessageDialog(null, "No hay equipos con esos precios");
        }
        else
        {
            // muestro el valor de la variable datos
            JOptionPane.showMessageDialog(null, datos);
        }
    }
    
    // método para mostrar equipos por marca
    public static void mostrarPorMarca(Logica obj, String marca)
    {
        // inicializamos una variable de tipo string llamada datos en ""
        String datos = "";
        // recorremos el vector con el ciclo for
        for (int i = 0; i < obj.getTamaño(); i++)
        {
            // si la marca de la posicion i es igual al valor de la variable marca pasada como parametro
            if (obj.getVector(i).getMarca().equals(marca))
            {
                // entonces acumulo en la variable datos la informacion de la posicion i
                datos += "Refencia: " + obj.getVector(i).getReferencia()+ "\n" +
                         "Marca: " + obj.getVector(i).getMarca() + "\n" +
                         "Modelo: " + obj.getVector(i).getModelo() + "\n" +
                         "Precio: " + obj.getVector(i).getPrecio() + "\n\n";
            }
        }
        // si el valor de la variable datos es igual a  ""
        if (datos.equals(""))
        {
            // entonces se mostrara un mensaje
            JOptionPane.showMessageDialog(null, "No hay equipos con esa marca");
        }
        else
        {
            // muestro el valor de la variable datos
            JOptionPane.showMessageDialog(null, datos);
        }
    }
    
    // método para mostrar el menú de opciones
    public static int menu()
    {
        int opcion;
        do
        {
            opcion = Integer.parseInt(JOptionPane.showInputDialog(
            "=========== SELECCIONE UNA OPCIÓN DEL MENÚ =========== \n" +
            "1. Crear vector.\n" +
            "2. Buscar referencias.\n" +
            "3. Mostrar modelos ordenados.\n" +
            "4. Mostrar equipos por rango de precios.\n" +
            "5. Mostrar información del equipo mas economico.\n" +
            "6. Mostrar información del equipo mas costoso.\n" +
            "7. Mostrar datos\n" +
            "8. Salir\n\n" +
            " Seleccione una opción del 1 al 8:"));
        }
        while(opcion < 1 || opcion > 8);
        return opcion;
    }
    
    // método para mostrar el menú de opciones especifico al buscar un equipo
    public static int menuEquipo()
    {
        int opc_m;
        do
        {
            opc_m = Integer.parseInt(JOptionPane.showInputDialog(
            "Buscar equipo mas economico por:\n" +
            "1. Marca especifica\n" +
            "2. Todas las marcas"));
        }
        while (opc_m < 1 || opc_m > 2);
        return opc_m;
    }
    
    // método para mostrar un mensaje de error
    public static void errorMensaje(int opc)
    {
        // dependiendo del valor de la variable opc pasada como parametro, se seleccionara un caso
        switch (opc)
        {
            case 1:
                JOptionPane.showMessageDialog(null, "No se ha creado el vector");
                break;
            default:
                JOptionPane.showMessageDialog(null, "No se encuentra el dato");
                break;
        }

    }
    
    public static void main(String[] args)
    {
        // se crea un objeto de la clase Logica (Instanciación)
        Logica obj = new Logica();
        // se declara un objeto de tipo Laptop
        Laptop lap;
        // se declaran las siguientes variables:
        int opcion, tam, pos, opc_equipo;
        String dato;
        do
        {
            // le asignamos a la variable opcion el valor que retorne el metodo menu
            opcion = menu();
            // dependiendo del valor de la variable opcion se seleccionara un caso
            switch(opcion) 
            {
                case 1:
                    do{
                        tam = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite tamaño del Vector:"));
                        if (tam<0)
                        {
                            JOptionPane.showMessageDialog(null, "Error, numero negativo.");
                        }
                    }
                    while(tam<0);
                    obj.setTamaño(tam);
                    obj.crearVector();
                    for (int i = 0; i < obj.getTamaño(); i++)
                    {
                        lap = new Laptop();
                        JOptionPane.showMessageDialog(null, "Llene la información del laptop " + i);
                        llenar(lap,obj,i);
                        obj.setVector(i, lap);
                    }
                    break;
                case 2:
                    if(obj.getTamaño()!=0)
                    {
                        dato = JOptionPane.showInputDialog("Digite referencia laptop que quiere buscar:");
                        pos = obj.buscar(dato);
                        if (pos != -1)
                        {
                            mostrar(obj, pos);
                        }
                        else
                        {
                            errorMensaje(2);
                        }
                    }
                    else
                    {
                        errorMensaje(1);
                    }
                    break;
                case 3:
                    if(obj.getTamaño()!=0)
                    {
                        dato = JOptionPane.showInputDialog("Digite la marca:");
                        pos = obj.buscarMarca(dato);
                        if (pos != -1)
                        {
                            obj.ordenarPorReferencia();
                            mostrarPorMarca(obj, dato);
                        }
                        else
                        {
                            errorMensaje(2);
                        }
                    }
                    else
                    {
                        errorMensaje(1);
                    }
                    break;
                case 4:
                    if (obj.getTamaño()!=0)
                    {
                        float p_inicial = Float.parseFloat(JOptionPane.showInputDialog("Digite el precio inicial:"));
                        float p_final = Float.parseFloat(JOptionPane.showInputDialog("Digite el precio final:"));
                        mostrarPorRango(obj, p_inicial, p_final);
                    }
                    else
                    {
                        errorMensaje(1);
                    }
                    break;
                case 5:
                    if (obj.getTamaño()!=0)
                    {
                        opc_equipo = menuEquipo();
                        if (opc_equipo == 1)
                        {
                            String m = JOptionPane.showInputDialog("Digite la marca:");
                            pos = obj.buscarEquipoEconomicoMarca(m);
                            if (pos != -1)
                            {
                                JOptionPane.showMessageDialog(null,"EQUIPO MAS ECONOMICO");
                                mostrar(obj, pos);
                            }
                            else
                            {
                                errorMensaje(2);
                            } 
                        }
                        else
                        {
                            pos = obj.buscarEquipoEconomicoTodos();
                            if (pos != -1)
                            {
                                JOptionPane.showMessageDialog(null,"EQUIPO MAS ECONOMICO");
                                mostrar(obj, pos);
                                
                            }
                            else
                            {
                                errorMensaje(2);
                            }
                        }
                    }
                    else
                    {
                        errorMensaje(1);
                    }
                    break;
                case 6:
                    if (obj.getTamaño()!=0)
                    {
                        opc_equipo = menuEquipo();
                        if (opc_equipo == 1)
                        {
                            String m = JOptionPane.showInputDialog("Digite la marca:");
                            pos = obj.buscarEquipoCostosoMarca(m);
                            if (pos != -1)
                            {
                                JOptionPane.showMessageDialog(null,"EQUIPO MAS COSTOSO");
                                mostrar(obj, pos);
                                
                            }
                            else
                            {
                                errorMensaje(2);
                            } 
                        }
                        else
                        {
                            pos = obj.buscarEquipoCostosoTodos();
                            if (pos != -1)
                            {
                                JOptionPane.showMessageDialog(null,"EQUIPO MAS COSTOSO");
                                mostrar(obj, pos);
                            }
                            else
                            {
                                errorMensaje(2);
                            }
                        }
                    }
                    else
                    {
                        errorMensaje(1);
                    }
                    break;
                case 7:
                    if (obj.getTamaño()!=0)
                    {
                        listar(obj);
                    }
                    else
                    {
                        errorMensaje(1);
                    }
                    break;
                default:
                    JOptionPane.showMessageDialog(null, "Adios!! <AiudaCode>");
                    break;
            }
        }
        while (opcion != 8);
    }
}