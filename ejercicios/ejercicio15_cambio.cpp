#include "validaciones.h"

void cambio(int monto);

int main() {
    try {
        int monto = leerEntero("Monto en soles (1 - 100): ", 1, 100);
        cambio(monto);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

void cambio(int monto) {
    if (monto < 1 || monto > 100)
        throw out_of_range("el monto debe estar entre 1 y 100");
    const int valores[] = {100, 50, 20, 10, 5, 2, 1};
    int piezas = 0;
    cout << "Desglose minimo de S/ " << monto << ":" << endl;
    for (int i = 0; i < 7; i++) {
        int cantidad = monto / valores[i];
        monto %= valores[i];
        if (cantidad > 0) {
            string tipo = (valores[i] >= 10) ? " billete(s) de S/ " : " moneda(s) de S/ ";
            cout << "  " << cantidad << tipo << valores[i] << endl;
            piezas += cantidad;
        }
    }
    cout << "Total de piezas: " << piezas << endl;
}
