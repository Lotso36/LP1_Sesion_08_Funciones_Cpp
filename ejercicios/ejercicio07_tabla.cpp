#include "validaciones.h"

void tablaMultiplicar(int n);

int main() {
    try {
        int n = leerEntero("Numero natural (1 - 1000000): ", 1, 1000000);
        tablaMultiplicar(n);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

void tablaMultiplicar(int n) {
    if (n < 1) throw invalid_argument("el numero debe ser natural (>= 1)");
    cout << "Tabla de multiplicar del " << n << ":" << endl;
    for (int i = 1; i <= 10; i++)
        cout << setw(8) << n << " x " << setw(2) << i << " = " << setw(8) << n * i << endl;
}
