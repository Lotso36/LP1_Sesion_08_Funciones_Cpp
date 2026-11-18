#include "validaciones.h"

void piramideDigitos(int filas);

int main() {
    try {
        int filas = leerEntero("Numero de filas (11 - 20): ", 11, 20);
        piramideDigitos(filas);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

void piramideDigitos(int filas) {
    if (filas < 11 || filas > 20) throw out_of_range("las filas deben estar entre 11 y 20");
    for (int i = 1; i <= filas; i++) {
        cout << string(2 * (filas - i), ' ');
        for (int k = i; k <= 2 * i - 1; k++) cout << k % 10 << ' ';   // tramo ascendente
        for (int k = 2 * i - 2; k >= i; k--) cout << k % 10 << ' ';   // tramo descendente
        cout << endl;
    }
}
