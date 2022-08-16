#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Pila.h"

class Controlador {
	public:
		explicit Controlador() { }
		~Controlador() { }

		void menu() const;
		int pedirDato();
		void agregarDato(Pila *, int);
		void imprimirDatos(Pila *) const;
		void verTamano(Pila *) const;
		void eliminarDato(Pila *);
		void inversa(Pila *);
		void ordenar(Pila *, int);
		void verUltimoDato(Pila *) const;
	
};

#endif //CONTROLADOR_H