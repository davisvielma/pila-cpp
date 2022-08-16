#ifndef NODO_H
#define NODO_H

class Nodo {
    private:
        Nodo *next;
        int dato;

    friend class Pila;
};

#endif //NODO_H