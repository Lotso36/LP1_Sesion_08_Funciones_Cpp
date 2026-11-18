#include "validaciones.h"

double parteDecimal(double numero);

int main() {
    try {
        double numero = leerReal("Numero flotante: ", -1000000, 1000000);
        cout << fixed << setprecision(6);
        cout << "Parte decimal de " << numero << " = " << parteDecimal(numero) << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

double parteDecimal(double numero) {
    if (!isfinite(numero)) throw invalid_argument("el numero debe ser finito");
    return numero - trunc(numero);  // conserva el signo del numero
}
