#include "validaciones.h"

double calcularInteres(double capital, double tasa, int dias);

int main() {
    try {
        double capital = leerReal("Capital en soles (0.01 - 100000000): ", 0.01, 100000000);
        double tasa = leerReal("Tasa de interes nominal anual en % (0 - 100): ", 0, 100);
        int dias = leerEntero("Periodo en dias (1 - 3650): ", 1, 3650);
        double interes = calcularInteres(capital, tasa, dias);
        cout << fixed << setprecision(2);
        cout << "Interes producido: S/ " << interes << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

double calcularInteres(double capital, double tasa, int dias) {
    if (capital <= 0 || tasa < 0 || dias <= 0)
        throw invalid_argument("capital y periodo deben ser positivos y la tasa no negativa");
    return capital * tasa * dias / (360.0 * 100.0);
}
