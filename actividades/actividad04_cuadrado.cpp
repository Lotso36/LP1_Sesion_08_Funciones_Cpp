#include "validaciones.h"

long long calcularCuadradoPorValor(int numero);

int main() {
    try {
        int numero = leerEntero("Ingrese un entero (|n| <= 46340): ", -46340, 46340);
        long long cuadrado = calcularCuadradoPorValor(numero);
        cout << "El cuadrado de " << numero << " es: " << cuadrado << endl;
        cout << "El valor de numero en main sigue siendo: " << numero << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

long long calcularCuadradoPorValor(int numero) {
    long long resultado = static_cast<long long>(numero) * numero;
    if (resultado > 2147483647LL)
        throw overflow_error("el cuadrado excede el rango de int");
    return resultado;
}
