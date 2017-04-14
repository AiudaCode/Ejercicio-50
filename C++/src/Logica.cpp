#include "Logica.h"

Logica::Logica()
{
    // se le asignan valores por defecto a los atributos en el constructor de la clase
    tamano = 0;
    vector = NULL;
}

Logica::~Logica()
{
    //dtor
}

// método para crear el vector
void Logica::crearVector()
{
    // le asigno al vector de tipo Laptop el tamaño del valor de la variable tamano
    vector = new Laptop[tamano];
}

// métodos Setters y Getters de la clase
void Logica::setVector(int pos, Laptop *val)
{
    vector[pos] = *val;
}

// para poder entender estos dos métodos es necesario leer acerca de como accedemos al valor de un puntero en c++
// en la sección de temas en programacion I podras encontrar la información necesaria :)
Laptop *Logica::getVector(int pos)
{
    return &vector[pos];
}

void Logica::setTamano(int val)
{
    tamano = val;
}
int Logica::getTamano()
{
    return tamano;
}
// método para buscar una referencia
int Logica::buscar(string nom)
{
    // recorremos el vector con el ciclo for
    for (int i = 0; i < getTamano(); i++)
    {
        // si la referencia de la posicion i del vector es igual al valor de la vatiable nom pasada como parametro
        if (getVector(i)->getReferencia().compare(nom) == 0)
        {
            // entonces, se retorna la posicion i
            return i;
        }
    }
    // si no se encontro nada, se retorna -1
    return -1;
}

// método para buscar una marca
int Logica::buscarMarca(string mar)
{
    // recorremos el vector con el ciclo for
    for (int i = 0; i < getTamano(); i++)
    {
        // si la marca de la posicion i del vector es igual al valor de la vatiable mar pasada como parametro
        if (getVector(i)->getMarca().compare(mar) == 0)
        {
            // entonces, se retorna la posicion i
            return i;
        }
    }
    // si no se encontro nada, se retorna -1
    return -1;
}

// método para buscar el equipo mas economico de una marca
int Logica::buscarEquipoEconomicoMarca(string mar)
{
    // inicializo una variable de tipo double llamada men, en el precio del equipo mas costoso por la marca especifica mar
    double men = getVector(buscarEquipoCostosoMarca(mar))->getPrecio();
    // declaro una variable de tipo double llamada def
    double def;
    // inicializo una variable de tipo int llamada pos_menor, en -1
    int pos_menor = -1;
    // recorremos el vector con el ciclo for
    for (int i = 0; i < getTamano(); i++)
    {
        // le asignamos a la variable def, el precio de la posicion i del vector
        def = getVector(i)->getPrecio();
        // si la marca de la posicion i del vector es igual al valor de la variable mar pasada
        // como parametro y si def es menor a la variable men
        if (getVector(i)->getMarca().compare(mar) == 0 && def < men)
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
int Logica::buscarEquipoEconomicoTodos()
{
    // inicializo una variable de tipo double llamada men, en el precio del equipo mas costoso de todas las marcas
    double men = getVector(buscarEquipoCostosoTodos())->getPrecio();
    // declaro una variable de tipo double llamada def
    double def;
    // inicializo una variable de tipo int llamada pos_menor, en -1
    int pos_menor = -1;
    // recorremos el vector con el ciclo for
    for (int i = 0; i < getTamano(); i++)
    {
        // le asignamos a la variable def, el precio de la posicion i del vector
        def = getVector(i)->getPrecio();
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
int Logica::buscarEquipoCostosoMarca(string nom)
{
    // inicializamos una variable de tipo double llamada max, en 0
    double max = 0;
    // método para buscar el equipo mas economico de una marca
    double def;
    // inicializo una variable de tipo int llamada pos_mayor, en -1
    int pos_mayor = -1;
    // recorremos el vector con el ciclo for
    for (int i = 0; i < getTamano(); i++)
    {
        // le asignamos a la variable def, el precio de la posicion i del vector
        def = getVector(i)->getPrecio();
        // si la marca de la posicion i del vector es igual al valor de la variable nom pasada como parametro
        // y si el valor de la varianle def es mayor al valor de la variable max
        if (getVector(i)->getMarca().compare(nom) == 0 && def > max)
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
int Logica::buscarEquipoCostosoTodos()
{
    // inicializamos una variable de tipo double llamada max, en 0
    double max = 0;
    // método para buscar el equipo mas economico de una marca
    double def;
    // inicializo una variable de tipo int llamada pos_mayor, en -1
    int pos_mayor = -1;
    // recorremos el vector con el ciclo for
    for (int i = 0; i < getTamano(); i++)
    {
        // le asignamos a la variable def, el precio de la posicion i del vector
        def = getVector(i)->getPrecio();
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

// método para cambiar la posicion de un objeto del vector con otra
void Logica::cambiar(int p1, int p2)
{
    // declaro un objeto de tipo Laptop llamado temp
    Laptop *temp;
    // le asigno a la variable temp el objeto que esta en la posicion p1 del vector
    temp = getVector(p1);
    // a la posicion p1 del vector se le asignara el objeto que esta en la posicion p2
    setVector(p1, getVector(p2));
    // a la posicion p2 del vector se le asignara el objeto temp
    setVector(p2, temp);
}

// método para ordenar por referencia
void Logica::ordenarPorReferencia()
{
    for (int i = 0; i < getTamano(); i++)
    {
        for (int j = i+1; j < getTamano(); j++)
        {
            // si la referencia de la posicion es menor a la referencia de la posicion j del vector
            if (getVector(i)->getReferencia().compare(getVector(j)->getReferencia()) < 0)
            {
                // cambiamos la posicion i con j
                cambiar(i, j);
            }
        }
    }
}
