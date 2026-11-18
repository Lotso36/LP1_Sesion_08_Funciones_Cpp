#include "validaciones.h"

long long sumaDivisibles(int a, int b, int c);

int main() {
    try {
        int a = leerEntero("Inicio del intervalo a: ", -1000000, 1000000);
        int b = leerEntero("Fin del intervalo b (b >= a): ", a, 1000000);
        int c = leerEntero("Divisor c (1 - 1000000): ", 1, 1000000);
        cout << "La suma de los multiplos de " << c << " en [" << a << ", " << b << "] es "
             << sumaDivisibles(a, b, c) << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

long long sumaDivisibles(int a, int b, int c) {
    if (c == 0) throw domain_error("el divisor no puede ser cero");
    if (a > b) throw invalid_argument("el intervalo es invalido (a > b)");
    long long suma = 0;
    for (int i = a; i <= b; i++)
        if (i % c == 0) suma += i;
    return suma;
}
