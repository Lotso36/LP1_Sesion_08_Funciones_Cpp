#include "validaciones.h"

int sumaDigitos(long long numero);

int main() {
    try {
        long long n = leerEntero("Numero entero: ", -1000000000000LL, 1000000000000LL);
        cout << "La suma de los digitos de " << n << " es " << sumaDigitos(n) << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

int sumaDigitos(long long numero) {
    if (numero < 0) numero = -numero;
    int suma = 0;
    while (numero > 0) {
        suma += static_cast<int>(numero % 10);
        numero /= 10;
    }
    return suma;
}
