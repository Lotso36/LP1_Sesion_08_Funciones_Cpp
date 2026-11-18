#include "validaciones.h"

long long factorial(int n);
long long sumaFactoriales(int n);

int main() {
    try {
        int n = leerEntero("Valor de n (1 - 20): ", 1, 20);
        cout << "1! + 2! + ... + " << n << "! = " << sumaFactoriales(n) << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

long long factorial(int n) {
    if (n < 0) throw invalid_argument("el factorial no esta definido para negativos");
    if (n > 20) throw overflow_error("n! excede el rango de long long para n > 20");
    long long resultado = 1;
    for (int i = 2; i <= n; i++) resultado *= i;
    return resultado;
}

long long sumaFactoriales(int n) {
    long long suma = 0;
    for (int i = 1; i <= n; i++) suma += factorial(i);
    return suma;
}
