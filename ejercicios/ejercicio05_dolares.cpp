#include "validaciones.h"

double convierteDolares(double soles, double tipoCambio);

int main() {
    try {
        double soles = leerReal("Monto en soles (S/): ", 0, 10000000);
        double tc = leerReal("Tipo de cambio (soles por dolar): ", 0.01, 100);
        double dolares = convierteDolares(soles, tc);
        cout << fixed << setprecision(2);
        cout << "S/ " << soles << " equivalen a US$ " << dolares << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

double convierteDolares(double soles, double tipoCambio) {
    if (soles < 0) throw invalid_argument("el monto no puede ser negativo");
    if (tipoCambio <= 0) throw invalid_argument("el tipo de cambio debe ser positivo");
    return soles / tipoCambio;
}
