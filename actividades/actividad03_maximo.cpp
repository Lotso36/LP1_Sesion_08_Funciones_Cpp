#include "validaciones.h"

int ubicaMax(int a, int b);

int main() {
    try {
        int numero1 = leerEntero("Digite el valor numerico 1: ", -1000000, 1000000);
        int numero2 = leerEntero("Digite el valor numerico 2: ", -1000000, 1000000);
        int maximo = ubicaMax(numero1, numero2);
        if (numero1 == numero2)
            cout << "Los dos valores son iguales: " << maximo << endl;
        else
            cout << "El mayor de los dos valores es: " << maximo << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

int ubicaMax(int a, int b) {
    return (a > b) ? a : b;
}
