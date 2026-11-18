#include "validaciones.h"

long long MCD(long long a, long long b);

int main() {
    try {
        long long a = leerEntero("Primer entero: ", -1000000000000LL, 1000000000000LL);
        long long b = leerEntero("Segundo entero: ", -1000000000000LL, 1000000000000LL);
        long long resultado = MCD(a, b);
        cout << "MCD(" << a << ", " << b << ") = " << resultado << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

long long MCD(long long a, long long b) {
    if (a == 0 && b == 0) throw domain_error("el MCD de 0 y 0 no esta definido");
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {                      // algoritmo de Euclides
        long long resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}
