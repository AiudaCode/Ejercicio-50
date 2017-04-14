#include "Laptop.h"

Laptop::Laptop()
{
    // se le asignan valores por defecto a los atributos en el constructor de la clase
    referencia = "";
    marca = "";
    modelo = "";
    precio = 0;
    m_ram = 0;
    ghz = 0;
}

Laptop::~Laptop()
{
    //dtor
}

// métodos Setters y Getters de los atributos de la clase
void Laptop::setReferencia(string val)
{
    referencia = val;
}

string Laptop::getReferencia()
{
    return referencia;
}

void Laptop::setMarca(string val)
{
    marca = val;
}

string Laptop::getMarca()
{
    return marca;
}

void Laptop::setModelo(string val)
{
    modelo = val;
}

string Laptop::getModelo()
{
    return modelo;
}

void Laptop::setPrecio(double val)
{
    precio = val;
}

double Laptop::getPrecio()
{
    return precio;
}

void Laptop::setMemoriaRam(float val)
{
    m_ram = val;
}

float Laptop::getMemoriaRam()
{
    return m_ram;
}

void Laptop::setGhz(float val)
{
    ghz = val;
}

float Laptop::getGhz()
{
    return ghz;
}
