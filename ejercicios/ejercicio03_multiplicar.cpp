#include "validaciones.h"

double multiplica(double a, double b);

int main() {
    try {
        double a = leerReal("Primer valor real: ", -1000000, 1000000);
        double b = leerReal("Segundo valor real: ", -1000000, 1000000);
        double producto = multiplica(a, b);
        cout << fixed << setprecision(4);
        cout << a << " * " << b << " = " << producto << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

double multiplica(double a, double b) {
    double producto = a * b;
    if (!isfinite(producto))
        throw overflow_error("el producto excede el rango de double");
    return producto;
}
