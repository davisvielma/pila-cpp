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
                    controlador.inversa(pila);
                    break;

                case 6:
                    controlador.ordenar(pila, 1);
                    break;

                case 7:
                    controlador.ordenar(pila, 2);
                    break;

                case 8:
                    controlador.eliminarDato(pila);
                    break;
            }

        } catch (int e) {
            if (e == -1) cout << RED "\nERROR!! Opción invalida." << endl;
            else if (e == -2) cout << RED "\nERROR!! Pila vaciá." << endl;
        }

    } while (opcion != 9);

    return 0;
}