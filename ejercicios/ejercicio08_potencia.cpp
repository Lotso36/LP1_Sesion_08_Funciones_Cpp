#include "validaciones.h"

double potencia(double base, int exponente);

int main() {
    try {
        double base = leerReal("Base (-1000 a 1000): ", -1000, 1000);
        int exponente = leerEntero("Exponente entero (-1000 a 1000): ", -1000, 1000);
        double resultado = potencia(base, exponente);
        cout << setprecision(10);
        cout << base << " ^ " << exponente << " = " << resultado << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

double potencia(double base, int exponente) {
    if (base == 0 && exponente <= 0)
        throw domain_error("0 elevado a un exponente no positivo es indefinido");
    long long e = (exponente < 0) ? -static_cast<long long>(exponente) : exponente;
    double resultado = 1, factor = base;
    while (e > 0) {                       // exponenciacion rapida
        if (e % 2 == 1) resultado *= factor;
        factor *= factor;
        e /= 2;
    }
    if (exponente < 0) resultado = 1 / resultado;
    if (!isfinite(resultado)) throw overflow_error("el resultado excede el rango de double");
    return resultado;
}
