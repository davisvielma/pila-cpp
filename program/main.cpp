#include <iostream>
#include "Controlador.h"
#include "Pila.h"

using namespace std;

#define RED "\x1B[31m"

int main(int argc, char const *argv[]) {

    Controlador controlador;
    Pila *pila = new Pila();
    int opcion = 0;

    do {

        try {
            controlador.menu();
            cin >> opcion;

            if (opcion < 1 || opcion > 9) throw -1;

            switch(opcion) {
                case 1:
                    controlador.agregarDato(pila, controlador.pedirDato());
                    break;

                case 2:
                    controlador.verTamano(pila);
                    break;

                case 3:
                    controlador.verUltimoDato(pila);
                    break;

                case 4:
                    controlador.imprimirDatos(pila);
                    break;

                case 5:
                    controlador.inversaPila(pila);
                    break;

                case 6:
                    controlador.ordenarPila(pila, static_cast<int>(Pila::Orden::ASCENDENTE));
                    break;

                case 7:
                    controlador.ordenarPila(pila, static_cast<int>(Pila::Orden::DESCENDENTE));
                    break;

                case 8:
                    controlador.eliminarDato(pila);
                    break;
            }

        } catch (int e) {
            cout << RED "\nERROR!! Opción invalida." << endl;
        }

    } while (opcion != 9);

    delete pila;

    return 0;
}