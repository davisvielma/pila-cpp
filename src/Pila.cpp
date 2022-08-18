#include "Pila.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Pila::Pila() {
    this->cima = new Nodo();
    this->tamano = 0;
}

bool Pila::vacia() const {
    return ((!this->cima->siguiente) ? true : false);
}

void Pila::setTamano(int n) {
    this->tamano += n;
}

void Pila::agregar(int dato) {
    Nodo *nodo = new Nodo();
    nodo->dato = dato;
    nodo->siguiente = this->cima->siguiente;

    this->cima->siguiente = nodo;
    this->setTamano(1);
}

int Pila::remover() {
    int dato = 0;

    if(!this->vacia()) {
        Nodo *nodo = this->cima->siguiente->siguiente;
        dato = this->cima->siguiente->dato;
        delete this->cima->siguiente;
        this->cima->siguiente = nodo;
        this->setTamano(-1);
    }  

    return dato;
}

void Pila::imprimir() const {
    if(!this->vacia()) {
        Nodo *nodo = this->cima->siguiente;

        while(nodo != NULL) {
            cout << nodo->dato << " | ";
            nodo = nodo->siguiente;
        }

        cout << endl;
    }
}

Pila* Pila::inversa() {
    if(!this->vacia()) {
        Nodo *nodo = this->cima->siguiente;
        Pila *pila = new Pila();

        while(nodo != NULL) {
            pila->agregar(nodo->dato);
            nodo = nodo->siguiente;
        }

        return pila;
    } 
}

Pila* Pila::ordenar(int opcion) {
    if(!this->vacia()) {
        Nodo *nodo = this->cima->siguiente;
        Pila *pila = new Pila();
        vector<int> v;

        while(nodo != NULL) {
            v.push_back(nodo->dato);
            nodo = nodo->siguiente;
        }

        if (opcion == static_cast<int>(this->Orden::ASCENDENTE)) sort(v.begin(), v.end());
        else sort(v.rbegin(), v.rend());

        for (int elemento: v) {
            pila->agregar(elemento);
        }

        return pila;
    }
}

Pila::~Pila() {
    while(!this->vacia()) {
        this->remover();
    }

    delete cima;
}