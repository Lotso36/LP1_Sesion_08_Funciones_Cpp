#include "validaciones.h"

int elevarAlCuadrado(int numero);

int main() {
    try {
        int numero = leerEntero("Ingrese un entero (|n| <= 46340): ", -46340, 46340);
        cout << "Antes de la llamada, numero = " << numero << endl;
        int cuadrado = elevarAlCuadrado(numero);
        cout << "El cuadrado por valor es: " << cuadrado << endl;
        cout << "Despues de la llamada, numero = " << numero << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

int elevarAlCuadrado(int numero) {
    numero = numero * numero;  // modifica solo la copia local
    cout << "Dentro de la funcion, la copia vale " << numero << endl;
    return numero;
}
