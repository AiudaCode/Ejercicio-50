#ifndef LAPTOP_H
#define LAPTOP_H
#include <iostream>

using namespace std;

class Laptop
{
    public:
        Laptop();
        virtual ~Laptop();
        // se declaran los métodos publicos
        void setReferencia(string val);
        string getReferencia();
        void setMarca(string val);
        string getMarca();
        void setModelo(string val);
        string getModelo();
        void setPrecio(double val);
        double getPrecio();
        void setMemoriaRam(float val);
        float getMemoriaRam();
        void setGhz(float val);
        float getGhz();
    protected:

    private:
        // se declaran los atributos privados
        string referencia;
        string marca;
        string modelo;
        double precio;
        float m_ram;
        float ghz;
};

#endif // LAPTOP_H
