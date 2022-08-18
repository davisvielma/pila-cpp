#include "Controlador.h"
#include <iostream>

using namespace std;

#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"

void Controlador::menu() const {
	cout << GREEN "\n\t\tPractica de pilas." << endl;
	cout << "\n1) Agregar un numero a la pila." << endl;
	cout << "2) Ver cuantos elementos tiene la pila." << endl;
	cout << "3) Ver ultimo elemento agregado a la pila." << endl;
	cout << "4) Imprimir valores de la pila." << endl;
	cout << "5) Obtener inversa de la pila." << endl;
	cout << "6) Obtener pila de orden ascendente." << endl;
	cout << "7) Obtener pila de orden descendente." << endl;
	cout << "8) Eliminar un numero de la pila." << endl;
	cout << "9) Salir." << endl;
	cout << "*Elige una opción: ";
}

void Controlador::pilaVacia() const {
	cout << YELLOW "\nPila vaciá." << endl;
}

int Controlador::pedirDato() {
	int dato = 0;

	cout << YELLOW "\nIngrese un numero: ";
	cin >> dato;

	return dato;
}

void Controlador::agregarDato(Pila *p, int dato) {
	p->agregar(dato);
}

void Controlador::imprimirDatos(Pila *p) const {
	if(p->vacia()) {
		this->pilaVacia();
		return;
	}

	cout << YELLOW "" << endl;
	p->imprimir();
}

void Controlador::verTamano(Pila *p) const {
	cout << YELLOW "\nNumero de elementos de la pila: " << p->getTamano() << endl;
}

void Controlador::eliminarDato(Pila *p) {
	if (p->vacia()) {
		this->pilaVacia();
		return;
	}

	cout << YELLOW "\nSe elimino el numero: " << p->remover() << endl;
}

void Controlador::inversaPila(Pila *p) {
	if (p->vacia()) {
		this->pilaVacia();
		return;
	}

	Pila *aux = p->inversa();
	this->imprimirDatos(aux);
}

void Controlador::ordenarPila(Pila *p, int opcion) {
	if (p->vacia()) {
		this->pilaVacia();
		return;
	}

	if (opcion !=  static_cast<int>(Pila::Orden::ASCENDENTE) && opcion != static_cast<int>(Pila::Orden::DESCENDENTE)) throw -1;

	Pila *aux = p->ordenar(opcion);
	this->imprimirDatos(aux);
}

void Controlador::verUltimoDato(Pila *p) const {
	if (p->vacia()) {
		this->pilaVacia();
		return;
	}

	cout << YELLOW "\nUltimo elemento en la pila: " << p->getDato() << endl;
}