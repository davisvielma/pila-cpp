#ifndef PILA_H
#define PILA_H

#include "Nodo.h"

class Pila {
    private:
        Nodo *top;
    
    public:
        explicit Pila();
        ~Pila();

        inline int getDato() const { return this->top->next->dato; }
        void add(int);
        int remove();
        bool empty() const;
        void print() const;
        int size() const;
        Pila* reverse();
        Pila* order(int);
};

#endif //PILA_H