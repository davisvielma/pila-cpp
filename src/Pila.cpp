#include "Pila.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Pila::Pila() {
    this->top = new Nodo();
}

bool Pila::empty() const {
    return ((!this->top->next) ? true : false);
}

void Pila::add(int dato) {
    Nodo *nodo = new Nodo();
    nodo->dato = dato;
    nodo->next = this->top->next;

    this->top->next = nodo;

    return;
}

int Pila::remove() {
    int dato = 0;

    if(!this->empty()) {
        Nodo *nodo = this->top->next->next;
        dato = this->top->next->dato;
        delete this->top->next;
        this->top->next = nodo;
    }  

    return dato;
}

void Pila::print() const {
    if(!this->empty()) {
        Nodo *nodo = this->top->next;

        while(nodo != NULL) {
            cout << nodo->dato << " | ";
            nodo = nodo->next;
        }

        cout << endl;
    }

    return;
}

int Pila::size() const {
    int tamano = 0;

    if (this->empty()) {
        return tamano;
    }

    Nodo *nodo = this->top->next;

     while(nodo != NULL) {
        tamano++;
        nodo = nodo->next;
    }

    return tamano;
}

Pila* Pila::reverse() {
    if(!this->empty()) {
        Nodo *nodo = this->top->next;
        Pila *pila = new Pila();

        while(nodo != NULL) {
            pila->add(nodo->dato);
            nodo = nodo->next;
        }

        return pila;
    } 
}

Pila* Pila::order(int opcion) {
    if(!this->empty()) {
        Nodo *nodo = this->top->next;
        Pila *pila = new Pila();
        vector<int> v;

        while(nodo != NULL) {
            v.push_back(nodo->dato);
            nodo = nodo->next;
        }

        if (opcion == 1) sort(v.begin(), v.end());
        else sort(v.rbegin(), v.rend());

        for (int elemento: v) {
            pila->add(elemento);
        }

        return pila;
    }
}