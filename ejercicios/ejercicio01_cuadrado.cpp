#include "validaciones.h"

double calculaArea(double lado);
double calculaPerimetro(double lado);

int main() {
    try {
        double lado = leerReal("Lado del cuadrado (0.01 - 100000): ", 0.01, 100000);
        cout << fixed << setprecision(2);
        cout << "Area      = " << calculaArea(lado) << endl;
        cout << "Perimetro = " << calculaPerimetro(lado) << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

double calculaArea(double lado) {
    if (lado <= 0) throw invalid_argument("el lado debe ser mayor que cero");
    return lado * lado;
}

double calculaPerimetro(double lado) {
    if (lado <= 0) throw invalid_argument("el lado debe ser mayor que cero");
    return 4 * lado;
}
