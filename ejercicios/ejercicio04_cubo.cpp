#include "validaciones.h"

long long cubo(long long n);

int main() {
    try {
        long long n = leerEntero("Ingrese un numero entero: ", -3000000, 3000000);
        long long resultado = cubo(n);
        cout << "El cubo de " << n << " es " << resultado << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

long long cubo(long long n) {
    const long long LIMITE = 2097151;  // mayor n tal que n^3 cabe en long long
    if (n > LIMITE || n < -LIMITE)
        throw overflow_error("el cubo excede el rango de long long");
    return n * n * n;
}
