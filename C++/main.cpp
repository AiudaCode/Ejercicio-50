#include <iostream>
#include "Logica.h"
#include "Laptop.h"
#include "stdlib.h"

using namespace std;

// método para llenar el vector
void llenar(Laptop *obj, Logica *log, int pos)
{
    // declaramos una variable de tipo string llamada ref
    string ref;
    // inicializamos una variable de tipo bool llamada existe en false
    bool existe = true;
    // con el ciclo do-while validaremos si la referencia esta o no repetida
    do
    {
        // pedimos la referencia
        cout << "Ingrese la referencia" << endl;
        cout << ">> ";
        cin >> ref;
        // inicializamos una variable de tipo bool llamada repetida en false
        bool repetida = false;
        // recorremos hasta el valor de la variable pasada como parametro pos
        for (int i = 0; i < pos; i++)
        {
            // si la referencia de la posicion i del vector es igual al valor de la variable ref
            if(log->getVector(i)->getReferencia().compare(ref) == 0)
            {
                // entonces la referencia estara repetida, le asignamos a la variable repetida el valor de true
                repetida = true;
            }
        }
        // si esta repetida
        if (repetida)
        {
            // entonces le mostramos al usuario un mensaje
            cout << "Error, esta referencia ya existe en el vector." << endl;
        }
        else
        {
            // sino entonces le asignamos a la variable existe el valor de false
            existe = false;
        }
    }
    while(existe); // estas instrucciones anteriores se ejecutaran cada vez que el usuario ingrese una referencia que ya exista
    // encapsulamos la variable ref
    obj->setReferencia(ref);
    // pedimos la marca
    string mar;
    cout << "Ingrese la marca" << endl;
    cout << ">> ";
    cin >> mar;
    // encapsulamos la variable mar
    obj->setMarca(mar);
    // pedimos el modelo
    string mod;
    cout << "Ingrese el modelo" << endl;
    cout << ">> ";
    cin >> mod;
    // encapsulamos la variable mod
    obj->setModelo(mod);
    // pedimos el precio
    double pre;
    cout << "Ingrese el precio" << endl;
    cout << ">> ";
    cin >> pre;
    // encapsulamos la variable pre
    obj->setPrecio(pre);
    // pedimos la capacidad de memoria ram
    float mem;
    cout << "Ingrese capacidad de memoria ram" << endl;
    cout << ">> ";
    cin >> mem;
    // encapsulamos la variable mem
    obj->setMemoriaRam(mem);
    // pedimos la velocidad del procesador
    float ghz;
    cout << "Ingrese velocidad del procesador" << endl;
    cout << ">> ";
    cin >> ghz;
    // encapsulamos la variable ghz
    obj->setGhz(ghz);
}

// método para mostrar la información de una posicion especifica del vector
void mostrar(Logica *obj,  int pos)
{
    cout << "Referencia: " << obj->getVector(pos)->getReferencia() << endl;
    cout << "Marca: " << obj->getVector(pos)->getMarca() << endl;
    cout << "Modelo: " << obj->getVector(pos)->getModelo() << endl;
    cout << "Precio: " << obj->getVector(pos)->getPrecio() << endl;
    cout << "Memoria Ram: " << obj->getVector(pos)->getMemoriaRam() << "gb" << endl;
    cout << "Velocidad de procesador: " << obj->getVector(pos)->getGhz() << "ghz" << endl << endl;
}

// método para listar toda la información del vector
void listar(Logica *obj)
{
    for (int i = 0; i < obj->getTamano(); i++)
    {
        mostrar(obj, i);
    }
}

// método para mostrar equipos por rango
void mostrarPorRango(Logica *obj, float p_inicial, float p_final)
{
    // inicializamos una variable de tipo bool llamada datos en false
    bool datos = false;
    // recorremos el vector con el ciclo for
    for (int i = 0; i < obj->getTamano(); i++)
    {
        // si el precio de la posicion i esta entre el rango del precio inicial y el precio final
        if (obj->getVector(i)->getPrecio() >= p_inicial && obj->getVector(i)->getPrecio() <= p_final)
        {
            // entonces se muestra la información de ese equipo
            cout << "Referencia: " << obj->getVector(i)->getReferencia() << endl;
            cout << "Marca: " << obj->getVector(i)->getMarca() << endl;
            cout << "Modelo: " << obj->getVector(i)->getModelo() << endl;
            cout << "Precio: " << obj->getVector(i)->getPrecio() << endl;
            cout << "Memoria Ram: " << obj->getVector(i)->getMemoriaRam() << "gb" << endl;
            cout << "Velocidad de procesador: " << obj->getVector(i)->getGhz() << "ghz" << endl << endl;
            // le asignamos a la variable datos el valor true
            datos = true;
        }
    }
    // si no hay datos
    if (!datos)
    {
        // entonces se mostrara un mensaje
        cout << "No hay equipos con esos precios" << endl;
    }
}

// método para mostrar equipos por marca
void mostrarPorMarca(Logica *obj, string marca)
{
    // inicializamos una variable de tipo bool llamada datos en false
    bool datos = false;
    // recorremos el vector con el ciclo for
    for (int i = 0; i < obj->getTamano(); i++)
    {
        // si la marca de la posicion i es igual al valor de la variable marca pasada como parametro
        if (obj->getVector(i)->getMarca().compare(marca) == 0)
        {
            // entonces se mostrara la información de ese producto
            cout << "Refencia: " << obj->getVector(i)->getReferencia() << endl;
            cout << "Marca: " << obj->getVector(i)->getMarca() << endl;
            cout << "Modelo: " << obj->getVector(i)->getModelo() << endl;
            cout << "Precio: " << obj->getVector(i)->getPrecio() << endl << endl;
            // le asignamos a la variable datos el valor true
            datos = true;
        }
    }
    // si no hay datos
    if (!datos)
    {
        // entonces se mostrara un mensaje
        cout << "No hay equipos con esas marcas" << endl;
    }
}

// método para mostrar el menú de opciones
int menu()
{
    int opcion;
    do
    {
        cout << "=========================MENU=========================" << endl;
        cout << "1. Crear vector." << endl;
        cout << "2. Buscar referencias." << endl;
        cout << "3. Mostrar modelos ordenados." << endl;
        cout << "4. Mostrar equipos por rango de precios." << endl;
        cout << "5. Mostrar informacion del equipo mas economico." << endl;
        cout << "6. Mostrar informacion del equipo mas costoso." << endl;
        cout << "7. Mostrar datos" << endl;
        cout << "8. Salir" << endl;
        cout << ">> ";
        cin >> opcion;
        system("cls");
    }
    while (opcion < 1 || opcion > 8);
    return opcion;
}

// método para mostrar el menú de opciones especifico al buscar un equipo
int menuEquipo()
{
    int opc_m;
    do
    {
        cout << "Buscar equipo mas economico por:" << endl;
        cout << "1. Marca especifica" << endl;
        cout << "2. Todas las marcas" << endl;
        cout << ">> ";
        cin >> opc_m;
    }
    while (opc_m < 1 || opc_m > 2);
    return opc_m;
}

// método para mostrar un mensaje de error
void errorMensaje(int opc)
{
    // dependiendo del valor de la variable opc pasada como parametro, se seleccionara un caso
    switch (opc)
    {
        case 1:
            cout << "======================================================" << endl;
            cout << "||             No se ha creado el vector            ||" << endl;
            break;
        default:
            cout << "======================================================" << endl;
            cout << "||              No se encuentra el dato             ||" << endl;
            break;
    }

}


int main(void)
{
    // se crea un objeto de la clase Logica (Instanciación)
    Logica *obj = new Logica();
    // se declara un objeto de tipo Laptop
    Laptop *lap;
    // se declaran las siguientes variables:
    int opcion, tam, pos, opc_equipo;
    string dato;
    do
    {
        // le asignamos a la variable opcion el valor que retorne el metodo menu
        opcion = menu();
        // dependiendo del valor de la variable opcion se seleccionara un caso
        switch(opcion)
        {
            case 1:
                do{
                    cout << "Digite tamano del Vector" << endl;
                    cout << ">> ";
                    cin >> tam;
                    if (tam < 0)
                    {
                        cout << "Error, numero negativo." << endl;
                    }
                }
                while (tam < 0);
                obj->setTamano(tam);
                obj->crearVector();
                for (int i = 0; i < obj->getTamano(); i++)
                {
                    lap = new Laptop();
                    cout << "Llene la informacion del laptop " << i << endl;
                    llenar(lap, obj, i);
                    obj->setVector(i, lap);
                }
                break;
            case 2:
                if(obj->getTamano() != 0)
                {
                    cout << "Digite referencia laptop que quiere buscar" << endl;
                    cout << ">> ";
                    cin >> dato;
                    pos = obj->buscar(dato);
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
                if(obj->getTamano()!= 0)
                {
                    cout << "Digite la marca" << endl;
                    cout << ">> ";
                    cin >> dato;
                    pos = obj->buscarMarca(dato);
                    if (pos != -1)
                    {
                        obj->ordenarPorReferencia();
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
                if (obj->getTamano() != 0)
                {
                    float p_inicial, p_final;
                    cout << "Digite el precio inicial" << endl;
                    cout << ">> ";
                    cin >> p_inicial;
                    cout << "Digite el precio final" << endl;
                    cout << ">> ";
                    cin >> p_final;
                    mostrarPorRango(obj, p_inicial, p_final);
                }
                else
                {
                    errorMensaje(1);
                }
                break;
            case 5:
                if (obj->getTamano() != 0)
                {
                    opc_equipo = menuEquipo();
                    if (opc_equipo == 1)
                    {
                        string m;
                        cout << "Digite la marca" << endl;
                        cout << ">> ";
                        cin >> m;
                        pos = obj->buscarEquipoEconomicoMarca(m);
                        if (pos != -1)
                        {
                            cout << "EQUIPO MAS ECONOMICO (" << m << ")" << endl;
                            mostrar(obj, pos);
                        }
                        else
                        {
                            errorMensaje(2);
                        }
                    }
                    else
                    {
                        pos = obj->buscarEquipoEconomicoTodos();
                        if (pos != -1)
                        {
                            cout << "EQUIPO MAS ECONOMICO (TODOS)" << endl;
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
                if (obj->getTamano()!= 0)
                {
                    opc_equipo = menuEquipo();
                    if (opc_equipo == 1)
                    {
                        string m;
                        cout << "Digite la marca" << endl;
                        cout << ">> ";
                        pos = obj->buscarEquipoCostosoMarca(m);
                        if (pos != -1)
                        {
                            cout << "EQUIPO MAS COSTOSO (" << m << ")" << endl;
                            mostrar(obj, pos);
                        }
                        else
                        {
                            errorMensaje(2);
                        }
                    }
                    else
                    {
                        pos = obj->buscarEquipoCostosoTodos();
                        if (pos != -1)
                        {
                            cout << "EQUIPO MAS COSTOSO (TODOS)" << endl;
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
                if (obj->getTamano()!= 0)
                {
                    listar(obj);
                }
                else
                {
                    errorMensaje(1);
                }
                break;
            default:
                cout << "Adios!! <AiudaCode>" << endl;
                break;
        }
    }
    while (opcion != 8);
}
