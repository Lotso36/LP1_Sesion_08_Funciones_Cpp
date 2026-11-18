#include "validaciones.h"

int exponenteDe(long long n, long long primo);
void mostrarDescomposicion(long long n);

int main() {
    try {
        long long n = leerEntero("Entero positivo (1 - 1000000000000): ", 1, 1000000000000LL);
        mostrarDescomposicion(n);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

int exponenteDe(long long n, long long primo) {
    int exponente = 0;
    while (n % primo == 0) {
        n /= primo;
        exponente++;
    }
    return exponente;
}

void mostrarDescomposicion(long long n) {
    if (n < 1) throw invalid_argument("se requiere un entero positivo");
    if (n == 1) { cout << "1 no tiene factores primos." << endl; return; }
    cout << n << " = ";
    bool primero = true;
    for (long long f = 2; f * f <= n; f++) {
        int e = exponenteDe(n, f);
        if (e == 0) continue;
        cout << (primero ? "" : " x ") << f;
        if (e > 1) cout << "^" << e;
        primero = false;
        for (int k = 0; k < e; k++) n /= f;
    }
    if (n > 1) cout << (primero ? "" : " x ") << n;
    cout << endl;
}
