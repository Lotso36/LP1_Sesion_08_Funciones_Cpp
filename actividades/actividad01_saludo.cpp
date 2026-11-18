#include "validaciones.h"

void saludo();

int main() {
    try {
        saludo();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

void saludo() {
    int veces = leerEntero("Cantidad de veces a imprimir el saludo (1-100): ", 1, 100);
    for (int i = 1; i <= veces; i++)
        cout << i << ". Bienvenidos a Funciones en Lenguaje de Programacion I" << endl;
}
