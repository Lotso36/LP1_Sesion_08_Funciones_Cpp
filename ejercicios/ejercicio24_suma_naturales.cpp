#include "validaciones.h"

long long sumaNaturales(long long n);

int main() {
    try {
        long long n = leerEntero("Valor de n (1 - 2000000000): ", 1, 2000000000LL);
        cout << "1 + 2 + 3 + ... + " << n << " = " << sumaNaturales(n) << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

long long sumaNaturales(long long n) {
    if (n < 1) throw invalid_argument("n debe ser un natural positivo");
    return n * (n + 1) / 2;               // formula de Gauss, sin ciclo
}
