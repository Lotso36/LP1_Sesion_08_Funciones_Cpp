#include "validaciones.h"

void primos(long long n);

int main() {
    try {
        long long n = leerEntero("Entero a descomponer (2 - 10^12): ", 2, 1000000000000LL);
        primos(n);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

void primos(long long n) {
    if (n < 2) throw invalid_argument("el numero debe ser mayor o igual que 2");
    cout << n << " = ";
    bool primero = true;
    for (long long f = 2; f * f <= n; f++)
        while (n % f == 0) {
            cout << (primero ? "" : " x ") << f;
            primero = false;
            n /= f;
        }
    if (n > 1) cout << (primero ? "" : " x ") << n;   // factor primo restante
    cout << endl;
}
