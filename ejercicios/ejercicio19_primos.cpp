#include "validaciones.h"

bool esPrimo(int n);
void listarPrimos(int inferior, int superior);

int main() {
    try {
        int inferior = leerEntero("Limite inferior (1 - 100000): ", 1, 100000);
        int superior = leerEntero("Limite superior: ", inferior, 100000);
        listarPrimos(inferior, superior);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

bool esPrimo(int n) {
    if (n < 2) return false;               // 1 no es primo por definicion
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0) return false;
    return true;
}

void listarPrimos(int inferior, int superior) {
    if (inferior > superior) throw invalid_argument("el limite inferior supera al superior");
    int cantidad = 0;
    cout << "Primos entre " << inferior << " y " << superior << ":" << endl;
    for (int n = inferior; n <= superior; n++)
        if (esPrimo(n)) {
            cout << n << " ";
            cantidad++;
        }
    cout << "\nTotal: " << cantidad << " numeros primos." << endl;
}
