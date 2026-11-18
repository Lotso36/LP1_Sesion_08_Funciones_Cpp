#include "validaciones.h"

void resolverCuadratica(double a, double b, double c);

int main() {
    try {
        double a;
        do {
            a = leerReal("Coeficiente a (distinto de 0): ", -1000, 1000);
            if (a == 0) cout << "  Error: si a = 0 la ecuacion no es cuadratica." << endl;
        } while (a == 0);
        double b = leerReal("Coeficiente b: ", -1000, 1000);
        double c = leerReal("Coeficiente c: ", -1000, 1000);
        resolverCuadratica(a, b, c);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

void resolverCuadratica(double a, double b, double c) {
    if (a == 0) throw invalid_argument("el coeficiente a no puede ser cero");
    double disc = b * b - 4 * a * c;
    cout << fixed << setprecision(4) << "Discriminante = " << disc << endl;
    if (disc > 0) {
        cout << "Dos raices reales distintas:" << endl;
        cout << "  x1 = " << (-b + sqrt(disc)) / (2 * a) << endl;
        cout << "  x2 = " << (-b - sqrt(disc)) / (2 * a) << endl;
    } else if (disc == 0) {
        cout << "Una raiz real doble: x = " << -b / (2 * a) << endl;
    } else {
        double re = -b / (2 * a), im = sqrt(-disc) / (2 * a);
        cout << "Raices complejas conjugadas:" << endl;
        cout << "  x1 = " << re << " + " << fabs(im) << "i" << endl;
        cout << "  x2 = " << re << " - " << fabs(im) << "i" << endl;
    }
}
