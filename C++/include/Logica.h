#ifndef LOGICA_H
#define LOGICA_H
#include "Laptop.h"
#include <iostream>

using namespace std;

class Logica
{
    public:
        Logica();
        virtual ~Logica();
        // se declaran los métodos publicos
        void crearVector();
        void setVector(int pos, Laptop *val);
        Laptop *getVector(int pos);
        void setTamano(int val);
        int getTamano();
        int buscar(string nom);
        int buscarMarca(string nom);
        int buscarEquipoEconomicoMarca(string nom);
        int buscarEquipoEconomicoTodos();
        int buscarEquipoCostosoMarca(string nom);
        int buscarEquipoCostosoTodos();
        void ordenarPorReferencia();
        void cambiar(int p1, int p2);
    protected:

    private:
        // se declaran los atributos privados
        Laptop *vector;
        int tamano;
};

#endif // LOGICA_H
