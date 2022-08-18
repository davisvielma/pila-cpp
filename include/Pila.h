#ifndef PILA_H
#define PILA_H

#include "Nodo.h"

class Pila {
    private:
        Nodo *cima;
        int tamano;
        void setTamano(int);      
    
    public:
        explicit Pila();
        ~Pila();

        enum class Orden {
            ASCENDENTE,
            DESCENDENTE
        };

        inline int getDato() const { return this->cima->siguiente->dato; }
        inline int getTamano() const { return this->tamano; }
        void agregar(int);
        int remover();
        bool vacia() const;
        void imprimir() const;
        Pila* inversa();
        Pila* ordenar(int);
};

#endif //PILA_H