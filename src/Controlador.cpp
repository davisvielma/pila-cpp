#include "Controlador.h"
#include <iostream>

using namespace std;

#define BLACK "\x1B[30m"
#define YELLOW "\x1B[33m"
#define GREEN "\x1B[32m"

void Controlador::menu() const {
	cout << GREEN "\n\t\tPractica de pilas." << endl;
	cout << "\n1) Agregar un numero a la pila." << endl;
	cout << "2) Ver cuentos elementos tiene la pila." << endl;
	cout << "3) Ver ultimo elementos agregado a la pila." << endl;
	cout << "4) Imprimir valores de la pila." << endl;
	cout << "5) Obtener inversa de la pila." << endl;
	cout << "6) Obtener pila de orden ascendente." << endl;
	cout << "7) Obtener pila de orden descendente." << endl;
	cout << "8) Eliminar un numero de la pila." << endl;
	cout << "9) Salir." << endl;
	cout << "*Elige una opción: ";

	return;
}

int Controlador::pedirDato() {
	int dato = 0;

	cout << "\nIngrese un numero: ";
	cin >> dato;

	return dato;
}

void Controlador::agregarDato(Pila *p, int dato) {
	p->add(dato);

	return;
}

void Controlador::imprimirDatos(Pila *p) const {
	if(p->empty()) throw -2;

	cout << endl;
	p->print();

	return;
}

void Controlador::verTamano(Pila *p) const {
	cout << "\nNumero de elementos de la pila: " << p->size() << endl;

	return;
}

void Controlador::eliminarDato(Pila *p) {
	if (p->empty()) throw -2;

	cout << "\nSe elimino el numero: " << p->remove() << endl;

	return;
}

void Controlador::inversa(Pila *p) {
	if (p->empty()) throw -2;

	Pila *aux = p->reverse();
	this->imprimirDatos(aux);

	return;
}

void Controlador::ordenar(Pila *p, int opcion) {
	if (p->empty()) throw -2;
	if (opcion < 1 || opcion > 2) throw -1;

	Pila *aux = p->order(opcion);
	this->imprimirDatos(aux);

	return;
}

void Controlador::verUltimoDato(Pila *p) const {
	if (p->empty()) throw -2;

	cout << "\nUltimo elemento en la pila: " << p->getDato() << endl;
}