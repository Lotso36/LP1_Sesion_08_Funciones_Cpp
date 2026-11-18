#include "validaciones.h"

double evaluarPolinomio(double x);

int main() {
    try {
        double x = leerReal("Valor de x (-100 a 100): ", -100, 100);
        cout << setprecision(10);
        cout << "r = 3x^5 - 5x^3 + 2x - 7, con x = " << x << endl;
        cout << "r = " << evaluarPolinomio(x) << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

double evaluarPolinomio(double x) {
    double r = 3;              // metodo de Horner: coeficientes 3, 0, -5, 0, 2, -7
    r = r * x + 0;
    r = r * x - 5;
    r = r * x + 0;
    r = r * x + 2;
    r = r * x - 7;
    if (!isfinite(r)) throw overflow_error("el resultado excede el rango de double");
    return r;
}
